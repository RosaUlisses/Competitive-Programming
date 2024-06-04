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


void solve() {
  int n;  
  cin >> n;
  
  ivec nums(n);
  fin(v, nums) cin >> v;


  map<ii, pair<map<int,int>, int>> f;
  map<ii, pair<map<int,int>, int>> s;
  map<ii, pair<map<int,int>, int>> t;


  int ans = 0;
  for(int i = 0; i < n - 2; i++) {
    ii p1 = {nums[i+1], nums[i+2]};
    ii p2 = {nums[i], nums[i+2]};
    ii p3 = {nums[i], nums[i+1]};
    
    if(has(f, p1)) {
      if(has(f[p1].f, nums[i])) {
        ans += (f[p1].s - f[p1].f[nums[i]]);
      }
      else {
        ans += f[p1].s;
      }
    }

    dbg(ans);

    if(has(s, p2)) {
      if(has(s[p2].f, nums[i+1])) {
        ans += (s[p2].s - s[p2].f[nums[i+1]]);
      }
      else {
        ans += s[p2].s;
      }
    }


    dbg(ans);

    if(has(t, p3)) {
      if(has(t[p3].f, nums[i+2])) {
        ans += (t[p3].s - t[p3].f[nums[i+2]]);
      }
      else {
        ans += t[p3].s;
      }
    }

    dbg(ans);

    if(!has(f, p1)) {
      f[p1] = {{{nums[i], 1}}, 1};
    }
    else {
      addm(f[p1].f, nums[i]);
      f[p1].s++;
    }

    if(!has(s, p2)) {
      s[p2] = {{{nums[i+1], 1}}, 1};
    }
    else {
      addm(s[p2].f, nums[i+1]);
      s[p2].s++;
    }

    if(!has(t, p3)) {
      t[p3] = {{{nums[i+2], 1}}, 1};
    }
    else {
      addm(t[p3].f, nums[i+2]);
      t[p3].s++;
    }

    dbg(ans);
  }

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
