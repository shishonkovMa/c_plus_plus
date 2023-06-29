#ifndef RINGBUF_HPP
#define RINGBUF_HPP


template<class T>
class RingBuffer {

    T* _buf;
    int _size;
    int _pTail;
    int _pHead;
    // Implemented curr_size, instead of _empty
    int curr_size;

public:
    RingBuffer(int sz = 5)
    {
        _size = sz;
        _buf = new T[_size];
        _pHead = 0;
        _pTail = -1;
        curr_size = 0;
    }

    ~RingBuffer()
    {
        delete[] _buf;
    }

    int getSize() const { return curr_size; }

    bool isEmpty() const { return (!curr_size); }

    bool isFull() const { return (curr_size == _size); }

    void push(const T& value)
    {
        if (isFull())
        {
            throw std::out_of_range("Buffer is full");
        }
        else
        {
            if (_pTail != _size - 1)
            {
                _pTail++;
                _buf[_pTail] = value;
            }
            else
            {
                _pTail = 0;
                _buf[_pTail] = value;
            }
            curr_size++;
        }
    }

    T& front()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Buffer is empty");
        }
        else
        {
            return _buf[_pHead];
        }
    }

    T& back()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Buffer is empty");
        }
        else
        {
            return _buf[_pTail];
        }
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Buffer is empty");
        }

        int pos = _pHead;

        if (_pHead != _size - 1)
        {
            _pHead++;
        }
        else
        {
            _pHead = 0;
        }

        curr_size--;
        return _buf[pos];
    }

    RingBuffer(const RingBuffer<T>& other)
    {
        _size = other._size;
        _pHead = other._pHead;
        _pTail = other._pTail;
        curr_size = other.curr_size;
        _buf = new T[_size];
        if (_pHead <= _pTail)
        {
            for (int i = _pHead; i <= _pTail; i++)
                _buf[i] = other._buf[i];
        }
        else
        {
            for (int i = _pHead; i < _size; i++)
                _buf[i] = other._buf[i];
            for (int i = 0; i <= _pTail; i++)
                _buf[i] = other._buf[i];
        }
    }

    RingBuffer<T> operator=(const RingBuffer<T>& rhv)
    {
        if (this != &rhv)
        {
            if (_size != rhv._size)
            {
                _size = rhv._size;
                delete[] _buf;
                _buf = new T[_size];
            }

            _pHead = rhv._pHead;
            _pTail = rhv._pTail;
            curr_size = rhv.curr_size;

            if (_pHead <= _pTail)
            {
                for (int i = _pHead; i <= _pTail; i++)
                    _buf[i] = rhv._buf[i];
            }
            else
            {
                for (int i = _pHead; i < _size; i++)
                    _buf[i] = rhv._buf[i];
                for (int i = 0; i <= _pTail; i++)
                    _buf[i] = rhv._buf[i];
            }
        }
        return *this;
    }
};

#endif // RINGBUF_HPP
