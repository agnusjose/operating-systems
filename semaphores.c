#include<stdio.h>
#include<stdlib.h>
int mutex=1,empty=2,full=0;
void producer();
void consumer();
int wait(int);
int signal(int);
void main()
{
int ch;
while(ch!=3)
{
printf("enter choice: 1.Producer 2.Consumer 3.exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
 if(mutex==1&&empty!=0)
 {
 producer();
 printf("item produced\n");
 }
 else
 {
 printf("Buffer full\n");
 }
 break;
}
case 2:
{
 if(mutex==1&&full!=0)
 {
 consumer();
 printf("item consumed\n");
 }
 else
 {
 printf("Buffer empty\n");
 }
 break;
}
case 3:
{
exit(0);
break;
}
}
}
}
int wait(int s)
{
 s--;
 return s;
}
int signal(int s)
{
 s++;
 return s;
}
void producer()
{
 mutex=wait(mutex);
 empty=wait(empty);
 full=signal(full);
 mutex=signal(mutex);
}
void consumer()
{
mutex=wait(mutex);
empty=signal(empty);
full=wait(full);
mutex=signal(mutex);
}

