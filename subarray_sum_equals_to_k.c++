//question:

/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
  
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 
Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107 */

//____________________________________________________________________________________________________________________________________________________________________________________________________________

//approach1:

//lets go with the brute force search first

int subarraysum(vector<int>&nums,int k)
{
int c=0;
  for(int i=0;i<nums.size();i++)
  {
    int ans=0;
    for(int j=i;j<nums.size();j++)
    {
      ans+=nums[j];
      if(ans==k)
      {
        c++;
      }
    }
  }
   return c;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//but here it takes o(n^2) time complexity so to optimise it we have to calculate the prefix sum and save it in the unorderedmap
//first we calculate the prefix sum and if the prefixsum is equal to the k then increase the count
//then check whether the prefix - the k value exists in the map. if exists then add the count o the prefixsum to the count.
//if not then add it to the map
//by doing this we will cutoff the extra value which ois making subarray not equal to k so we ed up getting the desired subarray.

int subarraysum(vector<int>&nums,int k)
{
  int prefix=0;
  int c=0;
  unordered_map<int,int>mp;
  for(int i=0;i<nums.size();i++)
  {
    prefix+=nums[i];
    if(prefix==k)
    {
      c++;
    }
    if(mp.find(prefix-k)!=mp.end())
    {
      c+=mp[prefix-k];
    }
    mp[prefix]++;
  }
  return c;
}
