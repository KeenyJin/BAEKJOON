#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string sum(string, string);

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    // n can be 10000, which the answer is so large that 'long long' cannot handle it.
    // So let's calculate fibonacci numbers using 'string'.
    // https://j3sung.tistory.com/295
    string dp[10001]; dp[0]="0"; dp[1]="1";
    for(int i=2;i<=n;i++) dp[i]=sum(dp[i-1], dp[i-2]);
    cout<<dp[n];

    return 0;
}

string sum(string a, string b){
    string res; int carry=0;
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
    while(a.length()<b.length()) a+="0";
    while(a.length()>b.length()) b+="0";
    // Now the length of a and b are same.
    for(int i=0;i<a.length();i++){
        int plus = a[i]-'0'+b[i]-'0'+carry; // char-'0'=int
        res += to_string(plus%10);
        carry = plus/10;
    }
    if(carry) res+=to_string(carry);

    reverse(res.begin(), res.end());

    return res;
}
