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
#define rep(i, s, n) for(auto i = s; i < n; i++)
#define reprv(i, s, n) for(auto i = s; i >= n; i--)
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

constexpr int inf = 3e5 + 100;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 2e9 + 1;

int n; 
imat days;

const size_t MAX = (size_t)1e5 + 10;
int memo[MAX][3];

int dp(int i, int j) {
  ii p = {i,j};
  if(memo[i][j] != -1) return memo[i][j];

  if(i == n - 1) {
    return days[i][j]; 
  }

  int rs = -inf;
  
  for(int k = 0; k < 3; k++) {
    if(k == j) continue;

    rs = max(dp(i + 1, k) + days[i][j], rs);
  }

  memo[i][j] = rs;

  return memo[i][j];
}

void solve() {
  cin >> n;

  rep(i, 0, MAX) {
    rep(j, 0, 3) {
      memo[i][j] = -1;
    }
  }

  days = vector<ivec>(n, ivec(3));

  fin(r, days) {
    fin(v, r) cin >> v;
  }

  int rs = -inf;
  dbg(days);
  for(int i = 0; i < 3; i++) {
    dbg(i);
    rs = max(dp(0, i), rs);
  }

  dbg(rs);
  print(rs);
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
