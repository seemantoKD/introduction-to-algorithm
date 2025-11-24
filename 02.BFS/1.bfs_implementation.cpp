#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000]; // node number question e deya thake tai dore nilam 1000 ta node ache
bool visited[1000];

void bfs_traversal(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) 
    {
        // ber kore ana
        int par = q.front();
        q.pop();

        // oi node ke niye kaj
        cout << par << " ";

        // children push
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

    // vector<int> adj_list[node]; //bfs e bar bar function e parameter hisebe na patiye ekbare globally niye nilam
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // only use for undirected graph
    }

    // visited arrayr sobkichu false korlam initially
    memset(visited, false, sizeof(visited));

    bfs_traversal(0); // dore nilam source node 0
    return 0;
}

/*
step :
    1. globally duita jinis declare korbo
        -> adj_list declare korbo (array of vector)
        -> visited array ta just declare korbo , initialize korbo na
    2. graph ta represent ba store korbo main function e adj_list er help niye
    3. memset diye visited array initialize korbo false diye
    4. bfs traversal function call korbo , parameter hisebe source node pass korbo
    5. bfs traversal function e giye kaj korbo

        (1)
        -> ekta que nibo
        -> queue manually source node push korbo
        -> visited[source] = true korbo

        (2)
        -> while loop calabo jar condition hobe !q.empty()
        -> // ber kore ana
            int par = q.front()
            q.pop()

        -> // oi node niye kaj
            cout<<par<<" ";

        -> // children push
            for(int child : adj_list)
            {
                if(!visited[child])
                {
                    q.push(child);
                    visited[child] = true;
                }
            }
*/