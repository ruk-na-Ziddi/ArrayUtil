typedef char * STRING;
typedef int (MatchFunc)(void* hint, void* item);
typedef void (ConvertFunc)(void* hint, void* sourceItem, void* destinationItem);
typedef void (OperationFunc)(void* hint,void* item);
typedef void* (ReducerFunc)(void* hint, void* previousItem, void* item);
typedef struct arrayUtil {
	void *base;
	int typeSize;
	int length;
}ArrayUtil;

int areEqual(ArrayUtil a1,ArrayUtil a2);
ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil util, int length);
int findIndex(ArrayUtil util, void* element);
void *findFirst(ArrayUtil util, MatchFunc* match, void* hint);
void *findLast(ArrayUtil util, MatchFunc* match, void* hint);
int count(ArrayUtil util, MatchFunc* match, void* hint);
int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems );
int arrayEqual(void *arr1,void *arr2);
void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);
void forEach(ArrayUtil util, OperationFunc* operation, void* hint);
void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue);
void dispose(ArrayUtil util);