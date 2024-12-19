#include <cuda_runtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 

__global__ void addMKernel(int *a, int *b, int *c, int n) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < n && col < n) {
        int index = row * n + col; 
        c[index] = a[index] + b[index];
    }
}
void initM(int *matrix, int n) {
    for (int i = 0; i < n * n; i++) {
        matrix[i] = rand() % 11 + 10; 
    }
}
void printM(int *matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int *h_a, *h_b, *h_c;      
    int *d_a, *d_b, *d_c;     
    size_t size = N * N * sizeof(int);

    h_a = (int *)malloc(size);
    h_b = (int *)malloc(size);
    h_c = (int *)malloc(size);
    srand(time(NULL));
    initM(h_a, N);
    initM(h_b, N);
    cudaMalloc((void **)&d_a, size);
    cudaMalloc((void **)&d_b, size);
    cudaMalloc((void **)&d_c, size);
    cudaMemcpy(d_a, h_a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, size, cudaMemcpyHostToDevice);
    dim3 blockSize(16, 16); 
    dim3 gridSize((N + blockSize.x - 1) / blockSize.x, (N + blockSize.y - 1) / blockSize.y);
    addMKernel<<<gridSize, blockSize>>>(d_a, d_b, d_c, N);
    cudaMemcpy(h_c, d_c, size, cudaMemcpyDeviceToHost);
    printf("Matriz A:\n");
    printMatrix(h_a, N);

    printf("Matriz B:\n");
    printMatrix(h_b, N);

    printf("Resultado:\n");
    printMatrix(h_c, N);

    free(h_a);
    free(h_b);
    free(h_c);
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}
