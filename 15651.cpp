#include <iostream>
#define MAX 7

using namespace std;

int n, m, ans[MAX]={};

void func(int k){
    if(k==m){
        for(int i=0;i<m-1;i++) cout<<ans[i]<<" ";
        cout<<ans[m-1]<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        ans[k]=i+1;
        func(k+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    func(0);
    return 0;
}
