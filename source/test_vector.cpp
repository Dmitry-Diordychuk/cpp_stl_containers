/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:57:07 by kdustin           #+#    #+#             */
/*   Updated: 2021/05/24 21:12:31 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestMiscellanea.hpp"

void test_vectorgroup_iterconstructor()
{
	std::cout << "vector::iter_constructor" << std::endl;

	int array[] = {1, 2, 3, 4};
	std::vector<int> original_vector(array, array + 4);
	ft::Vector<int> my_vector(array, array + 4);

	std::vector<int>::iterator o_it = original_vector.begin();
	ft::Vector<int>::iterator m_it = my_vector.begin();
	while (o_it != original_vector.end() || m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	std::cout << std::endl;
}

void test_vectorgroup_copyconstructor()
{
	std::cout << "vector::copy_consturctor" << std::endl;

	std::vector<std::string> original_vector(3, "Hello");
	ft::Vector<std::string> my_vector(3, "Hello");

	std::vector<std::string> original_vector_copy(original_vector);
	ft::Vector<std::string> my_vector_copy(my_vector);

	std::vector<std::string>::iterator o_it = original_vector.begin();
	ft::Vector<std::string>::iterator m_it = my_vector.begin();
	while (o_it != original_vector.end() || m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	o_it = original_vector_copy.begin();
	m_it = my_vector_copy.begin();
	while (o_it != original_vector_copy.end() || m_it != my_vector_copy.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector_copy.capacity(), my_vector_copy.capacity());

	std::cout << std::endl;
}

void test_vectorgroup_assignmentoperator()
{
	std::cout << "vector::assignment_operator" << std::endl;

	std::vector<std::string> original_vector(3, "Hello");
	ft::Vector<std::string> my_vector(3, "Hello");

	std::vector<std::string> original_vector_copy(2, "Wordl!");
	ft::Vector<std::string> my_vector_copy(2, "World");

	original_vector_copy = original_vector;
	my_vector_copy = my_vector;

	std::vector<std::string>::iterator o_it = original_vector.begin();
	ft::Vector<std::string>::iterator m_it = my_vector.begin();
	while (o_it != original_vector.end() || m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	o_it = original_vector_copy.begin();
	m_it = my_vector_copy.begin();
	while (o_it != original_vector_copy.end() || m_it != my_vector_copy.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector_copy.capacity(), my_vector_copy.capacity());

	std::cout << std::endl;
}

void test_vectorgroup_iterator()
{
	std::cout << "vector::iterator" << std::endl;

	std::vector<int> original_vector(3);
	ft::Vector<int> my_vector(3);

	std::vector<int>::iterator o_it = original_vector.begin();
	ft::Vector<int>::iterator m_it = my_vector.begin();
	while (o_it != original_vector.end() && m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	std::cout << std::endl;
}

void test_vectorgroup_constiterator()
{
	std::cout << "vector::const_iterator" << std::endl;

	const std::vector<int> original_vector(3, 3);
	const ft::Vector<int> my_vector(3, 3);

	std::vector<int>::const_iterator o_it = original_vector.begin();
	ft::Vector<int>::const_iterator m_it = my_vector.begin();
	while (o_it != original_vector.end() || m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	std::cout << std::endl;
}

void test_vectorgroup_reverseiterator()
{
	std::cout << "vector::reverse_iterator" << std::endl;

	std::vector<std::string> original_vector(3, "Hello");
	ft::Vector<std::string> my_vector(3, "Hello");

	std::vector<std::string>::reverse_iterator o_it = original_vector.rbegin();
	ft::Vector<std::string>::reverse_iterator m_it = my_vector.rbegin();
	while (o_it != original_vector.rend() || m_it != my_vector.rend())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	std::cout << std::endl;
}

void test_vectorgroup_constreverseiterator()
{
	std::cout << "vector::const_reverse_iterator" << std::endl;

	const std::vector<std::string> original_vector(3, "Hello");
	const ft::Vector<std::string> my_vector(3, "Hello");

	std::vector<std::string>::const_reverse_iterator o_it = original_vector.rbegin();
	ft::Vector<std::string>::const_reverse_iterator m_it = my_vector.rbegin();
	while (o_it != original_vector.rend() || m_it != my_vector.rend())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	std::cout << std::endl;
}

void test_vectorgroup_size()
{
	std::cout << "vector::size" << std::endl;

	std::vector<std::string> original_vector;
	ft::Vector<std::string> my_vector;
	ASSERT_EQ(original_vector.size(), my_vector.size());
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	std::vector<std::string> original_vector_n(3, "Hello");
	ft::Vector<std::string> my_vector_n(3, "Hello");
	ASSERT_EQ(original_vector_n.size(), my_vector_n.size());
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	std::vector<std::string> original_vector_copy(original_vector_n);
	ft::Vector<std::string> my_vector_copy(my_vector_n);
	ASSERT_EQ(original_vector_copy.size(), my_vector_copy.size());
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	std::string array[] = {"Hello", "Wordl!"};
	std::vector<std::string> original_vector_itcon(array, array + 2);
	ft::Vector<std::string> my_vector_itcon(array, array + 2);
	ASSERT_EQ(original_vector_itcon.size(), my_vector_itcon.size());
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	original_vector_itcon = original_vector_copy;
	my_vector_itcon = my_vector_copy;
	ASSERT_EQ(original_vector_itcon.size(), my_vector_itcon.size());
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	std::cout << std::endl;
}

void test_vectorgroup_resize()
{
	std::cout << "vector::resize" << std::endl;

	int array[] = {1, 2, 3, 4};
	std::vector<int> original_vector(array, array + 4);
	ft::Vector<int> my_vector(array, array + 4);

	original_vector.resize(9);
	my_vector.resize(9);

	std::vector<int>::iterator o_it = original_vector.begin();
	ft::Vector<int>::iterator m_it = my_vector.begin();
	while (o_it != original_vector.end() && m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	original_vector.resize(3);
	my_vector.resize(3);

	o_it = original_vector.begin();
	m_it = my_vector.begin();
	while (o_it != original_vector.end() && m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	original_vector.resize(12);
	my_vector.resize(12);

	o_it = original_vector.begin();
	m_it = my_vector.begin();
	while (o_it != original_vector.end() && m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	std::cout << std::endl;
}

void test_vectorgroup_empty()
{
	std::cout << "vector::empty" << std::endl;

	std::vector<std::string> original_vector;
	ft::Vector<std::string> my_vector;

	ASSERT_EQ(original_vector.empty(), original_vector.empty());

	original_vector.push_back("Hello");
	my_vector.push_back("Hello");

	ASSERT_EQ(original_vector.empty(), original_vector.empty());

	original_vector.pop_back();
	my_vector.pop_back();

	ASSERT_EQ(original_vector.empty(), original_vector.empty());

	std::cout << std::endl;
}

void test_vectorgroup_reserve()
{
	std::cout << "vector::reserve" << std::endl;

	std::vector<std::string> original_vector;
	ft::Vector<std::string> my_vector;

	original_vector.reserve(2);
	my_vector.reserve(2);
	ASSERT_EQ(original_vector.capacity(), original_vector.capacity());

	original_vector.reserve(6);
	my_vector.reserve(6);
	ASSERT_EQ(original_vector.capacity(), original_vector.capacity());

	original_vector.reserve(4);
	my_vector.reserve(4);
	ASSERT_EQ(original_vector.capacity(), original_vector.capacity());

	std::cout << std::endl;
}

void test_vectorgroup_accessoperator()
{
	std::cout << "vector::operator[]" << std::endl;

	std::vector<std::string> original_vector;
	ft::Vector<std::string> my_vector;

	original_vector.push_back("Hello");
	original_vector.push_back("World");
	original_vector.push_back("42");
	my_vector.push_back("Hello");
	my_vector.push_back("World");
	my_vector.push_back("42");

	for (size_t i = 0; i < original_vector.size() && i < my_vector.size(); ++i)
		ASSERT_EQ(original_vector[i], my_vector[i]);

	std::string array[] = {"Hello", "world", "!"};
	const std::vector<std::string> original_vector_const(array, array + 4);
	const ft::Vector<std::string> my_vector_const(array, array + 4);

	for (size_t i = 0; i < original_vector_const.size() && i < my_vector_const.size(); ++i)
		ASSERT_EQ(original_vector_const[i], my_vector_const[i]);

	std::cout << std::endl;
}

void test_vectorgroup_at()
{
	std::cout << "vector::at" << std::endl;

	std::vector<std::string> original_vector;
	ft::Vector<std::string> my_vector;

	original_vector.push_back("Hello");
	original_vector.push_back("World");
	original_vector.push_back("42");
	my_vector.push_back("Hello");
	my_vector.push_back("World");
	my_vector.push_back("42");

	for (size_t i = 0; i < original_vector.size() && i < my_vector.size(); ++i)
		ASSERT_EQ(original_vector.at(i), my_vector.at(i));
	bool is_original_throw = false;
	bool is_my_throw = false;
	try
	{
		original_vector.at(3);
	}
	catch(std::out_of_range e)
	{
		is_original_throw = true;
	}
	try
	{
		my_vector.at(3);
	}
	catch(std::out_of_range e)
	{
		is_my_throw = true;
	}
	ASSERT_EQ(is_original_throw, is_my_throw);

	std::string array[] = {"Hello", "world", "!"};
	const std::vector<std::string> original_vector_const(array, array + 3);
	const ft::Vector<std::string> my_vector_const(array, array + 3);

	for (size_t i = 0; i < original_vector_const.size() && i < my_vector_const.size(); ++i)
		ASSERT_EQ(original_vector_const.at(i), my_vector_const.at(i));

	is_original_throw = false;
	is_my_throw = false;
	try
	{
		original_vector_const.at(3);
	}
	catch(std::out_of_range e)
	{
		is_original_throw = true;
	}
	try
	{
		my_vector_const.at(3);
	}
	catch(std::out_of_range e)
	{
		is_my_throw = true;
	}
	ASSERT_EQ(is_original_throw, is_my_throw);

	std::cout << std::endl;
}

void test_vectorgroup_assign()
{
	std::cout << "vector::at" << std::endl;

	int array1[] = {1, 2, 3, 4};
	int array2[] = {5, 6, 7, 8};
	std::vector<int> original_vector1(array1, array1 + 4);
	ft::Vector<int> my_vector1(array1, array1 + 4);
	std::vector<int> original_vector2(array2, array2 + 4);
	ft::Vector<int> my_vector2(array2, array2 + 4);

	std::vector<int>::iterator o_it = original_vector2.begin();
	ft::Vector<int>::iterator m_it = my_vector2.begin();

	original_vector1.assign(o_it, original_vector2.end());
	my_vector1.assign(m_it, my_vector2.end());

	o_it = original_vector1.begin();
	m_it = my_vector1.begin();
	while (o_it != original_vector1.end() && m_it != my_vector1.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	o_it = original_vector2.begin();
	m_it = my_vector2.begin();
	while (o_it != original_vector2.end() && m_it != my_vector2.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	original_vector1.assign(5, 0);
	my_vector1.assign(5, 0);

	o_it = original_vector1.begin();
	m_it = my_vector1.begin();
	while (o_it != original_vector1.end() && m_it != my_vector1.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	std::cout << std::endl;
}

void test_vectorgroup_pushback()
{
	std::cout << "vector::push_back" << std::endl;

	std::vector<std::string> original_vector;
	ft::Vector<std::string> my_vector;

	original_vector.push_back("Hello");
	original_vector.push_back("World");
	original_vector.push_back("42");
	my_vector.push_back("Hello");
	my_vector.push_back("World");
	my_vector.push_back("42");

	std::vector<std::string>::iterator o_it = original_vector.begin();
	ft::Vector<std::string>::iterator m_it = my_vector.begin();
	while (o_it != original_vector.end() && m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	std::cout << std::endl;
}

void test_vectorgroup_popback()
{
	std::cout << "vector::pop_back" << std::endl;

	std::vector<std::string> original_vector;
	ft::Vector<std::string> my_vector;

	original_vector.push_back("Hello");
	original_vector.push_back("World");
	original_vector.push_back("42");
	my_vector.push_back("Hello");
	my_vector.push_back("World");
	my_vector.push_back("42");

	original_vector.pop_back();
	my_vector.pop_back();

	std::vector<std::string>::iterator o_it = original_vector.begin();
	ft::Vector<std::string>::iterator m_it = my_vector.begin();
	while (o_it != original_vector.end() && m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	original_vector.pop_back();
	my_vector.pop_back();

	o_it = original_vector.begin();
	m_it = my_vector.begin();
	while (o_it != original_vector.end() && m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	original_vector.pop_back();
	my_vector.pop_back();

	o_it = original_vector.begin();
	m_it = my_vector.begin();
	while (o_it != original_vector.end() && m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector.capacity(), my_vector.capacity());

	std::cout << std::endl;
}

void test_vectorgroup_insert()
{
	std::cout << "vector::insert" << std::endl;

	int array1[] = {1, 2, 3};
	std::vector<int> original_vector(array1, array1 + 3);
	ft::Vector<int> my_vector(array1, array1 + 3);
	std::vector<int>::iterator o_it;
	ft::Vector<int>::iterator m_it;

	o_it = original_vector.begin() + 2;
	m_it = my_vector.begin() + 2;

	o_it = original_vector.insert(o_it, 200);
	m_it = my_vector.insert(m_it, 200);

	ASSERT_EQ(*o_it, *m_it);

	o_it += 1;
	m_it += 1;

	original_vector.insert(o_it, 2, 300);
	my_vector.insert(m_it, 2, 300);

	o_it = original_vector.begin() + 4;
	m_it = my_vector.begin() + 4;

	int array2[] = {4, 5, 6};
	original_vector.insert(o_it, array2, array2 + 3);
	my_vector.insert(m_it, array2, array2 + 3);

	o_it = original_vector.begin();
	m_it = my_vector.begin();

	while (o_it != original_vector.end() && m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector.size(), my_vector.size());

	std::cout << std::endl;
}

void test_vectorgroup_erase()
{
	std::cout << "vector::erase" << std::endl;

	std::vector<int> original_vector;
	ft::Vector<int> my_vector;

	for (int i = 1; i <= 10; ++i)
	{
		original_vector.push_back(i);
		my_vector.push_back(i);
	}

	std::vector<int>::iterator o_it;
	ft::Vector<int>::iterator m_it;

	o_it = original_vector.erase(original_vector.begin() + 4);
	m_it = my_vector.erase(my_vector.begin() + 4);
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_vector.begin();
	m_it = my_vector.begin();
	while (o_it != original_vector.end() && m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector.size(), my_vector.size());

	o_it = original_vector.erase(original_vector.begin(), original_vector.end());
	m_it = my_vector.erase(my_vector.begin(), my_vector.end());
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_vector.begin();
	m_it = my_vector.begin();
	while (o_it != original_vector.end() && m_it != my_vector.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_vector.size(), my_vector.size());

	std::cout << std::endl;
}

void test_vectorgroup_swap()
{
	std::cout << "vector::swap" << std::endl;

	std::vector<int> original_foo (3,100);
	std::vector<int> original_bar (5,200);

	ft::Vector<int> my_foo (3,100);
	ft::Vector<int> my_bar (5,200);

	original_foo.swap(original_bar);
	my_foo.swap(my_bar);

	std::vector<int>::iterator o_it = original_foo.begin();
	ft::Vector<int>::iterator m_it = my_foo.begin();
	while (o_it != original_foo.end() && m_it != my_foo.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_foo.size(), my_foo.size());

	o_it = original_bar.begin();
	m_it = my_bar.begin();
	while (o_it != original_bar.end() && m_it != my_bar.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_bar.size(), my_bar.size());

	std::cout << std::endl;
}

void test_vectorgroup_clear()
{
	std::cout << "vector::clear" << std::endl;

	std::vector<int> original_foo (3,100);
	ft::Vector<int> my_foo (3,100);

	original_foo.clear();
	my_foo.clear();

	std::vector<int>::iterator o_it = original_foo.begin();
	ft::Vector<int>::iterator m_it = my_foo.begin();
	while (o_it != original_foo.end() && m_it != my_foo.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_foo.size(), my_foo.size());

	std::cout << std::endl;
}

void test_vectorgroup_relationaloperators()
{
	std::cout << "vector::relational_operators" << std::endl;

	int array1[] = {1, 2, 1, 1}; int n1 = 4;
	int array2[] = {1, 2, 3}; int n2 = 3;

	std::vector<int> original_foo(array1, array1 + n1);
	std::vector<int> original_bar(array2, array2 + n2);

	ft::Vector<int> my_foo(array1, array1 + n1);
	ft::Vector<int> my_bar(array2, array2 + n2);

	ASSERT_EQ(original_foo == original_bar, my_foo == my_bar);
	ASSERT_EQ(original_foo != original_bar, my_foo != my_bar);
	ASSERT_EQ(original_foo < original_bar, my_foo < my_bar);
	ASSERT_EQ(original_foo <= original_bar, my_foo <= my_bar);
	ASSERT_EQ(original_foo > original_bar, my_foo > my_bar);
	ASSERT_EQ(original_foo >= original_bar, my_foo >= my_bar);

	std::cout << std::endl;
}

void test_vectorgroup_stdswap()
{
	std::cout << "vector::std::swap" << std::endl;


	int array1[] = {1, 2, 1, 1}; int n1 = 4;
	int array2[] = {1, 2, 3}; int n2 = 3;

	std::vector<int> original_foo(array1, array1 + n1);
	std::vector<int> original_bar(array2, array2 + n2);

	ft::Vector<int> my_foo(array1, array1 + n1);
	ft::Vector<int> my_bar(array2, array2 + n2);

	std::swap(original_foo, original_bar);
	ft::swap(my_foo, my_bar);

	std::vector<int>::iterator o_it = original_foo.begin();
	ft::Vector<int>::iterator m_it = my_foo.begin();
	while (o_it != original_foo.end() && m_it != my_foo.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_foo.size(), my_foo.size());

	o_it = original_bar.begin();
	m_it = my_bar.begin();
	while (o_it != original_bar.end() && m_it != my_bar.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_bar.size(), my_bar.size());

	std::cout << std::endl;
}

int test_vectorgroup()
{
	test_vectorgroup_iterconstructor();
	test_vectorgroup_copyconstructor();
	test_vectorgroup_assignmentoperator();

	test_vectorgroup_iterator();
	test_vectorgroup_constiterator();
	test_vectorgroup_reverseiterator();
	test_vectorgroup_constreverseiterator();

	test_vectorgroup_size();
	test_vectorgroup_resize();
	test_vectorgroup_empty();
	test_vectorgroup_reserve();

	test_vectorgroup_accessoperator();
	test_vectorgroup_at();

	test_vectorgroup_assign();
	test_vectorgroup_pushback();
	test_vectorgroup_popback();
	test_vectorgroup_insert();
	test_vectorgroup_erase();
	test_vectorgroup_swap();
	test_vectorgroup_clear();

	test_vectorgroup_relationaloperators();
	test_vectorgroup_stdswap();

	return (0);
}
