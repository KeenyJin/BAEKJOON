#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline int euclidean(int a, int b){
    return a%b ? euclidean(b, a%b) : b;
}

int main(){
    int n;
    int arr[100] = {};
    
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr+n);
    
    int ans = arr[1]-arr[0];
    for(int i=1;i<n-1;i++) ans = euclidean(arr[i+1]-arr[i], ans);

    vector<int> sol;
    for(int i = 2; i*i <= ans; i++){
        if(ans%i==0){
            sol.push_back(i);
            if(i!=ans/i) sol.push_back(ans/i);
        }
    }
    sol.push_back(ans);
    sort(sol.begin(), sol.end());

    for(auto i=0;i<sol.size();i++) cout<<sol[i]<<" ";

    return 0;
}
