#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    int **sum = new int*[n];
    for(int i=0;i<n;i++) {
        sum[i] = new int[n+1]; sum[i][0]=0;
    }
    
    for(int j=0;j<n;j++){
        for(int i=1;i<=n;i++){
            cin>>sum[j][i]; sum[j][i]+=sum[j][i-1];
        }
    }
    for(int i=0;i<m;i++){
        int s1, f1, s2, f2, ans=0;
        cin>>s1>>f1>>s2>>f2;
        for(int j=s1-1;j<s2;j++) ans+=sum[j][f2]-sum[j][f1-1];
        cout<<ans<<'\n';
    }
    
    for(int i=0;i<n;i++) delete[] sum[i];
    delete[] sum;
    return 0;
}
