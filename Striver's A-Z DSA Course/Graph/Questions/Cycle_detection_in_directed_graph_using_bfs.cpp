// Logic simple hai   we know topo sort works only for DAG   so if there is no cycle  it should work fine and ans.size() == v  but if there is a cycle then queeu becomes empty earlier and the condition fails     which we can use to detect cycle
class Solution
{
public:
    bool isCyclic(int v, vector<vector<int>> &a)
    {
        // code here
        vector<int> indegree(v, 0);
        vector<int> ans;
        vector<int> adj[v];
        queue<int> q;
        for (int i = 0; i < a.size(); i++)
        {
            indegree[a[i][1]]++;
            adj[a[i][0]].push_back(a[i][1]);
        }
        for (int i = 0; i < v; i++)
            if (indegree[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto i : adj[node])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
        return ans.size() != v;
    }
};
// TC - O(v+e)  SC - O(e+v)