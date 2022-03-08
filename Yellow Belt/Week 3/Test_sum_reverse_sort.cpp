#include "sum_reverse_sort.h"
#include "TestFrameWork.h"

using namespace std;


void Test_sum()
{
    AssertEqual(5, Sum(2,3));
    AssertEqual(-1, Sum(2,-3));
    AssertEqual(100, Sum(50,50));
}

void Test_revers_string()
{
    AssertEqual("qwerty", Reverse("ytrewq"));
    AssertEqual("qwerty ", Reverse(" ytrewq"));
}

void Test_sort_vector()
{
    vector<int> v = {3,4,2,1};
    vector<int> v1 = {1,2,3,4};
    Sort(v);

    AssertEqual(v1, v);
}


int main()
{
    TestRunner runner;

    runner.RunTest(Test_sum,"Test sum");
    runner.RunTest(Test_revers_string,"Test revers string");
    runner.RunTest(Test_sort_vector,"Test sort vector");

    return 0;
}