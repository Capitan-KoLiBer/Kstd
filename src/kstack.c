#include "kstack.h"

Kstack *kstack_new(){
    Kstack *kstack = malloc(sizeof(Kstack));
    kstack->next = NULL;
    kstack->length = 0;
    return kstack;
}

Kstack *kstack_push(Kstack *kstack , void *data){
    Kstack *node = malloc(sizeof(Kstack));
    node->data = data;
    node->next = kstack;
    node->length = kstack->length+1;
    return node;
}

Kstack *kstack_pop(Kstack *kstack , void **data){
    *data = kstack_first(kstack);
    int index = kstack->length;
    int length = kstack->length;
    if(index >= 1 && index < kstack->length){
        Kstack *temp = kstack;
        int position = kstack->length;
        while(temp != NULL){
            if(position == index+1){
                void *clear = temp->next;
                temp->next = temp->next->next;
                if(clear != NULL){
                    free(clear);
                }
                kstack->length = length-1;
                return kstack;
            }
            temp = temp->next;
            position--;
        }
    }else if(index == kstack->length){
        return kstack->next;
    }
    return kstack;
}

void *kstack_first(Kstack *kstack){
    int index = kstack->length;
    Kstack *temp = kstack;
    int position = kstack->length;
    while(temp != NULL){
        if(position == index){
            return temp->data;
        }
        temp = temp->next;
        position--;
    }
    return NULL;
}

void *kstack_last(Kstack *kstack){
    int index = 1;
    Kstack *temp = kstack;
    int position = kstack->length;
    while(temp != NULL){
        if(position == index){
            return temp->data;
        }
        temp = temp->next;
        position--;
    }
    return NULL;
}

int kstack_length(Kstack *kstack){
    return kstack->length;
}

void kstack_free(Kstack *kstack){
    while(kstack != NULL){
        void *clear = kstack;
        kstack = kstack->next;
        free(clear);
    }
}
