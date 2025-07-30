#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    bool isBalancedSequence = true;
    int openParantheseCounter = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
            openParantheseCounter--;
        else
            openParantheseCounter++;
        if (openParantheseCounter < 0)
            isBalancedSequence = false;
    }
    if (openParantheseCounter != 0)
        isBalancedSequence = false;

    if (isBalancedSequence)
    {
        stack<int> myStack;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (myStack.empty())
                    isBalancedSequence = false;
                else
                {
                    cout << myStack.top() + 1 << ' ' << i + 1 << '\n';
                    myStack.pop();
                }
            }
            else
                myStack.push(i);
        }
    }
    else
        cout << "-1\n";

    return 0;
}
