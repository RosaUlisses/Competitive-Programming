#include <algorithm>
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
  int n, m, q;  
  cin >> n >> m >> q;

  str s, t;
  cin >> s >> t;


  ivec pr(n);
  vector<bool> ok(n);

  for(int i = 0; i < n - m + 1; i++) {
    bool f = true;
    for(int j = 0; j < m; j++) {
      if(s[i + j] != t[j]) f = false;
    }

    ok[i] = f;
    pr[i + 1] = pr[i] + ok[i];
  }

  for(int i = max(0ll, n - m + 1); i + 1 < n; i++) {
    pr[i+1] = pr[i];
  }  

  for(int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    l--; r -= m - 1;
    if(r >= l) {
      print(pr[r] - pr[l]);
    }
    else {
      print(0);
    }
  }

  dbg(pr);  
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int nt = 1;

  while(nt--) {
    solve();
  }

  return 0;
}
