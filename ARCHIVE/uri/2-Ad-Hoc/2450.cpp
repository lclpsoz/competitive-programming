#include <bits/stdc++.h>
using namespace std;

int i, j;
int n, m, val, bef, now;
bool test;

int main (){

	scanf("%d %d", &n, &m);
	test = true;
	bef = 0;
	for (i = 0; i < n; i++){

		for (j = 0; j < m; j++){

			scanf("%d", &val);
			if (val && !now)
				now = j+1;

		}
		if (now == 0) now = m+1;
		//printf("%d\n", now);

		if (now < bef || (now < m+1 && now == bef))
			test = false;

		bef = now;
		now = 0;

	}

	if (test) printf("S\n");
	else printf("N\n");

	return 0;
}
