#include <iostream>

using namespace std;

int main() {
    int nt;
    cin >> nt;

    for (int i = 0; i < nt; ++i) {
        double a, b, c; 
        cin >> a >> b >> c;
        double bigger = a > b ? a : b;
        double smaller = a < b ? a : b;
        int count = 0;
        
        while(bigger > smaller) {
            bigger -= c; 
            smaller += c;
            count++;
        } 
        
        cout << count << "\n";
    }
    
    
	return 0;
}
