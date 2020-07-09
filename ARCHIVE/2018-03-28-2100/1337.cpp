#include <bits/stdc++.h>
using namespace std;

int i;
int arr[3], aux;

int main ()
{
	for (i = 0; i < 3; i++)
		scanf ("%d", &arr[i]);
	while (arr[0]) {
		sort (arr, arr+3);
		if (arr[0] != arr[1] && arr[1] != arr[2])
			printf ("1 1 2\n");
		else if (arr[0] == 13 && arr[1] == 13 && arr[2])
			printf ("*\n");
		else if (arr[0] == arr[1] && arr[0] == 13 && arr[2] == 12)
			printf ("1 1 1\n");
		else if (arr[1] == arr[2] && arr[0] == 12 && arr[2] == 13)
			printf ("1 1 1\n");
		else if (arr[0] == arr[1] && arr[1] == arr[2])
			printf ("%d %d %d\n", arr[0]+1, arr[1]+1, arr[2]+1);
		else {
			if (arr[0] == arr[1])
				swap (arr[0], arr[2]);

			arr[0]++;
			if (arr[0] > 13) {
				arr[0] = 1;
				arr[1]++;
				arr[2]++;
			}
			else if (arr[0] == arr[1])
				arr[0]++;
			sort (arr, arr+3);
			printf ("%d %d %d\n", arr[0], arr[1], arr[2]);
		}


		for (i = 0; i < 3; i++)
			scanf ("%d", &arr[i]);
	}
	return 0;
}
