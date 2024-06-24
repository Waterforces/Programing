#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,k;
char s[N],q[N];
int dis[N],b[N];
int  sum;
vector<int> v[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> pq;

void bfs(int x,int y) {
    if(x>n || y>n) return ;
    int cur=v[x][y];
    int _size=v[x].size();
    for(int i=0;i<_size;i++) {
        int next=v[x][y];
    }
}

int main() {
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        cin >> s[i];
        dis[i]=INT_MAX:
    }
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<k;i++) cin >> q[i];
    pq.push({d[1]=0,1});
    while(!pq.empty()) {
        auto [x,y]=pq.top();
        pq.pop();
        bfs(x,y);
    }
}