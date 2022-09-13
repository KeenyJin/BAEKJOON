#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

template <class T> struct absless {
    bool operator() (const T& x, const T& y){
        if(abs(x)!=abs(y)) return abs(x)>abs(y);
        else return x>y;
    }
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, order; cin>>n;
    priority_queue<int, vector<int>, absless<int>> q;
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
