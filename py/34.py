# 34. Find First and Last Position of Element in Sorted Array
class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ret=[-1,-1]
        times_found = 0
        if len(nums)==0:
            return ret
        if len(nums)==1:
            if nums[0]==target:
                return [0,0]
            else:
                return ret
        if nums[0]>target or nums[-1]<target:
            return ret
        idx_left = 0
        idx_right = len(nums)-1
        if nums[0]==target:
            ret[0]=0
            ret[1]=0
        if nums[1]==target:
            ret[0]=1
            ret[1]=1
        if nums[1]==target and nums[0]==target:
            ret[0]=0
            ret[1]=1
        while(idx_left!=idx_right-1):
            idx_mid = int((idx_right+idx_left)/2)
            num_mid = nums[idx_mid]
            
            if nums[idx_left] == target:
                num_mid = target
                idx_mid = idx_left
            if nums[idx_right] == target:
                num_mid = target
                idx_mid = idx_right
                
            if num_mid>target:
                idx_right = idx_mid
            elif num_mid<target:
                idx_left = idx_mid
            else:  # Found Target
                ret[0]=idx_mid
                ret[1]=ret[0]
                flag = True
                idx = idx_mid
                while flag:  # left
                    if idx==0:
                        flag = False
                        break
                    if nums[idx-1]==target:
                        idx-=1
                        ret[0]=idx
                    else:
                        flag = False
                flag = True
                idx = idx_mid
                while flag:  # left
                    if idx==len(nums)-1:
                        flag = False
                        break
                    if nums[idx+1]==target:
                        idx+=1
                        ret[1]=idx
                    else:
                        flag = False
                return ret

        return ret
        
        
