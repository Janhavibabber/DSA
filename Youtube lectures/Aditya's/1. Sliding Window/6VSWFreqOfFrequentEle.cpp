//Frequency of most frequent element
// 1st Method : -Two Pointers / Sliding Window🔥
// Intuition 🚀 The goal of the problem is to find the maximum frequency of an element in an array after performing certain operations.The operations involve adding or
// subtracting a given value k to elements in the array.To achieve this,
// the code uses a sliding window approach.
// The intuition behind the sliding window is to maintain a valid
// subarray(window) that satisfies the given condition. By adjusting the window based on the sum of elements and the condition, the code efficiently explores different subarrays to find the maximum frequency.

// Approach 🚀
// Sorting:

// The array nums is sorted in ascending order. Sorting is crucial for the sliding window approach, as it allows us to efficiently adjust the window based on the current element.
// Sliding Window:

// Two pointers, left and right, are used to define the subarray. The right pointer is advanced to include elements in the current subarray, while the left pointer is adjusted to maintain a valid subarray.
// Subarray Sum and Adjustments:

// currentSum represents the sum of elements in the current subarray. The code adds the current element (nums[right]) to this sum.
// A while loop checks if the current subarray violates the condition (sum + k < nums[right] * length). If it does, the code adjusts the subarray by removing the leftmost element and updating the sum. This ensures that the condition is satisfied.
// Update Maximum Frequency:

// The maximum frequency (maxFrequency)
// is updated by comparing it with the length of the current subarray(right - left + 1).The length represents the number of elements in the valid subarray.Return Result :

//     The final result is the maximum frequency found after processing the entire array.In summary,
//     the approach involves efficiently exploring different subarrays using a sliding window and adjusting the window based on the sum of elements and the given condition.Sorting the array is a key step to simplify the sliding window process.The code efficiently finds the maximum frequency by maintaining a valid subarray and updating the frequency as the window moves through the array.

// ✒️Code
//     class Solution
// {
// public:
//     int maxFrequency(vector<int> &nums, int k)
//     {
//         int maxFrequency = 0; // Initialize the maximum frequency
//         long currentSum = 0;  // Initialize the current sum of the subarray elements

//         std::sort(nums.begin(), nums.end()); // Sort the array in ascending order

//         for (int left = 0, right = 0; right < nums.size(); ++right)
//         {
//             currentSum += nums[right]; // Include the current element in the subarray sum

//             // Check if the current subarray violates the condition (sum + k < nums[right] * length)
//             while (currentSum + k < static_cast<long>(nums[right]) * (right - left + 1))
//             {
//                 currentSum -= nums[left]; // Adjust the subarray sum by removing the leftmost element
//                 left++;                   // Move the left pointer to the right
//             }

//             // Update the maximum frequency based on the current subarray length
//             maxFrequency = std::max(maxFrequency, right - left + 1);
//         }

//         return maxFrequency;
//     }
// };
// Complexity 🚁
// 🏹Time complexity: O(n log n)
// The code sorts the array, which has a time complexity of O(n log n), where n is the length of the input array nums.
// The main loop iterates through each element in the sorted array once, so it has a time complexity of O(n), where n is the length of the input array.
// Overall, the dominant factor is the sorting operation, making the time complexity O(n log n).
// 🏹Space complexity: O(1)
// The space complexity is O(1) because the code uses a constant amount of extra space, regardless of the size of the input array. The additional space is used for variables like maxFrequency, currentSum, and loop variables (left and right), and it does not depend on the input size. Hence, the space complexity is constant.
// vote.jpg

// 2nd Method :- Sliding Window & Greedy🔥
// Intuition 🚀
// The goal of the problem is to find the maximum frequency of any element in a subarray after performing operations on the array. The operations involve adjusting the subarray by removing elements to minimize the difference between the product of the element and the length of the subarray and the sum of the subarray.

// Approach 🚀
// Counting Sort:

// The initial step involves sorting the array in non-decreasing order using counting sort. This step ensures that elements are processed in ascending order during the main iteration.
// Sliding Window:

// The code uses a sliding window approach with two pointers (start and i) to define the current subarray.
// start represents the leftmost index of the subarray, and i represents the rightmost index.
// Product and Sum Calculation:

// For each element in the sorted array, the code calculates the product of the element and the length of the current subarray (subarrayProduct = nums[i] * subarrayLength).
// It also maintains the sum of elements in the current subarray (subarraySum += nums[i]).
// Adjustment of Subarray:

