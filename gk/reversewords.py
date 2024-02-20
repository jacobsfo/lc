# User function Template for python3
'''
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.
'''
class Solution:
    
    #Function to reverse words in a given string.
    def reverseWords(self,S):
        # code here 
        a=S.split('.')
        b=reversed(a)
        c=""
        for v in b:
            c += (v+'.')
            
    
        c=c[:-1]
        return c

#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = str(input())
        obj = Solution()
        print(obj.reverseWords(s))

# } Driver Code Ends