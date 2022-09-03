#include <iostream>
using namespace std;

int num[3]={};
int arr[2187][2187];
bool func(int, int, int);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    if(func(0, 0, n)) num[arr[0][0]+1]++;
    cout<<num[0]<<'\n'<<num[1]<<'\n'<<num[2];

    return 0;
}

bool func(int r, int c, int x){
    if(x==1) return true; //Cannot divide any more.
    int y = x/3;
    bool a[3][3] = {}, all_square = true;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++){ //Divide into 9.
        a[i][j] = func(r+y*i, c+y*j, y);
        all_square = all_square && a[i][j];
    }
    if(all_square){ //If all 9 parts are squares.
        bool same = true;
        int tmp[3] = {};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                tmp[arr[r+i*y][c+j*y]+1]++;
                if(arr[r+i*y][c+j*y]!=arr[r][c]) same = false;
            }
        }
        if(same) return true; //All 9 parts are same, so total is a square.
        num[0] += tmp[0]; num[1] += tmp[1]; num[2] += tmp[2];
        return false; //9 parts are not the same color.
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]) num[arr[r+y*i][c+y*j]+1]++;
        }
    }
    return false; //At least one part is not a square.
}
