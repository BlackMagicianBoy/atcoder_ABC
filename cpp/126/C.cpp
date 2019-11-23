#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define int long long

signed main()
{
    int N, K;
    cin >> N >> K;
    int denominator = N * (1 << 25);
    int numerator = 0;
    for (int i = 1; i <= N; i++)
    {
        int n_coin = 0;
        while (i * (1 << n_coin) >= 1 && i * (1 << n_coin) < K)
        {
            n_coin++;
        }
        numerator += (1 << (25 - n_coin));
    }

    printf("%.10f\n", (double)numerator / denominator);
}