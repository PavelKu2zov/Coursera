#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename DataType>
void RemoveDuplicates(vector<DataType>& elements) {
    sort(begin(elements), end(elements));
    elements.erase(
            unique(begin(elements), end(elements)),
            elements.end());
}


/*
template <typename T>
void RemoveDuplicates(vector<T>& elements)
{
    auto it = begin(elements);
    while(it != end(elements))
    {
        T item = *it;
        it++;
        auto it2 = it;
        while(it2 != end(elements))
        {
            if (item == *it2)
            {
                elements.erase(it2);
            }
            else
            {
                it2++;
            }
        }
    }

}
*/
/*
template <typename T>
void RemoveDuplicates(vector<T>& elements)
{
    auto it = begin(elements);
    while(it != end(elements))
    {
        auto it2 = it+1;
        while(it2 != end(elements))
        {
            it2 = find(it2,end(elements),*it);
            if (it2 != end(elements))
            {
                elements.erase(it2);
            }
        }
        it++;
    }
}
*/

int main()
{
    vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
    RemoveDuplicates(v1);
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;

    vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
    RemoveDuplicates(v2);
    for (const string& s : v2) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}


