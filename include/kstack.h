#ifndef KSTD_KSTACK_H
#define KSTD_KSTACK_H

#include <string.h>
#include <stdlib.h>

typedef struct Kstack{
    struct Kstack *next;
    void *data;
    int length;
} Kstack;

Kstack *kstack_new();
Kstack *kstack_push(Kstack *kstack , void *data);
Kstack *kstack_pop(Kstack *kstack , void **data);
void *kstack_first(Kstack *kstack);
void *kstack_last(Kstack *kstack);
int kstack_length(Kstack *kstack);
void kstack_free(Kstack *kstack);

#endif //KSTD_KSTACK_H
