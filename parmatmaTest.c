#define String char* 
#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_double(){
	double a [] = {2.34};
	double b [] = {2.34};
	ArrayUtil array1 = {a, sizeof(double), 1};
	ArrayUtil array2 = {b, sizeof(double), 1};
	assert(areEqual(array1,array2));
}

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_string(){
	String a [] = {"hello"};
	String b [] = {"hello"};
	ArrayUtil array1 = {a, sizeof(String), 1};
	ArrayUtil array2 = {b, sizeof(String), 1};
	assert(areEqual(array1,array2));
}

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_not_be_equal_String(){
	String a [] = {"hallo"};
	String b [] = {"hello"};
	ArrayUtil array1 = {a, sizeof(String), 1};
	ArrayUtil array2 = {b, sizeof(String), 1};
	assertEqual(areEqual(array1,array2),0);
}

int compare(void *hint,void* item){
	if(*(char*)item=='a')
		return 1;
	return 0;
}

void test_filter_will_return_the_array_a_a_a(){
	char a[]={'a','a','a','b','d'},hint=3;
	int length;
	char* result[5];
	ArrayUtil array = {a, sizeof(char), 5};
	length = filter(array,compare,&hint,(void **)result,5);
}

int isEqual(void* hint, void* item){
	if(*(int*)item==8 ||*(float*)item == 9.0 || *(double*)item==8.9)
		return 1;
	return 0;
}

void test_filter_will_return_the_array_of_8_8_8(){
	int a[]={1,8,8,7,8,9},hint=3,length;
	int* result[6];
	ArrayUtil array = {a, sizeof(int), 6};
	length = filter(array,isEqual,&hint,(void **)result,5);
}

int stringCompare(void *hint, void* item){
	String str ="hello";
	String getItem = *(String*)item;
	if(getItem==str)
		return 1;
	return 0;
}

void test_filter_will_return_the_array_string_contain_hello(){
	int length,hint=9;
	void* result[2],*expected;
	ArrayUtil array = create(sizeof(String),2);
	((char**)array.base)[0]="hello";
	((char**)array.base)[1]="gello";
	length = filter(array,stringCompare,&hint,(void **)result,2);
	expected = ((String*)result)[0];
	assertEqual(length,1);
	// assertEqual(strcmp(expected,"hello"),0);
}