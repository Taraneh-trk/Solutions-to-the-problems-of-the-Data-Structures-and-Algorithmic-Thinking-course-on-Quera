#include<iostream>
using namespace std;

const int MAXN = 100 * 1000 + 5;

int main()
{
	int n, x, t = 0;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		if(x != i + 1)
			t++;
	}	
	
	if(t == 2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
		
	return 0;
}
