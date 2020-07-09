//Breaking the number into it powers of 10 and using a matriz to know the amount of numbers until that one. The matriz is filled using previous calculated values
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

const int MAXN = 20, MAXM = 10;

int i, j;
llu mat[MAXN][MAXM];//Save amount of numbers that have 4 or 13 in it in logic of power of 10^x (0 <= x <= 19) to lines and the multiplier of that has columns, that range [0,9], with the exception of the last line, that one goes until 2 * 10^19, as a result of type limination

llu pow_10 (int a){

	int k;
	llu ans = 1;
	for (k = 0; k < a; k++)
		ans *= 10;

	return ans;

}

void fill_mat (){

	for (i = 0; i < MAXM; i++)
		if (i >= 4) mat[0][i] = 1;
		else mat[0][i] = 0;

	for (i = 1; i < MAXN; i++){

		mat[i][1] = mat[i-1][9] + mat[i-1][1];

		mat[i][2] = 2 * mat[i][1];
		//Because it will 'pass' throut the 13...

		//Minus amount that was 3X before, because every possible number, including thoses, that starts with 13 will be counted. Minus all possible numbers in that amount of digits. If in 2000, that will 13XX, or the number of number with 4 or 13 with 2 digits, or before 100. If 20, will be 13, amount of digits is 0, so 10^0 = 1, plus 1, minus amount of numbers before 10^0 = 0, so in 1, that is 0, so the result is +1.
		mat[i][2] -= mat[i-1][1];
		mat[i][2] += pow_10(i-1);

		for (j = 3; j < MAXM; j++){

			if (j == 4)
				mat[i][j] = mat[i][3] + mat[i][1] + 1;
			else if (j == 5)
				mat[i][j] = mat[i][4] + pow_10(i) - 1;
			else
				mat[i][j] = mat[i][j-1] + mat[i][1];

		}
	}
}

llu amnt_n (char *n){

	int bef, now;
	llu ans = 0;
	int size = strlen(n);

	bef = -1;
	for (i = 0; i < size; i++){

		now = n[i] - '0';
		ans += mat[size - 1 - i][now];

		if (bef == 1 && now > 3){

			ans += pow_10(size-1-i) + 1; //+1 to count the 13XXX itself
			ans -= (mat[size-1-i][4] - (mat[size-1-i][3])); //Only remove the value that would be duplicated, the value of 3XXX, that is the acumulated until 4XXX - what acumulated until 3XXX

		}
		if (now == 4 && i < size-1){

			for (j = i+1; j < size; j++)
				ans += (n[j] - '0') * pow_10(size-1-j);

			break;

		}
		if (bef == 1 && now == 3){

			ans++;//+1 to count the 13XXX itself, in the case of 4XXX it was already in 'count' in mat
			for (j = i+1; j < size; j++)
				ans += (n[j] - '0') * pow_10(size-1-j);

			break;

		}

		bef = now;

	}

	return ans;

}

int main (){

	char n[30];
	llu aux, first, second, first_amnt, second_amnt, ans, dif;

	fill_mat();

	/*for (i = 0; i <= 20 ;i++){

		for (j = 0; j < 10; j++)
			printf("%d * 10^%d: %llu\n", j, i, mat[i][j]);
		puts("");

	}*/

	while (scanf("%s", n) != EOF){

		first = 0;
		for (i = strlen(n)-1, j = 0; i >= 0; i--, j++)
			first += (n[i]-'0') * pow_10(j);

		first_amnt = amnt_n(n);
		ans = first;
		if (first_amnt > 0){

			dif = first_amnt;
			while (dif > 0){

				first_amnt = amnt_n(n);
				second = first + dif;

				//Convert second to string
				aux = second;
				i = 0;
				while (aux > 0){
					aux /= 10;
					i++;
				}
				n[i--] = '\0';
				aux = second;
				while (aux > 0){

					n[i--] = (aux % 10) + '0';
					aux /= 10;

				}

				second_amnt = amnt_n(n);
				dif = second_amnt - first_amnt;
				//printf("dif: %llu\n", dif);

				first = second;
				//printf("%llu\t\t%llu\n", dif, first);

				//for (j = 0; j < 1e7; j++);

			}

			//printf("ANS:\n");
			ans = first;
		}

		printf("%llu\n", ans);
	}

	return 0;
}
