#include "function.h"
int cmp(const void* a, const void* b) {
	if(*(int*)a > *(int*)b)	return -1;
	if(*(int*)a < *(int*)b)	return 1;
	return 0;
}
