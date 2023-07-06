//question

/* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

The task is to find the configuration of two lines that maximizes the amount of water the container can hold. In other words, 
we need to find two lines such that the distance between them (along the x-axis) is maximized while ensuring that the height of the shorter line is also maximized.

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.*/

//___________________________________________________________________________________________________________________________________________________________________________

//approach:

//two pointer approach
//intialise the answer as 0
//first we take two pointers one is left which is equal to 0 and other is right which is equal to size of teh array-1
//while left is less tahn right we take the minimum from the two pointers and do that minimum pointer * the distance between the left and right pointer
// store that in the variable area
//now store the max in btw the area and the answer in the answer
// then check if height[left]>height[right] if yes do right-- else do left++
//return the answer


int maxwater(vector<int>&height)
{
  int left=0;
  int right=height.size()-1;
  int ans=0;
  while(left<right)
  {
    int area=min(height[left],height[right])*(right-left);
    ans=max(area,ans);
    if(height[left]<height[right])
    {
      left++;
    }
    else
    {
      right--;
    }
  }
  return ans;
}
