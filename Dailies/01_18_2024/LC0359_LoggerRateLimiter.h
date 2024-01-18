class Logger {
private:
    std::unordered_map<std::string, int> _messageToExpiryTS;

public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        auto msgIt = _messageToExpiryTS.find(message);
        if(msgIt == _messageToExpiryTS.end()){
            _messageToExpiryTS[message] = timestamp + 10;
            return true;
        }else{
            if(timestamp < msgIt->second){
                return false;
            }else{
                msgIt->second = timestamp + 10;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */