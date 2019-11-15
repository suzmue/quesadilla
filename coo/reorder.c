#include <cstdio>
#include <cstdlib>


struct coo_t
{
	int32_t	idx0;
	int32_t	idx1;
	int32_t	idx2;
	double	val;
};


// transpose permutes the modes of the coordinates to be [0, 2, 1]
int transpose_coo_021(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [0, 2, 1]
	// Fix and sort on [0]
	// Create buckets and quotient
	int *bucket_0 = (int *)malloc(c_size*sizeof(int));
	int *quotient_0 = (int *)malloc(c_size*sizeof(int));
	int current_0 = 0;
	bucket_0[0] = 0;
	quotient_0[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx0 != C_coords[i - 1].idx0) {
			current_0++;
			quotient_0[current_0] = i;
		}
		bucket_0[i] = current_0;
	}

	// Histogram sort on mode 2 into the permutation array
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
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		int idx = B2_count[idx2] - 1;
		C_coords_scratch[idx] = C_coords[i];
		perm[idx] = bucket_0[i];
		B2_count[idx2]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_0[bucket_0[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_0[perm[i]] ++;
	}
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B2_count);
	free(bucket_0);
	free(quotient_0);
	return 0;
}
