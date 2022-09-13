#include <iostream>
using namespace std;

inline int min_2(int x, int y){return (x<y)?x:y;}
inline int min_3(int x, int y, int z){return min_2(min_2(x, y), z);}
inline int min_arr(int *x){return min_3(*x, *(x+1), *(x+2));}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, arr[1000][3]={}; //arr[i][j] contains a minimum cost for painting 1~i houses(i house: j color).
    cin>>N;
    cin>>arr[0][0]>>arr[0][1]>>arr[0][2];
    for(int i=1;i<N;i++) {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        arr[i][0]+=min_2(arr[i-1][1], arr[i-1][2]);
        arr[i][1]+=min_2(arr[i-1][0], arr[i-1][2]);
        arr[i][2]+=min_2(arr[i-1][0], arr[i-1][1]);
    }
    cout<<min_arr(arr[N-1]);
    
    return 0;
}

