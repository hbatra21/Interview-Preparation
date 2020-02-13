class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         vector<int> a;
        if(nums1.size() == 0 || nums2.size() == 0)
            return a;
        stack<int> st;
        int n = nums1.size(), m = nums2.size();
        vector<int> v(n);
        unordered_map<int, int> mp;
        vector<int> ans(m, -1);
        st.push(nums2[m-1]);
        for(int i = m-2; i >= 0; i--){
            while(!st.empty() && st.top() < nums2[i])
                st.pop();
            if(!st.empty()){
                ans[i] = st.top();
                st.push(nums2[i]);
            }
            else if(st.empty())
                st.push(nums2[i]);
        }
        for(int i = 0; i < m; i++)
            mp[nums2[i]] = ans[i];
        for(int i = 0; i < n; i++)
            v[i] =mp[nums1[i]];
        
        
        return v;
    } 
};
