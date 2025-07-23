#include<bits/stdc++.h>
using namespace std;

int cnt = 1;

void hanoi(char from, char to, char help, int n)
{
    if(n == 1)
    { /// exit condition
        /// base case
        /// move the only disk from 'from' to 'to'
        cout << cnt++ << ' ' << from << ' ' << to << '\n';
        return;
    }
    /// n != 1 Recursion case

    /// move n-1 disk from 'from' to 'help'
    hanoi(from, help, to, n - 1);

    /// move the n-th disk from 'from' to 'to'
    cout << cnt++ << ' ' << from << ' ' << to << '\n';

    /// move n-1 disk from 'help' to 'to'
    hanoi(help, to, from, n - 1);
}

int main()
{
    int n;
    cin >> n; /// input
	hanoi('A', 'B', 'C', n); /// move n disk from 'A' to 'B'
}
