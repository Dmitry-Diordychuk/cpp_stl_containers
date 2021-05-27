/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:17:35 by kdustin           #+#    #+#             */
/*   Updated: 2021/05/28 00:38:42 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <limits>
#include <memory>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"
#include "Pair.hpp"

namespace ft
{
    template <class Arg1, class Arg2, class Result>
    struct binary_function {
        typedef Arg1 first_argument_type;
        typedef Arg2 second_argument_type;
        typedef Result result_type;
    };

    template <class T>
    struct less : ft::binary_function <T,T,bool>
    {
        bool operator() (const T& x, const T& y) const { return x<y; }
    };

    template < class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<Pair<const Key,T> > >
    class Map
    {
    public:
        typedef Key                                 key_type;
        typedef T                                   mapped_type;
        typedef Pair<const key_type, mapped_type>   value_type;
        typedef Compare                             key_compare;
        typedef Alloc                               allocator_type;
        typedef typename Alloc::reference           reference;
        typedef typename Alloc::const_reference     const_reference;
        typedef typename Alloc::pointer	            pointer;
        typedef typename Alloc::const_pointer       const_pointer;
        typedef typename Alloc::difference_type		difference_type;
		typedef size_t								size_type;

        template <typename Tp, typename Ref, typename Ptr>
        class _Map_iterator;

		typedef _Map_iterator<value_type, value_type&, value_type*>				iterator;
		typedef _Map_iterator<value_type, const value_type&, const value_type*>	const_iterator;
		typedef ft::reverse_iterator<iterator>			                        reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	                        const_reverse_iterator;

        class value_compare : ft::binary_function <key_type, key_type, bool>
        {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
            public:
                Compare comp;
                value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object

                typedef bool result_type;
                typedef value_type first_argument_type;
                typedef value_type second_argument_type;
                bool operator() (const value_type& x, const value_type& y) const
                {
                    return comp(x.first, y.first);
                }
        };

    private:
        struct node
        {
            bool        is_red;
            bool        is_nil;
            node*       parent;
            node*       left;
            node*       right;
            value_type* val;

            node() {};
            ~node() {};
        };

        allocator_type          _allocator;
        std::allocator<node>    _node_allocator;

        value_compare   _comp;
        node*           _tree;
        node*           _nil;

        node *createNode(key_type key, mapped_type data)
        {
            node* p = _node_allocator.allocate(1);
            _node_allocator.construct(p, node());
            p->val = _allocator.allocate(1);
            _allocator.construct(p->val, value_type(key, data));
            p->is_red = false;
            p->is_nil = false;
            return (p);
        }

        void deleteNode(node *n)
        {
            _allocator.destroy(n->val);
            _allocator.deallocate(n->val, 1);
            _node_allocator.destroy(n);
            _node_allocator.deallocate(n, 1);
        }

        void createNil()
        {
            _nil = createNode(key_type(), mapped_type());
            _nil->is_nil = true;
            _nil->left = NULL;
            _nil->right = NULL;
            _nil->parent = NULL;
        }

        node *cloneNode(node *prev_node)
        {
            std::allocator<node> alloc;
            node* new_node = alloc.allocate(1);
            alloc.construct(new_node, node());
            new_node->val = _allocator.allocate(1);
            _allocator.construct(new_node->val, value_type(prev_node->val->first, prev_node->val->second));
            new_node->is_red = prev_node->is_red;
            new_node->is_nil = prev_node->is_nil;
            return (new_node);
        }

        static node *rbTreeMin(node *x)
        {
            while (x->left->is_nil != true)
                x = x->left;
            return (x);
        }

        static node *rbTreeMax(node *x)
        {
            while (x->right->is_nil != true)
                x = x->right;
            return (x);
        }

        node *rbTreeSearch(node *x, key_type key)
        {
            while (x->is_nil != true && key != x->val->first)
                if (key < x->val->first)
                    x = x->left;
                else
                    x = x->right;
            return (x);
        }

        static node *rbTreeSuccessor(node *x)
        {
            if (x->right->is_nil != true)
                return (rbTreeMin(x->right));
            node *y = x->parent;
            while (y->is_nil != true && x == y->right)
            {
                x = y;
                y = y->parent;
            }
            return (y);
        }

        static node *rbTreePredecessor(node *x)
        {
            if (x->left->is_nil != true)
                return (rbTreeMax(x->left));
            node *y = x->parent;
            while (y->is_nil != true && x != y->right)
            {
                x = y;
                y = y->parent;
            }
            return (y);
        }

        void rbLeftRotate(node *x)
        {
            node *y = x->right;
            x->right = y->left;

            if (y->left != _nil)
                y->left->parent = x;
            y->parent = x->parent;
            if (x->parent == _nil)
                _tree = y;
            else if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;

            x->parent = y;
        }

        void rbRightRotate(node *x)
        {
            node *y = x->left;
            x->left = y->right;

            if (y->right != _nil)
                y->right->parent = x;
            y->parent = x->parent;
            if (x->parent == _nil)
                _tree = y;
            else if (x == x->parent->right)
                x->parent->right = y;
            else
                x->parent->left = y;
            y->right = x;

            x->parent = y;
        }

        void rbInsertFixup(node *z)
        {
            while (z->parent->is_red == true)
            {
                if (z->parent == z->parent->parent->left)
                {
                    node *y = z->parent->parent->right;
                    if (y->is_red == true)
                    {
                        z->parent->is_red = false;
                        y->is_red = false;
                        z->parent->parent->is_red = true;
                        z = z->parent->parent;
                    }
                    else
                    {
                        if (z == z->parent->right)
                        {
                            z = z->parent;
                            rbLeftRotate(z);
                        }
                        z->parent->is_red = false;
                        z->parent->parent->is_red = true;
                        rbRightRotate(z->parent->parent);
                    }
                }
                else
                {
                    node *y = z->parent->parent->left;
                    if (y->is_red == true)
                    {
                        z->parent->is_red = false;
                        y->is_red = false;
                        z->parent->parent->is_red = true;
                        z = z->parent->parent;
                    }
                    else
                    {
                        if (z == z->parent->left)
                        {
                            z = z->parent;
                            rbRightRotate(z);
                        }
                        z->parent->is_red = false;
                        z->parent->parent->is_red = true;
                        rbLeftRotate(z->parent->parent);
                    }
                }
            }
            _tree->is_red = false;
        }

        node *rbTreeInsert(node *z)
        {
            node *y = _nil;
            node *x = _tree;
            while (x != _nil)
            {
                y = x;
                if (z->val->first < x->val->first)
                    x = x->left;
                else if (z->val->first > x->val->first)
                    x = x->right;
                else
                    return (x);
            }
            z->parent = y;
            if (y == _nil)
                _tree = z;
            else if (z->val->first < y->val->first)
                y->left = z;
            else if (z->val->first > y->val->first)
                y->right = z;
            else
                return (x);
            z->left = _nil;
            z->right = _nil;
            z->is_red = true;
            rbInsertFixup(z);
            return (z);
        }

        void treeWalkCopy(node *x, node *y)
        {
            if (x->is_nil != true)
            {
                if (x->left->is_nil != true)
                {
                    y->left = cloneNode(x->left);
                    y->left->parent = y;
                }
                else
                    y->left = _nil;

                if (x->right->is_nil != true)
                {
                    y->right = cloneNode(x->right);
                    y->right->parent = y;
                }
                else
                    y->right = _nil;

                treeWalkCopy(x->left, y->left);
                treeWalkCopy(x->right, y->right);
            }
        }

        void treeWalkDelete(node* x)
        {
            if (x == _nil)
                return ;
            if (x->left != _nil)
                treeWalkDelete(x->left);
            if (x->right != _nil)
                treeWalkDelete(x->right);
            if (x == x->parent->left)
                x->parent->left = _nil;
            else if (x == x->parent->right)
                x->parent->right = _nil;
            deleteNode(x);
        }

    public:
        explicit Map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            : _allocator(alloc), _comp(comp)
        {
            createNil();
            _tree = _nil;
        };

        template <class InputIterator>
        Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type())
            : _allocator(alloc), _comp(comp)
        {
            createNil();
            _tree = _nil;
            while (first != last)
            {
                insert(*first);
                ++first;
            }
        };

        Map (const Map& x) : _allocator(x._allocator), _comp(x._comp) {
            createNil();
            if (x._tree->is_nil != true)
            {
                this->_tree = cloneNode(x._tree);
                this->_tree->parent = _nil;
            }
            else
                this->_tree = _nil;
            treeWalkCopy(x._tree, this->_tree);
        };

        // map& operator= (const map& x);
        ~Map() {
            treeWalkDelete(_tree);
            deleteNode(_nil);
        };

        iterator begin() {
            return (iterator(rbTreeMin(_tree)));
        };
        const_iterator begin() const {
            return (const_iterator(rbTreeMin(_tree)));
        };

        iterator end() {
            return (iterator(_nil));
        };
        const_iterator end() const {
            return (const_iterator(_nil));
        };

        reverse_iterator rbegin() {
            return (reverse_iterator(rbTreeMax(_tree)));
        };
        const_reverse_iterator rbegin() const {
            return (const_reverse_iterator(rbTreeMax(_tree)));
        };

        reverse_iterator rend() {
            return (reverse_iterator(_nil));
        };
        const_reverse_iterator rend() const {
            return (const_reverse_iterator(_nil));
        };

        // bool empty() const;
        // size_type size() const;
        // size_type max_size() const;

        // mapped_type& operator[] (const key_type& k);

        Pair<iterator, bool> insert (const value_type& val) {
            Pair<iterator, bool> result;
            node *new_node = createNode(val.first, val.second);

            node* result_node = rbTreeInsert(new_node);
            if (new_node->val == result_node->val)
                result.second = true;
            else
            {
                deleteNode(new_node);
                result.second = false;
            }
            result.first = iterator(result_node);
            return (result);
        };

        // iterator insert (iterator position, const value_type& val);
        // template <class InputIterator>
        // void insert (InputIterator first, InputIterator last) {
        //     while (first != last)
        //     {

        //     }
        // };
        // void erase (iterator position);
        // size_type erase (const key_type& k);
        // void erase (iterator first, iterator last);
        // void swap (map& x);
        // void clear();

        // key_compare key_comp() const;
        // value_compare value_comp() const;

        // iterator find (const key_type& k);
        // const_iterator find (const key_type& k) const;
        // size_type count (const key_type& k) const;
        // iterator lower_bound (const key_type& k);
        // const_iterator lower_bound (const key_type& k) const;
        // iterator upper_bound (const key_type& k);
        // const_iterator upper_bound (const key_type& k) const;
        // pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
        // pair<iterator,iterator>             equal_range (const key_type& k);

        struct _Map_iterator_base
        {
            node *_cur;

            _Map_iterator_base() {};
            _Map_iterator_base(node *x) : _cur(x) {};
            _Map_iterator_base(const _Map_iterator_base& x) : _cur(x._cur) {};
            ~_Map_iterator_base() {};
            _Map_iterator_base& operator=(const _Map_iterator_base& rhs){
                this->_cur = rhs._cur;
                return (*this);
            };

            bool operator== (const _Map_iterator_base& other) const {return (this->_cur == other._cur);};
            bool operator!= (const _Map_iterator_base& other) const {return (this->_cur != other._cur);};

            node *increase(node *x)
            {
                return (rbTreeSuccessor(x));
            }

            node *decrease(node *x)
            {
                return (rbTreePredecessor(x));
            }
        };

        template <typename Tp, typename Ref, typename Ptr>
        class _Map_iterator : public _Map_iterator_base
        {
            public:
                typedef _Map_iterator<Tp, Tp&, Tp*>				iterator;
                typedef _Map_iterator<Tp, const Tp&, const Tp*>	const_iterator;
				typedef _Map_iterator<Tp, Ref, Ptr>				self;

				typedef bidirectional_iterator_tag				iterator_category;
				typedef Tp										value_type;
				typedef std::ptrdiff_t							difference_type;
				typedef Ptr										pointer;
				typedef Ref										reference;

				_Map_iterator() {};
				_Map_iterator(node *current) : _Map_iterator_base(current) {};
				_Map_iterator(const iterator& other) : _Map_iterator_base(other) {};
				~_Map_iterator() {};
				self& operator= (const iterator& rhs) {
					_Map_iterator_base::operator=(rhs);
					return (*this);
				};

				self& operator++ () {
                    this->_cur = this->increase(this->_cur);
					return (*this);
				};

				self& operator++ (int) {
                    this->_cur = this->increase(this->_cur);
					return (*this);
				};

				self& operator-- () {
					this->_cur = this->decrease(this->_cur);
					return (*this);
				};

				self& operator-- (int) {
					this->_cur = this->decrease(this->_cur);
					return (*this);
				};

				reference operator*() const {
					return (*this->_cur->val);
				};

				pointer operator->() const {
					return (this->_cur->val);
				};
        };
    };
}

#endif // !MAP_HPP
