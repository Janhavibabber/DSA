//To count the total no. of occurences an element have in the sorted array
#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>&nums, int target, string find){
    int start = 0;
    int end = nums.size() - 1;
    int ans = -1;

    while(start<=end){
        int mid = start + (end - start)/2;
        if(target < nums[mid]){
            end = mid-1;
        }
        else if(target>nums[mid]){
            start = mid +1;
        }
        else{
            ans = mid;
            // count occurences logic
            if(find == "FIRST"){
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
    }
    return ans;
}


int count(vector<int>& nums, int target){
    int first = search(nums, target, "FIRST");
    int Last = search(nums, target, "LAST");

    int res = Last - first + 1;
    return res;
}

int main()
{
    int n,target;
    cin >> n;
    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << "Enter the element to be searched: ";
    cin >> target;

    cout<< count(nums, target);
    return 0;
}