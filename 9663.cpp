#include <iostream>
#define MAX 15
using namespace std;

int n, cnt=0;
int cant_put_here[MAX][MAX]={};

void func(int k){
    if(k==n){
        cnt++; return;
    }
    for(int i=0;i<n;i++){
        if(cant_put_here[k][i]==0){
            for(int j=k+1;j<n;j++) {
                if(cant_put_here[j][i]==0) cant_put_here[j][i]=k+1;
            }
            for(int j=1;j<n;j++){
                if(k+j>=n) break;
                if(i+j<n && cant_put_here[k+j][i+j]==0) cant_put_here[k+j][i+j]=k+1;
                if(i-j>=0 && cant_put_here[k+j][i-j]==0) cant_put_here[k+j][i-j]=k+1;
            }
            func(k+1);
            for(int j=k+1;j<n;j++) {
                if(cant_put_here[j][i]==k+1) cant_put_here[j][i]=0;
            }
            for(int j=1;j<n;j++){
                if(k+j>=n) break;
                if(i+j<n && cant_put_here[k+j][i+j]==k+1) cant_put_here[k+j][i+j]=0;
                if(i-j>=0 && cant_put_here[k+j][i-j]==k+1) cant_put_here[k+j][i-j]=0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    func(0);
    cout<<cnt;

    return 0;
}
