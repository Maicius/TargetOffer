class Solution:
    def ReverseSentence(self, s):
        # write code here
        sentence = s.split(" ")
        res = []
        i = len(sentence) - 1
        while i >= 0:
            res.append(sentence[i])
            i -= 1
        return " ".join(res)
so = Solution()
so.ReverseSentence("student. a am I")