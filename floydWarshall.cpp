#include <bits/stdc++.h>
using namespace std;

#define N 4
#define INF 999

void minDist(int graph[N][N]);

int main()
{
    int graph[N][N] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}};

    minDist(graph);
}

void minDist(int graph[N][N])
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}