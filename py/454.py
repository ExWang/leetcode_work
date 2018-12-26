# 454. 4Sum II
class Solution:
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        mydict = {}
        for a in A:
            for b in B:
                if a+b not in mydict:
                    mydict[a+b]=1
                else:
                    mydict[a+b]+=1
        count = 0
        for c in C:
            for d in D:
                if -(c+d) in mydict:
                    count += mydict[-(c+d)]
        
        return count
