#include <bits/stdc++.h>
using namespace std;

int parent[105]; // leader
int group_size[105];

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
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (group_size[leader1] > group_size[leader2])
    {
        parent[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }

    else
    {
        parent[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    memset(parent, -1, sizeof(parent));
    memset(group_size, 1, sizeof(group_size));

    int node, edge;
    cin >> node >> edge;

    bool cycle = false;
    while (edge--)
    {
        int a, b;
        cin >> a >> b;

        // leader -> parent
        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA == leaderB)
            cycle = true;
        else
            dsu_union(a, b);
    }

    if (cycle)
        cout << "Cycle detected\n";
    else
        cout << "NO Cycle\n";
    return 0;
}