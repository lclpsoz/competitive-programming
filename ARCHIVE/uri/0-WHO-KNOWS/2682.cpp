#include <bits/stdc++.h>
using namespace std;

int bef, now, val;

int main(){

	bef = -1;
	while (scanf("%d", &now) != EOF){

		if (bef > now && !val)
			val = bef + 1;

		bef = now;

	}

	if (!val)
		val = bef + 1;

	printf("%d\n", val);

	return 0;
}
