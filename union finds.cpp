class Solution {
public:
    int par[26],rank[26];
    int findPar(int x){
        if(x==par[x]) return x;
        return par[x]=findPar(par[x]);
    }
    void unions(int x,int y){
        x=findPar(x);
        y=findPar(y);
        if(rank[x]>rank[y]){
            par[y]=x;
        }
        else if(rank[x]<rank[y]){
            par[x]=y;
        }
        else{
            par[x]=y;
            rank[y]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        // vector<int>col(26);
        for(int i=0;i<26;i++){
            par[i]=i;
            rank[i]=1;
        }
        int n=equations.size();
        for(int i=0;i<n;i++){
            if(equations[i][1]=='='){
                unions(equations[i][0]-'a',equations[i][3]-'a');
            }
        }
        for(int i=0;i<n;i++){
            if(equations[i][1]=='!'){
                if(findPar(equations[i][3]-'a')==findPar(equations[i][0]-'a'))
                    return false;
            }
        }
        return true;
    }
};
