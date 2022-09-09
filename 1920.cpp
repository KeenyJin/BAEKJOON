#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int arr[MAX];

int check(int b, int e, int chk){
    if(arr[(b+e)/2]==chk) return 1;
    if(e==b+1) return 0;
    if(arr[(b+e)/2]>chk) return check(b, (b+e)/2, chk);
    else return check((b+e)/2, e, chk);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    int m; cin>>m;
    int *chklst = new int[m];
    for(int i=0;i<m;i++) cin>>chklst[i];
    for(int i=0;i<m;i++) cout<<check(-1, n, chklst[i])<<'\n';

    delete[] chklst;
    return 0;
}

