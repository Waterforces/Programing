// #include<bits/stdc++.h>
// #define T pair<int,int>  
// using namespace std;
// const int N=1e5+5;
// int n,m,s,t;
// int dist[N],p[N];
// vector<pair<int,int> > v[N];
// priority_queue<T,vector<T>,greater<T> > pq;

// void dij(int cur,int dis) {
//     if(dist[cur]<=dis) return ;
//     dist[cur]=dis;
//     for(auto [next,ndis] :v[cur]) {
//         if(dist[next]<=ndis+dis) continue ;
//         p[next]=cur;
//         pq.push({ndis+dis,next});
//     }
// }

// void fnpar(int cur) {
//     if(cur==-1) return ;
//     fnpar(p[cur]);
//     cout << cur << " ";
// }

// int main() {
//     cin >> n >> m >> s >> t;
//     for(int i=0;i<n;i++) dist[i]=INT_MAX;
//     for(int i=0;i<m;i++) {
//         int a,b,w;
//         cin >> a >> b >> w;
//         v[a].push_back({b,w});
//     }
//     p[s]=-1;
//     pq.push({0,s});
//     while(!pq.empty()) {
//         auto [dis,cur]=pq.top();
//         pq.pop();
//         cout << cur << " " << dis << "\n";
//         for(auto [next,ndis]:v[cur]) {
//             if(dist[next]>ndis+dis) {
//                 p[next]=cur;
//                 dist[next]=ndis+dis;
//                 pq.push({ndis+dis,next});
//             }

//         }    
//     }
//     fnpar(t);
// }

#include <bits/stdc++.h>
#define T pair<int,int>
using namespace std;
vector<T> vec[100001];
int dis[100001];
int pre[100001];
priority_queue<T, vector<T>, greater<T>> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,s,t; cin >> n >> m >> s >> t;
    for(int i=0;i<n;i++) dis[i] = INT_MAX;
    while (m--) {
        int u,v,w; cin >> u >> v >> w; w = log(w);
        vec[u].push_back({w, v});
        vec[v].push_back({w, u});
    }
    q.push({dis[s] = 1, s});
    while (!q.empty()) {
        auto [dist,u] = q.top(); q.pop();
        cout << u << " " << dist << "\n";
        for(auto [w,v]:vec[u]) {
            if (dis[v] > dist + w) {
                pre[v] = u;
                dis[v] = dist + w;
                q.push({dis[v], v});
            }
        }
    }
    vector<int> ans;
    while (t!=s) {
        ans.push_back(t);
        t = pre[t];
    }
    ans.push_back(t);
    reverse(ans.begin(), ans.end());
    for(auto i:ans) cout << i << ' ';
    return 0;
}