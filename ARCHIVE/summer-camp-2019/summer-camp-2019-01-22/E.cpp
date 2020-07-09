#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 1e5+10;

int n;
vector<pii> adj[N];
// pii pd[N];
int val[N];
bool friends[N];

pii solve (int v, int parent) {
    pii ret = {0, 0};
    int bst = 2000000000;
    for (auto p : adj[v]) {
        int u = p.x;
        if (u != parent) {
            pii now = solve (u, v);
            ret.y += now.y;
            bst = min (bst, now.x-now.y);
//             printf ("u(%d) -> %d %d\n", u, now.x, now.y);
        }
    }
    if (bst == 2000000000)
        bst = 0;
//     printf ("%d\n", bst);
    ret.x = ret.y + bst;
    if (friends[v] or ret.y)
        ret.y += val[v];
//     printf ("%d (%d, %d) %d\n", v, ret.x, ret.y, bst);
    return ret;
}

void proc (int v, int parent, int now) {
    val[v] = now;
    for (auto p : adj[v])
        if (p.x != parent)
            proc (p.x, v, p.y);
}

int main()
{
    int f;
    while (scanf ("%d %d", &n, &f) != EOF) {
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            friends[i] = false;
        }
        for (int i = 0; i < n-1; i++) {
            int a, b, w;
            scanf ("%d %d %d", &a, &b, &w);
            adj[a].push_back ({b, w});
            adj[b].push_back ({a, w});
        }
        while (f--) {
            int x;
            scanf ("%d", &x);
            friends[x] = true;
        }
        proc (1, 1, 0);
        printf ("%d\n", solve (1, 1).x);
    }

    return 0;
}
