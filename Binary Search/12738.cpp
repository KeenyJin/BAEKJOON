// Same with Problem #12015.
#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n; cin>>n;
	int* arr = new int[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(ans.size()==0 || arr[i] > ans.back()){
			ans.push_back(arr[i]);
			continue;
		}
		int lo = -1, hi = ans.size();
		while(hi!=lo+1){
			int md = (hi+lo)/2;
			if(ans[md]>=arr[i]) hi = md;
			else lo = md;
		}
		ans[hi] = arr[i];
	}
	cout<<ans.size();
	
	delete[] arr;
	return 0;
}
