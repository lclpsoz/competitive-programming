#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6+10;

char c;
int n;
bool ans;
stack<char> pi;

int main ()
{
	scanf ("%d", &n);
	getchar ();
	for (int i = 0; i < n; i++) {
		ans = true;
		c = getchar ();
		while (c != '\n' && c != EOF) {
		//	putchar (c);
			switch (c) {
				case ')':
					if (!pi.empty() && pi.top() == '(')
						pi.pop ();
					else
						ans = false;
					break;
				case ']':
					if (!pi.empty() && pi.top() == '[')
						pi.pop ();
					else
						ans = false;
					break;
				case '}':
					if (!pi.empty() && pi.top() == '{')
						pi.pop ();
					else
						ans = false;
					break;
				default:
					pi.push (c);
			}
			c = getchar ();
		}
		if (!pi.empty ())
			ans = false;
		if (!pi.empty ())
			pi.pop ();

		ans ? printf ("S\n") : printf ("N\n");
	}

	return 0;
}
