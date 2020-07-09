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

const int MOD = 1e9+7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5+100;

int lenBase, lenText;
char base[110], text[N];
int acu[N];

inline bool eval (int l, int r) {
    for (int i = 0; i < lenBase; i++) {
        if (base[i] > text[i+l])
            return true;
        else if (base[i] < text[i+l])
            return false;
    }
    
    return true;
}

int main () {
    text[0] = '#';
    scanf ("%s %s", base, text+1);
    lenBase = strlen (base);
    lenText = strlen (text);
    
    acu[0] = 1;
    int l = 1;
    for (int i = 1; i < lenText; i++) {
        if (i-l+1 > lenBase) ++l;
        for (int j = l; j <= i; j++)
            if (text[j] != '0' and (i-j+1 < lenBase or eval (j, i)))
                acu[i] = mod (acu[i]+acu[j-1]);
    }
    
    
    printf ("%d\n", mod(acu[lenText-1]));
    
	return 0;
}
