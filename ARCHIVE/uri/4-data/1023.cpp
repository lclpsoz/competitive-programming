#include <bits/stdc++.h>
using namespace std;

int i;
int city;
int qnt;
int peop, cons;
int total_peo, total_con;
vector<pair<int,int> > houses;

bool order (pair<int,int> i, pair<int,int> j){

	return (i.second < j.second);

}

int main (){

	city = 1;
	scanf("%d", &qnt);
	while (qnt){

		total_peo = total_con = 0;
		if (city > 1) printf("\n");

		for (i = 0; i < qnt; i++){

			scanf("%d %d", &peop, &cons);
			total_peo += peop;
			total_con += cons;
			houses.push_back(make_pair(peop, cons/peop));

		}

		sort(houses.begin(), houses.end(), order);

		for (i = 0; i < qnt-1; i++){

			if (houses[i].second == houses[i+1].second){

				houses[i+1].first += houses[i].first;
				houses[i].first = -1;

			}
		}

		printf("Cidade# %d:\n", city++);

		cons = 0;
		peop = 0;
		for (i = 0; i < qnt; i++){

			if (houses[i].first > 0){

				printf("%d-%d", houses[i].first, houses[i].second);
				if (i < qnt-1) printf(" ");

			}

		}
		printf("\n");
		printf("Consumo medio: %.2lf m3.\n", floor(100*(double)total_con / (double)total_peo)/100);

		houses.clear();

		scanf("%d", &qnt);
	}

	return 0;
}
