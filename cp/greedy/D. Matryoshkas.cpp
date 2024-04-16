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


void solve() {
  int n;      
  cin >> n;

  map<int,int> mp;

  for(int i = 0; i < n; i++) {
    int val;
    cin >> val;
    if(!has(mp, val)) mp[val] = 1;
    else mp[val]++;
  }

  ivec ns;
  fin(p, mp) ns.push_back(p.f);

  int ans = mp[ns[0]];
  int l = mp[ns[0]];
  for(int i = 1; i < sz(ns); i++) {
    if(mp[ns[i]] > l && ns[i] - 1 == ns[i - 1]) {
      ans += (mp[ns[i]] - l);
    } 

    dbg(mp[ns[i]], l);

    if(ns[i] - 1 != ns[i - 1]) {
      ans += mp[ns[i]];
    }

    l = mp[ns[i]];
  }

  print(ans);
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
