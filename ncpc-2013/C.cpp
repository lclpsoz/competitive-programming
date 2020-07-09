#include <bits/stdc++.h>
using namespace std;

// --
#define x first
#define y second
#define len(x) ((int)x.size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
    return (int)(((x%m) + m)%m);
}
// --

vector<int> vec = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

int main() {
    ld x;
    scanf ("%Lf", &x);
    vector<int> ans;
    for(int i = 1; i < len(vec); i++)
        for(int j = vec[i-1]; j < vec[i]; j++) {
            int nxt = (j%vec[i-1])*10 + j/vec[i-1];
            if(nxt >= j and cmp(nxt, j*x) == 0)
                ans.push_back(j);
        }
    if(len(ans) == 0)
        printf("No solution\n");
    for(int y : ans)
        printf("%d\n", y);

    return 0;
}