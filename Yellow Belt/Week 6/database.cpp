#include <database.h>

using namespace std;

void Database::Add(const Date& date,  const string& event)
{
    if (!event.empty()) {
        if (bd[date].empty()) {
            bd[date].push_back(event);
        } else if (find(begin(bd[date]), end(bd[date]), event) == end(bd[date])) {
            bd[date].push_back(event);
        }
    }
}
/*
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
*/
/*
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
*/
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

int Database::RemoveIf(function<bool(const Date&, const string&)> p )
{
    int countErase = 0;

    for(auto it = bd.begin(); it != bd.end(); )
    {
        auto itRemove = remove_if(it->second.begin(), it->second.end(),
                  [it, p](string str) { return p(it->first, str); });

        countErase += it->second.end() - itRemove;

        it->second.erase(itRemove,it->second.end());

        if (it->second.empty())
        {
            it = bd.erase(it);
        }
        else
        {
            it++;
        }
    }
    return countErase;
}

vector<int> Database::FindIf(function<bool(const Date&, const string&)> p )
{
    return vector<int>{1,2,3};
}

string Database::Last(const Date& date) const
{
    return "";
}