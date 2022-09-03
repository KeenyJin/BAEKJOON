#include <iostream>
#include <string>
using namespace std;

string ans, arr[64];
void func(int, int, int);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    func(0, 0, n);
    cout<<ans;

    return 0;
}

void func(int r, int c, int x){
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(arr[r+i][c+j]!=arr[r][c]){
                ans += "("; int y = x/2;
                func(r, c, y); func(r, c+y, y);
                func(r+y, c, y); func(r+y, c+y, y);
                ans += ")"; return;
            }
        }
    }
    ans += arr[r][c];
    return;
}
