# -*- coding:utf-8 -*-
class Solution:
    def LeftRotateString(self, s, n):
        # write code here
        n = n % len(s)
        return  s[n:] + s[:n]
so = Solution()
print(so.LeftRotateString('abcdefg', 2))