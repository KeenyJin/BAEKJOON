//This problem can be solved by HashTable as well.
//Below is the implementation of C++ upper/lower bound, by Binary Search algorithm.

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    int m; cin>>m;
    int *chklst = new int[m];
    for(int i=0;i<m;i++) cin>>chklst[i];
    for(int i=0;i<m;i++){
        int chk = chklst[i], lo = -1, hi = n, uidx = -2, lidx = -1;
        while(hi!=lo+1){
            int idx = (lo+hi)/2;
            if(arr[idx]>=chk) hi = idx;
            else lo = idx;
        }
        if(arr[hi]==chk) lidx=hi;
        hi=n; lo=-1;
        while(hi!=lo+1){
            int idx = (lo+hi)/2;
            if(arr[idx]<=chk) lo = idx;
            else hi = idx;
        }
        if(arr[lo]==chk) uidx=lo;
        cout<< uidx-lidx+1 <<" ";
    }

    delete[] arr, chklst;
    return 0;
}
