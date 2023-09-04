#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

inline bool is_valid_password2(const string& word, const pair<int,int>& range_password) {
    int password_size = range_password.second - range_password.first;
    for (int i = 1; i < word.size() - 1; ++i) {
        int counter = 0;
        for (int j = i; j < i + password_size; ++j) {
            if (j > word.size() - 1) {
                break;
            }
            if(word[j] == word[range_password.first + counter]) {
                counter++;
            }
            else break;
            if (counter == password_size && j < word.size() - 1) return true;
        }
    }

    return false;   
}


inline bool prefix_and_sufix_are_equal(const string& string, const int lenght) {
    for (int i = 0; i < lenght; ++i) {
        if (string[i] != string[string.size() - lenght + i]) return false; 
    }
    
    return true;
}

bool prefix_and_sufix_are_equal2(const string& str, int length) {
    string prefix = str.substr(0, length);
    string sufix = str.substr(str.size() - length, length);
    return std::hash<string>()(prefix) == std::hash<string>()(sufix);
}

inline pair<int,int> find_password2(const string& word) {
    for (int i = word.size() - 2; i >= 1; --i) {
        if (prefix_and_sufix_are_equal2(word, i)) {
            pair<int,int> prefix_range = {0, i};
            if (is_valid_password2(word, prefix_range)) {
                return prefix_range;
            }
        }
    }

    return {-1, -1};   
}


inline pair<int,int> find_password3(const string& word) {
    if (word.size() == 1) return {-1, -1};
    
    set<int> prefix_lengths;

    for (int i = 1; i <= word.size() - 2; ++i) {
        string prefix = word.substr(0, i);
        string sufix = word.substr(word.size() - i, i);
        if (std::hash<string>()(prefix) == std::hash<string>()(sufix)) {
            prefix_lengths.insert(-prefix.size()); 
        }
    } 
    

    for (auto length : prefix_lengths) {
        if (is_valid_password2(word, {0, -length})) {
            return {0, -length};
        } 
    }

    return {-1, -1};
}

int main() {
    string word;
    word.reserve(1000000);
    cin >> word;

    pair<int,int> result = find_password3(word);
    if (result.first != -1) {
        for (int i = result.first; i < result.second; ++i) {
            cout << word[i]; 
        }
    }

    else cout << "Just a legend";
	return 0;
}
