//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<long long int> prev(sum + 1, 0);
        fill(prev.begin(), prev.end(), 0);
        
        for (int i = 0; i <= sum; i++) {
            if (i % coins[0] == 0) {
                prev[i] = 1;
            }
        }
        
        for (int i = 1; i < N; i++) {
            vector<long long int> curr(sum + 1, 0);
            fill(curr.begin(), curr.end(), 0);
            
            for (int j = 0; j <= sum; j++) {
                long long int a, b;
                a = b = 0;
                
                a = prev[j];
                if (j >= coins[i]) {
                    b = curr[j - coins[i]];
                }
                
                curr[j] = a + b;
            }
            prev = curr;
        }
        
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends