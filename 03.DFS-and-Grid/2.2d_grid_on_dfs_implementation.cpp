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

void dfs(int srcr, int srcc) // source er row, source er column
{
    // print
    cout << srcr << " " << srcc << endl;
    visited[srcr][srcc] = true;

    // child niye kechal
    for (int i = 0; i < 4; i++) // loop 4 bar colce karon child 4 tai thake grid a
    {
        int cr = srcr + movement[i].first;  // child row
        int cc = srcc + movement[i].second; // child col

        if (valid(cr, cc) && !visited[cr][cc])
        {
            dfs(cr, cc);
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

    // call dfs
    dfs(si, sj);
    return 0;
}

/*
    step :
        1. globally row col declare
        2. globally char type er 2d grid declare
        3. globally visited array declare
        4. globally vector pair er movement declare and changes value diye initialize
        5. main function er vitor row col input
        6. 2d grid element input
        7. source er row col input
        8. memset diye visited array false kora
        9. dfs call source ke diye
        10. dfs function e giye
            -> source er row col print evong sathe sathe visited true kora
            -> // child niye kechal
                for (int i = 0; i < 4; i++) // loop 4 bar colce karon child 4 tai thake grid a
                {
                    int cr = srcr + movement[i].first;  // child row
                    int cc = srcc + movement[i].second; // child col

                    if (valid(cr, cc) && !visited[cr][cc])
                    {
                        dfs(cr, cc);
                    }
                }
        11. valid function er kaj kora
*/