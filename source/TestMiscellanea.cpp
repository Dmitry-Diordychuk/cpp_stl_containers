/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestMiscellanea.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:41:06 by kdustin           #+#    #+#             */
/*   Updated: 2021/05/21 23:00:42 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestMiscellanea.hpp"
#include "cmath"

TestClass::TestClass() {}
TestClass::TestClass(const TestClass&) {}
TestClass::~TestClass() {}

TestClass& TestClass::operator=(TestClass&) {return (*this);}

int TestClass::getA(){
	return (_a);
}

void TestClass::setA(int a){
	_a = a;
}

std::string TestClass::getB(){
	return (_b);
}

void TestClass::setB(std::string b){
	_b = b;
}

bool single_digit(const int& value){
	return (value < 10);
}

bool is_odd::operator()(const int& value){
	return ((value % 2) == 1);
}

bool same_integral_part(double first, double second){
	return (int(first) == int(second));
}

bool is_near::operator() (double first, double second){
	return (fabs(first - second) < 5.0);
}

bool mycomp(double first, double second)
{
	return (int(first) < int(second));
}

bool descendingComp(const std::string first, const std::string second)
{
	return (first > second);
}
