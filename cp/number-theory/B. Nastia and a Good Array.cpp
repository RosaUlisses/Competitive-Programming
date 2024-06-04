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

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

void solve() {
  int n;  
  cin >> n;

  ivec v(n);
  fin(val, v) cin >> val;

  int big_prime = 1999999993;

  vector<ivec> out;
  for(int i = 0; i < n - 1; i++) {
    if(gcd(v[i], v[i+1]) != 1) {
      if(v[i] <= v[i+1]) {
        out.pb({i + 1, i + 2, v[i], big_prime});
        v[i + 1] = big_prime;
      }
      else {
        out.pb({i + 1, i + 2, v[i+1], big_prime});
        v[i] = v[i+1];
        v[i+1] = big_prime;
      }
    }
    i++;
  }


  for(int i = 1; i < n; i++) {
    dbg(gcd(v[i-1], v[i]));
  }

  dbg(v);
  dbg(out);

  print(sz(out));
  fin(r, out) {
    fin(val, r) {
      cout << val << " ";
    }
    cout << endl;
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
