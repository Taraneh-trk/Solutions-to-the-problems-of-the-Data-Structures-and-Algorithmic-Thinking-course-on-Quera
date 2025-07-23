#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    pair<int, int> reverse_segment[n];
    for(int i = 0; i < n; i++)
        cin >> reverse_segment[i].second >> reverse_segment[i].first;
        
    sort(reverse_segment, reverse_segment + n);
    int answer = 0, end_of_last_choosen_segment = 0;
    for(int i = 0; i < n; i++)
        if(reverse_segment[i].second >= end_of_last_choosen_segment)
            answer++, end_of_last_choosen_segment = reverse_segment[i].first;
            
    cout << answer << '\n';
    return 0;
}