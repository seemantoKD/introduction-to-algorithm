#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool visited[1000];

void dfs(int source)
{
    // print
    // cout << source << " ";
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

    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));

    int component_count = 0;
    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            // cout << endl;
            component_count++;
        }
    }
    cout << component_count << endl;
    return 0;
}