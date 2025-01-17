#User function Template for python3


class Solution:
    def solve(self,n,l):
        if(l[n]!=-1):
            return l[n]
        if(n==0 or n==1):
            return n
        
        l[n] = n*self.solve(n-1,l) 
        return l[n]
        
    
    def factorial (self, n):
        l = [-1]*(n+1)
        if(n==0):
            return 1
        ans = self.solve(n,l)
        return ans
       


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        print(ob.factorial(N))

        print("~")

# } Driver Code Ends