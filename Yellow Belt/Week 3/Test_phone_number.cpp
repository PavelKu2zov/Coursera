#include "TestFrameWork.h"
#include "phone_number.h"

using namespace std;


void Test_1()
{
    AssertEqual("+7-495-1232345",PhoneNumber("+7-495-1232345").GetInternationalNumber());
    AssertEqual("+7-495-1232345",PhoneNumber("+7-495-1232345").GetInternationalNumber());
    AssertEqual("+7-495-1232345",PhoneNumber("+--").GetInternationalNumber());
}

int main()
{
    TestRunner runner;
    runner.RunTest(Test_1,"Test #1");
    return 0;
}