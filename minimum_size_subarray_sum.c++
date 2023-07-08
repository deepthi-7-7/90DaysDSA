//question:

/*Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
  
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
  
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0  */

//_______________________________________________________________________________________________________________________________________________________________________

//approach:

//we can do sliding windows here
//take two pointers left and right now add the right until the sum >=the given target
//if it satisfies the condition then we need to check the next subarray so we run this checking in while loop here
//we calculate the minimum size of the subarray whose sum is >=target
//then we need to delete the left one and increment the left

int minimum_subarray(vector<int>&nums,int target)
{
  int l=0;
  int s=0;
  int res=INT_MAX;
  for(int r=0;r<nums.size();r++)
  {
    s+=nums[r];
    while(s>=target)
    {
      res=min(res,r-l+1);
      s-=nums[l];
      l++;
    }
  }
  if(res==INT_MAX)
  {
    return 0;
  }
  return res;
}
