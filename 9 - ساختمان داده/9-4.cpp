#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<char> myList;

    // current position iterator
    list<char>::iterator currentPosition = myList.begin();

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string operation;
        cin >> operation;
        if (operation == "+")
        { // move iterator one step further if possible
            if (currentPosition != myList.end())
                currentPosition++;
        }
        else if (operation == "-")
        { // move iterator one step back if possible
            if (currentPosition != myList.begin())
                currentPosition--;
        }
        else
        {
            char c;
            cin >> c;
            myList.insert(currentPosition, c);
            // after inserting the iterator moves to next position
        }
    }

    for (list<char>::iterator it = myList.begin(); it != myList.end(); it++)
        cout << *it;
    cout << endl;
    
    return 0;
}
