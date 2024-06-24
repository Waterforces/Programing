#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    vector<pair<int,int>> v;
    int dis=INT_MAX;
} node;
int n,m,q;
node x[100005];
int k[100005];
priority_queue<tuple<int,int>> pq;

void dij(int cur,int dis) {
    if(x[cur].dis<=dis) return ;
    x[cur].dis=dis;
    int _size=x[cur].v.size();
    for(int i=0;i<_size;i++) {
        int next=x[cur].v[i].first;
        int ndis=dis+x[cur].v[i].second;
        if(x[next].dis<=ndis) continue ;
        pq.push({ndis,next});
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) k[i]=INT_MAX;
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        x[u].v.push_back({v,w});
        x[v].v.push_back({u,w});
    }
    cin >> q;
    for(int i=0;i<q;i++) {
        int a,b;
        cin >> a >> b;
        if(k[a]>b) {
            k[a]=b;
            pq.push({b,a});
        }
    }
    while(!pq.empty()) {
        auto [dis,next]=pq.top();
        pq.pop();
        dij(next,dis);
    }
    // for(int i=0;i<n;i++) {
    //     cout << i << " " << x[i].dis << "\n";
    // }
    cout << x[0].dis;
}