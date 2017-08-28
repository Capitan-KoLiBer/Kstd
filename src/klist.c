#include "klist.h"

Klist *klist_new(size_t block_size , int (*equality_function)(void*,void*)){
    Klist *klist = malloc(sizeof(Klist));
    klist->pointer = malloc(block_size);
    klist->block_size = block_size+4;
    klist->equality_function = equality_function;
    klist->length = 0;
    return klist;
}

Klist *klist_add(Klist *klist , void *data){
    klist->length++;
    klist->pointer = realloc(klist->pointer,(klist->length+1)*klist->block_size);
    klist->pointer[klist->length] = data;
    return klist;
}

Klist *klist_put(Klist *klist , int index , void *data){
    if(index >= 0 && index < klist->length){
        klist->pointer[index+1] = data;
        return klist;
    } else {
        return klist;
    }
}

Klist *klist_remove(Klist *klist , int index){
    memcpy(klist->pointer+index+1,klist->pointer+index+2,(klist->length-index)*klist->block_size);
    klist->length--;
    klist->pointer = realloc(klist->pointer,(klist->length+1)*klist->block_size);
    return klist;
}

void *klist_get(Klist *klist , int index){
    if(index >= 0 && index < klist->length){
        return klist->pointer[index+1];
    }else{
        return NULL;
    }
}

int klist_indexof(Klist *klist , void *data){
    for(int cursor = 0 ; cursor < klist->length ; cursor++){
        if((*klist->equality_function)(data,klist_get(klist,cursor))){
            return cursor;
        }
    }
    return -1;
}

int klist_length(Klist *klist){
    return klist->length;
}

void klist_free(Klist *klist){
    if(klist != NULL){
        if(klist->pointer != NULL){
            free(klist->pointer);
        }
        free(klist);
    }
}