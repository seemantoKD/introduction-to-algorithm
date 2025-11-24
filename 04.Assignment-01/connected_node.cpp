#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;

    vector<int> adj_list[node];

    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int c;
        cin >> c;

        vector<int> v = adj_list[c];

        if (v.size() == 0)
        {
            cout << -1 << endl;
            continue;
        }

        sort(v.begin(), v.end(), greater<int>());
        for (int val : v)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}