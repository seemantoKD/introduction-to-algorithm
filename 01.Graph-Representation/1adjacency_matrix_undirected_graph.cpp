#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;

    int adj_mat[node][node];

    // manual process for initialize all val = 0
    //  for(int i = 0;i<node;i++)
    //  {
    //      for(int j = 0;j<node;j++)
    //      {
    //          adj_mat[i][j] = 0;
    //      }
    //  }

    // shortcut process for initialize all val with 0
    // syntax : memset(kar_memory_set_korbo,koto_diye_initialize_korbo,koto_tuk_porjonto_korbo)
    memset(adj_mat, 0, sizeof(adj_mat));

    // diagonal val 1 set korlam
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 1;
            }
        }
    }

    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1; // for undirected graph
    }

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
    step :
    1. node , edge input neya
    2. 2D array declare
    3. array-র sokol element memset diye 0 set korbo
    4. diagonal borabor value 1 set korbo
    5. while(edge--)
    {
        int a,b;
        cin>>a>>b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;
    }
    6. 2D array print
*/