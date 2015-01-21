#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define STRING_SIZE sizeof(STRING)
#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>

void test_areEqual_return_1_when_both_array_lenght_base_and_typesize_and_elements_are_same(){
	int array1[]={1,2,3,4,5};
	int array2[]={1,2,3,4,5};
	ArrayUtil u1={array1,INT_SIZE,5};
	ArrayUtil u2={array2,INT_SIZE,5};
	assertEqual(areEqual(u1,u2), 1);
}

void test_areEqual_return_1_when_both_characetr_array_lenght_base_and_typesize_and_elements_are_same(){
	char array1[]={'a','b','c','d','\0'};
	char array2[]={'a','b','c','d','\0'};
	ArrayUtil u1={array1,CHAR_SIZE,5};
	ArrayUtil u2={array2,CHAR_SIZE,5};
	assertEqual(areEqual(u1,u2), 1);
}

void test_areEqual_return_0_when_both_characetr_array_lenght_are_same_but_typesize_is_different(){
	int array1[]={1,2,3,4,5};
	char array2[]={'a','b','c','d','\0'};
	ArrayUtil u1={array1,INT_SIZE,5};
	ArrayUtil u2={array2,CHAR_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_both_characetr_array_typesize_are_same_but_length_is_different(){
	char array1[]={'a','b','c','\0'};
	char array2[]={'a','b','c','d','\0'};
	ArrayUtil u1={array1,INT_SIZE,4};
	ArrayUtil u2={array2,CHAR_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_1_for_array_of_string_if_everything_is_same(){
	STRING array1[]={"abc","abc","abc","abc","abc"};
	STRING array2[]={"abc","abc","abc","abc","abc"};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,5};
	assertEqual(areEqual(u1,u2), 1);
}

void test_areEqual_return_0_for_array_of_string_if_lenghts_are_different(){
	STRING array1[]={"abc","abc","abc","abc","abc"};
	STRING array2[]={"abc","abc","abc","abc","abc"};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_1_when_length_and_typesize_are_same_and_each_ele_is_empty_string(){
	STRING array1[]={"","","","",""};
	STRING array2[]={"","","","",""};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,5};
	assertEqual(areEqual(u1,u2), 1);
}

void test_areEqual_return_0_when_typesize_and_length_are_same_but_first_has_less_element(){
	STRING array1[]={"","","",""};
	STRING array2[]={"","","","",""};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_typesize_is_same_but_second_has_less_element_and_less_length(){
	STRING array1[]={"ank","aks","ank","aks","ank"};
	STRING array2[]={"ank","aks","ank","aks"};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_1_typesize_is_STRING_SIZE_and_2_is_INT_SIZE(){
	STRING array1[]={"abc","abc","abc","abc","abc"};
	int array2[]={1,2,3,4,5};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,INT_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_returns_0_when_lenght_are_not_equal(){
	int array1[]={1,2,3,4};
	int array2[]={1,2,3,4,5};
	ArrayUtil u1={array1,INT_SIZE,4};
	ArrayUtil u2={array2,INT_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_returns_0_when_length_is_equal_but_typeSize_is_not_equal(){
	int array1[]={1,2,3,4,5};
	char array2[]={'a','b','c','d','\0'};
	ArrayUtil u1={array1,INT_SIZE,5};
	ArrayUtil u2={array2,CHAR_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_create_creates_a_given_length_array_of_5_elements_initialized_to_0_when_given_length_is_5(){
	int array[]={0,0,0,0,0};
	ArrayUtil util=create(INT_SIZE,5);
	ArrayUtil expected={array,INT_SIZE,5};
	assert(areEqual(util,expected));
	free(util.base);
}

void test_create_creates_a_given_length_array_of_3_elements_initialized_to_0_when_given_length_is_3(){
	int array[]={0,0,0};
	ArrayUtil util=create(INT_SIZE,3);
	ArrayUtil expected={array,INT_SIZE,3};
	assert(areEqual(util,expected));
	free(util.base);
}

void test_if_new_length_is_less_than_old_length_resize_gives_an_array_of_starting_elements_till_given_length(){
	int array[]={1,2,3,4,5};
	int newArray[]={1,2,3};
	ArrayUtil util={array,INT_SIZE,5},resized;
	ArrayUtil expected={newArray,INT_SIZE,3};
	resized=resize(util,3);
	assert(areEqual(resized,expected));
	free(resized.base);
}

void test_if_new_length_is_greter_than_old_length_then_in_resized_array_extra_elements_of_new_array_should_be_0(){
	int array[]={1,2,3};
	int newArray[]={1,2,3,0,0};
	ArrayUtil util={array,INT_SIZE,3},resized;
	ArrayUtil expected={newArray,INT_SIZE,5};
	resized=resize(util,5);
	assert(areEqual(resized,expected));
	free(resized.base);
}

void test_findindex_returns_index_when_element_is_present(){
	int array[]={1,2,3,4,5,6};
	int x=5;
	ArrayUtil util={array,INT_SIZE,6};
	assertEqual(findIndex(util,&x), 4);
}

void test_findindex_returns_minus_one_when_element_is_not_present(){
	int array[]={1,2,3,4,5,6};
	int x=9;
	ArrayUtil util={array,INT_SIZE,6};
	assertEqual(findIndex(util,&x), -1);
}

void test_findindex_returns_index_when_element_is_present_for_character_array(){
	char array[]={'a','b','c','d','e','f','\0'};
	char x='c';
	ArrayUtil util={array,sizeof(char),7};
	assertEqual(findIndex(util,&x), 2);
}

int isEven(void *hint,void *item){
	return *((int*)item)%2==0;
}

void test_findFirst_returns_even_number_from_array_on_first_when_condition_matches(){
	int array[]={1,2,3,4,5,6,7,8};
	ArrayUtil util={array,INT_SIZE,8};
	void *hint;
	int *result;
	result =(int *)findFirst(util,isEven,&hint);
	assertEqual(*result, 2);
}

void test_findFirst_returns_0_when_no_element_matches_condition(){
	int array[]={1,3,5,7};
	ArrayUtil util={array,INT_SIZE,4};
	void *hint;
	int *result;
	result =findFirst(util,isEven,&hint);
	assertEqual((int )result, 0);
}

void test_findLast_returns_last_even_number_from_array_when_condition_matches(){
	int array[]={1,2,3,4,5,6,7,8};
	ArrayUtil util={array,INT_SIZE,8};
	void *hint;
	int *result;
	result =(int *)findLast(util,isEven,&hint);
	assertEqual(*result, 8);
}

void test_findLast_returns_0_when_no_element_matches_condition(){
	int array[]={1,3,5,7};
	ArrayUtil util={array,INT_SIZE,4};
	void *hint;
	int *result;
	result =findLast(util,isEven,&hint);
	assertEqual((int )result, 0);
}

void test_count_returns_4_for_1_2_3_4_5_6_7_8_when_checked_for_even_no(){
	int array[]={1,2,3,4,5,6,7,8};
	ArrayUtil util={array,INT_SIZE,8};
	void *hint;
	int result=count(util,isEven,&hint);
	assertEqual(result, 4);
}

void test_count_returns_0_for_1_3_5_7_when_checked_for_even_no(){
	int array[]={1,3,5,7};
	ArrayUtil util={array,INT_SIZE,4};
	void *hint;
	int result=count(util,isEven,&hint);
	assertEqual(result, 0);
}

void test_filter_fills_filtered_array_with_even_numbers_of_existing_array_and_returns_count(){
	int array[]={1,2,3,4,5,6,7,8};
	int newArray[]={2,4,6,8};
	ArrayUtil util={array,INT_SIZE,8};
	int *filtered=(int *)malloc(sizeof(int)*5);
	int conter=filter(util,isEven,0,(void**)&filtered,5);
 	assertEqual(conter,4);
 	assert(arrayEqual(newArray,filtered));
 	free(filtered);
}

void test_filter_returns_0_when_there_are_no_enven_no_in_existing_array(){
	int array[]={1,3,5,7};
	ArrayUtil util={array,INT_SIZE,4};
	int *filtered=(int *)malloc(sizeof(int)*2);
	int counter=filter(util,isEven,0,(void**)&filtered,2);
 	assertEqual(counter,0);
 	free(filtered);
}

void increment_by_1(void *hint, void *sourceItem, void *destinationItem){
	*(int*)destinationItem = *(int*)sourceItem+1;
}

void test_map_increments_by_one_all_array_elements(){
	void *hint;
	int array[]={1,2,3,4,5};
	int newArray[]={2,3,4,5,6};
	ArrayUtil util={array,INT_SIZE,5};
	ArrayUtil expected={newArray,INT_SIZE,5};
	ArrayUtil mapped={calloc(5,INT_SIZE),INT_SIZE,5};
	map(util,mapped,increment_by_1,&hint);
	assert(areEqual(expected, mapped));
	assert(arrayEqual(newArray,expected.base));
}

void square_elements(void *hint, void *sourceItem, void *destinationItem){
	*(int*)destinationItem=*(int*)sourceItem * *(int*)sourceItem;
}

void test_map_returns_square_of_each_element_in_array(){
	void *hint;
	int array[]={1,2,3,4,5};
	int newArray[]={1,4,9,16,25};
	ArrayUtil util={array,INT_SIZE,5};
	ArrayUtil expected={newArray,INT_SIZE,5};
	ArrayUtil mapped={calloc(5,INT_SIZE),INT_SIZE,5};
	map(util,mapped,square_elements,&hint);
	assert(areEqual(expected, mapped));
	assert(arrayEqual(newArray,expected.base));
}

void element_plus_one(void* hint, void* item){
	*((int *)item)= *((int *)item) + 1;
}

void test_forEach_icrements_each_element_by_one(){
	void *hint;
	int array[]={1,2,3,4,5};
	int incremented[]={2,3,4,5,6};
	ArrayUtil util={array,INT_SIZE,5};
	ArrayUtil expected={incremented,INT_SIZE,5};
	forEach(util,element_plus_one,&hint);
	assert(areEqual(util,expected));
}

void element_into_element_plus_one(void* hint, void* item){
	*((int *)item)= *((int *)item) * ((*((int *)item))+1);
}

void test_forEach_does_multiplication_of_item_with_item_plus_one(){
	void *hint;
	int array[]={1,2,3,4,5};
	int incremented[]={2,6,12,20,30};
	ArrayUtil util={array,INT_SIZE,5};
	ArrayUtil expected={incremented,INT_SIZE,5};
	forEach(util,element_into_element_plus_one,&hint);
	assert(areEqual(util,expected));
}

void *add_all(void* hint, void* previousItem, void* item){
	*((int*)item)= *((int*)previousItem) + *((int*)item);
	return ((int*)item);
}

void test_reduce_gives_15_when_elements_are_1_2_3_4_5_and_initial_value_is_0(){
	void *hint;
	int intialValue=0;
	int array[]={1,2,3,4,5};
	ArrayUtil util={array,INT_SIZE,5};
	void *return_value=reduce(util,add_all,&hint,&intialValue);
	assertEqual(*((int*)return_value),15);
}

void test_reduce_gives_30_when_elements_are_1_2_3_4_5_and_initial_value_is_15(){
	void *hint;
	int intialValue=15;
	int array[]={1,2,3,4,5};
	ArrayUtil util={array,INT_SIZE,5};
	void *return_value=reduce(util,add_all,&hint,&intialValue);
	assertEqual(*((int*)return_value),30);
}