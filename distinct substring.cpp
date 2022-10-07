struct Node{
    Node* link[26];
    bool containsKey(char c)
    {
        return (link[c-'a']!=NULL);
    }
    void put(char c)
    {
        link[c-'a']=new Node();
    }
    Node* getNext(char c){
        return link[c-'a'];
    }
};
class Trie{
    public:
     Node* root;
     Trie(){
         root=new Node();
     }
     int insert(string s){
         Node* node=root;
         int res=0;
         for(int i=0;i<s.length();i++){
             if(!(node->containsKey(s[i]))){
                 res++;
                 node->put(s[i]);
             }
             node=node->getNext(s[i]);
         }
         return res;
     }
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int res=0;
    Trie* trie=new Trie();
    for(int i=0;i<s.length();i++){
        string str="";
        for(int j=i;j<s.length();j++){
            str+=s[j];
         }
        res+=trie->insert(str);
    }
    return res+1;
}
