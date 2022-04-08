#include <date.h>

using namespace std;

/*----------------------------------------- class Date--------------------------------------*/
Date::Date(int y,int m, int d)
{
    if ((m < 1) || (m >12))
    {
        throw std::invalid_argument("Month value is invalid: " + to_string(m));
    }
    if ((d < 1) || (d > 31))
    {
        throw std::invalid_argument("Day value is invalid: " + to_string(d));
    }
    if (y < 0)
    {
        year = y*(-1);
    }
    else
    {
        year = y;
    }
    month = m;
    day = d;
}
int Date::GetYear() const
{
    return year;
}
int Date::GetMonth() const
{
    return month;
}
int Date::GetDay() const
{
    return day;
}

/*-------------------------------------- end class Date -----------------------------------*/

bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() < rhs.GetYear())
    {
        return true;
    }
    else if (lhs.GetYear() > rhs.GetYear())
    {
        return false;
    }
    else
    {
        if (lhs.GetMonth() < rhs.GetMonth())
        {
            return true;
        }
        else if (lhs.GetMonth() > rhs.GetMonth())
        {
            return false;
        }
        else
        {
            if (lhs.GetDay() < rhs.GetDay())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

bool operator==(const Date& lhs, const Date& rhs)
{
    if ((lhs.GetYear() == rhs.GetYear()) &&  (lhs.GetMonth() == rhs.GetMonth()) && (lhs.GetDay() == rhs.GetDay()))
    {
        return true;
    }
    return false;
}

Date ParseDate(istringstream& is)
{
    int year,month,day;
    char def1,def2;

    is >> year >> def1 >> month >> def2 >> day;

    if ((is) && (is.peek() == ' ') && (def1 == '-')&& (def2 == '-'))
    {
        try
        {
            return Date(year,month,day);
        }
        catch (invalid_argument& ex)
        {
            //cout << ex.what() << endl;
        }
    }

    return Date(0,0,0);
}