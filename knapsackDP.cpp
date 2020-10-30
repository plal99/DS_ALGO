#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p[] = {1, 2, 5, 6};
    int wt[] = {2, 3, 4, 5};

    int m = 8, n = 4;

    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            // paddings made 0
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            // knapsack problem
            else if (j >= wt[i - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + p[i - 1]);

            // take the above value
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][m] << "\n";

    int i = n, j = m;
    while(i>0 && j >0)
    {
        if(dp[i][j] == dp[i-1][j])
        {
            i--;
            continue;
        }
        else
        {
            cout << p[i-1] << " ";
            i--;
            j -= wt[i];
        }
        
    }
}