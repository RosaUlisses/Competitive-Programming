#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int number_of_goals;
    cin >> number_of_goals;
    map<string, int> goals_per_team;
    pair<string, int> most_goals = {"", -1};

    for (int i = 0; i < number_of_goals; ++i) {
        string team;
        cin >> team;
        if (goals_per_team.find(team) != goals_per_team.end()) {
            goals_per_team[team] = goals_per_team[team] + 1;
        } else goals_per_team.insert({team, 1});

        if (goals_per_team[team] > most_goals.second) {
            most_goals = {team, goals_per_team[team]};
        }
    }

    cout << most_goals.first;

    return 0;
}
