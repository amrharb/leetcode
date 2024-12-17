class LRUCache {
private:
    vector<int>keys;
    vector<int>vals;
    unordered_map<int,int>index;
    int capacity,size,start;
public:
    LRUCache(int capacity) {
        start=0;
        size=0;
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(index.count(key)){
            keys.push_back(key);
            vals.push_back(vals[index[key]]);
            index[key]=keys.size()-1;
            return vals.back();
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(!index.count(key)){
            size++;
            if(size>capacity){
                while(true){
                    if(index[keys[start]]==start){
                        index.erase(keys[start]);
                        start++;
                        size--;
                        break;
                    }else{
                        start++;
                    }
                }
            }
        }
        index[key]=keys.size();
        keys.push_back(key);
        vals.push_back(value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */