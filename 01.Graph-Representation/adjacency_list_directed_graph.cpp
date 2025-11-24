#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;

    vector<int> adj_list[node]; // array of vector

    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b); // array -r a number index e giye j vector pailam sekhane b push_back korlam
    }

    // printing adjacency list
    for (int i = 0; i < node; i++) // loop for array
    {
        cout << i << " -> ";
        for (int val : adj_list[i]) // loop for vector
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}