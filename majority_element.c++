//question:

/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
  
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 
Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 
Follow-up: Could you solve the problem in linear time and in O(1) space? */

//______________________________________________________________________________________________________________________________________________________________________

//approach1:

//it can be done by brute force approach too by using two loops and maintaining the count then we wou d have a time complexity of o(n^2)
// here lets do it using the most common approach by using maps
//we will store the elements in the map and track the count of the elements how many times they are repeated and then return the majority element which is
//occured more than n/2 times.

int majorityelement(vector<int>&nums)
{
  unordered_map<int,int>mp;
  for(int i=0;i<nums.size();i++)
  {
    mp[nums[i]]++;
  }
  for(auto it:mp)
  {
    if(it.second>nums.size()/2)
    {
      return it.first;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//approach2:

//here we will have a element which is not intialised and the count intialised to 0
//in this if the count=0 then we will assign the element the value where the i is at and we will increase the count to 1
//if the next element matches that then we will increment the count
//if not then we will decrement the count
//at last we will traverse through the array and find the original count of the element if it is greater than n/2 then return that element

int majorityelement(vector<int>&nums)
{
  int e;
  int c=0;
  for(int i=0;i<nums.size();i++)
  {
    if(c==0)
    {
      e=nums[i];
      c=1;
    }
    else if(e==nums[i])
    {
      c++;
    }
    else
    {
      c--;
    }
  }
  int ct=0;
  for(int i=0;i<nums.size();i++)
  {
    if(e==nums[i])
    {
      ct++;
    }
  }
  if(ct>nums.size()/2)
  {
    return e;
  }
  return -1;
}

  
