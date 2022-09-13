#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    priority_queue<int, vector<int>, less<int>> small;
    priority_queue<int, vector<int>, greater<int>> big;
  // Use two priority queues as one data structure.
  // Always keep the size of 'small' same as or one more bigger than 'big'.
  // Therefore, top value of 'small' is the middle value of the whole data.

    int num, size=1; cin>>num;
    small.push(num); cout<<num<<"\n";
    for(int i=1;i<n;i++){
        cin>>num;
        int t = small.top();
        if(size%2==1){
            if(num>=t) big.push(num);
            else{
                big.push(small.top());
                small.pop();
                small.push(num);
            }
        }
        else{
            if(num>t){
                big.push(num);
                small.push(big.top());
                big.pop();
            }
            else small.push(num);
        }
        cout<<small.top()<<"\n";
        size++;
    }
    
    return 0;
}
