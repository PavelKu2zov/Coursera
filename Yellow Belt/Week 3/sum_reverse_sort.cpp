#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y)
{
    return x+y;
}

string Reverse(string s)
{
    string revStr;
    for(int i=s.size()-1;i>=0;i--)
    {
        revStr.push_back(s[i]);
    }
    return revStr;
}

void Sort(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
}
