#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool visited[1000];
int parent[1000];
bool cycle;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        // main kaj

        for (int child : adj_list[par])
        {
            if (visited[child] && parent[par] != child)
            {
                cycle = true;
            }

            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parent[child] = par;
            }
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

    // bfs for disconnected graph
    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }

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

/*
4 4
0 1
1 2
1 3
2 3
*/