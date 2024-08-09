#include <iostream>
#include <vector>
using namespace std;

// const int MOD = 1e9 + 7;

// int numDistinct(string S, string T) {
//     int n = S.length();
//     int m = T.length();
//     vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    
//     // Base case: transforming any prefix of S into an empty string T
//     for (int i = 0; i <= n; i++) {
//         dp[i][0] = 1;
//     }
    
//     // Fill the DP table
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             dp[i][j] = dp[i-1][j]; // Skip the current character of S
//             if (S[i-1] == T[j-1]) {
//                 dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
//             }
//         }
//     }
    
//     return dp[n][m];
// }

// int main() {
//     string S, T;
//     cin >> S >> T;
//     cout << numDistinct(S, T) << endl;
//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(int A, int B, vector<int> &C) {
    int M = C.size();
    vector<int> river(A, 0);
    int pos = 0; // Current position to place platforms
    int totalLength = 0; // Total length of all platforms
    
    // Calculate total length of all platforms
    for (int i = 0; i < M; i++) {
        totalLength += C[i];
    }

    // Calculate gaps between platforms to place them lexicographically smallest
    for (int i = 0; i < M; i++) {
        int platformLength = C[i];
        int remainingPlatforms = M - i - 1;
        int remainingLength = totalLength - platformLength;

        // Calculate minimum gap needed
        int minGap = max(0, A - (pos + totalLength));
        
        if (pos + platformLength + minGap > A) {
            return {-1}; // Not possible to place platforms within constraints
        }

        pos += minGap;
        
        // Place the platform
        for (int j = 0; j < platformLength; j++) {
            river[pos + j] = i + 1;
        }
        
        pos += platformLength;
        totalLength -= platformLength;
    }

    return river;
}

int main() {
    int A, B;
    cin >> A >> B;
    int M;
    cin >> M;
    vector<int> C(M);
    for (int i = 0; i < M; i++) {
        cin >> C[i];
    }

    vector<int> result = solve(A, B, C);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
