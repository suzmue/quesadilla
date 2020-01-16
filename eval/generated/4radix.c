
#include <iostream>
#include "taco.h"
#include "taco/util/timers.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

#include "taco/tensor.h"
#include "taco/format.h"
#include "taco/error.h"
#include "taco/util/strings.h"
#include "taco/util/files.h"
#include <cstdio>
#include <cstdlib>
#include <vector>


struct coo_t
{
	int32_t	idx0;
	int32_t	idx1;
	int32_t	idx2;
	int32_t	idx3;
	double	val;
};


using namespace taco;
int cmp_0123(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_123(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_23(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_3(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_0132(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_132(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_32(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_2(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_0213(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_213(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_13(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_0231(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_231(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_31(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_1(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_0312(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_312(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_12(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_0321(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_321(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_21(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_1023(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_023(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_1032(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_032(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_1203(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_203(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_03(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_1230(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_230(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_30(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_0(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_1302(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_302(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_02(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_1320(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_320(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_20(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_2013(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_013(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_2031(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_031(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_2103(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_103(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_2130(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_130(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_2301(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_301(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_01(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_2310(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_310(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_10(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_3012(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_012(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_3021(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_021(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_3102(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_102(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_3120(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_120(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_3201(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_201(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_3210(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_210(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 1, 2, 3)
int transpose_coo_0123_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 1, 2, 3)

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(3, []), (2, []), (1, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 1, 3, 2)
int transpose_coo_0132_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 1, 3, 2)

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(2, []), (3, []), (1, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 2, 1, 3)
int transpose_coo_0213_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 2, 1, 3)

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(3, []), (1, []), (2, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 2, 3, 1)
int transpose_coo_0231_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 2, 3, 1)

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(1, []), (3, []), (2, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 3, 1, 2)
int transpose_coo_0312_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 3, 1, 2)

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(2, []), (1, []), (3, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 3, 2, 1)
int transpose_coo_0321_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 3, 2, 1)

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(1, []), (2, []), (3, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 0, 2, 3)
int transpose_coo_1023_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 0, 2, 3)

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(3, []), (2, []), (0, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 0, 3, 2)
int transpose_coo_1032_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 0, 3, 2)

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(2, []), (3, []), (0, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 2, 0, 3)
int transpose_coo_1203_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 2, 0, 3)

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(3, []), (0, []), (2, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 2, 3, 0)
int transpose_coo_1230_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 2, 3, 0)

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(0, []), (3, []), (2, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 3, 0, 2)
int transpose_coo_1302_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 3, 0, 2)

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(2, []), (0, []), (3, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 3, 2, 0)
int transpose_coo_1320_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 3, 2, 0)

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(0, []), (2, []), (3, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 0, 1, 3)
int transpose_coo_2013_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 0, 1, 3)

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(3, []), (1, []), (0, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 0, 3, 1)
int transpose_coo_2031_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 0, 3, 1)

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(1, []), (3, []), (0, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 1, 0, 3)
int transpose_coo_2103_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 1, 0, 3)

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(3, []), (0, []), (1, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 1, 3, 0)
int transpose_coo_2130_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 1, 3, 0)

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(0, []), (3, []), (1, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 3, 0, 1)
int transpose_coo_2301_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 3, 0, 1)

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(1, []), (0, []), (3, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 3, 1, 0)
int transpose_coo_2310_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 3, 1, 0)

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(0, []), (1, []), (3, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 0, 1, 2)
int transpose_coo_3012_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 0, 1, 2)

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(2, []), (1, []), (0, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 0, 2, 1)
int transpose_coo_3021_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 0, 2, 1)

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(1, []), (2, []), (0, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 1, 0, 2)
int transpose_coo_3102_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 1, 0, 2)

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(2, []), (0, []), (1, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 1, 2, 0)
int transpose_coo_3120_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 1, 2, 0)

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(0, []), (2, []), (1, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 2, 0, 1)
int transpose_coo_3201_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 2, 0, 1)

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(1, []), (0, []), (2, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 2, 1, 0)
int transpose_coo_3210_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 2, 1, 0)

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 < B0_size; idx0 ++)
	{
		B0_count[idx0] += B0_count[idx0 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B0_count[idx0]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B0_count);

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 < B1_size; idx1 ++)
	{
		B1_count[idx1] += B1_count[idx1 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B1_count[idx1]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B1_count);

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 < B2_size; idx2 ++)
	{
		B2_count[idx2] += B2_count[idx2 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B2_count[idx2]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B2_count);

	// Histogram sort on mode 3
	int B3_size = dimensions[3];
	int32_t *B3_count = (int32_t *)calloc(B3_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx3 = C_coords[i].idx3;
		B3_count[idx3]++;
	}

	// Prefix sum over B3_count
	for(int idx3 = 1; idx3 < B3_size; idx3 ++)
	{
		B3_count[idx3] += B3_count[idx3 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx3 = C_coords[i].idx3;
		int idx = B3_count[idx3] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B3_count[idx3]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B3_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(0, []), (1, []), (2, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}

int main(int argc, char* argv[]) {
  char *p;
  int SPLIT;
   std::string filename = argv[1];

  long conv = strtol(argv[2], &p, 10);
  SPLIT = conv;

  // Read tensor data  
  int order = 4;
  int * dimensions = (int*)malloc(sizeof(int)*order);
  memset(dimensions, 0, sizeof(int)*order);
  
  int32_t init_alloc_size = 1048576;
  int32_t A_capacity = init_alloc_size;
  struct coo_t *A = (struct coo_t *)malloc(sizeof(struct coo_t)* A_capacity);

  std::fstream stream;
  util::openStream(stream, filename, fstream::in);

  std::string line;
  if (!std::getline(stream, line)) {
    return -1;
  }


  int size = 0;

  do {
      if(size >= A_capacity){
          int32_t A_capacity_new = 2 * (A_capacity);
          A = (struct coo_t*)realloc(A, sizeof(struct coo_t) * A_capacity_new);
          A_capacity = A_capacity_new;
        }

    char* linePtr = (char*)line.data();

    // Generated by coo/gen_taco_to_list.py

	long idx0 = strtol(linePtr, &linePtr, 10);
	A[size].idx0 = (int32_t)idx0 - 1;
	dimensions[0] = std::max(dimensions[0], (int)idx0);
	long idx1 = strtol(linePtr, &linePtr, 10);
	A[size].idx1 = (int32_t)idx1 - 1;
	dimensions[1] = std::max(dimensions[1], (int)idx1);
	long idx2 = strtol(linePtr, &linePtr, 10);
	A[size].idx2 = (int32_t)idx2 - 1;
	dimensions[2] = std::max(dimensions[2], (int)idx2);
	long idx3 = strtol(linePtr, &linePtr, 10);
	A[size].idx3 = (int32_t)idx3 - 1;
	dimensions[3] = std::max(dimensions[3], (int)idx3);

    double val = strtod(linePtr, &linePtr);
    A[size].val = val;
    size ++;

  } while (std::getline(stream, line));

  stream.close();

  // Copy the tensor to test correctness.
  struct coo_t *A_copy = (coo_t*)malloc(sizeof(struct coo_t)*size);
  memcpy(A_copy, A, sizeof(struct coo_t)*size);


		if(0 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_0123);
		// (0, 1, 2, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 0123 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_0123_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 3): [(3, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 3): [(3, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 3): [(3, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 3): [(3, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 1, 2, 3): [(3, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(1 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_0132);
		// (0, 1, 3, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 0132 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_0132_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 2): [(2, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 2): [(2, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 2): [(2, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 2): [(2, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 1, 3, 2): [(2, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(2 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_0213);
		// (0, 2, 1, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 0213 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_0213_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 3): [(3, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 3): [(3, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 3): [(3, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 3): [(3, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 2, 1, 3): [(3, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(3 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_0231);
		// (0, 2, 3, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 0231 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_0231_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 1): [(1, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 1): [(1, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 1): [(1, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 1): [(1, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 2, 3, 1): [(1, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(4 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_0312);
		// (0, 3, 1, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 0312 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_0312_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 2): [(2, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 2): [(2, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 2): [(2, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 2): [(2, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 3, 1, 2): [(2, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(5 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_0321);
		// (0, 3, 2, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 0321 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_0321_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 1): [(1, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 1): [(1, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 1): [(1, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 1): [(1, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 3, 2, 1): [(1, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(6 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_1023);
		// (1, 0, 2, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 1023 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_1023_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 3): [(3, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 3): [(3, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 3): [(3, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 3): [(3, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 0, 2, 3): [(3, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(7 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_1032);
		// (1, 0, 3, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 1032 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_1032_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 2): [(2, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 2): [(2, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 2): [(2, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 2): [(2, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 0, 3, 2): [(2, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(8 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_1203);
		// (1, 2, 0, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 1203 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_1203_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 3): [(3, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 3): [(3, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 3): [(3, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 3): [(3, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 2, 0, 3): [(3, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(9 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_1230);
		// (1, 2, 3, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 1230 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_1230_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 0): [(0, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 0): [(0, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 0): [(0, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 0): [(0, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 2, 3, 0): [(0, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(10 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_1302);
		// (1, 3, 0, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 1302 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_1302_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 2): [(2, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 2): [(2, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 2): [(2, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 2): [(2, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 3, 0, 2): [(2, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(11 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_1320);
		// (1, 3, 2, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 1320 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_1320_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 0): [(0, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 0): [(0, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 0): [(0, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 0): [(0, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 3, 2, 0): [(0, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(12 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_2013);
		// (2, 0, 1, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 2013 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_2013_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 3): [(3, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 3): [(3, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 3): [(3, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 3): [(3, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 0, 1, 3): [(3, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(13 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_2031);
		// (2, 0, 3, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 2031 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_2031_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 1): [(1, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 1): [(1, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 1): [(1, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 1): [(1, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 0, 3, 1): [(1, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(14 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_2103);
		// (2, 1, 0, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 2103 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_2103_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 3): [(3, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 3): [(3, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 3): [(3, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 3): [(3, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 1, 0, 3): [(3, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(15 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_2130);
		// (2, 1, 3, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 2130 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_2130_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 0): [(0, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 0): [(0, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 0): [(0, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 0): [(0, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 1, 3, 0): [(0, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(16 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_2301);
		// (2, 3, 0, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 2301 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_2301_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 1): [(1, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 1): [(1, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 1): [(1, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 1): [(1, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 3, 0, 1): [(1, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(17 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_2310);
		// (2, 3, 1, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 2310 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_2310_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 0): [(0, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 0): [(0, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 0): [(0, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 0): [(0, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 3, 1, 0): [(0, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(18 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_3012);
		// (3, 0, 1, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 3012 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_3012_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 2): [(2, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 2): [(2, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 2): [(2, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 2): [(2, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 0, 1, 2): [(2, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(19 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_3021);
		// (3, 0, 2, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 3021 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_3021_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 1): [(1, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 1): [(1, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 1): [(1, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 1): [(1, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 0, 2, 1): [(1, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(20 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_3102);
		// (3, 1, 0, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 3102 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_3102_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 2): [(2, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 2): [(2, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 2): [(2, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 2): [(2, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 1, 0, 2): [(2, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(21 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_3120);
		// (3, 1, 2, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 3120 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_3120_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 0): [(0, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 0): [(0, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 0): [(0, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 0): [(0, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 1, 2, 0): [(0, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(22 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_3201);
		// (3, 2, 0, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 3201 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_3201_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 1): [(1, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 1): [(1, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 1): [(1, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 1): [(1, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 2, 0, 1): [(1, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(23 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_3210);
		// (3, 2, 1, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 3210 | 4 | 4" ;
			qsort(A, size, sizeof(struct coo_t), cmp_0123);
			transpose_coo_3210_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 0): [(0, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 0): [(0, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 0): [(0, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 0): [(0, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 2, 1, 0): [(0, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
	free(A);
	free(A_copy);
	free(dimensions);
}
