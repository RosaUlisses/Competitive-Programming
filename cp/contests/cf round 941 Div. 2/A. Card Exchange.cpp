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
#define minel(x) *min_element(all(x))
#define maxel(x) *max_element(all(x))
#define f first
#define s second
#define int long long


using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using imat = vector<vector<int>>;
using str = string;

constexpr int msize = 0;
constexpr int inf = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 0x3f3f3f3f3f3f3f3fLL;


void solve() {
  int n, k;  
  cin >> n >> k;

  map<int,int> m;

  rep(i, 0, n) {
    int v;
    cin >> v;
    addm(m, v);
  }

  fin(p, m) {
    if(p.s >= k) {
      print(k - 1);
      return;
    }
  }

  print(n);
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
