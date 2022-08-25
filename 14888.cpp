#include <iostream>

using namespace std;

int n, num[11]={}, op[4]={};
int mini, maxi, cnt=0;
int result;

void func(int k){
    if(k==n-1){
        if(cnt==0){
            mini = result;
            maxi = result;
            cnt++;
        }
        else{
            mini = (mini<result)?mini:result;
            maxi = (maxi>result)?maxi:result;
        }
        return;
    }
    for(int i=0;i<4;i++){
        if(op[i]!=0){
            op[i]--;
            int prev_result=result;
            switch(i){
                case 0:
                    result+=num[k+1];
                    break;
                case 1:
                    result-=num[k+1];
                    break;
                case 2:
                    result*=num[k+1];
                    break;
                case 3:
                    result/=num[k+1];
                    break;
            }
            func(k+1);
            op[i]++;
            result=prev_result;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++) cin>>num[i];
    cin>>op[0]>>op[1]>>op[2]>>op[3];

    result=num[0];
    func(0);

    cout<<maxi<<'\n'<<mini;
    return 0;
}
