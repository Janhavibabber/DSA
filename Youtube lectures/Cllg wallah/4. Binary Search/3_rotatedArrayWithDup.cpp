#include<iostream>
#include<vector>
using namespace std;

bool binarySearch(vector<int> &nums, int target)
{
    int lo = 0, hi = nums.size() - 1;
    if (nums[lo] == target || nums[hi] == target)
        return true;

    while(lo<=hi){
        while (nums[lo] == nums[hi] && lo < hi){
            lo++;
            hi--;
        }

        int mid = lo+(hi - lo) / 2;
        if(nums[mid] == target)
            return true;
        if(nums[lo]<=nums[mid]){
            if(nums[lo]<target && target<=nums[mid]){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        else{
            if(nums[mid]<=target && target<=nums[hi]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    if(binarySearch(nums, k)){
        cout << "Element found";
    }
    else{
        cout << "Element not found";
    }
    return 0;
}