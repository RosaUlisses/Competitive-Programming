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
    ((std::cout << (first ? "" : ", ") << args, first = false), ...); std::cout << endl;
};
#define print(...) print_values(__VA_ARGS__);  

#define fin(x, y) for(auto& x : y)
#define fint(i, s, n) for(int i = s; i < n; i++)
#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define minel(x) *min_element(all(x))
#define maxel(x) *max_element(all(x))
#define f first
#define s second


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

int maxS(vector<ll> as) {
  if(as[0] == 0) {
    return 1;
  }

  ll s = as[0];

  s += (2 * min(as[1], as[2]));

  ll d = abs(as[1] - as[2]);

  if(as[0] == as[3]) {
    return s + as[3] + (d != 0 ? 1 : 0);
  }

  if(as[0] < as[3]) {
    return s + as[0] + 1;
  }

  s += as[3];
  as[0] -= as[3];

  if(as[0] >= d) {
    return s + d;
  }

  return s + as[0] + 1;
}


void solve() {
  vector<ll> as(4);   
  fin(v, as) cin >> v;

  ll res = maxS(as);

  dbg(res);

  print(res);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int nt;
  cin >> nt;

  while (nt--) {
      solve();
  }

  return 0;
}
