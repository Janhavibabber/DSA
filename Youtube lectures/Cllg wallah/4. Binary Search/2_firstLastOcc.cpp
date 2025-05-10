#include<bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    int res = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] >= target)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}

int lastOcc(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    int res = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] > target)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}


int main()
{
    int n, target;
    cin>>n >> target;

    vector<int> nums;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }

    // code 2: lower bound and upper bound logic
    vector<int> ans;
    int lowerBound = firstOcc(nums, target);
    if (lowerBound < nums.size() && nums[lowerBound] == target)
    {
        int upperBound = lastOcc(nums, target);
        ans.push_back(lowerBound);
        ans.push_back(upperBound - 1);
    }
    else
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    cout<<ans[0]<<" "<<ans[1]<<endl;


    return 0;
}