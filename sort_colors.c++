//question:

/* Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red,
white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2] */

//_________________________________________________________________________________________________________________________________________________________________________________________

//approach:

//as they mentioned no sorting function should be used we can use the dutch national flag algorithm
//basically this algo have three pointers low,high,mid where low=0,mid=0;high=size of the array-1
//we will iterate the mid pointer through the array
//if the value at mid=0 then we need to swap the low and the mid value and then increment both low and mid to make sure to push all the 0's to the start 
//if its equal to 1 then we just increment the low
//if it equals to 2 then swap the high value and mid value and decrement the high to make sure that all the 2s go to the end 
//this makes all the 0s to go before low and all 2s go after high and 1s remain in midddle 
//this loop continues until the mid<=high once mid crossed high that means the arrray is sorted

void colors(vector<int>&nums)
{
  int l=0,m=0,h=nums.size()-1;
  while(m<=h)
  {
    if(nums[m]==0)
    {
      swap(nums[m],nums[l]);
      l++;
      m++;
    }
    else if(nums[m]==1)
    m++;
    else
    {
      swap(nums[m],nums[h]);
      h--;
    }
  }
}
