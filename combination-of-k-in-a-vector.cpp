#include <iostream>
#include <vector>
using namespace std;

bool nextCombo (vector<int>& ps, int n, int k) {

    for (int i = 1; i <= k; i++) {

        if (ps[k - i] < n - i) {

            ps[k - i]++;

            for (int j = i - 1; j > 0; j--) {
                ps[k - j] = ps[k - j - 1] + 1;
            }

            return true;
        }
    }

    return false;
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};

    int n = arr.size();
    int k = 4;  // combination size

    vector<int> ps(k);

    for (int i = 0; i < k; i++) {
        ps[i] = i;  // ps[i] stores the indices
    }

    do {

        for (int i = 0; i < k; i++) {
            cout << arr[ps[i]] << " ";  // arr[ps[i]] -> ps[i] creates all the combination of k indices
        }

        cout << '\n';

    } while (nextCombo(ps, n, k));

    return 0;
}
