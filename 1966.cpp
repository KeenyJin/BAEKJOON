#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    for(int i=0;i<n;i++){
        int N, M; cin>>N>>M;
        int prior, arr[10]={}, cnt=0; //arr: # of papers with priority of index.
        queue<int> printer;
        for(int j=0;j<N;j++){
            int num; cin>>num; printer.push(num); arr[num]++;
            if(j==M) prior=num;
        }
        for(int j=9;j>=prior;j--){
            while(arr[j]!=0){
                int top = printer.front();
                if(top!=j){
                    printer.pop(); printer.push(top);
                }
                else{
                    printer.pop(); cnt++; arr[j]--;
                    if(j==prior && M==0) break;
                }
                if(M==0) M=printer.size()-1;
                else M--;
            }
        }
        cout<<cnt<<'\n';
    }

    return 0;
}

//You can use priority_queue to replace 'arr'.
