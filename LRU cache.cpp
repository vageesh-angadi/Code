struct Node{
    Node *next,*prev;
    int key,value;
    Node(int _key,int _value){
        key=_key;
        value=_value;
    }
};
class LRUCache {
public:
    Node* head=new Node(0,0);
    Node* tail=new Node(0,0);
    unordered_map<int,Node*>m;
    int c=0;
    LRUCache(int capacity) {
        c=capacity;
        head->next=tail;
        tail->prev=head;
        head->prev=NULL;
        tail->next=NULL;
    }
    void remove(Node* x){
        x->prev->next=x->next;
        x->next->prev=x->prev;
        x->next=NULL;
        x->prev=NULL;
        m.erase(x->key);
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* x=m[key];
            int res=x->value;
            remove(x);
            put(key,res);
            return res;
        }
       return -1;
    }

    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            remove(m[key]);
        }
        if(m.size()==c){
            remove(tail->prev);
        }        
        Node* nah=new Node(key,value);
        nah->next=head->next;
        head->next->prev=nah;
        head->next=nah;
        nah->prev=head;
        m[key]=nah;
    }
};
