//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(int idx, int sum, vector<int> &arr, vector<int> &ans, int N)
    {
        //basecase
        if(idx == N){
            ans.push_back(sum);
            return;
        }
        
        //case 1 solve then remaining portion will take care recursion
        
        //pick the element
        solve(idx+1, sum+arr[idx], arr, ans, N);
        
        //neglect the element
        solve(idx+1, sum, arr, ans, N);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        int idx = 0, sum = 0;
        solve(idx, sum, arr, ans, N);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends