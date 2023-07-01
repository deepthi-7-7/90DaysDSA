//question:

/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5 */

//_______________________________________________________________________________________________________________________________________________________________________________________

//solution1: 

//first lets do it by using the sorting technique

int findkthelement(vector<int>&nums,int k)
{
  sort(nums.begin(),nums.end());
  return nums[nums.size()-k];
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//solution2:

//as in the question tehy said not to use the sorting method 
