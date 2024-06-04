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

constexpr int size_ = 1e5 + 100;
constexpr int inf = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 0x3f3f3f3f3f3f3f3fLL;

ivec h;
int n, k; 

int memo[size_];

int dp(int i) {
  if(i == n - 1) return 0;
  if(memo[i] != -1) return memo[i];

  int mn;
  for(int j = 1; j <= k; j++) {
    if(j == 1) mn = dp(i + j) + abs(h[i] - h[i + j]);
    dbg(i,j);
    if(i + j >= n) continue;
    mn = min(dp(i + j) + abs(h[i] - h[i + j]), mn);
    dbg(mn);
  } 

  memo[i] = mn;

  return memo[i];
}

void solve() {
  cin >> n >> k;

  rep(i, 0, size_) memo[i] = -1;

  h = ivec(n);
  fin(v, h) cin >> v;

  print(dp(0));
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int nt = 1;
  /* cin >> nt; */

  while(nt--) {
    solve();
  }

  return 0;
}
