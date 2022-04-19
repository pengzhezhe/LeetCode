#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        unordered_map<string, int> frequencies;
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        int maxCount = 0;
        string maxWord = "";
        string word;
        for (int i = 0; i <= paragraph.size(); i++) {
            if (isalpha(paragraph[i])) {
                word.push_back(tolower(paragraph[i]));
            } else if (word.size() > 0) {
                if (!bannedSet.count(word)) {
                    frequencies[word]++;
                    if (frequencies[word] > maxCount) {
                        maxCount = frequencies[word];
                        maxWord = word;
                    }
                }
                word = "";
            }
        }
        return maxWord;
    }
};

int main() {
    Solution solution = Solution();
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned{"hit"};
    cout << solution.mostCommonWord(paragraph, banned);
    return 0;
}