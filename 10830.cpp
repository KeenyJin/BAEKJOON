#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, mat[5][5], ans[5][5]={};
    long long B;
    cin>>N>>B;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++){
        cin>>mat[i][j];
        if(i==j) ans[i][j] = 1;
    }
    while(B){
        int tmp[5][5]={};
        if(B%2){
            for(int i=0;i<N;i++) for(int j=0;j<N;j++){
                tmp[i][j]=ans[i][j]; ans[i][j]=0;
            }
            // ans = ans*M
            for(int i=0;i<N;i++) for(int j=0;j<N;j++){
                for(int k=0;k<N;k++) ans[i][j] += (tmp[i][k]*mat[k][j])%1000;
                ans[i][j] %= 1000;
            }
            if(B==1) break;
        }
        for(int i=0;i<N;i++) for(int j=0;j<N;j++){
            tmp[i][j]=mat[i][j]; mat[i][j]=0;
        }
        // M = M*M
        for(int i=0;i<N;i++) for(int j=0;j<N;j++){
            for(int k=0;k<N;k++) mat[i][j] += (tmp[i][k]*tmp[k][j])%1000; 
            mat[i][j] %= 1000;
        }
        B/=2;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cout<<ans[i][j]<<" ";
        cout<<'\n';
    }
    
    return 0;
}
