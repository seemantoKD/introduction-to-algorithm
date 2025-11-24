#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
int visited[1000];

void dfs(int source)
{
    // print
    cout << source << " ";
    visited[source] = true;

    // child er upor loop
    for (int child : adj_list[source])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    // input graph element
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // for undirected
    }

    memset(visited, false, sizeof(visited));
    dfs(0); // source = 0
    cout << endl;
    return 0;
}

/*
step :
    1. globally array of vector and visited array declare
    2. main function er vitor ese node and edge input nibo
    3. adjacency list diye graph input nibo
    4. memset diye visited arrayr sokol element false kore debo
    5. dfs call korbo
    6. dfs e giye
        -> prothome source ta print korbo
        -> child er upor loop calabo nicer moto
            // child er upor loop
            for (int child : adj_list[source])
            {
                if (!visited[child])
                {
                    dfs(child);
                }
            }
*/