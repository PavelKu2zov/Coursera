#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if ((range_end-range_begin)<2)
        return;

    /*if ((range_end-range_begin) == 2)
    {
        sort(range_begin,range_end);
        return;
    }*/
    vector<typename RandomIt::value_type> elements(range_begin,range_end);

    MergeSort(begin(elements),RandomIt(begin(elements) + (end(elements)-begin(elements))/2));
    MergeSort(RandomIt(begin(elements) + (end(elements)-begin(elements))/2),end(elements));
    vector<typename RandomIt::value_type> dis;
    merge(begin(elements),RandomIt(begin(elements) + (end(elements)-begin(elements))/2),
          RandomIt(begin(elements) + (end(elements)-begin(elements))/2),end(elements),
          //std::back_inserter(dis));
          range_begin);
    /*auto it2 = begin(dis);
    for (auto it = range_begin; it != range_end ; it++)
    {
        *it = *it2;
        it2++;
    }*/

}

int main()
{
    vector<int> v = {6, 4, 70, 6, 4, 4, 0, 1,10,15};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}