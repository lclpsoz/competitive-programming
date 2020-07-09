#include <bits/stdc++.h>
using namespace std;

char arr[100], vow[100];;

int main ()
{
	scanf ("%s", arr);
	int j = 0;
	for (int i = 0; arr[i] != '\0'; i++) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			vow[j++] = arr[i];
	}
	vow[j] = '\0';
	int size = strlen (vow);
	bool ans = true;
	j = size-1;
	for (int i = 0; j >= 0 && vow[i] != '\0'; j--, i++) {
		//printf ("%d %d\n", i, j);
		if (vow[i] != vow[j])
			ans = false;
	}
	ans ? printf ("S\n") : printf ("N\n");

	return 0;
}
