/* Binary Search Visualizer with Enhanced Visualization */

#include <bits/stdc++.h>
#include <thread>
using namespace std;

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

// ANSI color codes for highlighting
#define RESET   "\033[0m"
#define BOLDYELLOW "\033[1;33m"

// Clear the console screen
void clearScreen() {
    system(CLEAR);
}

// Print the current search range along with elements in range, highlighting the midpoint
void printSearchRange(const vector<int>& v, int l, int r, int mid) {
    cout << "Current search range: [" << l << ", " << r << ")\n";
    cout << "Elements in range: [";
    for (int i = l; i < r; i++) {
        if (i == mid)
            cout << BOLDYELLOW << v[i] << RESET;
        else
            cout << v[i];
        if (i != r - 1) cout << ", ";
    }
    cout << "]\n";
    cout << "Midpoint index: " << mid << ", value: " << BOLDYELLOW << v[mid] << RESET << "\n";
    cout << "---------------------------------------------\n";
}

// Conditions for binary search variants
bool isOkStandard(vector<int>& v, int x, int mid) {
    return x < v[mid];
}
bool isOkUpperBound(vector<int>& v, int x, int mid) {
    return x < v[mid];
}
bool isOkLowerBound(vector<int>& v, int x, int mid) {
    return x <= v[mid];
}

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int key;
    cout << "Enter the key: ";
    cin >> key;

    int option;
    cout << "Choose search type:\n";
    cout << "1. Standard Binary Search\n2. Upper Bound\n3. Lower Bound\nChoice: ";
    cin >> option;

    int l = 0, r = v.size();
    int delay = 2000;

    clearScreen(); // Start fresh

    switch(option) {
        case 1: {
            while (l < r) {
                int mid = (l + r) / 2;
                clearScreen();
                printSearchRange(v, l, r, mid);
                this_thread::sleep_for(chrono::milliseconds(delay));
                if (isOkStandard(v, key, mid))
                    r = mid;
                else
                    l = mid + 1;
            }
            clearScreen();
            if (l > 0 && v[l - 1] == key)
                cout << BOLDYELLOW << "Element found at index " << (l - 1) << ", value: " << v[l - 1] << RESET << "\n";
            else
                cout << BOLDYELLOW << "Element not found in the array." << RESET << "\n";
            break;
        }
        case 2: {
            while (l < r) {
                int mid = (l + r) / 2;
                clearScreen();
                printSearchRange(v, l, r, mid);
                this_thread::sleep_for(chrono::milliseconds(delay));
                if (isOkUpperBound(v, key, mid))
                    r = mid;
                else
                    l = mid + 1;
            }
            clearScreen();
            if (l < v.size())
                cout << BOLDYELLOW << "Upper bound index: " << l << ", value: " << v[l] << RESET << "\n";
            else
                cout << BOLDYELLOW << "Upper bound index: " << l << " (no element greater than key)" << RESET << "\n";
            break;
        }
        case 3: {
            while (l < r) {
                int mid = (l + r) / 2;
                clearScreen();
                printSearchRange(v, l, r, mid);
                this_thread::sleep_for(chrono::milliseconds(delay));
                if (isOkLowerBound(v, key, mid))
                    r = mid;
                else
                    l = mid + 1;
            }
            clearScreen();
            if (l < v.size())
                cout << BOLDYELLOW << "Lower bound index: " << l << ", value: " << v[l] << RESET << "\n";
            else
                cout << BOLDYELLOW << "Lower bound index: " << l << " (no element >= key)" << RESET << "\n";
            break;
        }
        default:
            cout << "Invalid option. Choose 1, 2, or 3.\n";
    }
}
