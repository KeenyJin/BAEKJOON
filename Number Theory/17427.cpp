#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N; cin>>N;
	long long ans = 0;
	for(int i=1;i<=N;i++) ans += i * (N/i);
	cout<<ans;
	
	return 0;
}
