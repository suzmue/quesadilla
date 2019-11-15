#include <cstdio>
#include <cstdlib>


struct coo_t
{
	int32_t	idx0;
	int32_t	idx1;
	int32_t	idx2;
	double	val;
};

/*
    perm = [1,0,2]
    datatypes = ["int32_t", "int32_t", "int32_t", "double"]
    dims = [25,25,10]
    generate_header(3,datatypes)
    # 3 schedules

    # Schedule 012
    schedule = [(0,[]), (1,[]), (2,[0,1])]
    generate_function("012_3",perm, 3, datatypes, dims, schedule)

    # Schedule 021
    schedule = [(0,[]), (2,[0]), (1,[])]
    generate_function("021_3", perm, 3, datatypes, dims, schedule)

    # Schedule 102
    schedule = [(1,[]), (0,[1]), (2,[0,1])]
    generate_function("102_3", perm, 3, datatypes, dims, schedule)

    # Schedule 120
    schedule = [(1,[]),  (2,[1]), (0, [1])]
    generate_function("120_3", perm, 3, datatypes, dims, schedule)

    # Schedule 201
    schedule = [ (2,[]), (0, []), (1, [])]
    generate_function("201_3", perm, 3, datatypes, dims, schedule)

    # Schedule 210
    schedule = [(2,[]), (1, []), (0, [1])]
    generate_function("210_3", perm, 3, datatypes, dims, schedule)

    # 2 Schedule

    # 01
    schedule = [(0,[]), (1, []),]
    generate_function("01_2", perm, 3, datatypes, dims, schedule)
    # 02
    # schedule = [(0,[]), (2, [0]),]
    # generate_function("02_2", perm, 3, datatypes, dims, schedule)
    # 10
    schedule = [(1,[]), (0, [1]),]
    generate_function("10_2", perm, 3, datatypes, dims, schedule)
    # 12
    schedule = [(1,[]), (2, [0,1]),]
    generate_function("12_2", perm, 3, datatypes, dims, schedule)
    # 20
    # schedule = [(2,[]), (0, []),]
    # generate_function("20_2", perm, 3, datatypes, dims, schedule)
    # 21
    schedule = [(2,[0]), (1, []),]
    generate_function("21_2", perm, 3, datatypes, dims, schedule)

    # 1 schedule
    # schedule = [(0,[])]
    # generate_function("0_1", perm, 3, datatypes, dims, schedule)

    schedule = [(1,[])]
    generate_function("1_1", perm, 3, datatypes, dims, schedule)

    # schedule = [(2,[0])]
    # generate_function("2_1", perm, 3, datatypes, dims, schedule)
    # 0 Schedule
    # schedule = []
    # generate_function("0", perm, 3, datatypes, dims, schedule)

*/


