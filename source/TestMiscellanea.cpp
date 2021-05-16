/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestMiscellanea.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:41:06 by kdustin           #+#    #+#             */
/*   Updated: 2021/05/16 14:45:14 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestMiscellanea.hpp"

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
