/*
 * File:   List_test.c
 * Author: Lukasz
 *
 * Created on 2016-07-23, 13:19:38
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

/*
 * Simple C Test Suite
 */

void test_initialization() {
    List l;
    List_init(l);
    if(l.next!=NULL){
        printf("%%TEST_FAILED%% time=0 testname=test_initialization (List_test) message=Pointer to next item in a list has not been initialized to NULL\n");
    }
}
void test_list_put(){
    List l;
    List* lptr;
    int data[]={5,2,3};
    List_init(l);
    lptr=List_put(&l,(void*)&data[0]);
    lptr=List_put(&l,(void*)&data[1]);
    lptr=List_put(&l,(void*)&data[2]);
    if(*(int*)lptr->data!=data[2] || lptr->next!=NULL){
        printf("%%TEST_FAILED%% time=0 testname=test_list_put (List_test) message=Data has not been set in the list\n");
    }

}
void test_list_pop(){
    List l;
    List* lptr;
    int data[]={5,3,4};
    int result=0;
    List_init(l);
    List_put(&l,(void*)&data[0]);
    lptr=List_put(&l,(void*)&data[1]);
    List_put(&l,(void*)&data[2]);
    result=*(int*)List_pop(&l);
    printf("%d",result);
    if(result!=data[2] || lptr->next!=NULL){
        printf("%%TEST_FAILED%% time=0 testname=test_list_pop (List_test) message=Data has not been taken from last element from the list\n");
    }
}
void test_get_element(){
    List l;
    int data[]={5,2,3};
    void* result=0;
    int res=0;
    List_init(l);
    List_put(&l,(void*)&data[0]);
    List_put(&l,(void*)&data[1]);
    List_put(&l,(void*)&data[2]);
    result=List_get_element(&l,2);
    if(result==NULL){
        printf("%%TEST_FAILED%% time=0 testname=test_get_element (List_test) message=error getting data from valid index element\n");
        return;
    }
    res=*(int*)result;
    if(res!=data[1]){
        printf("%%TEST_FAILED%% time=0 testname=test_get_element (List_test) message=Data has not been taken from pointed by index element:its %d but should be %d \n",res,data[1]);
        return;
    }
    result=List_get_element(&l,5);
    if(result!=NULL){
        printf("%%TEST_FAILED%% time=0 testname=test_get_element (List_test) message=data has not been set to null whit index exceeding list number\n");
    }
}
void test_d_list_put(){
    List_double l;
    List_double* lptr;
    int data[]={5,2,3};
    List_d_init(l);
    lptr=List_d_put(&l,(void*)&data[0]);
    lptr=List_d_put(&l,(void*)&data[1]);
    lptr=List_d_put(&l,(void*)&data[2]);
    if(*(int*)lptr->data!=data[2] || lptr->next!=NULL){
        printf("%%TEST_FAILED%% time=0 testname=test_d_list_put (List_test) message=Data has not been set in the list it s %d but should be %d\n",*(int*)lptr->data,data[2]);
    }
}
void test_d_list_pop(){
    List_double l;
    List_double* lptr;
    int data[]={5,3,4};
    int result=0;
    List_d_init(l);
    List_d_put(&l,(void*)&data[0]);
    lptr=List_d_put(&l,(void*)&data[1]);
    List_d_put(&l,(void*)&data[2]);
    result=*(int*)List_d_pop(&l);
    printf("%d",result);
    if(result!=data[2] || lptr->next!=NULL){
        printf("%%TEST_FAILED%% time=0 testname=test_d_list_pop (List_test) message=Data has not been taken from last element from the list\n");
    }
}
void test_list_get_element(){
    
}
void test_list_c_add(){
    List_double l;
    List_double* lptr;
    List_d_init(l);
    int data[]={1,5};
    int res=0;
    List_c_add(&l,(void*)&data[0]);
    if(l.next!=l.previous){
        printf("%%TEST_FAILED%% time=0 testname=test_list_c_add (List_test) message=Error adding first element to the list because next=%x, previous-%x and both should be: %x\n",l.next,l.previous,&l);
    }
    lptr=List_c_add(&l,(void*)&data[1]);
    if(lptr->next!=&l || lptr->previous!=&l){
        printf("%%TEST_FAILED%% time=0 testname=test_list_c_add (List_test) message=Error adding second element to the list because lptr->next=%x, lptr->previous-%x and both should be: %x\n",l.next,l.previous,&l);
    }
    res=*(int*)lptr->data;
    if(res!=data[1]){
        printf("%%TEST_FAILED%% time=0 testname=test_list_c_add (List_test) message=Error geting data from the list, its %d but should be %d\n",res,data[1]);
    }
}
void test_list_c_remove(){
    List_double l;
    List_double* lptr, *lptr2;
    List_d_init(l);
    int data[]={1,5,4};
    int res=0;
    List_c_add(&l,(void*)&data[0]);
    lptr=List_c_add(&l,(void*)&data[1]);
    lptr2=List_c_add(lptr,(void*)&data[2]);
    res=*(int*)List_c_remove_element(lptr);
    if(res!=data[1]){
        printf("%%TEST_FAILED%% time=0 testname=test_list_c_remove (List_test) message=Error getting value from list its: %d but should be: %d\n",res,data[1]);
    }
    res=*(int*)lptr->data;
    if(&l!= lptr2->previous){
        printf("%%TEST_FAILED%% time=0 testname=test_list_c_remove (List_test) message=Pointers have not been set properly it is l %x l.n %x l.p %x  , l1 %x l1.n %x l1.p %x \n",&l,l.next,l.previous,lptr2,lptr2->next,lptr2->previous);
    }
}


