// program for negative weighted cycle
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

    // detect cycle
    bool cycle = false;
    for (int i = 0; i < node; i++)
    {
        if (adj_mat[i][i] < 0)
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
        cout << "Negative weighted Cycle detected" << endl;
    else
    {
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
    }
    return 0;
}