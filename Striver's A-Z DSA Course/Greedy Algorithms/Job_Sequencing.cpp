/*Job Sequencing Problem

Given a set of n jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.
Note:  Jobs will be given in the form (id, deadline, profit) associated with that Job.

Examples:
Input: n = 4, Jobs = [(1, 4, 20), (2, 1, 10), (3, 1, 40), (4, 1, 30)]
Output: [2, 60]
Explanation: Since at deadline 1 Job3 can give the maximum profit and for deadline 4 we left with only Job1 hence Job1 and Job3 can be done with maximum profit of 60 (20+40).

Input: n = 5, Jobs = [(1, 2, 100), (2, 1, 19), (3, 2, 27), (4, 1, 25), (5,  1,15)]
Output: [2, 127]
Explanation: 2 jobs can be done with maximum profit of 127 (100+27).*/

/*
struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

// Optimal approach - profit ke basis pe sort kar liya aur deadline ke ekdum last day karne ka try kar rahe hain   agar dono ek hi deadline pe aa rahe hain ot us se ek din oehle karne ka ya jab bhi last -1 aa raha hai uspe de rahe hain
class Solution
{
public:
    static bool comp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job a[], int n)
    {
        // code here
        sort(a, a + n, comp);
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
            maxi = max(maxi, a[i].deadline);
        vector<int> q(maxi, -1);
        int profit = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = a[i].deadline - 1; j >= 0; j--)
            {
                if (q[j] == -1)
                {
                    q[j] = a[i].id;
                    count++;
                    profit += a[i].profit;
                    break;
                }
            }
        }
        return {count, profit};
    }
};
// TC - O(nlogn)  SC - O(n)

/*Agar kisi struct/class ke kisi member ke basis pe sort karna ho, to basic syntax ye hota hai:
Method 1: Comparator Function
bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}
sort(arr, arr + n, cmp);

Method 2: Lambda Function (modern C++)
sort(arr, arr + n, [](Job a, Job b) {
    return a.profit > b.profit;
});

Ascending profit
return a.profit < b.profit;

Descending profit:
return a.profit > b.profit;

Vector of Pairs Example
vector<pair<int,int>> v;
sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
});

General Template (Interview mein yaad rakhne layak)
sort(start, end, [](Type a, Type b) {
    return condition;
});

Example:
sort(arr, arr + n, [](Job a, Job b) {
    return a.deadline < b.deadline;
});

ya
sort(arr, arr + n, [](Job a, Job b) {
    return a.profit > b.profit;
});

Bas rule yaad rakho:
return true;
matlab:
a ko b se pehle rakhna hai
Isliye:
return a.profit > b.profit;
=> zyada profit wali job pehle aayegi.*/