// If the difference between the product and the sum of the subarray exceeds the given limit (k), the subarray is adjusted.
// The adjustment involves removing elements from the left of the subarray (subarraySum -= nums[start]) and updating the subarray length until the condition is satisfied.
// Update Maximum Frequency:

// The code updates the maximum frequency (maxFrequency)
// by comparing it with the length of the current subarray.The length of the subarray represents the frequency of the current element in the subarray.Iteration Through Array :

//     The iteration through the array continues until all elements are processed.Return Result :

//     The final result returned is the maximum frequency found after processing the entire array.Summary : The approach involves maintaining a sliding window and adjusting it as needed to satisfy the given condition.The code efficiently finds the maximum frequency by considering the product of elements and the length of the subarray,
//     with counting sort aiding in sorting the array initially.The sliding window adjusts to minimize the difference between the product and the sum of the subarray, ensuring an optimal solution to the problem.

// ✒️Code class Solution
// {
// public:
//     int maxFrequency(std::vector<int> &nums, int k)
//     {
//         countingSort(nums);        // Sort the array using counting sort
//         int start = 0;             // Start index of the current subarray
//         long long subarraySum = 0; // Sum of elements in the current subarray
//         int maxFrequency = 1;      // Initialize the maximum frequency to 1

//         // Iterate through the sorted array
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int subarrayLength = i - start + 1;                              // Length of the current subarray
//             long long subarrayProduct = (long long)nums[i] * subarrayLength; // Use long long to avoid overflow
//             subarraySum += nums[i];                                          // Add the current element to the subarray sum

//             // Adjust the subarray to satisfy the condition (product - sum <= k)
//             while (subarrayProduct - subarraySum > k)
//             {
//                 subarraySum -= nums[start];                            // Remove the leftmost element from the subarray
//                 start++;                                               // Move the start index to the right
//                 subarrayLength--;                                      // Decrease the length of the subarray
//                 subarrayProduct = (long long)nums[i] * subarrayLength; // Recalculate the product
//             }

//             // Update the maximum frequency based on the current subarray length
//             maxFrequency = std::max(maxFrequency, subarrayLength);
//         }

//         return maxFrequency; // Return the final result
//     }

// private:
//     // Counting Sort to sort the array in non-decreasing order
//     void countingSort(std::vector<int> &nums)
//     {
//         int maxElement = INT_MIN;

//         // Find the maximum element in the array
//         for (int num : nums)
//         {
//             maxElement = std::max(maxElement, num);
//         }

//         // Create an array to store the count of each element
//         std::vector<int> countMap(maxElement + 1, 0);

//         // Count the occurrences of each element in the array
//         for (int num : nums)
//         {
//             countMap[num]++;
//         }

//         int index = 0;

//         // Reconstruct the sorted array
//         for (int i = 0; i <= maxElement; i++)
//         {
//             while (countMap[i]-- > 0)
//             {
//                 nums[index++] = i;
//             }
//         }
//     }
// };
// Complexity 🚁
// 🏹Time complexity: O(N + K)
// Counting Sort (sorting step): O(N + K), where N is the length of the input array nums, and K is the range of values (maximum element in nums).

// Counting sort has a linear time complexity because it iterates through the input array once to count the occurrences of each element and then reconstructs the sorted array.
// Main Loop (sliding window): O(N), where N is the length of the input array nums.

// The main loop iterates through each element of the sorted array once.
// The overall time complexity is dominated by the counting sort step, making the total time complexity O(N + K).

// 🏹Space complexity: O(K)
// Counting Sort (sorting step): O(K), where K is the range of values (maximum element in nums).

// The space required for counting sort is proportional to the range of values in the input array.
// Other Variables: O(1).

// The space required for variables such as start, subarraySum, maxFrequency, etc., is constant and does not depend on the input size.
// The overall space complexity is O(K), where K is the range of values in the input array.

// Note: The space complexity of the counting sort step dominates the overall space complexity. If the range of values (K) is significantly smaller than the length of the input array (N), the space complexity can be considered linear (O(N)).

// vote.jpg

// 3rd Method :- Binary Search with Prefix Sum🔥
// The least efficient approach
// Intuition 🚀
// The problem requires finding the maximum frequency of an element in a subarray after performing certain operations. The operations involve changing the elements in the subarray to make the difference between the maximum and minimum elements within a specified limit (k). The provided solution tackles this problem using a binary search approach.

// Approach 🚀
// Sort the Array:

// The array is sorted in ascending order. Sorting simplifies the calculation of differences between adjacent elements.
// Calculate Differences and Prefix Sums:

