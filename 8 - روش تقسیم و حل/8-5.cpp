#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &s, int l, int r)
{
    int i = l;
    int pivot = s[l];

    for (int j = l + 1; j <= r; j++)
        if (s[j] <= pivot)
            i++, swap(s[j], s[i]);

    swap(s[i], s[l]);
    return i;
}

void quickSort(vector<int> &s, int l, int r)
{
    if (r - l <= 0)
        return;

    int pivot = partition(s, l, r);
    cout << s[pivot] << ' ';

    quickSort(s, l, pivot - 1);
    quickSort(s, pivot + 1, r);
}

int main()
{
    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    quickSort(s, 0, n - 1);
    cout << endl;
    
    return 0;
}
