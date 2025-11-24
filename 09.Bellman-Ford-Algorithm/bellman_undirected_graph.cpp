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
        edge_list.push_back(Edge(b, a, c)); // undirected
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

    for (int i = 0; i < node; i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}

/*
    step :
        1. globally Edge class create kore
            -> a , b, c constructor diye initialize korbo
        2. globally distance array nibo
        3. main function a ese edge list diye graph input nibo
            -> note : graph input er smy Edge class theke vector a value push ta ektu bujbo
        4. distance array ke INT_MAX diye initialize korbo
        5. dis[src] = 0 korbo
        6. node - 1 porjonto loop caliye bellman_ford er process continue korbo
            code : for (int i = 0; i < node - 1; i++)
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
        7. distance array ta print kore dibo

*/