#include <iostream>
#include <cstdlib>
//#include <vector>
#define MAX 20

using namespace std;

int n, s[MAX][MAX]={};
int s_min=2147483647;

int team_start[MAX/2]={}, team_link[MAX/2]={};
bool not_available[MAX]={};
//vector<int> team_start;

void func(int k, int pos){
    if(k==n/2){
        //vector<int> team_link;
        int idx=0;
        for(int i=0;i<n;i++) if(!not_available[i]) {
            //team_link.push_back(i);
            team_link[idx]=i; idx++;
        }
        int s_start=0, s_link=0;
        for(int i=0;i<n/2;i++) for(int j=0;j<n/2;j++) {
            if(i==j) continue;
            s_start+=s[team_start[i]][team_start[j]];
            s_link+=s[team_link[i]][team_link[j]];
        }
        s_min = (s_min < abs(s_start-s_link)) ? s_min : abs(s_start-s_link);
        return;
    }
    for(int i=pos;i<n;i++){
        if(k==0 && i>=n/2) return;
        not_available[i]=true;
        team_start[k]=i;
        func(k+1, i+1);
        not_available[i]=false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> s[i][j];
    
    func(0,0);
    cout<<s_min;

    return 0;
}
