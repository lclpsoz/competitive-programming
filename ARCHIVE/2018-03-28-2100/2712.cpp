#include <bits/stdc++.h>
using namespace std;

int n;
int i, j, lst;
char str[130];
bool test;

int main ()
{
	scanf ("%d", &n);
	for (i = 0; i < n; i++) {
		getchar ();
		scanf ("%[^\n]", str);
		test = true;
		if (strlen (str) != 8 || str[3] != '-')
			printf ("FAILURE\n");
		else {
			for (j = 0; j < 3 && test; j++)
				if (str[j] < 'A' || str[j] > 'Z')
					test = false;
			for (j = 4; test && j < 8; j++)
				if (str[j] < '0' || str[j] > '9')
					test = false;
			if (!test)
				printf ("FAILURE\n");
			else {
				lst = str[7] - '0' - 1;
				if (lst == 8 || lst == -1)
					printf ("FRIDAY\n");
				else {
					lst /= 2;
					switch (lst) {
						case 0: printf ("MONDAY\n");
								break;
						case 1: printf ("TUESDAY\n");
								break;
						case 2: printf ("WEDNESDAY\n");
								break;
						case 3: printf ("THURSDAY\n");
								break;
					}
				}

			}
		}
	}
	return 0;
}
