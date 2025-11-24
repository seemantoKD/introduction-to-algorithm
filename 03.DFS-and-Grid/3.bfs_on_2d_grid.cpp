#include <bits/stdc++.h>
using namespace std;

int row, col;
char grid[100][100]; // row,col
bool visited[100][100];
vector<pair<int, int>> movement = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int childrow, int childcol)
{
    if (childrow < 0 || childrow >= row || childcol < 0 || childcol >= col)
    {
        return false;
    }

    else
    {
        return true;
    }
}

void bfs(int sr, int sc)
{
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        cout << par.first << " " << par.second << endl; // first -> row, second->col

        for (int i = 0; i < 4; i++)
        {
            int cr = par.first + movement[i].first;
            int cc = par.second + movement[i].second;

            if (!visited[cr][cc] && valid(cr, cc))
            {
                q.push({cr, cc});
                visited[cr][cc] = true;
            }
        }
    }
}

int main()
{
    cin >> row >> col;

    // grid element input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
        }
    }

    // input source node
    int si; // source er row er index
    int sj; // source er col er index
    cin >> si >> sj;

    memset(visited, false, sizeof(visited));

    // call bfs
    bfs(si, sj);
    return 0;
}
