#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if ((range_end-range_begin)<2)
        return;
    vector<typename RandomIt::value_type> elements(range_begin,range_end);

    auto part1 = begin(elements) + elements.size()/3;
    auto part2 = part1 + elements.size()/3;

    MergeSort(begin(elements),part1);
    MergeSort(part1,part2);
    MergeSort(part2,end(elements));
    vector<typename RandomIt::value_type> dis;
    merge(begin(elements),part1,part1,part2,std::back_inserter(dis));
    merge(begin(dis),end(dis),part2,end(elements),range_begin);
}

int main()
{
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}