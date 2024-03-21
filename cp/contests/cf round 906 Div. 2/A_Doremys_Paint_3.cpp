#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

#define loop(x, y) for(int x = 0; x < y; x++)
#define fin(x, y) for(auto& x : y)
#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define f first
#define s second


using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using imat = vector<vector<int>>;
using str = string;

constexpr int inf = 2e9 + 1;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 3e5 + 100;

void solve() {
    int n;
    cin >> n;
    
    ivec v(n);

    fin(val, v) {
        cin >> val;
    }
    
    if(n == 2) {
        print("Yes");
        return;
    }
    
    
    map<int,int> m;
    loop(i, n) {
        if(!has(m, v[i])) {
            m.insert({v[i], 1});        
        }
        else m[v[i]]++;
    }
    
    if(sz(m) == 1) {
        print("Yes");
        return;
    } 
    
    if(sz(m) == 2) {
        vector<int> qtd;
        fin(p, m) {
            qtd.push_back(p.s); 
        }
        
        if(qtd[0] > qtd[1]) {
            if (qtd[0] == (qtd[1] + 1)) {
                print("Yes");
                return;
            }
        }
        
        else if(qtd[1] > qtd[0]) {
            if (qtd[1] == (qtd[0] + 1)) {
                print("Yes");
                return;
            }
        }
        
        else {
            print("Yes");
            return;
        }
    }

    print("No"); 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int nt;
    cin >> nt;

    while (nt--) {
        solve();
    }

    return 0;
}
