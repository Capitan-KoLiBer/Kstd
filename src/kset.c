#include "kset.h"

Kset *kset_new(size_t block_size,int (*equality_function)(void*,void*)){
    Kset *kset = malloc(sizeof(Kset));
    kset->pointer = malloc(block_size);
    kset->block_size = block_size+4;
    kset->equality_function = equality_function;
    kset->length = 0;
    return kset;
}

Kset *kset_add(Kset *kset , void *data){
    if(kset_indexof(kset,data) < 0){
        kset->length++;
        kset->pointer = realloc(kset->pointer,(kset->length+1)*kset->block_size);
        kset->pointer[kset->length] = data;
        return kset;
    }else{
        return kset;
    }
}

Kset *kset_put(Kset *kset , int index , void *data){
    if(index >= 0 && index < kset->length){
        if(kset_indexof(kset,data) < 0 || ((*kset->equality_function)(data,kset_get(kset,index)))){
            kset->pointer[index+1] = data;
            return kset;
        }else{
            return kset;
        }
    } else {
        return kset;
    }
}

Kset *kset_remove(Kset *kset , int index){
    memcpy(kset->pointer+index+1,kset->pointer+index+2,(kset->length-index)*kset->block_size);
    kset->length--;
    kset->pointer = realloc(kset->pointer,(kset->length+1)*kset->block_size);
    return kset;
}

void *kset_get(Kset *kset , int index){
    if(index >= 0 && index < kset->length){
        return kset->pointer[index+1];
    }else{
        return NULL;
    }
}

int kset_indexof(Kset *kset , void *data){
    for(int cursor = 0 ; cursor < kset->length ; cursor++){
        if((*kset->equality_function)(data,kset_get(kset,cursor))){
            return cursor;
        }
    }
    return -1;
}

int kset_length(Kset *kset){
    return kset->length;
}

void kset_free(Kset *kset){
    if(kset != NULL){
        if(kset->pointer != NULL){
            free(kset->pointer);
        }
        free(kset);
    }
}