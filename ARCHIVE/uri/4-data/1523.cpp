#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+100;

int main (){

	int i, j;
	bool resp;
	int in, out, last;
	pair<int,int> hours[MAXN];
	int qnt_spaces, qnt_cars;
	stack<int> park;

	scanf("%d %d", &qnt_cars, &qnt_spaces);
	while (qnt_cars || qnt_spaces){

		resp = false;
		if (qnt_spaces){

			resp = true;
			last = 0;
			for (i = 1; i <= qnt_cars; i++){

				scanf("%d %d", &in, &out);

				hours[in].first = i;
				hours[out].second = i;

				if (in > last) last = in;
				if (out > last) last = out;

			}

			for (i = 1; i <= last; i++){

				//Car out
				if (hours[i].second){

					if (park.empty() || hours[i].second != park.top()){

						resp = false;
						break;

					}

					park.pop();

				}
				//Car in
				if (hours[i].first)
					park.push(hours[i].first);

				if (park.size() > qnt_spaces){

					resp = false;
					break;

				}
			}
		}

		if (resp) printf("Sim\n");
		else printf("Nao\n");

		for (i = 0; i <= last; i++){

			hours[i].first = 0;
			hours[i].second = 0;

		}

		while (!park.empty()) park.pop();

		scanf("%d %d", &qnt_cars, &qnt_spaces);
	}

	return 0;
}
