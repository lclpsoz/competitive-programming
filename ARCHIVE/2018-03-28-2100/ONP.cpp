#include <bits/stdc++.h>
using namespace std;

char *pol (char *str)
{
	char *ans = (char*) malloc (sizeof (char) * 1e3);;
	stack <char> opr;
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		switch (str[i]) {
			case ')': while (!opr.empty () && opr.top () != '(') {
						  ans[j++] = opr.top ();
						  opr.pop ();
					  }
					  opr.pop (); // '('
					  break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^': if (!opr.empty () && opr.top () != '(') {
						  ans[j++] = opr.top ();
						  opr.pop ();
					  }
			default: opr.push (str[i]);
		}
	}
	return ans;
}

int main ()
{
	int n;
	char str[1000];
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%s", str);
		printf ("%s\n", pol (str));
	}

	return 0;
}
