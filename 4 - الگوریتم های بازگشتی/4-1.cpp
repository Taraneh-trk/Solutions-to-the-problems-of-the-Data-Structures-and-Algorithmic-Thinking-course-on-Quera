#include<bits/stdc++.h>
using namespace std;

int f(int x)
{
	if(x == 0)
	    return 5;
	int tmp = f(x - 1); // calculating f_{x-1}
	if(x % 2 == 0)
	    return tmp  - 21;
	else
	    return tmp * tmp;
}

int main()
{
    int n;
    cin >> n; // input
	cout << f(n) << endl; // calling f to calculate f_n
}
