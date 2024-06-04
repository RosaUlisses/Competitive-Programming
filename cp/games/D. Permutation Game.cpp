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
using ii = pair<int, int>;
using ivec = vector<int>;
using imat = vector<vector<int>>;
using str = string;

constexpr int msize = 0;
constexpr int inf = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 0x3f3f3f3f3f3f3f3fLL;

int calc(ivec& p, ivec& a, int s, int k) {
  ll mx = 0, curr = 0;
  set<int> vis;
  
  while(!has(vis, s) and k > 0) {
    vis.insert(s); 
    mx = max(mx, curr + a[s] * k);
    curr += a[s];
    k--;
    s = p[s];
  }

  return mx;
}

void solve() {
  int n, k, pb, ps;   
  cin >> n >> k >> pb >> ps;

  ivec p(n), a(n);
  fin(v, p) {
    cin >> v;
    v--;
  } 
  fin(v, a) cin >> v;

  int bv = calc(p, a, pb - 1, k);
  int sv = calc(p, a, ps - 1, k);

  if(bv > sv) {
    print("Bodya");
  }
  else if(sv > bv) {
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
