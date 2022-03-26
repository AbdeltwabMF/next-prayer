// Copyright (c) 2021-2022 Abd El-Twab M. Fakhry
// Distributed under the GPL-v3 license, see the accompanying
// file COPYING or https://www.gnu.org/licenses/gpl-3.0.en.html.

#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <utility>

#if __cplusplus >= 201402L
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif

#if __cplusplus >= 201402L
using ::__gnu_pbds::tree;
using ::__gnu_pbds::null_type;
using ::__gnu_pbds::rb_tree_tag;
using ::__gnu_pbds::tree_order_statistics_node_update;
#endif

using ::std::cin;
using ::std::tie;
using ::std::cout;
using ::std::less;
using ::std::pair;
using ::std::string;
using ::std::ostream;
using ::std::ios_base;
using ::std::make_pair;
using ::std::to_string;

template <class T, typename Comp = less <T> >
using indexed_set = tree <
  T,
  null_type,
  Comp,
  rb_tree_tag,
  tree_order_statistics_node_update
  >;

void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

ostream &operator << (ostream &os, const pair<string, string> &p) {
  os << p.first << " " << p.second;
  return os;
}

class Compare {
 public:
  bool operator() (
    const pair <string, string> &lhs,
    const pair <string, string> &rhs
  )
  const {
  if (lhs.second != rhs.second)
    return lhs.second < rhs.second;
  else
    return lhs.first < rhs.first;
  }
};

const int TEN = 10;
const string VERSION = "v2.0.0";
string INPUT_DIR = "/home/amf/.local/share/next-prayer/";
string OUTPUT_DIR = "/tmp/next-prayer/";

void File(const char* fread) {
  freopen(fread, "r", stdin);
  /* freopen(fwrite, "w", stdout); */
}

indexed_set <pair<string, string>, Compare> mawaqeet;
pair <string, string> cur, _next, _prev;

int
CurrPrayer(pair <string, string> cur) {
  /* return the number of items in the set that are strictly smaller than cur */
  return mawaqeet.order_of_key(cur);
}

pair <string, string>
NextPrayer(pair <string, string> cur) {
  int sz = mawaqeet.size();
  return *mawaqeet.find_by_order((CurrPrayer(cur) + 1) % sz);
}

pair <string, string>
PrevPrayer(pair <string, string> cur) {
  int sz = mawaqeet.size();
  return *mawaqeet.find_by_order((CurrPrayer(cur) - 1 + sz) % sz);
}

string
AdhanNow(pair <string, string> cur, pair <string, string> _next) {
  return (cur.second == _next.second ? "True" : "False");
}

string
FetchNext(pair <string, string> cur) {
  return (cur.second == "00:00" ? "True" : "False");
}

pair <int, int>
ConverStrToPairInt(const string &x) {
  assert(static_cast<int>(x.size()) == 5);
  int hrs = (x[0] - '0') * TEN + (x[1] - '0');
  int mns = (x[3] - '0') * TEN + (x[4] - '0');

  return make_pair(hrs, mns);
}

string
GetTimeDifference(string lhs, string rhs) {
  string ret = "";

  int lhrs, lmns, rhrs, rmns, dhrs, dmns;
  tie(lhrs, lmns) = ConverStrToPairInt(lhs);
  tie(rhrs, rmns) = ConverStrToPairInt(rhs);

  if (lhrs > rhrs) rhrs += 24;
  if (lmns > rmns) rmns += 60, --rhrs;

  dhrs = rhrs - lhrs;
  dmns = rmns - lmns;

  if (dhrs < 10) ret += "0";
  ret += to_string(dhrs);
  ret += ":";
  if (dmns < 10) ret += "0";
  ret += to_string(dmns);

  return ret;
}

pair<string, string>
Make12(const string &x) {
  assert(static_cast<int>(x.size()) == 5);
  if (x <= "11:59")
    return make_pair(x, "AM");
  else if (x <= "12:59")
    return make_pair(x, "PM");
  else
    return make_pair(GetTimeDifference("12:00", x), "PM");
}

const string
GetCurrentTimeDate() {
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%H:%M %d-%m-%Y", &tstruct);

  return buf;
}

const string
GetHijriDate() {
  string day, month_ar, month_en, year;
  cin.ignore();
  getline(cin, day);
  getline(cin, month_ar);
  getline(cin, month_en);
  getline(cin, year);

  return day + "." + month_ar + "." + year;
}

void
ReadData() {
  string _salat, _time;
  for (int i = 0; i < 6; ++i) {
    cin >> _salat >> _time;
    mawaqeet.insert(make_pair(_salat, _time));
  }
}

int main(int argc, char** argv) {
  Fast();
  File((INPUT_DIR + GetCurrentTimeDate().substr(6) + ".txt").c_str());

  ReadData();
  cur = make_pair("A", GetCurrentTimeDate().substr(0, 5));
  mawaqeet.insert(cur);

  _next = NextPrayer(cur);
  _prev = PrevPrayer(cur);

  string next_prayer  =  _next.first + " " + Make12(_next.second).first + " " + Make12(_next.second).second;
  string prev_prayer  =  _prev.first + " " + Make12(_prev.second).first + " " + Make12(_prev.second).second;
  string time_left    =  GetTimeDifference(cur.second, _next.second);
  string elapsed_time =  GetTimeDifference(_prev.second, cur.second);
  string is_adhan     =  AdhanNow(cur, _next);
  string is_newday    =  FetchNext(cur);
  string hijri_date   =  GetHijriDate();

  // Read args from command line
  if (argc == 2) {
    if (strcmp(argv[1], "--help") == 0) {
      cout << "Usage: " << argv[0] << " [options...]" << "\n";
      cout << "Options:\n";
      cout << " --next      " << "The next prayer and its time." << "\n";
      cout << " --prev      " << "The previous prayer and its time." << "\n";
      cout << " --hybrid    " << "The elapsed time since the previous prayer as far as the elapsed time <= THRESHOLD." << "\n";
      cout << " --left      " << "The time left till the next prayer." << "\n";
      cout << " --elapsed   " << "The time elapsed since the previous prayer." << "\n";
      cout << " --adhan     " << "Whether the current time is adhan or not." << "\n";
      cout << " --hijri     " << "The current hijri date." << "\n";
      cout << " --help      " << "Display this help message." << "\n\n\n";
      cout << "This is not the full help, use (man next_prayer) for the manual." << "\n";
      return 0;
    } else if (strcmp(argv[1], "--version") == 0) {
      cout << "Version: " << VERSION << "\n";
      return 0;
    } else if (strcmp(argv[1], "--hybrid") == 0) {
      if (elapsed_time <= "00:30") {
        cout << elapsed_time << " since " << _prev.first << "\n";
      } else {
        cout << _next.first << " " << Make12(_next.second) << "\n";
      }
      return 0;
    } else if (strcmp(argv[1], "--next") == 0) {
      cout << _next.first << " " << Make12(_next.second) << "\n";
      return 0;
    } else if (strcmp(argv[1], "--prev") == 0) {
      cout << _prev.first << " " << Make12(_prev.second) << "\n";
      return 0;
    } else if (strcmp(argv[1], "--elapsed") == 0) {
      cout << elapsed_time << " since " << _prev.first << "\n";
      return 0;
    } else if (strcmp(argv[1], "--left") == 0) {
      cout << time_left << " until " << _next.first << "\n";
      return 0;
    } else if (strcmp(argv[1], "--adhan") == 0) {
      cout << is_adhan << "\n";
      return 0;
    }
  }
}
