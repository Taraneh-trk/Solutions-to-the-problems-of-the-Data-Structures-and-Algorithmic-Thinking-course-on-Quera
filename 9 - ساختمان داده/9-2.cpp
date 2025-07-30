#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;

    stack<string> history;
    history.push(""); // the empty string is added first
    for (int i = 0; i < q; i++)
    {
        string operation;
        cin >> operation;

        string lastString = history.top();
        if (operation == "insert")
        {
            int index;
            char c;
            cin >> index >> c;
            index--;
            // add character 'c' to index and shift the rest
            for (int i = index; i < (int)lastString.size(); i++)
                swap(lastString[i], c);
            lastString += c;
            history.push(lastString);
        }
        else if (operation == "delete")
        {
            string s = "";
            int index;
            cin >> index;
            index--;

            // add all elements to 's' except lastString[index]
            for (int i = 0; i < (int)lastString.size(); i++)
                if (i != index)
                    s += lastString[i];
            history.push(s);
        }
        else
            history.pop();
    }
    
    cout << history.top() << endl;
    return 0;
}
