class DynamicArray {
private:
    int* data;
    int capacity;
    int size;
public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        size = 0;
        if(capacity > 0) data = new int[capacity];
    }

    int get(int i) {
        return data[i];
    }

    void set(int i, int n) {
        data[i] = n;
    }

    void pushback(int n) {
        if(capacity == size) resize();

        data[size] = n;
        size++;
    }

    int popback() {
        int value = data[size-1];
        size--;
        return value;
    }

    void resize() {
        capacity *= 2;

        int* new_data = new int[capacity];

        for(int i = 0; i < size; i++){
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
