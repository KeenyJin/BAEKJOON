#include <iostream>
#include <vector>

using namespace std;

int n, m; 
bool printed[8] = {};
vector<int> ans;

void func(int k){
    if(k==m){
        for(vector<int>::iterator it=ans.begin();it<ans.end()-1;it++)
            cout << *it << " ";
        cout << *(ans.end()-1) << '\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(!printed[i]){
            printed[i]=true;
            ans.push_back(i+1);
            func(k+1);
            ans.pop_back();
            printed[i]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    func(0);
    return 0;
}
