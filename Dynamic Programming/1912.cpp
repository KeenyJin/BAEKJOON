#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int* arr = new int[n];
    cin>>arr[0];
    int max = arr[0];
    for(int i=1;i<n;i++) {
        cin>>arr[i];
        if(arr[i-1]>0) arr[i] += arr[i-1];
        if(max<arr[i]) max = arr[i];
    }
    cout<<max;

    delete[] arr;
	return 0;
}
