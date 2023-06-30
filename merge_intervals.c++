//question:

/* Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].*/

//_____________________________________________________________________________________________________________________________________________________________________


//solution:

//here first we assign a result vector which contains vector in it. then we need to sort the orignal intervals. and intilise temp to the first vector in the interval.
//now for each interval check whether the first value of the second vector is greater then the second value of temp
//if not thn make the second value of the temp as the maximum value in between the second value of the it and teh second value of the temp.
//if yes then we need to push back the temp value into the result and we make the next it as the temp. and finally we push back the last vector of the intervals to result

//the time complexity is o(nlogn) for sorting and o(n) for the loop so it gives o(nlogn)

vector<vector<int>> merged_intervals(vector<vector<int>>&intervals)
{
  vector<vector<int>>result;
  sort(intervals.begin(),intervals.end());
  if(intervals.size()==0)
  {
    return result;
  }
  vector<int>temp=intervals[0];
  for(auto it:intervals)
  {
    if(it[0]<=temp[1])
    {
      temp[1]=max(temp[1],it[1]);
    }
    else
    {
      result.push_back(temp);
      temp=it;
    }
  }
  result.push_back(temp);
  return result;
}
