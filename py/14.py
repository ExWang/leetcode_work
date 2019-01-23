# 14. Longest Common Prefix
class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        common = ""
        min_len = 9999
        if len(strs) == 0:
            return ""
        for word in strs:
            if min_len > len(word): min_len=len(word)
        
        for idx in range(min_len):
            now_letter = strs[0][idx]
            for word in strs:
                if now_letter == word[idx]:
                    continue
                return common
            common += now_letter
        return common
