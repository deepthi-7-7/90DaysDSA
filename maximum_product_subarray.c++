//question:

/* Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6. */

//____________________________________________________________________________________________________________________________________________________________________________

//approach1:

//for this problem we can usually go through that 3 loops and 2 loops as we did for the maximum subarray problem 
//first lets see how does it work with the 3 loops 

int maxproduct(vector<int>&nums)
{
  int maxi=INT_MIN;
  for(int i=0;i<nums.size();i++)
  {
    for(int j=i;j<nums.size();j++)
    {
      int p=1;
      for(int k=i;k<=j;k++)
      {
        if(nums[k]==0)
        {
          p=1;
        }
        p*=nums[k];
      }
        maxi=max(maxi,p);
    }
  }
  return maxi;
}

