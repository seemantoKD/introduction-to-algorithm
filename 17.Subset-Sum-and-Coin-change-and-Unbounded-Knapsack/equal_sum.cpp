#include <bits/stdc++.h>
using namespace std;

int val[1005];
int dp[1005][1005];

bool subset_sum(int i, int sum)
{
    if (i < 0)
        return sum == 0;
    if (dp[i][sum] != -1)
        return dp[i][sum];

    if (val[i] <= sum)
    {
        bool op1 = subset_sum(i - 1, sum - val[i]);
        bool op2 = subset_sum(i - 1, sum);
        return dp[i][sum] = op1 || op2;
    }

    else
        return dp[i][sum] = subset_sum(i - 1, sum);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> val[i];

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += val[i];

    if (sum & 1)
    {
        cout << "NO\n";
        return 0;
    }
    sum /= 2;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= sum; j++)
            dp[i][j] = -1;

    bool psbl = subset_sum(n - 1, sum);
    cout << (psbl ? "YES\n" : "NO\n");
    return 0;
}