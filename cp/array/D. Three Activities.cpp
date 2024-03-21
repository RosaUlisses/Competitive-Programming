#include <bits/stdc++.h>
#include <utility>

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


bool all_different(ivec vec) {
  set<int> st;
  
  fin(v, vec) {
    if(has(st, v)) {
      return false;
    }

    st.insert(v);
  }

  return true;
}


void solve() {
  int n;
  cin >> n;
  vector<vector<ii>> vecs(3);
  vector<vector<pair<int, int>>> maxes;

  fin(vec, vecs) {
    for(int i = 0; i < n; i++) {
      int val;
      cin >> val;
      vec.push_back({val, i});
    }
    sort(all(vec), [](auto x, auto y) {
      return x.f > y.f;
    });
    
    maxes.push_back({vec[0], vec[1], vec[2]});
  }

  ll maxval = 0; 

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < 3; k++) {
        if(all_different({ maxes[0][i].s, maxes[1][j].s, maxes[2][k].s })) {
          ll sum = maxes[0][i].f + maxes[1][j].f + maxes[2][k].f;
          if(sum > maxval) maxval = sum;
        }
      }
    }
  }

  print(maxval);
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
