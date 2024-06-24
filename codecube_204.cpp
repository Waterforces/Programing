#include<bits/stdc++.h>
using namespace std;
typedef struct node {
    vector<pair<int,int> >  v;
    int dis=INT_MAX;
} node;
const int N=5e4+5;
node x[N];
int n,m,sum;
char s[5],q[N]rs[4]={'X','M','A','S'};
priority_queue<pair<int,int> > pq;
map<char,int> mp;
vector<int> f;

void dij(int cur,int dis) {
    if(x[cur].dis<=dis) return ;
    x[cur].dis=dis;
    int _size=x[cur].v.size();
    for(int i=0;i<_size();i++) {
        int next=x[cur].v[i].first;
        int ndis=dis+x[cur].v[i].second;
        if(x[next].dis<=ndis) continue ;
        pq.push({ndis,next});
    }
}

int main() {
    cin >> n >> m;
    for(int i=0;i<4;i++) {
        cin >> s[i];
        if(s[i]=='_') f.push_back(i);
    }
    for(int i=0;i<n;i++) {
        char q;
        cin >> q;
        mp[q]=i;
    }
    for(int i=0;i<m;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        x[a].v.push_back({b,w});
        x[b].v.push_back({a,w});
    }
    pq.push_back({0,1});
    while(!pq.empty()) {
        auto [dis,next] =pq.front();
        pq.pop();
        dij(next,dis);
    }
    for(auto a:f) {
        int idx=mp[rs[a]];
        sum+=x[idx].dis;
    }
    cout << sum;
}