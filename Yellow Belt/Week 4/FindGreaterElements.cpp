#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace  std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> result;
    auto it = find_if(
            begin(elements), end(elements),
            [&border](T item) { return item > border; }
    );
    if (it != end(elements))
    {
       // it++;
        while (it != end(elements)) {
            result.push_back(*it);
            it++;
        }
    }

    return result;
}


int main()
{
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    for (int x : FindGreaterElements(set<int>{1,2,3,5,6,7,8}, 4)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;

    return 0;
}