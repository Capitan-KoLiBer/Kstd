#ifndef KSTD_KSET_H
#define KSTD_KSET_H

#include <string.h>
#include <stdlib.h>

typedef struct Kset{
    void **pointer;
    size_t block_size;
    int length;
    int (*equality_function)(void*,void*);
} Kset;

Kset *kset_new(size_t block_size,int (*equality_function)(void*,void*));
Kset *kset_add(Kset *kset , void *data);
Kset *kset_put(Kset *kset , int index , void *data);
Kset *kset_remove(Kset *kset , int index);
void *kset_get(Kset *kset , int index);
int kset_indexof(Kset *kset , void *data);
int kset_length(Kset *kset);
void kset_free(Kset *kset);


#endif //KSTD_KSET_H
