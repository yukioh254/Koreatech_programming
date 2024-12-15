#include <iostream>
#include <vector>
#include "team_manager.h"
#include "team_printer.h"

using namespace std;

int main() {
    int p, m;
    cin >> p >> m;

    vector<Team> teams;

    for (int i = 0; i < p; ++i) {
        int level;
        string name;
        cin >> level >> name;
        registerPlayer(teams, level, name, m);
    }

    printTeams(teams, m);

    return 0;
}
