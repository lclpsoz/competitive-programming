#include <bits/stdc++.h>
using namespace std;

int i;
int n, stu, x, cont;

bool ord (const pair<int, int> &a, const pair<int, int> &b) {
	return (a.second > b.second);
}

priority_queue <pair<int,int>, vector < <pair<int, int> >, ord> scr;


int main ()
{
	while (scanf ("%d", &n), n) {
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
