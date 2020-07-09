#include <bits/stdc++.h>
using namespace std;

int i, j;
char arr[75], num[75];

int main ()
{
	while (scanf ("%[^\n]", arr) != EOF) {
		getchar (); // \n
		bool noZero = false;
		bool zero = false;
		if (arr[0] == '\0')
			printf ("error\n");
		else {
			for (i = 0, j = 0; arr[i] != '\0'; i++) {
				if (arr[i] > '0' && arr[i] <= '9') {
					num[j++] = arr[i];
					noZero = true;
				}
				else if (arr[i] == '0' || arr[i] == 'o' || arr[i] == 'O') {
					zero = true;
					if (noZero)
						num[j++] = '0';
				}
				else if (arr[i] == 'l') {
					num[j++] = '1';
					noZero = true;
				}
				else {
					if (arr[i] != ',' && arr[i] != ' ') {
						num[0] = '-';
						num[1] = '\0';
						j = 2;
					}
				}
			}
			if (j == 0 && zero)
				num[j++] = '0';
			num[j] = '\0';
			// printf ("%s\n", num);
			int k = 0;
			long long aux;
			if (num[0] == '\0' || num[0] == '-')
				printf ("error\n");
			else if (strlen (num) < 10) {
				sscanf (num, "%lld", &aux);
				printf ("%lld\n", aux);
			}
			else if (strlen (num) == 10) {
				sscanf (num, "%lld", &aux);
				if (aux > 2147483647)
					printf ("error\n");
				else
					printf ("%lld\n", aux);
			}
			else
				printf ("error\n");
			arr[0] = '\0';
		}
	}

	return 0;
}
