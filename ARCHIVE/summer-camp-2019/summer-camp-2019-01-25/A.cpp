#include<bits/stdc++.h>
using namespace std;

// -----------
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
// -----------

using T = ll;

struct pt {
    T x, y;
    
    pt operator+ (pt p) {return {x+p.x, y+p.y};}
    pt operator- (pt p) {return {x-p.x, y-p.y};}
};

bool operator< (pt p1, pt p2) {
    return make_pair(p1.x, p1.y) < make_pair(p2.x, p2.y);
}

ostream& operator<< (ostream& os, pt p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

T cross (pt a, pt b) { return a.x*b.y - a.y*b.x; }

T inner (pt a, pt b) { return a.x*b.x - a.y*b.y; }

bool ccw (pt p, pt q, pt r) {
    return cross (q-p, r-p) > 0;
}

bool collinear (pt p, pt q, pt r) {
    return cross (p-q, r-q) == 0;
}

int leftmostIndex (vector<pt> &P) {
    int ans = 0;
    for (int i = 1; i < len (P); i++)
        if (P[i] < P[ans]) ans = i;
    return ans;
}

T orient (pt a, pt b, pt c) { return cross (b-a, c-a); }

bool properInter (pt a, pt b, pt c, pt d) {
    T oa = orient (c, d, a);
    T ob = orient (c, d, b);
    T oc = orient (a, b, c);
    T od = orient (a, b, d);
//     cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
//     cout << "GER: " << oa << ' ' << ob << ' ' << oc << ' ' << od << '\n';

    if (oa*ob < 0 and oc*od < 0)
        return true;
    return false;
}

pt pivot = {0, 0};
set<pt> points;

bool angleCmp (pt a, pt b) {
    if (collinear (pivot, a, b))
        return inner (pivot-a, pivot-a) < inner (pivot-b, pivot-b);
    return cross (a-pivot, b-pivot) >= 0;
}

vector<pt> convexHull (vector<pt> P) {
    int i, j, n = len (P);
    if (n <= 2)
        return P;
    int P0 = leftmostIndex(P);
    swap (P[0], P[P0]);
    pivot = P[0];
    sort (++P.begin(), P.end(), angleCmp);
    vector<pt> S;
    S.push_back (P[n-1]);
    S.push_back (P[0]);
    S.push_back (P[1]);
    for (i = 2; i < n;) {
        j = len (S) - 1;
        if (ccw (S[j-1], S[j], P[i])) S.push_back (P[i++]);
        else
            S.pop_back ();
    }
//     cout << "len (S): " << len (S) << '\n';
    reverse (S.begin(), S.end());
    S.pop_back ();
    reverse (S.begin(), S.end());
    return S;
}


int main () {
//     printf ("TEST: %d\n", properInter ({0, 0}, {1, 0}, {49, 49}, {50, 50}));
    int n;
    vector<pt> vec;
    while (scanf ("%d", &n), n) {
        points.clear();
        while (n--) {
            ll x, y;
            scanf ("%lld %lld", &x, &y);
            points.insert ({x, y});
        }
        
        int cnt = 0;
        bool ans = true;
        while (len (points) >= 3) {
            vec.clear();
//                  cout << len (points) << '\n';
            for (pt p : points)
                vec.push_back (p);
            
            ans = false;
            for (int i = 0; i < len(vec)-2; i++)
                if (orient (vec[i], vec[i+1], vec[i+2]) != 0)
                    ans = true;
            if (!ans) break;
            
//             cout << "len (vec): " << len (vec) << '\n';
            vec = convexHull (vec);
//             cout << "len (vec): " << len (vec) << '\n';
            
            for (pt p : vec) {
//                  cout << p << '\n';
                points.erase (p);
            }
            
            vector<pt> aux;
            for (int i = 0; i < len (vec); i++) {
//                 cout << vec[i] << ' ' << vec[i+1] << '\n';
                for (pt p : points) {
//                      cout << p << '\n';
                    if (i == (len(vec)-1) and orient (vec.back(), vec[0], p) == 0) {
//                          cout << p << '\n';
                        aux.push_back (p);
                    } else if (i < len (vec)-1 and orient (vec[i], vec[i+1], p) == 0) {
//                         cout << i << ' ' << i+1 << '\n';
//                          cout << vec[i] << vec[i+1] << p << '\n';
//                          cout << p << '\n';
                        aux.push_back (p);
                    }
                }
            }
            for (pt p : aux)
                points.erase (p);
//              cout << "len(points): " << len(points) << '\n';
            ++cnt;
        }
//         cout << "ans: " << ans << '\n';
        printf ("%s\n", (len (points) == 0 and cnt%2 == 1 and ans) ? "Take this onion to the lab!" : "Do not take this onion to the lab!");
    }
    
    return 0;
}
