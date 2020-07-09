//Implementation using two piles and one vector, one for the train originally, one for the station and the vector for the train  in the end that is readed from stdin. The logic isto first check if the value is in the stack train_ori, if not check if on top of station, if now, than it's impossible to make that sequence.
#include <bits/stdc++.h>
using namespace std;


int i;
int qnt;
int val;
vector<int> train_fin;
stack<int> train_ori, station;
bool ans;

int main (){

	scanf("%d", &qnt);
	while (qnt){

		scanf("%d", &val);
		while (val){

			train_fin.push_back(val);
			for (i = 1; i < qnt; i++){

				scanf("%d", &val);
				train_fin.push_back(val);

			}


			for (i = qnt; i >= 1; i--)
				train_ori.push(i);

			i = 0;
			ans = true;
			while (i < qnt && ans){

				while (!train_ori.empty() && train_ori.top() < train_fin[i]){

					station.push(train_ori.top());
					train_ori.pop();

				}

				if (!train_ori.empty() && train_ori.top() == train_fin[i]){

					i++;
					train_ori.pop();

				}
				else if (!station.empty() && station.top() == train_fin[i]){

					i++;
					station.pop();

				}
				else ans = false;

			}

			if (ans) puts("Yes");
			else puts("No");

			while (!train_ori.empty()) train_ori.pop();
			while (!station.empty()) station.pop();

			train_fin.clear();

			scanf("%d", &val);
		}

		puts("");
		scanf("%d", &qnt);
	}

	return 0;
}
