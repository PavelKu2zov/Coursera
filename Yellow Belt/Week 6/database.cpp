#include <database.h>

using namespace std;

void Database::Add(const Date& date,  const string& event)
{
    bd[date].insert(event);
}

bool Database::DeleteEvent(const Date& date, const string& event)
{
    bool result = false;
    if (bd.count(date)!=0)
    {
        result = bd[date].erase(event);
        if (bd[date].size()==0)
        {
            bd.erase(date);
        }
        result = result;
    }
    return result;
}

int  Database::DeleteDate(const Date& date)
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

set<string> Database::Find(const Date& date) const
{
    return bd.at(date);
}

void Database::Print(ostream& stream) const
{
    for(const auto& date : bd)
    {
        for(const auto& event : date.second)
        {
            stream << setfill('0')<<setw(4)<<date.first.GetYear()<<"-"<< setw(2)<<date.first.GetMonth()\
            <<"-"<< setw(2)<<date.first.GetDay() << " " << event << endl;
        }
    }
}

void Database::PrintEvents(const Date& date) const
{
    if (bd.count(date) !=0)
    {
        for(const auto& event : bd.at(date))
        {
            cout << event << endl;
        }
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
            char def1,def2;
            inSStream >> CMD;

            if ("Add" == CMD)
            {
                inSStream >> year >> def1 >> month >> def2 >> day;
                if ((inSStream) && (inSStream.peek() == ' ') && (def1 == '-')&& (def2 == '-'))
                {
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
                else
                {
                    stringstream inSStream2;
                    string str1,str2;
                    inSStream2 << command;
                    inSStream2 >> str1 >> str2;
                    cout << "Wrong date format: "<< str2 << endl;
                    break;
                }
            }
            else if ("Del" == CMD)
            {
                try
                {
                    inSStream >> year >> def1 >> month >> def2 >> day;
                    if (!((inSStream) && ((inSStream.peek() == ' ') || (inSStream.peek() == EOF) && (def1 == '-') && (def2 == '-'))))
                    {
                        stringstream inSStream2;
                        string str1,str2;
                        inSStream2 << command;
                        inSStream2 >> str1 >> str2;
                        cout << "Wrong date format: "<< str2 << endl;
                        break;
                    }

                    if (inSStream.peek() == ' ')
                    {
                        Date date(year,month,day);
                        inSStream >> event;
                        if (event.size()!=0)
                        {
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
                            stringstream inSStream2;
                            string str1,str2;
                            inSStream2 << command;
                            inSStream2 >> str1 >> str2;
                            cout << "Wrong date format: "<< str2<< " " << endl;
                            break;
                        }
                    }
                    else
                    {
                        Date date(year,month,day);
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
                    inSStream >> year >> def1 >> month >> def2 >> day;
                    if ((inSStream) && (inSStream.peek() == EOF) && (def1 == '-')&& (def2 == '-'))
                    {
                        Date date(year,month,day);
                        bd.PrintEvents(date);
                    }
                    else
                    {
                        stringstream inSStream2;
                        string str1,str2;
                        inSStream2 << command;
                        inSStream2 >> str1 >> str2;
                        cout << "Wrong date format: "<< str2 << endl;
                        break;
                    }
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