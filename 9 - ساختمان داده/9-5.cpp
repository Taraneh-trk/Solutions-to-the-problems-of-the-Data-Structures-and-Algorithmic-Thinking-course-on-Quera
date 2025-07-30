#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

bool comparePairs(pair<int, int> a, pair<int, int> b)
{ // returns true if : a < b
    return (a.first < b.first) || (a.first == b.first && a.second < b.second);
}

struct Heap
{
    pair<int, int> heap[MAXN];
    int size;

    Heap()
    {
        size = 0;
    }

    Heap(pair<int, int> *begin, pair<int, int> *end)
    {
        size = end - begin;
        for (int i = 1; i <= size; i++)
            heap[i] = *(begin + i - 1);

        for (int i = size; i > 0; i--)
            pushDown(i);
    }

    void pushDown(int v)
    {
        int minVertex = -1;
        if (2 * v <= size)
            minVertex = 2 * v;
        if (2 * v + 1 <= size && comparePairs(heap[2 * v + 1], heap[2 * v]))
            minVertex = 2 * v + 1;
        if (minVertex == -1 || comparePairs(heap[v], heap[minVertex]))
            return;
        swap(heap[v], heap[minVertex]);
        pushDown(minVertex);
    }

    void pushUp(int v)
    {
        if (v == 1 || comparePairs(heap[v / 2], heap[v]))
            return;
        swap(heap[v], heap[v / 2]);
        pushUp(v / 2);
    }

    void insert(pair<int, int> val)
    {
        size++;
        heap[size] = val;
        pushUp(size);
    }

    void removeMin()
    {
        swap(heap[1], heap[size]);
        size--;
        pushDown(1);
    }

    bool isEmpty()
    {
        return size == 0;
    }

    pair<int, int> getMin()
    {
        return heap[1];
    }
} idHeap, dayHeap;

int q, numberOfStrings;
string myStrings[MAXN];
vector<pair<string, int>> customerList[MAXN];
bool mark[MAXN];

int getID(string arbitraryString)
{ // return the id of a string
    return lower_bound(myStrings, myStrings + numberOfStrings, arbitraryString) - myStrings;
}

int main()
{
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            string s;
            int t;
            cin >> s >> t;
            myStrings[numberOfStrings++] = s;
            customerList[i].push_back({s, t});
        }
    }

    sort(myStrings, myStrings + numberOfStrings);
    // getId can be used from now on!

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < customerList[i].size(); j++)
        {
            string name = customerList[i][j].first;
            int id = getID(name);
            int d = customerList[i][j].second;
            idHeap.insert({id, i + d});
            dayHeap.insert({i + d, id});
        }

        vector<int> output; // the id of people whom their subscription is done by the end of the day
        while (!dayHeap.isEmpty() && dayHeap.getMin().first - 1 == i)
        {
            int id = dayHeap.getMin().second;
            dayHeap.removeMin();
            if (!mark[id])
            { // check if it is not removed before
                mark[id] = true;
                output.push_back(id);
            }
        }

        // remove all previously removed ones
        while (!idHeap.isEmpty() && mark[idHeap.getMin().first])
            idHeap.removeMin();

        if (!idHeap.isEmpty())
        {
            int id = idHeap.getMin().first;
            mark[id] = true;
            output.push_back(id);
            idHeap.removeMin();
        }

        sort(output.begin(), output.end());     // sort the output
        for (int j = 0; j < output.size(); j++) // output the string whose id is output[i]
            cout << myStrings[output[j]] << ' ';
        cout << endl;
    }

    return 0;
}
