//question:

/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.*/


//_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


//solution1:

//it takes the time complexity of O(n^2) as it takes two for loops and space complexity is o(n)

//as we notice here they said duplicates must not be there so it is better to use the sets
//sets stores every element in an sorted order and also doesnot allows the duplicate elements
//then we also create the result vector to store the result
//now we sort the nums vector and we loop through this vector
//now intialise the left as i+1 and right as nums.size()-1
//and check whether the nums[i]+nums[left]+nums[right]=0 , if yes then insert these three values inside the set and increment the left and decrement the right
//if the sum of those three is less then the 0 then increment the left, if sum is greater than 0 then decrement the right
// atlast using for loop iterate through the set using an auto iterate and push them into the result vector and return the result


vector<int>sumof(vector<int>&nums,int target)
{
  vector<vector<int>>result;
  set<vector<int>>st;
  sort(nums.begin(),nums.end());
  for(int i=0;i<nums.size()-1;i++)
  {
    int left=i+1;
    int right=nums.size()-1;
    int sum=nums[i]+nums[left]+nums[right];
    if(sum==0)
    {
      st.insert({nums[i],nums[left],nums[right]});
      left++;
      right--;
    }
    else if(sum<0)
    {
      left++;
    }
    else
    {
      right--;
    }
  }
  for(auto it:st)
  {
    result.push_back(st);
  }
return result;
}
