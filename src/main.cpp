#include <iostream>
#include "AboutList.hpp"
#include "AboutOther.hpp"
#include "AboutSearch.hpp"
#include "AboutDynamicProgramming.hpp"
#include "AboutBack.hpp"
#include "AboutSimulation.hpp"
using namespace std;
int main()
{
    cout << "---Solution Call---" << endl;
    JZ44Solution test;
    cout<<test.findNthDigit(500000000);
    return 0;
}
