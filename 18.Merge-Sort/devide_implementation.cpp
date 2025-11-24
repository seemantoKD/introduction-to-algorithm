#include <bits/stdc++.h>
using namespace std;

void devide(int arr[], int l, int r)
{
    // Print current segment
    for (int i = l; i <= r; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // base case
    if (l >= r)
    {
        return;
    }

    int mid = (l + r) / 2;
    devide(arr, l, mid);     // left part
    devide(arr, mid + 1, r); // right part
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // function call
    devide(arr, 0, n - 1);
    return 0;
}