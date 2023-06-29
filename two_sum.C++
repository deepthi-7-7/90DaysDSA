//Question:

//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.

/*Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]*/


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

//solution1:

//This approach takes the time complexity of O(n2) so this is not an optimal search
//But this is the first thought that came in my mind when i read the question
#include<bits/stdc++.h>
using namespace std;
vector<int>twosum(vector<int>&nums,int target)
{
  vector<int>result;
  for(int i=0;i<nums.size()-1;i++)
  {
    for(int j=i+1;j<nums.size();j++)
    {
      if(nums[i]+nums[j]==target)
      {
        result.push_back(i);
        result.push_back(j);
      }
    }
  }
return result;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

//solution2:

//This approach takes the tiem complexity of O(nlogn). This approach is optimised than the first approach.
//In this first we copy the anums array and sort it
//we now intialise left as 0 and right as the size of the sorted array-1
//now we loop trough the array until left<right and add the left and the right. mow store the occored value in some variable called sum
//now checjk whether it matches the target. if yes then loop through the original nums array and push into the result vector if you find the both left and right in the array and break the loop when result size=2
//if sum<target then do left++ and if sum>target do right--

vector<int>twosum(vector<int>&nums,int target)
{
  vector<int>sortednums=nums;
  sort(nums.begin(),nums.end());
  int left=0;
  int right=sortednums.size()-1;
  while(left<right)
  {
    int sumy=sortednums[left]+sortednums[right];
    if(sumy==target)
    {
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]==sortednums[left]
        {
          result.push_back(i);
        }
        else if(nums[i]==sortednums[right]
        {
          result.push_back(i);
        }
        if(result.size()==2)
        {
          break;
        }
      }
      return result;
    }
    else if (sumy<target)
    {
      left++;
    }
    else
    {
      right--;
    }
  }
return {};
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//This approach is teh optimal approach. This one takes O(n) time complexity
//create an unordered map and loop through the nums vector
//now find whether the target-nums[i] i.e, the compliment of nums[i] is present in the map or it using find. 
//if it is present it will give some value if not it will give the mp.end(). 
//if it is present then return the values that is the number and its compliment i.e, mp[target-nums[i]],i 
//if the value is not present then make mp[nums[i]]=i

vector<int>sumof(vector<int>&nums,int target)
{
  unordered_map<int,int>mp;
  for(int i=0;i<nums.size();i++)
  {
    if(find(mp[target-nums[i]])==mp.end())
    {
      return {mp[target[nums[i]],i};
    }
      mp[nums[i]]=i;
  }
return {-1,-1};
}
