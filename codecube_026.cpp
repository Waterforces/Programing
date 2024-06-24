#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,_max;
int swp[N],dp[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        dp[a]++;
        dp[b+1]--;
        // dis();
    }
    for(int i=1;i<N;i++) {
        swp[i]=dp[i]+swp[i-1];
        _max=max(_max,swp[i]);
    }
    cout << _max;
}
