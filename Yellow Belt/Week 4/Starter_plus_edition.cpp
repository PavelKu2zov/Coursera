#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

#define DAYS    (400*365) + 400/4

struct dateStruct
{
    uint32_t year;
    uint32_t month;
    uint32_t day;
};

map<uint32_t,uint32_t> months = {{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};

uint32_t GetDayMonths(dateStruct date);
uint32_t GetDayYear(dateStruct date);

istream& operator>>(istream& stream,dateStruct& date)
{
    stream >> date.year;
    stream.ignore(1);
    stream >> date.month;
    stream.ignore(1);
    stream >> date.day;
    return stream;
}

bool operator < (const dateStruct& lhs,const dateStruct& rhs)
{
    bool result = false;
    uint32_t lhsDays,rhsDays;

    lhsDays = GetDayYear(lhs) + GetDayMonths(lhs) + lhs.day;
    rhsDays = GetDayYear(rhs) + GetDayMonths(rhs) + rhs.day;
    if (lhsDays < rhsDays)
        result = true;
    else
        result = false;

    return result;
}

pair<dateStruct,int> operator + ( pair<dateStruct,int>& lhs, pair<dateStruct,int>& rhs)
{
    pair<dateStruct,int> result;

    result.first = rhs.first;
    result.second = lhs.second + rhs.second;

    return result;
}


uint32_t GetDayMonths(dateStruct date)
{
    uint32_t day=0;
    auto it = begin(months);
    for (uint32_t i=1;i < date.month;i++)
    {
        if ((i == 2) && (date.year%4 == 0))
        {
            day += 29;
        }
        else
        {
            day += it->second;
        }
        it++;
    }
    return day;
}

uint32_t GetDayYear(dateStruct date)
{
    uint32_t day=0;
    date.year -=1700;
    day = date.year * 365;
    if (date.year%4 == 0)
        day += (date.year/4)-1;
    else
        day += date.year/4;

    return day;
}

int main()
{
    vector<uint64_t> budget(DAYS);
    int numberDays,Q;

    cin >> numberDays;

    for (int i=0;i<numberDays;i++)
    {
        dateStruct dateIn;
        int E;
        cin >> dateIn >> E;
        uint32_t numberDay = GetDayYear(dateIn)+ GetDayMonths(dateIn) + dateIn.day;
        budget[numberDay]= E;
    }

    cin >> Q;
    vector<uint64_t> money(DAYS);
    partial_sum(budget.begin(),budget.end(),money.begin());

    for (int i=0;i<Q;i++)
    {
        dateStruct dateBegin,dateEnd;

        cin >> dateBegin >> dateEnd;
        uint32_t dayBegin = GetDayYear(dateBegin)+ GetDayMonths(dateBegin)+dateBegin.day;
        uint32_t dayEnd = GetDayYear(dateEnd)+ GetDayMonths(dateEnd)+dateEnd.day;
        cout << money[dayEnd]-money[dayBegin]+budget[dayBegin] << endl;
    }


    return 0;
}