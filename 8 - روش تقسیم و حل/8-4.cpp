#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int a[MAXN], b[MAXN];

ll inversion(int *a, int l, int r)
{
    if (r - l <= 1)
        return 0LL; // number of inversion in array with length 1

    int mid = (l + r) / 2;

    ll result = 0;

    result += inversion(a, l, mid); // number of inversion in [l, mid)
    result += inversion(a, mid, r); // number of inversion in [mid, r)

    // this part will compute number of inversion between let part and right part
    int k = 0;
    for (int i = l; i < mid; i++)
    {
        while (k < r - mid && a[i] > a[mid + k])
            k++;
        // k is number of elements less than a[i] in right part
        result += k; // add k to number of inversions
    }

    // merge two parts and sort array like we did in merge sort
    int p1 = l, p2 = mid, cnt = 0;
    while (p1 < mid || p2 < r)
    {
        if (p1 == mid)
            b[cnt++] = a[p2++];
        else if (p2 == r)
            b[cnt++] = a[p1++];
        else if (a[p1] < a[p2])
            b[cnt++] = a[p1++];
        else
            b[cnt++] = a[p2++];
    }

    for (int i = l; i < r; i++)
        a[i] = b[i - l];

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << inversion(a, 0, n) << endl;
    return 0;
}
