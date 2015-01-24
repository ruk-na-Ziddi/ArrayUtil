#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>

ArrayUtil util1,util2;
typedef struct Student{
    int rollno;
    float age;
} student;
void test_create_Structures_with_all_fields_NULL(){
    student temp = {0,0.0};
    student Student[1] = {temp};
    ArrayUtil expected = {Student,sizeof(student),1};
    util1 = create(sizeof(student),1);    
    assert(areEqual(expected,util1));
}

int isEven(void *hint,void *item){
    return (*((int*)item)%2)==0;
}


void test_filter_populate_destination_array_with_evenNumbers(){
    int maxItem=6;
    int *evens[maxItem];
    util1 = (ArrayUtil){(int[]){101,22,12,13},sizeof(int),4}; 
	assertEqual(filter(util1,isEven,0,(void**)evens,maxItem),2);
	assertEqual(*(evens[0]),22);
	assertEqual(*(evens[1]),12);
}

void test_filter_populate_destination_array_until_hits_max_size_and_return_no_element_added_to_id(){
    int maxItem=2;
    int *evens [maxItem];
    util1 = (ArrayUtil){(int[]){101,22,12,14},sizeof(int),4};   	 
	assertEqual(filter(util1,isEven,0,(void**)evens,maxItem),2);
	assertEqual(*(evens[0]),22);
	assertEqual(*(evens[1]),12);
}

void multiplyBy(void* hint, void* sourceItem, void* destinationItem){
    *(int*)destinationItem = *(int*)sourceItem * *(int*)(hint);
}

void test_map_converts_each_element_source_array_and_put_it_to_destination_array(){
    int hint =10;
    ArrayUtil expected={(int[]){10,20,30,40,50},sizeof(int),5};
    util1=(ArrayUtil){(int[]){1,2,3,4,5},sizeof(int),5};
    util2 =create(sizeof(int),5);
    
    map(util1,util2,multiplyBy,&hint);
    assert(areEqual(expected, util2));
}