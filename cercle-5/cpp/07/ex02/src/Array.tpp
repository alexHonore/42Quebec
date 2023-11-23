
template <class T>
Array<T>::Array() : _n(0) {
        this->_array = new T[this->_n];
}

template <class T>
Array<T>::Array(unsigned int n) : _n(n) {
        this->_array = new T[this->_n];
        for (unsigned int i = 0; i < this->_n; i++) {
            this->_array[i] = T();
        }
}

template <class T>
Array<T>::Array(const Array& src) {
    this->_n = src._n;
    this->_array = new T[this->_n];
    for (unsigned int i = 0; i < src._n; i++)
        this->_array[i] = src._array[i];
}

template <class T>
Array<T>::~Array() {
    delete[] this->_array;
}


template <class T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
    if (this != &rhs)
    {
        delete[] this->_array;
        this->_n = rhs._n;
        this->_array = new T[this->_n];
        for (unsigned int i = 0; i < rhs._n; i++)
            this->_array[i] = rhs._array[i];
    }
    return (*this);
}

template <class T>
int Array<T>::size() const {
    return (this->_n);
}

template <class T>
T& Array<T>::operator[](unsigned int i) {
    if (i >= this->_n)
        throw Array<T>::OutOfBoundsException();
    return (this->_array[i]);
}
