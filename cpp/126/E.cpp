#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> relation((int)1e5);
vector<bool> ok((int)1e5, false);
int ans = 0;

void change(int changed)
{
    ok[changed] = true;
    for (int i = 0; i < relation[changed].size(); i++)
    {
        if (!ok[relation[changed][i]])
            change(relation[changed][i]);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        relation[a].push_back(b);
        relation[b].push_back(a);
    }

    for (int i = 0; i < N; i++)
    {
        if (!ok[i])
        {
            ans++;
            change(i);
        }
    }

    cout << ans << endl;
}