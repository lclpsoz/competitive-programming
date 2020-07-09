#include <bits/stdc++.h>
using namespace std;

int i;
int atc, def, atc_fst, def_fst, def_sec, val;

int main (){

	scanf("%d %d", &atc, &def);
	while (atc || def){

		atc_fst = 99999;
		for (i = 0; i < atc; i++){

			scanf("%d", &val);
			atc_fst = min(val, atc_fst);
		}

		def_fst = def_sec = 99999;
		for (i = 0; i < def; i++){

			scanf("%d", &val);

			if (val < def_fst){

				def_sec = def_fst;
				def_fst = val;

			}
			else if (val < def_sec) def_sec = val;

		}

		if (atc_fst < def_sec) printf("Y\n");
		else printf("N\n");

		scanf("%d %d", &atc, &def);
	}

	return 0;
}
