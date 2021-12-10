//
// Created by pzz on 2021/12/10.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
private:
    vector<string> result;
    unordered_map<string, map<string, int>> targets;

    bool backtracing(int ticketsNum) {
        if (result.size() == ticketsNum + 1)
            return true;

        for (pair<const string, int> &target: targets[result.back()]) {
            if (target.second <= 0) {
                continue;
            }
            
            result.push_back(target.first);
            target.second--;
            if (backtracing(ticketsNum))
                return true;
            target.second++;
            result.pop_back();
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        targets.clear();
        for (vector<string> &vec: tickets) {
            targets[vec[0]][vec[1]]++;
        }
        result.push_back("JFK");
        backtracing(tickets.size());
        return result;
    }
};

int main() {
    return 0;
}