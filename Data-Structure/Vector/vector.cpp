template <class T>
Vector<T>::Vector(unsigned int capacity) : _size(0), _capacity(capacity), buffer(0) 
{
    buffer = new T[_size];
}

template <class T>
Vector<T>::~Vector()
{
   delete [] buffer; 
}

template <class T>
void Vector<T>::push_back(const T& value)
{
    buffer[_size++] = value;
}

template <class T>
T& Vector<T>::back() 
{
    return buffer[_size - 1];
}

template <class T>
unsigned int Vector<T>::size()
{
    return _size;
}

template <class T>
unsigned int Vector<T>::capacity()
{
    return _capacity;
}

template <class T>
void Vector<T>::reserve(unsigned int _capacity)
{

}

template <class T>
void Vector<T>::resize(unsigned int size)
{
    if (size < _size) 
        throw std::range_error("Size cannot be lower than current size");
}

