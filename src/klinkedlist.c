#include "klinkedlist.h"

Klinkedlist *klinkedlist_new(int (*equality_function)(void*,void*)){
    Klinkedlist *klinkedlist = malloc(sizeof(Klinkedlist));
    klinkedlist->next = NULL;
    klinkedlist->equality_function = equality_function;
    klinkedlist->length = 0;
    return klinkedlist;
}

Klinkedlist *klinkedlist_add(Klinkedlist *klinkedlist , void *data){
    Klinkedlist *node = malloc(sizeof(Klinkedlist));
    node->data = data;
    node->next = klinkedlist;
    node->length = klinkedlist->length+1;
    node->equality_function = klinkedlist->equality_function;
    return node;
}

Klinkedlist *klinkedlist_put(Klinkedlist *klinkedlist , int index , void *data){
    index++;
    if(index >= 1 && index <= klinkedlist->length){
        Klinkedlist *temp = klinkedlist;
        int position = klinkedlist->length;
        while(temp != NULL){
            if(position == index){
                temp->data = data;
                return klinkedlist;
            }
            temp = temp->next;
            position--;
        }
    }
    return klinkedlist;
}

Klinkedlist *klinkedlist_remove(Klinkedlist *klinkedlist , int index){
    index++;
    int length = klinkedlist->length;
    if(index >= 1 && index < klinkedlist->length){
        Klinkedlist *temp = klinkedlist;
        int position = klinkedlist->length;
        while(temp != NULL){
            if(position == index+1){
                void *clear = temp->next;
                temp->next = temp->next->next;
                if(clear != NULL){
                    free(clear);
                }
                klinkedlist->length = length-1;
                return klinkedlist;
            }
            temp = temp->next;
            position--;
        }
    }else if(index == klinkedlist->length){
        return klinkedlist->next;
    }
    return klinkedlist;
}

void *klinkedlist_get(Klinkedlist *klinkedlist , int index){
    index++;
    if(index >= 1 && index <= klinkedlist->length){
        Klinkedlist *temp = klinkedlist;
        int position = klinkedlist->length;
        while(temp != NULL){
            if(position == index){
                return temp->data;
            }
            temp = temp->next;
            position--;
        }
    }
    return NULL;
}

int klinkedlist_indexof(Klinkedlist *klinkedlist , void *data){
    Klinkedlist *temp = klinkedlist;
    int position = klinkedlist->length;
    while(temp != NULL){
        position--;
        if((*klinkedlist->equality_function)(data,temp->data)){
            return position;
        }
        temp = temp->next;
    }
    return -1;
}

int klinkedlist_length(Klinkedlist *klinkedlist){
    return klinkedlist->length;
}

void klinkedlist_free(Klinkedlist *klinkedlist){
    while(klinkedlist != NULL){
        void *clear = klinkedlist;
        klinkedlist = klinkedlist->next;
        free(clear);
    }
}