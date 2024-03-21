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


void solve() {
  int n;
  cin >> n;
  str s;
  cin >> s;

  int mc = 0;
  int pc = 0;
  int ec = 0;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'm') {
      while(s[i] == 'm') {
        i++;
        mc++;
      }
      i--;

      if(s[i + 1] == 'a' && s[i + 2] == 'p') {
        i += 2;
        while(s[i] == 'p') {
          i++;
          pc++;
        }
        i--;

        if(s[i + 1] == 'i' && s[i + 2] == 'e') {
          i += 2;
          while(s[i] == 'e') {
            i++;
            ec++;
          }
          i--;

          ans += min(2, pc);
        }

        else {
          ans++;          
        }
      }
    }

    else if(s[i] == 'p') {
      while(s[i] == 'p') {
        i++;
        pc++;
      }
      i--;

      if(s[i + 1] == 'i' && s[i + 2] == 'e') {
        i += 2;
        while(s[i] == 'e') {
          i++;
          ec++;
        }
        i--;

        ans++;
      }
    }

    mc = 0;
    pc = 0;
    ec = 0;
  }

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
