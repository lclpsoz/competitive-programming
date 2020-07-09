#include <cstdio>
using namespace std;

const int MAXN = 1e3+10;

int n;
bool verif[MAXN];

int main ()
{
	scanf ("%d", &n);
	getchar (); getchar (); getchar ();
	for (int i = 2; i <= n; i++) {
		if (getchar () == '0')
			verif[i] = true;
		getchar (); // ' ' or '\n'
	}
	bool ans = true;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// When they CAN'T connect
			if (getchar () == '0' && j > i) {
				if (verif[i] && verif[j])
					ans = false;
			}
			getchar (); // ' ' or '\n'
		}
	}

	ans ? printf ("Bazinga!\n") : printf ("Fail!\n");

	return 0;
}
