#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e6+10;

set<string> dij;
char str[MAXS];

int main (){

	while(scanf("%s", str) != EOF){

		dij.insert(str);

	}

	printf("%lu\n", dij.size());

	return 0;
}
