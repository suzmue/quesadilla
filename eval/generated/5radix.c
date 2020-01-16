
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
	int32_t	idx4;
	double	val;
};


using namespace taco;
int cmp_01234(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_1234(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_234(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_34(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_4(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_01243(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_1243(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_243(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_43(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_01324(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_1324(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_324(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_24(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_01342(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_1342(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_342(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_42(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_01423(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_1423(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_423(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_01432(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_1432(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_432(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_02134(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_2134(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_134(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_02143(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_2143(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_143(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_02314(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_2314(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_314(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_14(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_02341(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_2341(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_341(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_41(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_02413(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_2413(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_413(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_02431(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_2431(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_431(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_03124(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_3124(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_124(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_03142(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_3142(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_142(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_03214(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_3214(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_214(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_03241(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_3241(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_241(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_03412(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_3412(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_412(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_03421(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_3421(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_421(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_04123(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4123(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_04132(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4132(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_04213(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4213(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_04231(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4231(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_04312(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4312(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_04321(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4321(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_10234(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_0234(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_10243(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_0243(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_10324(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_0324(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_10342(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_0342(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_10423(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_0423(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_10432(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_0432(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_12034(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_2034(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_034(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_12043(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_2043(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_043(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_12304(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_2304(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_304(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_04(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_12340(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_2340(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_340(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_40(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_12403(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_2403(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_403(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_12430(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_2430(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_430(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_13024(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_3024(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_024(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_13042(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_3042(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_042(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_13204(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_3204(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_204(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_13240(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_3240(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_240(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_13402(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_3402(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_402(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_13420(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_3420(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_420(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_14023(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4023(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_14032(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4032(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_14203(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4203(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_14230(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4230(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_14302(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4302(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_14320(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4320(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_20134(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_0134(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_20143(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_0143(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_20314(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_0314(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_20341(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_0341(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_20413(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_0413(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_20431(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_0431(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_21034(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_1034(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_21043(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_1043(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
int cmp_21304(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_1304(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_21340(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_1340(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_21403(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_1403(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_21430(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_1430(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_23014(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_3014(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_014(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_23041(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_3041(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_041(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_23104(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_3104(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_104(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_23140(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_3140(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_140(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_23401(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_3401(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_401(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_23410(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_3410(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_410(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_24013(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4013(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_24031(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4031(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_24103(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4103(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_24130(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4130(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_24301(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4301(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_24310(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4310(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_30124(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_0124(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_30142(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_0142(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_30214(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_0214(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_30241(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_0241(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_30412(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_0412(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_30421(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_0421(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_31024(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_1024(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_31042(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_1042(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	return 0;
}
int cmp_31204(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_1204(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_31240(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_1240(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_31402(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_1402(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_31420(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_1420(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_32014(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_2014(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_32041(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_2041(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
		return 1;
	}
	return 0;
}
int cmp_32104(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_2104(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	return 0;
}
int cmp_32140(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_2140(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
		return 1;
	}
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
		return 1;
	}
	return 0;
}
int cmp_32401(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_2401(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_32410(const void *p, const void *q)
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
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_2410(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_34012(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4012(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_34021(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4021(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_34102(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4102(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_34120(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4120(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_34201(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4201(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_34210(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_4210(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
int cmp_40123(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
		return 1;
	}
	return 0;
}
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
int cmp_40132(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
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
int cmp_40213(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
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
int cmp_40231(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
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
int cmp_40312(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
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
int cmp_40321(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
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
int cmp_41023(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
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
int cmp_41032(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
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
int cmp_41203(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
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
int cmp_41230(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
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
int cmp_41302(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
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
int cmp_41320(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
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
int cmp_42013(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
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
int cmp_42031(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
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
int cmp_42103(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx3 < s->idx3) {
		return -1;
	} else if (r->idx3 > s->idx3) {
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
int cmp_42130(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
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
int cmp_42301(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
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
int cmp_42310(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
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
int cmp_43012(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
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
int cmp_43021(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
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
int cmp_43102(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx2 < s->idx2) {
		return -1;
	} else if (r->idx2 > s->idx2) {
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
int cmp_43120(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
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
int cmp_43201(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx1 < s->idx1) {
		return -1;
	} else if (r->idx1 > s->idx1) {
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
int cmp_43210(const void *p, const void *q)
{
	struct coo_t * r = (struct coo_t *)p;
	struct coo_t * s = (struct coo_t *)q;
	if(r->idx4 < s->idx4) {
		return -1;
	} else if (r->idx4 > s->idx4) {
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
	if(r->idx0 < s->idx0) {
		return -1;
	} else if (r->idx0 > s->idx0) {
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
// transpose permutes the modes of the coordinates to be (0, 1, 2, 3, 4)
int transpose_coo_01234_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 1, 2, 3, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (3, []), (2, []), (1, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 1, 2, 4, 3)
int transpose_coo_01243_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 1, 2, 4, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (4, []), (2, []), (1, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 1, 3, 2, 4)
int transpose_coo_01324_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 1, 3, 2, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (2, []), (3, []), (1, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 1, 3, 4, 2)
int transpose_coo_01342_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 1, 3, 4, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (4, []), (3, []), (1, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 1, 4, 2, 3)
int transpose_coo_01423_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 1, 4, 2, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (2, []), (4, []), (1, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 1, 4, 3, 2)
int transpose_coo_01432_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 1, 4, 3, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (3, []), (4, []), (1, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 2, 1, 3, 4)
int transpose_coo_02134_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 2, 1, 3, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (3, []), (1, []), (2, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 2, 1, 4, 3)
int transpose_coo_02143_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 2, 1, 4, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (4, []), (1, []), (2, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 2, 3, 1, 4)
int transpose_coo_02314_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 2, 3, 1, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (1, []), (3, []), (2, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 2, 3, 4, 1)
int transpose_coo_02341_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 2, 3, 4, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (4, []), (3, []), (2, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 2, 4, 1, 3)
int transpose_coo_02413_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 2, 4, 1, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (1, []), (4, []), (2, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 2, 4, 3, 1)
int transpose_coo_02431_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 2, 4, 3, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (3, []), (4, []), (2, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 3, 1, 2, 4)
int transpose_coo_03124_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 3, 1, 2, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (2, []), (1, []), (3, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 3, 1, 4, 2)
int transpose_coo_03142_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 3, 1, 4, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (4, []), (1, []), (3, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 3, 2, 1, 4)
int transpose_coo_03214_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 3, 2, 1, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (1, []), (2, []), (3, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 3, 2, 4, 1)
int transpose_coo_03241_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 3, 2, 4, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (4, []), (2, []), (3, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 3, 4, 1, 2)
int transpose_coo_03412_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 3, 4, 1, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (1, []), (4, []), (3, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 3, 4, 2, 1)
int transpose_coo_03421_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 3, 4, 2, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (2, []), (4, []), (3, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 4, 1, 2, 3)
int transpose_coo_04123_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 4, 1, 2, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (2, []), (1, []), (4, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 4, 1, 3, 2)
int transpose_coo_04132_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 4, 1, 3, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (3, []), (1, []), (4, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 4, 2, 1, 3)
int transpose_coo_04213_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 4, 2, 1, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (1, []), (2, []), (4, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 4, 2, 3, 1)
int transpose_coo_04231_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 4, 2, 3, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (3, []), (2, []), (4, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 4, 3, 1, 2)
int transpose_coo_04312_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 4, 3, 1, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (1, []), (3, []), (4, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (0, 4, 3, 2, 1)
int transpose_coo_04321_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (0, 4, 3, 2, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (2, []), (3, []), (4, []), (0, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 0, 2, 3, 4)
int transpose_coo_10234_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 0, 2, 3, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (3, []), (2, []), (0, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 0, 2, 4, 3)
int transpose_coo_10243_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 0, 2, 4, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (4, []), (2, []), (0, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 0, 3, 2, 4)
int transpose_coo_10324_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 0, 3, 2, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (2, []), (3, []), (0, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 0, 3, 4, 2)
int transpose_coo_10342_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 0, 3, 4, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (4, []), (3, []), (0, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 0, 4, 2, 3)
int transpose_coo_10423_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 0, 4, 2, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (2, []), (4, []), (0, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 0, 4, 3, 2)
int transpose_coo_10432_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 0, 4, 3, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (3, []), (4, []), (0, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 2, 0, 3, 4)
int transpose_coo_12034_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 2, 0, 3, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (3, []), (0, []), (2, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 2, 0, 4, 3)
int transpose_coo_12043_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 2, 0, 4, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (4, []), (0, []), (2, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 2, 3, 0, 4)
int transpose_coo_12304_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 2, 3, 0, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (0, []), (3, []), (2, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 2, 3, 4, 0)
int transpose_coo_12340_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 2, 3, 4, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (4, []), (3, []), (2, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 2, 4, 0, 3)
int transpose_coo_12403_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 2, 4, 0, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (0, []), (4, []), (2, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 2, 4, 3, 0)
int transpose_coo_12430_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 2, 4, 3, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (3, []), (4, []), (2, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 3, 0, 2, 4)
int transpose_coo_13024_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 3, 0, 2, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (2, []), (0, []), (3, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 3, 0, 4, 2)
int transpose_coo_13042_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 3, 0, 4, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (4, []), (0, []), (3, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 3, 2, 0, 4)
int transpose_coo_13204_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 3, 2, 0, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (0, []), (2, []), (3, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 3, 2, 4, 0)
int transpose_coo_13240_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 3, 2, 4, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (4, []), (2, []), (3, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 3, 4, 0, 2)
int transpose_coo_13402_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 3, 4, 0, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (0, []), (4, []), (3, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 3, 4, 2, 0)
int transpose_coo_13420_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 3, 4, 2, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (2, []), (4, []), (3, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 4, 0, 2, 3)
int transpose_coo_14023_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 4, 0, 2, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (2, []), (0, []), (4, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 4, 0, 3, 2)
int transpose_coo_14032_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 4, 0, 3, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (3, []), (0, []), (4, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 4, 2, 0, 3)
int transpose_coo_14203_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 4, 2, 0, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (0, []), (2, []), (4, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 4, 2, 3, 0)
int transpose_coo_14230_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 4, 2, 3, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (3, []), (2, []), (4, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 4, 3, 0, 2)
int transpose_coo_14302_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 4, 3, 0, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (0, []), (3, []), (4, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (1, 4, 3, 2, 0)
int transpose_coo_14320_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (1, 4, 3, 2, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (2, []), (3, []), (4, []), (1, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 0, 1, 3, 4)
int transpose_coo_20134_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 0, 1, 3, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (3, []), (1, []), (0, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 0, 1, 4, 3)
int transpose_coo_20143_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 0, 1, 4, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (4, []), (1, []), (0, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 0, 3, 1, 4)
int transpose_coo_20314_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 0, 3, 1, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (1, []), (3, []), (0, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 0, 3, 4, 1)
int transpose_coo_20341_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 0, 3, 4, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (4, []), (3, []), (0, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 0, 4, 1, 3)
int transpose_coo_20413_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 0, 4, 1, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (1, []), (4, []), (0, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 0, 4, 3, 1)
int transpose_coo_20431_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 0, 4, 3, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (3, []), (4, []), (0, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 1, 0, 3, 4)
int transpose_coo_21034_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 1, 0, 3, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (3, []), (0, []), (1, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 1, 0, 4, 3)
int transpose_coo_21043_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 1, 0, 4, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (4, []), (0, []), (1, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 1, 3, 0, 4)
int transpose_coo_21304_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 1, 3, 0, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (0, []), (3, []), (1, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 1, 3, 4, 0)
int transpose_coo_21340_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 1, 3, 4, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (4, []), (3, []), (1, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 1, 4, 0, 3)
int transpose_coo_21403_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 1, 4, 0, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (0, []), (4, []), (1, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 1, 4, 3, 0)
int transpose_coo_21430_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 1, 4, 3, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (3, []), (4, []), (1, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 3, 0, 1, 4)
int transpose_coo_23014_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 3, 0, 1, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (1, []), (0, []), (3, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 3, 0, 4, 1)
int transpose_coo_23041_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 3, 0, 4, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (4, []), (0, []), (3, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 3, 1, 0, 4)
int transpose_coo_23104_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 3, 1, 0, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (0, []), (1, []), (3, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 3, 1, 4, 0)
int transpose_coo_23140_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 3, 1, 4, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (4, []), (1, []), (3, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 3, 4, 0, 1)
int transpose_coo_23401_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 3, 4, 0, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (0, []), (4, []), (3, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 3, 4, 1, 0)
int transpose_coo_23410_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 3, 4, 1, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (1, []), (4, []), (3, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 4, 0, 1, 3)
int transpose_coo_24013_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 4, 0, 1, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (1, []), (0, []), (4, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 4, 0, 3, 1)
int transpose_coo_24031_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 4, 0, 3, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (3, []), (0, []), (4, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 4, 1, 0, 3)
int transpose_coo_24103_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 4, 1, 0, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(3, []), (0, []), (1, []), (4, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 4, 1, 3, 0)
int transpose_coo_24130_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 4, 1, 3, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (3, []), (1, []), (4, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 4, 3, 0, 1)
int transpose_coo_24301_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 4, 3, 0, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (0, []), (3, []), (4, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (2, 4, 3, 1, 0)
int transpose_coo_24310_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (2, 4, 3, 1, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (1, []), (3, []), (4, []), (2, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 0, 1, 2, 4)
int transpose_coo_30124_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 0, 1, 2, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (2, []), (1, []), (0, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 0, 1, 4, 2)
int transpose_coo_30142_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 0, 1, 4, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (4, []), (1, []), (0, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 0, 2, 1, 4)
int transpose_coo_30214_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 0, 2, 1, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (1, []), (2, []), (0, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 0, 2, 4, 1)
int transpose_coo_30241_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 0, 2, 4, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (4, []), (2, []), (0, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 0, 4, 1, 2)
int transpose_coo_30412_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 0, 4, 1, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (1, []), (4, []), (0, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 0, 4, 2, 1)
int transpose_coo_30421_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 0, 4, 2, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (2, []), (4, []), (0, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 1, 0, 2, 4)
int transpose_coo_31024_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 1, 0, 2, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (2, []), (0, []), (1, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 1, 0, 4, 2)
int transpose_coo_31042_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 1, 0, 4, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (4, []), (0, []), (1, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 1, 2, 0, 4)
int transpose_coo_31204_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 1, 2, 0, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (0, []), (2, []), (1, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 1, 2, 4, 0)
int transpose_coo_31240_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 1, 2, 4, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (4, []), (2, []), (1, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 1, 4, 0, 2)
int transpose_coo_31402_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 1, 4, 0, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (0, []), (4, []), (1, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 1, 4, 2, 0)
int transpose_coo_31420_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 1, 4, 2, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (2, []), (4, []), (1, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 2, 0, 1, 4)
int transpose_coo_32014_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 2, 0, 1, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (1, []), (0, []), (2, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 2, 0, 4, 1)
int transpose_coo_32041_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 2, 0, 4, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (4, []), (0, []), (2, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 2, 1, 0, 4)
int transpose_coo_32104_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 2, 1, 0, 4)

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(4, []), (0, []), (1, []), (2, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 2, 1, 4, 0)
int transpose_coo_32140_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 2, 1, 4, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (4, []), (1, []), (2, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 2, 4, 0, 1)
int transpose_coo_32401_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 2, 4, 0, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (0, []), (4, []), (2, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 2, 4, 1, 0)
int transpose_coo_32410_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 2, 4, 1, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (1, []), (4, []), (2, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 4, 0, 1, 2)
int transpose_coo_34012_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 4, 0, 1, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (1, []), (0, []), (4, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 4, 0, 2, 1)
int transpose_coo_34021_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 4, 0, 2, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (2, []), (0, []), (4, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 4, 1, 0, 2)
int transpose_coo_34102_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 4, 1, 0, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(2, []), (0, []), (1, []), (4, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 4, 1, 2, 0)
int transpose_coo_34120_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 4, 1, 2, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (2, []), (1, []), (4, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 4, 2, 0, 1)
int transpose_coo_34201_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 4, 2, 0, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(1, []), (0, []), (2, []), (4, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (3, 4, 2, 1, 0)
int transpose_coo_34210_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (3, 4, 2, 1, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);

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
	cout << " |  [(0, []), (1, []), (2, []), (4, []), (3, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 0, 1, 2, 3)
int transpose_coo_40123_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 0, 1, 2, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(3, []), (2, []), (1, []), (0, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 0, 1, 3, 2)
int transpose_coo_40132_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 0, 1, 3, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(2, []), (3, []), (1, []), (0, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 0, 2, 1, 3)
int transpose_coo_40213_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 0, 2, 1, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(3, []), (1, []), (2, []), (0, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 0, 2, 3, 1)
int transpose_coo_40231_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 0, 2, 3, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(1, []), (3, []), (2, []), (0, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 0, 3, 1, 2)
int transpose_coo_40312_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 0, 3, 1, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(2, []), (1, []), (3, []), (0, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 0, 3, 2, 1)
int transpose_coo_40321_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 0, 3, 2, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(1, []), (2, []), (3, []), (0, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 1, 0, 2, 3)
int transpose_coo_41023_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 1, 0, 2, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(3, []), (2, []), (0, []), (1, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 1, 0, 3, 2)
int transpose_coo_41032_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 1, 0, 3, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(2, []), (3, []), (0, []), (1, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 1, 2, 0, 3)
int transpose_coo_41203_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 1, 2, 0, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(3, []), (0, []), (2, []), (1, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 1, 2, 3, 0)
int transpose_coo_41230_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 1, 2, 3, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(0, []), (3, []), (2, []), (1, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 1, 3, 0, 2)
int transpose_coo_41302_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 1, 3, 0, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(2, []), (0, []), (3, []), (1, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 1, 3, 2, 0)
int transpose_coo_41320_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 1, 3, 2, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(0, []), (2, []), (3, []), (1, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 2, 0, 1, 3)
int transpose_coo_42013_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 2, 0, 1, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(3, []), (1, []), (0, []), (2, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 2, 0, 3, 1)
int transpose_coo_42031_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 2, 0, 3, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(1, []), (3, []), (0, []), (2, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 2, 1, 0, 3)
int transpose_coo_42103_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 2, 1, 0, 3)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(3, []), (0, []), (1, []), (2, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 2, 1, 3, 0)
int transpose_coo_42130_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 2, 1, 3, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(0, []), (3, []), (1, []), (2, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 2, 3, 0, 1)
int transpose_coo_42301_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 2, 3, 0, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(1, []), (0, []), (3, []), (2, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 2, 3, 1, 0)
int transpose_coo_42310_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 2, 3, 1, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(0, []), (1, []), (3, []), (2, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 3, 0, 1, 2)
int transpose_coo_43012_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 3, 0, 1, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(2, []), (1, []), (0, []), (3, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 3, 0, 2, 1)
int transpose_coo_43021_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 3, 0, 2, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(1, []), (2, []), (0, []), (3, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 3, 1, 0, 2)
int transpose_coo_43102_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 3, 1, 0, 2)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(2, []), (0, []), (1, []), (3, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 3, 1, 2, 0)
int transpose_coo_43120_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 3, 1, 2, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(0, []), (2, []), (1, []), (3, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 3, 2, 0, 1)
int transpose_coo_43201_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 3, 2, 0, 1)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(1, []), (0, []), (2, []), (3, []), (4, [])] ";
	cout << " | "<< res ;
	return 0;
}
// transpose permutes the modes of the coordinates to be (4, 3, 2, 1, 0)
int transpose_coo_43210_all(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	taco::util::Timer timer;
	timer.start();
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in (4, 3, 2, 1, 0)

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

	// Histogram sort on mode 4
	int B4_size = dimensions[4];
	int32_t *B4_count = (int32_t *)calloc(B4_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx4 = C_coords[i].idx4;
		B4_count[idx4]++;
	}

	// Prefix sum over B4_count
	for(int idx4 = 1; idx4 < B4_size; idx4 ++)
	{
		B4_count[idx4] += B4_count[idx4 - 1];
	}
	for( int i = c_size - 1; i >= 0; i--)
	{
		int32_t idx4 = C_coords[i].idx4;
		int idx = B4_count[idx4] - 1;
		C_coords_scratch[idx] = C_coords[i];
		B4_count[idx4]--;
	}

	memcpy(C_coords, C_coords_scratch, c_size*sizeof(struct coo_t));


	free(B4_count);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	timer.stop();
	taco::util::TimeResults res = timer.getResult();
	cout << " |  [(0, []), (1, []), (2, []), (3, []), (4, [])] ";
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
  int order = 5;
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
	long idx4 = strtol(linePtr, &linePtr, 10);
	A[size].idx4 = (int32_t)idx4 - 1;
	dimensions[4] = std::max(dimensions[4], (int)idx4);

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
			qsort(A_copy, size, sizeof(struct coo_t), cmp_01234);
		// (0, 1, 2, 3, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 01234 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_01234_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 3, 4): [(4, []), (3, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 3, 4): [(4, []), (3, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 3, 4): [(4, []), (3, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 3, 4): [(4, []), (3, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 3, 4): [(4, []), (3, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 1, 2, 3, 4): [(4, []), (3, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(1 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_01243);
		// (0, 1, 2, 4, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 01243 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_01243_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 4, 3): [(3, []), (4, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 4, 3): [(3, []), (4, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 4, 3): [(3, []), (4, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 4, 3): [(3, []), (4, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 1, 2, 4, 3): [(3, []), (4, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 1, 2, 4, 3): [(3, []), (4, []), (2, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(2 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_01324);
		// (0, 1, 3, 2, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 01324 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_01324_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 2, 4): [(4, []), (2, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 2, 4): [(4, []), (2, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 2, 4): [(4, []), (2, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 2, 4): [(4, []), (2, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 2, 4): [(4, []), (2, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 1, 3, 2, 4): [(4, []), (2, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(3 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_01342);
		// (0, 1, 3, 4, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 01342 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_01342_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 4, 2): [(2, []), (4, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 4, 2): [(2, []), (4, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 4, 2): [(2, []), (4, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 4, 2): [(2, []), (4, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 1, 3, 4, 2): [(2, []), (4, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 1, 3, 4, 2): [(2, []), (4, []), (3, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(4 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_01423);
		// (0, 1, 4, 2, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 01423 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_01423_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 1, 4, 2, 3): [(3, []), (2, []), (4, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 1, 4, 2, 3): [(3, []), (2, []), (4, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 1, 4, 2, 3): [(3, []), (2, []), (4, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 1, 4, 2, 3): [(3, []), (2, []), (4, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 1, 4, 2, 3): [(3, []), (2, []), (4, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 1, 4, 2, 3): [(3, []), (2, []), (4, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(5 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_01432);
		// (0, 1, 4, 3, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 01432 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_01432_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 1, 4, 3, 2): [(2, []), (3, []), (4, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 1, 4, 3, 2): [(2, []), (3, []), (4, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 1, 4, 3, 2): [(2, []), (3, []), (4, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 1, 4, 3, 2): [(2, []), (3, []), (4, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 1, 4, 3, 2): [(2, []), (3, []), (4, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 1, 4, 3, 2): [(2, []), (3, []), (4, []), (1, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(6 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_02134);
		// (0, 2, 1, 3, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 02134 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_02134_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 3, 4): [(4, []), (3, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 3, 4): [(4, []), (3, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 3, 4): [(4, []), (3, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 3, 4): [(4, []), (3, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 3, 4): [(4, []), (3, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 2, 1, 3, 4): [(4, []), (3, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(7 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_02143);
		// (0, 2, 1, 4, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 02143 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_02143_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 4, 3): [(3, []), (4, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 4, 3): [(3, []), (4, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 4, 3): [(3, []), (4, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 4, 3): [(3, []), (4, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 2, 1, 4, 3): [(3, []), (4, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 2, 1, 4, 3): [(3, []), (4, []), (1, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(8 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_02314);
		// (0, 2, 3, 1, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 02314 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_02314_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 1, 4): [(4, []), (1, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 1, 4): [(4, []), (1, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 1, 4): [(4, []), (1, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 1, 4): [(4, []), (1, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 1, 4): [(4, []), (1, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 2, 3, 1, 4): [(4, []), (1, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(9 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_02341);
		// (0, 2, 3, 4, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 02341 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_02341_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 4, 1): [(1, []), (4, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 4, 1): [(1, []), (4, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 4, 1): [(1, []), (4, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 4, 1): [(1, []), (4, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 2, 3, 4, 1): [(1, []), (4, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 2, 3, 4, 1): [(1, []), (4, []), (3, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(10 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_02413);
		// (0, 2, 4, 1, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 02413 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_02413_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 2, 4, 1, 3): [(3, []), (1, []), (4, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 2, 4, 1, 3): [(3, []), (1, []), (4, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 2, 4, 1, 3): [(3, []), (1, []), (4, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 2, 4, 1, 3): [(3, []), (1, []), (4, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 2, 4, 1, 3): [(3, []), (1, []), (4, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 2, 4, 1, 3): [(3, []), (1, []), (4, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(11 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_02431);
		// (0, 2, 4, 3, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 02431 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_02431_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 2, 4, 3, 1): [(1, []), (3, []), (4, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 2, 4, 3, 1): [(1, []), (3, []), (4, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 2, 4, 3, 1): [(1, []), (3, []), (4, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 2, 4, 3, 1): [(1, []), (3, []), (4, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 2, 4, 3, 1): [(1, []), (3, []), (4, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 2, 4, 3, 1): [(1, []), (3, []), (4, []), (2, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(12 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_03124);
		// (0, 3, 1, 2, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 03124 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_03124_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 2, 4): [(4, []), (2, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 2, 4): [(4, []), (2, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 2, 4): [(4, []), (2, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 2, 4): [(4, []), (2, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 2, 4): [(4, []), (2, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 3, 1, 2, 4): [(4, []), (2, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(13 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_03142);
		// (0, 3, 1, 4, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 03142 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_03142_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 4, 2): [(2, []), (4, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 4, 2): [(2, []), (4, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 4, 2): [(2, []), (4, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 4, 2): [(2, []), (4, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 3, 1, 4, 2): [(2, []), (4, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 3, 1, 4, 2): [(2, []), (4, []), (1, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(14 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_03214);
		// (0, 3, 2, 1, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 03214 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_03214_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 1, 4): [(4, []), (1, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 1, 4): [(4, []), (1, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 1, 4): [(4, []), (1, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 1, 4): [(4, []), (1, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 1, 4): [(4, []), (1, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 3, 2, 1, 4): [(4, []), (1, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(15 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_03241);
		// (0, 3, 2, 4, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 03241 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_03241_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 4, 1): [(1, []), (4, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 4, 1): [(1, []), (4, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 4, 1): [(1, []), (4, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 4, 1): [(1, []), (4, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 3, 2, 4, 1): [(1, []), (4, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 3, 2, 4, 1): [(1, []), (4, []), (2, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(16 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_03412);
		// (0, 3, 4, 1, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 03412 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_03412_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 3, 4, 1, 2): [(2, []), (1, []), (4, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 3, 4, 1, 2): [(2, []), (1, []), (4, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 3, 4, 1, 2): [(2, []), (1, []), (4, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 3, 4, 1, 2): [(2, []), (1, []), (4, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 3, 4, 1, 2): [(2, []), (1, []), (4, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 3, 4, 1, 2): [(2, []), (1, []), (4, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(17 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_03421);
		// (0, 3, 4, 2, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 03421 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_03421_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 3, 4, 2, 1): [(1, []), (2, []), (4, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 3, 4, 2, 1): [(1, []), (2, []), (4, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 3, 4, 2, 1): [(1, []), (2, []), (4, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 3, 4, 2, 1): [(1, []), (2, []), (4, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 3, 4, 2, 1): [(1, []), (2, []), (4, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 3, 4, 2, 1): [(1, []), (2, []), (4, []), (3, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(18 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_04123);
		// (0, 4, 1, 2, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 04123 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_04123_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 4, 1, 2, 3): [(3, []), (2, []), (1, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 4, 1, 2, 3): [(3, []), (2, []), (1, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 4, 1, 2, 3): [(3, []), (2, []), (1, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 4, 1, 2, 3): [(3, []), (2, []), (1, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 4, 1, 2, 3): [(3, []), (2, []), (1, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 4, 1, 2, 3): [(3, []), (2, []), (1, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(19 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_04132);
		// (0, 4, 1, 3, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 04132 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_04132_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 4, 1, 3, 2): [(2, []), (3, []), (1, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 4, 1, 3, 2): [(2, []), (3, []), (1, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 4, 1, 3, 2): [(2, []), (3, []), (1, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 4, 1, 3, 2): [(2, []), (3, []), (1, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 4, 1, 3, 2): [(2, []), (3, []), (1, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 4, 1, 3, 2): [(2, []), (3, []), (1, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(20 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_04213);
		// (0, 4, 2, 1, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 04213 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_04213_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 4, 2, 1, 3): [(3, []), (1, []), (2, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 4, 2, 1, 3): [(3, []), (1, []), (2, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 4, 2, 1, 3): [(3, []), (1, []), (2, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 4, 2, 1, 3): [(3, []), (1, []), (2, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 4, 2, 1, 3): [(3, []), (1, []), (2, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 4, 2, 1, 3): [(3, []), (1, []), (2, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(21 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_04231);
		// (0, 4, 2, 3, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 04231 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_04231_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 4, 2, 3, 1): [(1, []), (3, []), (2, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 4, 2, 3, 1): [(1, []), (3, []), (2, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 4, 2, 3, 1): [(1, []), (3, []), (2, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 4, 2, 3, 1): [(1, []), (3, []), (2, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 4, 2, 3, 1): [(1, []), (3, []), (2, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 4, 2, 3, 1): [(1, []), (3, []), (2, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(22 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_04312);
		// (0, 4, 3, 1, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 04312 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_04312_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 4, 3, 1, 2): [(2, []), (1, []), (3, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 4, 3, 1, 2): [(2, []), (1, []), (3, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 4, 3, 1, 2): [(2, []), (1, []), (3, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 4, 3, 1, 2): [(2, []), (1, []), (3, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 4, 3, 1, 2): [(2, []), (1, []), (3, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 4, 3, 1, 2): [(2, []), (1, []), (3, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(23 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_04321);
		// (0, 4, 3, 2, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 04321 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_04321_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (0, 4, 3, 2, 1): [(1, []), (2, []), (3, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (0, 4, 3, 2, 1): [(1, []), (2, []), (3, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (0, 4, 3, 2, 1): [(1, []), (2, []), (3, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (0, 4, 3, 2, 1): [(1, []), (2, []), (3, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (0, 4, 3, 2, 1): [(1, []), (2, []), (3, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (0, 4, 3, 2, 1): [(1, []), (2, []), (3, []), (4, []), (0, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(24 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_10234);
		// (1, 0, 2, 3, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 10234 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_10234_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 3, 4): [(4, []), (3, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 3, 4): [(4, []), (3, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 3, 4): [(4, []), (3, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 3, 4): [(4, []), (3, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 3, 4): [(4, []), (3, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 0, 2, 3, 4): [(4, []), (3, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(25 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_10243);
		// (1, 0, 2, 4, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 10243 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_10243_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 4, 3): [(3, []), (4, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 4, 3): [(3, []), (4, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 4, 3): [(3, []), (4, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 4, 3): [(3, []), (4, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 0, 2, 4, 3): [(3, []), (4, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 0, 2, 4, 3): [(3, []), (4, []), (2, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(26 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_10324);
		// (1, 0, 3, 2, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 10324 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_10324_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 2, 4): [(4, []), (2, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 2, 4): [(4, []), (2, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 2, 4): [(4, []), (2, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 2, 4): [(4, []), (2, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 2, 4): [(4, []), (2, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 0, 3, 2, 4): [(4, []), (2, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(27 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_10342);
		// (1, 0, 3, 4, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 10342 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_10342_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 4, 2): [(2, []), (4, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 4, 2): [(2, []), (4, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 4, 2): [(2, []), (4, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 4, 2): [(2, []), (4, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 0, 3, 4, 2): [(2, []), (4, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 0, 3, 4, 2): [(2, []), (4, []), (3, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(28 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_10423);
		// (1, 0, 4, 2, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 10423 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_10423_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 0, 4, 2, 3): [(3, []), (2, []), (4, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 0, 4, 2, 3): [(3, []), (2, []), (4, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 0, 4, 2, 3): [(3, []), (2, []), (4, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 0, 4, 2, 3): [(3, []), (2, []), (4, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 0, 4, 2, 3): [(3, []), (2, []), (4, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 0, 4, 2, 3): [(3, []), (2, []), (4, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(29 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_10432);
		// (1, 0, 4, 3, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 10432 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_10432_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 0, 4, 3, 2): [(2, []), (3, []), (4, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 0, 4, 3, 2): [(2, []), (3, []), (4, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 0, 4, 3, 2): [(2, []), (3, []), (4, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 0, 4, 3, 2): [(2, []), (3, []), (4, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 0, 4, 3, 2): [(2, []), (3, []), (4, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 0, 4, 3, 2): [(2, []), (3, []), (4, []), (0, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(30 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_12034);
		// (1, 2, 0, 3, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 12034 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_12034_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 3, 4): [(4, []), (3, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 3, 4): [(4, []), (3, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 3, 4): [(4, []), (3, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 3, 4): [(4, []), (3, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 3, 4): [(4, []), (3, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 2, 0, 3, 4): [(4, []), (3, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(31 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_12043);
		// (1, 2, 0, 4, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 12043 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_12043_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 4, 3): [(3, []), (4, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 4, 3): [(3, []), (4, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 4, 3): [(3, []), (4, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 4, 3): [(3, []), (4, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 2, 0, 4, 3): [(3, []), (4, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 2, 0, 4, 3): [(3, []), (4, []), (0, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(32 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_12304);
		// (1, 2, 3, 0, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 12304 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_12304_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 0, 4): [(4, []), (0, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 0, 4): [(4, []), (0, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 0, 4): [(4, []), (0, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 0, 4): [(4, []), (0, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 0, 4): [(4, []), (0, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 2, 3, 0, 4): [(4, []), (0, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(33 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_12340);
		// (1, 2, 3, 4, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 12340 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_12340_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 4, 0): [(0, []), (4, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 4, 0): [(0, []), (4, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 4, 0): [(0, []), (4, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 4, 0): [(0, []), (4, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 2, 3, 4, 0): [(0, []), (4, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 2, 3, 4, 0): [(0, []), (4, []), (3, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(34 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_12403);
		// (1, 2, 4, 0, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 12403 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_12403_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 2, 4, 0, 3): [(3, []), (0, []), (4, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 2, 4, 0, 3): [(3, []), (0, []), (4, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 2, 4, 0, 3): [(3, []), (0, []), (4, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 2, 4, 0, 3): [(3, []), (0, []), (4, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 2, 4, 0, 3): [(3, []), (0, []), (4, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 2, 4, 0, 3): [(3, []), (0, []), (4, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(35 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_12430);
		// (1, 2, 4, 3, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 12430 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_12430_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 2, 4, 3, 0): [(0, []), (3, []), (4, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 2, 4, 3, 0): [(0, []), (3, []), (4, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 2, 4, 3, 0): [(0, []), (3, []), (4, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 2, 4, 3, 0): [(0, []), (3, []), (4, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 2, 4, 3, 0): [(0, []), (3, []), (4, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 2, 4, 3, 0): [(0, []), (3, []), (4, []), (2, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(36 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_13024);
		// (1, 3, 0, 2, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 13024 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_13024_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 2, 4): [(4, []), (2, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 2, 4): [(4, []), (2, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 2, 4): [(4, []), (2, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 2, 4): [(4, []), (2, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 2, 4): [(4, []), (2, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 3, 0, 2, 4): [(4, []), (2, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(37 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_13042);
		// (1, 3, 0, 4, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 13042 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_13042_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 4, 2): [(2, []), (4, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 4, 2): [(2, []), (4, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 4, 2): [(2, []), (4, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 4, 2): [(2, []), (4, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 3, 0, 4, 2): [(2, []), (4, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 3, 0, 4, 2): [(2, []), (4, []), (0, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(38 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_13204);
		// (1, 3, 2, 0, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 13204 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_13204_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 0, 4): [(4, []), (0, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 0, 4): [(4, []), (0, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 0, 4): [(4, []), (0, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 0, 4): [(4, []), (0, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 0, 4): [(4, []), (0, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 3, 2, 0, 4): [(4, []), (0, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(39 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_13240);
		// (1, 3, 2, 4, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 13240 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_13240_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 4, 0): [(0, []), (4, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 4, 0): [(0, []), (4, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 4, 0): [(0, []), (4, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 4, 0): [(0, []), (4, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 3, 2, 4, 0): [(0, []), (4, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 3, 2, 4, 0): [(0, []), (4, []), (2, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(40 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_13402);
		// (1, 3, 4, 0, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 13402 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_13402_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 3, 4, 0, 2): [(2, []), (0, []), (4, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 3, 4, 0, 2): [(2, []), (0, []), (4, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 3, 4, 0, 2): [(2, []), (0, []), (4, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 3, 4, 0, 2): [(2, []), (0, []), (4, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 3, 4, 0, 2): [(2, []), (0, []), (4, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 3, 4, 0, 2): [(2, []), (0, []), (4, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(41 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_13420);
		// (1, 3, 4, 2, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 13420 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_13420_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 3, 4, 2, 0): [(0, []), (2, []), (4, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 3, 4, 2, 0): [(0, []), (2, []), (4, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 3, 4, 2, 0): [(0, []), (2, []), (4, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 3, 4, 2, 0): [(0, []), (2, []), (4, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 3, 4, 2, 0): [(0, []), (2, []), (4, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 3, 4, 2, 0): [(0, []), (2, []), (4, []), (3, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(42 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_14023);
		// (1, 4, 0, 2, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 14023 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_14023_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 4, 0, 2, 3): [(3, []), (2, []), (0, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 4, 0, 2, 3): [(3, []), (2, []), (0, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 4, 0, 2, 3): [(3, []), (2, []), (0, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 4, 0, 2, 3): [(3, []), (2, []), (0, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 4, 0, 2, 3): [(3, []), (2, []), (0, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 4, 0, 2, 3): [(3, []), (2, []), (0, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(43 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_14032);
		// (1, 4, 0, 3, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 14032 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_14032_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 4, 0, 3, 2): [(2, []), (3, []), (0, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 4, 0, 3, 2): [(2, []), (3, []), (0, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 4, 0, 3, 2): [(2, []), (3, []), (0, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 4, 0, 3, 2): [(2, []), (3, []), (0, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 4, 0, 3, 2): [(2, []), (3, []), (0, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 4, 0, 3, 2): [(2, []), (3, []), (0, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(44 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_14203);
		// (1, 4, 2, 0, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 14203 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_14203_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 4, 2, 0, 3): [(3, []), (0, []), (2, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 4, 2, 0, 3): [(3, []), (0, []), (2, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 4, 2, 0, 3): [(3, []), (0, []), (2, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 4, 2, 0, 3): [(3, []), (0, []), (2, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 4, 2, 0, 3): [(3, []), (0, []), (2, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 4, 2, 0, 3): [(3, []), (0, []), (2, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(45 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_14230);
		// (1, 4, 2, 3, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 14230 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_14230_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 4, 2, 3, 0): [(0, []), (3, []), (2, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 4, 2, 3, 0): [(0, []), (3, []), (2, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 4, 2, 3, 0): [(0, []), (3, []), (2, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 4, 2, 3, 0): [(0, []), (3, []), (2, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 4, 2, 3, 0): [(0, []), (3, []), (2, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 4, 2, 3, 0): [(0, []), (3, []), (2, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(46 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_14302);
		// (1, 4, 3, 0, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 14302 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_14302_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 4, 3, 0, 2): [(2, []), (0, []), (3, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 4, 3, 0, 2): [(2, []), (0, []), (3, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 4, 3, 0, 2): [(2, []), (0, []), (3, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 4, 3, 0, 2): [(2, []), (0, []), (3, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 4, 3, 0, 2): [(2, []), (0, []), (3, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 4, 3, 0, 2): [(2, []), (0, []), (3, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(47 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_14320);
		// (1, 4, 3, 2, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 14320 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_14320_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (1, 4, 3, 2, 0): [(0, []), (2, []), (3, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (1, 4, 3, 2, 0): [(0, []), (2, []), (3, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (1, 4, 3, 2, 0): [(0, []), (2, []), (3, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (1, 4, 3, 2, 0): [(0, []), (2, []), (3, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (1, 4, 3, 2, 0): [(0, []), (2, []), (3, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (1, 4, 3, 2, 0): [(0, []), (2, []), (3, []), (4, []), (1, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(48 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_20134);
		// (2, 0, 1, 3, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 20134 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_20134_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 3, 4): [(4, []), (3, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 3, 4): [(4, []), (3, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 3, 4): [(4, []), (3, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 3, 4): [(4, []), (3, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 3, 4): [(4, []), (3, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 0, 1, 3, 4): [(4, []), (3, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(49 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_20143);
		// (2, 0, 1, 4, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 20143 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_20143_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 4, 3): [(3, []), (4, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 4, 3): [(3, []), (4, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 4, 3): [(3, []), (4, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 4, 3): [(3, []), (4, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 0, 1, 4, 3): [(3, []), (4, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 0, 1, 4, 3): [(3, []), (4, []), (1, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(50 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_20314);
		// (2, 0, 3, 1, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 20314 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_20314_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 1, 4): [(4, []), (1, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 1, 4): [(4, []), (1, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 1, 4): [(4, []), (1, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 1, 4): [(4, []), (1, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 1, 4): [(4, []), (1, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 0, 3, 1, 4): [(4, []), (1, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(51 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_20341);
		// (2, 0, 3, 4, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 20341 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_20341_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 4, 1): [(1, []), (4, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 4, 1): [(1, []), (4, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 4, 1): [(1, []), (4, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 4, 1): [(1, []), (4, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 0, 3, 4, 1): [(1, []), (4, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 0, 3, 4, 1): [(1, []), (4, []), (3, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(52 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_20413);
		// (2, 0, 4, 1, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 20413 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_20413_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 0, 4, 1, 3): [(3, []), (1, []), (4, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 0, 4, 1, 3): [(3, []), (1, []), (4, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 0, 4, 1, 3): [(3, []), (1, []), (4, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 0, 4, 1, 3): [(3, []), (1, []), (4, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 0, 4, 1, 3): [(3, []), (1, []), (4, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 0, 4, 1, 3): [(3, []), (1, []), (4, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(53 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_20431);
		// (2, 0, 4, 3, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 20431 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_20431_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 0, 4, 3, 1): [(1, []), (3, []), (4, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 0, 4, 3, 1): [(1, []), (3, []), (4, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 0, 4, 3, 1): [(1, []), (3, []), (4, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 0, 4, 3, 1): [(1, []), (3, []), (4, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 0, 4, 3, 1): [(1, []), (3, []), (4, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 0, 4, 3, 1): [(1, []), (3, []), (4, []), (0, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(54 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_21034);
		// (2, 1, 0, 3, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 21034 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_21034_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 3, 4): [(4, []), (3, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 3, 4): [(4, []), (3, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 3, 4): [(4, []), (3, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 3, 4): [(4, []), (3, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 3, 4): [(4, []), (3, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 1, 0, 3, 4): [(4, []), (3, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(55 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_21043);
		// (2, 1, 0, 4, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 21043 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_21043_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 4, 3): [(3, []), (4, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 4, 3): [(3, []), (4, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 4, 3): [(3, []), (4, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 4, 3): [(3, []), (4, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 1, 0, 4, 3): [(3, []), (4, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 1, 0, 4, 3): [(3, []), (4, []), (0, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(56 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_21304);
		// (2, 1, 3, 0, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 21304 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_21304_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 0, 4): [(4, []), (0, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 0, 4): [(4, []), (0, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 0, 4): [(4, []), (0, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 0, 4): [(4, []), (0, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 0, 4): [(4, []), (0, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 1, 3, 0, 4): [(4, []), (0, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(57 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_21340);
		// (2, 1, 3, 4, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 21340 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_21340_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 4, 0): [(0, []), (4, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 4, 0): [(0, []), (4, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 4, 0): [(0, []), (4, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 4, 0): [(0, []), (4, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 1, 3, 4, 0): [(0, []), (4, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 1, 3, 4, 0): [(0, []), (4, []), (3, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(58 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_21403);
		// (2, 1, 4, 0, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 21403 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_21403_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 1, 4, 0, 3): [(3, []), (0, []), (4, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 1, 4, 0, 3): [(3, []), (0, []), (4, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 1, 4, 0, 3): [(3, []), (0, []), (4, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 1, 4, 0, 3): [(3, []), (0, []), (4, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 1, 4, 0, 3): [(3, []), (0, []), (4, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 1, 4, 0, 3): [(3, []), (0, []), (4, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(59 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_21430);
		// (2, 1, 4, 3, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 21430 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_21430_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 1, 4, 3, 0): [(0, []), (3, []), (4, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 1, 4, 3, 0): [(0, []), (3, []), (4, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 1, 4, 3, 0): [(0, []), (3, []), (4, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 1, 4, 3, 0): [(0, []), (3, []), (4, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 1, 4, 3, 0): [(0, []), (3, []), (4, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 1, 4, 3, 0): [(0, []), (3, []), (4, []), (1, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(60 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_23014);
		// (2, 3, 0, 1, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 23014 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_23014_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 1, 4): [(4, []), (1, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 1, 4): [(4, []), (1, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 1, 4): [(4, []), (1, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 1, 4): [(4, []), (1, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 1, 4): [(4, []), (1, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 3, 0, 1, 4): [(4, []), (1, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(61 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_23041);
		// (2, 3, 0, 4, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 23041 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_23041_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 4, 1): [(1, []), (4, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 4, 1): [(1, []), (4, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 4, 1): [(1, []), (4, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 4, 1): [(1, []), (4, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 3, 0, 4, 1): [(1, []), (4, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 3, 0, 4, 1): [(1, []), (4, []), (0, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(62 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_23104);
		// (2, 3, 1, 0, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 23104 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_23104_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 0, 4): [(4, []), (0, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 0, 4): [(4, []), (0, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 0, 4): [(4, []), (0, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 0, 4): [(4, []), (0, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 0, 4): [(4, []), (0, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 3, 1, 0, 4): [(4, []), (0, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(63 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_23140);
		// (2, 3, 1, 4, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 23140 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_23140_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 4, 0): [(0, []), (4, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 4, 0): [(0, []), (4, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 4, 0): [(0, []), (4, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 4, 0): [(0, []), (4, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 3, 1, 4, 0): [(0, []), (4, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 3, 1, 4, 0): [(0, []), (4, []), (1, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(64 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_23401);
		// (2, 3, 4, 0, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 23401 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_23401_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 3, 4, 0, 1): [(1, []), (0, []), (4, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 3, 4, 0, 1): [(1, []), (0, []), (4, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 3, 4, 0, 1): [(1, []), (0, []), (4, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 3, 4, 0, 1): [(1, []), (0, []), (4, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 3, 4, 0, 1): [(1, []), (0, []), (4, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 3, 4, 0, 1): [(1, []), (0, []), (4, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(65 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_23410);
		// (2, 3, 4, 1, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 23410 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_23410_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 3, 4, 1, 0): [(0, []), (1, []), (4, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 3, 4, 1, 0): [(0, []), (1, []), (4, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 3, 4, 1, 0): [(0, []), (1, []), (4, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 3, 4, 1, 0): [(0, []), (1, []), (4, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 3, 4, 1, 0): [(0, []), (1, []), (4, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 3, 4, 1, 0): [(0, []), (1, []), (4, []), (3, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(66 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_24013);
		// (2, 4, 0, 1, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 24013 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_24013_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 4, 0, 1, 3): [(3, []), (1, []), (0, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 4, 0, 1, 3): [(3, []), (1, []), (0, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 4, 0, 1, 3): [(3, []), (1, []), (0, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 4, 0, 1, 3): [(3, []), (1, []), (0, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 4, 0, 1, 3): [(3, []), (1, []), (0, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 4, 0, 1, 3): [(3, []), (1, []), (0, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(67 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_24031);
		// (2, 4, 0, 3, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 24031 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_24031_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 4, 0, 3, 1): [(1, []), (3, []), (0, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 4, 0, 3, 1): [(1, []), (3, []), (0, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 4, 0, 3, 1): [(1, []), (3, []), (0, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 4, 0, 3, 1): [(1, []), (3, []), (0, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 4, 0, 3, 1): [(1, []), (3, []), (0, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 4, 0, 3, 1): [(1, []), (3, []), (0, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(68 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_24103);
		// (2, 4, 1, 0, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 24103 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_24103_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 4, 1, 0, 3): [(3, []), (0, []), (1, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 4, 1, 0, 3): [(3, []), (0, []), (1, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 4, 1, 0, 3): [(3, []), (0, []), (1, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 4, 1, 0, 3): [(3, []), (0, []), (1, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 4, 1, 0, 3): [(3, []), (0, []), (1, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 4, 1, 0, 3): [(3, []), (0, []), (1, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(69 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_24130);
		// (2, 4, 1, 3, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 24130 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_24130_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 4, 1, 3, 0): [(0, []), (3, []), (1, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 4, 1, 3, 0): [(0, []), (3, []), (1, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 4, 1, 3, 0): [(0, []), (3, []), (1, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 4, 1, 3, 0): [(0, []), (3, []), (1, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 4, 1, 3, 0): [(0, []), (3, []), (1, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 4, 1, 3, 0): [(0, []), (3, []), (1, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(70 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_24301);
		// (2, 4, 3, 0, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 24301 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_24301_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 4, 3, 0, 1): [(1, []), (0, []), (3, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 4, 3, 0, 1): [(1, []), (0, []), (3, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 4, 3, 0, 1): [(1, []), (0, []), (3, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 4, 3, 0, 1): [(1, []), (0, []), (3, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 4, 3, 0, 1): [(1, []), (0, []), (3, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 4, 3, 0, 1): [(1, []), (0, []), (3, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(71 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_24310);
		// (2, 4, 3, 1, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 24310 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_24310_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (2, 4, 3, 1, 0): [(0, []), (1, []), (3, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (2, 4, 3, 1, 0): [(0, []), (1, []), (3, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (2, 4, 3, 1, 0): [(0, []), (1, []), (3, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (2, 4, 3, 1, 0): [(0, []), (1, []), (3, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (2, 4, 3, 1, 0): [(0, []), (1, []), (3, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (2, 4, 3, 1, 0): [(0, []), (1, []), (3, []), (4, []), (2, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(72 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_30124);
		// (3, 0, 1, 2, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 30124 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_30124_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 2, 4): [(4, []), (2, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 2, 4): [(4, []), (2, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 2, 4): [(4, []), (2, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 2, 4): [(4, []), (2, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 2, 4): [(4, []), (2, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 0, 1, 2, 4): [(4, []), (2, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(73 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_30142);
		// (3, 0, 1, 4, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 30142 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_30142_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 4, 2): [(2, []), (4, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 4, 2): [(2, []), (4, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 4, 2): [(2, []), (4, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 4, 2): [(2, []), (4, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 0, 1, 4, 2): [(2, []), (4, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 0, 1, 4, 2): [(2, []), (4, []), (1, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(74 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_30214);
		// (3, 0, 2, 1, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 30214 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_30214_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 1, 4): [(4, []), (1, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 1, 4): [(4, []), (1, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 1, 4): [(4, []), (1, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 1, 4): [(4, []), (1, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 1, 4): [(4, []), (1, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 0, 2, 1, 4): [(4, []), (1, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(75 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_30241);
		// (3, 0, 2, 4, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 30241 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_30241_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 4, 1): [(1, []), (4, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 4, 1): [(1, []), (4, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 4, 1): [(1, []), (4, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 4, 1): [(1, []), (4, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 0, 2, 4, 1): [(1, []), (4, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 0, 2, 4, 1): [(1, []), (4, []), (2, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(76 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_30412);
		// (3, 0, 4, 1, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 30412 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_30412_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 0, 4, 1, 2): [(2, []), (1, []), (4, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 0, 4, 1, 2): [(2, []), (1, []), (4, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 0, 4, 1, 2): [(2, []), (1, []), (4, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 0, 4, 1, 2): [(2, []), (1, []), (4, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 0, 4, 1, 2): [(2, []), (1, []), (4, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 0, 4, 1, 2): [(2, []), (1, []), (4, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(77 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_30421);
		// (3, 0, 4, 2, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 30421 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_30421_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 0, 4, 2, 1): [(1, []), (2, []), (4, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 0, 4, 2, 1): [(1, []), (2, []), (4, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 0, 4, 2, 1): [(1, []), (2, []), (4, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 0, 4, 2, 1): [(1, []), (2, []), (4, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 0, 4, 2, 1): [(1, []), (2, []), (4, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 0, 4, 2, 1): [(1, []), (2, []), (4, []), (0, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(78 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_31024);
		// (3, 1, 0, 2, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 31024 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_31024_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 2, 4): [(4, []), (2, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 2, 4): [(4, []), (2, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 2, 4): [(4, []), (2, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 2, 4): [(4, []), (2, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 2, 4): [(4, []), (2, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 1, 0, 2, 4): [(4, []), (2, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(79 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_31042);
		// (3, 1, 0, 4, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 31042 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_31042_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 4, 2): [(2, []), (4, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 4, 2): [(2, []), (4, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 4, 2): [(2, []), (4, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 4, 2): [(2, []), (4, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 1, 0, 4, 2): [(2, []), (4, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 1, 0, 4, 2): [(2, []), (4, []), (0, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(80 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_31204);
		// (3, 1, 2, 0, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 31204 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_31204_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 0, 4): [(4, []), (0, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 0, 4): [(4, []), (0, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 0, 4): [(4, []), (0, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 0, 4): [(4, []), (0, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 0, 4): [(4, []), (0, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 1, 2, 0, 4): [(4, []), (0, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(81 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_31240);
		// (3, 1, 2, 4, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 31240 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_31240_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 4, 0): [(0, []), (4, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 4, 0): [(0, []), (4, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 4, 0): [(0, []), (4, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 4, 0): [(0, []), (4, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 1, 2, 4, 0): [(0, []), (4, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 1, 2, 4, 0): [(0, []), (4, []), (2, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(82 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_31402);
		// (3, 1, 4, 0, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 31402 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_31402_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 1, 4, 0, 2): [(2, []), (0, []), (4, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 1, 4, 0, 2): [(2, []), (0, []), (4, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 1, 4, 0, 2): [(2, []), (0, []), (4, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 1, 4, 0, 2): [(2, []), (0, []), (4, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 1, 4, 0, 2): [(2, []), (0, []), (4, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 1, 4, 0, 2): [(2, []), (0, []), (4, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(83 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_31420);
		// (3, 1, 4, 2, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 31420 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_31420_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 1, 4, 2, 0): [(0, []), (2, []), (4, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 1, 4, 2, 0): [(0, []), (2, []), (4, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 1, 4, 2, 0): [(0, []), (2, []), (4, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 1, 4, 2, 0): [(0, []), (2, []), (4, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 1, 4, 2, 0): [(0, []), (2, []), (4, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 1, 4, 2, 0): [(0, []), (2, []), (4, []), (1, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(84 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_32014);
		// (3, 2, 0, 1, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 32014 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_32014_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 1, 4): [(4, []), (1, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 1, 4): [(4, []), (1, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 1, 4): [(4, []), (1, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 1, 4): [(4, []), (1, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 1, 4): [(4, []), (1, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 2, 0, 1, 4): [(4, []), (1, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(85 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_32041);
		// (3, 2, 0, 4, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 32041 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_32041_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 4, 1): [(1, []), (4, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 4, 1): [(1, []), (4, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 4, 1): [(1, []), (4, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 4, 1): [(1, []), (4, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 2, 0, 4, 1): [(1, []), (4, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 2, 0, 4, 1): [(1, []), (4, []), (0, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(86 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_32104);
		// (3, 2, 1, 0, 4)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 32104 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_32104_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 0, 4): [(4, []), (0, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 0, 4): [(4, []), (0, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 0, 4): [(4, []), (0, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 0, 4): [(4, []), (0, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 0, 4): [(4, []), (0, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 2, 1, 0, 4): [(4, []), (0, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(87 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_32140);
		// (3, 2, 1, 4, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 32140 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_32140_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 4, 0): [(0, []), (4, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 4, 0): [(0, []), (4, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 4, 0): [(0, []), (4, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 4, 0): [(0, []), (4, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 2, 1, 4, 0): [(0, []), (4, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 2, 1, 4, 0): [(0, []), (4, []), (1, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(88 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_32401);
		// (3, 2, 4, 0, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 32401 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_32401_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 2, 4, 0, 1): [(1, []), (0, []), (4, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 2, 4, 0, 1): [(1, []), (0, []), (4, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 2, 4, 0, 1): [(1, []), (0, []), (4, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 2, 4, 0, 1): [(1, []), (0, []), (4, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 2, 4, 0, 1): [(1, []), (0, []), (4, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 2, 4, 0, 1): [(1, []), (0, []), (4, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(89 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_32410);
		// (3, 2, 4, 1, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 32410 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_32410_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 2, 4, 1, 0): [(0, []), (1, []), (4, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 2, 4, 1, 0): [(0, []), (1, []), (4, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 2, 4, 1, 0): [(0, []), (1, []), (4, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 2, 4, 1, 0): [(0, []), (1, []), (4, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 2, 4, 1, 0): [(0, []), (1, []), (4, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 2, 4, 1, 0): [(0, []), (1, []), (4, []), (2, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(90 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_34012);
		// (3, 4, 0, 1, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 34012 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_34012_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 4, 0, 1, 2): [(2, []), (1, []), (0, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 4, 0, 1, 2): [(2, []), (1, []), (0, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 4, 0, 1, 2): [(2, []), (1, []), (0, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 4, 0, 1, 2): [(2, []), (1, []), (0, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 4, 0, 1, 2): [(2, []), (1, []), (0, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 4, 0, 1, 2): [(2, []), (1, []), (0, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(91 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_34021);
		// (3, 4, 0, 2, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 34021 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_34021_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 4, 0, 2, 1): [(1, []), (2, []), (0, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 4, 0, 2, 1): [(1, []), (2, []), (0, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 4, 0, 2, 1): [(1, []), (2, []), (0, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 4, 0, 2, 1): [(1, []), (2, []), (0, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 4, 0, 2, 1): [(1, []), (2, []), (0, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 4, 0, 2, 1): [(1, []), (2, []), (0, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(92 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_34102);
		// (3, 4, 1, 0, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 34102 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_34102_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 4, 1, 0, 2): [(2, []), (0, []), (1, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 4, 1, 0, 2): [(2, []), (0, []), (1, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 4, 1, 0, 2): [(2, []), (0, []), (1, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 4, 1, 0, 2): [(2, []), (0, []), (1, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 4, 1, 0, 2): [(2, []), (0, []), (1, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 4, 1, 0, 2): [(2, []), (0, []), (1, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(93 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_34120);
		// (3, 4, 1, 2, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 34120 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_34120_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 4, 1, 2, 0): [(0, []), (2, []), (1, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 4, 1, 2, 0): [(0, []), (2, []), (1, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 4, 1, 2, 0): [(0, []), (2, []), (1, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 4, 1, 2, 0): [(0, []), (2, []), (1, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 4, 1, 2, 0): [(0, []), (2, []), (1, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 4, 1, 2, 0): [(0, []), (2, []), (1, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(94 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_34201);
		// (3, 4, 2, 0, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 34201 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_34201_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 4, 2, 0, 1): [(1, []), (0, []), (2, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 4, 2, 0, 1): [(1, []), (0, []), (2, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 4, 2, 0, 1): [(1, []), (0, []), (2, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 4, 2, 0, 1): [(1, []), (0, []), (2, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 4, 2, 0, 1): [(1, []), (0, []), (2, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 4, 2, 0, 1): [(1, []), (0, []), (2, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(95 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_34210);
		// (3, 4, 2, 1, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 34210 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_34210_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (3, 4, 2, 1, 0): [(0, []), (1, []), (2, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (3, 4, 2, 1, 0): [(0, []), (1, []), (2, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (3, 4, 2, 1, 0): [(0, []), (1, []), (2, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (3, 4, 2, 1, 0): [(0, []), (1, []), (2, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (3, 4, 2, 1, 0): [(0, []), (1, []), (2, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (3, 4, 2, 1, 0): [(0, []), (1, []), (2, []), (4, []), (3, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(96 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_40123);
		// (4, 0, 1, 2, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 40123 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_40123_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 0, 1, 2, 3): [(3, []), (2, []), (1, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 0, 1, 2, 3): [(3, []), (2, []), (1, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 0, 1, 2, 3): [(3, []), (2, []), (1, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 0, 1, 2, 3): [(3, []), (2, []), (1, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 0, 1, 2, 3): [(3, []), (2, []), (1, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 0, 1, 2, 3): [(3, []), (2, []), (1, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(97 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_40132);
		// (4, 0, 1, 3, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 40132 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_40132_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 0, 1, 3, 2): [(2, []), (3, []), (1, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 0, 1, 3, 2): [(2, []), (3, []), (1, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 0, 1, 3, 2): [(2, []), (3, []), (1, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 0, 1, 3, 2): [(2, []), (3, []), (1, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 0, 1, 3, 2): [(2, []), (3, []), (1, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 0, 1, 3, 2): [(2, []), (3, []), (1, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(98 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_40213);
		// (4, 0, 2, 1, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 40213 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_40213_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 0, 2, 1, 3): [(3, []), (1, []), (2, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 0, 2, 1, 3): [(3, []), (1, []), (2, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 0, 2, 1, 3): [(3, []), (1, []), (2, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 0, 2, 1, 3): [(3, []), (1, []), (2, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 0, 2, 1, 3): [(3, []), (1, []), (2, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 0, 2, 1, 3): [(3, []), (1, []), (2, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(99 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_40231);
		// (4, 0, 2, 3, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 40231 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_40231_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 0, 2, 3, 1): [(1, []), (3, []), (2, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 0, 2, 3, 1): [(1, []), (3, []), (2, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 0, 2, 3, 1): [(1, []), (3, []), (2, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 0, 2, 3, 1): [(1, []), (3, []), (2, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 0, 2, 3, 1): [(1, []), (3, []), (2, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 0, 2, 3, 1): [(1, []), (3, []), (2, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(100 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_40312);
		// (4, 0, 3, 1, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 40312 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_40312_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 0, 3, 1, 2): [(2, []), (1, []), (3, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 0, 3, 1, 2): [(2, []), (1, []), (3, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 0, 3, 1, 2): [(2, []), (1, []), (3, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 0, 3, 1, 2): [(2, []), (1, []), (3, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 0, 3, 1, 2): [(2, []), (1, []), (3, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 0, 3, 1, 2): [(2, []), (1, []), (3, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(101 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_40321);
		// (4, 0, 3, 2, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 40321 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_40321_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 0, 3, 2, 1): [(1, []), (2, []), (3, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 0, 3, 2, 1): [(1, []), (2, []), (3, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 0, 3, 2, 1): [(1, []), (2, []), (3, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 0, 3, 2, 1): [(1, []), (2, []), (3, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 0, 3, 2, 1): [(1, []), (2, []), (3, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 0, 3, 2, 1): [(1, []), (2, []), (3, []), (0, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(102 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_41023);
		// (4, 1, 0, 2, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 41023 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_41023_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 1, 0, 2, 3): [(3, []), (2, []), (0, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 1, 0, 2, 3): [(3, []), (2, []), (0, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 1, 0, 2, 3): [(3, []), (2, []), (0, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 1, 0, 2, 3): [(3, []), (2, []), (0, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 1, 0, 2, 3): [(3, []), (2, []), (0, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 1, 0, 2, 3): [(3, []), (2, []), (0, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(103 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_41032);
		// (4, 1, 0, 3, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 41032 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_41032_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 1, 0, 3, 2): [(2, []), (3, []), (0, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 1, 0, 3, 2): [(2, []), (3, []), (0, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 1, 0, 3, 2): [(2, []), (3, []), (0, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 1, 0, 3, 2): [(2, []), (3, []), (0, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 1, 0, 3, 2): [(2, []), (3, []), (0, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 1, 0, 3, 2): [(2, []), (3, []), (0, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(104 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_41203);
		// (4, 1, 2, 0, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 41203 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_41203_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 1, 2, 0, 3): [(3, []), (0, []), (2, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 1, 2, 0, 3): [(3, []), (0, []), (2, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 1, 2, 0, 3): [(3, []), (0, []), (2, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 1, 2, 0, 3): [(3, []), (0, []), (2, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 1, 2, 0, 3): [(3, []), (0, []), (2, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 1, 2, 0, 3): [(3, []), (0, []), (2, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(105 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_41230);
		// (4, 1, 2, 3, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 41230 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_41230_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 1, 2, 3, 0): [(0, []), (3, []), (2, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 1, 2, 3, 0): [(0, []), (3, []), (2, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 1, 2, 3, 0): [(0, []), (3, []), (2, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 1, 2, 3, 0): [(0, []), (3, []), (2, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 1, 2, 3, 0): [(0, []), (3, []), (2, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 1, 2, 3, 0): [(0, []), (3, []), (2, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(106 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_41302);
		// (4, 1, 3, 0, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 41302 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_41302_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 1, 3, 0, 2): [(2, []), (0, []), (3, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 1, 3, 0, 2): [(2, []), (0, []), (3, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 1, 3, 0, 2): [(2, []), (0, []), (3, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 1, 3, 0, 2): [(2, []), (0, []), (3, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 1, 3, 0, 2): [(2, []), (0, []), (3, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 1, 3, 0, 2): [(2, []), (0, []), (3, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(107 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_41320);
		// (4, 1, 3, 2, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 41320 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_41320_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 1, 3, 2, 0): [(0, []), (2, []), (3, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 1, 3, 2, 0): [(0, []), (2, []), (3, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 1, 3, 2, 0): [(0, []), (2, []), (3, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 1, 3, 2, 0): [(0, []), (2, []), (3, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 1, 3, 2, 0): [(0, []), (2, []), (3, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 1, 3, 2, 0): [(0, []), (2, []), (3, []), (1, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(108 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_42013);
		// (4, 2, 0, 1, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 42013 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_42013_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 2, 0, 1, 3): [(3, []), (1, []), (0, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 2, 0, 1, 3): [(3, []), (1, []), (0, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 2, 0, 1, 3): [(3, []), (1, []), (0, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 2, 0, 1, 3): [(3, []), (1, []), (0, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 2, 0, 1, 3): [(3, []), (1, []), (0, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 2, 0, 1, 3): [(3, []), (1, []), (0, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(109 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_42031);
		// (4, 2, 0, 3, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 42031 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_42031_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 2, 0, 3, 1): [(1, []), (3, []), (0, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 2, 0, 3, 1): [(1, []), (3, []), (0, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 2, 0, 3, 1): [(1, []), (3, []), (0, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 2, 0, 3, 1): [(1, []), (3, []), (0, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 2, 0, 3, 1): [(1, []), (3, []), (0, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 2, 0, 3, 1): [(1, []), (3, []), (0, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(110 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_42103);
		// (4, 2, 1, 0, 3)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 42103 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_42103_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 2, 1, 0, 3): [(3, []), (0, []), (1, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 2, 1, 0, 3): [(3, []), (0, []), (1, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 2, 1, 0, 3): [(3, []), (0, []), (1, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 2, 1, 0, 3): [(3, []), (0, []), (1, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 2, 1, 0, 3): [(3, []), (0, []), (1, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 2, 1, 0, 3): [(3, []), (0, []), (1, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(111 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_42130);
		// (4, 2, 1, 3, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 42130 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_42130_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 2, 1, 3, 0): [(0, []), (3, []), (1, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 2, 1, 3, 0): [(0, []), (3, []), (1, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 2, 1, 3, 0): [(0, []), (3, []), (1, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 2, 1, 3, 0): [(0, []), (3, []), (1, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 2, 1, 3, 0): [(0, []), (3, []), (1, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 2, 1, 3, 0): [(0, []), (3, []), (1, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(112 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_42301);
		// (4, 2, 3, 0, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 42301 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_42301_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 2, 3, 0, 1): [(1, []), (0, []), (3, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 2, 3, 0, 1): [(1, []), (0, []), (3, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 2, 3, 0, 1): [(1, []), (0, []), (3, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 2, 3, 0, 1): [(1, []), (0, []), (3, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 2, 3, 0, 1): [(1, []), (0, []), (3, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 2, 3, 0, 1): [(1, []), (0, []), (3, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(113 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_42310);
		// (4, 2, 3, 1, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 42310 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_42310_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 2, 3, 1, 0): [(0, []), (1, []), (3, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 2, 3, 1, 0): [(0, []), (1, []), (3, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 2, 3, 1, 0): [(0, []), (1, []), (3, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 2, 3, 1, 0): [(0, []), (1, []), (3, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 2, 3, 1, 0): [(0, []), (1, []), (3, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 2, 3, 1, 0): [(0, []), (1, []), (3, []), (2, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(114 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_43012);
		// (4, 3, 0, 1, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 43012 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_43012_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 3, 0, 1, 2): [(2, []), (1, []), (0, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 3, 0, 1, 2): [(2, []), (1, []), (0, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 3, 0, 1, 2): [(2, []), (1, []), (0, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 3, 0, 1, 2): [(2, []), (1, []), (0, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 3, 0, 1, 2): [(2, []), (1, []), (0, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 3, 0, 1, 2): [(2, []), (1, []), (0, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(115 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_43021);
		// (4, 3, 0, 2, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 43021 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_43021_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 3, 0, 2, 1): [(1, []), (2, []), (0, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 3, 0, 2, 1): [(1, []), (2, []), (0, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 3, 0, 2, 1): [(1, []), (2, []), (0, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 3, 0, 2, 1): [(1, []), (2, []), (0, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 3, 0, 2, 1): [(1, []), (2, []), (0, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 3, 0, 2, 1): [(1, []), (2, []), (0, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(116 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_43102);
		// (4, 3, 1, 0, 2)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 43102 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_43102_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 3, 1, 0, 2): [(2, []), (0, []), (1, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 3, 1, 0, 2): [(2, []), (0, []), (1, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 3, 1, 0, 2): [(2, []), (0, []), (1, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 3, 1, 0, 2): [(2, []), (0, []), (1, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 3, 1, 0, 2): [(2, []), (0, []), (1, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 3, 1, 0, 2): [(2, []), (0, []), (1, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(117 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_43120);
		// (4, 3, 1, 2, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 43120 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_43120_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 3, 1, 2, 0): [(0, []), (2, []), (1, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 3, 1, 2, 0): [(0, []), (2, []), (1, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 3, 1, 2, 0): [(0, []), (2, []), (1, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 3, 1, 2, 0): [(0, []), (2, []), (1, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 3, 1, 2, 0): [(0, []), (2, []), (1, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 3, 1, 2, 0): [(0, []), (2, []), (1, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(118 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_43201);
		// (4, 3, 2, 0, 1)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 43201 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_43201_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 3, 2, 0, 1): [(1, []), (0, []), (2, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 3, 2, 0, 1): [(1, []), (0, []), (2, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 3, 2, 0, 1): [(1, []), (0, []), (2, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 3, 2, 0, 1): [(1, []), (0, []), (2, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 3, 2, 0, 1): [(1, []), (0, []), (2, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 3, 2, 0, 1): [(1, []), (0, []), (2, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
		if(119 == SPLIT){
		// Sort the copy to the desired permutation.
			qsort(A_copy, size, sizeof(struct coo_t), cmp_43210);
		// (4, 3, 2, 1, 0)
		for(int i = 0; i < 100; i ++){
			cout << filename << " | 43210 | 5 | 5" ;
			qsort(A, size, sizeof(struct coo_t), cmp_01234);
			transpose_coo_43210_all(A, size, order, dimensions);
			cout << endl;
			// Check that it was permuted correctly.
			for(int i = 0; i < size; i ++) {
				if(A[i].idx0 != A_copy[i].idx0){
					cout << "Error permuting array: index incorrect: (4, 3, 2, 1, 0): [(0, []), (1, []), (2, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx1 != A_copy[i].idx1){
					cout << "Error permuting array: index incorrect: (4, 3, 2, 1, 0): [(0, []), (1, []), (2, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx2 != A_copy[i].idx2){
					cout << "Error permuting array: index incorrect: (4, 3, 2, 1, 0): [(0, []), (1, []), (2, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx3 != A_copy[i].idx3){
					cout << "Error permuting array: index incorrect: (4, 3, 2, 1, 0): [(0, []), (1, []), (2, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].idx4 != A_copy[i].idx4){
					cout << "Error permuting array: index incorrect: (4, 3, 2, 1, 0): [(0, []), (1, []), (2, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
				if(A[i].val != A_copy[i].val){
					cout << "Error permuting array: value incorrect: (4, 3, 2, 1, 0): [(0, []), (1, []), (2, []), (3, []), (4, [])]" << endl;
					exit(3);
				}
			}
		}

		}
	free(A);
	free(A_copy);
	free(dimensions);
}
