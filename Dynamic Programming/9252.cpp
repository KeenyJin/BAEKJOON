// https://gusdnr69.tistory.com/194
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001] = {0, };
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string a, b, lcs; cin>>a>>b;
	a = ' ' + a;
	b = ' ' + b;
	for(int i=1;i<b.size();i++){
		for(int j=1;j<a.size();j++){
			if(a[j]==b[i]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	int c = a.size()-1, r = b.size()-1;
	while(dp[r][c]){
		if(dp[r][c]==dp[r-1][c]) r--;
		else if(dp[r][c]==dp[r][c-1]) c--;
		else{lcs += a[c]; r--; c--;}
	}
	
	cout<<dp[b.size()-1][a.size()-1]<<'\n';
	if(lcs.size()) for(int i=lcs.size()-1;i>=0;i--) cout<<lcs[i];
	
	return 0;
}
