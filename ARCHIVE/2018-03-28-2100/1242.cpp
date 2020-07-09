#include <bits/stdc++.h>
using namespace std;

int i, j;
int ans;
int arr[10]; //B, C, F, S  (F-C and B-S)
char str[310];

int main ()
{
	while (scanf (" %[^\n]", str) != EOF) {
		for (i = 0; i < 4; i++)
			arr[i] = 0;
		ans = 0;
		for (i = 0; str[i] != '\0'; i++) {
			switch (str[i]) {
				case 'B': if (arr[3]) {
							  arr[3]--;
							  ans++;
						  }
						  else
							  arr[0]++;
						  break;
				case 'C': if (arr[2]) {
							  arr[2]--;
							  ans++;
						  }
						  else
							  arr[1]++;
						  break;
				case 'F': if (arr[1]) {
							  arr[1]--;
							  ans++;
						  }
						  else
							  arr[2]++;
						  break;
				case 'S': if (arr[0]) {
							  arr[0]--;
							  ans++;
						  }
						  else
							  arr[3]++;
						  break;
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}
