class MyHashSet {

public:
    vector<int> database;

    MyHashSet() {
        database.resize(1000001, 0);
    }
    
    void add(int key) {
        database[key] = 1;
    }
    
    void remove(int key) {
        database[key] = 0;
    }
    
    bool contains(int key) {
        return database[key] == 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */