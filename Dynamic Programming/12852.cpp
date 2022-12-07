#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n; cin>>n;
	int** arr = new int*[n+1];
	for(int i=0;i<=n;i++) arr[i] = new int[2];
	
	arr[n][0] = 1;
	for(int i=n;i>=1;i--){
		for(int j=0;j<3;j++){
			int x;
			if(j==0) x = i-1;
			else if(j==1 && i%2==0) x = i/2;
			else if(j==2 && i%3==0) x = i/3;
			if(arr[x][0]==0 || arr[x][0] > arr[i][0]+1){
				arr[x][0] = arr[i][0] + 1;
				arr[x][1] = i;
			}
		}
	}
	cout<<arr[1][0]-1<<'\n';
	vector<int> ans; ans.push_back(1);
	for(int i=1;i<arr[1][0];i++) ans.push_back(arr[ans.back()][1]);
	for(int i=0;i<ans.size();i++) cout<<ans[ans.size()-1-i]<<" ";
	
	for(int i=0;i<=n;i++) delete[] arr[i];
	delete[] arr;
	return 0;
}
