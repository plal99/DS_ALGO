#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int matrixChain(int arr[], int n, int i, int j);

int main()
{
    int arr[] = {3,2,4,2,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof(dp));
    int temp = matrixChain(arr, n, 1, n - 1);
    cout << temp;
}

int matrixChain(int arr[], int n, int i, int j)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = 999;
    for (int k = i; k < j; k++)
        dp[i][j] = min(dp[i][j], matrixChain(arr, n, i, k) + matrixChain(arr, n, k + i, j) + arr[i - 1] * arr[k] * arr[j]);
    // c[i-j] = min(c[i-k] + c[k+1 - j] + d(i-1)*d(k)*d(j))

    return dp[i][j];
}