#include <bits/stdc++.h>
using namespace std;

char str[200];
int n;
stack<char> pi;

int main ()
{
	scanf ("%d ", &n);
	for (int i = 0; i < n; i++) {
		int ans = 1;
		str[0] = '\0';
		scanf ("%[^\n]", str);
		getchar ();
		for (int j = 0; ans && str[j] != '\0'; j++) {
			switch (str[j]) {
				case '(':
				case '[': pi.push (str[j]);
						  break;
				case ')': if (pi.empty() || pi.top() != '(')
							  ans = 0;
						  if (!pi.empty())
							  pi.pop ();
						  break;
				case ']': if (pi.empty() || pi.top() != '[')
							  ans = 0;
						  if (!pi.empty())
							  pi.pop ();
						  break;
			}
		}
		if (!pi.empty())
			ans = 0;
		while (!pi.empty())
			pi.pop ();
		ans ? printf ("Yes\n") : printf ("No\n");
	}
	return 0;
}
