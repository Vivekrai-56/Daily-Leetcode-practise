//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
    sort(arr,arr+n);
    int lastSmaller = INT_MIN;
    int count =0;
    int longest =1;
    for(int i=0;i<n;i++){
        if(arr[i]-1 == lastSmaller){
            count += 1;
            lastSmaller = arr[i];
        }
        else if(lastSmaller != arr[i]){
            count = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest,count);
    }

    return longest;
      
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends