#include <bits/stdc++.h>

using namespace std;

int main() {
    int count = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        
        vector<int> arr(n);

        int ans;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] == i + 1) {
                ans = i + 1;
            }
        }
        
        cout << "Teste " << count << "\n";
        cout << ans << "\n";
        
        count++;
    }

    return 0;
}
