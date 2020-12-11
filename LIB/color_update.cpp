struct segments {
	int n;
	set<pair<pii, int>> segs;
	set<pii> freq;
	vi cnt; // WARNING: Change to map if maximum value is too big
	segments (int _n, int max_v) : n(_n) {
		segs.insert({{1, n}, 1});
		freq.insert({n, 1});
		cnt = vi(max_v + 1);
		cnt[1] = n;
	}

	void add (int l, int r, int new_color) {
		auto it = segs.lower_bound({{l, -1}, -1});
		if (it == segs.end() or it->x.x > l) --it;
		vector<pair<pii, int>> segs_inter;
		do {
			segs_inter.push_back(*it);
			++it;
		} while (it != segs.end() and it->x.x <= r);
		for (auto s : segs_inter)
			segs.erase(s);

		if (segs_inter.front().x.x < l) {
			if (segs_inter.front().y == new_color)
				l = segs_inter.front().x.x;
			else {
				segs.insert({{segs_inter.front().x.x, l-1}, segs_inter.front().y});
				segs_inter.front().x.x = l;
			}
		}
		if (segs_inter.back().x.y > r) {
			if (segs_inter.back().y == new_color)
				r = segs_inter.back().x.y;
			else {
				segs.insert({{r+1, segs_inter.back().x.y}, segs_inter.back().y});
				segs_inter.back().x.y = r;
			}
		}

		for (auto [interval, color] : segs_inter) {
			auto [a, b] = interval;
			freq.erase({cnt[color], color});
			cnt[color] -= b-a+1;
			freq.insert({cnt[color], color});
		}

		freq.erase({cnt[new_color], new_color});
		cnt[new_color] += r-l+1;
		freq.insert({cnt[new_color], new_color});
		segs.insert({{l, r}, new_color});
	}

	int get_freq (int color) {
		return cnt[color];
	}

	int get_most_freq_freq () {
		return freq.rbegin()->x;
	}
};
