#include <bits/stdc++.h>
using namespace std;

int i;
int n, stu, x, cont;
vector <int> arr[105];

int main ()
{
	while (scanf ("%d", &n), n) {
		int bigger = 0;
		printf ("Turma %d\n", ++cont);
		for (i = 0; i < n; i++) {
			scanf ("%d %d", &stu, &x);
			bigger = max (bigger, x);
			arr[x].insert (arr[x].end(), stu);
		}
		for (i = 0; i < arr[bigger].size (); i++)
			printf ("%d ", arr[bigger][i]);
		printf ("\n");
		printf ("\n");
		for (i = 0; i <= 100; i++) {
			arr[i].clear();
		}
	}
	return 0;
}
