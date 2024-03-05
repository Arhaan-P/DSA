#include <iostream>
using namespace std;

int main() {
    int a[10] = {11, 12, 19, 20, 22, 33, 40, 46, 50, 53}; // Initialize array
    int target, beg = 0, end = 9, mid = (beg + end) / 2; // Initialize variables for binary search

    cout << "Enter target: "; // Prompt user for target
    cin >> target; // Read target from user

    // Binary search algorithm
    while (a[mid] != target && beg <= end) {
        if (a[mid] < target) {
            beg = mid + 1; // Update lower bound
        } else {
            end = mid - 1; // Update upper bound
        }
        mid = (beg + end) / 2; // Update mid-point
    }

    // Check if target is found or not
    if (a[mid] == target) {
        cout << "Search successful, target found at position: " << mid + 1; // Print position if found
    } else {
        cout << "The number is not found "; // Print message if not found
    }

    return 0;
}
