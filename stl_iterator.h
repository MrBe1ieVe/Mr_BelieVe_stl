//
// Created by Mr.BelieVe on 2020/6/4.
//

#ifndef MR_BELIEVE_STL_STL_ITERATOR_H
#define MR_BELIEVE_STL_STL_ITERATOR_H

#include "stl_config.h"
#include "stl_iterator_base.h"

__STL_BEGIN_NAMESPACE
    template<class _Container>
    class back_insert_iterator {
    protected:
        _Container *container;
    public:
        typedef _Container container_type;
        typedef output_iterator_tag iterator_category;
        typedef void value_type;
        typedef void difference_type;
        typedef void pointer;
        typedef void reference;

        explicit back_insert_iterator(_Container &__x) : container(&__x) {}

        back_insert_iterator<_Container> &operator=(const typename _Container::value_type &__value) {
            container->push_back(__value);
            return *this;
        }

        back_insert_iterator<_Container> &operator*() { return *this; }

        back_insert_iterator<_Container> &operator++() { return *this; }

        back_insert_iterator<_Container> &operator++(int) { return *this; }
    };

    template<class _Container>
    inline back_insert_iterator<_Container> back_inserter(_Container &__x) {
        return back_insert_iterator<_Container>(__x);
    }

    template<class _Container>
    class front_insert_iterator {
    protected:
        _Container *container;
    public:
        typedef _Container container_type;
        typedef output_iterator_tag iterator_category;
        typedef void value_type;
        typedef void difference_type;
        typedef void pointer;
        typedef void reference;

        explicit front_insert_iterator(_Container &__x) : container(&__x) {}

        front_insert_iterator<_Container> &operator=(const typename _Container::value_type &__value) {
            container->push_front(__value);
            return *this;
        }

        front_insert_iterator<_Container> &operator*() { return *this; }

        front_insert_iterator<_Container> &operator++() { return *this; }

        front_insert_iterator<_Container> &operator++(int) { return *this; }
    };

    template<class _Container>
    inline front_insert_iterator<_Container> front_inserter(_Container &__x) {
        return front_insert_iterator<_Container>(__x);
    }

    template<class _Container>
    class insert_iterator {
    protected:
        _Container *container;
        typename _Container::iterator iter;
    public:
        typedef _Container container_type;
        typedef output_iterator_tag iterator_category;
        typedef void value_type;
        typedef void difference_type;
        typedef void pointer;
        typedef void reference;

        insert_iterator(_Container &__x, typename _Container::iterator __i) : container(&__x), iter(__i) {}

        insert_iterator<_Container> &operator=(const typename _Container::value_type &__value) {
            iter = container->insert(iter, __value);//将元素插入到iter指向的元素之前的位置
            ++iter;//指向原来的元素
            return *this;
        }

        insert_iterator<_Container> &operator*() { return *this; }

        insert_iterator<_Container> &operator++() { return *this; }

        insert_iterator<_Container> &operator++(int) { return *this; }
    };

    template<class _Container, class _Iterator>
    inline insert_iterator<_Container> inserter(_Container &__x, _Iterator __i) {
        typedef typename _Container::iterator __iter;
        return insert_iterator<_Container>(__x, __iter(__i));
    }

    template<class _Iterator>
    class reverse_iterator {
    protected:
        _Iterator current;  //对应正向迭代器
    public:
            //5个迭代器与正向迭代器相同
        typedef typename iterator_traits<_Iterator>::iterator_category
                iterator_category;
        typedef typename iterator_traits<_Iterator>::value_type
                value_type;
        typedef typename iterator_traits<_Iterator>::difference_type
                difference_type;
        typedef typename iterator_traits<_Iterator>::pointer
                pointer;
        typedef typename iterator_traits<_Iterator>::reference
                reference;

        typedef _Iterator iterator_type;//对应正向迭代器
        typedef reverse_iterator<_Iterator> _Self;//逆向
    public:
        reverse_iterator() {}

        explicit reverse_iterator(iterator_type __x) : current(__x) {}

        reverse_iterator(const _Self &__x) : current(__x.current) {}

        template<class _Iter>
        reverse_iterator(const reverse_iterator<_Iter> &__other):current(__other.base()) {}

        iterator_type base() const {
            return current;
        }

        reference operator*() const {
            _Iterator __tmp = current;
            return *--__tmp;
        }//关键。对逆向迭代器取值，即为对应的正向迭代器退一位取值

        pointer operator->() const {
            return &(operator*());
        }
        //下面都是，前进变成后退，后退变成前进（因为正向前进等于逆向的倒退
        _Self &operator++() {
            --current;
            return *this;
        }

        _Self operator++(int) {
            _Self __tmp = *this;
            --current;
            return __tmp;
        }

        _Self &operator--() {
            ++current;
            return *this;
        }

        _Self operator--(int) {
            _Self __tmp = *this;
            ++current;
            return __tmp;
        }

        _Self operator+(difference_type __n) const {
            return _Self(current - __n);
        }

        _Self operator-(difference_type __n) const {
            return _Self(current + __n);
        }

        _Self &operator+=(difference_type __n) {
            current -= __n;
            return *this;
        }

        _Self &operator-=(difference_type __n) {
            current += __n;
            return *this;
        }

        reference operator[](difference_type __n) const {
            //base()[-n-1]
            return *(*this + __n);
        }
    };

    template<class _Iterator>
    inline bool operator==(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs) {
        return __lhs.base() == __rhs.base();
    }

    template<class _Iterator>
    inline bool operator!=(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs) {
        return !(__lhs == __rhs);
    }

    template<class _Iterator>
    inline bool operator<(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs) {
        return __rhs.base() < __lhs.base();//逆向的lhs.base()等于正向的rhs.base()，画图容易理解
    }

    template<class _Iterator>
    inline bool operator>(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs) {
        return __lhs > __rhs ;
    }

    template<class _Iterator>
    inline bool operator<=(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs) {
        return !(__lhs > __rhs);
    }

    template<class _Iterator>
    inline bool operator>=(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs) {
        return !(__lhs < __rhs);
    }

    template<class _Iterator>
    reverse_iterator<_Iterator>
    operator+(typename reverse_iterator<_Iterator>::difference_type __n,
              const reverse_iterator<_Iterator> &__x) {
        //return it + n;正向 + n，逆向 - n
        return reverse_iterator<_Iterator>(__x.base() - __n);
    }

    template<class _Iterator>
    typename reverse_iterator<_Iterator>::difference_type
    operator-(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs) {
        return __rhs.base() - __lhs.base();
    }
__STL_END_NAMESPACE
#endif //MR_BELIEVE_STL_STL_ITERATOR_H
