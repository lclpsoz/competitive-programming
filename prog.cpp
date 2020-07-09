#include <bits/stdc++.h>

using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
#define len(x) (int)x.size()
#define X real()
#define Y imag()
#define mp make_pair
using pii = pair < int, int > ;
using ll = long long;
using ld = long double;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

int n, m;
char mat[1010][1010];
vector < int > rows[1010], cols[1010];

int main() {
    scanf("%d %d", & n, & m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf(" %c", & mat[i][j]);
            if (mat[i][j] == '@') {
                rows[i].pb(j);
                cols[j].pb(i);
            }
        }
    int ans = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int aux = 10100;
            if (rows[i].size()) {
                vector < int > & v = rows[i];
                auto it = lower_bound(v.begin(), v.end(), j);
                if (it == v.end()) {
                    aux = abs(v[v.size() - 1] - j);
                } else {
                    int pos = it - v.begin();
                    if (pos == 0)
                        aux = abs( * it - j);
                    else
                        aux = min(abs( * it - j), abs(v[pos - 1] - j));
                }
            }
            if (cols[j].size()) {
                vector < int > & v = cols[j];
                if (!v.empty()) {
                    auto it = lower_bound(v.begin(), v.end(), i);
                    if (it == v.end()) {
                        aux = min(aux, abs(v[v.size() - 1] - i));
                    } else {
                        int pos = it - v.begin();
                        if (pos == 0)
                            aux = min(abs( * it - i), aux);
                        else
                            aux = min(aux, min(abs( * it - i), abs(v[pos - 1] - i)));
                    }
                }
            }

            if (aux == 10100) {
                printf("%d\n", -1);
                return 0;
            } else {
                ans = max(ans, aux);
            }
        }
    printf("%d\n", ans == 10100 ? -1 : ans);

    return 0;
}
