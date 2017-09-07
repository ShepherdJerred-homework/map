#pragma once
#include <vector>

using std::vector;

template <typename K, typename V>
class Map {
public:
    class Wrapper {
    public:
        operator V&();
        V* operator &();
        const V& operator =(const V&);
        bool exists();
    private:
        Wrapper(Map&, const K&);
        Wrapper(const Wrapper&);
        Map& map;
        K key;
        V* value;

        friend class Map;
    };

    class Iterator {
    public:
        void operator++();
        void operator--();
        void operator++(int);
        void operator--(int);
        V& operator*();
        bool hasNext();
    private:
        Iterator(Map&);
        Map& map;
        int index;

        friend class Map;
    };

    class Visitor {
    public:
        virtual void visit(K&, V&) = 0;
    };

    void visit(Visitor&);
    Iterator getIterator();
    Wrapper operator[](const K&);
    unsigned size();

private:
    vector<K> keys;
    vector<V> values;

    V* find(const K&);
    V* set(const K&, const V&);
};

// Visitor
template <typename K, typename V>
void Map<K, V>::visit(Visitor& visitor) {
    for (int i = 0; i < keys.size(); i++) {
        visitor.visit(keys[i], values[i]);
    }
}

// Iterator static factory
template <typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::getIterator() {
    return Map<K, V>::Iterator(*this);
}

// Exists
template <typename K, typename V>
bool Map<K, V>::Wrapper::exists() {
    return (value != nullptr);
}

// Brackets operator
// map[key];
template <typename K, typename V>
typename Map<K, V>::Wrapper Map<K, V>::operator[](const K& key) {
    return Wrapper(*this, key);
}

// Size
template <typename K, typename V>
unsigned Map<K, V>::size() {
    return keys.size();
}

// Find
template <typename K, typename V>
V* Map<K, V>::find(const K& key) {
    for (int i = 0; i < keys.size(); i++) {
        if (keys[i] == key) {
            return &values[i];
        }
    }
    return nullptr;
}

// Set
template <typename K, typename V>
V* Map<K, V>::set(const K& key, const V& value) {
    V* existingValue = find(key);

    if (existingValue != nullptr) {
        *existingValue = value;
    } else {
        keys.push_back(key);
        values.push_back(value);
        existingValue = find(key);
    }

    return existingValue;
}

// Wrapper
// Constructor
template <typename K, typename V>
Map<K, V>::Wrapper::Wrapper(Map& map, const K& key) : map(map) {
    this->key = key;
    this->value = map.find(key);
}

// Copy constructor
template <typename K, typename V>
Map<K, V>::Wrapper::Wrapper(const Wrapper& rValue) {
    this->map = rValue.map;
    this->key = rValue.key;
    this->value = rValue.value;
}

// Cast from wrapper to V
template <typename K, typename V>
Map<K, V>::Wrapper::operator V&() {
    if (this->value == nullptr) {
        throw std::range_error("Key not found in map");
    }
    return *this->value;
}

// Address of operator
template <typename K, typename V>
V* Map<K, V>::Wrapper::operator &() {
    if (this->value == nullptr) {
        throw std::range_error("Key not found in map");
    }
    return this->value;
}

// Assignment operator
template <typename K, typename V>
const V& Map<K, V>::Wrapper::operator =(const V& rValue) {
    map.set(key, rValue);
    return rValue;
}

// Iterator
template <typename K, typename V>
Map<K, V>::Iterator::Iterator(Map& map) : map(map), index(0) {

}

template <typename K, typename V>
void Map<K, V>::Iterator::operator++() {
    if (index < map.keys.size()) {
        index++;
    } else {
        index = 0;
    }
}

template <typename K, typename V>
void Map<K, V>::Iterator::operator--() {
    if (index != 0) {
        index--;
    } else {
        index = map.keys.size() - 1;
    }
}

template <typename K, typename V>
void Map<K, V>::Iterator::operator++(int) {
    ++this;
}

template <typename K, typename V>
void Map<K, V>::Iterator::operator--(int) {
    --this;
}

template <typename K, typename V>
V& Map<K, V>::Iterator::operator*() {
    return map.values[index];
}

template <typename K, typename V>
bool Map<K, V>::Iterator::hasNext() {
    return index < map.keys.size();
}
