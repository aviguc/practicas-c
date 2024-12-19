#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_THREADS 8

typedef struct {
    int start;
    int end;
    int count;
} ThreadData;


bool es_primo(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void* contar_primos(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    data->count = 0;

    for (int i = data->start; i <= data->end; i++) {
        if (es_primo(i)) {
            data->count++;
        }
    }

    return NULL;
}

int main() {
    int n, num_threads;

    printf("Introduce el valor de n: ");
    scanf("%d", &n);

    
    printf("Introduce el número de hilos (máximo %d): ", MAX_THREADS);
    scanf("%d", &num_threads);
    if (num_threads > MAX_THREADS) num_threads = MAX_THREADS;

    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];

    int intervalo = n / num_threads;
    int inicio = 1;

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].start = inicio;
        thread_data[i].end = (i == num_threads - 1) ? n : (inicio + intervalo - 1);
        pthread_create(&threads[i], NULL, contar_primos, &thread_data[i]);
        inicio = thread_data[i].end + 1;
    }

    int total_primos = 0;
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        total_primos += thread_data[i].count;
    }

    printf("Total de números primos en el intervalo [1, %d]: %d\n", n, total_primos);

    return 0;
}
