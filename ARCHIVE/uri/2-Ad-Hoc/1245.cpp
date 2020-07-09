#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int i;
int qnt, shoe, pairs;
pair<int, int> arr[MAXN]; //Amount of each pair
char feet;

int main (){

	while (scanf("%d", &qnt) != EOF){

		pairs = 0;
		for (i = 0; i < qnt; i++){

			scanf("%d %c", &shoe, &feet);

			if (feet == 'E'){

				if (arr[shoe].second){

					pairs++;
					arr[shoe].second--;

				}
				else arr[shoe].first++;

			}
			else{

				if (arr[shoe].first){

					pairs++;
					arr[shoe].first--;

				}
				else arr[shoe].second++;

			}
		}

		printf("%d\n", pairs);

		for (i = 30; i < 61; i++){

			arr[i].first = 0;
			arr[i].second = 0;

		}
	}

	return 0;
}
