#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7+10;

int i, j, k, l, m;
int qnt_regions, choosen, last, arr[MAXN];

int main (){

	scanf("%d", &qnt_regions);

	while (qnt_regions){

		last = 0;
		for (choosen = 1; last != 13; choosen++){

			for (i = 0; i < qnt_regions; i++)
				arr[i] = i+1;

			i = j = 0;
			arr[i] = 0; //Region 1 is the first
			i++;

			while (j < qnt_regions - 2){


				l = 0;
				while (!arr[i] || l < choosen - 1){

					if (arr[i]) l++;
					i++;
					i == qnt_regions ? i = 0:0;

				}

				arr[i] = 0;
				j++;

			}

			for (k = 0; k < qnt_regions && !arr[k]; k++);
			last = arr[k];

		}
		printf("%d\n", choosen-1);

		//qnt_regions++;
		//if (qnt_regions == 101) qnt_regions = 0;
		scanf("%d", &qnt_regions);

	}

	return 0;
}
