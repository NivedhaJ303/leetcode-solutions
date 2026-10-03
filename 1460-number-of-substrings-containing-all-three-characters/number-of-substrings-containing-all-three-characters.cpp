class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3,-1);
        int count=0;

        for(int i=0;i<s.size();i++){
            // update last seen position
            last[s[i]-'a']=i;

            //have we seen a,b,c?, if seen 3 then move inside if
            if(last[0]!=-1&&last[1]!=-1&&last[2]!=-1){
                count=count+1+min({last[0],last[1],last[2]});
            }
        }
        return count;
    }
};