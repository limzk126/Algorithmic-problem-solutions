#
# @lc app=leetcode id=733 lang=python3
#
# [733] Flood Fill
#

# @lc code=start
class Solution:
    def floodFill(
        self, image: List[List[int]], sr: int, sc: int, color: int
    ) -> List[List[int]]:
        m, n, target = len(image), len(image[0]), image[sr][sc]

        def dfs(row, col):
            if (
                (not (0 <= row < m and 0 <= col < n))
                or image[row][col] == color
                or image[row][col] != target
            ):
                return
            image[row][col] = color
            [dfs(row + x, col + y) for (x, y) in ((0, 1), (1, 0), (0, -1), (-1, 0))]

        dfs(sr, sc)
        return image
