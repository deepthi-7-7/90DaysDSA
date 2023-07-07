//question:

/*Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.*/

//______________________________________________________________________________________________________________________________________________________________________________________________

//approach1:

//so if we take an array [1,2,3] now the subarrays are [1] [1,2] [1,2,3] [2] [2,3] [3]
//to achieve that we need to traverse through a loop using pinter i from 0 to size of array, now for next loop we start j pointer at where i pointer is to the size of teh aray
//now to print it we need to traverse the k pointer through another loop of range i to j

//as now we got the subarrays then if we want teh maximum subarray then then we need to calculate the sum of each subarray and find the maxof the subarrays

//timecomplexity is o(n^3) as we using 3 loops

int maxsubarray(vector<int>&nums)
{
  int maxi=INT_MIN;
  for(int i=0;i<nums.size();i++)
  {
    for(int j=i;j<nums.size();j++)
    {
      int currentsum=0;
      for(int k=i;k<=j;k++)
      {
        currentsum+=nums[k];
      }
      maxi=max(maxi,currentsum);
    }
  }
return maxi;
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//approach2:
//we can optimise the above code by just removing the third loop where we can add the current sum in the 2nd loop itself where j traverse through the array
//timecomplexity is o(n^2) as only two loops will be used in this approach

int maxsubarray(vector<int>&nums)
{
  int maxi=INT_MIN;
  for(int i=0;i<nums.size();i++)
  {
    int s=0;
    for(int j=i;j<nums.size();j++)
    {
      s+=nums[j];
      maxi=max(maxi,s);
    }
  }
  return maxi;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//approach3:

//the timecomplexity is o(n) as only one loop

//this approach is also called as kadens algorithm
// in this first we take the amximum as the 1st value of the array
// then we intialise sum as 0
// then we loop through the array and when we get the sum as the previous sum + the new value of the nums
//if the newsum<0 then make it equal to 0 as we only looking for maximum value 
//ebvery while update the maxi value where we compare max btw suma nd teh maxi

int maxsubarray(vector<int>&nums)
{
  int maxi=a[0];
  int s=0;
  for(int i=0;i<nums.size();i++)
  {
    if(s<0)
    {
      s=0;
    }
    s+=nums[i];
    maxi=max(maxi,s);
  }
return maxi;
}

    
