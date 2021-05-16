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
# define LIST_HPP

# include <limits>
# include "iterator.hpp"
# include "reverse_iterator.hpp"

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
	private:
		typedef T								value_type;
		typedef Alloc							allocator_type;
		typedef T&								reference;
		typedef const T&						const_reference;
		typedef T*								pointer;
		typedef const T*						const_pointer;
		typedef typename Alloc::difference_type	difference_type;
		typedef size_t							size_type;

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

		t_node *lastNode()
		{
			return (this->_end->prev);
		};

	public:
		// CONSTRUCTORS
		explicit List (const allocator_type& alloc = allocator_type())
			:	_allocator(alloc),
				_n(0),
				_begin(NULL)
		{
			this->_end = createEnd();
			_begin = this->_end;
		};

		explicit List (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type())
			:	_allocator(alloc),
				_n(0),
				_begin(NULL)
		{
			this->_end = createEnd();
			_begin = this->_end;
			for (int i = 0; i < n; ++i)
				push_back(val);
		};

		// template <class InputIterator>
		// List (InputIterator first, InputIterator last,
		// 	const allocator_type& alloc = allocator_type()){

		// };

		List (const List& x)
			:	_allocator(x._allocator),
				_n(0),
				_begin(NULL)
		{
			this->_end = createEnd();
			_begin = this->_end;
			const_iterator it = x.begin();
			for (; it != x.end(); ++it)
				this->push_back(*it);
		};

		//DESTRUCTOR
		~List()
		{
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
		//Operator
		List& operator= (const List& x);
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
		}
		// Element access
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		// Modifiers
		// template <class InputIterator>
		// 	void assign (InputIterator first, InputIterator last);
		void assign (size_type n, const value_type& val);
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
		//iterator insert (iterator position, const value_type& val);
		//void insert (iterator position, size_type n, const value_type& val);
		// template <class InputIterator>
		// 	void insert (iterator position, InputIterator first, InputIterator last);
		//iterator erase (iterator position);
		//iterator erase (iterator first, iterator last);
		void swap (List& x);
		void resize (size_type n, value_type val = value_type());
		void clear();
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

		class iterator
		{
			private:
				t_node	*_next;
				t_node	*_prev;
				t_node	*_cur;
			public:
				typedef bidirectional_iterator_tag	iterator_category;
				typedef value_type					value_type;
				typedef difference_type				difference_type;
				typedef pointer						pointer;
				typedef reference					reference;

				iterator() : _next(NULL), _prev(NULL), _cur(NULL) {};
				iterator(t_node *current) : _next(current->next), _prev(current->prev), _cur(current) {};
				iterator(const iterator& other) : _next(other._next), _prev(other._prev), _cur(other._cur) {};
				~iterator() {};

				iterator& operator= (const iterator& rhs) {
					if (this == &rhs)
						return (*this);
					this->_next = rhs._next;
					this->_prev = rhs._prev;
					this->_cur = rhs._cur;
					return (*this);
				};
				bool operator== (const iterator& other) const {
					if (this->_cur == other._cur)
						return (true);
					return (false);
				};
				bool operator!= (const iterator& other) const {
					if (this->_cur != other._cur)
						return (true);
					return (false);
				};
				iterator& operator++ () {
					if (this->_next != NULL)
					{
						t_node *temp = this->_next;
						this->_next = temp->next;
						this->_prev = temp->prev;
						this->_cur = temp;
					}
					return (*this);
				};
				iterator& operator++ (int) {
					if (this->_next != NULL)
					{
						t_node *temp = this->_next;
						this->_next = temp->next;
						this->_prev = temp->prev;
						this->_cur = temp;
					}
					return (*this);
				};
				iterator& operator-- () {
					if (this->_prev != NULL)
					{
						t_node *temp = this->_prev;
						this->_next = temp->next;
						this->_prev = temp->prev;
						this->_cur = temp;
					}
					return (*this);
				};
				iterator& operator-- (int) {
					if (this->_prev != NULL)
					{
						t_node *temp = this->_prev;
						this->_next = temp->next;
						this->_prev = temp->prev;
						this->_cur = temp;
					}
					return (*this);
				};

				reference operator*() const {
					return (*_cur->data);
				};
				pointer operator->() const {
					return (_cur->data);
				};
		};

		class const_iterator
		{
			private:
				t_node	*_next;
				t_node	*_prev;
				t_node	*_cur;
			public:
				typedef bidirectional_iterator_tag	iterator_category;
				typedef const value_type			value_type;
				typedef difference_type				difference_type;
				typedef const pointer				pointer;
				typedef const T&					reference;

				const_iterator() : _next(NULL), _prev(NULL), _cur(NULL) {};
				const_iterator(const iterator&) {};
				const_iterator(t_node *current) : _next(current->next), _prev(current->prev), _cur(current) {};
				const_iterator(const const_iterator& other) : _next(other._next), _prev(other._prev), _cur(other._cur) {};
				~const_iterator() {};

				const_iterator& operator= (const const_iterator& rhs) {
					if (this == &rhs)
						return (*this);
					this->_next = rhs._next;
					this->_prev = rhs._prev;
					this->_cur = rhs._cur;
					return (*this);
				};
				bool operator== (const const_iterator& other) const {
					if (this->_cur == other._cur)
						return (true);
					return (false);
				};
				bool operator!= (const const_iterator& other) const {
					if (this->_cur != other._cur)
						return (true);
					return (false);
				};
				const_iterator& operator++ () {
					if (this->_next != NULL)
					{
						t_node *temp = this->_next;
						this->_next = temp->next;
						this->_prev = temp->prev;
						this->_cur = temp;
					}
					return (*this);
				};
				const_iterator& operator++ (int) {
					if (this->_next != NULL)
					{
						t_node *temp = this->_next;
						this->_next = temp->next;
						this->_prev = temp->prev;
						this->_cur = temp;
					}
					return (*this);
				};
				const_iterator& operator-- () {
					if (this->_prev != NULL)
					{
						t_node *temp = this->_prev;
						this->_next = temp->next;
						this->_prev = temp->prev;
						this->_cur = temp;
					}
					return (*this);
				};
				const_iterator& operator-- (int) {
					if (this->_prev != NULL)
					{
						t_node *temp = this->_prev;
						this->_next = temp->next;
						this->_prev = temp->prev;
						this->_cur = temp;
					}
					return (*this);
				};

				reference operator*() const {
					return (*_cur->data);
				};
				pointer operator->() const {
					return (_cur->data);
				};
		};

		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

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
