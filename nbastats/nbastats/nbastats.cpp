// nbastats.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<sstream>
#include<map>
#include<algorithm>
#include<iterator>

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
    bool operator<(player& p) {
        return name < p.name;
    }
};

struct sortByPoints {
    bool operator()(const player* p1, const player* p2)const {
        if (p1->points == p2->points) {
            return p1->name < p2->name;
        }
        return p1->points > p2->points;
    }
};
struct sortByBoards {
    bool operator()(const player* p1, const player* p2)const {
        if (p1->rebounds == p2->rebounds) {
            return p1->name < p2->name;
        }
        return p1->rebounds > p2->rebounds;
    }
};

struct sortByFGP {
    bool operator()(const player* p1, const player* p2)const {
        if (p1->fgp == p2->fgp) {
            return p1->name < p2->name;
        }
        return (p1->fgp > p2->fgp) && (p1->name != p2->name);
    }
};
struct sortByAssists {
    bool operator()(const player* p1, const player* p2)const {
        if (p1->assists == p2->assists) {
            return p1->name < p2->name;
        }
        return (p1->assists > p2->assists) && (p1->name != p2->name);
    }
};
struct sortByFTP {
    bool operator()(const player* p1, const player* p2)const {
        if (p1->ftp == p2->ftp) {
            return p1->name < p2->name;
        }
        return (p1->ftp > p2->ftp) && (p1->name != p2->name);
    }
};
struct sortByBlocks {
    bool operator()(const player* p1, const player* p2)const {
        if (p1->blocks == p2->blocks) {
            return p1->name < p2->name;
        }
        return (p1->blocks > p2->blocks) && (p1->name != p2->name);
    }
};
struct sortBySteals {
    bool operator()(const player* p1, const player* p2) const {
        if (p1->steals == p2->steals) {
            return p1->name < p2->name;
        }
        return (p1->steals > p2->steals) && (p1->name != p2->name);
    }
};
struct sortByThrees {
    bool operator()(const player* p1, const player* p2)const {
        if (p1->three == p2->three) {
            return p1->name < p2->name;
        }
        return (p1->three > p2->three) && (p1->name != p2->name);
    }
};
struct sortByTOs {
    bool operator()(const player* p1, const player* p2) const {
        return (p1->turnovers < p2->turnovers) && (p1->name != p2->name);
    }
};






vector<player *> parseInput() {
    ifstream ifs("players.txt");
    vector<player *> v;
    if (ifs.is_open()) {
        string line;
        while (getline(ifs, line)) {
            stringstream ss(line);
            string nextColumn;

            getline(ss, nextColumn, ','); // #
            getline(ss, nextColumn, ','); // name
            player* p = new player();
            p->name = nextColumn;
            getline(ss, nextColumn, ','); // position
            getline(ss, nextColumn, ','); // age
            getline(ss, nextColumn, ','); // team
            getline(ss, nextColumn, ','); // games
            int g = 0;
            stringstream gamestream(nextColumn);
            gamestream >> g;
            getline(ss, nextColumn, ','); // games started
            getline(ss, nextColumn, ','); // minutes played 
            getline(ss, nextColumn, ','); // fg
            getline(ss, nextColumn, ','); // fga
            getline(ss, nextColumn, ','); // fg%
            stringstream temp(nextColumn);
            double stat;
            temp >> stat;
            p->fgp = stat;
            getline(ss, nextColumn, ','); // 3 pointers
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p->three = stat;
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
            p->ftp = stat;
            getline(ss, nextColumn, ','); // orbd
            getline(ss, nextColumn, ','); // drbd
            getline(ss, nextColumn, ','); // rebounds
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p->rebounds = stat;
            getline(ss, nextColumn, ','); // assist
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p->assists = stat;
            getline(ss, nextColumn, ','); // steal
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p->steals = stat;
            getline(ss, nextColumn, ','); // block
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p->blocks = stat;
            getline(ss, nextColumn, ','); // turnover
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p->turnovers = stat;
            getline(ss, nextColumn, ','); // fouls
            getline(ss, nextColumn, ','); // points
            temp.clear();
            temp.str(nextColumn);
            temp >> stat;
            p->points = stat;
            if (g > 10) {
                v.push_back(p);
            }
        }
    }
    else {
        cout << "file didn't open" << endl;
    }

    return v;
}

void print_player(vector<player*>& players, size_t i) {
    player* p = players[i];
    cout << "name: " << p->name << "  points: " << p->points << "  fg%: " << p->fgp << "  assists: " << p->assists << "  3pt: " << p->three << "  blocks: " << p->blocks << "  boards: " << p->rebounds << " TO: " << p->turnovers << endl;
}

