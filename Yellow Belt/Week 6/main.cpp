#include "database.h"
#include "date.h"
#include "condition_parser.h"
#include "node.h"
#include "test_runner.h"

#include <iostream>
#include <stdexcept>
#include <condition_parser_test.h>

using namespace std;

string ParseEvent(istream& is) {
  string event;
  is >> std::ws;
  getline(is,event);
  return event;
}

void TestAll();

int main() {
  //TestAll();

  Database db;
/*
    istringstream inputTest(
    "Add 2017-11-02 a\n"
    "Add 2017-11-02 b\n"
    "Add 2017-11-04 b\n"
    "Add 2017-11-07 c\n"
    "Add 2017-11-10 a\n"
    "Add 2017-11-10 c\n"
    "Print\n"
    "Del date == 2017-11-10\n"

    //"Print\n"
    "Find date > 2017-11-02 AND (event == \"a\" OR event == \"c\")\n"

    );
*/
  for (string line; getline(cin, line); ) {
      //for (string line; getline(inputTest, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "Add") {
      const auto date = ParseDate(is);
      const auto event = ParseEvent(is);
      db.Add(date, event);
    } else if (command == "Print") {
      db.Print(cout);
    } else if (command == "Del") {
      auto condition = ParseCondition(is);
      auto predicate = [condition](const Date& date, const string& event) {
        return condition->Evaluate(date, event);
      };
      int count = db.RemoveIf(predicate);
      cout << "Removed " << count << " entries" << endl;
    } else if (command == "Find") {
      auto condition = ParseCondition(is);
      auto predicate = [condition](const Date& date, const string& event) {
        return condition->Evaluate(date, event);
      };

      const auto entries = db.FindIf(predicate);
      for (const auto& entry : entries) {
        cout << entry << endl;
      }
      cout << "Found " << entries.size() << " entries" << endl;
    } else if (command == "Last") {
      try {
          cout << db.Last(ParseDate(is)) << endl;
      } catch (invalid_argument&) {
          cout << "No entries" << endl;
      }
    } else if (command.empty()) {
      continue;
    } else {
      throw logic_error("Unknown command: " + command);
    }
  }

  return 0;
}

void TestParseEvent() {
  {
    istringstream is("event");
    AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
  }
  {
    istringstream is("   sport event ");
    AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
  }
  {
    istringstream is("  first event  \n  second event");
    vector<string> events;
    events.push_back(ParseEvent(is));
    events.push_back(ParseEvent(is));
    AssertEqual(events, vector<string>{"first event  ", "second event"}, "Parse multiple events");
  }
}

void TestParseDate() {
    {
        istringstream is("2017-11-06");
        AssertEqual(ParseDate(is), Date(2017,11,06), "Parse date without leading spaces");
    }
    {
        istringstream is("   2017-11-06 ");
        AssertEqual(ParseDate(is), Date(2017,11,06), "Parse date with leading spaces");
    }
    {
        istringstream is("2017-11-6");
        AssertEqual(ParseDate(is), Date(2017,11,06), "Parse multiple events");
    }
}


void TestAll() {
  TestRunner tr;
    tr.RunTest(TestParseDate, "TestParseDate");
    tr.RunTest(TestParseEvent, "TestParseEvent");
    tr.RunTest(TestParseCondition, "TestParseCondition");
}
