#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long answer = 0;
    for (int a = 1; a <= n / 3; a++)
    {
        int l = n / 2 - 2 * a + 1;
        if (l < 0)
            l = 0;
        int r = (n - 3 * a) / 2;
        answer = answer + r - l + 1;
    }
    
    cout << answer << '\n';
    return 0;
}
