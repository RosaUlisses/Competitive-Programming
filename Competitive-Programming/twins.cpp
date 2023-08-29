#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimum_coins(vector<int>& coins, int coin_amout) {
   int sum = 0; 
   int index = coins.size() - 1;
   while(sum <= coin_amout) {
      sum += coins[index]; 
      coin_amout -= coins[index];
      index--;
   }
    
    return coins.size() - index - 1;
}

int main() {
    int number_of_coins;
    cin >> number_of_coins;
    vector<int> coins(number_of_coins);
    int sum = 0;

    for (int i = 0; i < number_of_coins; ++i) {
        cin >> coins[i];     
        sum += coins[i];
    }

    sort(coins.begin(), coins.end()); 
    
    cout << minimum_coins(coins, sum); 
    
	return 0;
}
