#include<bits/stdc++.h>
using namespace std;
int n,m,_max,cou;
char s[35][35];
bool visited[35][35];

void flood(int x,int y) {
    // cout << x << " " << y << "\n";
    if(x<=0 || y<=0 || x>n || y>m) return ;
    if(visited[x][y]) return ;
    if(s[x][y]=='#') return ;
    if(s[x+1][y]!='#' && s[x-1][y]!='#' && s[x][y+1]!='#' && s[x][y-1]!='#') cou++;
    //cout << x << " " << y << "\n";
    visited[x][y]=true ;
    flood(x,y+1);
    flood(x,y-1);
    flood(x+1,y);
    flood(x-1,y);
}

int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> s[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s[i][j]=='#') continue ;
            if(visited[i][j]) continue ;
            cou=0;
            flood(i,j);
            _max=max(_max,cou);
            cout << _max << " " << cou << "\n";
        }
    }
    cout << _max;
}