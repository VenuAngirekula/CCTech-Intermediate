#ifndef VERIFY_H
#define VERIFY_H

#include <stdbool.h>

#define verify(cond) \
do \
{ \
	if (!(cond)) \
	{ \
		fprintf(stderr, "%s:%d: error: In function %s(), verification of condition \"%s\" faied.\n", \
				__FILE__, __LINE__, __func__,(#cond));\
	} \
} while (0) \

#endif


