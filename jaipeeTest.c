#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>
ArrayUtil util,expectedUtil;

void test_array_util_areEqual_returns_0_if_both_array_are_not_equal_in_length_and_elements(){
	int a[]={0,3,8,5,2,3,4,5}, b[]={1,5,2,3,7};
	ArrayUtil a_array = {a,sizeof(int),8};
	ArrayUtil b_array = {b,sizeof(int),5};
	assertEqual(areEqual(a_array, b_array),0);
}
void test_create_allocates_space_for_DOUBLE_array_and_assigns_zero_to_all_bytes(){
	double doubleArray[] = {0,0,0,0};
	expectedUtil = (ArrayUtil){doubleArray,sizeof(double),4};
	util = create(sizeof(double),4);
	assertEqual(areEqual(expectedUtil,util),1);
	dispose(util);
}
void test_create_allocates_space_for_INT_array_and_assigns_zero_to_all_bytes(){
	int intArray[] = {0,0,0,0};
	expectedUtil = (ArrayUtil){intArray,sizeof(int),4};
	util = create(sizeof(int),4);
	assertEqual(areEqual(expectedUtil,util),1);
	dispose(util);
}

void test_resize_returns_CHAR_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(char []){'a','e','i','o'},sizeof(char),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(char []){'a','e','i','o',0,0},sizeof(char),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_CHAR_array_within_structure_with_new_allocated_space_less_than_previous(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(char []){'a','e','i','o','u'},sizeof(char),5};
	resizedArray = resize(util,2);
	expectedUtil = (ArrayUtil){(char []){'a','e'},sizeof(char),2};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_DOUBLE_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89},sizeof(double),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89,0,0},sizeof(double),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_DOUBLE_array_within_structure_with_new_allocated_space_less_than_previous(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89},sizeof(double),4};
	resizedArray = resize(util,2);
	expectedUtil = (ArrayUtil){(double []){1.0,2.11111},sizeof(double),2};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_FLOAT_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(float []){1.0,2.11111,3.123,4.89},sizeof(float),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(float []){1.0,2.11111,3.123,4.89,0,0},sizeof(float),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

void test_resize_returns_INT_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(int []){1,2,3,4},sizeof(int),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(int []){1,2,3,4,0,0},sizeof(int),6}; 
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}