#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N_max = 1e5;
vector<vector<pair<int, int>>> graph(N_max);
vector<bool> black(N_max, false);
vector<bool> checked(N_max, false);

void explore(int now, bool now_black)
{
    for (int i = 0; i < graph[now].size(); i++)
    {
        int v = graph[now][i].first;
        int l = graph[now][i].second;
        if (!checked[v])
        {
            if (l % 2 == 0)
            {
                black[v] = now_black;
            }
            else
            {
                black[v] = !now_black;
            }
            checked[v] = true;
            explore(v, black[v]);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    black[0] = true;
    checked[0] = true;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back(pair<int, int>(v, w));
        graph[v].push_back(pair<int, int>(u, w));
    }

    explore(0, true);

    for (int i = 0; i < N; i++)
    {
        if (black[i])
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}