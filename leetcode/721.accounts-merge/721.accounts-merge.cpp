/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        class Solution
        {
        public:
            unordered_set<string> visited;
            unordered_map<string, vector<string>> al;

            void dfs(vector<string> &mergedAccount, string email)
            {
                if (visited.find(email) != visited.end())
                    return;
                visited.insert(email);
                mergedAccount.push_back(email);

                for (auto nb : al[email])
                {
                    dfs(mergedAccount, nb);
                }
            }

            vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
            {

                for (auto account : accounts)
                {
                    string first = account[1];

                    for (int i = 2; i < account.size(); ++i)
                    {
                        string email = account[i];
                        al[first].push_back(email);
                        al[email].push_back(first);
                    }
                }

                vector<vector<string>> res;
                for (auto account : accounts)
                {
                    string name = account[0];
                    string first = account[1];

                    if (visited.find(first) != visited.end())
                        continue;

                    vector<string> mergedAccount;
                    mergedAccount.push_back(name);
                    dfs(mergedAccount, first);
                    sort(mergedAccount.begin() + 1, mergedAccount.end());
                    res.push_back(mergedAccount);
                }

                return res;
            }
        };
    }
};
// @lc code=end
