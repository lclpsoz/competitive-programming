#include<bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
    return (int)(((x%m) + m) % m);
}



// ------------------------------------------------------------

const int N = 1e5+10;

int n;
// vector<int> divisors;
bool msk[N];
string str;
bool not_prime[N];
bool ans[N];
vector<int> primes;

// int brute_force (string &s) {
//     int ret = 0;
//     for (int k = 1; k < len (s); k++)
//         for (int i = 0; i < len (s); i++) {
//             int j = i, st = i;
//             if (str[j] == 'P') continue;
//             j = (j+k)% len (s);
//             bool test = true;
//             while (j != st) {
//                 if (str[j] == 'P') {
//                     test = false;
//                     break;
//                 }
//                 j = (j+k)%len(s);
//             }
//             if (test) {
// //                 cout << k << " in " << i << '\n';
//                 ++ret;
//                 break;
//             }
//         }
//     
//     return ret;
// }

int main () {
    cin.tie (0);
    ios::sync_with_stdio (false);
    
//     for (int i = 0; i < 100; i++)
//         cout << i << ": " << primes[i] << '\n';
    
    while (cin >> str) {
        n = len (str);
        
        bool poca = false;
        for (int i = 0; i < n; i++)
            if (str[i] == 'P') {
                poca = true;
                break;
            }
        if (!poca)
            cout << n-1 << '\n';
        else {
//             cout << "n: " << n << '\n';
//             for (int j = 0; j < len (primes) and primes[j] <= n; j++) {
            for (int j = 1; j < n; j++) {
//                 int p = primes[j];
                int p = j;
//                 cout << "P: " << p << '\n';
                if (n%p == 0) {
                    for (int i = 0; i < p; i++)
                        msk[i] = 1;
                    for (int i = 0; i < n; i++)
                        if (str[i] == 'P')
                            msk[i%p] = 0;
                    bool test = false;
                    for (int i = 0; i < p; i++) {
                        if (msk[i])
                            test = true;
                        msk[i] = 0;
                    }
//                     cout << p << ' ' << test << '\n';
                    if (test)
                        for (int k = p; k < n; k+=p)
                            ans[k] = true;
                }
            }
            int ret = 0;
            for (int i = 2; i < n; i++) {
                ret += ans[i];
                ans[i] = false;
            }
            cout << ret << '\n';
//             if (ret != brute_force (str)) {
//                 cout << str << '\n';
//                 cout << "WRONG!!! " << brute_force (str) << '\n';
//             }
        }
    }
    
    return 0;
}
