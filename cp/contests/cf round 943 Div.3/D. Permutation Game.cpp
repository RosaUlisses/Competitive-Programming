#include <bits/stdc++.h>
#include <memory>
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

constexpr int msize = 1e9 + 100;
constexpr int inf = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 0x3f3f3f3f3f3f3f3fLL;

const int ab = 1e5 + 100;
ivec a, p;
int memo[ab][msize];

int mxx = -inf;

int dp(int i, int k) {
  if(k == 0) return 0;
  if(k == 1){
    return a[i - 1];
  } 
  ii pr = {i, k};

  if(p[i - 1] == i) {
    return k * a[i - 1];
  } 

  if(a[i - 1] == mxx) {
    memo[i][k] = k * a[i - 1];
    return k * a[i - 1];
  }
  if(memo[i][k] != -1) return memo[i][k];

  int maxv = -inf;

  /* dbg(a[p[i - 1] - 1]); */
  /* if(a[p[i - 1] - 1] > a[i - 1]) { */
  /*   int v = dp(p[i - 1], k - 1) + a[i - 1]; */
  /*   memo[pr] = v; */
  /*   return memo[pr]; */
  /* }  */

  for(int j = k - 1; j >= 0; j--) {
    int v = dp(p[i - 1], j) + (a[i - 1] * (k - 1 - j));
    maxv = max(v, maxv);
  }

  memo[i][k] = maxv + a[i - 1];

  return memo[i][k];
}

void solve() {
  int n, k, pb, ps;  
  cin >> n >> k >> pb >> ps;

  dbg("I");
  memset(memo, -1, sizeof(memo)); 


  p = ivec(n);
  a = ivec(n);

  fin(v, p) cin >> v;
  fin(v, a){
    cin >> v;
    mxx = max(mxx, v); 
  }

  dbg(pb, ps);
  dbg(mxx);

  int resb = dp(pb, k);
  dbg(resb);
  int ress = dp(ps, k);

  if(resb > ress) {
    print("Bodya");
  }
  else if(resb < ress) {
    print("Sasha");
  }
  else {
    print("Draw");
  }
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
