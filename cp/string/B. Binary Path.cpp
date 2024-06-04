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
#define int long long


using namespace std;

using ll = long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using imat = vector<vector<int>>;
using str = string;

constexpr int msize = 2 * 1e5 + 100;
constexpr int inf = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 0x3f3f3f3f3f3f3f3fLL;

int n, ct;      
vector<str> g;


void solve() {
  cin >> n;

  g = vector<str>(2);
  cin >> g[0]; cin >> g[1];

  str pth = {g[0][0]};
  int i = 1, j = 0;
  bool d = false;
  while(true) {
    if(i == n) {
      pth.push_back(g[1][j]);
      break;
    }
    if(g[0][i] <= g[1][j]) pth.push_back(g[0][i]);
    else {
      dbg("oi");
      pth.push_back(g[1][j]);
      d = true;
      for(int k = j + 1; k < n; k++) {
        pth.push_back(g[1][k]);
        dbg(k);
      }
      break;
    }
    i++; j++;
  }

  int last = n - 1;
  while(last >= 0 and pth[last + 1] == g[1][last]) {
    last--;
  }
  last++;

  int ans = 1;

  rep(k, last, n - 1) {
    if(g[0][k + 1] == g[1][k]) ans++;
    else break;
  }

  print(pth);
  print(ans);
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
