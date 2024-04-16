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

ii maxx(ivec& ns) {
  int ix = 0;
  int mx = ns[0];

  for(int i = 1; i < sz(ns); i++) {
    if(mx < ns[i]) {
      mx = ns[i];
      ix = i;
    }
  }

  return {mx, ix};
}

ii minn(ivec& ns) {
  int ix = 0;
  int mn = ns[0];

  for(int i = 1; i < sz(ns); i++) {
    if(mn > ns[i]) {
      mn = ns[i];
      ix = i;
    }
  }

  return {mn, ix};
}

bool alleq(ivec& ns) {
  for(int i = 0; i < sz(ns); i++) {
    if(i + 1 < sz(ns)) {
      if(ns[i] != ns[i + 1]) return false;
    }
  }

  return true;
}

void solve() {
  int n;      
  cin >> n;

  ivec nums;

  bool b = false;
  fint(i, 0, n) {
    int val;
    cin >> val;
    if(val == 1) b = true;
    nums.push_back(val);
  }

  if(alleq(nums)) {
    print(0);
    return;
  }

  if(b) {
    print(-1);
    return;
  }

  vector<ii> ops;
  for(int i = 0; i < 30 * n; i++) {
    ii mxx = maxx(nums);
    ii mnn = minn(nums);

    dbg(mxx, mnn);
    nums[mxx.s] = mxx.f / mnn.f;
    if((mxx.f % mnn.f) != 0) {
      nums[mxx.s]++;
    }

    ops.push_back({mxx.s + 1, mnn.s + 1});

    dbg(nums);
    
    if(alleq(nums)) {
      break;
    }
  }

  print(ops.size());
  fin(v, ops) {
    print(v.f, v.s);
  }
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
