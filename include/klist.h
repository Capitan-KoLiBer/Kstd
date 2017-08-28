#ifndef KSTD_KLIST_H
#define KSTD_KLIST_H

#include <string.h>
#include <stdlib.h>

typedef struct Klist{
    void **pointer;
    size_t block_size;
    int length;
    int (*equality_function)(void*,void*);
} Klist;

Klist *klist_new(size_t block_size,int (*equality_function)(void*,void*));
Klist *klist_add(Klist *klist , void *data);
Klist *klist_put(Klist *klist , int index , void *data);
Klist *klist_remove(Klist *klist , int index);
void *klist_get(Klist *klist , int index);
int klist_indexof(Klist *klist , void *data);
int klist_length(Klist *klist);
void klist_free(Klist *klist);

#endif //KSTD_KLIST_H
