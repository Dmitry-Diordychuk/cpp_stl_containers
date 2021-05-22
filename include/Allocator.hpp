/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:11:01 by marvin            #+#    #+#             */
/*   Updated: 2021/04/19 13:11:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <limits>
#include <memory>

namespace ft
{
	template <typename T>
	class Allocator : public std::allocator<T>
	{
	public:
		typedef T						value_type;
		typedef T*						pointer;
		typedef T&						reference;
		typedef const T*				const_pointer;
		typedef const T&				const_reference;
		typedef size_t					size_type;
		typedef ptrdiff_t				difference_type;

		template <class Other>															//Что это?
			struct rebind {
				typedef Allocator<Other> other;
			};
		// Constructors
		Allocator() throw () {};
		Allocator(const Allocator&) throw() {};
		template <class U>
			Allocator(const Allocator<U>&) throw() {};
		// Destructor
		~Allocator() throw() {};
		// Getter
		size_type		max_size() const throw() {
			size_type result = std::allocator<T>::max_size();
			std::cout << "Max_size: " << result << std::endl;
			return (result);
			//return (std::numeric_limits<size_t>::max() / sizeof(T));
		}
		// Other
		pointer			allocate(size_type n, const void* hint = 0) {
			//(void)hint;
			std::cout << "Allocate n: " << n << " hint: " << hint << std::endl;
			return (std::allocator<T>::allocate(n, hint));
			//return (new value_type[n]);
		}
		void			deallocate(pointer p, size_type n) {
			std::cout << "Deallocate p: " << p << " n: " << n << std::endl;
			std::allocator<T>::deallocate(p, n);
			//delete [] p;
		}
		void			construct(pointer p, const_reference val) {
			std::cout << "Construct p: " << p << " val: " << val << std::endl;
			std::allocator<T>::construct(p, val);
			//p = new ((void*)p) value_type(val);
		}
		void			destroy(pointer p) {
			std::cout << "Destroy p: " << p << std::endl;
			std::allocator<T>::destroy(p);
			//((pointer*)p)->~value_type();
		}
	};

	// template <>
	// class Allocator<void>
	// {
	// public:
	// 	typedef void* pointer;
	// 	typedef const void* const_pointer;
	// 	typedef void value_type;
	// 	template <class U> struct rebind { typedef Allocator<U> other; };
	// };
}

#endif // !ALLOCATOR_H
