template <class T>
class Vector {
private:
    unsigned int __size;
    unsigned int __capacity;

    T* buffer;

public:
    Vector(unsigned int capacity = 0);
    ~Vector();

    void reserve(unsigned int new_capacity);

    void push_back(const T& value);
    void pop_back(); 

    T* data() const;
    bool empty() const;
    unsigned int size() const;
    unsigned int capacity() const;
    T& back();
    T& front();

    /* Overloading operators */
    T& operator[](unsigned int index);
};

#include "vector.cpp"
