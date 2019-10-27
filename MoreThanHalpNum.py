# -*- coding:utf-8 -*-
import collections
# 题目描述
# 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        result = 0
        res = collections.Counter(numbers)
        for i, v in res.items():
            if v > len(numbers) / 2:
                result = i
                break
        return result

    """
    第二种，假设有这个数字，那么它的数量一定比其它所有数字之和还要多，按照这个思路得出num，然后验证
    """
    def MoreThanHalfNum_Solution1(self, numbers):
        # write code here
        if not numbers:
            return 0
        num = numbers[0]
        count = 1
        for i in range(1, len(numbers)):
            if numbers[i] == num:
                count += 1
            else:
                count -= 1
            if count == 0:
                num = numbers[i]
                count = 1
        count = 0
        for i in numbers:
            if i == num:
                count += 1
        return num if count > len(numbers) / 2.0 else 0
    """对列表排序，计算下标为len/2(即中间位置)的数字数量即可"""
    def MoreThanHalfNum_Solution2(self, numbers):
        # write code here
        # 对列表进行快排
        left = 0
        right = len(numbers) - 1
        stack = [right, left]
        while stack:
            low = stack.pop()
            high = stack.pop()
            if low >= high:
                continue
            less = low - 1
            mid = numbers[high]
            for i in range(low, high):
                if numbers[i] <= mid:
                    less += 1
                    numbers[less], numbers[i] = numbers[i], numbers[less]
            numbers[less + 1], numbers[high] = numbers[high], numbers[less + 1]
            stack.extend([high, less+2, less, low])
        # 验证
        count = 0
        length = len(numbers) // 2
        for i in numbers:
            if i == numbers[length // 2]:
                count += 1
        return numbers[length // 2] if count > length / 2.0 else 0
    

    """对列表排序，计算下标为len/2(即中间位置)的数字数量即可"""
    def MoreThanHalfNum_Solution3(self, numbers):
        # write code here
        # 对列表进行快排
        left = 0
        right = len(numbers) - 1
        stack = [right, left]
        while stack:
            low = stack.pop()
            high = stack.pop()
            if low >= high:
                continue
            less = low - 1
            mid = numbers[high]
            for i in range(low, high):
                if numbers[i] <= mid:
                    less += 1
                    numbers[less], numbers[i] = numbers[i], numbers[less]
            numbers[less + 1], numbers[high] = numbers[high], numbers[less + 1]
            stack.extend([high, less+2, less, low])
        # 验证
        count = 0
        length = len(numbers) // 2
        for i in numbers:
            if i == numbers[length // 2]:
                count += 1
        return numbers[length // 2] if count > length / 2.0 else 0
            