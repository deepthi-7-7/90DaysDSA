//question:

/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false */


//solution:

//this approach has one for loop and its time complexity is o(nlogn) as we use the sorting here
//first we need to sort the nums vector and loop through it and check whether the nums[i] is equal to its next number or not 
//if yes then return true, and if not then return false

bool contains_duplicate(vector<int>&nums)
{
  sort(nums.begin(),nums.end());
  for(int i=0;i<nums.size();i++)
  {
    if(nums[i]==nums[i+1])
    {
      return true;
    }
  }
  return false;
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

//solution2:

//the time complexity of this approach is o(n)
//here instead of sorting we use the unordered set. then we can check whether the value of num is already present in theset or not
//to do that we check if the count of the nums in the st is greater than 0 or not
//if greater then return true as duplicate is present , else add that num value to the set and return false


bool contains_duplicate(vector<int>&nums)
{
  unordered_set<int>st;
  for(num:nums)
    {
      if(st.count(num)>0)
      {
        return false;
      }
      st.insert(num);
    }
 return true;
}
    
