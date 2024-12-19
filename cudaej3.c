#include <cuda_runtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_SIZE 1024
#define BLOCK_SIZE 16
#define GRID_SIZE 16

__global__ void sumaVKernel(int *vec, int *result, int n) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x; 
    int stride = blockDim.x * gridDim.x; 
    int sum = 0;
    for (int i = idx; i < n; i += stride) {
        sum += vec[i];
    }
    atomicAdd(result, sum);
}

void initV(int *vec, int n) {
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 11 + 5; 
    }
}

int main() {
    int *h_vec;     
    int h_result = 0; 
    int *d_vec, *d_result; 

    size_t size = VECTOR_SIZE * sizeof(int);
    h_vec = (int *)malloc(size);

    srand(time(NULL));
    initV(h_vec, VECTOR_SIZE);

    cudaMalloc((void **)&d_vec, size);
    cudaMalloc((void **)&d_result, sizeof(int));

    cudaMemcpy(d_result, &h_result, sizeof(int), cudaMemcpyHostToDevice);

    cudaMemcpy(d_vec, h_vec, size, cudaMemcpyHostToDevice);

    dim3 blockSize(BLOCK_SIZE); 
    dim3 gridSize(GRID_SIZE);   

    sumaVKernel<<<gridSize, blockSize>>>(d_vec, d_result, VECTOR_SIZE);

    cudaMemcpy(&h_result, d_result, sizeof(int), cudaMemcpyDeviceToHost);

    printf("V:\n");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        printf("%d ", h_vec[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }

    printf("\nResultado: %d\n", h_result);

    free(h_vec);
    cudaFree(d_vec);
    cudaFree(d_result);

    return 0;
}
