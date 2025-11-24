#include <bits/stdc++.h>
using namespace std;

int parent[105]; // leader

int find(int node)
{
    while (parent[node] != -1)
    {
        cout<<node<<endl;
        node = parent[node];
    }
    return node;
}

int main()
{
    memset(parent, -1, sizeof(parent));

    // manually dilam initial parent / leader
    parent[0] = 1;
    //parent[1] = -1; memset a kora already
    parent[2] = 1;
    parent[3] = 1;
    parent[4] = 5;
    parent[5] = 3;

    cout << find(4); // 4 er parent ke bole dibe
    return 0;
}