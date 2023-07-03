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
//but this might exceeds the time limit when more nums are given so it is bad in worst case

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

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

//approach2: instead we use the observation approach

//so here we randomly checks the prefix product and teh suffix product 
//if the number is 0 then update the prefix and suffix as 1 (as if its 0 tehn whole product becomes0)
//then find the maximum in the both suffix product and preix product and return it

int maxproduct(vector<int>&nums)
{
 int pmax=INT_MIN;
 int smax=INT_MIN;
 int preffix=1;
 int suffix=1;
 for(int i=0;i<nums.size();i++)
 {
  if(prefix==0)
  {
    prefix=1;
  }
  if(suffix==0)
  {
    suffix=1;
  }
  prefix*=nums[k];
  suffix*=nums[nums.size()-1-i];
  pmax=max(pmax,prefix);
  smax=max(smax,suffix);
 }
 int maxi=max(pmax,smax);
 return maxi;
}



