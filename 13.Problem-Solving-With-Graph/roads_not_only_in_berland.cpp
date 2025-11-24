#include <bits/stdc++.h>
using namespace std;

int parent[1005];
int grp_sz[1005];

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

    // cycle
    if (l1 == l2)
        return;

    if (grp_sz[l1] >= grp_sz[l2])
    {
        parent[l2] = l1;
        grp_sz[l1] += grp_sz[l2];
    }

    else
    {
        parent[l1] = l2;
        grp_sz[l2] += grp_sz[l1];
    }
}

int main()
{
    int node, edge;
    cin >> node;
    edge = node - 1;

    vector<pair<int, int>> rastaBad;
    vector<pair<int, int>> create;
    
    for (int i = 1; i <= node; i++)
    {
        parent[i] = -1;
        grp_sz[i] = 1;
    }

    while (edge--)
    {
        int a, b;
        cin >> a >> b;

        int la = find(a);
        int lb = find(b);

        // cycle -> not needed this path
        if (la == lb)
            rastaBad.push_back({a, b});
        else
            dsu_union(a, b);
    }

    for (int i = 2; i <= node; i++)
    {
        int l1 = find(1);
        int li = find(i);
        if (l1 != li)
        {
            create.push_back({1, i});
            dsu_union(1, i);
        }
    }

    cout << rastaBad.size() << endl;
    for(int i = 0;i<rastaBad.size();i++)
        cout<<rastaBad[i].first<<" "<<rastaBad[i].second<<" "<<create[i].first<<" "<<create[i].second<<endl;
    return 0;
}
