#pragma once
#include <string>
#include <stdexcept>
#include <sstream>

using namespace std;

class Date {
public:

    Date(int y,int m, int d);

    int GetYear() const;

    int GetMonth() const;

    int GetDay() const;

private:
    int day;
    int month;
    int year;
};

bool operator<(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);

bool operator>=(const Date& lhs, const Date& rhs);

bool operator<=(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& oStream,const Date& date);

Date ParseDate(istringstream& is);