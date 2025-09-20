// quera solution
#include <iostream>
#include <string>
using namespace std;


int solve(string s) {
    // Base case for a single character string
    if (s.size() == 1)
        return (s[0] == '?' ? 2 : 1);
    
    // Create four base patterns
    string t[4];
    t[0] = "aa";
    t[1] = "ab";
    t[2] = "ba";
    t[3] = "bb";

    // Extend the patterns to the length of the string s
    for (int j = 0; j < 4; j++)
        for (int i = 2; i < s.size(); i++)
            t[j] += (t[j][i - 2] == 'a' ? 'b' : 'a');

    int ans = 0;

    // Check each pattern against the string s
    for (int j = 0; j < 4; j++) {
        bool comp = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '?' && s[i] != t[j][i])
                comp = false;
        }
        if (comp) ans++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    cout << solve(s) << endl; 
    return 0;
}
// my solution
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	string s;
	getline(cin,s);
	
	bool flag = true,ffo=false,ffe=false;
	ll ans=0;
	ll fch_even=-1,fch_odd=-1;
	for(int i=0;i<s.length();i++){
		if(s[i]!='?'){
			if(i%2==0){
				fch_even=i;
				ffe=true;
			}else if(i%2==1){
				fch_odd=i;
				ffo=true;
			}
		}
		if(ffe && ffo){
			break;
		}
	}
	
	if(ffe==false && ffo==false){
		cout<<4<<'\n';
	}else if(ffe==true && ffo==false){
		for(int i=fch_even-2;i>=0;i-=2){
			if(s[i]==s[i+2]){
				cout<<0<<'\n';
				return 0;
			}else if(s[i]=='?'){
				s[i] = (s[i+2]=='a' ? 'b' : 'a');
			}
		}
		for(int i=fch_even+2;i<s.length();i+=2){
			if(s[i]==s[i-2]){
				cout<<0<<'\n';
				return 0;
			}else if(s[i]=='?'){
				s[i] = (s[i-2]=='a' ? 'b' : 'a');
			}
		}
		cout<<2<<'\n';
	}else if(ffe==false && ffo==true){
		for(int i=fch_odd-2;i>=0;i-=2){
			if(s[i]==s[i+2]){
				cout<<0<<'\n';
				return 0;
			}else if(s[i]=='?'){
				s[i] = (s[i+2]=='a' ? 'b' : 'a');
			}
		}
		for(int i=fch_odd+2;i<s.length();i+=2){
			if(s[i]==s[i-2]){
				cout<<0<<'\n';
				return 0;
			}else if(s[i]=='?'){
				s[i] = (s[i-2]=='a' ? 'b' : 'a');
			}
		}
		cout<<2<<'\n';
	}else if(ffe==true && ffo==true){
		for(int i=fch_even-2;i>=0;i-=2){
			if(s[i]==s[i+2]){
				cout<<0<<'\n';
				return 0;
			}else if(s[i]=='?'){
				s[i] = (s[i+2]=='a' ? 'b' : 'a');
			}
		}
		for(int i=fch_even+2;i<s.length();i+=2){
			if(s[i]==s[i-2]){
				cout<<0<<'\n';
				return 0;
			}else if(s[i]=='?'){
				s[i] = (s[i-2]=='a' ? 'b' : 'a');
			}
		}
		for(int i=fch_odd-2;i>=0;i-=2){
			if(s[i]==s[i+2]){
				cout<<0<<'\n';
				return 0;
			}else if(s[i]=='?'){
				s[i] = (s[i+2]=='a' ? 'b' : 'a');
			}
		}
		for(int i=fch_odd+2;i<s.length();i+=2){
			if(s[i]==s[i-2]){
				cout<<0<<'\n';
				return 0;
			}else if(s[i]=='?'){
				s[i] = (s[i-2]=='a' ? 'b' : 'a');
			}
		}
		cout<<1<<'\n';
	}
	
	
	return 0;
}
