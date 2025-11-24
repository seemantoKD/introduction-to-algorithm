#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int dis[100];

int main()
{
    int node, edge;
    cin >> node >> edge;

    vector<Edge> edge_list;
    while (edge--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 0; i < node; i++)
        dis[i] = INT_MAX;

    dis[0] = 0; // src -> 0

    for (int i = 0; i < node - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            // path relaxation
            if ((dis[a] + c < dis[b]) && dis[a] != INT_MAX)
                dis[b] = dis[a] + c;
        }
    }

    // extra ekbar
    bool cycle = false;
    for (auto ed : edge_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;

        // path relaxation
        if ((dis[a] + c < dis[b]) && dis[a] != INT_MAX)
        {
            // dis[b] = dis[a] + c;
            cycle = true;
            break;
        }
    }

    if (cycle)
        cout << "Negative weighted Cycle detected\n";
    else
    {
        for (int i = 0; i < node; i++)
            cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}

/*
for detect cycle :
4  4
0 1 5
1 2 3
2 3 2
3 1 -6
*/