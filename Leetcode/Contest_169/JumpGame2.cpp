class Solution {
public:
	 
    int jump(vector<int>& nums) {
        int curr_reach=0, max_reach=0, steps=0;
        for(int i = 0; i < nums.size()-1; i++){
            curr_reach = max(curr_reach, nums[i] + i); 
            if(i == max_reach){ 
                steps++; 
                max_reach = max(max_reach, curr_reach);        
            }
        }
        return steps;
    }
   // DP Solution - TLE
   // int jump(vector<int>& nums) {
   //      int table[nums.size()]; 
   //      table[0] = 0;
   //      for(int i=1; i < nums.size();i++){
   //          table[i] = 99999999;
   //          for(int j=0; j<=i; j++){
   //              if(j + nums[j] >=i)
   //                  table[i] = min(table[i], table[j]+ 1);
   //          }
   //      }
   //      return table[nums.size()-1];
   //  }
};
