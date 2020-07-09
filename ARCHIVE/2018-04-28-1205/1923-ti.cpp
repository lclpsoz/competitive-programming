#include <bits/stdc++.h>
using namespace std;

int n, g;
char aux[1000];
string n1, n2;
map<string, vector<string>> rl;
set<string> amg;
map<string, bool> visitado;

void bfs()
{
    queue<string> f;
    f.push("Rerisson");
    for(int i = 0; i < g; ++i){
    	if (f.empty()) return;
    	n1 = f.front(); f.pop();
        visitado[n1] = true;
    	for(auto x : rl[n1]){
            if (visitado[x]) continue;
            amg.insert(x);
            f.push(x);
            visitado[x] = true;
    	}
    }
}

int main () {
    scanf("%d%d", &n, &g);
    for(int i = 0; i < n; ++i) {
    	scanf ("%s", aux);
        n1 = aux;
        scanf("%s", aux);
        n2 = aux;
    	rl[n1].push_back(n2);
        rl[n2].push_back(n1);
    }
    bfs();
    printf("%ld", amg.size());
    putchar('\n');
    for(auto x : amg) {
        cout << x;
    	putchar('\n');
    }

    return 0;
}
