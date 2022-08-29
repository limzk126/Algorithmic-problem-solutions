#
# @lc app=leetcode id=721 lang=python3
#
# [721] Accounts Merge
#

# @lc code=start
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        from collections import defaultdict

        visited = set()
        d = defaultdict(list)

        def dfs(email, mergedAcc):
            if email in visited:
                return
            visited.add(email)
            mergedAcc.append(email)

            for nb in d[email]:
                dfs(nb, mergedAcc)

        for account in accounts:
            firstEmail = account[1]

            for i in range(1, len(account)):
                d[firstEmail].append(account[i])
                d[account[i]].append(firstEmail)

        res = []
        for account in accounts:
            name = account[0]
            firstEmail = account[1]

            if firstEmail in visited:
                continue

            mergedAcc = []
            dfs(firstEmail, mergedAcc)
            mergedAcc = [name] + sorted(mergedAcc)
            res.append(mergedAcc)

        return res


# @lc code=end
