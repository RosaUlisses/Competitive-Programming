#include <bits/stdc++.h>
#include <bitset>
#include <set>
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
#define forn(i, n) for(auto i = 0; i < n; ++i)
#define forv(i, n) for(auto i = n; i >= 0; --i)
#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define addm(x, y) if(!has(x, y)) { x[y] = 1; } else { x[y]++; }
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define f first
#define s second
#define pb push_back
#define eb emplace_back
/* #define int long long */


using namespace std;

using ll = long long;
using ui = unsigned int;
using ii = pair<int, int>;
using ivec = vector<int>;
using imat = vector<vector<int>>;
using str = string;

constexpr int msize = 0;
constexpr int inf = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 0x3f3f3f3f3f3f3f3fLL;

struct comparer {
  bool operator()(const bitset<31>& a, const bitset<31>& b) const {
    return a.to_ulong() < b.to_ulong();
  }
};

void solve() {
  int n;  
  cin >> n;

  vector<ui> nums(n);
  fin(v, nums) cin >> v;

  map<bitset<31>, int,comparer> ps;

  int c = 0;
  forn(i, n) {
    dbg(nums[i]);
    bitset<31> bs(nums[i]);
    bitset<31> fp(nums[i]);
    fp.flip();

    if(!has(ps, bs)) {
      if(!has(ps, fp)) {
        ps[fp] = 1;
      }
      else {
        ps[fp]++;
      }
    }
    else {
      c++;
      if(ps[bs] == 1) {
        ps.erase(bs);
      }
      else {
        ps[bs]--;
      } 
    }
  }

  int count = 0;
  fin(v, ps) {
    count += v.s;
  }
  c += count;

  print(c);
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
