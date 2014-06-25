#include <stdexcept>

template <class T>
Vector<T>::Vector(unsigned int capacity) : __size(0), __capacity(capacity)
{
    buffer = new T[__capacity];
}

template <class T>
Vector<T>::Vector(const Vector<T>& rhs) : __size(rhs.size()), __capacity(rhs.capacity())
{
    this->buffer = new T[__capacity];
    for (unsigned int i = 0; i < __size; ++i)
        buffer[i] = rhs.buffer[i];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) 
{
    if (this == &rhs)
        return *this;
    __size = rhs.size();
    __capacity = rhs.capacity();

    delete [] buffer;
    this->buffer = new T[__capacity];
    for (unsigned int i = 0; i < __size; ++i)
        buffer[i] = rhs.buffer[i];
    return *this;
}

template <class T>
Vector<T>::~Vector()
{
    delete [] buffer;
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return buffer;
}

template <class T>
typename Vector<T>::iterator Vector<T>::end()
{
    return buffer + __size;
}

template <class T>
void Vector<T>::reserve(unsigned int new_capacity)
{
    if (new_capacity < __capacity) return;
    __capacity = new_capacity;
    T* temp_buffer = new T[__capacity];
    for (int i = 0; i < __size; ++i) 
        temp_buffer[i] = buffer[i];
    delete [] buffer;
    buffer = temp_buffer;
}

template <class T>
void Vector<T>::resize(unsigned int size, const T& val)
{
    if (size > __capacity)
        reserve(size + 5);
    if (size < __size) 
        for (int i = __size; i > size; --i)
            pop_back();
    else if (size > __size)
        for (int i = __size; i < size; ++i)
            push_back(val);
}

template <class T>
void Vector<T>::push_back(const T& value)
{
    if (__size >= __capacity) 
        reserve((__size*2) + 1);
    buffer[__size++] = value;
}

template <class T>
void Vector<T>::pop_back()
{
    if (__size == 0)
        throw std::out_of_range("Vector is empty. Cannot pop");
    --__size;
}

template <class T>
T* Vector<T>::data() const 
{
    return buffer;
}

template <class T>
bool Vector<T>::empty() const
{
    return __size == 0;
}

template <class T>
unsigned int Vector<T>::size() const
{
    return __size;
}

template <class T>
unsigned int Vector<T>::capacity() const
{
    return __capacity;
}

template <class T>
T& Vector<T>::back()
{
    return buffer[__size - 1];
}

template <class T>
T& Vector<T>::front()
{
    return buffer[0];
}

template <class T>
T& Vector<T>::operator[](unsigned int index)
{
    return buffer[index];
}   

template <class T>
void Vector<T>::assign(unsigned int n, const T& val)
{
    delete [] buffer;
        
}
