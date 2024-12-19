#include <cuda_runtime.h>
#include <stdio.h>

#define VECTOR_SIZE 128

__global__ void initvKernel(int *vec) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x; 
    if (idx < VECTOR_SIZE) { 
        vec[idx] = idx;
    }
}

__global__ void initvconStrideKernel(int *vec, int n) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x; 
    int stride = blockDim.x * gridDim.x; 

    for (int i = idx; i < n; i += stride) { 
        vec[i] = i;
    }
}

int main() {
    int *d_vec; 
    int h_vec[VECTOR_SIZE]; 
    size_t size = VECTOR_SIZE * sizeof(int);

    cudaMalloc((void **)&d_vec, size);

    printf("Primera Parte: Bloques de tamaño 8\n");
    int blockSize1 = 8;
    int gridSize1 = (VECTOR_SIZE + blockSize1 - 1) / blockSize1; 

    initvKernel<<<gridSize1, blockSize1>>>(d_vec);

    cudaMemcpy(h_vec, d_vec, size, cudaMemcpyDeviceToHost);
    for (int i = 0; i < VECTOR_SIZE; i++) {
        printf("%d ", h_vec[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("Segunda Parte: Bloques de tamaño 8, Grid de tamaño 8 \n");
    int blockSize2 = 8;
    int gridSize2 = 8;
    initvconStrideKernel<<<gridSize2, blockSize2>>>(d_vec, VECTOR_SIZE);t
    cudaMemcpy(h_vec, d_vec, size, cudaMemcpyDeviceToHost);
    for (int i = 0; i < VECTOR_SIZE; i++) {
        printf("%d ", h_vec[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    cudaFree(d_vec);

    return 0;
}
