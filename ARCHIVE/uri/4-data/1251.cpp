#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e3+10, MAXN = 150;

int i;
int size;
char str[MAXS], c;
vector< pair<char, int> > tabl(MAXN);

bool ord (const pair<char, int> &a, const pair<char, int> &b){

	return (a.second < b.second || (a.second == b.second && a.first > b.first));

}

int main (){

	bool test = false;

	while (scanf("%s", str) != EOF){

		if (test) printf("\n");

		for (i = 30; i < 129; i++)
			tabl[i].first = i;

		size = strlen(str);
		for (i = 0; i < size; i++){

			tabl[str[i]].second++;


		}
		//printf("%s\n", str);

		/*for (i = 32; i < 128; i++)
			printf("%d %d %d\n", i, tabl[i].first, tabl[i].second);
		printf("\n");*/

		sort(tabl.begin()+32, tabl.begin()+128, ord);

		/*for (i = 32; i < 128; i++)
			printf("%d %d %d\n", i, tabl[i].first, tabl[i].second);
		printf("\n");*/

		for (i = 0; i < 129; i++)
			if (tabl[i].second){

				printf("%d %d\n", tabl[i].first, tabl[i].second);
				tabl[i].second = 0;

			}

		test = true;

	}

	return 0;
}