// transpose permutes the modes of the coordinates to be [1, 0, 2]
int transpose_coo_102_012_3(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [1, 0, 2]

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

	// Fix and sort on [0, 1]
	// Create buckets and quotient
	int *bucket_201 = (int *)malloc(c_size*sizeof(int));
	int *quotient_201 = (int *)malloc(c_size*sizeof(int));
	int current_201 = 0;
	bucket_201[0] = 0;
	quotient_201[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx0 != C_coords[i - 1].idx0) {
			current_201++;
			quotient_201[current_201] = i;
		}
		if(C_coords[i].idx1 != C_coords[i - 1].idx1) {
			current_201++;
			quotient_201[current_201] = i;
		}
		bucket_201[i] = current_201;
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
		perm[idx] = bucket_201[i];
		B2_count[idx2]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_201[bucket_201[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_201[perm[i]] ++;
	}
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B0_count);
	free(B1_count);
	free(B2_count);
	free(bucket_201);
	free(quotient_201);
	return 0;
}
// transpose permutes the modes of the coordinates to be [1, 0, 2]
int transpose_coo_102_021_3(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [1, 0, 2]

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
	int *bucket_20 = (int *)malloc(c_size*sizeof(int));
	int *quotient_20 = (int *)malloc(c_size*sizeof(int));
	int current_20 = 0;
	bucket_20[0] = 0;
	quotient_20[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx0 != C_coords[i - 1].idx0) {
			current_20++;
			quotient_20[current_20] = i;
		}
		bucket_20[i] = current_20;
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
		perm[idx] = bucket_20[i];
		B2_count[idx2]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_20[bucket_20[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_20[perm[i]] ++;
	}

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

	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B0_count);
	free(B2_count);
	free(bucket_20);
	free(quotient_20);
	free(B1_count);
	return 0;
}
// transpose permutes the modes of the coordinates to be [1, 0, 2]
int transpose_coo_102_102_3(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [1, 0, 2]

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

	// Fix and sort on [1]
	// Create buckets and quotient
	int *bucket_01 = (int *)malloc(c_size*sizeof(int));
	int *quotient_01 = (int *)malloc(c_size*sizeof(int));
	int current_01 = 0;
	bucket_01[0] = 0;
	quotient_01[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx1 != C_coords[i - 1].idx1) {
			current_01++;
			quotient_01[current_01] = i;
		}
		bucket_01[i] = current_01;
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
		perm[idx] = bucket_01[i];
		B0_count[idx0]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_01[bucket_01[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_01[perm[i]] ++;
	}
	// Fix and sort on [0, 1]
	// Create buckets and quotient
	int *bucket_201 = (int *)malloc(c_size*sizeof(int));
	int *quotient_201 = (int *)malloc(c_size*sizeof(int));
	int current_201 = 0;
	bucket_201[0] = 0;
	quotient_201[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx0 != C_coords[i - 1].idx0) {
			current_201++;
			quotient_201[current_201] = i;
		}
		if(C_coords[i].idx1 != C_coords[i - 1].idx1) {
			current_201++;
			quotient_201[current_201] = i;
		}
		bucket_201[i] = current_201;
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
		perm[idx] = bucket_201[i];
		B2_count[idx2]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_201[bucket_201[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_201[perm[i]] ++;
	}
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B1_count);
	free(B0_count);
	free(bucket_01);
	free(quotient_01);
	free(B2_count);
	free(bucket_201);
	free(quotient_201);
	return 0;
}
// transpose permutes the modes of the coordinates to be [1, 0, 2]
int transpose_coo_102_120_3(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [1, 0, 2]

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

	// Fix and sort on [1]
	// Create buckets and quotient
	int *bucket_21 = (int *)malloc(c_size*sizeof(int));
	int *quotient_21 = (int *)malloc(c_size*sizeof(int));
	int current_21 = 0;
	bucket_21[0] = 0;
	quotient_21[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx1 != C_coords[i - 1].idx1) {
			current_21++;
			quotient_21[current_21] = i;
		}
		bucket_21[i] = current_21;
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
		perm[idx] = bucket_21[i];
		B2_count[idx2]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_21[bucket_21[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_21[perm[i]] ++;
	}
	// Fix and sort on [1]
	// Create buckets and quotient
	int *bucket_01 = (int *)malloc(c_size*sizeof(int));
	int *quotient_01 = (int *)malloc(c_size*sizeof(int));
	int current_01 = 0;
	bucket_01[0] = 0;
	quotient_01[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx1 != C_coords[i - 1].idx1) {
			current_01++;
			quotient_01[current_01] = i;
		}
		bucket_01[i] = current_01;
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
		perm[idx] = bucket_01[i];
		B0_count[idx0]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_01[bucket_01[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_01[perm[i]] ++;
	}
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B1_count);
	free(B2_count);
	free(bucket_21);
	free(quotient_21);
	free(B0_count);
	free(bucket_01);
	free(quotient_01);
	return 0;
}
// transpose permutes the modes of the coordinates to be [1, 0, 2]
int transpose_coo_102_201_3(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [1, 0, 2]

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

	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B2_count);
	free(B0_count);
	free(B1_count);
	return 0;
}
// transpose permutes the modes of the coordinates to be [1, 0, 2]
int transpose_coo_102_210_3(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [1, 0, 2]

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

	// Fix and sort on [1]
	// Create buckets and quotient
	int *bucket_01 = (int *)malloc(c_size*sizeof(int));
	int *quotient_01 = (int *)malloc(c_size*sizeof(int));
	int current_01 = 0;
	bucket_01[0] = 0;
	quotient_01[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx1 != C_coords[i - 1].idx1) {
			current_01++;
			quotient_01[current_01] = i;
		}
		bucket_01[i] = current_01;
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
		perm[idx] = bucket_01[i];
		B0_count[idx0]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_01[bucket_01[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_01[perm[i]] ++;
	}
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B2_count);
	free(B1_count);
	free(B0_count);
	free(bucket_01);
	free(quotient_01);
	return 0;
}
// transpose permutes the modes of the coordinates to be [1, 0, 2]
int transpose_coo_102_01_2(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [1, 0, 2]

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

	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B0_count);
	free(B1_count);
	return 0;
}
// transpose permutes the modes of the coordinates to be [1, 0, 2]
int transpose_coo_102_10_2(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [1, 0, 2]

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

	// Fix and sort on [1]
	// Create buckets and quotient
	int *bucket_01 = (int *)malloc(c_size*sizeof(int));
	int *quotient_01 = (int *)malloc(c_size*sizeof(int));
	int current_01 = 0;
	bucket_01[0] = 0;
	quotient_01[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx1 != C_coords[i - 1].idx1) {
			current_01++;
			quotient_01[current_01] = i;
		}
		bucket_01[i] = current_01;
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
		perm[idx] = bucket_01[i];
		B0_count[idx0]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_01[bucket_01[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_01[perm[i]] ++;
	}
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B1_count);
	free(B0_count);
	free(bucket_01);
	free(quotient_01);
	return 0;
}
// transpose permutes the modes of the coordinates to be [1, 0, 2]
int transpose_coo_102_12_2(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [1, 0, 2]

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

	// Fix and sort on [0, 1]
	// Create buckets and quotient
	int *bucket_201 = (int *)malloc(c_size*sizeof(int));
	int *quotient_201 = (int *)malloc(c_size*sizeof(int));
	int current_201 = 0;
	bucket_201[0] = 0;
	quotient_201[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx0 != C_coords[i - 1].idx0) {
			current_201++;
			quotient_201[current_201] = i;
		}
		if(C_coords[i].idx1 != C_coords[i - 1].idx1) {
			current_201++;
			quotient_201[current_201] = i;
		}
		bucket_201[i] = current_201;
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
		perm[idx] = bucket_201[i];
		B2_count[idx2]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_201[bucket_201[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_201[perm[i]] ++;
	}
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B1_count);
	free(B2_count);
	free(bucket_201);
	free(quotient_201);
	return 0;
}
// transpose permutes the modes of the coordinates to be [1, 0, 2]
int transpose_coo_102_21_2(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [1, 0, 2]
	// Fix and sort on [0]
	// Create buckets and quotient
	int *bucket_20 = (int *)malloc(c_size*sizeof(int));
	int *quotient_20 = (int *)malloc(c_size*sizeof(int));
	int current_20 = 0;
	bucket_20[0] = 0;
	quotient_20[0] = 0;
	for(int i = 1; i < c_size; i ++)
	{
		if(C_coords[i].idx0 != C_coords[i - 1].idx0) {
			current_20++;
			quotient_20[current_20] = i;
		}
		bucket_20[i] = current_20;
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
		perm[idx] = bucket_20[i];
		B2_count[idx2]--;
	}

	// Move the items back to the buckets.
	for (int i = 0; i < c_size; i ++) {
		C_coords[quotient_20[bucket_20[perm[i]]]] = C_coords_scratch[perm[i]];
		quotient_20[perm[i]] ++;
	}

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

	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B2_count);
	free(bucket_20);
	free(quotient_20);
	free(B1_count);
	return 0;
}
// transpose permutes the modes of the coordinates to be [1, 0, 2]
int transpose_coo_102_1_1(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [1, 0, 2]

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

	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	free(B1_count);
	return 0;
}
