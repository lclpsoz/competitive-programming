#include <bits/stdc++.h>
using namespace std;

// -----------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

// --------

const int N = 1e3 + 10;

int n, m;
vector<pair<int, int>> g[N];
int dist[N][N];

void dijkstra(){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dist[i][j] = 1e9;
        }
    }
    dist[1][0] = 0;
    set<pair<int, pair<int, int>>> s;
    s.insert({0, {1, 0}});
    while(!s.empty()){
        int d = s.begin()->x, u = s.begin()->y.x, k = s.begin()->y.y; s.erase(s.begin());
        
        if(dist[u][k] == d){
            for(auto e : g[u]){
                int v = e.x, cost = e.y;
                if(d + cost < dist[v][k + 1]){
                    dist[v][k + 1] = d + cost;
                    s.insert({dist[v][k + 1], {v, k + 1}});
                }
            }
        }
    }
}

int main () {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    
    dijkstra();
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = min(dist[i][j], dist[i][j - 1]);
        }
    }
    
    int q;
    scanf("%d", &q);
    while(q--){
        int v, k;
        scanf("%d %d", &v, &k); k++;
        if(dist[v][k] < 1e9) printf("=] %d\n", dist[v][k]);
        else printf("=[\n");
    }

    return 0;
}
