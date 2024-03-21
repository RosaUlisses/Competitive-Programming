#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

#define fin(x, y) for(auto& x : y)
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

map<int,int> trial(int n) {
  map<int,int> fc;
  for (int d = 2; d * d <= n; d++) {
      while (n % d == 0) {
          if(!has(fc, d)) fc[d] = 1;
          else fc[d]++;
          n /= d;
      }
  }
  if (n > 1)
    fc[n] = 1;

  return fc;
}

int extract(map<int,int> m, int v) {
  if(has(m, v)) {
    return m[v] + 1;
  }

  return 1;
}


void solve() {
  int a, b, l; 
  cin >> a >> b >> l;
  
  map<int,int> fc = trial(l);

  if(a == b) {
    int ans = fc[a] / 2 + 1 + (fc[a] - 1) / 2 + 1; 
    print(ans);
    return;
  }

  int ans = extract(fc, a) * extract(fc, b); 

  print(ans);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int nt;
  cin >> nt;

  while (nt--) {
      solve();
  }

  return 0;
}
