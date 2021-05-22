/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 01:11:51 by kdustin           #+#    #+#             */
/*   Updated: 2021/05/23 00:09:59 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <limits>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class Vector
	{
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef T&											reference;
		typedef const T&									const_reference;
		typedef T*											pointer;
		typedef const T*									const_pointer;
		typedef typename Alloc::difference_type				difference_type;
		typedef size_t										size_type;

		typedef pointer										iterator;
		typedef const_pointer								const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:
		allocator_type	_allocator;
		size_type		_n;
		pointer			_start;
		pointer			_finish;
		pointer			_end_of_storage;

	public:
		explicit Vector (const allocator_type& alloc = allocator_type())
		 : _allocator(alloc), _n(0), _start(NULL), _finish(NULL), _end_of_storage(NULL) {};

		explicit Vector (size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type())
		 : _allocator(alloc), _n(0), _start(NULL), _finish(NULL), _end_of_storage(NULL) {
			if (n < _allocator.max_size())
			{
				_start = _allocator.allocate(n);
				_end_of_storage = _start + n - 1;
				size_type i = -1;
				while (++i < n)
					_allocator.construct(_start + i, val);
				_finish = _start + i - 1;
				_n = n;
			}
		};

		template <class InputIterator>
		Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if< !ft::is_integral<InputIterator>::value >::type* = 0) {
			InputIterator temp = first;
			_n = 0;
			while (temp != last)
			{
				++_n;
				++temp;
			}
			_allocator = alloc;
			_start = _allocator.allocate(_n);
			_end_of_storage = _start + _n - 1;
			size_type i = 0;
			while (first != last)
			{
				_allocator.construct(_start + i, *first);
				++first;
				++i;
			}
			_finish = _start + _n - 1;
		};

		Vector (const Vector& x) {
			this->_allocator = x._allocator;
			this->_n = x._n;
			this->_start = this->_allocator.allocate(_n);
			this->_end_of_storage = this->_start + this->_n - 1;
			const_iterator it = x.begin();
			size_type i = 0;
			while (it != x.end())
			{
				this->_allocator.construct(_start + i, *it);
				++it;
				++i;
			}
			this->_finish = _start + _n - 1;
		};

		~Vector() {
			if (_start)
			{
				size_type i = -1;
				while (++i < _n)
					_allocator.destroy(_start + i);
				_allocator.deallocate(_start, _n);
			}
		};

		Vector& operator= (const Vector& x) {
			if (_start)
			{
				size_type i = -1;
				while (++i < _n)
					_allocator.destroy(_start + i);
				_allocator.deallocate(_start, _n);
			}
			this->_allocator = x._allocator;
			this->_n = x._n;
			this->_start = this->_allocator.allocate(_n);
			this->_end_of_storage = this->_start + this->_n - 1;
			const_iterator it = x.begin();
			size_type i = 0;
			while (it != x.end())
			{
				this->_allocator.construct(_start + i, *it);
				++it;
				++i;
			}
			this->_finish = _start + _n - 1;
			return (*this);
		};

		iterator begin() {
			return (_start);
		};

		const_iterator begin() const {
			return (_start);
		};

		iterator end() {
			return (_finish + 1);
		};

		const_iterator end() const {
			return (_finish + 1);
		};

		reverse_iterator rbegin() {
			reverse_iterator rit(_finish + 1);
			return (rit);
		};

		const_reverse_iterator rbegin() const {
			reverse_iterator rit(_finish + 1);
			return (rit);
		};

		reverse_iterator rend() {
			reverse_iterator rit(_start);
			return (rit);
		};

		const_reverse_iterator rend() const {
			reverse_iterator rit(_start);
			return (rit);
		};

		size_type size() const {
			return (_n);
		};

		size_type max_size() const{
			return (std::numeric_limits<size_type>::max() / sizeof(T));
		};

		// void resize (size_type n, value_type val = value_type());

		// size_type capacity() const;

		// bool empty() const;

		// void reserve (size_type n);

		// reference operator[] (size_type n);
		// const_reference operator[] (size_type n) const;

		// reference at (size_type n);
		// const_reference at (size_type n) const;

		// reference front();
		// const_reference front() const;

		// reference back();
		// const_reference back() const;

		// template <class InputIterator>
		// void assign (InputIterator first, InputIterator last);
		// void assign (size_type n, const value_type& val);

		// void push_back (const value_type& val);

		// void pop_back();

		// iterator insert (iterator position, const value_type& val);
		// void insert (iterator position, size_type n, const value_type& val);
		// template <class InputIterator>
		// void insert (iterator position, InputIterator first, InputIterator last);

		// iterator erase (iterator position);
		// iterator erase (iterator first, iterator last);

		// void swap (vector& x);

		// void clear();
	};

	// template <class T, class Alloc>
	// bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y);

	// template < class T, class Alloc = std::allocator<T> > class Vector;	// generic template
	// template <class Alloc> class Vector<bool,Alloc>;					// bool specialization
}

#endif // !VECTOR_HPP
