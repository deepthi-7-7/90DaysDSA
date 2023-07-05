//question:

/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.*/

//_________________________________________________________________________________________________________________________________________________________________________

//approach1:

//first we can find the minimum value using the for loop and min function.
//before entering the loop you need to intialise the maxi value as 0 so that if the mini is the alst element of the array then to return 0 as the profit
//so in the loop we need to check if the current element is greater then the min right after finding the min
//if it is greater then we need to find the maxi by comparing the max in btw the maxi and the current element-the mini and update the maxi value
//finally return the maxi value

int maxprofit(vectior<int>&prices)
{
  int mini=INT_MAX;
  int maxi=0;
  for(int i=0;i<prices.size();i++)
  {
    mini=min(mini,,prices[1];
    if(prices[i]>mini)
    {
      maxi=max(maxi,prices[i]-maxi);
    }
  }
return maxi;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//approach2:

//we can use dp approach so that we can reduce the space complexity
//here the timecomplexity is o(n) and space complexity is o(1)


int maxprofit(vector<int>&prices)
{
  int mini=prices[0];
  int maxi=0;
  for(int i=0;i<prices.size();i++)
  {
    int cost=prices[i]-mini;
    maxi=max(cost,maxi);
    mini=min(mini,price[i]);
  }
  return maxi;
}
