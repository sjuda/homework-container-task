#pragma once

#include <stdexcept>

template <typename T, size_t N>
struct array
{
    struct Iterator
        : public std::iterator<std::random_access_iterator_tag, T>
    {
        T * ptr;
        explicit Iterator(T* p)
            : ptr(p)
        { }

        T& operator*()
        {
            return *ptr;
        }

        T* operator->()
        {
            return ptr;
        }

        Iterator& operator++()
        {
            ++ptr;
            return *this;
        }
        Iterator operator++(int /*unused*/)
        {
            Iterator it(ptr);
            ++ptr;
            return it;
        }
        Iterator& operator+=(size_t n)
        {
            ptr += n;
            return *this;
        }
        Iterator& operator-=(size_t n)
        {
            ptr -= n;
            return *this;
        }

        Iterator& operator--()
        {
            --ptr;
            return *this;
        }

        Iterator operator--(int /*unused*/)
        {
            Iterator it(ptr);
            --ptr;
            return it;
        }

        bool operator==(Iterator it)
        {
            return ptr == it.ptr;
        }

        bool operator<(Iterator it)
        {
            return ptr < it.ptr;
        }

        bool operator<=(Iterator it)
        {
            return this->operator==(it) || this->operator<(it);
        }

        bool operator>(Iterator it)
        {
            return !(this->operator==(it) || this->operator<(it));
        }

        bool operator>=(Iterator it)
        {
            return !this->operator<(it);
        }

        bool operator!=(Iterator it)
        {
            return !(this->operator==(it));
        }
    };

    using value_type = T;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = T*;
    using const_pointer = const T*;
    using iterator = Iterator;
    using const_iterator = const Iterator;

    T data[N];

    ~array() = default;
    array() = default;

    size_type size() const noexcept
    {
        return N;
    }

    reference operator[](size_type ind)
    {
        return data[ind];
    }

    const_reference operator[](size_type ind) const
    {
        return data[ind];
    }

    reference at(size_type ind)
    {
        if (ind < size())
            return data[ind];
        throw std::out_of_range("out_of_range");
    }

    const_reference at(size_type ind) const
    {
        if (ind < size())
            return data[ind];
        throw std::out_of_range("out_of_range");
    }

    reference front()
    {
        return data[0];
    }

    const_reference front() const
    {
        return data[0];
    }

    reference back()
    {
        return data[size() - 1];
    }

    const_reference back() const
    {
        return data[size() - 1];
    }

    iterator begin()
    {
        return iterator(data);
    }

    const_iterator begin() const
    {
        return const_iterator(data);
    }

    iterator end()
    {
        return iterator(data + size());
    }

    const_iterator end() const
    {
        return const_iterator(data + size());
    }

    bool empty() const
    {
        return size() == 0;
    }

    void swap(array& oth)
    {
        for (size_type i = 0; i < size(); ++i)
        {
            std::swap(oth[i], data[i]);
        }
    }

    void fill(const T& value)
    {
        std::fill(this->begin(), this->end(), value);
    }
};

template<class T, size_t N>
bool operator==(const array<T, N>& a, const array<T, N>& b)
{
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

template<class T, size_t N>
bool operator!=(const array<T, N>& a, const array<T, N>& b)
{
    return !(a == b);
}
