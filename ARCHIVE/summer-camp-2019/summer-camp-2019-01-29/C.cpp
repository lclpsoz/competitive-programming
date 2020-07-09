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

const int N = sqrt (1e13+1000);

ll q;
// map<ll, bool> mp;
bool not_prime[N];
vector<int> primes;

// vector<ll> divs (ll x) {
//     vector<ll> now;
//     for (int i = 2; i < x/2; i++)
//         if (x%2
// }

void sieve () {
    int i = 2;
    for (; i*i < N; i++)
        if (!not_prime[i]) {
            primes.push_back (i);
            for (int j = i*i; j < N; j+=i)
                not_prime[j] = true;
        }
    while (i < N) {
        if (!not_prime[i])
            primes.push_back (i);
        i++;
    }
}

int main () {
//     cin.tie (0);
//     ios::sync_with_stdio (false);
    sieve ();
    cin >> q;
    bool two = false;
//     cout << "here\n";
    int qnt = 0;
    ll ans = 1;
    ll qq = q;
    for (int p : primes) {
        if (p*p > q) break;
//         cout << p << '\n';
        while (q%p == 0) {
            two = true;
            ++qnt;
            ans *= p;
            q /= p;
            if (qnt == 2)
                break;
        }
        if (qnt == 2 and ans != qq) {
            cout << '1' << '\n';
            cout << ans << '\n';
            exit (0);
        }
    }
    if (two)
        cout << 2 << '\n';
    else
        cout << 1 << '\n' << 0 << '\n';

	return 0;
}
