#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, cnt=0; cin>>n;
	int* prime = new int[n+1];
	for(int i=2;i<=n;i++) prime[i] = i;
	for(int i=2;i<=sqrt(n);i++){
		if(prime[i]==0) continue;
		for(int j=i*i;j<=n;j+=i) prime[j] = 0;
	}
	vector<int> prime_sum; prime_sum.push_back(0);
	for(int i=2;i<=n;i++){
		if(prime[i]!=0) prime_sum.push_back(i + prime_sum[prime_sum.size()-1]);
	}
	
	int i = prime_sum.size()-2, j = prime_sum.size()-1;
	while(i!=j && i>=0){
		int k = prime_sum[j] - prime_sum[i];
		if(k == n){cnt++; i--;}
		else if(k < n) i--;
		else j--;
	}
	cout<<cnt;
	
	delete[] prime;
	return 0;
}
