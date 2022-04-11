#include <database.h>

using namespace std;


void Database::Add(const Date& date,  const string& event)
{
    if (!event.empty())
    {
        int sizeBefore = bdS[date].size();
        bdS[date].insert(event);
        if (sizeBefore < bdS[date].size())
            bd[date].push_back(event);
    }
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


int Database::RemoveIf(function<bool(const Date&, const string&)> p )
{
    int countErase = 0;
    int countEraseLast = 0;

    for(auto it = bd.begin(); it != bd.end(); )
    {
        auto itRemove = remove_if(it->second.begin(), it->second.end(),
                  [it, p](string str) { return p(it->first, str); });


        countErase += it->second.end() - itRemove;

        it->second.erase(itRemove,it->second.end());

        if (it->second.empty())
        {
            bdS.erase(it->first);
            it = bd.erase(it);
        }
        else
        {
            if (countEraseLast != countErase)
            {
                bdS[it->first].clear();
                bdS[it->first] = std::set<string>(it->second.begin(), it->second.end());
                countEraseLast = countErase;
            }
            it++;
        }
    }
    return countErase;
}

vector<string> Database::FindIf(function<bool(const Date&, const string&)> p ) const
{
    vector<string> result;


    for (auto it = bd.begin(); it != bd.end(); it++) {
        auto itFind = it->second.begin();

        while (itFind != it->second.end()) {
            itFind = find_if(itFind, it->second.end(),
                             [it, p](string str) { return p(it->first, str); });

            if (itFind != it->second.end()) {
                ostringstream is;
                is << it->first << " " << *itFind;
                result.push_back(is.str());
                itFind++;
            }
        }
    }

    return result;
}

string Database::Last(const Date& date) const
{
    const auto itr_upper = bd.upper_bound(date);

    if (itr_upper == bd.begin())
    {
        throw std::invalid_argument("No entries");
    }
    ostringstream is;
    is << prev(itr_upper)->first << " " << prev(itr_upper)->second.back();
    return is.str();



}