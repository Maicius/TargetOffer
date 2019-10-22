class Solution:
    dp = {}
    #     题目描述
    # 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
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