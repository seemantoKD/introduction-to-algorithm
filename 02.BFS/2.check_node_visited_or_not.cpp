#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[10000];
bool visited[1000];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
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
    int src, dst;
    cin >> src >> dst;

    bfs(src);

    if (visited[dst])
    {
        cout << "YES\n";
    }

    else
    {
        cout << "NO\n";
    }
    return 0;
}

/*
problem : node 0 theke node 4 e jawa jay ki na
*/