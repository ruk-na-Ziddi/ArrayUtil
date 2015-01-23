#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)
#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>

void test_findIndex_returns_1_if_the_search_char_is_found_on_1st_location (){
	int x = 'a';
	char array[] = "car";
	ArrayUtil util = create(CHAR_SIZE,3);
	util.base = (void*)array;
	assertEqual(findIndex(util,&x),1);
}

void* sum (void* hint, void* pv, void* cv){
	int* _pv = (int*)pv;
	int* _cv = (int*)cv;
	int* result = (int*)malloc(INT_SIZE); 
	*result = *_pv + *_cv;
	printf("=================================%d\n", *result);
	return result;
}

void test_reduce_returns_sum_of_all_integers_of_array (){
	int hint = 2,result;
	int initial_value = 0;
	int array[] = {1,2,3};
	void* (*fn_ptr)(void*,void*,void*) = &sum;
	ArrayUtil util = create(INT_SIZE,3);
	util.base = array;
	result = *(int*)reduce(util,fn_ptr,(void*)&hint,(void*)&initial_value);
	assertEqual(result,6);
}