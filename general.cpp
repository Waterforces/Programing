#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N],h[N];

int fn(int cur) {
    if(h[cur]==cur) return cur;
    return h[cur]=fn(h[cur]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        h[i]=i;
    }
    for(int i=1;i<=m;i++) {
        int s,t;
        cin >> s >> t;
        int hs=fn(s);
        int ht=fn(t);
        if(hs==ht) {
            cout << -1 << "\n";
            continue ;
        }
        if(a[hs]<a[ht]) {
            cout << ht << "\n";
            a[ht]+=a[hs];
            a[hs]=0;
            h[hs]=h[ht];
            continue ;
        }
        if(a[hs]>a[ht]) {
            cout << hs << "\n";
            a[hs]+=a[ht];
            a[ht]=0;
            h[ht]=h[hs];
            continue ;
        }
        if(a[hs]==a[ht]) {
            if(hs<ht) {
                cout << hs << "\n";
                a[hs]+=(a[ht]/2);
                a[ht]=0;
                h[ht]=h[hs];
                continue ;
            }
            else {
                cout << ht << "\n";
                a[ht]+=(a[hs]/2);
                a[hs]=0;
                h[hs]=h[ht];
                continue ;
            }
        }
    }
}
