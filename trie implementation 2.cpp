#include <bits/stdc++.h> 
using namespace std;
struct Node{
    Node* link[26];
    int cp=0,ew=0;
    bool containsKey(char c){
        return (link[c-'a']!=NULL);
    }
    void put(char c){
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
        // Write your code here.
    }

    void insert(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!(node->containsKey(word[i]))){
                 node->put(word[i]);   
            }
            node=node->getNext(word[i]);
            node->cp++;
        }
        node->ew++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!(node->containsKey(word[i]))){
                return 0;
            }
            node=node->getNext(word[i]);
        }
        return node->ew;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!(node->containsKey(word[i]))){
                return 0;
            }
            node=node->getNext(word[i]);
        }
        return node->cp;
    }

    void erase(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.length();i++){
            node=node->getNext(word[i]);
            node->cp--;
        }
        node->ew--;
    }
};
