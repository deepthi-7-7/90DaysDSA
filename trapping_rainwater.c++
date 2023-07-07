//question:

/* Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9 */

//_________________________________________________________________________________________________________________________________________________________________________________________________________

//approach1:
//this is a bruteforce approach in this we first intialise left and right as the 0and the length of the vector-1
//then we will update the leftmax and rightmax in the loop where the left max is the max of the leftmax and the height of the left and same goes with the right
//then we delete the height of the left/ right block from the min btw the rightmax and left max 
//add this to the result and return it

int trappingwater(vector<int>&height)
{
  int left=0;
  int right=height.size();
  int leftmax=0;
  int rightmax=0;
  int result=0;
  while(left<right)
  {
    leftmax=max(leftmax,height[left]);
    rightmax=max(rightmax,height[rigth]);
    if(leftmax<rightmax)
    {
      result+=leftmax-height[left];
      left++;
    }
    else
    {
      result+=rightmax-height[right];
      right--;
    }
  }
  return result;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//approach2:
//in this we first compute the prefix max and the suffix max
// i.e, if we have the array as [0,1,0,2,1,0,1,3,2,1,2,1] then the prefix max array will give us [0,1,1,2,2,2,2,3,3,3,3,3] an the suffix max will give us [3,3,3,3,3,3,3,3,2,2,2,1]
//after that we will traverse the array and find the minimum in btw the leftmax and the rightmax at the particular index and delet the height at the index
//update the result and return the result value

int rainwater(vector<int>&height)
{
  int leftmax[height.size()-1], rightmax[height.size()-1];
  leftmax[0]=height[0];
  rightmax[height.size()-1]=height[height.size()];
  for(int i=1;i<height.size();i++)
  {
    leftmax[i]=max(leftmax[i-1],height[i]);
  }
  for(int i=height.size()-2;i>=0;i--)
  {
    rightmax[i]=max(rightmax[i+1],height[i]);
  }
  int result=0;
  for(int i=0;i<height.size();i++)
  {
    result+=min(leftmax[i],rightmax[i])-height[i];
  }
  return result;
}

