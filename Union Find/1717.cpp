#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin>>n>>m;
	int* arr = new int[n+1];
	for(int i=0;i<=n;i++) arr[i] = i;
	
	for(int i=0;i<m;i++){
		int o, a, b; cin>>o>>a>>b;
		vector<int> x = {a}, y = {b};
		while(true){
			if(arr[x.back()]==x.back()) break;
			x.push_back(arr[x.back()]);
		}
		while(true){
			if(arr[y.back()]==y.back()) break;
			y.push_back(arr[y.back()]);
		}
		for(int j=0;j<x.size()-1;j++) arr[x[j]] = arr[x.back()];
		for(int j=0;j<y.size()-1;j++) arr[y[j]] = arr[y.back()];
		if(o){
			if(x.back()==y.back()) cout<<"YES\n";
			else cout<<"NO\n";
		}
		else{
			if(x.back()>y.back()) arr[x.back()] = y.back();
			else arr[y.back()] = x.back();
		}
	}
	
	delete[] arr;
	return 0;
}
