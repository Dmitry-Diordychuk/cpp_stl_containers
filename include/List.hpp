/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:35:37 by marvin            #+#    #+#             */
/*   Updated: 2021/04/15 17:35:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <limits>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"

namespace ft
{
	/**
	 * @brief double-linked list
	 *
	 * @tparam T value type.
	 * @tparam Alloc allocator.
	 */
	template <typename T, typename Alloc = std::allocator<T> >
	class List
	{
	public:
		typedef T										value_type;
		typedef Alloc									allocator_type;
		typedef T&										reference;
		typedef const T&								const_reference;
		typedef T*										pointer;
		typedef const T*								const_pointer;
		typedef typename Alloc::difference_type			difference_type;
		typedef size_t									size_type;

		template <typename Tp, typename Ref, typename Ptr>
		class _List_iterator;

		typedef _List_iterator<T, T&, T*>				iterator;
		typedef _List_iterator<T, const T&, const T*>	const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	private:
		allocator_type		_allocator;
		size_type			_n;
		typedef struct		s_node
		{
			pointer		data;
			s_node		*next;
			s_node		*prev;
		}					t_node;
		t_node				*_begin;
		t_node				*_end;

		t_node *createNode(const value_type& val) {
			pointer p = _allocator.allocate(1);
			_allocator.construct(p, val);
			t_node *node = new t_node();
			node->data = p;
			node->next = NULL;
			node->prev = NULL;
			return (node);
		};

		t_node *createEnd() {
			t_node *node = new t_node();
			node->data = new T();
			node->next = NULL;
			node->prev = NULL;
			return (node);
		};

		t_node *lastNode() {
			return (this->_end->prev);
		};

	public:
		// CONSTRUCTORS
		explicit List (const allocator_type& alloc = allocator_type())
			:	_allocator(alloc),
				_n(0)
		{
			this->_end = createEnd();
			_begin = this->_end;
		};

		explicit List (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type())
			:	_allocator(alloc),
				_n(0)
		{
			this->_end = createEnd();
			_begin = this->_end;
			this->assign(n, val);
		};

		template <class InputIterator>
		List (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if< !ft::is_integral<InputIterator>::value >::type* = 0)
			:	_allocator(alloc),
				_n(0)
		{
			this->_end = createEnd();
			_begin = this->_end;
			this->assign(first, last);
		};

		List (const List& x)
			:	_allocator(x._allocator),
				_n(0)
		{
			this->_end = createEnd();
			_begin = this->_end;
			this->assign(x.begin(), x.end());
		};

		//DESTRUCTOR
		~List() {
			while (_begin != _end)
			{
				t_node *temp = _begin->next;
				_allocator.destroy(_begin->data);
				_allocator.deallocate(_begin->data, -1);
				delete _begin;
				_begin = temp;
			}
			delete _end->data;
			delete _end;
		};

		//Operator =
		List& operator= (const List& x){
			if (this == &x)
				return (*this);
			this->_allocator = x._allocator;
			this->_begin = this->_end;
			this->assign(x.begin(), x.end());
			return (*this);
		};

		// Iterators
		iterator begin() {
			if (_n != 0)
			{
				iterator it(this->_begin);
				return (it);
			}
			iterator it(_end);
			return (it);
		};

		const_iterator begin() const{
			if (_n != 0)
			{
				const_iterator it(this->_begin);
				return (it);
			}
			const_iterator it(_end);
			return (it);
		};

		iterator end() {
			iterator it(_end);
			return (it);
		};

		const_iterator end() const{
			const_iterator it(_end);
			return (it);
		};

		reverse_iterator rbegin() {
			reverse_iterator rev_it(_end);
			return (rev_it);
		};

		const_reverse_iterator rbegin() const{
			reverse_iterator rev_it(_end);
			return (rev_it);
		};

		reverse_iterator rend() {
			reverse_iterator rev_it(_begin);
			return (rev_it);
		};

		const_reverse_iterator rend() const{
			reverse_iterator rev_it(_begin);
			return (rev_it);
		};

		// Capacity
		bool empty() const {
			if (_n == 0)
				return (true);
			return (false);
		};

		size_type size() const {
			return (_n);
		};

		size_type max_size() const {
			return (std::numeric_limits<size_type>::max());
		};

		// Element access
		reference front() {
			return (*(this->begin()));
		};

		const_reference front() const {
			return (*(this->begin()));
		};

		reference back() {
			iterator it = this->end();
			--it;
			return (*it);
		}

		const_reference back() const {
			const_iterator it = this->end();
			--it;
			return (*it);
		}

		// Modifiers
		template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
			typename ft::enable_if< !ft::is_integral<InputIterator>::value >::type* = 0)
		{
			this->clear();
			for (; first != last; ++first)
				push_back(*first);
		}

		void assign (size_type n, const value_type& val) {
			this->clear();
			for (size_type i = 0; i < n; ++i)
				push_back(val);
		};

		void push_front (const value_type& val) {
			if (_n < max_size())
			{
				t_node *node = createNode(val);
				node->next = _begin;
				_begin->prev = node;
				_begin = node;
				++_n;
			}
		};

		void pop_front() {
			if (_n != 0)
			{
				t_node *temp = _begin;
				_begin = _begin->next;
				_begin->prev = NULL;
				_allocator.destroy(temp->data);
				_allocator.deallocate(temp->data, -1);
				delete temp;
				--_n;
			}
		};

		void push_back (const value_type& val) {
			if (_n < max_size())
			{
				t_node *node = createNode(val);
				t_node *last = lastNode();
				if (last != NULL)
				{
					node->prev = last;
					last->next = node;
				}
				else
					_begin = node;
				node->next = this->_end;
				this->_end->prev = node;
				++_n;
			}
		};

		void pop_back() {
			if (_n != 0)
			{
				t_node *last = lastNode();
				if (last->prev != NULL)
					last->prev->next = this->_end;
				else
					_begin = _end;
				this->_end->prev = last->prev;
				_allocator.destroy(last->data);
				_allocator.deallocate(last->data, -1);
				delete last;
				--_n;
			}
		};

		iterator insert (iterator position, const value_type& val){
			t_node		*new_node = createNode(val);
			t_node		*prev = position.getPrev();
			t_node		*next = position.getCurrent();
			iterator	result;

			new_node->next = next;
			if (new_node->next)
				new_node->next->prev = new_node;
			new_node->prev = prev;
			if (new_node->prev)
				new_node->prev->next = new_node;
			_n++;
			result.setCurrent(new_node);
			result.setPrev(new_node->prev);
			result.setNext(new_node->next);
			if (!new_node->prev)
				_begin = new_node;
			return (result);
		};

		void insert (iterator position, size_type n, const value_type& val)
		{
			for (size_type i = 0; i < n; ++i)
				position = this->insert(position, val);
		};

		template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if< !ft::is_integral<InputIterator>::value >::type* = 0)
		{
			--last;
			for (; last != first; --last)
				position = this->insert(position, *last);
			position = this->insert(position, *last);
		};

		iterator erase (iterator position) {
			t_node *next = position.getNext();
			t_node *prev = position.getPrev();
			iterator result;

			if (_n == 0 || position.getCurrent() == _end)
			{
				result.setCurrent(_end);
				result.setPrev(NULL);
				result.setNext(NULL);
				return (result);
			}
			if (position.getCurrent() == _begin)
				_begin = position.getNext();
			delete position.getCurrent();
			if (next)
				next->prev = prev;
			if (prev)
				prev->next = next;
			result.setCurrent(next);
			result.setPrev(next->prev);
			result.setNext(next->next);
			--this->_n;
			return (result);
		};

		iterator erase (iterator first, iterator last) {
			while (first != last)
				first = this->erase(first);
			return (last);
		};

		void swap (List& x) {
			t_node *temp_begin = this->_begin;
			t_node *temp_end = this->_end;
			size_type temp_n = this->_n;
			this->_begin = x._begin;
			this->_end = x._end;
			this->_n = x._n;
			x._begin = temp_begin;
			x._end = temp_end;
			x._n = temp_n;
		};

		void resize (size_type n, value_type val = value_type()) {
			while (_n > n)
				this->pop_back();
			while (_n < n)
				this->push_back(val);
		};

		void clear() {
			while (_n != 0)
				this->pop_back();
			_end->next = NULL;
			_end->prev = NULL;
		};

		// Operations
		//void splice (iterator position, List& x);
		//void splice (iterator position, List& x, iterator i);
		//void splice (iterator position, List& x, iterator first, iterator last);
		void remove (const value_type& val);
		template <class Predicate>
			void remove_if (Predicate pred);
		void unique();
		template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred);
		void merge (List& x);
		template <class Compare>
			void merge (List& x, Compare comp);
		void sort();
		template <class Compare>
			void sort (Compare comp);
		void reverse();

		class _List_iterator_base
		{
			private:
				t_node *_next;
				t_node *_prev;
				t_node *_cur;
			public:
				_List_iterator_base() {};
				_List_iterator_base(t_node *node) : _next(node->next), _prev(node->prev), _cur(node) {};
				_List_iterator_base(const _List_iterator_base& x) : _next(x._next), _prev(x._prev), _cur(x._cur) {};
				~_List_iterator_base() {};
				_List_iterator_base& operator=(const _List_iterator_base& rhs){
					this->_next = rhs._next;
					this->_prev = rhs._prev;
					this->_cur = rhs._cur;
					return (*this);
				};

				t_node	*getCurrent() const {return (_cur);};
				t_node	*getPrev() const {return (_prev);};
				t_node	*getNext() const {return (_next);};
				void	setCurrent(t_node *cur) {_cur = cur;};
				void	setPrev(t_node *prev) {_prev = prev;};
				void	setNext(t_node *next) {_next = next;};

				bool operator== (const _List_iterator_base& other) const {return (this->_cur == other._cur);};
				bool operator!= (const _List_iterator_base& other) const {return (this->_cur != other._cur);};

				_List_iterator_base& increment () {
					if (this->_next != NULL)
					{
						t_node *temp = this->_next;
						this->_next = temp->next;
						this->_prev = temp->prev;
						this->_cur = temp;
					}
					return (*this);
				};

				_List_iterator_base& decrement () {
					if (this->_prev != NULL)
					{
						t_node *temp = this->_prev;
						this->_next = temp->next;
						this->_prev = temp->prev;
						this->_cur = temp;
					}
					return (*this);
				};
		};

		template <typename Tp, typename Ref, typename Ptr>
		class _List_iterator : public _List_iterator_base
		{
			public:
				typedef _List_iterator<Tp, Tp&, Tp*>				iterator;
				typedef _List_iterator<Tp, Ref, Ptr>				self;

				typedef bidirectional_iterator_tag					iterator_category;
				typedef Tp											value_type;
				typedef std::ptrdiff_t								difference_type;
				typedef Ptr											pointer;
				typedef Ref											reference;

				_List_iterator() {};
				_List_iterator(t_node *current) : _List_iterator_base(current) {};
				_List_iterator(const iterator& other) : _List_iterator_base(other) {};
				~_List_iterator() {};

				self& operator= (const iterator& rhs) {
					_List_iterator_base::operator=(rhs);
					return (*this);
				};
				self& operator++ () {
					this->increment();
					return (*this);
				};
				self& operator++ (int) {
					this->increment();
					return (*this);
				};
				self& operator-- () {
					this->decrement();
					return (*this);
				};
				self& operator-- (int) {
					this->decrement();
					return (*this);
				};
				bool operator== (const self& other) const {
					return (_List_iterator_base::operator==(other));
				};
				bool operator!= (const self& other) const {
					return (_List_iterator_base::operator!=(other));
				};

				reference operator*() const {
					return (*this->getCurrent()->data);
				};

				pointer operator->() const {
					return (this->getCurrent()->data);
				};
		};
	};

	//Non member overload
	// template <class T, class Alloc>
	// 	bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// 	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// 	bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// 	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// 	bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// 	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// 	void swap (list<T,Alloc>& x, list<T,Alloc>& y);
}

#endif // !LIST_HPP
