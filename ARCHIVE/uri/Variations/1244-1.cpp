//Implementation using 'bubble sort' logic
#include <bits/stdc++.h>
using namespace std;

const int MAXS = 100;

int qnt;
vector<pair<int, string> > vect;
char c, str[MAXS];

void bubble (int qnt){

	int i, j, k;
	pair<int, string> aux;

	for (k = 0; k < qnt; k++)
		for (i = 0; i < qnt-1;i++){

			j = i + 1;
			if (vect[i].first < vect[j].first){

				aux = make_pair(vect[i].first, vect[i].second);
				vect[i] = make_pair(vect[j].first, vect[j].second);
				vect[j] = make_pair(aux.first, aux.second);

			}

		}
}

int main (){

	int i, j;

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%s%c", str, &c);
		vect.push_back(make_pair(strlen(str), str));
		while (c != '\n'){

			scanf("%s%c", str, &c);
			vect.push_back(make_pair(strlen(str), str));

		}

		//sort(vect.begin(), vect.end(), order_size);
		bubble (vect.size());

		for (j = 0; j < vect.size(); j++){

			//printf("%d ", vect[j].first);
			cout << vect[j].second;
			if (j < vect.size()-1) printf(" ");

		}
		printf("\n");
		vect.clear();

	}

	return 0;
}
