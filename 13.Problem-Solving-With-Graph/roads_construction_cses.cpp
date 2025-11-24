/*
// Time limit excedeed -> bfs/dfs appraoch
#include <bits/stdc++.h>
using namespace std;

int sz = 0;
vector<int> adj_list[100005];
bool visited[100005];

void dfs(int src)
{
    visited[src] = true;
    sz++;

    for (auto child : adj_list[src])
        if (!visited[child])
            dfs(child);
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
        adj_list[b].push_back(a); // undirected

        memset(visited, false, sizeof(visited));

        int mx = 0;
        int count = 0;

        for (int i = 1; i <= node; i++)
        {
            if (!visited[i])
            {
                sz = 0;
                dfs(i);
                count++;
                mx = max(sz, mx);
            }
        }
        cout << count << " " << mx << endl;
    }

    // cout << count << endl; // component koyta
    // cout << mx << endl; // largest component er size koto

    return 0;
}
*/

// dsu approach
#include <bits/stdc++.h>
using namespace std;

int parent[100005];
int grp_sz[100005];
int cmp;
int mx;

int find(int node)
{
    if (parent[node] == -1)
        return node;

    int leader = find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int l1 = find(node1);
    int l2 = find(node2);

    // cycle thakle -> component same so kombe na return hoye jabe
    if (l1 == l2)
        return;

    if (grp_sz[l1] >= grp_sz[l2])
    {
        parent[l2] = l1;
        grp_sz[l1] += grp_sz[l2];
        mx = max(mx, grp_sz[l1]);
    }

    else
    {
        parent[l1] = l2;
        grp_sz[l2] += grp_sz[l1];
        mx = max(mx, grp_sz[l2]);
    }
    cmp--;
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    cmp = node;
    mx = 1;
    for (int i = 1; i <= node; i++)
    {
        parent[i] = -1;
        grp_sz[i] = 1;
    }

    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
        cout << cmp << " " << mx << endl;
    }
    return 0;
}
