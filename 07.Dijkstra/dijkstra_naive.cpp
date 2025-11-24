#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[1000];
int dis[1000];

void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;

    while (!q.empty())
    {
        // ber kore ana
        pair<int, int> par = q.front();
        q.pop();

        int par_node = par.first;
        int par_dis = par.second;

        // oi node ke niye kaj

        // children push
        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                q.push({child_node, dis[child_node]});
            }
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    while (edge--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c}); // for undirected graph
    }

    // memset(dis,INT_MAX,sizeof(dis)); // memset boro value niye kaj korte pare na
    for (int i = 0; i < node; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(0);

    // print all node shortest distance from source
    for (int i = 0; i < node; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
    return 0;
}

/*
    step :
        1. dijkstra graph input
        2. dis array initialize korbo sobaike INT_MAX diye
        3. dijkstra function call korbo
            -> function er vitor
                1. ber kore anbo
                2. children push korbo
                    code : for (auto child : adj_list[par_node])
                                {
                                    int child_node = child.first;
                                    int child_dis = child.second;

                                    if (par_dis + child_dis < dis[child_node])
                                    {
                                        dis[child_node] = par_dis + child_dis;
                                        q.push({child_node, dis[child_node]});
                                    }
                                }
        4. dijkstra distance array print kore dibo main function a
*/