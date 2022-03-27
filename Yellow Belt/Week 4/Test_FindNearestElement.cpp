#include <vector>
#include <map>
#include "TestFrameWork.h"

using namespace std;

extern set<int>::const_iterator FindNearestElement(
        const set<int>& numbers,
        int border);

void Test_1()
{
    set<int> numbers = {1, 4, 6};
    AssertEqual(1,*FindNearestElement(numbers, 0));
    AssertEqual(4,*FindNearestElement(numbers, 3));
    AssertEqual(4,*FindNearestElement(numbers, 5));
    AssertEqual(6,*FindNearestElement(numbers, 6));
    AssertEqual(6,*FindNearestElement(numbers, 100));

}

void Test_2()
{
    set<int> numbers = {1, 4, 6,10,21,30,34};
    AssertEqual(1,*FindNearestElement(numbers, 0));
    AssertEqual(4,*FindNearestElement(numbers, 3));
    AssertEqual(4,*FindNearestElement(numbers, 5));
    AssertEqual(6,*FindNearestElement(numbers, 6));
    AssertEqual(34,*FindNearestElement(numbers, 100));
    AssertEqual(21,*FindNearestElement(numbers, 23));
    AssertEqual(21,*FindNearestElement(numbers, 21));
    AssertEqual(10,*FindNearestElement(numbers, 15));
    AssertEqual(21,*FindNearestElement(numbers, 16));
    AssertEqual(10,*FindNearestElement(numbers, 15));
    AssertEqual(30,*FindNearestElement(numbers, 32));
    AssertEqual(34,*FindNearestElement(numbers, 34));
    AssertEqual(1,*FindNearestElement(numbers, 1));

}

void Test_3()
{
    set<int> numbers;
    AssertEqual(true,FindNearestElement(numbers, 0) == end(numbers));
    AssertEqual(true,FindNearestElement(numbers, 100) == end(numbers));
    AssertEqual(true,FindNearestElement(numbers, 25) == end(numbers));


}

int main()
{
    TestRunner runner;
    runner.RunTest(Test_1,"Test #1");
    runner.RunTest(Test_2,"Test #2");
    runner.RunTest(Test_3,"Test #3");
    return 0;
}