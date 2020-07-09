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

const int N = 2.5e5 + 10;
const int N2 = 5e5 + 10;

int n;
char arr[N2], str2[N];
int sep;

struct suffixArray {
	int RA[N2], tempRA[N2];
	int SA[N2], tempSA[N2];
	int c[N2];
	int Phi[N2], LCP[N2], PLCP[N2];
	
	void countingSort (int k) {
		int i, sum, maxi = max (300, n);
		memset (c, 0, sizeof c);
		for (i = 0; i < n; i++)
			c[i + k < n ? RA[i + k] : 0]++;
		for (i = sum = 0; i < maxi; i++) {
			int t = c[i]; c[i] = sum; sum += t;
		}
		for (i = 0; i < n; i++)
			tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
		for (i = 0; i < n; i++)
			SA[i] = tempSA[i];
	}
	
	void constructSA() {
		int i, k, r;
		for (i = 0; i < n; i++) RA[i] = arr[i];
		for (i = 0; i < n; i++) SA[i]  = i;
		for (k = 1; k < n; k <<= 1) {
			countingSort (k);
			countingSort (0);
			tempRA[SA[0]] = r = 0;
			for (i = 1; i < n; i++)
				tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] and RA[SA[i]+k] == RA[SA[i-1] + k]) ? r : ++r;
			for (i = 0; i < n; i++)
				RA[i] = tempRA[i];
			if (RA[SA[n-1]] == n-1) break;
		}
	}

	void computeLCP () {
		int i, L;
		Phi[SA[0]] = -1;
		for (int i = 1; i < n; i++)
			Phi[SA[i]] = SA[i-1];
		for (i = L = 0; i < n; i++) {
			if (Phi[i] == -1) { PLCP[i] = 0; continue; }
			while (arr[i + L] == arr[Phi[i] + L]) L++;
			PLCP[i] = L;
			L = max (L-1, 0);
		}
		for (int i = 0; i < n; i++)
			LCP[i] = PLCP[SA[i]];	
	}
};

void solve (suffixArray &sa) {
	int *SA = sa.SA;
	int *LCP = sa.LCP;
	int maxi = 0;
	int pos = -1;
	for (int i = 1; i < n; i++) {
		int posNow = SA[i-1];
		int posFut = SA[i];
		if (posFut < posNow) swap (posFut, posNow);
//  		printf ("%d %d %d | %d %c\n", posNow, sep, posFut, LCP[i], arr[i+LCP[i]-1]);
// 		if (arr[i+LCP[i]-1] == '$') LCP[i]--;
//  		printf ("%d %d %d | %d %c\n", posNow, sep, posFut, LCP[i], arr[i+LCP[i]-1]);
		if (posNow < sep and posFut > sep and 
			(LCP[i] > maxi or (LCP[i] == maxi and posFut < pos))) {
			maxi = LCP[i];
			pos = posFut;
		}
	}
	if (maxi > 0) {
		for (int i = pos; i < pos+maxi; i++) {
			putchar (arr[i]);
		}
		putchar ('\n');
	}
	printf ("%d\n", maxi);
}

int main () {
	scanf ("%s %s", arr, str2);
	bool frst = true;
	for (int i = 0, j = 0; str2[j] != '\0'; i++) {
		if (arr[i] != '\0') continue;
		if (frst) {
			frst = false;
			arr[i] = '-';
			sep = i;
			continue;
		}
		arr[i] = str2[j++];
		n = i;
	}
	++n;
 	arr[n++] = '$';
	suffixArray sa;
// 	printf ("%s\n", arr);
	sa.constructSA ();
	sa.computeLCP ();
// 	printf ("%s\n", arr);
// 	for (int i = 0; i < n; i++)
// 		printf ("%d: %d %d\n", i, sa.SA[i], sa.LCP[i]);
//  	printf ("%s\n",s arr);
	
	solve (sa);

	return 0;
}
