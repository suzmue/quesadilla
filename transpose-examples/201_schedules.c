#include <cstdio>
#include <cstdlib>

/*
    perm = [2,0,1]
    datatypes = ["int32_t", "int32_t", "int32_t", "double"]
    dims = [25,25,10]
    generate_header(3,datatypes)
    # 3 schedules

    # Schedule 012
    schedule = [(0,[]), (1,[0]), (2,[])]
    generate_function("012_3",perm, 3, datatypes, dims, schedule)

    # Schedule 021
    schedule = [(0,[]), (2,[]), (1,[0,2])]
    generate_function("021_3", perm, 3, datatypes, dims, schedule)

    # Schedule 102
    schedule = [(1,[]), (0,[]), (2,[])]
    generate_function("102_3", perm, 3, datatypes, dims, schedule)

    # Schedule 120
    schedule = [(1,[]),  (2,[]), (0, [2])]
    generate_function("120_3", perm, 3, datatypes, dims, schedule)

    # Schedule 201
    schedule = [ (2,[]), (0, [2]), (1, [0,2])]
    generate_function("201_3", perm, 3, datatypes, dims, schedule)

    # Schedule 210
    schedule = [(2,[]), (1, [2]), (0, [2])]
    generate_function("210_3", perm, 3, datatypes, dims, schedule)

    # 2 Schedule

    # 01
    # schedule = [(0,[]), (1, []),]
    # generate_function("01_2", perm, 3, datatypes, dims, schedule)
    # 02
    schedule = [(0,[]), (2, []),]
    generate_function("02_2", perm, 3, datatypes, dims, schedule)
    # 10
    # schedule = [(1,[]), (0, [1]),]
    # generate_function("10_2", perm, 3, datatypes, dims, schedule)
    # 12
    schedule = [(1,[0]), (2, []),]
    generate_function("12_2", perm, 3, datatypes, dims, schedule)
    # 20
    schedule = [(2,[]), (0, []),]
    generate_function("20_2", perm, 3, datatypes, dims, schedule)
    # 21
    schedule = [(2,[]), (1, [0,2]),]
    generate_function("21_2", perm, 3, datatypes, dims, schedule)

    # 1 schedule
    # schedule = [(0,[])]
    # generate_function("0_1", perm, 3, datatypes, dims, schedule)

    # schedule = [(1,[])]
    # generate_function("1_1", perm, 3, datatypes, dims, schedule)

    schedule = [(2,[])]
    generate_function("2_1", perm, 3, datatypes, dims, schedule)
    # 0 Schedule
    # schedule = []
    # generate_function("0", perm, 3, datatypes, dims, schedule)



*/
struct coo_t
{
	int32_t	idx0;
	int32_t	idx1;
	int32_t	idx2;
	double	val;
};