int main(int argc, char** argv) {
    clock_t main_tic, main_toc, tic, toc;
    printf("%%SUITE_STARTING%% List_test\n");
    printf("%%SUITE_STARTED%%\n");
    main_tic=clock();
        
    printf("%%TEST_STARTED%% test1 (List_test)\n");
    tic=clock();
    test_initialization();
    toc=clock();
    printf("%%TEST_FINISHED%% time=%.6f test1 (List_test) \n",(double)(toc-tic)/CLOCKS_PER_SEC);
    
    printf("%%TEST_STARTED%% test2 (List_test)\n");
    tic=clock();
    test_list_put();
    toc=clock();
    printf("%%TEST_FINISHED%% time=%.6f test2 (List_test) \n",(double)(toc-tic)/CLOCKS_PER_SEC);

    printf("%%TEST_STARTED%% test3 (List_test)\n");
    tic=clock();
    test_list_pop();
    toc=clock();
    printf("%%TEST_FINISHED%% time=%.6f test3 (List_test) \n",(double)(toc-tic)/CLOCKS_PER_SEC);
    
    printf("%%TEST_STARTED%% test4 (List_test)\n");
    tic=clock();
    test_get_element();
    toc=clock();
    printf("%%TEST_FINISHED%% time=%.6f test4 (List_test) \n",(double)(toc-tic)/CLOCKS_PER_SEC);
    
    printf("%%TEST_STARTED%% test5 (List_test)\n");
    tic=clock();
    test_list_c_add();
    toc=clock();
    printf("%%TEST_FINISHED%% time=%.6f test5 (List_test) \n",(double)(toc-tic)/CLOCKS_PER_SEC);

    printf("%%TEST_STARTED%% test6 (List_test)\n");
    tic=clock();
    test_list_c_remove();
    toc=clock();
    printf("%%TEST_FINISHED%% time=%.6f test6 (List_test) \n",(double)(toc-tic)/CLOCKS_PER_SEC);
    
    printf("%%TEST_STARTED%% test6 (List_test)\n");
    tic=clock();
    test_d_list_pop();
    toc=clock();
    printf("%%TEST_FINISHED%% time=%.6f test6 (List_test) \n",(double)(toc-tic)/CLOCKS_PER_SEC);
    
    printf("%%TEST_STARTED%% test6 (List_test)\n");
    tic=clock();
    test_d_list_pop();
    toc=clock();
    printf("%%TEST_FINISHED%% time=%.6f test6 (List_test) \n",(double)(toc-tic)/CLOCKS_PER_SEC);
    
    main_toc=clock();
    printf("%%SUITE_FINISHED%% time=%.6f\n",(double)(main_toc-main_tic)/CLOCKS_PER_SEC);

    return (EXIT_SUCCESS);
}