// Differences between adjacent elements are calculated and stored in the differences array.
// Prefix sums of the differences are calculated and stored in the prefixSums array. This aids in efficiently computing the sum of differences in subarrays.
// Binary Search for Maximum Frequency:

// A binary search is employed to find the maximum frequency that satisfies the given conditions.
// The search space is narrowed down by adjusting the low and high pointers.
// isPossible Function:

// The isPossible function checks if it's possible to achieve a certain frequency with the allowed difference k.
// It initializes the times variable based on the frequency and the last element in the subarray.
// It iterates through the array, updating the times variable by considering the difference in prefix sums and new differences.
// The minimum times is tracked, and the function returns true if the minimum times is within the allowed difference k.
// Explanation of Binary Search:
// The binary search in this context is applied to find the maximum frequency efficiently. The search space is the potential frequencies that we can achieve. The isPossible function checks whether it's possible to achieve a given frequency with the allowed difference. The binary search updates the search space based on the result of this check until it finds the maximum frequency.

// Overall:
// The approach leverages sorting, prefix sums, and binary search to efficiently find the maximum frequency of an element in a subarray while considering the allowed difference. The isPossible function plays a crucial role in determining the feasibility of achieving a certain frequency. The binary search optimally explores the space of potential frequencies.

// ✒️Code
// class Solution
// {
// public:
//     int maxFrequency(std::vector<int> &nums, int k)
//     {
//         // Sort the array in ascending order
//         std::sort(nums.begin(), nums.end());

//         int length = nums.size();

//         // Calculate the differences between adjacent elements
//         std::vector<long> differences(length);
//         for (int i = 1; i < length; i++)
//             differences[i] = static_cast<long>(nums[i]) - static_cast<long>(nums[i - 1]);

//         // Calculate the prefix sums of the differences
//         std::vector<long> prefixSums(length);
//         for (int i = 1; i < length; i++)
//             prefixSums[i] = prefixSums[i - 1] + differences[i];

//         int low = 1, high = length;

//         // Binary search for the maximum frequency
//         while (low < high)
//         {
//             int mid = (high - low + 1) / 2 + low;

//             // Check if it's possible to achieve the given frequency with the allowed difference
//             if (isPossible(nums, differences, prefixSums, mid, k))
//                 low = mid;
//             else
//                 high = mid - 1;
//         }

//         return low;
//     }

// private:
//     // Function to check if it's possible to achieve the given frequency with the allowed difference
//     bool isPossible(const std::vector<int> &nums, const std::vector<long> &differences, const std::vector<long> &prefixSums, int freq, int k)
//     {
//         int length = differences.size();

//         long times = 0;

//         // Calculate the initial times based on the frequency and the last element in the subarray
//         for (int i = freq - 2; i >= 0; i--)
//             times += static_cast<long>(nums[freq - 1]) - static_cast<long>(nums[i]);

//         long minTimes = times;

//         // Iterate from freq-th element to the end of the array
//         for (int i = freq; i < length; i++)
//         {
//             // Update times by considering the difference in prefix sums and new differences
//             times = times - (prefixSums[i - 1] - prefixSums[i - freq]) + differences[i] * (freq - 1);
//             minTimes = std::min(minTimes, times);
//         }

//         // Check if the minimum times is within the allowed difference (k)
//         return minTimes <= static_cast<long>(k);
//     }
// };
// Complexity 🚁
// 🏹Time complexity: O(n log n)
// Sorting:

// The initial sorting of the array takes O(n log n) time, where n is the length of the array.
// Differences and Prefix Sums:

// Calculating differences and prefix sums involves iterating through the array once, which takes O(n) time.
// Binary Search:

// The binary search iterates log(n) times.
// isPossible Function:

// The isPossible function iterates through the array once, making it O(n).
// The overall time complexity is dominated by the sorting step, making it O(n log n).

// 🏹Space complexity: O(n)
// Differences and Prefix Sums:

// Additional space is used to store the arrays differences and prefixSums, each of size n. Therefore, the space complexity for these arrays is O(n).
// Other Variables:

// Other variables like low, high, mid, times, and minTimes use constant space.
// The overall space complexity is O(n) due to the additional arrays created for differences and prefix sums.

// Complexity
//     Time complexity : O(NlogN)
//                           Space complexity : O(1)
//                                                  Code
//                                              class Solution
// {
// public:
//     bool ifPossible(vector<int> nums, int k, int mid)
//     {
//         long long int cSum = 0;
//         for (int i = 0; i < mid; i++)
//         {
//             cSum += nums[i];
//         }
//         int l = 0;
//         int i = mid;

