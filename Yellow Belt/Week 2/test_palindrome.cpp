#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

bool IsPalindrom(const string& str) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
    bool result = true;

    for (int i=0;i<str.size()/2;i++)
    {
        if (str[i] != str[str.size()-1-i])
        {
            result = false;
            break;
        }
    }
    return result;
}

void Test_1()
{
    AssertEqual(true, IsPalindrom(""));
    AssertEqual(true, IsPalindrom("q"));
    AssertEqual(true, IsPalindrom(" "));
    AssertEqual(true, IsPalindrom("  "));
    AssertEqual(true, IsPalindrom("   "));
    AssertEqual(true, IsPalindrom("!~ &%#@()-+^:;:^+-)(@#%& ~!"));
    AssertEqual(true, IsPalindrom("madam"));
    AssertEqual(false, IsPalindrom(" madam"));
    AssertEqual(true, IsPalindrom(" madam "));
    AssertEqual(false, IsPalindrom(" ma dam"));
    AssertEqual(true, IsPalindrom("ma d am"));
    AssertEqual(false, IsPalindrom("adam"));
    AssertEqual(false, IsPalindrom("mada"));
    AssertEqual(false, IsPalindrom("qweY_Yew"));
    AssertEqual(false, IsPalindrom("weY_Yewq"));
    AssertEqual(false, IsPalindrom("ZweY_YewX"));
    AssertEqual(false, IsPalindrom("123ab321"));
    AssertEqual(false, IsPalindrom("1 23 321"));
    AssertEqual(false, IsPalindrom("Amama"));
    AssertEqual(false, IsPalindrom("amamA"));

}


int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
    runner.RunTest(Test_1,"Test #1");

  return 0;
}
