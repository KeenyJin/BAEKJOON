// Meet in the Middle Algorithm.
// Divide one exponential problem into two.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, c, cnt=0; cin>>n>>c;
	vector<int> obj1, obj2;
	for(int i=0;i<n;i++){
		int o; cin>>o;
		if(i%2==1) obj1.push_back(o);
		else obj2.push_back(o);
	}
	if(n==1){  // There is only one object so cannot use MITM.
		if(obj2[0]<=c) cout<<2;
		else cout<<1;
		return 0;  // End code.
	}
	
	vector<int> ans1, ans2;
	ans1.push_back(0); ans2.push_back(0);
	for(int i=0;i<obj1.size();i++){
		int a = ans1.size();
		for(int j=0;j<a;j++){
			if(ans1[j]+obj1[i]<=c) ans1.push_back(ans1[j]+obj1[i]);
		}
	}
	for(int i=0;i<obj2.size();i++){
		int a = ans2.size();
		for(int j=0;j<a;j++){
			if(ans2[j]+obj2[i]<=c) ans2.push_back(ans2[j]+obj2[i]);
		}
	}
	sort(ans1.begin(), ans1.end());  // Sort one part and merge.
	for(int a: ans2){
		int lo = -1, hi = ans1.size();
		while(hi!=lo+1){
			int md = (hi+lo)/2;
			if(ans1[md]<=c-a) lo = md;
			else hi = md;
		}
		cnt += hi;
	}
	
	cout<<cnt;
	return 0;
}
