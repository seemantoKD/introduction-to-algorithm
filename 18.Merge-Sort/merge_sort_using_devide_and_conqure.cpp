#include <bits/stdc++.h>
using namespace std;

void conquer(int c[], int l, int mid, int r)
{
    // work for left array/left part
    int n = mid - l + 1;
    int left_arr[n];
    int k = l; // c arrayr pointer
    for (int i = 0; i < n; i++, k++)
    {
        left_arr[i] = c[k];
        // left_arr[i] = c[k++];
        // k++;
    }

    // work for right part/right array
    int m = r - mid;
    int right_arr[m];
    k = mid + 1;
    for (int i = 0; i < m; i++, k++)
    {
        right_arr[i] = c[k];
    }

    int i = 0, j = 0, curr = l;

    while (i < n && j < m)
    {
        if (left_arr[i] < right_arr[j])
        {
            c[curr++] = left_arr[i++];
        }

        else
        {
            c[curr++] = right_arr[j++];
        }
    }

    while (i < n)
    {
        c[curr++] = left_arr[i++];
    }

    while (j < m)
    {
        c[curr++] = right_arr[j++];
    }
}

void devide(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int mid = (l + r) / 2;
    devide(arr, l, mid);
    devide(arr, mid + 1, r);
    conquer(arr, l, mid, r);
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

    // devide function call
    devide(arr, 0, n - 1);

    // print the final array
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}