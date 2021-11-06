#include <iostream>
#include <set>
#include <string>
#include <assert.h>
#include <utility>

#if __cplusplus >= 201402L
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif

#if __cplusplus >= 201402L
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#endif

using namespace std;

template <class T, typename Comp = less <T> >
using indexed_set = tree <T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void file() {
	freopen("/tmp/next-prayer/input", "r", stdin);
	freopen("/tmp/next-prayer/output", "w", stdout);
}

class compare {
	public:
	bool operator() (const pair <string, string> &lhs, const pair <string, string> &rhs) const {
	if(lhs.second != rhs.second)
			return lhs.second < rhs.second;
		else
			return lhs.first < rhs.first;
	}
};

const int TEN = 10;

indexed_set <pair<string, string>, compare> mawaqeet;
pair <string, string> cur, _next, _prev;
string _salat, _time;

int
curr_prayer(pair <string, string> cur) {
	/* return the number of items in the set that are strictly smaller than cur */
	return mawaqeet.order_of_key(cur);
}

pair <string, string>
next_prayer(pair <string, string> cur) {
	int sz = mawaqeet.size();
	return *mawaqeet.find_by_order((curr_prayer(cur) + 1) % sz);
}

pair <string, string>
prev_prayer(pair <string, string> cur) {
	int sz = mawaqeet.size();
	return *mawaqeet.find_by_order((curr_prayer(cur) - 1 + sz) % sz);
}

string
adhan_now(pair <string, string> cur, pair <string, string> _next) {
	return (cur.second == _next.second ? "yes" : "no");
}

string
fetch_next(pair <string, string> cur) {
	return (cur.second == "00:00" ? "yes" : "no");
}

pair <int, int>
converto_int(string &x) {
	assert((int)x.size() == 5);
	int hrs = (x[0] - '0') * TEN + (x[1] - '0');
	int mns = (x[3] - '0') * TEN + (x[4] - '0');

	return make_pair(hrs, mns);
}

string
difference(pair <string, string> lhs, pair <string, string> rhs) {
	string ret = "";

	int lhrs, lmns, rhrs, rmns, dhrs, dmns;
	tie(lhrs, lmns) = converto_int(lhs.second);
	tie(rhrs, rmns) = converto_int(rhs.second);

	if(lhrs > rhrs) rhrs += 24;
	if(lmns > rmns) rmns += 60, --rhrs;

	dhrs = rhrs - lhrs;
	dmns = rmns - lmns;

	if(dhrs < 10) ret += "0";
	ret += to_string(dhrs);
	ret += ":";
	if(dmns < 10) ret += "0";
	ret += to_string(dmns);

	return ret;
}

void
read_data() {
	while(cin >> _time >> _salat) {
		mawaqeet.insert(make_pair(_salat, _time));

		if(_salat == "A")
			cur = make_pair(_salat, _time);
	}
}

int main ()
{
	fast();
	file();

	read_data();
	_next = next_prayer(cur);
	_prev = prev_prayer(cur);

	cout << "next_prayer" << " " << _next.first << " " << _next.second << endl;
	cout << "prev_prayer" << " " << _prev.first << " " << _prev.second << endl;
	cout << "time_left" << " " << difference(cur, _next) << endl;
	cout << "elapsed_time" << " " << " " << difference(_prev, cur) << endl;
	cout << "adhan_time" << " " << adhan_now(cur, _next) << endl;
	cout << "new_day" << " " << fetch_next(cur) << endl;
}
