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

using pp = pair<ld, ld>;

int n;
ld x, y;
pp pX, pY;
vector<pp> pts;
ld pi = 3.14;
    
ld sq (pp a, pp b) {
    pp ax = {a.x-b.x, a.y-b.y};
    return ax.x*ax.x + ax.y*ax.y;
}

ld dist (pp a, pp b) {
    return sqrt (sq (a, b));
}

ld getSqMax (pp a) {
    ld ret = -1;
    for (pp p : pts)
        ret = max (ret, sq (a, p));
    
    return ret;
}

int main () {
    
    
    pX.x = pY.x = 1e18; // Get min
    pX.y = pY.y = - 1e18; // Get max
    scanf ("%d", &n);
    while (n--) {
        scanf ("%Lf %Lf", &x, &y);
        pts.push_back ({x, y});
        pX.x = min (pX.x, x);
        pX.y = max (pX.y, x);
        pY.x = min (pY.x, y);
        pY.y = max (pY.y, y);
    }
    
    pp ans;
    
    int iterations = 20;
    int qntPts = 900;
    int qntBests = 9;
    vector<pair<ld, pp>> vec;
    for (int i = 0; i < iterations; i++) {
        vec.clear();
//         printf ("\n_____________________________\n");
//         printf ("x-> [%Lf, %Lf]\t", pX.x, pX.y);
//         printf ("y-> [%Lf, %Lf]\n", pY.x, pY.y);
        
        int sq = (int)sqrt (qntPts) - 1;
        ld dX = (pX.y - pX.x)/sq, dY = (pY.y - pY.x)/sq;
        pp pt = {pX.x, pY.x};
        for (int j = 0; j <= sq; j++) {
            pt.y = pY.x;
            for (int k = 0; k <= sq; k++) {
//                 printf ("[%.3Lf, %.3Lf] %.2Lf\n", pt.x, pt.y, sqrt (getSqMax (pt)));
                printf ("%d, %Lf\n", i, getSqMax (pt)); 
                vec.push_back ({getSqMax (pt), pt});
                pt.y += dY;
            }
            pt.x += dX;
        }
            
        sort (vec.begin(), vec.end());
        while (len (vec) > qntBests) vec.pop_back ();
        pX.x = pY.x = 1e18; // Get min
        pX.y = pY.y = - 1e18; // Get max
        for (auto p : vec) {
//             printf ("(%.3Lf, %.3Lf) %.2Lf\n", p.y.x, p.y.y, sqrt (getSqMax (p.y)));
            x = p.y.x, y = p.y.y;
            pX.x = min (pX.x, x);
            pX.y = max (pX.y, x);
            pY.x = min (pY.x, y);
            pY.y = max (pY.y, y);
        }
    }
//     printf ("x-> [%Lf, %Lf]\n", pX.x, pX.y);
//     printf ("y-> [%Lf, %Lf]\n", pY.x, pY.y);
    ld r = sqrt (vec.begin()->x);
    ans.x = (pX.x + pX.y)/2;
    ans.y = (pY.x + pY.y)/2;
    if (abs (ans.x) < 0.01) ans.x = 0;
    if (abs (ans.y) < 0.01) ans.y = 0;
    
    printf ("%.2Lf %.2Lf %.2Lf %.2Lf\n", ans.x, ans.y, r, 2*pi*r*4);

	return 0;
}
