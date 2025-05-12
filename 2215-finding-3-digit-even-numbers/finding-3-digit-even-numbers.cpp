class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
       set<int>st;
       int n = digits.size();
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(i==j || j==k || k==i || digits[i]==0) continue;
                int num = digits[i]*100 + digits[j]*10 + digits[k];
                if(num%2==0){
                    st.insert(num);
                }
            }
        }
       } 

       vector<int>ans(st.begin(),st.end());
       sort(ans.begin(),ans.end());
       return ans;
    }
    
};