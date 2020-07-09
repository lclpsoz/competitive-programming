#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
#define len(x) (int)x.size()
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 1e5+10;

char str[MAXN];
deque<char> arr;

int main ()
{
	scanf ("%s", str);
	for (int i = 0; str[i] != '\0'; i++)
		arr.pb (str[i]);
	int p;
	int aux = -1; // Primeiro zero ou dois
	char c = '1';
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == '1' && c != '1') {
			arr.erase (arr.begin()+i);
			arr.emplace (arr.begin()+p, '1');
			++p;
		} else if (c == '1' && arr[i] != '1') {
			c = arr[i];
			p = i;
		}	else if (c == '1') {
			c = '1';
			p = -1;
		}
	}
	/*for (char z : arr)
		putchar (z);
	putchar ('\n');*/
	p = -1;
	c = '-';
	for (int i = 0; i < arr.size(); i++) {
		if ((arr[i] == '0' && c == '1') || (c == '2' && arr[i] == '1')) {
			swap (arr[i], arr[p]);
			++p;
		} else if (c != arr[i] && arr[i] != '0') {
			c = arr[i];
			p = i;
		} else if (arr[i] == '0') {
			c = '-';
			p = -1;
		}
	}
	for (char z : arr)
		putchar (z);
	putchar ('\n');

  return 0;
}
