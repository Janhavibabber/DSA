#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    // unordered_map<int, int> basket;
    int i = 0, j = 0, ans = 0;
    int k = 2;
    vector<int> arr(9, 0);

    // for(int x=0; x<fruits.size(); x++){
    //     arr[fruits[i]]++;
    // }

    // cout<<256-zeros;

    while (j < fruits.size())
    {
        arr[fruits[j]]++;

        int zeros = count(arr.begin(), arr.end(), 0);
        // cout<<9-zeros<<endl;

        if (9 - zeros < k)
        {
            j++;
        }
        else if (9 - zeros == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (9 - zeros > k)
        {
            arr[fruits[i]]--;
            i++;
            j++;
        }
    }
    if(ans == 0)
        return -1;
    else
        return ans;
}

// class Solution
// {
// public:
//     int totalFruit(vector<int> &str)
//     {
//         if (str.size() == 1)
//             return 1; // edge case

//         int n = str.size();
//         int i = 0, j = 0, res = INT_MIN;
//         unordered_map<int, int> mp;

//         while (j < n)
//         {
//             mp[str[j]]++; // calculation
//             if (mp.size() < 2)
//             { // condition 1
//                 j++;
//             }
//             if (mp.size() == 2)
//             { // conditon 2
//                 res = max(res, j - i + 1);
//                 j++;
//             }
//             else if (mp.size() > 2) // condition 3
//             {
//                 while (mp.size() > 2)
//                 {
//                     mp[str[i]]--;
//                     if (mp[str[i]] == 0)
//                     {
//                         mp.erase(str[i]);
//                     }
//                     i++;
//                     // if(mp.size() == 2)
//                     // res = max(res, j-i+1);
//                 }
//                 j++;
//             }
//         }
//         if (mp.size() == 1)
//         {
//             auto it = mp.begin();
//             return it->second;
//         }

//         return res;
//     }

//     @amiyaranjanbarik5990 1 year ago
//         Problem Description : https : // leetcode.com/problems/fruit-into-baskets/
//                                       Problem solution : int totalFruit(vector<int> &fruits)
//     {
//         int i = 0, j = 0, ans = 0;
//         unordered_map<int, int> mp;
//         while (j < fruits.size())
//         {
//             mp[fruits[j]]++;
//             if (mp.size() <= 2)
//             {
//                 ans = max(ans, j - i + 1);
//                 j++;
//             }
//             else
//             {
//                 while (mp.size() > 2)
//                 {
//                     mp[fruits[i]]--;
//                     if (mp[fruits[i]] == 0)
//                     {
//                         mp.erase(fruits[i]);
//                     }
//                     i++;
//                 }
//                 j++;
//             }
//         }
//         return ans;
//     }

// #include <bits/stdc++.h>
//     using namespace std;

//     int pickToys(string s)
//     {
//         int i = 0, j = 0;
//         int maxi = INT_MIN;
//         unordered_map<char, int> mp;

//         while (j < s.size())
//         {
//             // calculation
//             mp[s[j]]++;

//             // cond < 2
//             if (mp.size() < 2)
//             {
//                 j++;
//             }

//             // cond == 2
//             else if (mp.size() == 2)
//             {
//                 maxi = max(maxi, j - i + 1);
//                 j++;
//             }

//             // cond > 2
//             else if (mp.size() > 2)
//             {
//                 while (mp.size() > 2)
//                 {
//                     mp[s[i]]--;
//                     if (mp[s[i]] == 0)
//                     {
//                         mp.erase(s[i]);
//                     }
//                     i++;
//                 }
//                 j++;
//             }
//         }
//         return maxi;
//     }

    int main()
    {
        vector<int> fruits = {0, 5, 9, 0, 9, 9, 0, 0, 2, 7};
        cout << totalFruit(fruits) << endl;
        return 0;
    }

// #include <bits/stdc++.h>
//     using namespace std;

//     // This function returns max toys that can be bought as a substring of given string having atmost k types of toys
//     // Time complexity - O(n) and space complexity - O(k)
//     int maxToys(string &toys, int k)
//     {
//         unordered_map<char, int> mp; // to store count of different types of toys selected

//         int n = toys.length(), ans = 0;

//         int i = 0, j = 0; // sliding window

//         // traversing string
//         while (j < n)
//         {
//             // calculation part
//             if (mp.find(toys[j]) == mp.end())
//                 mp[toys[j]] = 1;
//             else
//                 mp[toys[j]]++;

//             // conditions met
//             if ((int)mp.size() <= k)
//             {
//                 ans = max(ans, j - i + 1);
//             }
//             // max different types of toys condition violated
//             else
//             {
//                 while ((int)mp.size() > k)
//                 {
//                     mp[toys[i]]--;
//                     if (mp[toys[i]] == 0)
//                         mp.erase(toys[i]);

//                     i++;
//                 }
//             }

//             j++;
//         }

//         return ans;
//     }

//     int main()
//     {
//         string toys = "abbcba";
//         int k = 2;

//         cout << "Max toys that can be bought -> " << maxToys(toys, k) << endl; // ans is bbcb

//         return 0;
//     }

// #include <bits/stdc++.h>
//     using namespace std;
//     int maximumToys(string s, int k)
//     {
//         int i = 0;
//         int j = 0;
//         int ans = 0;
//         map<char, int> mp;
//         int sz = s.length();
//         while (j < sz)
//         {
//             mp[s[j]]++;
//             if (mp.size() <= k)
//             {
//                 ans = max(ans, j - i + 1);
//                 j++;
//             }
//             else if (mp.size() > k)
//             {
//                 while (mp.size() > k)
//                 {
//                     mp[s[i]]--;
//                     if (mp[s[i]] == 0)
//                         mp.erase(s[i]);
//                     i++;
//                 }
//                 j++;
//             }
//         }
//         return ans;
//     }
//     int main()
//     {
//         string s = "abaccab";
//         int k = 2;
//         cout << maximumToys(s, k);
//         return 0;
//     }