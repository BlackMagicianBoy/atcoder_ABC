#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <queue>

#define INF (int)(1e9 + 7)
#define int long long

using namespace std;

signed main()
{
    int Q;
    scanf("%lld", &Q);
    int sumx = 0;
    //always left.size() = right.size() or left.size() = right.size()+1
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    left.push(-INF);
    right.push(INF);
    int sumb = 0;

    for (int i = 0; i < Q; i++)
    {
        int q;
        scanf("%lld", &q);
        if (q == 1)
        {
            int b, x;
            scanf("%lld%lld", &x, &b);

            if (i == 0)
            {
                left.push(x);
            }
            else
            {
                int pminx = left.top();
                sumx += abs(pminx - x);

                //push
                if (x <= right.top())
                {
                    left.push(x);
                }
                else
                {
                    right.push(x);
                }

                //adjust size
                if (right.size() > left.size())
                {
                    left.push(right.top());
                    right.pop();
                }
                if (left.size() > right.size() + 1)
                {
                    right.push(left.top());
                    left.pop();
                }

                //
                int nminx = left.top();
                int dx = nminx - pminx;
                int n = right.size() + left.size() - 2;
                int index = (n - 1) / 2;
                if (dx >= 0)
                {
                    sumx += (index * 2 - n) * dx;
                }
                else
                {
                    sumx += ((index + 1) * 2 - n) * dx;
                }
            }

            sumb += b;
        }
        else
        {
            printf("%lld %lld\n", left.top(), sumx + sumb);
        }
    }

    return 0;
}