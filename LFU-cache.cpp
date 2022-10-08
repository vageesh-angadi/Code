struct Node{
    Node *prev,*next;
    int value,key,cnt=1;
    Node(int _key,int _value){
        key=_key;
        value=_value;
    }
};
struct List{
    Node *head=new Node(0,0),*tail=new Node(0,0);
    int sz=0;
    List(){
        head->next=tail;
        tail->prev=head;
        head->prev=NULL;
        tail->next=NULL;
    }
    void addFront(Node* t){
        t->next=head->next;
        head->next->prev=t;
        head->next=t;
        t->prev=head;
        sz++;
    }
    void removeNode(Node* del){
        del->prev->next=del->next;
        del->next->prev=del->prev;
        del->prev=NULL;
        del->next=NULL;
        sz--;
    }
};
class LFUCache {
public:
    map<int,List*>freListMap;
    map<int,Node*>m;
    int c=0,minFre=0,curSize=0;
    LFUCache(int capacity) {
        c=capacity;
        minFre=0,curSize=0;
    }
    void updateFreListMap(Node* node){
        m.erase(node->key);
        freListMap[node->cnt]->removeNode(node);
        if(node->cnt==minFre && freListMap[node->cnt]->sz==0){
            minFre++;
        }
        List* newList=new List();
        if(freListMap.find(node->cnt+1)!=freListMap.end()){
            newList=freListMap[node->cnt+1];
        }
        node->cnt+=1;
        newList->addFront(node);
        freListMap[node->cnt]=newList;
        m[node->key]=node;
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* resNode=m[key];
            int res=resNode->value;
            updateFreListMap(resNode);
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(c==0){
            return ;
        }
        if(m.find(key)!=m.end()){
            Node* node=m[key];
            node->value=value;
            updateFreListMap(node);
        }
        else{
            if(curSize==c){
                List* l=freListMap[minFre];
                m.erase(l->tail->prev->key);
                freListMap[minFre]->removeNode(l->tail->prev);
                curSize--;
            }  
            curSize++;
            minFre=1;
            List* L=new List();
            if(freListMap.find(minFre)!=freListMap.end()){
                L=freListMap[minFre];
            }
            Node* node=new Node(key,value);
            L->addFront(node);
            m[node->key]=node;
            freListMap[minFre]=L;
        }
    }
};
