#ifndef KSTD_KLINKEDLIST_H
#define KSTD_KLINKEDLIST_H

#include <string.h>
#include <stdlib.h>

typedef struct Klinkedlist{
    struct Klinkedlist *next;
    void *data;
    int length;
    int (*equality_function)(void*,void*);
} Klinkedlist;

Klinkedlist *klinkedlist_new(int (*equality_function)(void*,void*));
Klinkedlist *klinkedlist_add(Klinkedlist *klinkedlist , void *data);
Klinkedlist *klinkedlist_put(Klinkedlist *klinkedlist , int index , void *data);
Klinkedlist *klinkedlist_remove(Klinkedlist *klinkedlist , int index);
void *klinkedlist_get(Klinkedlist *klinkedlist , int index);
int klinkedlist_indexof(Klinkedlist *klinkedlist , void *data);
int klinkedlist_length(Klinkedlist *klinkedlist);
void klinkedlist_free(Klinkedlist *klinkedlist);

#endif //KSTD_KLINKEDLIST_H
