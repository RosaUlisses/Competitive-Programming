#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define lix(x) (x.size() - 1)

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
    int N = n;
    
    if(n == 9 || n <= 7) {
        print("NO");
    }

    int nd = 0;
    while(n / 10 > 0) {
        if ((n % 10) % 3 == 0 && (n % 10) != 0) {
            nd++;
        } 
        if(nd > 1) {
            print("NO");
            return;
        }
        n /= 10;
    }

    print("YES");
    if (i == 10) {
        print_s(4);
        print_s(5);
        print_s(1);
        cout << endl;
        return;
    } 
    
    if (N % 10 == 0) {
        print_s(N - 6);
        print_s(4);
        print_s(2);
        cout << endl;
        return;
    } 
    
    if (nd == 0) {
        print_s(N % 10);
        N -= (N % 10);
        print_s(2);
        print_s(N - 2);
        cout << endl; 
        return;
    }
    
    int oth = 0; 
    int dv3 = 0;
    int dv3_ix = 0;
    int ix = 1; 
    while(N / 10 > 0) {
        int ld = (n % 10); 
        if(ld % 3 == 0) {
           dv3 = ld; 
           dv3_ix = ix;
        } 
        else {
           oth += (ld * ix);  
        }
        
        ix *= 10;
        N /= 10;
    }

    print("YES");
    print_s(oth);
    print(1 * dv3_ix);
    if (dv3 == 3) {
        print(2 * dv3_ix);
    }
    else if(dv3 == 6) {
        print(5 * dv3_ix);
    }

    else if(dv3 == 9) {
        print(8 * dv3_ix);
    }

    cout << endl;
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
