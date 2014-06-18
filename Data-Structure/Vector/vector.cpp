template<class T>
Vector<T>::Vector(unsigned int _capacity) : size(0), capacity(_capacity), buffer(0) 
{
    buffer = new T[size];
}

template <class T>
void Vector<T>::push_back(const T& value)
{
    buffer[size++] = value;
}

template <class T>
T& Vector<T>::back() 
{
    return buffer[size - 1];
}

template <class T>
unsigned int Vector<T>::getSize()
{
    return size;
}

template <class T>
unsigned int Vector<T>::getCapacity()
{
    return capacity;
}

template <class T>
void Vector<T>::reserve(unsigned int _capacity)
{

}

template <class T>
void Vector<T>::resize(unsigned int _size)
{
    if (_size < size) 
        throw std::range_error("Size cannot be lower than current size");
}

