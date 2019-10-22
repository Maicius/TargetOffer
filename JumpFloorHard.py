class Solution:
    dp = {}

    def jumpFloorII(self, number):
        # 普通递归
        res = 0
        if number < 3:
            return number
        else:
            for i in range(1, number):
                res += self.jumpFloorII(i)
            return res + 1
    def jumpFloorII2(self, number):
        # 动态规划
        res = 0
        if number < 3:
            return number
        else:
            for i in range(1, number):
                if i in self.dp:
                    res += self.dp[i]
                else:
                    temp = self.jumpFloorII2(i)
                    self.dp[i] = temp
                    res += temp
            return res + 1
    def jumpFloorII3(self, number):
        # 组合数求和
        return 2 ** (number - 1)

so = Solution()
print(so.jumpFloorII2(6))