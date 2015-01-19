typedef struct arrayUtil ArrayUtil;
struct arrayUtil {
	void *base;
	int typeSize;
	int length;
};

int areEqual(ArrayUtil a1,ArrayUtil a2);