#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

char arr[150];
int a, b;

int main ()
{
	a = b = 0;
	scanf ("%s", arr);
	for (int i = 0; arr[i] != '\0'; i++)
		arr[i] == '-' ? a++ : b++;

	if (a == 0 || b == 0)
		printf ("YES\n");
	else if (a%b == 0)
		printf ("YES\n");
	else
		printf ("NO\n");

	return 0;
}
