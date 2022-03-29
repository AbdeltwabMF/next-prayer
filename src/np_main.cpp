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
using ::__gnu_pbds::null_type;
using ::__gnu_pbds::rb_tree_tag;
using ::__gnu_pbds::tree;
using ::__gnu_pbds::tree_order_statistics_node_update;
#endif

using ::std::cin;
using ::std::cout;
using ::std::ios_base;
using ::std::less;
using ::std::make_pair;
using ::std::ostream;
using ::std::pair;
using ::std::string;
using ::std::tie;
using ::std::to_string;

template <class T, typename Comp = less<T>>
using indexed_set =
    tree<T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;

void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

ostream &operator<<(ostream &os, const pair<string, string> &p) {
  os << p.first << " " << p.second;
  return os;
}

// clang-format off
class Compare {
 public:
  bool operator()(const pair<string, string> &lhs,
                  const pair<string, string> &rhs) const {
    if (lhs.second != rhs.second)
      return lhs.second < rhs.second;
    else
      return lhs.first < rhs.first;
  }
};
// clang-format on

// ANSI color for terminal output
/* const char BLACK[] = "\033[30m"; */
/* const char RED[] = "\033[31m"; */
/* const char GREEN[] = "\033[32m"; */
const char YELLOW[] = "\033[33m";
/* const char BLUE[] = "\033[34m"; */
const char MAGENTA[] = "\033[35m";
/* const char CYAN[] = "\033[36m"; */
/* const char WHITE[] = "\033[37m"; */
const char RESET[] = "\033[0m";

// ANSI color for terminal output (bold)
/* const char BOLD_BLACK[] = "\033[1;30m"; */
const char BOLD_RED[] = "\033[1;31m";
const char BOLD_GREEN[] = "\033[1;32m";
const char BOLD_YELLOW[] = "\033[1;33m";
/* const char BOLD_BLUE[] = "\033[1;34m"; */
const char BOLD_MAGENTA[] = "\033[1;35m";
const char BOLD_CYAN[] = "\033[1;36m";
const char BOLD_WHITE[] = "\033[1;37m";

const int TEN = 10;
const char VERSION[] = "v2.0.0";

void File(const char *fread) { freopen(fread, "r", stdin); }

indexed_set<pair<string, string>, Compare> mawaqeet;
pair<string, string> cur, _next, _prev;

int CurrPrayer(pair<string, string> cur) {
  /* return number of items in the set that are strictly smaller than cur */
  return mawaqeet.order_of_key(cur);
}

pair<string, string> NextPrayer(pair<string, string> cur) {
  int sz = mawaqeet.size();
  return *mawaqeet.find_by_order((CurrPrayer(cur) + 1) % sz);
}

pair<string, string> PrevPrayer(pair<string, string> cur) {
  int sz = mawaqeet.size();
  return *mawaqeet.find_by_order((CurrPrayer(cur) - 1 + sz) % sz);
}

string AdhanNow(pair<string, string> cur, pair<string, string> _next) {
  return (cur.second == _next.second ? "True" : "False");
}

string FetchNext(pair<string, string> cur) {
  return (cur.second == "00:00" ? "True" : "False");
}

pair<int, int> ConverStrToPairInt(const string &x) {
  assert(static_cast<int>(x.size()) == 5);
  int hrs = (x[0] - '0') * TEN + (x[1] - '0');
  int mns = (x[3] - '0') * TEN + (x[4] - '0');

  return make_pair(hrs, mns);
}

string GetTimeDifference(string lhs, string rhs) {
  string ret = "";

  int lhrs, lmns, rhrs, rmns, dhrs, dmns;
  tie(lhrs, lmns) = ConverStrToPairInt(lhs);
  tie(rhrs, rmns) = ConverStrToPairInt(rhs);

  if (lhrs > rhrs)
    rhrs += 24;
  if (lmns > rmns)
    rmns += 60, --rhrs;

  dhrs = rhrs - lhrs;
  dmns = rmns - lmns;

  if (dhrs < 10)
    ret += "0";
  ret += to_string(dhrs);
  ret += ":";
  if (dmns < 10)
    ret += "0";
  ret += to_string(dmns);

  return ret;
}

pair<string, string> Make12(const string &x) {
  assert(static_cast<int>(x.size()) == 5);
  if (x <= "11:59")
    return make_pair(x, "AM");
  else if (x <= "12:59")
    return make_pair(x, "PM");
  else
    return make_pair(GetTimeDifference("12:00", x), "PM");
}

