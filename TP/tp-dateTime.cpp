/////////////////////////////////// Date/Time //////////////////////////////////

int mnt[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

struct Date {
	int d, m, y;
	Date () : d(1), m(1), y(1) {}
	Date (int _d, int _m, int _y) : d(_d), m(_m), y(_y) {}
	Date (int days) : d(1), m(1), y(1) { advance (days); }
	bool leap () { return (y%4 == 0 && y%100) || (y%400 == 0); }
	int mdays () { return mnt[m] - mnt[m-1] + (m == 2)*leap(); }
	int ydays () { return 365 + leap(); }
	int count () {
		return (d-1) + mnt[m-1] + (m > 2)*leap() +
			365*(y-1) + (y-1)/4 - (y-1)/100 + (y-1)/400;
	}
	int weekday () { return (count()+1) % 7; }
	void advance (int days) {
		days += count();
		d = m = 1, y = 1 + days/366;
		days -= count();
		while (days >= ydays()) days -= ydays(), y++;
		while (days >= mdays()) days -= mdays(), m++;
		d += days;
	}
};

struct DateTime {
	Date dt;
	ll hr, mi, sec;
	DateTime () : hr(0), mi(0), sec(0) {}
	DateTime (ll _hr, ll _mi, ll _sec) : hr(_hr), mi(_mi), sec(_sec) {}
	DateTime (ll secs) : hr(0), mi(0), sec(0) { advance (secs); }
	ll count () { return 1LL*dt.count()*86400 + hr*3600 + mi*60 + sec; }
	void advance (ll secs) {
		sec += secs;
		mi += sec/60; sec %= 60;
		hr += mi/60; mi %= 60;
		dt.advance (hr/24); hr %= 24;
	}
};

////////////////////////// End of Date/Time. //////////////////////////////