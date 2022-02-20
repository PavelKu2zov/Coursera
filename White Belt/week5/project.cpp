#include <iostream>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <exception>
#include <stdexcept>

using namespace std;
// Реализуйте функции и методы классов и при необходимости добавьте свои

/*----------------------------------------- class Date--------------------------------------*/
class Date {
public:

    Date(int y,int m, int d)
    {
        if ((m < 1) || (m >12))
        {
            throw std::invalid_argument("Month value is invalid: " + to_string(m));
        }
        if ((d < 1) || (d > 31))
        {
            throw std::invalid_argument("Day value is invalid: " + to_string(d));
        }
        year = y;
        month = m;
        day = d;
        
    }

    int GetYear() const
    {
        return year;
    }
    int GetMonth() const
    {
        return month;
    }
    int GetDay() const
    {
        return day;
    }
private:
    int day = 0;
    int month = 0;
    int year = 0; 
};
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
/*---------------------------------------------class Database--------------------------------------*/
class Database {
public:
    void AddEvent(const Date& date,  const string& event)
    {
        bd[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event)
    {
        if (bd.count(date) !=0 )
        {
            if (bd[date].count(event) != 0)
            {
                bd[date].erase(event);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    int  DeleteDate(const Date& date)
    {
        if (bd.count(date) !=0 )
        {
            int numEventsErase = bd[date].size();
            if (numEventsErase == 0)
            {
                return 0;
            }
            else
            {
                bd[date].clear();
                return numEventsErase;
            }
        }
        else
        {
            return 0;
        }
    }

    set<string> Find(const Date& date) const
    {
        return bd.at(date);
    }

    void Print() const
    {
        for(const auto& dates : bd)
        {
            cout << dates.GetYear()<<"-"<< dates.GetMonth()<<"-"<< dates.Getday() << " ";
            for(const auto& event : dates)
            {
                cout << 
            }
        }
    }
private:
    map<Date,set<string>> bd;

};
/*------------------------------------------ end class Database ------------------------------------*/

int main() {
    Database bd;

    string command;
    stringstream inSStream;
    while (getline(cin, command)) 
    {
    // Считайте команды с потока ввода и обработайте каждую
        inSStream << command;
        string CMD,event;
        int year,month,day;
        inSStream >> CMD;
        if ("Add" == CMD)
        {
            inSStream >> year;
            inSStream.ignore(1);
            inSStream >> month;
            inSStream.ignore(1);
            inSStream >> day;
            inSStream.ignore(1);

            try
            {   
                Date date(year,month,day);
                inSStream >> event;
                bd.AddEvent(date,event);
            }
            catch (invalid_argument& ex) 
            {
                cout << ex.what() << endl;
                break;
            } 


        }
        else if ("Del" == CMD)
        {

        } 
        else if ("Find" == CMD)
        {

        }
        else if ("Print" == CMD)
        {
            for(auto& item : bd)
            {
                cout bd
            }
        }
        else
        {
            cout << "Unknown command: " << CMD;
            break;
        }

    }

  return 0;
}