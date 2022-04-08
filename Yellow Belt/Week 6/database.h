#pragma once

#include <iostream>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <iomanip>
#include <date.h>

using namespace std;

/*---------------------------------------------class Database--------------------------------------*/
class Database {
public:
    void Add(const Date& date,  const string& event);

    bool DeleteEvent(const Date& date, const string& event);

    int  DeleteDate(const Date& date);

    set<string> Find(const Date& date) const;

    void Print(ostream& stream) const;

    void PrintEvents(const Date& date) const;

private:
    map<Date,set<string>> bd;
};
