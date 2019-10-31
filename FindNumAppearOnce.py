# -*- coding:utf-8 -*-
import collections
class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        if len(array) < 2:
            return []
        dic = collections.Counter(array).items()
        dic = list(filter(lambda x: x[1] == 1, dic))
        return [x[0] for x in dic]

so = Solution()
so.FindNumsAppearOnce([2,4,3,6,3,2,5,5])