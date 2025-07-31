#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q, k;
    cin >> q >> k;

    set<int> landingPlaces;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        set<int>::iterator it = landingPlaces.lower_bound(x);
        bool permission = true;
        if (it != landingPlaces.end() && *it - x < k) // if next element is available and close to x
            permission = false;
        if (it != landingPlaces.begin() && x - *(--it) < k) // if previous element is available and is close to x
            permission = false;

        if (permission)
        {
            cout << "Permission Granted!\n";
            landingPlaces.insert(x);
        }
        else
            cout << "Permission Denied!\n";
    }

    return 0;
}
