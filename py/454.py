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
        
        return coun

# Fastest
class Solution_fast:
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        cnts = 0
        dd = {}
        aa = {}
        bb = {}
        cc = {}
        for a in A:
            aa[a] = aa.get(a, 0) + 1
        for b in B:
            bb[b] = bb.get(b, 0)+1
        for c in C:
            cc[c] = cc.get(c, 0) + 1
        for d in D:
            dd[d] = dd.get(d, 0) + 1
        ab = {}
        for a, av in aa.items():
            for b, bv in bb.items():
                ab[a+b] = ab.get(a+b, 0) + av*bv

        for c, cv in cc.items():
            for d, dv in dd.items():
                if -c-d in ab:
                    cnts += ab[-c-d] * cv * dv
        return cnts
