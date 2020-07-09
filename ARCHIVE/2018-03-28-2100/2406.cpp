#include <bits/stdc++.h>
using namespace std;

int n;
stack<char> pi;
char c;
bool ans;

int main ()
{
	scanf ("%d", &n);
	getchar ();
	for (int i = 0; i < n; i++) {
		ans = true;
		c = getchar ();
		while (c != '\n' && c != EOF) {
			switch (c) {
				case ')':
					if (!pi.empty () && pi.top() == '(')
						pi.pop();
					else
						ans = false;
					break;
				case ']':
					if (!pi.empty () && pi.top() == '[')
						pi.pop ();
					else
						ans = false;
					break;
				case '}':
					if (!pi.empty () && pi.top() == '{')
						pi.pop ();
					else
						ans = false;
					break;
				default: pi.push (c);
			}

			c = getchar ();
		}
		if (!pi.empty ())
			ans = false;
		while (!pi.empty ())
			pi.pop ();
		ans ? printf ("S\n") : printf ("N\n");
	}

	return 0;
}
