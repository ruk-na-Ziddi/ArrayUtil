typedef struct arrayUtil ArrayUtil;
struct arrayUtil {
	void *base;
	int typeSize;
	int length;
};

int areEqual(ArrayUtil a1,ArrayUtil a2);
ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil util, int length);
int findIndex(ArrayUtil util, void* element);