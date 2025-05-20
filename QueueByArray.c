#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define Que_Size 100
uint16_t QueArr[Que_Size];// Store in bss segment section of the RAM
char Front=-1,Rare=-1; // Store in Data segment section of the RAM

bool IsQueFull(void)
{
  return(Rare == Que_Size-1);    
}

bool IsQueEmpty(void)
{
    return (Front == -1);
}

uint16_t QuePeek(void)
{
    if(!IsQueEmpty())
      return QueArr[Front];
    else
    { printf("\nQueue is Empty\n");
      return 0;
    }        
}

uint16_t QueEnd(void)
{
    if(!IsQueEmpty())
      return QueArr[Rare];
    else
    { printf("Que is Empty");
      return 0;
    }
}

void Enqueu(uint16_t val)
{
    if(!IsQueFull())
    {
        if(Front == -1) Front = 0;
        Rare = Rare+1;
        QueArr[Rare] = val;
    }else
    {
        printf("\nQueue is OverFlow\n");
    }
}

uint16_t Dequeu(void)
{
    uint16_t val=0;
    if(!IsQueEmpty())
    {
        val = QueArr[Front];
        Front = Front+1;
        if(Front>Rare) Front = Rare = -1;
    }else
    {
        printf("\nQueue is Empty\n");
    }
    return val;
}

void ShowQueue(void)
{
    if(IsQueEmpty())
    { printf("Queue is Empty");
      return;
    }
    for(int i=Front;i<=Rare;i++)
     printf("%d\t",QueArr[i]);
}

int main(void)
{
    int choice,n=0; // store in stack part of RAM
    // all functions open in stack
    while(1)
    {
        printf("\n***********Menu*********\n");
        printf("\n Enter Choice:\n1.Enqueu\n2.Dequeue\n3.Show Queue\n4.Peek Queue\n5.End Queue\n6.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter n:");
                scanf("%d",&n);
                Enqueu(n); 
            break;
            
            case 2:
                printf("\n Deque = %d",Dequeu());
            break;
            
            case 3:
                ShowQueue();
            break;
            
            case 4:
                printf("\n Que Peek = %d",QuePeek());
            break;
            
            case 5:
                printf("\n Que End = %d",QueEnd());
            break;
            
            case 6:
                exit(1);
            default:
                printf("\nInvalid Option");
        }  
    }
    return 0;
}
