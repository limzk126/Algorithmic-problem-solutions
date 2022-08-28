class Solution:
    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        def topo_sort(A):
            deg, al, order = [0] * (k + 1), defaultdict(list), []
            for x, y in A:
                al[x].append(y)
                deg[y] = deg[y] + 1
            
            q = deque([i for i in range(1, k + 1) if deg[i] == 0])
            while q:
                x = q.popleft()
                order.append(x)
                for y in al[x]:
                    deg[y] = deg[y] - 1
                    if deg[y] == 0:
                        q.append(y)
            
            return order
        
        r_order, c_order = topo_sort(rowConditions), topo_sort(colConditions)
        if len(r_order) < k or len(c_order) < k: return []
        ans = [[0] * k for _ in range(k)]
        
        m = {x: i for i, x in enumerate(c_order)}
        for i in range(k):
            ans[i][m[r_order[i]]] = r_order[i]
        return ans
