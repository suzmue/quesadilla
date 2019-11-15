#include <cstdio>
#include <cstdlib>


struct coo_t
{
	int32_t	idx0;
	int32_t	idx1;
	int32_t	idx2;
	double	val;
};


// merge_0_sort performs a merge sort comparing on 0
void merge_0_sort(struct coo_t* C, struct coo_t* C_scratch, int start, int end)
{
	if(end > start + 1)
	{
		int m = start + (end - start) / 2;
		merge_0_sort(C, C_scratch, start, m);
		merge_0_sort(C, C_scratch, m, end);
		// Copy to scratch space
		memcpy(&C_scratch[start], &C[start], sizeof(struct coo_t)*(end-start));
		int i = start;
		int s_i = start;
		int e_i = m;
		while(s_i < m && e_i < end)
		{
			if(C_scratch[s_i].idx0 <=  C_scratch[e_i].idx0)
			{
				C[i] = C_scratch[s_i];
				s_i ++;
			} else {
				C[i] = C_scratch[e_i];
				e_i ++;
			}
			i++;
		}
		// Add any remaining s_i
		while(s_i < m)
		{
			C[i] = C_scratch[s_i];
			s_i ++;
			i++;
		}
		// Add any remaining e_i
		while(e_i < end)
		{
			C[i] = C_scratch[e_i];
			e_i ++;
			i++;
		}
	}
}

// merge_1_sort performs a merge sort comparing on 1
void merge_1_sort(struct coo_t* C, struct coo_t* C_scratch, int start, int end)
{
	if(end > start + 1)
	{
		int m = start + (end - start) / 2;
		merge_1_sort(C, C_scratch, start, m);
		merge_1_sort(C, C_scratch, m, end);
		// Copy to scratch space
		memcpy(&C_scratch[start], &C[start], sizeof(struct coo_t)*(end-start));
		int i = start;
		int s_i = start;
		int e_i = m;
		while(s_i < m && e_i < end)
		{
			if(C_scratch[s_i].idx1 <=  C_scratch[e_i].idx1)
			{
				C[i] = C_scratch[s_i];
				s_i ++;
			} else {
				C[i] = C_scratch[e_i];
				e_i ++;
			}
			i++;
		}
		// Add any remaining s_i
		while(s_i < m)
		{
			C[i] = C_scratch[s_i];
			s_i ++;
			i++;
		}
		// Add any remaining e_i
		while(e_i < end)
		{
			C[i] = C_scratch[e_i];
			e_i ++;
			i++;
		}
	}
}

// merge_2_sort performs a merge sort comparing on 2
void merge_2_sort(struct coo_t* C, struct coo_t* C_scratch, int start, int end)
{
	if(end > start + 1)
	{
		int m = start + (end - start) / 2;
		merge_2_sort(C, C_scratch, start, m);
		merge_2_sort(C, C_scratch, m, end);
		// Copy to scratch space
		memcpy(&C_scratch[start], &C[start], sizeof(struct coo_t)*(end-start));
		int i = start;
		int s_i = start;
		int e_i = m;
		while(s_i < m && e_i < end)
		{
			if(C_scratch[s_i].idx2 <=  C_scratch[e_i].idx2)
			{
				C[i] = C_scratch[s_i];
				s_i ++;
			} else {
				C[i] = C_scratch[e_i];
				e_i ++;
			}
			i++;
		}
		// Add any remaining s_i
		while(s_i < m)
		{
			C[i] = C_scratch[s_i];
			s_i ++;
			i++;
		}
		// Add any remaining e_i
		while(e_i < end)
		{
			C[i] = C_scratch[e_i];
			e_i ++;
			i++;
		}
	}
}

// transpose permutes the modes of the coordinates to be [1, 0, 2]
int transpose_coo_102(struct coo_t *C_coords, int c_size, int order, int *dimensions) {
	struct coo_t* C_coords_scratch = (struct coo_t *)malloc(sizeof(struct coo_t) * c_size);
	int* perm = (int *)malloc(sizeof(int) * c_size);

	// Sort the coordinates to be in [1, 0, 2]
	// Sort on 1
	merge_1_sort(C_coords, C_coords_scratch, 0, c_size);
	// Free the scratch space.
	free(C_coords_scratch);
	free(perm);
	return 0;
}
