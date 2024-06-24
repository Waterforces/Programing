#include<bits/stdc++.h>
using namespace std;
map<vector<int>,int> mp;
int n,m;
vector<int> q;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        vector<int> v;
        for(int j=0;j<m;j++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        mp[v]=i;
    }
    for(int i=1;i<=m;i++) {
        int a;
        cin >> a;
        q.push_back(a);
    }
    if(mp[q]!=0) {
        cout << mp[q];
        return 0;
    }
    for(auto x:mp) {
        vector<int> v;
        for(int i=0;i<m;i++) {
            int k=q[i]-x.first[i];
            v.push_back(k);
        }
        if(mp.count(v)) {
        cout << x.second << " " << mp[v];
        return 0;            
        }
    }
    cout << "NO";
}