template <class T>
class Vector {
private:
    unsigned int __size;
    unsigned int __capacity;

    T* buffer;

public:
    typedef T* iterator;

    /* Member Functions */
    Vector(unsigned int capacity = 0);
    Vector(const Vector<T>& rhs);
    Vector(unsigned int n, const T& val);
    Vector<T>& operator=(const Vector<T>& rhs);

    ~Vector();

    /* Iterators */
    iterator begin();
    iterator end();

    void reserve(unsigned int new_capacity);
    void resize(unsigned int new_size, const T& val = 0);

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

    /* Modifiers */
};

#include "vector.cpp"
