#include <iostream>
using namespace std;

int color[2]={};
int arr[128][128];
bool func(int, int, int);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    if(func(0, 0, n)) color[arr[0][0]]++;
    cout<<color[0]<<'\n'<<color[1];

    return 0;
}

bool func(int r, int c, int x){
    if(x==1) return true; //Cannot divide any more.
    int y = x/2;
    bool a = func(r, c, y), b = func(r+y, c, y);
    bool d = func(r, c+y, y), e = func(r+y, c+y, y);
    if(a && b && d && e){
        //Divide into 4. If all 4 parts are squares:
        int sum = arr[r][c]+arr[r+y][c]+arr[r][c+y]+arr[r+y][c+y];
        if(sum == 0 || sum == 4)
            return true; //All 4 parts are the same color, so total is a square.
        color[arr[r][c]]++; color[arr[r+y][c]]++;
        color[arr[r][c+y]]++; color[arr[r+y][c+y]]++;
        return false; //4 parts are not the same color.
    }
    if(a) color[arr[r][c]]++;
    if(b) color[arr[r+y][c]]++;
    if(d) color[arr[r][c+y]]++;
    if(e) color[arr[r+y][c+y]]++;
    return false; //At least one part is not a square.
}
