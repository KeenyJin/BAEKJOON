#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); // Must use cin/cout.tie(). Otherwise, timeout error occurs.

    int n, order; cin>>n;
    priority_queue<int> q;
    for(int i=0;i<n;i++){
        cin>>order;
        if(order) q.push(order);
        else{
            if(q.empty()) cout<<"0\n";
            else{
                cout<<q.top()<<"\n";
                q.pop();
            }
        }
    }
    
    return 0;
}
