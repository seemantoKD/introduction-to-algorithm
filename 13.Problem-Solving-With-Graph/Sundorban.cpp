#include <bits/stdc++.h>
using namespace std;

int row, col;
bool visited[35][35];
int level[35][35];
char grid[35][35];
vector<pair<int, int> > movement; //= {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int cr, int cc)
{
    if (cr >= row || cr < 0 || cc >= col || cc < 0)
        return false;
    return true;
}

void bfs(int sr, int sc)
{
    queue<pair<int, int> > q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    level[sr][sc] = 0;

    while (!q.empty())
    {
        // ber kore ana
        pair<int, int> par = q.front();
        q.pop();

        // oi node ke niye kaj

        // children push
        for (int i = 0; i < 4; i++)
        {
            int cr = par.first + movement[i].first;
            int cc = par.second + movement[i].second;

            if (valid(cr, cc) && !visited[cr][cc] && grid[cr][cc] != 'T')
            {
                q.push({cr, cc});
                visited[cr][cc] = true;
                level[cr][cc] = level[par.first][par.second] + 1;
            }
        }
    }
}

int main()
{
    movement.push_back({-1, 0});
    movement.push_back({1, 0});
    movement.push_back({0, -1});
    movement.push_back({0, 1});
    int sr = -1, sc = -1, dr = -1, dc = -1;
    // input grid

    while (cin >> row)
    {
        col = row;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'S') // source index
                {
                    sr = i;
                    sc = j;
                }

                if (grid[i][j] == 'E') // destination index
                {
                    dr = i;
                    dc = j;
                }
            }
        }

        memset(visited, false, sizeof(visited));
        memset(level, -1, sizeof(level));
        bfs(sr, sc);

        // shortest distance print
        cout << level[dr][dc] << endl;
    }
    return 0;
}