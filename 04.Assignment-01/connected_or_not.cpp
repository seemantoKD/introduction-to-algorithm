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
    }

    int q;
    cin >> q;
    while (q--)
    {
        int c, d;
        cin >> c >> d;

        bool found = false;
        for (int val : adj_list[c])
        {
            if (val == d)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            cout << "YES\n";
        }

        else
        {
            if (!found && c == d)
            {
                cout << "YES\n";
            }

            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}