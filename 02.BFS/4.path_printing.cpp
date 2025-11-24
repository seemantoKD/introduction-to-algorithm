#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool visited[1000];
int level[1000];
int parent[1000];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    // parent[src] = -1;

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
                level[child] = level[par] + 1;
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
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    int source, dst;
    cin >> source >> dst;

    bfs(source);

    // path printing
    int node1 = dst; // jekhan theke jatra shuru
    vector<int> path;
    while (node1 != -1)
    {
        path.push_back(node1);
        node1 = parent[node1];
    }

    reverse(path.begin(), path.end());
    // path printing
    for (int val : path)
    {
        cout << val << " ";
    }
    cout << endl;

    // //parent print
    // for (int i = 0; i < node; i++)
    // {
    //     cout << i << " parent -> " << parent[i] << endl;
    // }

    // //shortest distance finding
    // cout << "Shortest distance : " << level[dst] << endl;
    return 0;
}


/*
    step : 
        1. globally -
            -> array of vector declare
            -> visited array declare
            -> level array declare
            -> parent array declare
        2. graph input using adjacency_list
        3. memset use kore
            -> visited array false kora
            -> level array -1 kora
            -> parent array -1 kora
        4. source destination input
        5. source ke diye bfs call
        6. bfs function a giye 
            -> queue nibo
            -> source push korbo
            -> while loop calabo
                # code : while (!q.empty())
                            {
                                int par = q.front();
                                q.pop();

                                for (int child : adj_list[par])
                                {
                                    if (!visited[child])
                                    {
                                        q.push(child);
                                        visited[child] = true;
                                        level[child] = level[par] + 1;
                                        parent[child] = par;
                                    }
                                }
                            }
        7. main function e ese destination ke node1 a store korbo
        8. path nam er vector nibo 
            -> destination jotokkon na -1 hoy totokkon
                . path e node1 push korbo
                . node1 = parent[node1] eta likhe node1 ke update korbo
        9. path vector ke reverse kore print korbo
*/