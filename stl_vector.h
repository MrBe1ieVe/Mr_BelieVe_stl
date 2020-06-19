//
// Created by Mr.BelieVe on 2020/6/16.
//

#ifndef MR_BELIEVE_STL_STL_VECTOR_H
#define MR_BELIEVE_STL_STL_VECTOR_H

#include "stl_config.h"
#include "stl_alloc.h"
#include "stl_iterator.h"
#include "stl_uninitialized.h"

__STL_BEGIN_NAMESPACE

    template <class _Tp, class _Alloc>
    class _Vector_base {
    public:
        typedef _Alloc allocator_type;

        allocator_type get_allocator() const {return allocator_type();}

        _Vector_base(const _Alloc &)
                : _M_start(0), _M_finish(0), _M_end_of_storage(0) {}

        _Vector_base(size_t __n, const _Alloc &)
                : _M_start(0), _M_finish(0), _M_end_of_storage(0) {
            _M_start = _M_allocate(__n);
            _M_finish = _M_start;
            _M_end_of_storage = _M_start + __n;
        }

        ~_Vector_base() { _M_deallocate(_M_start, _M_end_of_storage - _M_start); }

    protected:
        _Tp *_M_start;
        _Tp *_M_finish;
        _Tp *_M_end_of_storage;

        typedef simple_alloc<_Tp, _Alloc> _M_data_allocator;

        _Tp *_M_allocate(size_t __n) {
            return _M_data_allocator::allocate(__n);
        }

        void _M_deallocate(_Tp *__p, size_t __n) {
            _M_data_allocator::deallocate(__p, __n);
        }
    };

    template <class _Tp, class _Alloc = alloc>
    class vector : protected _Vector_base<_Tp, _Alloc> {
    private:
        typedef _Vector_base<_Tp, _Alloc> _Base;
    public:
        typedef _Tp value_type;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        typedef value_type *iterator;
        typedef const value_type *const_iterator;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef typename _Base::allocator_type allocator_type;

        allocator_type get_allocator() const { return _Base::get_allocator(); }

        typedef reverse_iterator<const_iterator> const_reverse_iterator;
        typedef reverse_iterator<iterator> reverse_iterator;
    protected:
        using _Base::_M_allocate;
        using _Base::_M_deallocate;
        using _Base::_M_end_of_storage;
        using _Base::_M_finish;
        using _Base::_M_start;
    protected:
        void _M_insert_aux(iterator __position, const _Tp &__x>);

        void _M_insert_aux(iterator __position>);

    public:
        iterator begin() {
            return _M_start;
        }

        const_iterator begin() const {
            return _M_start;
        }

        iterator end() {
            return _M_finish;
        }

        const_iterator end() const {
            return _M_finish;
        }

        reverse_iterator rbegin() {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const {
            return reverse_iterator(end());
        }

        reverse_iterator rend() {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const {
            return reverse_iterator(begin());
        }

        size_type size() const {
            return size_type(end() - begin());
        }

        size_type max_size() const {
            return size_type(-1) / sizeof(_Tp);
        }

        size_type capacity() const {
            return size_type(_M_end_of_storage - begin());
        }

        bool empty() const {
            return begin() == end();
        }

        reference operator[](size_type __n) {
            return *(begin() + __n);
        }

        const reference operator[](size_type __n) const {
            return *(begin() + __n);
        }

        void _M_range_check(size_type __n) const {
            if(__n >= size())
            { throw; };
        }

        reference at(size_type __n) {
            _M_range_check(__n);
            return (*this)[__n];
        }

        const_reverse_iterator at(size_type __n) const {
            _M_range_check(__n);
            return (*this)[__n];
        }

        explicit vector(const allocator_type &__a = allocator_type()) : _Base(__a) {
        }

        vector(size_type __n, const _Tp &__value, const allocator_type &__a = allocator_type()) : _Base(__n, __a) {
            _M_finish = uninitialized_fill_n(_M_start, __n, __value);
        }

        explicit vector(size_type __n)
                : _Base(__n, allocator_type()) {
            _M_finish = uninitialized_fill_n(_M_start, __n, _Tp());
        }

        vector(const vector<_Tp, _Alloc> &__x) : _Base(__x.size(), __x,get_allocator()) {
            _M_finish = uninitialized_copy(__x.begin, __x.end(), _M_start);
        }

        template<class _InputIterator>
        vector(_InputIterator __first, _InputIterator __last, const allocator_type &__a = allocator_type()):_Base(__a) {
            typedef typename _Is_integer<_InputIterator>::_Intergal _Intergral;
            _M_initialize_aux(__first, __last, _Intergral())
        }
    };























__STL_END_NAMESPACE
#endif //MR_BELIEVE_STL_STL_VECTOR_H
