#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////


int main ()
{
	int n, a, b;
	scanf ("%d %d %d", &n, &a, &b);

	if (n == 1) {
		printf ("YES\n");
		printf ("0\n");
	} else if (n == 2) {
		if (a == b)
			printf ("NO\n");
		else if (a == 1) {
			printf ("YES\n");
			printf ("01\n");
			printf ("10\n");
		}
		else {
			printf ("YES\n");
			printf ("00\n");
			printf ("00\n");
		}
	} else {
		if (a != 1 && b != 1)
			printf ("NO\n");
		else if (a == b) {
			if (n == 3)
				printf ("NO\n");
			else {
				printf ("YES\n");
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (i == j)
							putchar ('0');
						else if (i == j+1 || j == i+1)
							putchar ('1');
						else
							putchar ('0');
					}
					putchar ('\n');
				}
			}
		}
		else {
			printf ("YES\n");
			if (a == 1) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (i == j)
							putchar ('0');
						else if (i < b-1 || j < b-1)
							putchar ('1');
						else
							putchar ('0');
					}
					putchar ('\n');
				}
			} else {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (i == j)
							putchar ('0');
						else if (i >= a-1 && j >= a-1)
							putchar ('1');
						else
							putchar ('0');
					}
					putchar ('\n');
				}
			}
		}
	}

	return 0;
}
