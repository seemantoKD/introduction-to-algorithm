#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;

    int adj_mat[node][node];

    // sobaike INT_MAX diye initialize
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INT_MAX;
        }
    }

    while (edge--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c;
        // adj_mat[b][a] = c; // undirected
    }

    // floyed_warshall
    for (int k = 0; k < node; k++)
    {
        for (int i = 0; i < node; i++)
        {
            for (int j = 0; j < node; j++)
            {
                if ((adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX) && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }
    }

    // print adj_mat
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            if (adj_mat[i][j] != INT_MAX)
                cout << adj_mat[i][j] << " ";
            else
                cout << "INF ";
        }
        cout << endl;
    }
    return 0;
}

/*
    step :
        1. node and edge input
        2. adj_mat declare size hobe number of node
        3. adj_mat element gulake 0 and INT_MAX diye initialize korbo
        4. adj_mat er element gula input
        5. floyed warshall apply
            code :
                // floyed_warshall
                for (int k = 0; k < node; k++)
                {
                    for (int i = 0; i < node; i++)
                    {
                        for (int j = 0; j < node; j++)
                        {
                            if ((adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX) && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                                adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                        }
                    }
                }
        6. adj_mat print kore dibo
*/