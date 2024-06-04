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
#define rep(i, s, n) for(auto i = s; i < n; ++i)
#define reprv(i, s, n) for(auto i = s; i >= n; --i)
#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define addm(x, y) if(!has(x, y)) { x[y] = 1; } else { x[y]++; }
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define f first
#define s second
#define pb push_back
#define int long long


using namespace std;

using ll = long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using imat = vector<vector<int>>;
using str = string;

constexpr int msize = 0;
constexpr int inf = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 0x3f3f3f3f3f3f3f3fLL;


void solve() {
  str s, t;
  cin >> s >> t;

  bool f = false;
  for(int i = 0; i < sz(s); i++) {
    int ix = 0, j = i;
    int c = 0;
    str ax;

    int k = 0;
    for(int j = sz(t); j >= 0; j--) {
      str aux;
      int last;
      for(int l = 0; l < j; l++) {
        if(l + i > sz(s)) break;
        aux.pb(s[l+i]);
        last = l + i;
      }

      dbg(aux, last, k , j);

      last--;
      for(int l = last; l > last-k; l--) {
        if(l < 0) break; 
        dbg(s[l], l);
        aux.pb(s[l]);
      }

      dbg(aux); 

      if(aux == t) {
        print("YES");
        return;
      }

      k++;
    }

  }

  print("NO");
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int nt;
  cin >> nt;

  while(nt--) {
    solve();
  }

  return 0;
}
