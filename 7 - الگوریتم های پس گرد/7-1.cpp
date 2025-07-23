#include <bits/stdc++.h>
using namespace std;

int per[10];

int ans = 0;
/// 'last' is the last index in currentPermutation that isn't set yet
void build(int n, int k, int last, int currentPermutation[])
{ //
    if (last == n)
    { /// exit condition
        int inv = 0;
        for (int i = 0; i < n; i++) /// count number of inversions
            for (int j = i + 1; j < n; j++)
                if (currentPermutation[i] > currentPermutation[j])
                    inv++;
        if (inv == k)
            ans++;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            bool isIn = false;             /// isIn = true if i is in currentPermutation
            for (int j = 0; j < last; j++) /// looking for 'i' in currentPermutation
                if (currentPermutation[j] == i)
                    isIn = true;
            if (!isIn)
            {                                              /// if i is not in currentPermutation
                currentPermutation[last] = i;              /// last-th element in permutation is i
                build(n, k, last + 1, currentPermutation); /// recursive
                currentPermutation[last] = 0;              /// this line is not necessary! (why?)
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    build(n, k, 0, per);
    cout << ans << endl;

    return 0;
}
