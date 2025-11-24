#include <bits/stdc++.h>
using namespace std;

long long dp[1005];

long long fibo(long long n)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fibo(n - 1) + fibo(n - 2);
    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof(dp));

    long long n;
    cin >> n;

    cout << fibo(n) << endl;
    return 0;
}
// complexity -> o(2^n)