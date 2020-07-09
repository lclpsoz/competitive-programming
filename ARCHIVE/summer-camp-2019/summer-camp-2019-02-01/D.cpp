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

const int N = 104;

int n;
char mat[N][N];
int aux[N][N];
set<pair<int, pii>> st;

bool check (int x, int y) {
    for (int i = x; i < n; i++) {
        if (mat[i][y] == 'X')
            break;
        if (mat[i][y] == 'R')
            return false;
    }
    for (int i = x; i >= 0; i--) {
        if (mat[i][y] == 'X')
            break;
        if (mat[i][y] == 'R')
            return false;
    }
    for (int i = y; i < n; i++) {
        if (mat[x][i] == 'X')
            break;
        if (mat[x][i] == 'R')
            return false;
    }
    for (int i = y; i >= 0; i--) {
        if (mat[x][i] == 'X')
            break;
        if (mat[x][i] == 'R')
            return false;
    }
    return true;
}

int brute (int x, int y) {
//     printf ("%d %d\n", x, y);
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             printf ("%c%c", mat[i][j], " \n"[j==n-1]);
    if (y == n)
        ++x, y = 0;
//     printf ("%d %d\n", x, y);
    if (x == n-1 and y == n-1)
        return (mat[x][y] == '.' and check (x, y));
    int ret = 0;
    if (mat[x][y] == '.' and check (x, y)) {
        mat[x][y] = 'R';
        ret =brute (x, y+1) + 1;
        mat[x][y] = '.';
    }
    ret = max (ret, brute (x, y+1));    
    return ret;
}

bool recu (int x, int y, int val, int acu = 0) {
//      for (int i = 1; i <= 1e8; i++) 100/11;
//     printf ("%d %d %d %d\n", x, y, val, acu);
//     if (true) {
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 printf ("%c%c", mat[i][j], " \n"[j==n-1]);
//     }
    if (y == n)
        ++x, y = 0;
    if (x == n-1 and y == n-1)
        if (acu == val or (check (x, y) and acu == val-1 and mat[x][y] == '.')) {
            if (mat[x][y] == '.' and check (x, y)) mat[x][y] = 'R';
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    printf ("%c%c", mat[i][j], " \n"[j==n-1]);
                return true;
        } else
            return false;
    

    if (mat[x][y] == '.' and check (x, y)) {
        mat[x][y] = 'R';
        if (recu (x, y+1, val, acu+1)) return true;
        mat[x][y] = '.';
    }
    if (recu (x, y+1, val, acu)) return true;
    return false;
}

void func (int x, int y) {
    mat[x][y] = '.';
    for (int i = x; i < n; i++) {
        if (mat[i][y] == 'X')
            break;
        aux[i][y]++;
    }
    for (int i = x; i >= 0; i--) {
        if (mat[i][y] == 'X')
            break;
        aux[i][y]++;
    }
    for (int i = y; i < n; i++) {
        if (mat[x][i] == 'X')
            break;
        aux[x][i]++;
    }
    for (int i = y; i >= 0; i--) {
        if (mat[x][i] == 'X')
            break;
        aux[x][i]++;
    }
    mat[x][y] = 'X';
}

int solve () {
    st.clear();
    int ret = 0;
    memset (aux, 0, sizeof aux);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] == 'X')
                func (i, j);
            
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             printf ("%c%c", mat[i][j], " \n"[j==n-1]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] == '.')
                st.insert ({-aux[i][j], {i, j}});
    for (auto p : st)
        if (check (p.y.x, p.y.y)) {
//              printf ("%d %d %d\n", p.x, p.y.x, p.y.y);
            ++ret;
            mat[p.y.x][p.y.y] = 'R';
        }
    
    return ret;
}

int main () {
    while (scanf ("%d", &n) != EOF) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf (" %c", &mat[i][j]);
//         int ans = brute (0, 0);
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 printf ("%c%c", mat[i][j], " \n"[j==n-1]);
        int ans = solve ();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                printf ("%c%c", mat[i][j], " \n"[j==n-1]);
        
        printf ("ans: %d\n", ans);
//         recu (0, 0, ans);
    }

	return 0;
}
