#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>

void test_areEqual_return_0_when_both_array_lenght_base_and_typesize_are_same(){
	ArrayUtil a1,a2;
	int array1[]={1,2,3,4,5};
	int array2[]={1,2,3,4,5};
	a1.base=array1;
	a1.typeSize=sizeof(int);
	a1.length=5;
	a2.base=array2;
	a2.typeSize=sizeof(int);
	a2.length=5;
	assertEqual(areEqual(a1,a2), 1);
}

void test_areEqual_returns_0_when_lenght_are_not_equal(){
	ArrayUtil a1,a2;
	int array1[]={1,2,3,4};
	int array2[]={1,2,3,4,5};
	a1.base=array1;
	a1.typeSize=sizeof(int);
	a1.length=4;
	a2.base=array2;
	a2.typeSize=sizeof(int);
	a2.length=5;
	assertEqual(areEqual(a1,a2), 0);
}

void test_areEqual_returns_0_when_length_is_equal_but_typeSize_is_not_equal(){
	ArrayUtil a1,a2;
	int array1[]={1,2,3,4,5};
	int array2[]={1,2,3,4,5};
	a1.base=array1;
	a1.typeSize=sizeof(char);
	a1.length=5;
	a2.base=array2;
	a2.typeSize=sizeof(int);
	a2.length=5;
	assertEqual(areEqual(a1,a2), 0);
}

void test_create_creates_a_given_length_array_of_5_elements_when_given_length_is_5(){
	ArrayUtil arr=create(sizeof(int),5);
	assertEqual(arr.typeSize, sizeof(int));
	assertEqual(arr.length, 5);
	assertEqual(((int *)arr.base)[0], 0);
	assertEqual(((int *)arr.base)[1], 0);
	assertEqual(((int *)arr.base)[2], 0);
	assertEqual(((int *)arr.base)[3], 0);
	assertEqual(((int *)arr.base)[4], 0);
	free(arr.base);
}

void test_create_creates_a_given_length_array_of_3_elements_when_given_length_is_3(){
	ArrayUtil arr=create(sizeof(int),3);
	assertEqual(arr.typeSize, sizeof(int));
	assertEqual(arr.length, 3);
	assertEqual(((int *)arr.base)[0], 0);
	assertEqual(((int *)arr.base)[1], 0);
	assertEqual(((int *)arr.base)[2], 0);
	free(arr.base);
}

void test_if_new_length_is_less_than_old_length_resize_gives_an_array_of_starting_elements_till_given_length(){
	ArrayUtil util,resized;
	int array[]={1,2,3,4,5};
	util.base=array;
	util.typeSize=sizeof(int);
	util.length=5;
	resized=resize(util,3);
	assertEqual(resized.typeSize, util.typeSize);
	assertEqual(resized.length, 3);
	assertEqual(((int *)resized.base)[0], 1);
	assertEqual(((int *)resized.base)[1], 2);
	assertEqual(((int *)resized.base)[2], 3);
	free(resized.base);
}

void test_if_new_length_is_greter_than_old_length_in_resized_array_extra_elements_of_new_array_should_be_0(){
	ArrayUtil util,resized;
	int array[]={1,2,3};
	util.base=array;
	util.typeSize=sizeof(int);
	util.length=3;
	resized=resize(util,5);
	assertEqual(resized.typeSize, util.typeSize);
	assertEqual(resized.length, 5);
	assertEqual(((int *)resized.base)[0], 1);
	assertEqual(((int *)resized.base)[1], 2);
	assertEqual(((int *)resized.base)[2], 3);
	assertEqual(((int *)resized.base)[3], 0);
	assertEqual(((int *)resized.base)[4], 0);
	free(resized.base);
}

void test_findindex_returns_index_when_element_is_present(){
	ArrayUtil util;
	int array[]={1,2,3,4,5,6};
	int x=5;
	util.base=array;
	util.typeSize=sizeof(int);
	util.length=6;
	assertEqual(findIndex(util,&x), 4);
}

void test_findindex_returns_minus_one_when_element_is_not_present(){
	ArrayUtil util;
	int array[]={1,2,3,4,5,6};
	int x=9;
	util.base=array;
	util.typeSize=sizeof(int);
	util.length=6;
	assertEqual(findIndex(util,&x), -1);
}

void test_findindex_returns_index_when_element_is_present_for_character_array(){
	ArrayUtil util;
	char array[]={'a','b','c','d','e','f','\0'};
	char x='c';
	util.base=array;
	util.typeSize=sizeof(char);
	util.length=7;
	assertEqual(findIndex(util,&x), 2);
}

int isEven(void *hint,void *item){
	return *((int*)item)%2==0;
}

void test_findFirst_returns_even_number_from_array_on_first_when_condition_matches(){
	ArrayUtil util;
	void *hint;
	int *result;
	int array[]={1,2,3,4,5,6,7,8};
	util.base=array;
	util.length=8;
	util.typeSize=sizeof(int);
	result =(int *)findFirst(util,isEven,&hint);
	assertEqual(*result, 2);
}

void test_findFirst_returns_0_when_no_element_matches_condition(){
	ArrayUtil util;
	void *hint;
	int *result;
	int array[]={1,3,5,7};
	util.base=array;
	util.length=4;
	util.typeSize=sizeof(int);
	result =findFirst(util,isEven,&hint);
	assertEqual((int )result, 0);
}