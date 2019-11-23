#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    cin >> S;
    bool first, second;
    if ((S[0] == '0' && S[1] != '0') || (S[0] == '1' && (S[1] == '0' || S[1] == '1' || S[1] == '2')))
        first = true;
    else
        first = false;

    if ((S[2] == '0' && S[3] != '0') || (S[2] == '1' && (S[3] == '0' || S[3] == '1' || S[3] == '2')))
        second = true;
    else
        second = false;

    if (first && second)
    {
        cout << "AMBIGUOUS" << endl;
    }
    else if (first)
    {
        cout << "MMYY" << endl;
    }
    else if (second)
    {
        cout << "YYMM" << endl;
    }
    else
    {
        cout << "NA" << endl;
    }

    return 0;
}