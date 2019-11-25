#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define int long long

using namespace std;

signed main()
{
    int N, M;
    //pair(number, the number of the number)
    vector<pair<int, int>> np;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        np.push_back(pair<int, int>(a, 1));
    }
    for (int i = 0; i < M; i++)
    {
        int b, c;
        cin >> b >> c;
        np.push_back(pair<int, int>(c, b));
    }

    sort(np.begin(), np.end(), greater<pair<int, int>>());

    int ans = 0;
    int nans = 0;
    for (int i = 0; i < np.size(); i++)
    {
        int n = np[i].first;
        int nn = np[i].second;
        if (nans + nn < N)
        {
            ans += nn * n;
            nans += nn;
        }
        else
        {
            ans += (N - nans) * n;
            break;
        }
    }

    cout << ans << endl;
}