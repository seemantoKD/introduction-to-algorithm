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
        adj_list[b].push_back(a); // only use when graph is undirected
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

/*
step :
    1. node and edge input
    2. array of vector declare
    3. while(edge--)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); //for undirected graph only
    }
    4. print adjacency list
        ->code :
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
*/