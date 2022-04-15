#include <iostream>
#include <vector>
#include "AboutList.hpp"
#include "AboutStackAndQueue.hpp"
using namespace std;

int main()
{
    JZ59Solution test;
    vector<int> a({2,3,4,2,6,2,5,1});
    test.maxInWindows(a,3);
    return 0;
}