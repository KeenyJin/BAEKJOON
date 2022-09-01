#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    stack<int> a;
    int *arr = new int[n];
    int *nge = new int[n];

    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=n-1;i>=0;i--){
        while(!a.empty() && a.top()<=arr[i]) a.pop();
        if(a.empty()) nge[i]=-1;
        else nge[i]=a.top();
        a.push(arr[i]);
    }
    for(int i=0;i<n;i++) cout<<nge[i]<<" ";

    delete[] nge;
    return 0;
}
