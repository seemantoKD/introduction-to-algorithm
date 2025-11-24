#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;

    vector<pair<int, int>> edge_list; // pair of vector

    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        edge_list.push_back({a, b});
    }

    // printing edge list
    for (auto p : edge_list) // <- shortcurt of -> for (pair<int, int> p : edge_list)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}

/*
step :
    1. node and edge input
    2. pair of vector declare
    3. while (edge--)
    {
        int a, b;
        cin >> a >> b;
        edge_list.push_back({a, b});
    }
    4. print edge list
        -> code :
        for (auto p : edge_list) // <- shortcurt of -> for (pair<int, int> p : edge_list)
        {
            cout << p.first << " " << p.second << endl;
        }
*/