#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool visited[1000];
int parent[1000];
bool cycle;

void dfs(int src)
{
    // cout << src << " ";
    visited[src] = true;

    for (int child : adj_list[src])
    {
        if (visited[child] && parent[src] != child)
        {
            cycle = true;
        }

        if (!visited[child])
        {
            parent[child] = src;
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
    memset(parent, -1, sizeof(parent));
    cycle = false;

    // dfs for disconnected graph
    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    /*
    // parent print
    for (int i = 0; i < node; i++)
    {
        cout << i << " parent-> " << parent[i] << endl;
    }
    */

    if (cycle)
    {
        cout << "Cycle detected\n";
    }

    else
    {
        cout << "Cycle not found\n";
    }
    return 0;
}