#include <bits/stdc++.h>
using namespace std;

int parent[105]; // leader

int find(int node)
{
    cout << node << endl;
    if (parent[node] == -1)
        return node;

    int leader = find(parent[node]);
    return leader;
}

int main()
{
    memset(parent, -1, sizeof(parent));

    // manually dilam initial parent / leader
    parent[0] = 1;
    // parent[1] = -1; memset a kora already
    parent[2] = 1;
    parent[3] = 1;
    parent[4] = 5;
    parent[5] = 3;

    cout << find(4); // 4 er parent ke bole dibe
    return 0;
}