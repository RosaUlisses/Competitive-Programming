#include <bits/stdc++.h>
#include <cstring>
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

constexpr int msize = 100000 + 100;
constexpr int inf = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 0x3f3f3f3f3f3f3f3fLL;

ivec coords, cc;

void solve() {
  int n;  
  cin >> n;

  coords = ivec(n); cc = ivec(n);
  fin(v, coords) cin >> v;

  cc[0] = 1; cc[n - 1] = n - 2;

  for(int i = 1; i < n - 1; i++) {
    if(coords[i+1] - coords[i] <= coords[i] - coords[i-1]) {
      cc[i] = i + 1;
    }
    else {
      cc[i] = i - 1;
    }
  }

  ivec l(n), r(n);

  int cd = 0;
  for(int i = 0; i < n; i++) {
    r[i] = cd;
    if(cc[i] == i + 1) {
      cd++;
    }
    else {
      cd += (coords[i+1] - coords[i]);
    }
  }

  cd = 0;
  for(int i = n - 1; i >= 0; i--) {
    l[i] = cd;
    if(cc[i] == i - 1) {
      cd++;
    }
    else {
      cd += (coords[i] - coords[i-1]);
    }
  }

  dbg(l);

  int q;
  cin >> q;

  for(int i = 0; i < q; i++) {
    int x, y; cin >> x >> y;

    if(x < y) {
      print(r[y-1] - r[x-1]);
    }
    else {
      print(l[y-1] - l[x-1]);
    }
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
