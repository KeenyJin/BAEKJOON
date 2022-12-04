#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, s; cin>>n>>s;
	int* sum = new int[n+1];
	sum[0]=0; cin>>sum[1];
	for(int i=2;i<=n;i++){
		cin>>sum[i]; sum[i]+=sum[i-1];
	}
	if(sum[n] < s){cout<<0; return 0;}
	int ans=n, i=n-1, j=n;
	while(i!=j && i>=0){
		int plus = sum[j] - sum[i];
		if(plus >= s){
			if(ans > j-i) ans = j-i;
			j--;
		}
		else i--;
	}
	cout<<ans;
	
	delete[] sum;
	return 0;
}
