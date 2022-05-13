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
    JZ47Solution test;
    vector<vector<int>> s;
    vector<int> a1({1,3,1});
    vector<int> a2({1,5,1});
    vector<int> a3({4,2,1});
    s.push_back(a1);
    s.push_back(a2);
    s.push_back(a3);
    cout<<test.maxValue(s);
    return 0;
}
