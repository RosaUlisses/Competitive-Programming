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
using ull = unsigned long long;
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

  int s = 0;
  fin(v, nums) {
    s += v;
  } 

  int mxs = -inf;
  ii pth;
  int cs = 0;

  int st = 0;
  int end = 0;

  for(int i = 0; i < n; i++) {
    if(nums[i] >= 0) {
      cs += nums[i];   
      end = i; 
    }
    
    if(nums[i] < 0) {
      if(abs(nums[i]) >= cs) {
        if(cs >= s) {
          print("NO");
          return;
        }
        st = i + 1;
        end = i + 1;
      }

      else {
        cs += nums[i];
        end = i;
      }
    }


    if((st != 0 or end < n - 1) and cs >= s) {
      print("NO");
      return;
    }
  }

  if((st != 0 or end < n - 1) and cs >= s) {
      print("NO");
      return;
  }

  print("YES");
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
