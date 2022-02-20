#include <iostream>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <iomanip>

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
        return bd[date].erase(event);
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
                //bd[date].clear();
                bd.erase(date);
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
        for(const auto& date : bd)
        {
            cout << setfill('0')<<setw(4)<<date.first.GetYear()<<"-"<< setw(2)<<date.first.GetMonth()\
                <<"-"<< setw(2)<<date.first.GetDay() << " ";

            int cnt=0;
            for(const auto& event : date.second)
            {
                if (cnt == date.second.size()-1)
                {
                    cout << event;
                }
                else
                {
                    cout << event << " ";
                    cnt++;
                }
            }
            cout << endl;
        }
    }
    void PrintEvents(const Date& date) const
    {
        if (bd.count(date) !=0)
        {
            for(const auto& event : bd.at(date))
            {
                cout << event << endl;
            }
         }
    }
private:
    map<Date,set<string>> bd;

};
/*------------------------------------------ end class Database ------------------------------------*/

Date GetDate(string& str)
{
    int year,month,day;
    stringstream inSStream(str);

    inSStream >> year;
    if (!inSStream.fail())
    {
        inSStream.ignore(1);
        inSStream >> month;
        if(!inSStream.fail())
        {
            inSStream.ignore(1);
            inSStream >> day;
            if(!inSStream.fail())
            {
                return Date(year,month,day);
            }
            else
            {
                throw std::invalid_argument("Wrong date format: " + str);
            }
        }
        else
        {
            throw std::invalid_argument("Wrong date format: " + str);
        }
    }
    else
    {
        throw std::invalid_argument("Wrong date format: " + str);
    }
    
}


int main() {
    Database bd;

    string command;
    stringstream inSStream;
    while (getline(cin, command)) 
    {
    // Считайте команды с потока ввода и обработайте каждую

        inSStream.clear();
        if (command.size() != 0)
        {
            inSStream << command;
            string CMD,event,dateStr;
            int year,month,day;
            inSStream >> CMD;
        
            if ("Add" == CMD)
            {
                try
                {   
                    inSStream >> dateStr;
                    Date date = GetDate(dateStr);
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
                try
                {   
                    inSStream >> dateStr;
                    //cout << "dataStr = " << dateStr << endl;
                    Date date = GetDate(dateStr);

                    inSStream >> event;
                    if (event.size()!=0)
                    {
                        //cout << "event = " << event << endl;
                        if ( true == bd.DeleteEvent(date,event))
                        {
                            cout << "Deleted successfully" << endl;
                        }
                        else
                        {
                            cout << "Event not found" << endl;
                        }
                    }
                    else
                    {   
                        cout << "Deleted " << bd.DeleteDate(date) << " events" << endl;    
                    }
                }
                catch (invalid_argument& ex) 
                {
                    cout << ex.what() << endl;
                    break;
                } 
            } 
            else if ("Find" == CMD)
            {
                try
                {   
                    inSStream >> dateStr;
                    Date date = GetDate(dateStr);
                    bd.PrintEvents(date);
                }
                catch (invalid_argument& ex) 
                {
                    cout << ex.what() << endl;
                    break;
                } 

                
            }
            else if ("Print" == CMD)
            {
                bd.Print();
            }
            else
            {
                cout << "Unknown command: " << CMD;
                break;
            }
        }
    }

  return 0;
}