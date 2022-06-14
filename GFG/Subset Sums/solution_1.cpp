// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void rec(vector<int> arr, int cur, int sum, vector<int>& res) {
        int n = arr.size();
        if (cur >= n) {
            res.push_back(sum);
            return;
        }
        
        rec(arr, cur + 1, sum + arr[cur], res);
        rec(arr, cur + 1, sum, res);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        rec(arr, 0, 0, res);
        
        return res;
    }
};

// { Driver Code Starts.
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
}  // } Driver Code Ends