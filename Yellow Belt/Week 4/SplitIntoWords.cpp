#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> SplitIntoWords(const string& s)
{
    vector<string> result;
    stringstream strStream;

    for (auto it = begin(s); it != end(s); it++)
    {
        if ((*it == ' ') || (it+1 == end(s)))
        {
            string tempStr;
            if (it+1 == end(s))
                strStream << *it;
            strStream >> tempStr;
            result.push_back(tempStr);
            strStream.clear();
        }
        else
        {
            strStream << *it;
        }
    }

    return result;
}

int main()
{
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}