// transpose permutes the modes of the coordinates to be [2, 0, 1]
int transpose_coo_201_012_3(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [2, 0, 1]

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 <= B0_size; idx0 ++)
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

	// Fix and sort on [0]
	// Create buckets and quotient
	int *bucket_10 = (int *)malloc(c_size*sizeof(int));
	int *quotient_10 = (int *)malloc(c_size*sizeof(int));
	int current_10 = 0;
	bucket_10[0] = 0;
	quotient_10[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx0 != C_coords[i - 1].idx0) {
			current_10++;
			quotient_10[current_10] = i;
		}
		bucket_10[i] = current_10;
	}

	// Histogram sort on mode 1 into the permutation array
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
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		perm[idx] = bucket_10[i];
		B1_count[idx1]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_10[bucket_10[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_10[perm[i]] ++;
	}

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 <= B2_size; idx2 ++)
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

	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B0_count);
	free(B1_count);
	free(bucket_10);
	free(quotient_10);
	free(B2_count);
	return 0;
}
// transpose permutes the modes of the coordinates to be [2, 0, 1]
int transpose_coo_201_021_3(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [2, 0, 1]

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 <= B0_size; idx0 ++)
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


	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 <= B2_size; idx2 ++)
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

	// Fix and sort on [0, 2]
	// Create buckets and quotient
	int *bucket_102 = (int *)malloc(c_size*sizeof(int));
	int *quotient_102 = (int *)malloc(c_size*sizeof(int));
	int current_102 = 0;
	bucket_102[0] = 0;
	quotient_102[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx0 != C_coords[i - 1].idx0) {
			current_102++;
			quotient_102[current_102] = i;
		}
		if(C_coords[i].idx2 != C_coords[i - 1].idx2) {
			current_102++;
			quotient_102[current_102] = i;
		}
		bucket_102[i] = current_102;
	}

	// Histogram sort on mode 1 into the permutation array
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
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		perm[idx] = bucket_102[i];
		B1_count[idx1]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_102[bucket_102[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_102[perm[i]] ++;
	}
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B0_count);
	free(B2_count);
	free(B1_count);
	free(bucket_102);
	free(quotient_102);
	return 0;
}
// transpose permutes the modes of the coordinates to be [2, 0, 1]
int transpose_coo_201_102_3(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [2, 0, 1]

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 <= B1_size; idx1 ++)
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


	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 <= B0_size; idx0 ++)
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


	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 <= B2_size; idx2 ++)
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

	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B1_count);
	free(B0_count);
	free(B2_count);
	return 0;
}
// transpose permutes the modes of the coordinates to be [2, 0, 1]
int transpose_coo_201_120_3(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [2, 0, 1]

	// Histogram sort on mode 1
	int B1_size = dimensions[1];
	int32_t *B1_count = (int32_t *)calloc(B1_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		B1_count[idx1]++;
	}

	// Prefix sum over B1_count
	for(int idx1 = 1; idx1 <= B1_size; idx1 ++)
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


	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 <= B2_size; idx2 ++)
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

	// Fix and sort on [2]
	// Create buckets and quotient
	int *bucket_02 = (int *)malloc(c_size*sizeof(int));
	int *quotient_02 = (int *)malloc(c_size*sizeof(int));
	int current_02 = 0;
	bucket_02[0] = 0;
	quotient_02[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx2 != C_coords[i - 1].idx2) {
			current_02++;
			quotient_02[current_02] = i;
		}
		bucket_02[i] = current_02;
	}

	// Histogram sort on mode 0 into the permutation array
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
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		perm[idx] = bucket_02[i];
		B0_count[idx0]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_02[bucket_02[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_02[perm[i]] ++;
	}
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B1_count);
	free(B2_count);
	free(B0_count);
	free(bucket_02);
	free(quotient_02);
	return 0;
}
// transpose permutes the modes of the coordinates to be [2, 0, 1]
int transpose_coo_201_201_3(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [2, 0, 1]

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 <= B2_size; idx2 ++)
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

	// Fix and sort on [2]
	// Create buckets and quotient
	int *bucket_02 = (int *)malloc(c_size*sizeof(int));
	int *quotient_02 = (int *)malloc(c_size*sizeof(int));
	int current_02 = 0;
	bucket_02[0] = 0;
	quotient_02[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx2 != C_coords[i - 1].idx2) {
			current_02++;
			quotient_02[current_02] = i;
		}
		bucket_02[i] = current_02;
	}

	// Histogram sort on mode 0 into the permutation array
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
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		perm[idx] = bucket_02[i];
		B0_count[idx0]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_02[bucket_02[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_02[perm[i]] ++;
	}
	// Fix and sort on [0, 2]
	// Create buckets and quotient
	int *bucket_102 = (int *)malloc(c_size*sizeof(int));
	int *quotient_102 = (int *)malloc(c_size*sizeof(int));
	int current_102 = 0;
	bucket_102[0] = 0;
	quotient_102[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx0 != C_coords[i - 1].idx0) {
			current_102++;
			quotient_102[current_102] = i;
		}
		if(C_coords[i].idx2 != C_coords[i - 1].idx2) {
			current_102++;
			quotient_102[current_102] = i;
		}
		bucket_102[i] = current_102;
	}

	// Histogram sort on mode 1 into the permutation array
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
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		perm[idx] = bucket_102[i];
		B1_count[idx1]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_102[bucket_102[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_102[perm[i]] ++;
	}
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B2_count);
	free(B0_count);
	free(bucket_02);
	free(quotient_02);
	free(B1_count);
	free(bucket_102);
	free(quotient_102);
	return 0;
}
// transpose permutes the modes of the coordinates to be [2, 0, 1]
int transpose_coo_201_210_3(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [2, 0, 1]

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 <= B2_size; idx2 ++)
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

	// Fix and sort on [2]
	// Create buckets and quotient
	int *bucket_12 = (int *)malloc(c_size*sizeof(int));
	int *quotient_12 = (int *)malloc(c_size*sizeof(int));
	int current_12 = 0;
	bucket_12[0] = 0;
	quotient_12[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx2 != C_coords[i - 1].idx2) {
			current_12++;
			quotient_12[current_12] = i;
		}
		bucket_12[i] = current_12;
	}

	// Histogram sort on mode 1 into the permutation array
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
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		perm[idx] = bucket_12[i];
		B1_count[idx1]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_12[bucket_12[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_12[perm[i]] ++;
	}
	// Fix and sort on [2]
	// Create buckets and quotient
	int *bucket_02 = (int *)malloc(c_size*sizeof(int));
	int *quotient_02 = (int *)malloc(c_size*sizeof(int));
	int current_02 = 0;
	bucket_02[0] = 0;
	quotient_02[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx2 != C_coords[i - 1].idx2) {
			current_02++;
			quotient_02[current_02] = i;
		}
		bucket_02[i] = current_02;
	}

	// Histogram sort on mode 0 into the permutation array
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
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		int idx = B0_count[idx0] - 1;
		C_coords_scratch[idx] = C_coords[i];
		perm[idx] = bucket_02[i];
		B0_count[idx0]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_02[bucket_02[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_02[perm[i]] ++;
	}
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B2_count);
	free(B1_count);
	free(bucket_12);
	free(quotient_12);
	free(B0_count);
	free(bucket_02);
	free(quotient_02);
	return 0;
}
// transpose permutes the modes of the coordinates to be [2, 0, 1]
int transpose_coo_201_02_2(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [2, 0, 1]

	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 <= B0_size; idx0 ++)
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


	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 <= B2_size; idx2 ++)
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

	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B0_count);
	free(B2_count);
	return 0;
}
// transpose permutes the modes of the coordinates to be [2, 0, 1]
int transpose_coo_201_12_2(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [2, 0, 1]
	// Fix and sort on [0]
	// Create buckets and quotient
	int *bucket_10 = (int *)malloc(c_size*sizeof(int));
	int *quotient_10 = (int *)malloc(c_size*sizeof(int));
	int current_10 = 0;
	bucket_10[0] = 0;
	quotient_10[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx0 != C_coords[i - 1].idx0) {
			current_10++;
			quotient_10[current_10] = i;
		}
		bucket_10[i] = current_10;
	}

	// Histogram sort on mode 1 into the permutation array
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
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		perm[idx] = bucket_10[i];
		B1_count[idx1]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_10[bucket_10[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_10[perm[i]] ++;
	}

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 <= B2_size; idx2 ++)
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

	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B1_count);
	free(bucket_10);
	free(quotient_10);
	free(B2_count);
	return 0;
}
// transpose permutes the modes of the coordinates to be [2, 0, 1]
int transpose_coo_201_20_2(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [2, 0, 1]

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 <= B2_size; idx2 ++)
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


	// Histogram sort on mode 0
	int B0_size = dimensions[0];
	int32_t *B0_count = (int32_t *)calloc(B0_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx0 = C_coords[i].idx0;
		B0_count[idx0]++;
	}

	// Prefix sum over B0_count
	for(int idx0 = 1; idx0 <= B0_size; idx0 ++)
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

	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B2_count);
	free(B0_count);
	return 0;
}
// transpose permutes the modes of the coordinates to be [2, 0, 1]
int transpose_coo_201_21_2(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [2, 0, 1]

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 <= B2_size; idx2 ++)
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

	// Fix and sort on [0, 2]
	// Create buckets and quotient
	int *bucket_102 = (int *)malloc(c_size*sizeof(int));
	int *quotient_102 = (int *)malloc(c_size*sizeof(int));
	int current_102 = 0;
	bucket_102[0] = 0;
	quotient_102[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx0 != C_coords[i - 1].idx0) {
			current_102++;
			quotient_102[current_102] = i;
		}
		if(C_coords[i].idx2 != C_coords[i - 1].idx2) {
			current_102++;
			quotient_102[current_102] = i;
		}
		bucket_102[i] = current_102;
	}

	// Histogram sort on mode 1 into the permutation array
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
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx1 = C_coords[i].idx1;
		int idx = B1_count[idx1] - 1;
		C_coords_scratch[idx] = C_coords[i];
		perm[idx] = bucket_102[i];
		B1_count[idx1]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_102[bucket_102[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_102[perm[i]] ++;
	}
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B2_count);
	free(B1_count);
	free(bucket_102);
	free(quotient_102);
	return 0;
}
// transpose permutes the modes of the coordinates to be [2, 0, 1]
int transpose_coo_201_2_1(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [2, 0, 1]

	// Histogram sort on mode 2
	int B2_size = dimensions[2];
	int32_t *B2_count = (int32_t *)calloc(B2_size, sizeof(int32_t));
	for( int i = 0; i < c_size; i++)
	{
		int32_t idx2 = C_coords[i].idx2;
		B2_count[idx2]++;
	}

	// Prefix sum over B2_count
	for(int idx2 = 1; idx2 <= B2_size; idx2 ++)
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

	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B2_count);
	return 0;
}
