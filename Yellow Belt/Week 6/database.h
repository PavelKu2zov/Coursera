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
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

/*---------------------------------------------class Database--------------------------------------*/
class Database {
public:
    void Add(const Date& date,  const string& event);

    void Print(ostream& stream) const;

    void PrintEvents(const Date& date) const;

    int RemoveIf(function<bool(const Date&, const string&)> p );

    vector<string> FindIf(function<bool(const Date&, const string&)> p ) const;

    string Last(const Date& date) const;

private:
    map<Date,vector<string>> bd;
};
