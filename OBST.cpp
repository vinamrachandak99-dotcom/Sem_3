#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to construct OBST and find its minimum expected cost
double optimalBST(const vector<double>& p, const vector<double>& q, int n) {
    vector<vector<double>> e(n + 2, vector<double>(n + 1, 0)); // expected cost
    vector<vector<double>> w(n + 2, vector<double>(n + 1, 0)); // probability sum

    // Base case initialization
    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    // Dynamic programming for chain lengths
    for (int l = 1; l <= n; l++) { // l = chain length
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            e[i][j] = 1e9; // initialize with large number
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            // try each key k as root
            for (int r = i; r <= j; r++) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) e[i][j] = t;
            }
        }
    }

    return e[1][n];
}

int main() {
    int n;
    cout << "Enter number of book IDs: ";
    cin >> n;

    vector<int> keys(n + 1);
    cout << "Enter " << n << " sorted keys:\n";
    for (int i = 1; i <= n; i++) cin >> keys[i];

    vector<double> p(n + 1), q(n + 1);
    cout << "Enter " << n << " probabilities of successful search:\n";
    for (int i = 1; i <= n; i++) cin >> p[i];

    cout << "Enter " << n + 1 << " probabilities of unsuccessful search:\n";
    for (int i = 0; i <= n; i++) cin >> q[i];

    double result = optimalBST(p, q, n);

    cout << fixed << setprecision(4);
    cout << "\nMinimum expected cost of OBST: " << result << endl;

    return 0;
}
