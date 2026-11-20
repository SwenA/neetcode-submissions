class DynamicArray {
private:
    int* m_data;
    int m_capacity;
    int m_size;
public:

    DynamicArray(int capacity) {
        m_capacity = capacity;
        m_size = 0;
        if(m_capacity > 0) m_data = new int[m_capacity];
    }

    int get(int i) {
        return m_data[i];
    }

    void set(int i, int n) {
        m_data[i] = n;
    }

    void pushback(int n) {
        if(m_capacity == m_size) resize();

        m_data[m_size] = n;
        m_size++;
    }

    int popback() {
        int value = m_data[m_size-1];
        m_size--;
        return value;
    }

    void resize() {
        m_capacity *= 2;

        int* temp = new int[m_capacity];

        for(int i = 0; i < m_size; i++){
            temp[i] = m_data[i];
        }
        delete[] m_data;
        m_data = temp;
    }

    int getSize() {
        return m_size;
    }

    int getCapacity() {
        return m_capacity;
    }
};
