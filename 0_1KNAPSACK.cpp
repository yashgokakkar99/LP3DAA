#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
    public:
    bool static comp(Item a,Item b)
    {
        return a.weight < b.weight;
    }
    int knapsack(int W, vector<Item> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int w=0;w<=W;w++)
            {
                if(arr[i-1].weight>=W)
                {
                    dp[i][w] = dp[i-1][w];
                }
                else{
                    dp[i][w] = max(dp[i][w],dp[i-1][w-arr[i-1].weight]+arr[i-1].value);
                }
            }
        }
        return dp[n][W];
    }
};

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int maxcap;
    cout<<"Enter maximum capacity : ";
    cin>>maxcap;
    vector<Item> arr(n);
    cout<<"Enter all items value and weight : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].value>>arr[i].weight;
    }
    cout<<"All items entered...";
    Solution object;
    int answer = object.knapsack(maxcap,arr);
    cout<<answer;
    return 0;
}
