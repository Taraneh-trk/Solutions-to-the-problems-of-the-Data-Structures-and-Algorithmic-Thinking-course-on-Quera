#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    long long int ans = -1000000000;
    for (int l = 0; l < n; l++)
    {
        long long int sum = 0;
        for (int r = l; r < n; r++)
        {
            sum += a[r];
            if (ans < sum)
                ans = sum;
        }
    }
    
    cout << ans << endl;
    return 0;
}
