#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 0, 0},
        {1, 1, 0},
        {0, 1, 0}
    };

    int rows = matrix.size();
    int cols = matrix[0].size();

    // Create a matrix to store the number of neighbours
    vector<vector<int>> neighborCount(rows, vector<int>(cols, 0));

    // Visit every index in the matrix
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {

            // Check all 8 possible directions
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {

                    // Skip the current element itself
                    if (dr == 0 && dc == 0)
                        continue;

                    int newRow = r + dr;
                    int newCol = c + dc;

                    // Check whether the neighbour is inside the matrix
                    if (newRow >= 0 && newRow < rows &&
                        newCol >= 0 && newCol < cols &&
                        matrix[newRow][newCol] == 1) {  // If the neighbour is 1; count++ (save it in neighborCount 

                        neighborCount[r][c]++;
                    }
                }
            }
        }
    }

    // Print the original matrix
    cout << "Original Matrix:\n";

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cout << matrix[r][c] << " ";
        }
        cout << "\n";
    }

    // Print the number of neighbours for each index
    cout << "\nNumber of Neighbours:\n";

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cout << neighborCount[r][c] << " ";
        }
        cout << "\n";
    }

    // Print index, value and number of neighbours
    cout << "\nDetails:\n";

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cout << "Index (" << r << ", " << c << ")"
                 << " -> Value: " << matrix[r][c]
                 << ", Neighbours: " << neighborCount[r][c]
                 << "\n";
        }
    }

    return 0;
}

