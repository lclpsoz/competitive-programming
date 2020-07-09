#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+100;

int i;
int qnt, val, ans, third, l, r, l_2, r_2;
int sums[MAXN]; //Last position will be qnt, because it start at position 1

int main (){

	while (scanf("%d", &qnt) != EOF){

		for (i = 0; i < qnt; i++){

			scanf("%d", &val);
			sums[i+1] += sums[i] + val;

		}

		ans = 0;
		if (sums[qnt] % 3) printf("0\n");
		else{

			r = 1;
			l = 0;
			third = sums[qnt] / 3;
			while (sums[qnt] - sums[r] > third){
				//cout << l << ' ' << r << '\n';
				while ((sums[r] - sums[l]) != third && sums[qnt] - sums[r] > third){

					if (sums[r] - sums[l] < third) r++;
					else l++;

				}
				if (sums[r] - sums[l] != third) break;

				r_2 = r + 1;

				while ((sums[r_2] - sums[l]) != third && r_2 < qnt){

					if (sums[r_2] - sums[l] < third) r_2++;
					else l++;

				}
				if (sums[r_2] - sums[l] == third) ans++;
				r++;

			}
			printf("%d\n", ans);

		}

		memset(sums, 0, sizeof(int)*qnt);

	}

	return 0;
}
