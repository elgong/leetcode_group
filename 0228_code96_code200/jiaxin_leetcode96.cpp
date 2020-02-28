#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numTrees(int n)
    {
        int dp[n + 1];
        memset(dp, 0, sizeof(0));
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }
};