int main()
{
    vector<player*> v = parseInput();
    //print_player(v, 3);
    map<string, player*> playersbyname;
    map<player*, string, sortByPoints> points;
    map<player*, string, sortByAssists> assists;
    map<player*, string, sortByBlocks> blocks;
    map<player *, string, sortByBoards> boards;
    map<player *, string, sortByFGP> fgp;
    map<player *, string, sortByFTP> ftp;
    map<player *, string, sortBySteals> steals;
    map<player *, string, sortByThrees> threes;
    map<player *, string, sortByTOs> turnovers;
    map<string, double> scores;
    for (size_t i = 0; i < v.size(); ++i) {
        playersbyname.insert({ v[i]->name, v[i] });
        points.insert({ v[i], v[i]->name });
        assists.insert({ v[i], v[i]->name });
        blocks.insert({ v[i], v[i]->name});
        boards.insert({ v[i], v[i]->name });
        fgp.insert({ v[i], v[i]->name });
        ftp.insert({ v[i], v[i]->name });
        steals.insert({ v[i], v[i]->name });
        threes.insert({ v[i], v[i]->name });
        turnovers.insert({ v[i], v[i]->name });
        scores.insert({ v[i]->name, 0.0 });
    }

    auto pointsreplace = points.begin();
    advance(pointsreplace, 30);
    auto assistsreplace = assists.begin();
    advance(assistsreplace, 30);
    auto blocksreplace = blocks.begin();
    advance(blocksreplace, 30);
    auto boardsreplace = boards.begin();
    advance(boardsreplace, 30);
    auto fgpreplace = fgp.begin();
    advance(fgpreplace, 30);
    auto ftpreplace = ftp.begin();
    advance(ftpreplace, 30);
    auto stealsreplace = steals.begin();
    advance(stealsreplace, 30);
    auto threesreplace = threes.begin();
    advance(threesreplace, 30);
    auto tosreplace = turnovers.begin();
    advance(tosreplace, 30);
    // points
    for (pair<player*, string> p : points) {
        double tscore = (p.first->points - pointsreplace->first->points) / (points.begin()->first->points - pointsreplace->first->points);
        if (tscore < -0.1) {
            scores[p.second] += -0.1;
        }
        else {
            scores[p.second] += tscore;
        }
    }
    //assists
    for (pair<player*, string> p : assists) {
        double tscore = (p.first->assists - assistsreplace->first->assists) / (assists.begin()->first->assists - assistsreplace->first->assists);
        if (tscore < -0.1) {
            scores[p.second] += -0.1;
        }
        else {
            scores[p.second] += tscore;
        }
    }
    //blocks
    for (pair<player*, string> p : blocks) {
        double tscore = (p.first->blocks - blocksreplace->first->blocks) / (blocks.begin()->first->blocks - blocksreplace->first->blocks);
        if (tscore < -0.1) {
            scores[p.second] += -0.1;
        }
        else {
            scores[p.second] += tscore;
        }
    }
    // boards
    for (pair<player*, string> p : boards) {
        double tscore = (p.first->rebounds - boardsreplace->first->rebounds) / (boards.begin()->first->rebounds - boardsreplace->first->rebounds);
        if (tscore < -0.1) {
            scores[p.second] += -0.1;
        }
        else {
            scores[p.second] += tscore;
        }
    }
    // fgp
    for (pair<player*, string> p : fgp) {
        double tscore = (p.first->fgp - fgpreplace->first->fgp) / (fgp.begin()->first->fgp - fgpreplace->first->fgp);
        if (tscore < -0.1) {
            scores[p.second] += -0.1;
        }
        else {
            scores[p.second] += tscore;
        }
    }
    // ftp
    for (pair<player*, string> p : ftp) {
        double tscore = (p.first->ftp - ftpreplace->first->ftp) / (ftp.begin()->first->ftp - ftpreplace->first->ftp);
        if (tscore < -0.1) {
            scores[p.second] += -0.1;
        }
        else {
            scores[p.second] += tscore;
        }
    }
    // steals
    for (pair<player*, string> p : steals) {
        double tscore = (p.first->steals - stealsreplace->first->steals) / (steals.begin()->first->steals - stealsreplace->first->steals);
        if (tscore < -0.1) {
            scores[p.second] += -0.1;
        }
        else {
            scores[p.second] += tscore;
        }
    }
    // threes
    for (pair<player*, string> p : threes) {
        double tscore = (p.first->three - threesreplace->first->three) / (threes.begin()->first->three - threesreplace->first->three);
        if (tscore < -0.1) {
            scores[p.second] += -0.1;
        }
        else {
            scores[p.second] += tscore;
        }
    }
    // turnovers
  //  for (pair<player*, string> p : points) {
    //    double tscore = (p.first->points - pointsreplace->first->points) / (points.begin()->first->points - pointsreplace->first->points);
      //  if (tscore < -0.25) {
        //    scores[p.second] += -0.25;
       // }
       // else {
        //    scores[p.second] += tscore;
       // }
    //}
    multimap<double, string> scoresordered;
    for (auto it = scores.begin(); it != scores.end(); ++it) {
        scoresordered.insert({ it->second, it->first });
    }
    for (auto it = scoresordered.begin(); it != scoresordered.end(); ++it) {
        cout << it->second << ":  " << it->first << endl;
    }
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
