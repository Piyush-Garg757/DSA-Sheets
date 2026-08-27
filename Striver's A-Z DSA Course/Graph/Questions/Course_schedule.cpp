/*Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.*/


// Directly inspired from detect a cycle in directed graph using dfs
class Solution
{
public:
    bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &path_visited)
    {
        visited[node] = 1;
        path_visited[node] = 1;
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, path_visited))
                    return true;
            }
            else if (path_visited[i])
                return true;
        }
        path_visited[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>> &a)
    {
        vector<int> adj[n];
        vector<int> visited(n, 0);
        vector<int> path_visited(n, 0);
        for (int i = 0; i < a.size(); i++)
            adj[a[i][0]].push_back(a[i][1]);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, path_visited))
                    return false;
            }
        }
        return true;
    }
};
// TC - O(v+e)  SC - O(e)