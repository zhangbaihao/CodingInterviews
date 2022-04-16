#include <iostream>
#include "AboutSearch.hpp"

using namespace std;

int main()
{
    cout << "main test" << endl;
    JZ4Solution test;
    vector<vector<int>> a;
    vector<int> b1({1, 2, 8, 9});
    vector<int> b2({2, 4, 9, 12});
    vector<int> b3({4, 7, 10, 13});

    // 1,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
    a.push_back(b1);
    a.push_back(b2);
    a.push_back(b3);
    test.Find(1, a);
    return 0;
}