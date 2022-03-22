#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <sstream>
#include "TestFrameWork.h"

extern float run(string str);

using namespace std;

void Test_1()
{
    AssertEqual(20,run("5\r\n"
                       "Earn 2000-01-01 2001-01-03 20\r\n"
                       "ComputeIncome 2000-01-01 2000-01-03\r\n"));

}


int main()
{
    TestRunner runner;
    runner.RunTest(Test_1,"Test #1");
    return 0;
}