#include <stdio.h>
#include <stdlib.h>
#include "list.h"
    List* List_put(List* ptr, Data d){
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=malloc(sizeof(List));
            ptr->next->data=d;
            ptr->next->next=NULL;
            return ptr->next;
    }
    List_double* List_d_put(List_double* ptr, Data d){
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=malloc(sizeof(List_double));
        ptr->next->data=d;
        ptr->next->next=NULL;
        ptr->next->previous=ptr;
        return ptr->next;
    }
    Data List_pop(List* ptr){
        List *pptr;
        Data d;
        while(ptr->next!=NULL){
            pptr=ptr;    
            ptr=ptr->next;
        }
        d=ptr->data;
        free(ptr);
        pptr->next=NULL;
        return d;
    }
    Data List_d_pop(List_double* ptr){
        Data d;
        while(ptr->next!=NULL){    
            ptr=ptr->next;
        }
        d=ptr->data;
        ptr->previous->next=NULL;
        free(ptr);
        return d;
    }
    Data List_get_element(List *ptr, int index){
        int i=0;
        while(i<index){
            if(ptr->next==NULL){
                return NULL;
            }
            ptr=ptr->next;
            i++;
        }
        return ptr->data;
    }
    List_double* List_c_add(List_double* ptr, Data d){
        if(ptr->next==NULL){
            ptr->data=d;
            ptr->next=ptr;
            ptr->previous=ptr;
            return ptr;
        }
        else{
            List_double* temp_ptr;
            temp_ptr=ptr->next;
            ptr->next=malloc(sizeof(List_double));
            ptr->next->previous=ptr;
            ptr->next->next=temp_ptr;
            ptr->next->data=d;
            return ptr->next;
        }
    }
    Data List_c_remove_element(List_double* ptr){
        Data d=ptr->data;
        if(ptr->next!=NULL){
            ptr->previous->next=ptr->next;
            ptr->next->previous=ptr->previous;
        }
        free(ptr);
        return d;
    }
        