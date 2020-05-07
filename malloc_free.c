#include<stdio.h>
#include<stddef.h>
#include<unistd.h>

struct mb{
  size_t size;
  int fr;
  struct mb *next;
  
};

char memory[10000];
struct mb *list = (void*)memory;

void init()
{
    list->size = 10000-sizeof(struct mb);
    list->fr=1;
    list->next= NULL;
}

void split(struct mb *c,size_t si)
{
    struct mb *new=(void *)((void*)c + si + sizeof(struct mb));
    new->size= c->size - si - sizeof(struct mb);
    new->fr=1;
    new->next = c->next;
    
    c->size=si;
    c->fr=0;
    c->next = new->next;
    
}

void *mallocn(size_t bytes)
{
    struct mb *curr,*prev; void *result;
    
    if(!(list->size))
    {
        init();
    }
    
    curr=list;
    
    while((curr->size < bytes) || (curr->fr == 0) || (curr->next!=NULL))
    {
        prev=curr;
        curr=curr->next;
    }
    
    if(curr->size==bytes)
    {
        result = (void*)(++curr);
        return result;
    }
    
    else if(curr->size>(bytes + sizeof(struct mb)))
    {
        split(curr,bytes);
        result = (void*)(++curr);
        return result;
    }
    
    else
    {
        printf("\n NO memory");
        return NULL;
    }
}

void merge()
{
    struct mb *curr,*prev;
    curr=list;
    while(curr->next!=NULL)
    {
        if(curr->next->fr && curr->fr)
        {
            curr->size+=curr->next->size + sizeof(struct mb);
            curr->next=curr->next->next;
        }
    
    
    prev=curr;
    curr=curr->next;
    }
}

void freen(struct mb **ptr)
{
    if(*ptr>=(void*)memory && *ptr<(void*)(memory+10000))
    {
        struct mb *curr=*ptr;
        --curr;
       curr->fr =1;
       merge();
       *ptr=NULL;
    }
    else
    	printf("\n Invalid Pointer! \n");

}

int main()
{
    int *p = (int *)mallocn(100*sizeof(int));
    printf("\n %p",p);
    
    freen(&p);
    if(p==NULL)
        printf("\n FREED!!");
    return 0;
}