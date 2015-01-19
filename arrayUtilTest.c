#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"
#include <string.h>
#include <stdio.h>

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