#include <bits/stdc++.h>
using namespace std;

int ans, qnt;
char str[200];

int main ()
{
	scanf ("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '1' && str[i+1] == '0') {
			i++;
			ans += 10;
		}
		else
			ans += str[i]-'0';
		qnt++;
	}
	printf ("%.2lf\n", (double)ans/qnt);
	return 0;
}
