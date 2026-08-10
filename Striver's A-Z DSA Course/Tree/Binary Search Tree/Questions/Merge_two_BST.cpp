/*Merge two BST 's

Given the roots r1 and r2 of two Binary Search Trees (BSTs), merge the elements of both trees into a single sorted array and return it.
The returned array should contain all the elements from both BSTs, including duplicate values if they are present.

Examples: 

Input: r1 = [3, 1, 5], r2 = [4, 2, 6]
Output: [1, 2, 3, 4, 5, 6]
Explanation: After merging and sorting the two BST we get [1, 2, 3, 4, 5, 6].

Input: r1 = [8, 2, 10, 1, N], r2 = [5, 3, N, 0, N] 
Output: [0, 1, 2, 3, 5, 8, 10]
Explanation: After merging and sorting the two BST we get [0, 1, 2, 3, 5, 8, 10].*/

/* Structure of a Binary Search Tree node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
}; */

class Solution {
	public:
	void inorder(Node* r, vector<int> &ans)
	{
		if (!r)
			return;
		inorder(r->left, ans);
		ans.push_back(r->data);
		inorder(r->right, ans);
	}
	vector<int> merge(Node *r1, Node *r2) {
		// code here
		vector<int> a, b, ans;
		inorder(r1, a);
		inorder(r2, b);
		int i = 0, j = 0;
		while (i < a.size() && j < b.size()) {
			if (a[i] < b[j])
				ans.push_back(a[i++]);
			else
				ans.push_back(b[j++]);
		}
		while (i < a.size())
			ans.push_back(a[i++]);
		while (j < b.size())
			ans.push_back(b[j++]);
		return ans;
	}
};
// TC - O(n1+n2)  SC - O(n1+n2)