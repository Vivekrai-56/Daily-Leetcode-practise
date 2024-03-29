//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	 bool helper(int i, int j, int n, int m, int k,vector<vector<char>>&grid, string &word, const auto& dir){

        while(i>=0 && j>=0 && i<n && j<m){
            if(grid[i][j]==word[k]){
                ++k;
                i=i+dir.first;
                j=j+dir.second;
                if(k==word.size()) return true;
            }else{
                return false;
            }
          
        }
        
        return false;
        
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> ans;
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<pair<int, int>> dirs={{-1, 0}, {-1, 1}, {0,1}, {1,1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
	    for(int i=0; i<n; ++i){
	        for(int j=0; j<m; ++j){
	            for(const auto& dir: dirs){
	                if(helper(i, j,n, m, 0, grid, word, dir)){
	                    ans.push_back({i,j});
	                    break;
	                }
	            }
	            
	        }
	    }
	    return ans;
	  
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends