

//NEEDLE IN THE HAYSTACK

int strStr(char * haystack, char * needle){
    
    int i,j=0;
    
    int ind= -1; //default -> not present
    
    for(i=0;i<strlen(haystack);i++)
    {
        char c = haystack[i];
        if(c==needle[j])
        {
            ind=i;
            j++;
            while(j < strlen(needle))
            {
                char d = haystack[ind+j];
                if(d != needle[j])
                {
                    ind = -1;
                    break;
                }
                j++;
            }
        
        }
        
        j=0;
        
        if(ind != -1)
            break;
    }
    
    return ind;
}

==========================================================================
//MERGE SORTED LL
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void addnode(struct ListNode** head, int d) //add to tail
{
    struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* t = *head;
    new->val = d;
    new->next=NULL;
  
    if(*head==NULL)
    {
        *head=new;
        return;
    }
    while(t->next != NULL)
    {
        t = t->next;
    }
    t->next = new;   
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *t1 = l1, *t2 =l2; //shadow heads
    struct ListNode* new =NULL;
    
    while(t1 != NULL || t2 != NULL)
    {
        if(t2 == NULL)
        {
            addnode(&new,t1->val);
            t1 = t1->next;    
        }
        
        if(t1 == NULL)
        {
            addnode(&new,t2->val); 
            t2 = t2->next;
        }
               
        else
        {
            if(t1->val <= t2->val)
            {
                addnode(&new,t1->val);
                t1 = t1->next;
            }     
            else
           {
                addnode(&new,t2->val); 
                t2 = t2->next; 
           }
        }   
    }
    return new;
}
==========================================================================

//CYCLE

bool hasCycle(struct ListNode *head) {
    int pos;
    struct ListNode *t = head, *fast= NULL;int count=0;
    bool f = false;
    
    
    if(pos == -1)
        return f;
    
    else
    {   
        while(t != NULL)
        {
            if(count == pos)
                fast = t;
            
            if(fast == t)
            {
                f = true;
                break;
            }
            
            count++;
            t = t->next;
        }
    }
    return f;
}

===========================================================================

//DELETE VAL
struct ListNode* removeElements(struct ListNode* head, int val){ 
    struct ListNode* t = head;struct ListNode* temp =NULL, *prev =NULL;
    
    while(t != NULL)
    {
        if(t == head && t->val == val)
        {
            temp = t;
            head = t->next;
            t = head;
            free(temp);
        }
        
        if(t->next->val == val)
        {
            temp = t->next;
            t->next = t->next->next;
            free(temp);
        }

        t = t->next;
    }
    
    return head;
}

===========================================================================

//MIDDLE OF LIST
struct ListNode* middleNode(struct ListNode* head){
    
    struct ListNode *ans=NULL, *temp =head;
    int count =0; //number of nodes
    
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    temp = head; int c=0,mid=0;
    
    if(count%2 ==0)
    {
        mid = count/2;
        mid++;
    }
    else
        mid = (count+1)/2;
    
    while(temp != NULL)
    {
        c++;
        if(c == mid)
            break;
        temp = temp->next;
    }
    ans = temp;
    return ans;

===========================================================================

//1->0->1 to 5 (bin to dec)
int getDecimalValue(struct ListNode* head){
    
    int dec=0;struct ListNode* temp=head;
    int r,c=0;
    
    while(temp !=NULL)
    {
        c++;
        temp = temp->next;
    }
    temp =head;

    for(int i =c-1; i>=0; i--)
    {
        r = temp->val;
        dec+= r*pow(2,i);
        temp = temp->next;
    }
    return dec;
}

===========================================================================

//ARRAY-ROTATE

void rotate(int* nums, int numsSize, int k){
    int temp;
    while(k>0)
    {
        temp = nums[numsSize-1];
        for(int i=0;i<numsSize-1;i++)
        {
            nums[numsSize-1-i] = nums[numsSize-2-i];
        }
        nums[0] = temp;
        k--;
   }
}
===========================================================================

//MOVE ZEROES IN ARRAY

void moveZeroes(int* nums, int numsSize){
    int i,k=0,temp;
    
    for(i=0;i<numsSize;i++)
    {
        if(nums[i] == 0)
        {
            //traverse all elements to left
            k=i;
            while(k < (numsSize-1))
            {
                nums[k] = nums[k+1];
                k++;
            }
            
            nums[numsSize-1]=0; //append 0 to the end
        }
    }
}




===========================================================================

//FIZZBUZZ

char ** fizzBuzz(int n, int* returnSize){
    
    *returnSize=n;
    char **c = (char**)malloc(n * sizeof(char*));
    char buf[11];

    for(int i=0; i<n;i++)
    {
        if((i+1)%3 == 0 && (i+1)%5 == 0) //FB
        {
            sprintf(buf,"%s","FizzBuzz");
        }
        
        else if((i+1)%3 == 0) //F
        {
            sprintf(buf,"%s","Fizz");
        }
        
        else if((i+1)%5 == 0) //B
        {
            sprintf(buf,"%s","Buzz");
        }
        
        else
        {
            int num = (i+1);
            sprintf(buf,"%d",num);
        }
        
        c[i]=malloc(sizeof(buf));
        memcpy(c[i],buf,strlen(buf)+1); //OR last char c[i][strlen(buf)] = '\0';
        memset(buf,"",11);
    }
    return c;
}


===========================================================================
//