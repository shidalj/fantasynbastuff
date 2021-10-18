// nbastats.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

struct player {
    string name;
    double fgp;
    double ftp;
    double points;
    double rebounds;
    double assists;
    double three;
    double blocks;
    double steals;
    double turnovers;
};

vector<player> parseInput() {
    ifstream ifs("players_test.txt");
    vector<player> v;
    if (ifs.is_open()) {
        string line;
        while (getline(ifs, line)) {
            stringstream ss(line);
            string nextColumn;

            getline(ss, nextColumn, ','); // #
            getline(ss, nextColumn, ','); // name
            player p;
            p.name = nextColumn;
            getline(ss, nextColumn, ','); // position
            getline(ss, nextColumn, ','); // age
            getline(ss, nextColumn, ','); // team
            getline(ss, nextColumn, ','); // games
            getline(ss, nextColumn, ','); // games started
            getline(ss, nextColumn, ','); // minutes played 
            getline(ss, nextColumn, ','); // fg
            getline(ss, nextColumn, ','); // fga
            getline(ss, nextColumn, ','); // fg%
            stringstream temp(nextColumn);
            double stat;
            temp >> stat;
            p.fgp = stat;
            getline(ss, nextColumn, ','); // 3 pointers
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p.three = stat;
            getline(ss, nextColumn, ','); // 3pa
            getline(ss, nextColumn, ','); // 3p%
            getline(ss, nextColumn, ','); // 2p
            getline(ss, nextColumn, ','); // 2pa
            getline(ss, nextColumn, ','); // 2p%
            getline(ss, nextColumn, ','); // efg%
            getline(ss, nextColumn, ','); // ft
            getline(ss, nextColumn, ','); // fta
            getline(ss, nextColumn, ','); // ft%
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p.ftp = stat;
            getline(ss, nextColumn, ','); // orbd
            getline(ss, nextColumn, ','); // drbd
            getline(ss, nextColumn, ','); // rebounds
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p.rebounds = stat;
            getline(ss, nextColumn, ','); // assist
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p.assists = stat;
            getline(ss, nextColumn, ','); // steal
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p.steals = stat;
            getline(ss, nextColumn, ','); // block
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p.blocks = stat;
            getline(ss, nextColumn, ','); // turnover
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p.turnovers = stat;
            getline(ss, nextColumn, ','); // fouls
            getline(ss, nextColumn, ','); // points
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p.points = stat;
            v.push_back(p);
        }
    }
    else {
        cout << "file didn't open" << endl;
    }

    return v;
}

void print_player(vector<player>& players, size_t i) {
    player p = players[i];
    cout << "name: " << p.name << "  points: " << p.points << "  fg%: " << p.fgp << "  assists: " << p.assists << "  3pt: " << p.three << "  blocks: " << p.blocks << "  boards: " << p.rebounds << " TO: " << p.turnovers << endl;
}

int main()
{
    vector<player> v = parseInput();
    print_player(v, 3);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
