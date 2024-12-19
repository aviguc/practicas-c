#include <cuda_runtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_SIZE 128
__global__ void addVKernel(int *a, int *b, int *c, int n) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x; 
    if (idx < n) { 
        c[idx] = a[idx] + b[idx];
    }
}

void initV(int *vec, int n) {
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 10 + 1; 
    }
}

int main() {
    int *h_a, *h_b, *h_c;   
    int *d_a, *d_b, *d_c;   

    size_t size = VECTOR_SIZE * sizeof(int);
    h_a = (int *)malloc(size);
    h_b = (int *)malloc(size);
    h_c = (int *)malloc(size);

    srand(time(NULL));
    initv(h_a, VECTOR_SIZE);
    initV(h_b, VECTOR_SIZE);

    cudaMalloc((void **)&d_a, size);
    cudaMalloc((void **)&d_b, size);
    cudaMalloc((void **)&d_c, size);

    cudaMemcpy(d_a, h_a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, size, cudaMemcpyHostToDevice);

    int blockSize = 8; 
    int gridSize = (VECTOR_SIZE + blockSize - 1) / blockSize; 

    addVKernel<<<gridSize, blockSize>>>(d_a, d_b, d_c, VECTOR_SIZE);

    cudaMemcpy(h_c, d_c, size, cudaMemcpyDeviceToHost);

    printf("V A:\n");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        printf("%d ", h_a[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }

    printf("V B:\n");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        printf("%d ", h_b[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }

    printf("Resultado:\n");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        printf("%d ", h_c[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }

    free(h_a);
    free(h_b);
    free(h_c);
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}
