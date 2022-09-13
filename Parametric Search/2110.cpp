#include <iostream>
#include <algorithm>
using namespace std;

int n, c;

bool check(int m, int* h){
    int idx = 0, cnt = 1;
    while(cnt<c){
        int dist = 0;
        while(dist<m){
            idx++;
            if(idx>=n) return false;
            dist += h[idx]-h[idx-1];
        }
        cnt++;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>c;
    int *home = new int[n];
    for(int i=0;i<n;i++) cin>>home[i];
    sort(home, home+n);

    int lo = 1, hi = (home[n-1]-home[0])/(c-1) + 1;
    while(hi!=lo+1){
        int md = (lo+hi)/2;
        if(check(md, home)) lo=md;
        else hi=md;
    }
    cout<<lo;

    delete[] home;
    return 0;
}
