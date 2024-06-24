#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e9+5;
ll n,m,q;
bool dp[N];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        dp[a]=!dp[a];
        dp[a]=!dp[a+b];
    }
    for(int i=1;i<=n;i++) {
        int p;
        cin >> p;
        int up=p,down=p+1;
    }
}