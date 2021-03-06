class TimeMap {
public:
    unordered_map<string, map<int, string>> hmap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hmap[key][timestamp]  = value;
    }
    
    string get(string key, int timestamp) {
        
        map<int, string>::iterator it = hmap[key].find(timestamp);
        if( it != hmap[key].end()){
            return it->second;
        }
        
        it = hmap[key].lower_bound(timestamp);
        if(it == hmap[key].begin()) return "";
        return (--it)->second;
        
    }
    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */