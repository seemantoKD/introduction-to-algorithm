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

int dfs(int sr, int sc)
{
    visited[sr][sc] = true;
    int count = 1;

    for (int i = 0; i < 4; i++)
    {
        int cr = sr + movement[i].first;
        int cc = sc + movement[i].second;

        if (valid(cr, cc) && !visited[cr][cc] && (grid[cr][cc] == '.'))
        {
            count += dfs(cr, cc);
        }
    }
    return count;
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

    memset(visited, false, sizeof(visited));

    vector<int> component;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                int size = dfs(i, j);
                component.push_back(size);
            }
        }
    }

    if (component.size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    sort(component.begin(), component.end());
    for (int val : component)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}