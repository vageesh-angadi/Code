struct Node{
    Node* link[2];
    bool containsKey(int c){
        return link[c]!=NULL;
    }
    void put(int c){
        link[c]=new Node();
    }
    Node* getNext(int c){
        return link[c];
    }
};
class Trie{
    public:
    Node* root=new Node();
    Trie(){

    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit);
            }
            node=node->getNext(bit);
        }
    }
    int Xor(int num){
        Node* node=root;
        int res=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            int req=0;
            if(bit==0) req = 1;
            if(node!=NULL && node->containsKey(req)){
                res=res|(1<<i);
                node=node->getNext(req);
            }
            else if(node!=NULL){
                node=node->getNext(bit);
            }
        }
        return res;
    }
};
class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie* trie=new Trie();
        vector<vector<int>>query(queries.size(),vector<int>(3,0));
        for(int i=0;i<queries.size();i++){
            query[i][0]=queries[i][0];
            query[i][1]=queries[i][1];
            query[i][2]=i;
        }
        sort(query.begin(),query.end(),cmp);
        vector<int>res(queries.size(),0);
        int n=queries.size(),j=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            while(j<nums.size() && nums[j]<=query[i][1]){
                trie->insert(nums[j]);
                j++;
            }
            if(j==0){
                res[query[i][2]]=-1;
            }
            else
                res[query[i][2]]=trie->Xor(query[i][0]);
        }
        return res;
    }
};