//         int t = (cSum + k) / mid;
//         if (t >= nums[i - 1])
//             return true;
//         while (i < nums.size())
//         {
//             cSum += nums[i];
//             cSum -= nums[l];
//             l++;
//             i++;
//             int t = (cSum + k) / mid;
//             if (t >= nums[i - 1])
//                 return true;
//         }
//         return false;
//     }
//     int maxFrequency(vector<int> &nums, int k)
//     {
//         sort(nums.begin(), nums.end());
//         int ans = 0;
//         int s = 1;
//         int e = nums.size();
//         while (s <= e)
//         {
//             int mid = (s + e) / 2;
//             if (ifPossible(nums, k, mid))
//             {
//                 ans = mid;
//                 s = mid + 1;
//             }
//             else
//                 e = mid - 1;
//         }

//         return ans;
//     }
// };



// Intuition
// Given an index i, if we treat nums[i] as target, we are concerned with how many elements on the left we can take. In the earlier approaches, we used a sliding window. In this approach, we will directly find the left-most index of these elements using binary search.
// Approach
// Algorithm
// Define a function check(i):
// Initialize the following integers:
// target = nums[i], the current target.
// left = 0, the left bound of the binary search.
// right = i, the right bound of the binary search.
// best = i, the best (furthest left) index that we can increment to target.
// While left <= right
// Calculate mid = (left + right) / 2.
// Calculate count = i - mid + 1.
// Calculate finalSum = count * target.
// Calculate originalSum = prefix[i] - prefix[mid] + nums[mid].
// Calculate operationsRequired = finalSum - originalSum.
// If operationsRequired > k, move left = mid + 1.
// Otherwise, update best = mid and right = mid - 1.
// Return i - best + 1.
// Sort nums.
// Create a prefix sum of nums.
// Initialize ans = 0.
// Iterate i over the indices of nums:
// Update ans with check(i) if it is larger.
// Return ans.

// Complexity
// Time complexity:
//   O(N⋅logN)
// Space complexity:
//   O(N)
// Code
// class Solution {
// public:
// int bs(int h,int x,int k,vector<long>& p)
// {
//     int l=0;
//     int high=h;
//     int ans=h;
//     while(l<high)
//     {
//         int mid=l+(high-l)/2;
//         long s=0;
//         if(mid==0)
//         {
//             s=p[h];
//         }
//         else
//          {
//              s=p[h]-p[mid-1];
//          }
//         long len=h-mid+1;
//         long total=len*x-s;
//         if(total<=k)
//         {
//             ans=min(ans,mid);
//             high=mid;
//         }
//         else
//         {
//             l=mid+1;
//         }
        
//     }
//     return ans;
// }
//     int maxFrequency(vector<int>& a, int k) {
        
//         int n=a.size();
//         vector<long> p(n,0);
//         sort(a.begin(),a.end());
//         p[0]=a[0];
//         for(int i=1;i<n;i++)
//           p[i]=a[i]+p[i-1];
//         int ans=1;

//         for(int j=n-1;j>0;j--)
//         {
//             int h=j;
//             int l=bs(h,a[j],k,p);
//             ans=max(ans,j-l+1);
//         }
//         return ans;
//     }
// };

// Intuition
//     Our goal is to identify a window in which we can adjust all its elements to the highest value present in that window.The objective is to select a window where the number of operations required to make all elements equal to the maximum value is less than the threshold k.Approach
//         Sort the vector in ascending order.Keep a variable to track the cumulative sum of all elements within the window,
//     along with maintaining the size of the window and the largest window size encountered so far(which will be the final answer).The window_size in incremented at each iteration.In order to make all elements within the window the largest, the required number of operations can be calculated as follows : number_of_operations = largest_in_window * window_size - window_sum.If the calculated number of operations exceeds the threshold value 'k', then it is necessary to reduce the window size.Complexity Time complexity : O(nlogn) O(nlogn) O(nlogn) Space complexity : O(1) O(1) O(1) Code class Solution
// {
// public:
//     int maxFrequency(vector<int> &nums, long k)
//     {
//         sort(nums.begin(), nums.end());

//         int pos = 0;
//         long result = 0;
//         long window_size = 0;
//         long window_sum = 0;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             window_sum += nums[i];
//             window_size = i - pos + 1;

//             while ((nums[i] * window_size - window_sum) > k)
//             {
//                 window_sum -= nums[pos++];
//                 window_size--;
//             }

//             result = max(result, window_size);
//         }
//         return result;
//     }
// };