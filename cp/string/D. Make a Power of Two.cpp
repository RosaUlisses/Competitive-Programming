#include <bits/stdc++.h>
#include <string>
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
#define int unsigned long long


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

int mcp(vector<str>& pows, str n) {
  int ct = maxnum;

  fin(p, pows) {
    int i = 0, j = 0, tk = 0;
    while(i < sz(n) and j < sz(p)) {
      if(n[i] == p[j]) {
        j++;
        tk++;
      }
      i++;
    }

    int crt = sz(n) - tk + sz(p) - tk;
    ct = min(ct, crt);
  }
  
  return ct;
}


void solve() {
  str n;  
  cin >> n;

  vector<str> pows;
  for(int i = 1; i <= 2e18; i*=2) {
    pows.push_back(to_string(i));
  }

  int ans = mcp(pows, n);

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
