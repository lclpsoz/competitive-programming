#include <stdio.h>
using namespace std;

const int MOD = 1e9+7;
inline int mod (long long  x, int m = MOD) {
	return (int)(x%m);
}

const int N = 55, FAT = 2505;

int n, m;
int pref[N][N];
int fat[FAT], invModFat[FAT];

inline int powMod (int b, int p) {
	int r = 1;
	while (p) {
		if (p&1)
			r = mod (r*1LL*b);
		b = mod (b*1LL*b);
		p >>= 1;		
	}
	
	return r;
}

inline int invMod (int v) {
	return powMod (v, MOD-2);
}

int main () {
	fat[0] = 1;
	invModFat[0] = 1;
	for (int i = 1; i < FAT; i++) {
		fat[i] = mod (i*1LL*fat[i-1]);
		invModFat[i] = invMod (fat[i]);
	}
	
	scanf ("%d %d ", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c = getchar ();
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
			pref[i][j] += (c == '#');
		}
		getchar ();
	}
	int ax, ay, bx, by;
	while (scanf ("%d %d %d %d", &ax, &ay, &bx, &by) != EOF) {
		int qntPos = (bx-ax+1) * (by-ay+1);
		int qntElems = pref[bx][by] - pref[ax-1][by] - pref[bx][ay-1] + pref[ax-1][ay-1];
		printf ("%d\n", mod (	mod (fat[qntPos]*1LL*invModFat[qntElems]) * 1LL *
								invModFat[qntPos-qntElems]) - 1);
	}

	return 0;
}
