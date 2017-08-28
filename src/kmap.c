#include "kmap.h"

Kmap *kmap_new(size_t block_size_key,size_t block_size_value,int (*equality_function)(void*,void*)){
    Kmap *kmap = malloc(sizeof(Kmap));
    kmap->pointer_key = malloc(block_size_key);
    kmap->pointer_value = malloc(block_size_value);
    kmap->block_size_key = block_size_key+4;
    kmap->block_size_value = block_size_value+4;
    kmap->equality_function = equality_function;
    kmap->length = 0;
    return kmap;
}

Kmap *kmap_put(Kmap *kmap , void *key , void *value){
    int indexof = kmap_indexof(kmap,key);
    if(indexof >= 0){
        kmap->pointer_value[indexof+1] = value;
    }else{
        kmap->length++;
        kmap->pointer_key = realloc(kmap->pointer_key,(kmap->length+1)*kmap->block_size_key);
        kmap->pointer_value = realloc(kmap->pointer_value,(kmap->length+1)*kmap->block_size_value);
        kmap->pointer_key[kmap->length] = key;
        kmap->pointer_value[kmap->length] = value;
    }
    return kmap;
}

Kmap *kmap_remove(Kmap *kmap , void *key){
    int indexof = kmap_indexof(kmap,key);
    if(indexof >= 0){
        memcpy(kmap->pointer_key+indexof+1,kmap->pointer_key+indexof+2,(kmap->length-indexof)*kmap->block_size_key);
        memcpy(kmap->pointer_value+indexof+1,kmap->pointer_value+indexof+2,(kmap->length-indexof)*kmap->block_size_value);
        kmap->length--;
        kmap->pointer_key = realloc(kmap->pointer_key,(kmap->length+1)*kmap->block_size_key);
        kmap->pointer_value = realloc(kmap->pointer_value,(kmap->length+1)*kmap->block_size_value);
    }
    return kmap;
}

void *kmap_get(Kmap *kmap , void *key){
    int indexof = kmap_indexof(kmap,key);
    if(indexof >= 0){
        return kmap->pointer_value[indexof+1];
    }else{
        return NULL;
    }
}

void *kmap_key(Kmap *kmap , int index){
    if(index >= 0 && index < kmap->length){
        return kmap->pointer_key[index+1];
    } else {
        return NULL;
    }
}

void *kmap_value(Kmap *kmap , int index){
    if(index >= 0 && index < kmap->length){
        return kmap->pointer_value[index+1];
    } else {
        return NULL;
    }
}

int kmap_indexof(Kmap *kmap , void *key){
    for(int cursor = 0 ; cursor < kmap->length ; cursor++){
        if((*kmap->equality_function)(key,kmap_key(kmap,cursor))){
            return cursor;
        }
    }
    return -1;
}

int kmap_length(Kmap *kmap){
    return kmap->length;
}

void kmap_free(Kmap *kmap){
    if(kmap != NULL){
        if(kmap->pointer_key != NULL){
            free(kmap->pointer_key);
        }
        if(kmap->pointer_value != NULL){
            free(kmap->pointer_value);
        }
        free(kmap);
    }
}
