/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:57:07 by kdustin           #+#    #+#             */
/*   Updated: 2021/05/23 00:15:25 by kdustin          ###   ########.fr       */
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

	o_it = original_vector_copy.begin();
	m_it = my_vector_copy.begin();
	while (o_it != original_vector_copy.end() || m_it != my_vector_copy.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

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

	o_it = original_vector_copy.begin();
	m_it = my_vector_copy.begin();
	while (o_it != original_vector_copy.end() || m_it != my_vector_copy.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

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

	std::vector<std::string> original_vector_n(3, "Hello");
	ft::Vector<std::string> my_vector_n(3, "Hello");
	ASSERT_EQ(original_vector_n.size(), my_vector_n.size());

	std::vector<std::string> original_vector_copy(original_vector_n);
	ft::Vector<std::string> my_vector_copy(my_vector_n);
	ASSERT_EQ(original_vector_copy.size(), my_vector_copy.size());

	std::string array[] = {"Hello", "Wordl!"};
	std::vector<std::string> original_vector_itcon(array, array + 2);
	ft::Vector<std::string> my_vector_itcon(array, array + 2);
	ASSERT_EQ(original_vector_itcon.size(), my_vector_itcon.size());

	original_vector_itcon = original_vector_copy;
	my_vector_itcon = my_vector_copy;
	ASSERT_EQ(original_vector_itcon.size(), my_vector_itcon.size());

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

	return (0);
}
