#include <iostream>

using namespace std;

int main() 
{
    int n;	
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	long long int ans = -10000000000000;
	
	for (int r = 1; r <= n; r++)
		for (int l = 0; l < r; l++) 
		{
			long long int sum = 0;
			
			for (int i = l; i < r; i++)
				sum += a[i];
			
			if (sum > ans) 
				ans = sum;
		}
	
	cout << ans << endl;
    return 0;
}
