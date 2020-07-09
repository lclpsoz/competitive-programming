#include <bits/stdc++.h>
using namespace std;

char arr[11][40];

int main ()
{
	for (int i = 0; i < 10; i++)
		scanf (" %s ", arr[i]);

	printf ("%s\n%s\n%s\n", arr[2], arr[6], arr[8]);

	return 0;
}
