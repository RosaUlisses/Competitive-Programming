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

map<int, int> trial(ll n) {
  map<int,int> res;
  for(ll i = 2; i <= n * n; i++) {
    while(n % i == 0) {
        if(!has(res, i)) res[i] = 1;  
        else res[i]++;
        n /= i;
    }
  }

  if(n > 1) {
    if(!has(res, n)) res[n] = 1;  
    else res[n]++;
  }

  return res;
}

void solve() {
       
  ll a, b, l; 
  cin >> a >> b >> l;

  set<int> ans;

  // the max exponent for A is 34
  for(int i = 0; i <= 34; i++) {
    int x = l;
    bool fail = false;

    for(int _ = 0; _ < i; _++) {
      if(x % a != 0) {
        fail = true;
        break;
      }
      x /= a;
    }

    /*
     * For each possible exponent of A we are calculating the possible exponents for B 
     */
    if(fail) break;
    while(true) {
      ans.insert(x);
      if(x % b != 0) break;
      x /= b;
    }
  }

  print(sz(ans));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    /* freopen("output.txt", "w", stdout); */
    freopen("error.txt", "w", stderr);
  #endif

  int nt;
  cin >> nt;

  while (nt--) {
      solve();
  }

  return 0;
}
