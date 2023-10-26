#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    bool static comp(Item a, Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, vector<Item> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end(), comp);

        int curWeight = 0;
        double finalvalue = 0.0;

        for (int i = 0; i < n; i++)
        {
            if (curWeight + arr[i].weight <= W)
            {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            else
            {
                int remain = W - curWeight;
                finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
                break;
            }
        }

        return finalvalue;
    }
};

int main()
{
    int n, weight;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight capacity: ";
    cin >> weight;

    vector<Item> arr(n);
    cout << "Enter the value and weight of each item:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }

    Solution obj;
    double ans = obj.fractionalKnapsack(weight, arr);
    cout << "The maximum value is " << setprecision(2) << fixed << ans << endl;

    return 0;
}
