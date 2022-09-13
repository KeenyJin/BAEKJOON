#include <iostream>
using namespace std;

int mat1[100][100], mat2[100][100], result[100][100];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M, K; cin>>N>>M;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin>>mat1[i][j];
    cin>>M>>K;
    for(int i=0;i<M;i++) for(int j=0;j<K;j++) cin>>mat2[i][j];
    for(int i=0;i<N;i++) for(int j=0;j<K;j++) for(int k=0;k<M;k++)
        result[i][j] += mat1[i][k]*mat2[k][j];
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
