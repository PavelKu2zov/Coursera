#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>

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
/*
class Rational {
// Вставьте сюда реализацию класса Rational
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        int NOD = gcd(numerator,denominator);
        if (denominator == 0)
        {
            throw std::invalid_argument("Denominator must not be 0.");
        }
        num = numerator/NOD;
        den = denominator/NOD;
        if ((num<0)&&(den<0))
        {
            num *= -1;
            den *= -1;
        }
        else if ((num>0)&&(den<0))
        {
            num *= -1;
            den *= -1;
        }

        if (numerator == 0)
        {
            den = 1;
        }
    }

    int Numerator() const {
        // Реализуйте этот метод
        return num;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return den;
    }

private:
    // Добавьте
    int num;
    int den;
};

*/
Rational operator+(const Rational& lhs, const Rational& rhs)
{
    int Numerator = lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator();
    int Denominator = lhs.Denominator()*rhs.Denominator();

    return Rational(Numerator,Denominator);
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    int Numerator = lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator();
    int Denominator = lhs.Denominator()*rhs.Denominator();

    return Rational(Numerator,Denominator);
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator()*rhs.Numerator(),lhs.Denominator()*rhs.Denominator());
}

// Вставьте сюда реализацию operator / для класса Rational
Rational operator/(const Rational& lhs, const Rational& rhs)
{
    if (rhs.Numerator() == 0)
    {
        throw std::domain_error("Denominator must not be 0.");
    }
    return Rational(lhs.Numerator()*rhs.Denominator(),lhs.Denominator()*rhs.Numerator());
}

istream& operator>>(istream& stream, Rational& r)
{
    int numerator,denominator;
    char sym;

    stream >> numerator;

    if(stream)
    {
        stream >> sym;
        if (stream)
        {
            if (sym == '/')
            {
                stream >> denominator;
                if (stream)
                {
                    r = Rational(numerator,denominator);
                }
            }
        }

    }
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& r)
{
    if (r.Denominator() <= 0)
        throw std::invalid_argument("");

    stream << r.Numerator() << "/" <<r.Denominator();
    return stream;
}

void Test_1()
{
    Rational r;
    ostringstream os;
    os.str("");
    os << r;
    AssertEqual("0/1",os.str());

    Rational r2(0,-268435455);
    os.str("");
    os << r2;
    AssertEqual("0/1",os.str());
}

void Test_2()
{
    Rational r(3,9);
    ostringstream os;
    os.str("");
    os << r;
    AssertEqual("1/3",os.str());
    Rational r1(9,3);
    os.str("");
    os << r1;
    AssertEqual("3/1",os.str());
    Rational r3(456,13);
    os.str("");
    os << r3;
    AssertEqual("456/13",os.str());

    Rational r4(268435455,-268435455);
    os.str("");
    os << r4;
    AssertEqual("-1/1",os.str());

}
void Test_3()
{
    Rational r(3,-9);
    ostringstream os;
    os.clear();
    os << r;
    AssertEqual("-1/3",os.str());
    Rational r1(-3,9);
    os.str("");
    os << r1;
    AssertEqual("-1/3",os.str());
    Rational r2(-3,-9);
    os.str("");
    os << r2;
    AssertEqual("1/3",os.str());
}

void Test_4()
{
    Rational r(3,-9);
    ostringstream os;
    os.clear();
    os << r;
    AssertEqual("-1/3",os.str());
    Rational r1(-3,9);
    os.str("");
    os << r1;
    AssertEqual("-1/3",os.str());
    Rational r2(-3,-9);
    os.str("");
    os << r2;
    AssertEqual("1/3",os.str());
}

void Test_5()
{
    Rational r(2147483647, 2147483647);
    ostringstream os;
    os.clear();
    os << r;
    AssertEqual("1/1",os.str());

}

int main() {
    TestRunner runner;
    // добавьте сюда свои тесты
    runner.RunTest(Test_1,"Test #1");
    runner.RunTest(Test_2,"Test #2");
    runner.RunTest(Test_3,"Test #3");
    runner.RunTest(Test_4,"Test #4");
    runner.RunTest(Test_5,"Test #5");


  return 0;
}
