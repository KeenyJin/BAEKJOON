#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, min, ans[2]; cin>>n;
	int* num = new int[n];
	for(int i=0;i<n;i++) cin>>num[i];
	sort(num, num+n);
	
	int *p=num, *q=num+n-1;
	min = abs(*p+*q); ans[0]=*p; ans[1]=*q;
	while(p!=q){
		if(min == 0) break;
		int sum = *p+*q;
		if(min > abs(sum)){
			min = abs(sum); ans[0]=*p; ans[1]=*q;
		}
		else if(sum > 0) q--;
		else p++;
	}
	cout<<ans[0]<<" "<<ans[1];
	
	delete[] num;
	return 0;
}
