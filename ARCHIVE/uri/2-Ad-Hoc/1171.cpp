#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt, val;
vector<int> numbers;
vector<pair<int, int> > num_qnt;

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%d", &val);
		numbers.push_back(val);

	}

	sort(numbers.begin(), numbers.end());

	num_qnt.push_back(make_pair(numbers[0], 1));
	for (i = 1, j = 0; i < qnt; i++){

		if (num_qnt[j].first != numbers[i]){

			num_qnt.push_back(make_pair(numbers[i], 1));
			j++;

		}
		else if (num_qnt[j].first == numbers[i]){

			num_qnt[j].second++;

		}
	}

	for (i = 0; i <= j; i++)
		printf("%d aparece %d vez(es)\n", num_qnt[i].first, num_qnt[i].second);


	return 0;
}
