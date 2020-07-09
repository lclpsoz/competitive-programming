int low[N], tin[N], component[N];
int timer, scc;
vi stk;

void tarjan(int v) {
	low[v] = tin[v] = ++timer;
	stk.emplace_back(v);
	for(int u : adj[v]) {
		if(!tin[u])
			tarjan(u);
		if(component[u] == -1)
			low[v] = min(low[v], low[u]);
	}

	if(low[v] == tin[v]) {
		while(true) {
			int u = stk.back();
			stk.pop_back();
			component[u] = scc;
			if(u == v) break;
		}
		scc++;
	}
}

void run()
{
	memset(low, 0, sizeof low);
	memset(tin, 0, sizeof tin);
	memset(component, -1, sizeof component);
	scc = timer = 0;
	for(int v = 0; v < n; v++)
		if(!tin[v]) tarjan(v);
}