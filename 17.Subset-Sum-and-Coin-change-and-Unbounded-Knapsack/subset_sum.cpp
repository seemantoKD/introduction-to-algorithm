#include <bits/stdc++.h>
using namespace std;

int val[1005];

bool subset_sum(int i, int sum)
{
    // base case
    if (i < 0)
        return sum == 0;

    if (val[i] <= sum)
    {
        // case 1 : neya psbl
        // 2 options
        // 1. nebo , 2. nebo na
        bool op1 = subset_sum(i - 1, sum - val[i]);
        bool op2 = subset_sum(i - 1, sum);
        return op1 || op2;
    }

    else
    {
        // case 2 : neya psbl na
        // 1 options
        // nibo na
        return subset_sum(i - 1, sum);
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> val[i];

    int sum;
    cin >> sum;

    bool psbl = subset_sum(n - 1, sum);
    if (psbl)
        cout << "Possible\n";
    else
        cout << "Not possible\n";
    return 0;
}
// complexity -> o(2^N)