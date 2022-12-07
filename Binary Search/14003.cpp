#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n; cin>>n;
	int* arr = new int[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	vector<vector<pair<int, int> > > ans;
	for(int i=0;i<n;i++){
		if(ans.size()==0 || arr[i] > ans[ans.size()-1][ans[ans.size()-1].size()-1].second){
			vector<pair<int, int> > v(1, make_pair(i, arr[i]));
			ans.push_back(v);
			continue;
		}
		int lo = -1, hi = ans.size();
		while(hi!=lo+1){
			int md = (hi+lo)/2;
			if(ans[md][ans[md].size()-1].second >= arr[i]) hi = md;
			else lo = md;
		}
		ans[hi].push_back(make_pair(i, arr[i]));
	}
	cout<<ans.size()<<'\n';
	
	pair<int, int> p = ans[ans.size()-1][ans[ans.size()-1].size()-1];
	int rightest_idx = p.first;
	vector<int> lis(1, p.second);
	for(int i=ans.size()-2;i>=0;i--){
		for(int j=ans[i].size()-1;j>=0;j--){
			if(ans[i][j].first < rightest_idx){
				rightest_idx = ans[i][j].first;
				lis.push_back(ans[i][j].second);
				break;
			}
		}
	}
	for(int i=lis.size()-1;i>=0;i--) cout<<lis[i]<<" ";
	
	delete[] arr;
	return 0;
}
