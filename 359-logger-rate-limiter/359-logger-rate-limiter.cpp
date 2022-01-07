class Logger {
public:
    unordered_map<string, int> hmap;
    Logger() {

    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        bool output = true;
        if(hmap.find(message) == hmap.end()){
            hmap[message] = timestamp + 10;
        }
        else{
            if(timestamp >= hmap[message]){
                hmap[message] = timestamp +  10;
            }else{
                output = false;
            }
            
        }
        return output;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */