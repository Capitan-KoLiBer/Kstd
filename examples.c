#include "klist.h"
#include "kset.h"
#include "kmap.h"
#include "klinkedlist.h"
#include "kqueue.h"
#include "kstack.h"
#include "stdio.h"

int equals(void *A , void *B){
    // A , B are string !
    if(strcmp(A,B) == 0){
        return 1;
    }else{
        return 0;
    }
}

int main() {
    int length,cursor;

    Klist *list = klist_new(sizeof(char*),equals);

    //   Adding !!!
    list = klist_add(list,"A");
    list = klist_add(list,"B");
    list = klist_add(list,"C");
    list = klist_add(list,"D");

    // Putting
    list = klist_put(list,2,"PUT");

    // Removing
    list = klist_remove(list,1);

    // Length
    length = klist_length(list);
    for(cursor = 0 ; cursor < length ; cursor++){
        printf("list[%d] = %s\n", cursor, (char *) klist_get(list, cursor));
    }
    printf("\n\n--------------------------------------------------------------\n\n");
    Kset *set = kset_new(sizeof(char*),equals);

    //   Adding !!!
    set = kset_add(set,"A");
    set = kset_add(set,"B");
    set = kset_add(set,"C");
    set = kset_add(set,"D");

    // Putting
    set = kset_put(set,2,"PUT");

    // Removing
    set = kset_remove(set,1);

    // Length
    length = kset_length(set);
    for(cursor = 0 ; cursor < length ; cursor++){
        printf("set[%d] = %s\n", cursor, (char *) kset_get(set, cursor));
    }
    printf("\n\n--------------------------------------------------------------\n\n");
    Kmap *map = kmap_new(sizeof(char*),sizeof(char*),equals);

    // Putting
    map = kmap_put(map,"KEY_1","VALUE_1");
    map = kmap_put(map,"KEY_2","VALUE_2");
    map = kmap_put(map,"KEY_1","VALUE_3");

    // Removing
    map = kmap_remove(map,"KEY_2");

    // Length
    length = kmap_length(map);
    for(cursor = 0 ; cursor < length ; cursor++){
        printf("map[%s] = %s\n", (char *) kmap_key(map, cursor), (char *) kmap_value(map, cursor));
    }
    printf("\n\n--------------------------------------------------------------\n\n");
    Klinkedlist *linkedlist = klinkedlist_new(equals);

    //   Adding !!!
    linkedlist = klinkedlist_add(linkedlist,"A");
    linkedlist = klinkedlist_add(linkedlist,"B");
    linkedlist = klinkedlist_add(linkedlist,"C");
    linkedlist = klinkedlist_add(linkedlist,"D");

    // Putting
    linkedlist = klinkedlist_put(linkedlist,2,"PUT");

    // Removing
    linkedlist = klinkedlist_remove(linkedlist,1);

    // Length
    length = klinkedlist_length(linkedlist);
    for(cursor = 0 ; cursor < length ; cursor++){
        printf("linkedlist[%d] = %s\n", cursor, (char *) klinkedlist_get(linkedlist, cursor));
    }
    printf("\n\n--------------------------------------------------------------\n\n");
    Kqueue *queue = kqueue_new();

    // Pushing
    queue = kqueue_push(queue,"A");
    queue = kqueue_push(queue,"B");
    queue = kqueue_push(queue,"C");
    queue = kqueue_push(queue,"D");

    // Poping
    length = kqueue_length(queue);
    for(cursor = 0 ; cursor < length ; cursor++){
        void *data = NULL;
        queue = kqueue_pop(queue,&data);
        printf("queue[%d] = %s\n", cursor, (char *) data);
    }
    printf("\n\n--------------------------------------------------------------\n\n");
    Kstack *stack = kstack_new();

    // Pushing
    stack = kstack_push(stack,"A");
    stack = kstack_push(stack,"B");
    stack = kstack_push(stack,"C");
    stack = kstack_push(stack,"D");

    // Poping
    length = kstack_length(stack);
    for(cursor = 0 ; cursor < length ; cursor++){
        void *data = NULL;
        stack = kstack_pop(stack,&data);
        printf("stack[%d] = %s\n", cursor, (char *) data);
    }

}