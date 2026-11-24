class MyHashSet {
public:
    MyHashSet() {
        m_numBuckets = 1009;
        m_hashSet.resize(m_numBuckets);
    }
    
    void add(int key) {
        int idx = key % m_numBuckets;
        if(m_hashSet[idx].empty()) {
            for(int i = 0; i < m_hashSet[idx].size(); i++) {
                if(m_hashSet[idx][i] == key) return; 
            }
            m_hashSet[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = key % m_numBuckets;
        if(!m_hashSet[idx].empty()) {
            for(int i = 0; i < m_hashSet[idx].size(); i++) {
                if(m_hashSet[idx][i] == key) m_hashSet[idx].erase(m_hashSet[idx].begin() + i); 
            }
        }
    }
    
    bool contains(int key) {
        int idx = key % m_numBuckets;
        if(!m_hashSet[idx].empty()) {
            for(int i = 0; i < m_hashSet[idx].size(); i++) {
                if(m_hashSet[idx][i] == key) return true; 
            }
        }
        return false;
    }

private:

int m_numBuckets = 0;
vector<vector<int>> m_hashSet;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */