#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    S[K - 1] = 'a' + S[K-1] - 'A';
    cout << S << endl;
}