#include <bits/stdc++.h>
using namespace std;

int const MAXS = 1e5+10;

int i, j;
int qnt;
int size, sum, sum_per, l, r, seq_l, seq_r;
int arr[MAXS];
char str[MAXS];

int main (){

	scanf("%d", &qnt);
	scanf("%s", str);
	for (i = 0; i < qnt; i++){

		if (str[i]-'0') sum++;
		else sum--;

	}
	l = 0;
	r = qnt-1;
	sum_per = sum;
	//printf("SUM: %d\n", sum);
	//printf("\n");

	//Taking from left
	while (sum && l <= r){

		if (sum > 0){

			if (str[r]-'0'){

				r--;
				sum--;

			}
			else{

				if (str[l]-'0') sum--;
				else sum++;
				l++;

			}
		}
		else{

			if (!str[r]-'0'){

				r--;
				sum++;

			}
			else{

				if (str[l]-'0') sum--;
				else sum++;
				l++;

			}
		}

		//printf("%d %d %d\n", l, r, sum);
	}

	//printf("%d %d\n", l, r);
	seq_l = r - l + 1;
	//printf("%d\n", seq_l);

	//Taking from right
	l = 0;
	r = qnt-1;
	sum = sum_per;
	while (sum && l <= r){

		if (sum > 0){

			if (str[l]-'0'){

				l++;
				sum--;

			}
			else{

				if (str[r]-'0') sum--;
				else sum++;
				r--;

			}
		}
		else{

			if (!str[l]-'0'){

				l++;
				sum++;

			}
			else{

				if (str[r]-'0') sum--;
				else sum++;
				r--;

			}
		}

		//printf("%d %d %d\n", l, r, sum);
	}
	//printf("%d %d\n", l, r);
	seq_r = r - l + 1;
	//printf("%d\n", seq_r);

	if (seq_r > seq_l) printf("%d\n", seq_r);
	else printf("%d\n", seq_l);

	return 0;
}
