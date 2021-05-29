/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_queue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:29:24 by kdustin           #+#    #+#             */
/*   Updated: 2021/05/29 16:44:20 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestMiscellanea.hpp"

int test_queuegroup()
{
	std::cout << "queue" << std::endl;

	std::queue<int> original_queue;
	ft::Queue<int> my_queue;
	std::queue<int> original_queue_2;
	ft::Queue<int> my_queue_2;

	// std::queue<int, std::vector<int> > original_queue;
	// ft::Queue<int, ft::Vector<int> > my_queue;
	// std::queue<int, std::vector<int> > original_queue_2;
	// ft::Queue<int, ft::Vector<int> > my_queue_2;

	// std::queue<int, std::list<int> > original_queue;
	// ft::Queue<int, ft::List<int> > my_queue;
	// std::queue<int, std::list<int> > original_queue_2;
	// ft::Queue<int, ft::List<int> > my_queue_2;

	ASSERT_EQ(original_queue.size(), my_queue.size());
	ASSERT_EQ(original_queue.empty(), my_queue.empty());

	original_queue.push(1);
	my_queue.push(1);

	ASSERT_EQ(original_queue.front(), my_queue.front());
	ASSERT_EQ(original_queue.back(), my_queue.back());

	original_queue.push(2);
	my_queue.push(2);

	ASSERT_EQ(original_queue.front(), my_queue.front());
	ASSERT_EQ(original_queue.back(), my_queue.back());

	original_queue.pop();
	my_queue.pop();

	ASSERT_EQ(original_queue.front(), my_queue.front());
	ASSERT_EQ(original_queue.back(), my_queue.back());

	original_queue.push(2);
	original_queue.push(3);
	my_queue.push(2);
	my_queue.push(3);

	original_queue_2.push(1);
	original_queue_2.push(2);
	original_queue_2.push(3);
	my_queue_2.push(1);
	my_queue_2.push(2);
	my_queue_2.push(3);

	ASSERT_EQ(original_queue == original_queue_2, my_queue == my_queue_2);
	ASSERT_EQ(original_queue != original_queue_2, my_queue != my_queue_2);
	ASSERT_EQ(original_queue < original_queue_2, my_queue < my_queue_2);
	ASSERT_EQ(original_queue <= original_queue_2, my_queue <= my_queue_2);
	ASSERT_EQ(original_queue > original_queue_2, my_queue > my_queue_2);
	ASSERT_EQ(original_queue >= original_queue_2, my_queue >= my_queue_2);

	ASSERT_EQ(original_queue.size(), my_queue.size());
	ASSERT_EQ(original_queue.empty(), my_queue.empty());

	std::cout << std::endl;

	return (0);
}