struct tm *localtime_r(const time_t *timep, struct tm *result);

const string GetCurrentTimeDate() {
  char buf[80];
  const time_t now = time(0);
  struct tm tstruct;
  tstruct = *localtime_r(&now, &tstruct);
  strftime(buf, sizeof(buf), "%H:%M %d-%m-%Y", &tstruct);

  return buf;
}

string GetHijriDate(string lang) {
  string day, month_ar, month_en, year;
  cin.ignore();
  getline(cin, day);
  getline(cin, month_ar);
  getline(cin, month_en);
  getline(cin, year);

  if (lang == "ar")
    return day + "-" + month_ar + "-" + year;
  else
    return day + "-" + month_en + "-" + year;
}

void PrintAll() {
  cout << BOLD_CYAN << "Prayer:\t\t" << BOLD_MAGENTA << "Time:\n" << RESET;
  cout << BOLD_CYAN << "-------\t\t" << BOLD_MAGENTA << "-----\n" << RESET;

  for (auto it = mawaqeet.begin(); it != mawaqeet.end(); ++it) {
    if (it->first == "A")
      continue;
    pair<string, string> cur = Make12(it->second);
    cout << BOLD_YELLOW << it->first << "\t\t" << BOLD_MAGENTA << cur.first
         << " " << cur.second << "\n"
         << RESET;
  }
}

void ReadData() {
  string _salat, _time;
  if (!(cin >> _salat >> _time)) {
    system("np_fetch.py");
    if (!(cin >> _salat >> _time)) {
      cout << BOLD_RED << "Unable to read data\n" << RESET;
      cout << YELLOW << "Run \"make clean install\" first!\n" << RESET;
      exit(1);
    }
  }

  mawaqeet.insert(make_pair(_salat, _time));
  for (int i = 1; i < 6; ++i) {
    cin >> _salat >> _time;
    mawaqeet.insert(make_pair(_salat, _time));
  }
}

int main(int argc, char **argv) {
  Fast();
  File(("IAMUName/.local/share/next-prayer/" + GetCurrentTimeDate().substr(6) +
        ".txt")
           .c_str());

  ReadData();
  cur = make_pair("A", GetCurrentTimeDate().substr(0, 5));
  mawaqeet.insert(cur);
  string hijri = GetHijriDate("ar");

  _next = NextPrayer(cur);
  _prev = PrevPrayer(cur);

  string next_prayer = _next.first + " " + Make12(_next.second).first + " " +
                       Make12(_next.second).second;
  string prev_prayer = _prev.first + " " + Make12(_prev.second).first + " " +
                       Make12(_prev.second).second;
  string time_left = GetTimeDifference(cur.second, _next.second);
  string elapsed_time = GetTimeDifference(_prev.second, cur.second);
  string is_adhan = AdhanNow(cur, _next);
  string is_newday = FetchNext(cur);

  // Read args from command line
  if (argc == 2) {
    if (strcmp(argv[1], "--help") == 0) {
      cout << MAGENTA << "Usage: " << BOLD_MAGENTA << "next-prayer" << RESET
           << MAGENTA << " [--help] [--version] [--options...]\n\n";
      cout << BOLD_YELLOW << "Options:\n" << BOLD_WHITE;
      cout << "  --help\t\tShow this help message and exit.\n";
      cout << "  --version\t\tShow version information and exit.\n";
      cout << "  --next\t\tShow next prayer time.\n";
      cout << "  --all\t\t\tShow all timings.\n";
      cout << "  --prev\t\tShow previous prayer time.\n";
      cout << "  --left\t\tShow time left to next prayer.\n";
      cout << "  --elapsed\t\tShow elapsed time since last prayer.\n";
      cout << "  --adhan\t\tShow if adhan is now playing.\n";
      cout << "  --hijri\t\tShow hijri date.\n";
      cout << "  --hybrid\t\tThe elapsed time since the previous prayer as";
      cout << " far as the elapsed time <= THRESHOLD.\n\n" << RESET;
      cout << YELLOW
           << "This is not the full help, use (man next-prayer) for the";
      cout << " manual.\n" << RESET;
      return 0;
    } else if (strcmp(argv[1], "--version") == 0) {
      cout << "Version: " << BOLD_GREEN << VERSION << "\n" << RESET;
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
    } else if (strcmp(argv[1], "--all") == 0) {
      PrintAll();
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
    } else if (strcmp(argv[1], "--hijri") == 0) {
      cout << hijri << "\n";
      return 0;
    }
  }
}
