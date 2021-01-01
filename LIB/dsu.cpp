struct Dsu {
	int n;
	vi sz, link;

	Dsu (int _n) : n(_n) {
		sz = vi(n+1, 1);
		link = vi(n+1);
		for (int i = 1; i <= n; i++)
			link[i] = i;
	}

	int find (int x) {
		if (link[x] == x) return x;
		return link[x] = find(link[x]);
	}

	bool same (int x, int y) {
		return this->find(x) == this->find(y);
	}

	void join (int x, int y) {
		x = find(x);
		y = find(y);
		if (this->same(x, y)) return;
		if (sz[x] > sz[y]) swap(x, y);

		sz[y] += sz[x];
		link[x] = y;
	}
};
