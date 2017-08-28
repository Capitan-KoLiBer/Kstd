#ifndef KSTD_KMAP_H
#define KSTD_KMAP_H

#include <string.h>
#include <stdlib.h>

typedef struct Kmap{
    void **pointer_key;
    void **pointer_value;
    size_t block_size_value;
    size_t block_size_key;
    int length;
    int (*equality_function)(void*,void*);
} Kmap;

Kmap *kmap_new(size_t block_size_key,size_t block_size_value,int (*equality_function)(void*,void*));
Kmap *kmap_put(Kmap *kmap , void *key , void *value);
Kmap *kmap_remove(Kmap *kmap , void *key);
void *kmap_get(Kmap *kmap , void *key);
void *kmap_key(Kmap *kmap , int index);
void *kmap_value(Kmap *kmap , int index);
int kmap_indexof(Kmap *kmap , void *key);
int kmap_length(Kmap *kmap);
void kmap_free(Kmap *kmap);

#endif //KSTD_KMAP_H
