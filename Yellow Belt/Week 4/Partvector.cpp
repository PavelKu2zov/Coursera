#include <vector>
#include <iostream>
using namespace std;

//void PrintVectorPart(const vector<int>& numbers);

void PrintVectorPart(const vector<int>& numbers)
{
    for(auto it = begin(numbers); it != end(numbers);it++)
    {
        if (*it < 0)
        {
            if  (it == begin(numbers))
                break;
            while(it != begin(numbers))
            {
                it--;
                cout << *it << ' ';
            }
            break;
        }
        else if (it+1 == end(numbers))
        {
            it++;
            while(it != begin(numbers))
            {
                it--;
                cout << *it << ' ';
            }
            break;
        }
    }
}

/*
int main()
{
    PrintVectorPart({6, 1, 8, -5, 4});
    cout << endl;
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    cout << endl;
    PrintVectorPart({6, 1, 8, 5, 4});
    cout << endl;

    return 0;
}*/