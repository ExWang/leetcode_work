# 5. Longest Palindromic Substring
class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = []
        # if len>3
        if len(s)>=3:
            for idx,char in enumerate(s):
                if idx>=1 and idx<=len(s)-2:
                    # print(idx,char,s[idx-1],s[idx+1])
                    # char and left
                    if char==s[idx-1]:
                        # print("LEFT")
                        tmp=[s[idx-1],char]
                        i=idx-2
                        j=idx+1
                        # print(i,j,idx)
                        while(i>=0 and j<len(s)):
                            if s[i]==s[j]:
                                tmp.insert(0,s[i])
                                tmp.append(s[j])
                            else:
                                break
                            i-=1
                            j+=1
                        if len(tmp)>len(res):
                            res = tmp
                    # char and right 
                    elif char==s[idx+1]:
                        # print("RIGHT")
                        tmp=[char,s[idx+1]]
                        i=idx-1
                        j=idx+2
                        while(i>=0 and j<len(s)):
                            if s[i]==s[j]:
                                tmp.insert(0,s[i])
                                tmp.append(s[j])
                            else:
                                break
                            i-=1
                            j+=1
                        if len(tmp)>len(res):
                            res = tmp
                    # char is middle
                    if s[idx-1]==s[idx+1]:
                        # print("MID")
                        tmp=[s[idx-1],char,s[idx+1]]
                        i=idx-2
                        j=idx+2
                        while(i>=0 and j<len(s)):
                            if s[i]==s[j]:
                                tmp.insert(0,s[i])
                                tmp.append(s[j])
                            else:
                                break
                            i-=1
                            j+=1
                        if len(tmp)>len(res):
                            res = tmp

                    pass
                else:
                    tmp=[char]
                    if len(tmp)>len(res):
                        res = tmp
                    pass
            return "".join(res)
        elif len(s)==2:
            if s[0]==s[1]:
                return s
            else:
                return s[0]
        else:
            return s
            

        
