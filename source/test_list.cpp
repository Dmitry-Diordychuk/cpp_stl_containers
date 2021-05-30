/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:53:12 by kdustin           #+#    #+#             */
/*   Updated: 2021/05/30 23:07:39 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestMiscellanea.hpp"

void test_typetrairsgroup_isintegral()
{
	std::cout << "type_traits::is_integral" << std::endl;
	ASSERT_EQ(ft::is_integral<int>::value, true);
	ASSERT_EQ(ft::is_integral<ft::List<int>::iterator>::value, false);
}

void test_listgroup_nconstructor()
{
	std::cout << "list::nconstructor" << std::endl;
	std::list<int>	original_list(10, 42);
	ft::List<int>	my_list(10, 42);

	std::list<int>::iterator original_it = original_list.begin();
	ft::List<int>::iterator my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	std::cout << std::endl;
}

void test_listgroup_iterconstructor()
{
	std::cout << "list::iterconstructor" << std::endl;

	int array[] = {1, 2, 3, 4, 5};

	std::list<int>	original_list(array, array + sizeof(array) / sizeof(int));
	ft::List<int>	my_list(array, array + sizeof(array) / sizeof(int));

	std::list<int>::iterator original_it = original_list.begin();
	ft::List<int>::iterator my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	std::cout << std::endl;
}

void test_listgroup_copyconstructor()
{
	std::cout << "list::copy_constructor" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);

	std::list<int> original_copy = std::list<int>(original_list);
	ft::List<int> my_copy = ft::List<int>(my_list);

	std::list<int>::iterator original_it = original_copy.begin();
	ft::List<int>::iterator my_it = my_copy.begin();
	while (original_it != original_copy.end() || my_it != my_copy.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == original_copy.end(), my_it == my_copy.end());

	std::cout << std::endl;
}

void test_listgroup_assignmentoperator()
{
	std::cout << "list::assignment_operator" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);

	std::list<int> second_original_list;
	ft::List<int> second_my_list;

	second_my_list.push_back(4);
	second_my_list.push_back(5);
	second_my_list.push_back(6);
	second_original_list.push_back(4);
	second_original_list.push_back(5);
	second_original_list.push_back(6);

	second_original_list = original_list;
	second_my_list = my_list;

	std::list<int>::iterator original_it = second_original_list.begin();
	ft::List<int>::iterator my_it = second_my_list.begin();
	while (original_it != second_original_list.end() || my_it != second_my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == second_original_list.end(), my_it == second_my_list.end());

	std::cout << std::endl;
}

void test_listgroup_iterator()
{
	std::cout << "list::iterator" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	std::list<int>::iterator original_it = original_list.begin();
	ft::List<int>::iterator my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	--original_it;
	--my_it;
	while (original_it != original_list.begin() || my_it != my_list.begin())
	{
		ASSERT_EQ(*original_it, *my_it);
		--original_it;
		--my_it;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		original_it++;
		my_it++;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	original_it--;
	my_it--;
	while (original_it != original_list.begin() || my_it != my_list.begin())
	{
		ASSERT_EQ(*original_it, *my_it);
		original_it--;
		my_it--;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	std::cout << std::endl;
}

void test_listgroup_constiterator()
{
	std::cout << "list::const_iterator" << std::endl;

	std::list<int>	original_list;
	ft::List<int>		my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	std::list<int>::const_iterator original_it = original_list.begin();
	ft::List<int>::const_iterator my_it = my_list.begin();

	while (original_it != original_list.end() || my_it != my_list.end())
	{
		//(*original_it)++;					compilation error
		//(*my_it)++;						compilation error
		ASSERT_EQ(*original_it, *my_it);
		original_it++;
		my_it++;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	std::cout << std::endl;
}

void test_listgroup_reverseiterator()
{
	std::cout << "list::reverse_iterator" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	std::list<int>::reverse_iterator original_rev_it = original_list.rbegin();
	ft::List<int>::reverse_iterator my_rev_it = my_list.rbegin();
	while (original_rev_it != original_list.rend() || my_rev_it != my_list.rend())
	{
		int o = *original_rev_it;
		int m = *my_rev_it;
		ASSERT_EQ(o, m);
		++original_rev_it;
		++my_rev_it;
	}
	ASSERT_EQ(original_rev_it == original_list.rend(), my_rev_it == my_list.rend());

	std::cout << std::endl;
}

void test_listgroup_empty()
{
	std::cout << "list::empty" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	ASSERT_EQ(original_list.empty(), my_list.empty());
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	ASSERT_EQ(original_list.empty(), my_list.empty());
	my_list.pop_back();
	my_list.pop_back();
	my_list.pop_back();
	original_list.pop_back();
	original_list.pop_back();
	original_list.pop_back();
	ASSERT_EQ(original_list.empty(), my_list.empty());
	std::cout << std::endl;
}

void test_listgroup_size()
{
	std::cout << "list::size" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	ASSERT_EQ(my_list.size(), original_list.size());
	my_list.push_back(1);
	original_list.push_back(1);
	ASSERT_EQ(my_list.size(), original_list.size());
	my_list.push_back(2);
	original_list.push_back(2);
	ASSERT_EQ(my_list.size(), original_list.size());
	my_list.push_back(3);
	original_list.push_back(3);
	ASSERT_EQ(my_list.size(), original_list.size());

	std::cout << std::endl;
}

void test_listgroup_front()
{
	std::cout << "list::front" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);

	ASSERT_EQ(my_list.front(), original_list.front());
	my_list.pop_front();
	original_list.pop_front();
	ASSERT_EQ(my_list.front(), original_list.front());
	my_list.pop_front();
	original_list.pop_front();
	ASSERT_EQ(my_list.front(), original_list.front());
	my_list.pop_front();
	original_list.pop_front();

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);

	const std::list<int>	const_original_list(original_list);
	const ft::List<int>		const_my_list(my_list);

	ASSERT_EQ(const_my_list.front(), const_original_list.front());

	std::cout << std::endl;
}

void test_listgroup_back()
{
	std::cout << "list::back" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);

	ASSERT_EQ(my_list.back(), original_list.back());
	my_list.pop_back();
	original_list.pop_back();
	ASSERT_EQ(my_list.back(), original_list.back());
	my_list.pop_back();
	original_list.pop_back();
	ASSERT_EQ(my_list.back(), original_list.back());
	my_list.pop_back();
	original_list.pop_back();

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);

	const std::list<int>	const_original_list(original_list);
	const ft::List<int>		const_my_list(my_list);

	ASSERT_EQ(const_my_list.back(), const_original_list.back());

	std::cout << std::endl;
}

void test_listgroup_pushback()
{
	std::cout << "list::push_back" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	std::list<int>::iterator original_it = original_list.begin();
	ft::List<int>::iterator my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	std::cout << std::endl;
}

void test_listgroup_pushfront()
{
	std::cout << "list::push_front" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_front(1);
	my_list.push_front(2);
	my_list.push_front(3);
	original_list.push_front(1);
	original_list.push_front(2);
	original_list.push_front(3);
	std::list<int>::iterator original_it = original_list.begin();
	ft::List<int>::iterator my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	std::cout << std::endl;
}

void test_listgroup_popback()
{
	std::cout << "list::pop_back" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	my_list.pop_back();
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	original_list.pop_back();
	std::list<int>::iterator original_it = original_list.begin();
	ft::List<int>::iterator my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	std::cout << std::endl;
}

void test_listgroup_popfront()
{
	std::cout << "list::pop_front" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	my_list.pop_front();														//POP
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	original_list.pop_front();
	std::list<int>::iterator original_it = original_list.begin();
	ft::List<int>::iterator my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	my_list.pop_front();														//POP
	original_list.pop_front();
	original_it = original_list.begin();
	my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	my_list.pop_front();														//POP
	original_list.pop_front();
	original_it = original_list.begin();
	my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	std::cout << std::endl;
}

void test_listgroup_insert()
{
	std::cout << "list::insert" << std::endl;

	std::list<int>				original_list;
	ft::List<int>				my_list;
	std::list<int>::iterator	o_it;
	ft::List<int>::iterator		m_it;

	o_it = original_list.insert(original_list.end(), 1);
	m_it = my_list.insert(my_list.end(), 1);
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_list.insert(original_list.end(), 2);
	m_it = my_list.insert(my_list.end(), 2);
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_list.insert(original_list.end(), 3);
	m_it = my_list.insert(my_list.end(), 3);
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	original_list.clear();
	my_list.clear();

	o_it = original_list.insert(original_list.begin(), 1);
	m_it = my_list.insert(my_list.begin(), 1);
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_list.insert(original_list.begin(), 2);
	m_it = my_list.insert(my_list.begin(), 2);
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_list.insert(original_list.begin(), 3);
	m_it = my_list.insert(my_list.begin(), 3);
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	o_it = original_list.begin();
	m_it = my_list.begin();
	o_it++;
	m_it++;

	original_list.insert(o_it, 4);
	my_list.insert(m_it, 4);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	o_it = original_list.begin();
	m_it = my_list.begin();
	o_it++;
	m_it++;
	o_it++;
	m_it++;

	original_list.insert(o_it, 3, 4);
	my_list.insert(m_it, 3, 4);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	int n[] = {5, 6, 7, 8, 9};

	o_it = original_list.begin();
	m_it = my_list.begin();
	++o_it;
	++m_it;

	original_list.insert(o_it, n, n + 3);
	my_list.insert(m_it, n, n + 3);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	std::list<int>				original_list2;
	ft::List<int>				my_list2;
	std::list<int>::iterator	o_begin = original_list.begin();
	ft::List<int>::iterator		m_begin = my_list.begin();
	std::list<int>::iterator	o_end = original_list.begin();
	ft::List<int>::iterator		m_end = my_list.begin();

	// o_begin++;
	// m_begin++;

	original_list2.insert(original_list2.end(), o_begin, o_end);
	my_list2.insert(my_list2.end(), m_begin, m_end);

	o_it = original_list2.begin();
	m_it = my_list2.begin();
	while (o_it != original_list2.end() || m_it != my_list2.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	std::cout << std::endl;
}

void test_listgroup_erase()
{
	std::cout << "list::erase" << std::endl;

	std::list<int>				original_list;
	ft::List<int>				my_list;
	std::list<int>::iterator	o_it;
	ft::List<int>::iterator		m_it;

	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);

	o_it = original_list.begin();
	++o_it;
	m_it = my_list.begin();
	++m_it;

	original_list.erase(o_it);
	my_list.erase(m_it);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	original_list.erase(original_list.begin());
	my_list.erase(my_list.begin());

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	original_list.erase(original_list.begin());
	my_list.erase(my_list.begin());

	ASSERT_EQ(original_list.size(), my_list.size());
	ASSERT_TRUE(original_list.size() == 0);

	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	original_list.push_back(4);
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	my_list.push_back(4);

	original_list.erase(++original_list.begin(), --original_list.end());
	my_list.erase(++my_list.begin(), --my_list.end());

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	original_list.erase(original_list.begin(), original_list.end());
	my_list.erase(my_list.begin(), my_list.end());

	ASSERT_EQ(original_list.size(), my_list.size());
	ASSERT_TRUE(original_list.size() == 0);

	std::cout << std::endl;
}

void test_listgroup_swap()
{
	std::cout << "list::swap" << std::endl;

	std::list<int> original_first (3,100);
	std::list<int> original_second (5,200);
	ft::List<int> my_first (3, 100);
	ft::List<int> my_second (5, 200);

	original_first.swap(original_second);
	my_first.swap(my_second);

	std::list<int>::iterator o_it = original_first.begin();
	ft::List<int>::iterator m_it = my_first.begin();
	while (o_it != original_first.end() || m_it != my_first.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	o_it = original_second.begin();
	m_it = my_second.begin();
	while (o_it != original_second.end() || m_it != my_second.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	std::cout << std::endl;
}

void test_listgroup_resize()
{
	std::cout << "list::resize" << std::endl;

	int n[] = {1, 2, 3};
	std::list<int> original_list(n, n + 3);
	ft::List<int> my_list(n, n + 3);

	original_list.resize(5);
	my_list.resize(5);

	std::list<int>::iterator o_it = original_list.begin();
	ft::List<int>::iterator m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	original_list.resize(2);
	my_list.resize(2);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	std::cout << std::endl;
}

void test_listgroup_splice()
{
	std::cout << "list::splice" << std::endl;

	std::list<int>				original_list1;
	std::list<int>				original_list2;
	ft::List<int>				my_list1;
	ft::List<int>				my_list2;
	std::list<int>::iterator	o_it;
	ft::List<int>::iterator		m_it;

	for (int i = 1; i <= 4; ++i)
		original_list1.push_back(i);
	for (int i = 1; i <= 4; ++i)
		my_list1.push_back(i);

	for (int i = 1; i <= 3; ++i)
		original_list2.push_back(i * 10);
	for (int i = 1; i <= 3; ++i)
		my_list2.push_back(i * 10);

	o_it = original_list1.begin();
	//++o_it;
	//++o_it;
	//++o_it;
	//++o_it;
	m_it = my_list1.begin();
	//++m_it;
	//++m_it;
	//++m_it;
	//++m_it;

	original_list1.splice (o_it, original_list2);
	my_list1.splice (m_it, my_list2);

	std::list<int>::iterator op_it = original_list1.begin();
	ft::List<int>::iterator mp_it = my_list1.begin();
	while (op_it != original_list1.end() || mp_it != my_list1.end())
	{
		ASSERT_EQ(*op_it, *mp_it);
		++op_it;
		++mp_it;
	}
	ASSERT_EQ(original_list2.empty(), my_list2.empty());

	original_list2.splice(original_list2.begin(), original_list1, o_it);
	my_list2.splice(my_list2.begin(), my_list1, m_it);

	op_it = original_list1.begin();
	mp_it = my_list1.begin();
	while (op_it != original_list1.end() || mp_it != my_list1.end())
	{
		ASSERT_EQ(*op_it, *mp_it);
		++op_it;
		++mp_it;
	}
	op_it = original_list2.begin();
	mp_it = my_list2.begin();
	while (op_it != original_list2.end() || mp_it != my_list2.end())
	{
		ASSERT_EQ(*op_it, *mp_it);
		++op_it;
		++mp_it;
	}

	o_it = original_list1.begin();
	std::advance(o_it, 3);
	m_it = my_list1.begin();
	m_it++;
	m_it++;
	m_it++;

	original_list1.splice(original_list1.begin(), original_list1, o_it, original_list1.end());
	my_list1.splice(my_list1.begin(), my_list1, m_it, my_list1.end());

	op_it = original_list1.begin();
	mp_it = my_list1.begin();
	while (op_it != original_list1.end() || mp_it != my_list1.end())
	{
		ASSERT_EQ(*op_it, *mp_it);
		++op_it;
		++mp_it;
	}

	std::cout << std::endl;
}

void test_listgroup_remove()
{
	std::cout << "list::remove" << std::endl;

	int array[] = {14, 89, 7, 14};
	std::list<int> original_list(array, array + 4);
	ft::List<int> my_list(array, array + 4);

	original_list.remove(89);
	my_list.remove(89);

	std::list<int>::iterator o_it = original_list.begin();
	ft::List<int>::iterator m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_list.size(), my_list.size());

	original_list.remove(14);
	my_list.remove(14);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_list.size(), my_list.size());

	original_list.remove(1);
	my_list.remove(1);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_list.size(), my_list.size());

	original_list.remove(7);
	my_list.remove(7);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_list.size(), my_list.size());

	original_list.remove(0);
	my_list.remove(0);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_list.size(), my_list.size());

	std::cout << std::endl;
}

void test_listgroup_removeif()
{
	std::cout << "list::remove_if" << std::endl;

	int array[] = {15, 36, 7, 17, 20, 39, 4, 1};
	std::list<int> original_list(array, array + 8);
	ft::List<int> my_list(array, array + 8);

	original_list.remove_if(single_digit);
	my_list.remove_if(single_digit);

	std::list<int>::iterator o_it = original_list.begin();
	ft::List<int>::iterator m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_list.size(), my_list.size());

	original_list.remove_if(is_odd());
	my_list.remove_if(is_odd());

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_list.size(), my_list.size());

	std::cout << std::endl;
}

void test_listgroup_unique()
{
	std::cout << "list::unique" << std::endl;

	int array[] = {1, 2, 2, 3, 3, 2, 1, 1, 2};
	std::list<int> original_list(array, array + 9);
	ft::List<int> my_list(array, array + 9);

	original_list.unique();
	my_list.unique();

	std::list<int>::iterator o_it = original_list.begin();
	ft::List<int>::iterator m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_list.size(), my_list.size());

	double arrayf[] = {2.72, 3.14, 12.15, 12.77, 12.77, 15.3, 72.25, 72.25, 73.0, 73.35};
	std::list<double> original_listf(arrayf, arrayf + 10);
	ft::List<double> my_listf(arrayf, arrayf + 10);

	original_listf.unique(same_integral_part);
	my_listf.unique(same_integral_part);

	std::list<double>::iterator of_it = original_listf.begin();
	ft::List<double>::iterator mf_it = my_listf.begin();
	while (of_it != original_listf.end() || mf_it != my_listf.end())
	{
		ASSERT_EQ(*of_it, *mf_it);
		++of_it;
		++mf_it;
	}
	ASSERT_EQ(original_listf.size(), my_listf.size());

	original_listf.unique(is_near());
	my_listf.unique(is_near());

	of_it = original_listf.begin();
	mf_it = my_listf.begin();
	while (of_it != original_listf.end() || mf_it != my_listf.end())
	{
		ASSERT_EQ(*of_it, *mf_it);
		++of_it;
		++mf_it;
	}
	ASSERT_EQ(original_listf.size(), my_listf.size());

	std::cout << std::endl;
}

void test_listgroup_merge()
{
	std::cout << "list::merge" << std::endl;

	double array_first[] = {2.2, 2.9, 3.1};
	double array_second[] = {1.4, 3.7, 7.1};
	std::list<double> original_list_first(array_first, array_first + 3);
	std::list<double> original_list_second(array_second, array_second + 3);
	ft::List<double> my_list_first(array_first, array_first + 3);
	ft::List<double> my_list_second(array_second, array_second + 3);

	original_list_first.merge(original_list_second);
	my_list_first.merge(my_list_second);

	std::list<double>::iterator o_it = original_list_first.begin();
	ft::List<double>::iterator m_it = my_list_first.begin();
	while (o_it != original_list_first.end() || m_it != my_list_first.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_list_second.empty(), my_list_second.empty());

	original_list_second.push_back(2.1);
	my_list_second.push_back(2.1);

	original_list_first.merge(original_list_second, mycomp);
	my_list_first.merge(my_list_second, mycomp);

	o_it = original_list_first.begin();
	m_it = my_list_first.begin();
	while (o_it != original_list_first.end() || m_it != my_list_first.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_list_second.empty(), my_list_second.empty());

	std::cout << std::endl;
}

void test_listgroup_sort()
{
	std::cout << "list::sort" << std::endl;

	std::list<std::string> original_list;
	ft::List<std::string> my_list;
	original_list.push_back("one");
	original_list.push_back("two");
	original_list.push_back("Three");
	my_list.push_back("one");
	my_list.push_back("two");
	my_list.push_back("Three");

	original_list.sort();
	my_list.sort();

	std::list<std::string>::iterator o_it = original_list.begin();
	ft::List<std::string>::iterator m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_list.size(), my_list.size());

	original_list.sort(descendingComp);
	my_list.sort(descendingComp);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_list.size(), my_list.size());

	std::cout << std::endl;
}

void test_listgroup_reverse()
{
	std::cout << "list::reverse" << std::endl;

	std::list<int> original_list;
	ft::List<int> my_list;

	for (int i = 1; i < 10; ++i)
	{
		original_list.push_back(i);
		my_list.push_back(i);
	}

	original_list.reverse();
	my_list.reverse();

	std::list<int>::iterator o_it = original_list.begin();
	ft::List<int>::iterator m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_list.size(), my_list.size());

	std::cout << std::endl;
}

void test_listgroup_relationaloperators()
{
	std::cout << "list::relational_operators" << std::endl;

	int array1[] = {1, 2, 3, 4};
	int array2[] = {1, 2, 3, 1};
	std::list<int> original_a(array1, array1 + 4);
	std::list<int> original_b(array1, array1 + 4);
	std::list<int> original_c(array2, array2 + 4);
	ft::List<int> my_a(array1, array1 + 4);
	ft::List<int> my_b(array1, array1 + 4);
	ft::List<int> my_c(array2, array2 + 4);

	ASSERT_EQ(original_a == original_b, my_a == my_b);
	ASSERT_EQ(original_b == original_c, my_b == my_c);

	ASSERT_EQ(original_a != original_b, my_a != my_b);
	ASSERT_EQ(original_b != original_c, my_b != my_c);

	ASSERT_EQ(original_a < original_b, my_a < my_b);
	ASSERT_EQ(original_b < original_c, my_b < my_c);

	ASSERT_EQ(original_a <= original_b, my_a <= my_b);
	ASSERT_EQ(original_b <= original_c, my_b <= my_c);

	ASSERT_EQ(original_a > original_b, my_a > my_b);
	ASSERT_EQ(original_b > original_c, my_b > my_c);

	ASSERT_EQ(original_a >= original_b, my_a >= my_b);
	ASSERT_EQ(original_b >= original_c, my_b >= my_c);

	std::cout << std::endl;
}

void test_listgroup_stdswap()
{
	std::cout << "list::std::swap" << std::endl;

	std::list<int> original_foo(3, 100);
	std::list<int> original_bar(5, 200);

	ft::List<int> my_foo(3, 100);
	ft::List<int> my_bar(5, 200);

	std::swap(original_foo, original_bar);
	ft::swap(my_foo, my_bar);

	std::list<int>::iterator o_it = original_foo.begin();
	ft::List<int>::iterator m_it = my_foo.begin();
	while (o_it != original_foo.end() || m_it != my_foo.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_foo.size(), my_foo.size());

	o_it = original_bar.begin();
	m_it = my_bar.begin();
	while (o_it != original_bar.end() || m_it != my_bar.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}
	ASSERT_EQ(original_bar.size(), my_bar.size());

	std::cout << std::endl;
}

int test_listgroup()
{
	test_typetrairsgroup_isintegral();

	test_listgroup_nconstructor();
	test_listgroup_iterconstructor();
	test_listgroup_copyconstructor();
	test_listgroup_assignmentoperator();

	test_listgroup_iterator();
	test_listgroup_constiterator();
	test_listgroup_reverseiterator();

	test_listgroup_empty();
	test_listgroup_size();

	test_listgroup_front();
	test_listgroup_back();

	test_listgroup_pushback();
	test_listgroup_pushfront();
	test_listgroup_popback();
	test_listgroup_popfront();
	test_listgroup_insert();
	test_listgroup_erase();
	test_listgroup_swap();
	test_listgroup_resize();
	test_listgroup_splice();
	test_listgroup_remove();
	test_listgroup_removeif();
	test_listgroup_unique();
	test_listgroup_merge();
	test_listgroup_sort();
	test_listgroup_reverse();

	test_listgroup_relationaloperators();
	test_listgroup_stdswap();

	return (0);
}
