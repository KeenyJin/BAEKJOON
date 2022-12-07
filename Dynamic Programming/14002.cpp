#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, ans[2]={}; cin>>n;
	int* arr = new int[n];
	int** dp = new int*[n];
	for(int i=0;i<n;i++) dp[i] = new int[2];
	for(int i=0;i<n;i++){cin>>arr[i]; dp[i][0]=0;}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++) if(arr[i]>arr[j] && dp[i][0]<dp[j][0]){
			dp[i][0] = dp[j][0]; dp[i][1] = j;
		}
		dp[i][0]++;
		if(ans[0]<dp[i][0]){
			ans[0] = dp[i][0]; ans[1] = i;
		}
	}
	
	cout<<ans[0]<<'\n';
	vector<int> sq(1, ans[1]);
	for(int i=1;i<ans[0];i++) sq.push_back(dp[sq.back()][1]);
	for(int i=0;i<ans[0];i++) cout<<arr[sq[ans[0]-1-i]]<<" ";
	
	for(int i=0;i<n;i++) delete[] dp[i];
	delete[] arr, dp;
	return 0;
}
