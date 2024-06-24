#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
int n;
bool visited[1005];
bool ans;

void re() {
    ans=0;
    for(int i=1;i<=n;i++) visited[i]=false ;
}

void run(int cur) {
    int _size=v[cur].size();
    if(visited[cur]) {
        ans++;
        return ;
    }
    visited[cur]=true ;
    if(_size==0) return ;
    for(int i=0;i<_size;i++) {
        run(v[cur][i]);
    }
    // visited[cur]=false ;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        int k;
        cin >> k;
        for(int j=1;j<=k;j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    for(int i=1;i<=n;i++) {
        re();
        run(i);
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}