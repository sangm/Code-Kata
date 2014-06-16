#include <stdexcept>

#define DEFAULT_CAPACITY 10

template <class T>
class Vector 
{
private:
    unsigned int _size;
    unsigned int _capacity;

    T* buffer;
public:
    Vector(unsigned int _capacity = 0);
    ~Vector();

    void push_back(const T& value);

    unsigned int size();
    unsigned int capacity();

    void reserve(unsigned int capacity);
    void resize(unsigned int size);

    T& back();
    T& front();
};

#include "vector.cpp"
