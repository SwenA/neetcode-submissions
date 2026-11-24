class MyHashMap {
public:
    MyHashMap() {
        m_cap = 1009;
        m_hashMap.resize(m_cap);
    }

    auto find(int key) {
        int idx = hash(key);

        for(auto it = m_hashMap[idx].begin(); it != m_hashMap[idx].end(); it++) {
            if(it->first == key) return it;
        }

        return m_hashMap[idx].end();
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        auto it = find(key);
        if(it == m_hashMap[idx].end()) {
            m_hashMap[idx].push_back({key, value});
            return;
        }

        it->second = value;

        
    }
    
    int get(int key) {
        int idx =  hash(key);
        auto it = find(key);
        if(it != m_hashMap[idx].end()) return it->second;
        return -1;
        
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto it = find(key);
        if(it != m_hashMap[idx].end()) m_hashMap[idx].erase(it);
    }

private: 

    int m_cap;
    vector<vector<pair<int, int>>> m_hashMap;

    int hash(int key) { return key % m_cap; }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */