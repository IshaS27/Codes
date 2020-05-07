#include <stdio.h>
#include <stdlib.h>


struct circbuf
{	
	int8_t *buffer, *front, *rear;
	int size; //size of the buffer
	int count; //to keep count of all members
};

typedef enum
{
	SUCCESS,
	FAIL,
	EMPTY,
	FULL
}stat;

stat addval(int v)
{
	stat s;
	if(count == size)
	{
		s= FULL;
	}
	
	else
	{
		if(c->rear == (c->buffer) + c->size - 1)
		{
			*(c->rear) = v;
			(count)++;
			(c->rear) = (c->buffer);
			s= SUCCESS;
		}
		else
		{
			*(c->rear) = v;
			(count)++;
			(c->rear)++;
			s= SUCCESS;
		}
	}
	
	return s;
}

stat delval()
{
	stat s; int v;
	
	if(count == 0 || (c->front) == (c->rear))
	{
		s= EMPTY;
	}
	else
	{
		if(c->front == (c->buffer) + c->size - 1)
		{
			(count)--;
			(c->front) = (c->buffer);
			s= SUCCESS;
		}
		else
		{
			v= *(c->front);
			(count)--;
			(c->front)++;
			
			s= SUCCESS;
		}
	}
	
	return s;
	
}


int main()
{
	size = 30;
	count =0;
	buffer = (int8_t*)malloc(size*sizeof(int8_t));
	
	
	
	front = buffer;
	rear= buffer;
	
	stat s = addval(8);
	stat s= delval();
	
	return 0;
}
