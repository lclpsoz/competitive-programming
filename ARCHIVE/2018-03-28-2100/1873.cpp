#include <bits/stdc++.h>
using namespace std;

int n;
int i;
char arr1[30], arr2[30];
bool ans;

int main ()
{
	scanf ("%d", &n);
	for (i = 0; i < n; i++) {
		scanf ("%s %s", arr1, arr2);
		ans = false; //sheldon wins
		switch (arr1[2]) {
			case 'd': if (arr2[2] == 'g' || arr2[2] == 's')
						  ans = true;
					  break;
			case 'p': if (arr2[2] == 'd' || arr2[2] == 'o')
						  ans = true;
					  break;
			case 's': if (arr2[2] == 'p' || arr2[2] == 'g')
						  ans = true;
					  break;
			case 'g': if (arr2[2] == 'o' || arr2[2] == 'p')
						  ans = true;
					  break;
			case 'o': if (arr2[2] == 's' || arr2[2] == 'd')
						  ans = true;
					  break;
		}
		if (strcmp(arr1, arr2))
			ans ? printf ("rajesh\n") : printf ("sheldon\n");
		else
			printf ("empate\n");
	}
	return 0;
}
