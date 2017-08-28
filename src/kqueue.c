#include "kqueue.h"

Kqueue *kqueue_new(){
    Kqueue *kqueue = malloc(sizeof(Kqueue));
    kqueue->next = NULL;
    kqueue->length = 0;
    return kqueue;
}

Kqueue *kqueue_push(Kqueue *kqueue , void *data){
    Kqueue *node = malloc(sizeof(Kqueue));
    node->data = data;
    node->next = kqueue;
    node->length = kqueue->length+1;
    return node;
}

Kqueue *kqueue_pop(Kqueue *kqueue , void **data){
    *data = kqueue_first(kqueue);
    int index = 1;
    int length = kqueue->length;
    if(index >= 1 && index < kqueue->length){
        Kqueue *temp = kqueue;
        int position = kqueue->length;
        while(temp != NULL){
            if(position == index+1){
                void *clear = temp->next;
                temp->next = temp->next->next;
                if(clear != NULL){
                    free(clear);
                }
                kqueue->length = length-1;
                return kqueue;
            }
            temp = temp->next;
            position--;
        }
    }else if(index == kqueue->length){
        return kqueue->next;
    }
    return kqueue;
}

void *kqueue_first(Kqueue *kqueue){
    int index = 1;
    Kqueue *temp = kqueue;
    int position = kqueue->length;
    while(temp != NULL){
        if(position == index){
            return temp->data;
        }
        temp = temp->next;
        position--;
    }
    return NULL;
}

void *kqueue_last(Kqueue *kqueue){
    int index = kqueue->length;
    Kqueue *temp = kqueue;
    int position = kqueue->length;
    while(temp != NULL){
        if(position == index){
            return temp->data;
        }
        temp = temp->next;
        position--;
    }
    return NULL;
}

int kqueue_length(Kqueue *kqueue){
    return kqueue->length;
}

void kqueue_free(Kqueue *kqueue){
    while(kqueue != NULL){
        void *clear = kqueue;
        kqueue = kqueue->next;
        free(clear);
    }
}
