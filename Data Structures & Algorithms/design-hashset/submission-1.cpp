class MyHashSet {
public:
    MyHashSet() {
        m_cap = 1009;
        m_hashSet.resize(m_cap);
    }
    
    void add(int key) {
        if(contains(key)) return;
        int idx = hash(key);
        m_hashSet[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        if(!m_hashSet[idx].empty()) {
            for(int i = 0; i < m_hashSet[idx].size(); i++) {
                if(m_hashSet[idx][i] == key) m_hashSet[idx].erase(m_hashSet[idx].begin() + i); 
            }
        }
    }
    
    bool contains(int key) {
        int idx = hash(key);
        if(!m_hashSet[idx].empty()) {
            for(int i = 0; i < m_hashSet[idx].size(); i++) {
                if(m_hashSet[idx][i] == key) return true; 
            }
        }
        return false;
    }

private:

int m_cap = 0;
vector<vector<int>> m_hashSet;

int hash(int key) { return key % m_cap; }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */