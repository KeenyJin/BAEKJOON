#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, x, cnt=0; cin>>n;
	int* num = new int[n];
	for(int i=0;i<n;i++) cin>>num[i];
	sort(num, num+n); cin>>x;
	
	int *p=num, *q=num+n-1;
	while(p!=q){
		if(x > *p+*q) p++;
		else if(x < *p+*q) q--;
		else{cnt++; p++;}
	}
	cout<<cnt;
	
	delete[] num;
	return 0;
}
