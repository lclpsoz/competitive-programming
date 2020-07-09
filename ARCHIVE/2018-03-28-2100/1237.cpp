#include <bits/stdc++.h>
using namespace std;

int k, l;
char arr1[55];
char arr2[55];
char arr3[55];

int main ()
{
	while (scanf ("%[^\n]", arr1) != EOF) {
		getchar ();
		scanf ("%[^\n]", arr2);
		getchar ();

		int ans = 0;
		for (int i = 0; arr1[i] != '\0'; i++) {
			l = 0; k = i;
			arr3[l++] = arr1[k++];
			arr3[l] = '\0';
			// printf ("\t%s\n", arr3);
			while (strstr (arr2, arr3) != NULL && arr1[k-1] != '\0') {
				ans = max (ans, (int) strlen (arr3));
				arr3[l++] = arr1[k++];
				arr3[l] = '\0';
				// printf ("\t%s\t%d\n", arr3, ans);
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}
