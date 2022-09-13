#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k; cin>>k>>n;
    long long *wire = new long long[k];
    cin>>wire[0];
    long long max=wire[0], sum=wire[0];
    for(int i=1;i<k;i++){
        cin>>wire[i]; sum+=wire[i];
        if(wire[i]>max) max=wire[i];
    }

    long long hi = sum/n + 1, lo = max/n;
    
    while(hi!=lo+1){
        int cnt=0;
        long long len=(hi+lo)/2;
        for(int i=0;i<k;i++) cnt+=wire[i]/len;
        if(cnt>=n) lo=len;
        else hi=len;
    }
    cout<<lo;

    delete[] wire;
    return 0;
}
