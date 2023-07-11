//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
     int findK(int a[MAX][MAX],int n,int m,int k)
    {
         int l=0,r=m-1,t=0,b=n-1;
         int cnt=0;
        while(l<=r && t<=b){
            
            for(int i=l;i<=r;i++){
                cnt++;
                if(cnt==k)return a[t][i];
            }t++;
            for(int i=t;i<=b;i++){
                cnt++;
                if(cnt==k)return a[i][r];
            }r--;
            for(int i=r;i>=l;i--){
                cnt++;
                if(cnt==k)return a[b][i];
            }b--;
            for(int i=b;i>=t;i--){
                cnt++;
                if(cnt==k)return a[i][l];
            }l++;
        }
        
        return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends