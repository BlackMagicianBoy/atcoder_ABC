#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> lr;

    int l = 1;
    int r = N;

    for (int i = 0; i < M; i++)
    {
        int tl, tr;
        cin >> tl >> tr;
        l = (tl > l) ? tl : l;
        r = (tr < r) ? tr : r;
    }

    cout << ((r - l + 1) > 0 ? r - l + 1 : 0) << endl;
}