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

char mat[10][100] = { 	"GQaku",
						"ISblv",
						"EOYcmw",
						"FPZdnx",
						"JTeoy",
						"DNXfpz",
						"AKUgq",
						"CMWhr",
						"BLVis",
						"HRjt"		};

map<char, int> mp;

int main ()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; mat[i][j] != '\0'; j++) {
			mp[mat[i][j]] = i;
		}
	int n;
	scanf ("%d ", &n);
	char arr[1000];
	while (n--)  {
		scanf ("%[^\n]", arr);
		getchar ();
		for (int i = 0, j = 0; i < 12 && arr[j] != '\0'; i++, j++) {
			if (arr[j] != ' ')
				printf ("%d", mp[arr[j]]);
			else
				i--;
		}
		putchar ('\n');
	}


	return 0;
}
