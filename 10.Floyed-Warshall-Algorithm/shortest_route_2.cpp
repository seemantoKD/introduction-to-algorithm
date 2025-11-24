#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge, q;
    cin >> node >> edge >> q;

    long long int adj_mat[node + 5][node + 5];

    // sobaike INT_MAX and 0 diye initialize
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = LLONG_MAX;
        }
    }

    while (edge--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], c);
        adj_mat[b][a] = min(adj_mat[b][a], c); // undirected
    }

    // floyed_warshall
    for (int k = 1; k <= node; k++)
    {
        for (int i = 1; i <= node; i++)
        {
            for (int j = 1; j <= node; j++)
            {
                if ((adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX) && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }
    }

    while (q--)
    {
        int src, dst;
        cin >> src >> dst;
        if (adj_mat[src][dst] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_mat[src][dst] << endl;
    }
    return 0;
}