//question:

/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:
e expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.*/

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//solution1:

int remove_duplicates(vector<int>&nums)
{
  vector<int>redult;
  set<int>st;
  for(int i=0;i<nums.size();i++)
  {
    if(st.count(nums[i])>0)
    {
      continue;
    }
    else
    {
      st.insert(nums[i]);
      result.push_back(nums[i]);
    }
  }
  nums=result;
  return result.size();
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//solution2:

//the time compelxity is O(n) and space complexity is also O(n)as here the set is used.

int remove_duplicates(vector<int>&nums)
{
  set<int>st(nums.begin(),nums.end());
  nums.assign(st.begin(),st.end());
  return nums.size();
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//solution3:

//here we use the intialise the j value as 1 and if the value at the current value at nums is not equal to previous value tehn we add that value to the nums[j] and increment teh j value
// here the time complexity is O(n) and space complexity is O(1)

int remove_duplicates(vector<int>&nums)
{
  int j=1;
  for(int i=1;i<nums.size();i++)
  {
    if(nums[i]!=nums[i-1])
    {
      nums[j]=nums[i];
      j++;
    }
  }
  return j;
}
