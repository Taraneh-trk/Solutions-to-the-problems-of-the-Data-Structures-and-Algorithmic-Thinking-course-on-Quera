#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 50000; /// MAX_SIZE should be greater than 2^n

string gray[MAX_SIZE]; /// result of gray_code will store in this array
string temp[MAX_SIZE]; /// this array helps to build gray code

void gray_code(int len)
{
    if (len == 1)
    {                  /// exit condition
        gray[0] = "0"; /// base case : '0', '1'
        gray[1] = "1";
        return;
    }
    /// len != 1, recursion case
    gray_code(len - 1); /// recursive

    int sizeOfGray = 1;
    for (int i = 0; i < len - 1; i++)
        sizeOfGray *= 2; /// sizeOfGray = 2^(len-1)

    int sz = 0;
    /// add zero to build first half of gray_code
    for (int i = 0; i < sizeOfGray; i++)
        temp[sz++] = "0" + gray[i];
        
    /// add one to build second half of gray_code
    for (int i = sizeOfGray - 1; i >= 0; i--) 
        temp[sz++] = "1" + gray[i];

    for (int i = 0; i < sz; i++)
        gray[i] = temp[i]; /// store gray_code
}

int main()
{
    int n;
    cin >> n; /// input
    gray_code(n);
    int p2 = 1;
    for (int i = 0; i < n; i++)
        p2 *= 2; /// p2 = 2^n
    for (int i = 0; i < p2; i++)
        cout << gray[i] << '\n'; /// print i-th gray_code
}
