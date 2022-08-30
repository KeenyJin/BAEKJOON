#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin>>n>>m;
    int *sum = new int[n+1];
    
    sum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>sum[i]; sum[i]+=sum[i-1];
    }
    for(int i=0;i<m;i++){
        int s, f; cin>>s>>f;
        cout<<sum[f]-sum[s-1]<<'\n';
    }

    delete[] sum;
    return 0;
}
