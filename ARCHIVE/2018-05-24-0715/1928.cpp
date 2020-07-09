#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 5e4+10, MAXL = 20;

int N;
vector<int> adj[MAXN];
int pai[MAXN];
int ancestral[MAXN][MAXL]; // MAXL representa lg N (com uma margem a mais, claro)
int nivel[MAXN];
pii arr[MAXN/2];

void dfs (int v, int p, int d) {
	pai[v] = p;
	nivel[v] = d;
	for (int u : adj[v])
		if (u != p)
			dfs (u, v, d+1);
}

void init () {
	// primeiro, inicializamos tudo para -1
	for(int i = 0;i < MAXN;i++)
	for(int j = 0;j < MAXL;j++)
		ancestral[i][j] = -1;

	// definimos os pais de carda vértice
	for(int i = 1;i <= N;i++) ancestral[i][0] = pai[i];

	// montamos o restante da tabela com programação dinâmica
	for(int j = 1;j < MAXL;j++)
	for(int i = 1;i <=   N;i++)
		if(ancestral[i][j-1] != -1)
	ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];
}

int LCA(int u, int v){

    if(nivel[u] < nivel[v]) swap(u, v); // isto é para definir u como estando mais abaixo

    // vamos agora fazer nivel[u] ser
    // igual nivel[v], subindo pelos
    // ancestrais de u

    for(int i = MAXL-1;i >= 0;i--)
        if(nivel[u] - (1<<i) >= nivel[v])
            u = ancestral[u][i];

    // agora, u e v estão no mesmo nível
    if(u == v) return u;

    // subimos o máximo possível de forma
    // que os dois NÃO passem a ser iguais

    for(int i = MAXL-1;i >= 0;i--)
        if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    // como subimos o máximo possível
    // sabemos que u != v e que pai[u] == pai[v]
    // logo, LCA(u, v) == pai[u] == pai[v]

    return ancestral[u][0];
}

int main ()
{
	scanf ("%d", &N);
	int x;
	int a, b;
	for (int i = 1; i <= N; i++) {
		scanf ("%d", &x);
		if (arr[x].x == 0)
			arr[x].x = i;
		else
			arr[x].y = i;
	}
	for (int i = 0; i < (N-1); i++) {
		scanf ("%d %d", &a, &b);
		adj[a].pb (b);
		adj[b].pb (a);
	}

	dfs (1, 1, 0);
	init ();
	int ans = 0;
	for (int i = 1; i <= N/2; i++) {
		a = arr[i].x;
		b = arr[i].y;
		int v = LCA (a, b);
		ans += nivel [a] + nivel [b] - 2*(nivel [v]);
	}

	printf ("%d\n", ans);

	return 0;
}
