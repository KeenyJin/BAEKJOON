#include <iostream>
using namespace std;

inline int max_2(int x, int y){return (x>y)?x:y;}
int max_arr(int *x, int y){
    int max = *x;
    for(int i=1;i<=y;i++) max = max_2(max, *(x+i));
    return max;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, arr[500][500]={};
    cin>>N;
    cin>>arr[0][0];
    for(int i=1;i<N;i++){
        cin>>arr[i][0]; arr[i][0]+=arr[i-1][0];
        for(int j=1;j<i;j++){
            cin>>arr[i][j];
            arr[i][j]+=max_2(arr[i-1][j-1], arr[i-1][j]);
        }
        cin>>arr[i][i]; arr[i][i]+=arr[i-1][i-1];
    }
    cout<<max_arr(arr[N-1], N-1);

    return 0;
}
