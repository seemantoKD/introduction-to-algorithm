#include <bits/stdc++.h>
using namespace std;

int r, c;
char grid[1001][1001];
bool visited[1001][1001];
vector<pair<int, int>> movement = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool valid(int cr, int cc)
{
    if (cr < 0 || cr >= r || cc < 0 || cc >= c)
    {
        return false;
    }
    return true;
}

void dfs(int sr, int sc)
{
    visited[sr][sc] = true;

    for (int i = 0; i < 4; i++)
    {
        int cr = sr + movement[i].first;
        int cc = sc + movement[i].second;

        if (valid(cr, cc) && !visited[cr][cc] && (grid[cr][cc] == '.' || grid[cr][cc] == 'A' || grid[cr][cc] == 'B'))
        {
            dfs(cr, cc);
        }
    }
}

int main()
{
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }

    int sr = -1, sc = -1;
    int dr = -1, dc = -1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 'A')
            {
                sr = i;
                sc = j;
            }

            if (grid[i][j] == 'B')
            {
                dr = i;
                dc = j;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    dfs(sr, sc);

    if (visited[dr][dc] == true)
    {
        cout << "YES\n";
    }

    else
    {
        cout << "NO\n";
    }
    return 0;
}