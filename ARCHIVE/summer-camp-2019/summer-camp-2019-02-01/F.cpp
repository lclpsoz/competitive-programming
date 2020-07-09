#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n;
map<int, int> mp;
pii vec[60];
bool done[60];
int qntArr[60];
set<int> eachTyp[60];

bool solve (int now) {
    memset (done, false, sizeof done);
    memset (qntArr, false, sizeof qntArr);
    for (int i = 1; i <= n; i++)
        eachTyp[i].clear();
    
    int x, y;
    x = vec[now].x;
    y = vec[now].y;
    int qntWer = 0;
    for (int i = 1; i <= n; i++)
        if (i != now) {
            if (vec[i].x == now or vec[i].y == now) {
                qntWer++;
                done[i] = true;
            }
        }
        
    if (qntWer > n/2)
        return true;
    qntArr[now] = qntWer;
    
    for (int i = 1; i <= n; i++)
        if (!done[i] and i != now) {
            int a = vec[i].x;
            int b = vec[i].y;
            if (qntArr[a] >= qntWer-1 or ((a == x or a == y) and
                qntArr[a] >= qntWer-2))
                swap (a, b);
            if (qntArr[a] >= qntWer-1 or ((a == x or a == y) and
                qntArr[a] >= qntWer-2)) {
                int choosen = -1, u;
                for (int v : eachTyp[a]) {
                    if (vec[v].x == a)
                        swap (vec[v].x, vec[v].y);
                    u = vec[v].x;
                    if (qntArr[u] == qntWer-1 or ((u == x or u == y) and qntArr[a] == qntWer-2))
                        continue;
                    choosen = v;
                    break;
                }
                if (choosen == -1) return false;
                qntArr[a]--;
                eachTyp[a].erase (choosen);
                qntArr[u]++;
                eachTyp[u].insert (choosen);
                
            }
            eachTyp[a].insert (i);
            qntArr[a]++;
        }
//     for (int i = 1; i <= n; i++)
//         printf ("%d %d\n", i, qntArr[i]);
    return true;
}

int main () {
    while (scanf ("%d", &n) != EOF) {
        mp.clear();
        for (int i = 1; i <= n; i++) {
            int x, y;
            scanf ("%d %d", &x, &y);
            vec[i] = {x, y};
            mp[x]++, mp[y]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!solve (i))
                ++ans;
//              printf ("|%d\n", ans);
        }
        printf ("%d\n", ans);
    }

	return 0;
}
