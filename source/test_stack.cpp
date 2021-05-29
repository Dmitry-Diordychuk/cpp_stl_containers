/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:57:25 by kdustin           #+#    #+#             */
/*   Updated: 2021/05/29 16:43:28 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestMiscellanea.hpp"

int test_stackgroup()
{
	std::cout << "stack" << std::endl;

	std::stack<int> original_stack;
	ft::Stack<int> my_stack;
	std::stack<int> original_stack_2;
	ft::Stack<int> my_stack_2;

	// std::stack<int, std::vector<int> > original_stack;
	// ft::Stack<int, ft::Vector<int> > my_stack;
	// std::stack<int, std::vector<int> > original_stack_2;
	// ft::Stack<int, ft::Vector<int> > my_stack_2;

	// std::stack<int, std::list<int> > original_stack;
	// ft::Stack<int, ft::List<int> > my_stack;
	// std::stack<int, std::list<int> > original_stack_2;
	// ft::Stack<int, ft::List<int> > my_stack_2;

	ASSERT_EQ(original_stack.size(), my_stack.size());
	ASSERT_EQ(original_stack.empty(), my_stack.empty());

	original_stack.push(1);
	my_stack.push(1);

	ASSERT_EQ(original_stack.top(), my_stack.top());

	original_stack.push(2);
	my_stack.push(2);

	ASSERT_EQ(original_stack.top(), my_stack.top());

	original_stack.pop();
	my_stack.pop();

	ASSERT_EQ(original_stack.top(), my_stack.top());

	original_stack.push(2);
	original_stack.push(3);
	my_stack.push(2);
	my_stack.push(3);

	original_stack_2.push(1);
	original_stack_2.push(2);
	original_stack_2.push(3);
	my_stack_2.push(1);
	my_stack_2.push(2);
	my_stack_2.push(3);

	ASSERT_EQ(original_stack == original_stack_2, my_stack == my_stack_2);
	ASSERT_EQ(original_stack != original_stack_2, my_stack != my_stack_2);
	ASSERT_EQ(original_stack < original_stack_2, my_stack < my_stack_2);
	ASSERT_EQ(original_stack <= original_stack_2, my_stack <= my_stack_2);
	ASSERT_EQ(original_stack > original_stack_2, my_stack > my_stack_2);
	ASSERT_EQ(original_stack >= original_stack_2, my_stack >= my_stack_2);

	ASSERT_EQ(original_stack.size(), my_stack.size());
	ASSERT_EQ(original_stack.empty(), my_stack.empty());

	std::cout << std::endl;

	return (0);
}
