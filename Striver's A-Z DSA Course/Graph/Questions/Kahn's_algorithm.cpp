// Basically topological sort bfs ke through karna\

// Approach - indegree vector banao aur jis jis ki indegre 0 hai vo sabse pehle aane chahiye order me to unhein queue me push kar do fir pop karo aur ans mein push_back karo fir jis jis se ye connected tha uskji indegree -- kar do aur agar unki indegree 0 ho jaye to unhein q mein push kar do    aise hi while(!q.empty())
class Solution
{
public:
    vector<int> topoSort(int v, vector<vector<int>> &a)
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
        return ans;
    }
};
// TC - O(v+e)  SC - O(e+v)