#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arrayUtil.h"

int arrayEqual(void *arr1,void *arr2){
	int i;
	char *array1=(char *)arr1;
	char *array2=(char *)arr2;
	int l1=strlen(array1);
	int l2=strlen(array2);
	if(l1!=l2){return 0;}
	for(i=0;i<l1;++i){
		if(array1[i]!=array2[i]){return 0;}
	}
	return 1;
}

int areEqual(ArrayUtil u1,ArrayUtil u2){
	int i;
	char *x=(char *)u1.base;
	char *y=(char *)u2.base;
	if(u1.length!=u2.length || u1.typeSize!=u2.typeSize){
		return 0;
	}
	for (i = 0; i < u1.length*u1.typeSize; ++i){
		if(x[i]!=y[i]){
			return 0;
		}
	}
	return 1;
}

ArrayUtil create(int typeSize, int length){
	ArrayUtil util={calloc(length,typeSize),typeSize,length};
	return util;
}

ArrayUtil resize(ArrayUtil util, int length){
	ArrayUtil resized={malloc(util.typeSize*length),util.typeSize,length};
	int i;
	for(i=0;i<length;++i){
		if(i>=util.length){
			((int *)resized.base)[i]=0;
		}else{
			((int *)resized.base)[i]=((int *)util.base)[i];
		}
	}
	return resized;
}

int findIndex(ArrayUtil util, void* element){
	int i,ele_i=0;
	char *array=(char *)util.base;
	char *ele=(char *)element;
	for (i = 0; i < util.length*util.typeSize; ++i){
		if(ele_i>0 && array[i]!=ele[ele_i]){
			ele_i=0;
		}
		if(array[i]==ele[ele_i]){
			++ele_i;
			if(ele_i==util.typeSize){
				return (i+1)/(util.typeSize)-1;
			}
		}
	}
	return -1;
}

void *findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	int i,j;
	char *ele=malloc(util.typeSize);
	char *array=(char *)util.base;
	for(i=0;i<util.length;++i){
		for(j=0;j<util.typeSize;++j){
			ele[j]=array[(i*util.typeSize)+j];
		}
		if(match(hint,ele)){
			return ele;
		}
	}
	return NULL;
}

void *findLast(ArrayUtil util, MatchFunc* match, void* hint){
	int i,j;
	char *ele=malloc(util.typeSize);
	char *array=(char *)util.base;
	for(i=(util.length-1);i>=0;--i){
		for(j=(util.typeSize-1);j>=0;--j){
			ele[j]=array[(i*util.typeSize)+j];
		}
		if(match(hint,ele)){
			return ele;
		}
	}
	return NULL;
}

int count(ArrayUtil util, MatchFunc* match, void* hint){
	int i,j,count=0;
	char *ele=malloc(util.typeSize);
	char *array=(char *)util.base;
	for(i=0;i<util.length;++i){
		for(j=0;j<util.typeSize;++j){
			ele[j]=array[(i*util.typeSize)+j];
		}
		if(match(hint,ele)){
			++count;
		}
	}
	return count;
}

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
	int i,j,count=0;
	char *ele=malloc(util.typeSize);
	char *array=(char *)util.base;
	for (i=0;i<util.length;i++){
		if(count==maxItems){
			return count;
		}
		for(j=0;j<util.typeSize;++j){
			ele[j]=array[(i*util.typeSize)+j];
		}
		if(match(hint,ele)){
			memcpy(&((*destination)[count*util.typeSize]),ele,util.typeSize);
			++count;
		}
	}
	return count;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	int i;
	char *array=(char *)source.base;
	char *dest=(char *)destination.base;
	for (i=0;i<source.length;i++){
		convert(hint,&(array[i*source.typeSize]),&(dest[i*source.typeSize]));
	}
}

void forEach(ArrayUtil util, OperationFunc* operation, void* hint) {
	int i;
	char *array=(char *)util.base;
	for(i=0;i<util.length;i++){
		operation(hint,&(array[i*util.typeSize]));
	}	
}

void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue){
	void *return_value=intialValue;
	int i;
	for(i=0;i<util.length;i++){
		return_value =  reducer(hint,&((int *)util.base)[i],intialValue);
	}
	return return_value;
}