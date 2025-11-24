#include <bits/stdc++.h>
using namespace std;

int val[1005];
int weight[1005];

int knapsack(int i, int max_weight)
{
    // base case
    if (i < 0 || max_weight <= 0)
        return 0;

    // case 1
    // 2 ta option
    // 1. bag a rakhbo -> op1, 2. bag a rakhbo na -> op2

    // bag a rakha jabe -> ami check korbo rakha gele o rakhle max na ki na rakhle max hobe
    if (weight[i] <= max_weight)
    {
        int op1 = knapsack(i - 1, max_weight - weight[i]) + val[i]; // bag a rakhsi
        int op2 = knapsack(i - 1, max_weight);                      // bag a rakhsi na
        return max(op1, op2);
    }

    // bag a rakhar jayga e nai tai option matro 1 ta
    else
        // case 2
        // option 1 ta
        // bag a rakha jabe na
        return knapsack(i - 1, max_weight);
}

int main()
{
    int n; // number of item
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    int max_weight; // maximum capacity of a bag
    cin >> max_weight;

    cout << knapsack(n - 1, max_weight) << endl; // last theke shuru
    return 0;
}

/*
    step :
        1. globally val and weight array nibo
        2. main function a ese proyojonio input nibo
        3. knapsack function call
        4. function a jabo
        5. function er jabotio kaj korbo
            // base case

            // option 2 tar jonno if a kaj korbo

            // option 1 tar jonno else a kaj korbo

        6. function theke return korbo max(op1,op2) , (if block theke + else block theke)
        7. main function a ese print
*/