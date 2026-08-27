/*Course Schedule II

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]*/


// Detecting cycle in a directed graph + topological sort
class Solution
{
public:
    bool dfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &st, vector<int> &path_visited)
    {
        visited[node] = 1;
        path_visited[node] = 1;
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, st, path_visited))
                    return true;
            }
            if (path_visited[i])
                return true;
        }
        st.push(node);
        path_visited[node] = 0;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>> &a)
    {
        vector<int> adj[n];
        vector<int> visited(n, 0);
        vector<int> path_visited(n, 0);
        for (int i = 0; i < a.size(); i++)
            adj[a[i][1]].push_back(a[i][0]);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, st, path_visited))
                    return {};
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
// TC - O(v+e)  SC - O(e)