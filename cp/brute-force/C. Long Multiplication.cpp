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
#define rep(i, s, n) for(auto i = s; i < n; i++)
#define reprv(i, s, n) for(auto i = s; i >= n; i--)
#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define addm(x, y) if(!has(x, y)) { x[y] = 1; } else { x[y]++; }
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

int ts(str& s) {
  int a = 0;
  fin(v, s) {
    a += (v - '0');
  }

  return a;
}

bool is_greater(str& a, str& b) {
  rep(i, 0, sz(a)) {
    int v1 = a[i] - '0';
    int v2 = b[i] - '0';

    if(v1 > v2) return true;
    if(v2 > v1) return false;
  }

  return false;
}

void solve() {
  str s1, s2;      
  cin >> s1 >> s2;

  
  rep(i, 0, sz(s1)) {
    int v1 = s1[i] - '0';
    int v2 = s2[i] - '0';
    if((v1 > v2 && is_greater(s1, s2)) || (v2 > v1 && is_greater(s2, s1))) {
      char aux = s1[i];
      s1[i] = s2[i];
      s2[i] = aux;
    }
  }

  print(s1);
  print(s2);
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
