#include <bits/stdc++.h>
using namespace std;

void LCS(string a, string b);

int main()
{
    string a = "AGGTAB";
    string b = "GXTXAYB";

    LCS(a, b);
}

void LCS(string a, string b)
{
    int m = a.size();
    m++;
    int n = b.size();
    n++;
    int dp[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[m-1][n-1] << "\n";
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    int i = m - 1;
    int j = n - 1;
    // This stack has the longest common substring
    stack<char> substring;
    while(i>=0 && j>=0)
    {
        if(dp[i][j] > dp[i-1][j-1])
        {
            substring.push(a[i - 1]);
            i--;
            j--;
        }
        else
        {
            j--;
        }
    }
    while(!substring.empty())
    {
        cout << substring.top();
        substring.pop();
    }
}