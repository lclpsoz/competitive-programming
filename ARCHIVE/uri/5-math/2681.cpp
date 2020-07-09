//Using closed formula for Hanoi Tower T(n) = 2^n - 1
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;
int const MAXN = 45, MOD = 86400;

int i, j;
llu base, val;
llu pow_two_10[45]; //Array with powers of two to powers of ten's {2^10^0, 2^10^1, 2^10^2,..., 2^10^44, 2^10^45}.
llu seconds;
int resp[3];
char str[45];

int main (){

	//Calculate powers of two and save them in pow_two_10
	base = 1LLU << 1;
	pow_two_10[0] = base;
	//printf("%d: %llu\n", i ,pow_two_10[i]);
	for (i = 1; i < 45; i++){

		val = base;
		//Get to the 8' power. Ex: starts with base 2^1, doing that go to 2^8 in 3 iterations instead of 8
		for (j = 0; j < 3; j++)
			 val = (val * val) % MOD;

		//Get from exp. 8 to 10, multiplying it twice by the exp. 1
		val = (val * base * base) % MOD;

		pow_two_10[i] = val;
		//printf("%d: %llu\n", i ,pow_two_10[i]);
		//To get reused in the new iteration
		base = val;

	}

	scanf("%s", str);

	seconds = 1;
	for (i = strlen(str)-1, j = 0; i >= 0; i--, j++){

		while (str[i]-'0'){

			seconds *= (pow_two_10[j]);
			seconds %= MOD;
			str[i]--;

		}
	}
	seconds--; //From the formula of Hinoi Tower

	//printf("%llu\n", seconds);
	resp[0] = seconds / 3600;
	seconds %= 3600;
	resp[1] = seconds / 60;
	seconds %= 60;
	resp[2] = seconds;

	printf("%02d:%02d:%02d\n", resp[0], resp[1], resp[2]);

	return 0;
}
