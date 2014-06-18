#include <stdexcept>

#define DEFAULT_CAPACITY 10

template <class T>
class Vector 
{
private:
    unsigned int size;
    unsigned int capacity;

    T* buffer;
public:
    Vector(unsigned int _capacity = 0);
    void push_back(const T& value);

    unsigned int getSize();
    unsigned int getCapacity();

    void reserve(unsigned int _capacity);
    void resize(unsigned int _size);

    T& back();
    T& front();
};

#include "vector.cpp"
