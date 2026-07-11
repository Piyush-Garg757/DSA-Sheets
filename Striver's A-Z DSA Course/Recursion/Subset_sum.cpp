/*Subset Sum Problem

Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum.

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.

Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.*/

class Solution {
	public:
	bool ans(vector<int>& arr, int sum, int n, int idx, int curr_sum)
	{
		if (curr_sum == sum)
			return true;
		if (idx == n || curr_sum>sum)
			return false;
		if (ans(arr, sum, n, idx + 1, curr_sum + arr[idx]))
			return true;
		if (ans(arr, sum, n, idx + 1, curr_sum))
			return true;
		return false;
	}
	bool isSubsetSum(vector<int>& arr, int sum) {
		// code here
		int n = arr.size();
		int idx = 0;
		int curr_sum = 0;
		return ans(arr, sum, n, idx, curr_sum);
	}
};
// TC - O(2^n)  SC - O(n)