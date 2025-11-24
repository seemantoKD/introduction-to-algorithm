#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<int> b(m);

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<int> combine(m + n);

    int i = 0, j = 0, curr = 0;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            combine[curr++] = a[i++];
            //i++;
            //curr++;
        }

        else
        {
            combine[curr++] = b[j++];
            //j++;
            //curr++;
        }
    }

    while (i < n)
    {
        combine[curr++] = a[i++];
        //i++;
        //curr++;
    }

    while (j < m)
    {
        combine[curr++] = b[j++];
        //j++;
        //curr++;
    }

    for (int val : combine)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}