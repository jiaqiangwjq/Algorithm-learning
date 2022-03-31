class MyHashMap {
public:

    vector<int> my_map;

    MyHashMap() {
        my_map.resize(10000001, -1);
    }
    
    void put(int key, int value) {
        my_map[key] = value;
    }
    
    int get(int key) {
    return my_map[key];
}
    
    void remove(int key) {
        my_map[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */