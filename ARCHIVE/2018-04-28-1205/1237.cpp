#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;

char arr1[MAXN], arr2[MAXN];
int aux, ans;

int main ()
{
	while (scanf ("%[^\n]", arr1) != EOF) {
		getchar();
		scanf ("%[^\n]", arr2);
		getchar();
		for (int i = 0; arr1[i] != '\0'; i++)
			for (int j = 0; arr2[j] != '\0'; j++) {
				if (arr1[i] == arr2[j]) {
					aux = 0;
					for (int k = i, l = j; arr1[k] != '\0' && arr2[l] != '\0' && arr1[k] == arr2[l]; k++, l++, aux++);
					ans = max (ans, aux);
				}
			}
		printf ("%d\n", ans);
		ans = 0;
	}

	return 0;
}
