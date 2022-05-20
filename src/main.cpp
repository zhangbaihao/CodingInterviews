#include <iostream>
#include "AboutList.hpp"
#include "AboutOther.hpp"
#include "AboutSearch.hpp"
#include "AboutDynamicProgramming.hpp"
#include "AboutBack.hpp"
#include "AboutSimulation.hpp"
using namespace std;
int dp[35][35] = {0};
bool isMatch(string s, string p)
{
    int len1 = s.length();
    int len2 = p.length();
    dp[0][0] = 1;
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (j >= 2 && p[j - 1] == '*')
            {
                if (i > 0 && p[j - 2] == s[i - 1] || p[j - 2] == '.')
                {
                    dp[i][j] |= dp[i - 1][j];
                }
                dp[i][j] |= dp[i][j - 2];
            }
            else if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
            {
                if (i > 0)
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[len1][len2] == 1;
}

int main()
{
    cout << "---Solution Call---" << endl;
    JZ62Solution test;
    test.LastRemaining_Solution2(5,3);
    return 0;
}
