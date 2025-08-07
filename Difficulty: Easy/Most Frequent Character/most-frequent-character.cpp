class Solution {
  public:
    char getMaxOccuringChar(string& s) {
    int n = s.length();
    vector<int>freq(26,0);
    
    for(int i=0;i<n;i++)
    freq[s[i]-'a']++;
    
   char ans ;
   int max_freq = 0;
   
//   0 -> 'a' 
//   (1 + 'a') -> 'b' 
   
   for(int i=0;i<26;i++)
   {
       int curr_freq = freq[i];
       
       if(curr_freq > max_freq)
       {
           max_freq = curr_freq;
           ans =  char(i + 'a');
       }
       else if(curr_freq==max_freq)
       {
           ans = min(ans, char(i+'a'));
       }
   }
   
   return ans;
    
    }
};