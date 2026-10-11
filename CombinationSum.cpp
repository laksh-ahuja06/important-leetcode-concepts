#include <iostream>
using namespace std;

vector<vector<int>> answer;

void backtrack (int start, vector<int> currentCombination,
                    vector<int>& candidates, int sum, int target) {
        if (sum == target) {
            answer.push_back (currentCombination); 
            return;
        }
        if (sum > target) return;
        for (int i = start; i < candidates.size (); i++) {
            int currentCandidate = candidates[i];
            currentCombination.push_back (currentCandidate);
            backtrack (i, currentCombination, candidates, sum + currentCandidate, target);
            currentCombination.pop_back ();
        }
    }

int main () {
    vector<int> candidates = {1,2,4,5,8};
    int target = 8;
    vector<int> currentCombination;
    backtrack (0, currentCombination, candidates, 0, target);
    return answer;
}

