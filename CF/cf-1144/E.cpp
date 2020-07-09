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

const int N = 2e5 + 100;

int k;
char a[N], b[N], c[N];

int main () {
    scanf ("%d", &k);
    scanf ("%s %s", a, b);
    for (int i = 0; i < k; i++)
        a[i] -= 'a', b[i] -= 'a';
//     for (int i = k-1; i >= 0; i--) {
//         for (int j = 0; j < k; j++)
//             printf ("%d ", b[j]);
//         putchar ('\n');
//         putchar ('\n');
//         if (b[i] < a[i]) {
//             b[i-1]--;
//             b[i] += 26;
//         }
//         b[i] = (a[i]+b[i])/2;
//         if (b[i] > 25) {
//             b[i] -= 26;
//             c[i-1]++;
//         }
//     }
//     for (int i = 0; i < k; i++)
//         putchar (b[i]+'a'+c[i]);
//     putchar ('\n');
//     for (int i = 0; i < k; i++)
//         printf ("%d ", a[i]);
//     putchar ('\n');
//     for (int i = 0; i < k; i++)
//         printf ("%d ", b[i]);
//     putchar ('\n');
    for (int i = k-1; i >= 0; i--)
        if (a[i] > b[i]) {
            b[i-1]--;
            b[i]+=26;
        }
//     putchar ('\n');
//     for (int i = 0; i < k; i++)
//         printf ("%d ", a[i]);
//     putchar ('\n');
//     for (int i = 0; i < k; i++)
//         printf ("%d ", b[i]);
//     putchar ('\n');
    for (int i = 0; i < k; i++) {
        if ((a[i]+b[i])%2 == 1)
            c[i+1]+=13;
        c[i] += (a[i]+b[i])/2;
        if (c[i] > 25) {
            c[i-1] += c[i]/26;
            c[i] %= 26;
        }
//         for (int j = 0; j < k; j++)
//             printf ("%d ", c[j]);
//         putchar ('\n');
//         putchar ('\n');
    }
    for (int i = k-1; i >= 0; i--)
        if (c[i] > 25) {
            c[i-1] += c[i]/26;
            c[i] %= 26;
        }
    for (int i = 0; i < k; i++)
        putchar (c[i]+'a');
    putchar ('\n');
    
    
	return 0;
}
