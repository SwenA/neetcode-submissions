using ListIt = std::list<int>::iterator;
class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if(!mp.contains(key)) return -1;

        sendToFront(key);
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.contains(key)) {
            sendToFront(key);
            mp[key] = {value, lst.begin()};
            return;
        }
        if(lst.size() == m_capacity) {
            mp.erase(lst.back());
            lst.pop_back();
        }
        lst.push_front(key);
        mp[key] = {value, lst.begin()};
    }

private:
    int m_capacity;

    std::unordered_map<int, std::pair<int, ListIt>> mp;
    std::list<int> lst;

    void sendToFront(int key){
        auto mapIt = mp.find(key);
        if(mapIt != mp.end()) {
            ListIt it = mapIt->second.second;
            lst.splice(lst.begin(), lst, it);
        }
    }
};
