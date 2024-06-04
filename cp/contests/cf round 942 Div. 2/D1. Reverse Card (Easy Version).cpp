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

constexpr int msize = 2 * (1e6) + 100;
constexpr int inf = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 0x3f3f3f3f3f3f3f3fLL;


int divi[msize];

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

void crivo(int lim1, int lim2) {
  for(int i = 1; i <= lim1; i++) divi[i] = 1;

  for(int i = 2; i <= lim1; i++) {
    if(divi[i] == 1) {
      dbg(i);
      for(int j = i; j <= lim2; j += i){
        if((gcd(j, i) * i) % (j + i) == 0) {
          dbg((j + i),gcd(j, i), i);
          divi[j]++;
        }
      } 
    }
  }
}


void solve() {
  int n, m;  
  cin >> n >> m;

  
  if(n < m) {
    crivo(n, n);
  }

  else {
    crivo(n, m);
  }


  int ans = 0;
  for(int i = 1; i <= n; i++) {
    dbg(i, divi[i]);
    ans += divi[i];
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
