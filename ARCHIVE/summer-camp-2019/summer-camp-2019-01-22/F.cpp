#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int INF = 1e6;
const int N = 55, T = 300;

int n, tMax, m;
int pd[N][T], travel[N];
vector<int> go[N], back[N];

int solve (int st, int tim) {
    if (st == 0 or st > n) return INF;
    if (tim > tMax) return INF;
    
    int &ret = pd[st][tim];
    if (ret != -1) return ret;
    
    if (st == n)
        ret = tMax-tim;
    else
        ret = INF;
    for (int t : go[st])
        if (t >= tim)
            ret = min (ret, solve (st+1, t+travel[st]) + (t - tim));
    for (int t : back[st])
        if (t >= tim)
            ret = min (ret, solve (st-1, t+travel[st-1]) + (t - tim));
//     printf ("%d %d %d\n", st, tim, ret);
    return ret;
}

void fGo (int t) {
    int pos = 1;
    while (pos <= n and t <= tMax) {
        go[pos].push_back (t);
        t += travel[pos];
        pos++;
    }
}

void fBack (int t) {
    int pos = n;
    while (pos >= 1 and t <= tMax) {
        back[pos].push_back (t);
        t += travel[pos-1];
        pos--;
    }
}

int main()
{
    int caso = 1;
    while (scanf ("%d", &n), n) {
        memset (pd, -1, sizeof pd);
        for (int i = 1; i <= n; i++) {
            go[i].clear();
            back[i].clear();
        }
        scanf ("%d", &tMax);
        for (int i = 1; i <= n-1; i++) {
            int t;
            scanf ("%d", &t);
            travel[i] = t;
        }
        
        scanf ("%d", &m);
        while (m--) {
            int t;
            scanf ("%d", &t);
            fGo (t);
        }
        scanf ("%d", &m);
        while (m--) {
            int t;
            scanf ("%d", &t);
            fBack (t);
        }
        
        int ans = solve (1, 0);
        
        printf ("Case Number %d: ", caso++);
        if (ans > tMax)
            printf ("impossible\n");
        else
            printf ("%d\n", ans);
    }

    return 0;
}
