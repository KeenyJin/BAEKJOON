// Implementing L and R without using string will be faster than below.

#include <iostream>
#include <string>
#include <queue>
using namespace std;

char dp[10000];
int before[10000];
string addzero(string);
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T; cin>>T;
	for(;T>0;T--){
		for(int i=0;i<10000;i++) dp[i] = 'X';
		string a, b; cin>>a>>b;
		int sia = stoi(a), sib = stoi(b);
		dp[sia] = 'Z';
		queue<int> q; q.push(sia);
		while(!q.empty()){
			int g = q.front(); q.pop();
			if(dp[sib] != 'X') break;
			string s = addzero(to_string(g));
			for(int i=0;i<4;i++){
				int t = -1; char c; string r;
				if(i==0){t = (2*g)%10000; c = 'D';}
				else if(i==1){
					if(g) t = g-1;
					else t = 9999;
					c = 'S';
				}
				else if(i==2 && dp[g] != 'R'){
					r = s; c = r[0]; r.erase(r.begin()); r.push_back(c);
					c = 'L'; t = stoi(r);
				}
				else if(i==3 && dp[g] != 'L'){
					r = s; c = r[3]; r.pop_back(); r.insert(r.begin(), c);
					c = 'R'; t = stoi(r);
				}
				if(t == -1 || dp[t] != 'X') continue;
				dp[t] = c; before[t] = g;
				q.push(t);
			}
		}
		string k (1, dp[sib]); int p = before[sib];
		while(dp[p] != 'Z'){k += dp[p]; p = before[p];}
		for(int i=k.size()-1;i>=0;i--) cout<<k[i];
		cout<<'\n';
	}
	
	return 0;
}

string addzero(string s){
	if(s.size()==4) return s;
	if(s.size()==3) return '0'+s;
	if(s.size()==2) return "00"+s;
	return "000"+s;
}
