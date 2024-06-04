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


void solve() {
  int n, k;  
  cin >> n >> k;

  ivec nums(k);
  ivec inc(k, n / k - 1);


  int r = n % k; 

  forn(i, r) {
    inc[i]++;
  }


  nums[0] = 1; 

   for(int i = 1; i < k; i++) {
      if(i % 2 != 0) {
          int ml = nums[i - 1] + inc[i - 1];
          int x = inc[i] + ml + 1;
          nums[i] = x;
      }
      else {
        nums[i] = nums[i - 1] + 1;
      }
   }

  dbg(nums);

  ivec ans = nums;

  for(int i = 0; i < n; ) {
    forn(j, k) {
      if(j % 2 == 0) nums[j]++;
      else nums[j]--;

      if(j + i + k < n) {
        ans.pb(nums[j]);
      }
    } 
    i += k;
  }

  dbg(ans);

  fin(v, ans) {
    cout << v << " ";
  }

  cout << endl;
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
