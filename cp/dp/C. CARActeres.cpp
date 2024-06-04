#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
  #include "/home/ullas/Programming/Competitive-Programming/cp/debug.h"
#endif

#ifdef ONLINE_JUDGE
  #define dbg(...) 
#endif

#define endl ('\n')
auto print_values = [](auto&&... args) {
    bool first = true;
    ((std::cout << (first ? "" : " ") << args, first = false), ...); std::cout << endl;
};
#define print(...) print_values(__VA_ARGS__);  

#define fin(x, y) for(auto& x : y)
#define fint(i, s, n) for(int i = s; i < n; i++)
#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define minel(x) *min_element(all(x))
#define maxel(x) *max_element(all(x))
#define f first
#define s second


using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using imat = vector<vector<int>>;
using str = string;

constexpr int inf = 3e5 + 100;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 2e9 + 1;


void solve() {
  str s; 
  cin >> s;

  dbg(s);
  ivec lpa(sz(s));
  ivec upa(sz(s));

  int lc = 0, uc = 0;
  for(int i = sz(s) - 1; i >= 0; i--) {
    lpa[i] = lc; 
    upa[i] = uc;

    if(islower(s[i])) lc++;
    else uc++;
  }  
  dbg(lpa, upa);

  int ans = inf;
  int lcc = 0, ucc = 0;
  for(int i = 0; i < sz(s); i++) {
    int st = i;
    int am = 0;
    while(islower(s[st]) ? islower(s[i]) : !islower(s[i]) && i < sz(s)) {
      i++;
      if(islower(s[st])) am++;
      else am++;
    }
    i--;

    dbg(i);
    int res;
    if(islower(s[st])) {
      res = min(lcc + upa[i], ucc + upa[i]);
    }
    else {
      res = min(lcc + upa[i], lcc + lpa[i]);
    }

    ans = min(ans, res);

    if(islower(s[st])) lcc += am;
    else ucc += am;
  }

  print(ans);
  dbg(ans);

}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int nt = 1;
  /* cin >> nt; */

  while (nt--) {
      solve();
  }

  return 0;
}
