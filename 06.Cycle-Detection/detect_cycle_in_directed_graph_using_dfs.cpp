#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool visited[1000];
bool path_visited[1000];
bool cycle;

void dfs(int src)
{
    visited[src] = true;
    path_visited[src] = true;

    for (int child : adj_list[src])
    {
        if (visited[child] && path_visited[child])
        {
            cycle = true;
        }

        if (!visited[child])
        {
            dfs(child);
        }
    }
    // ekhane return hobe function
    //  return howar time a path_visited false hobe
    path_visited[src] = false;
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
    }

    memset(visited, false, sizeof(visited));
    memset(path_visited, false, sizeof(path_visited));
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