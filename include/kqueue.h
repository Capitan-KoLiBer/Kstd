#ifndef KSTD_KQUEUE_H
#define KSTD_KQUEUE_H

#include <string.h>
#include <stdlib.h>

typedef struct Kqueue{
    struct Kqueue *next;
    void *data;
    int length;
} Kqueue;

Kqueue *kqueue_new();
Kqueue *kqueue_push(Kqueue *kqueue , void *data);
Kqueue *kqueue_pop(Kqueue *kqueue , void **data);
void *kqueue_first(Kqueue *kqueue);
void *kqueue_last(Kqueue *kqueue);
int kqueue_length(Kqueue *kqueue);
void kqueue_free(Kqueue *kqueue);

#endif //KSTD_KQUEUE_H
