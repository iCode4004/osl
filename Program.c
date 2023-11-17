Assignment 1
Program:
ans='y'
until [ $ans = 'n' ]
do
echo "********MENU*********"
echo "1:creat database"
echo "2:view database"
echo "3:insert record"
echo "4:search record"
echo "5:modify record"
echo "6:delete record"
echo "ENTER YOUR CHOICE"
read ch
case "$ch" in
1)
echo "enter file name"
read fname
echo "enter the database name"
read db
echo "enter fields"
read f1
read f2
printf "\t%s" $db >> $fname
printf "\n %s\t%s \n" $f1 $f2 >> $fname
echo "record created"
;;
2)
echo "enter file name"read fname
if [ -e $fname ]
then
3)
elseficat $fname
;;
echo "file does not exits"
echo "enter file name"
read fname
echo "how many entries you want to insert"
read n
while [ $n -gt 0 ]
do
echo "enter field value"
read f1
read f2
n=`expr $n - 1`
printf "\n %s\t%s \n" $f1 $f2 >> $fname
done
echo "record inserted"
;;
4)echo "enter file name"
read fname
if [ -e $fname ]
then
echo "enter rollno to be search"
read rno
grep "$rno" "$fname"
ans=$?
if [ $ans -eq 0 ]
then
echo "record found"
#grep $rno $fname
else
echo "record not found"
fi
else
echo "file does not exit"
fi
;;
5)
echo "enter file name"
read fname
if [ -e $fname ]
then
echo "enter roll no to be modify"
read rno
grep "$rno" "$fname"
ans=$?
if [ $ans -eq 0 ]
then
echo "record found"
grep -v "$rno" "$fname" > temp.data
echo "enter name"
read fname
echo "$rno" "$fname" >> temp1.data
sort temp.data > temp1.data
rm temp.data
rm $fname
mv temp1.data "$fname"
echo "record modify"
else
echo "record not found"
else
echo”file does not exists”
fi
;;
6)
echo "enter file name"
read fname
if [ -e $fname ]
then
echo "enter roll no to be deleted"
read rno
grep "$rno" "$fname"
ans=$?
if [ $ans -eq 0 ]
then
echo "record found"
grep -v "$rno" "$fname" > temp.data
rm $fname
mv temp.data "$fname"
echo "record deleted"
else
echo "record not found"
fi
else
echo "file does not exists"
fi
;;
esac
echo "do u want to continue"
read ans
done
Output: user@ubuntu:~$ sh ass1.sh
********MENU*********
1:create database
2:view database
3:insert record
4:search record
5:modify record
6:delete record
ENTER YOUR CHOICE
1
enter file name
bb.txt
enter the database name
student
enter fields
rollno
name
record created
do u want to continue
y
********MENU*********
1:creat database
2:view database
3:insert record
4:search record
5:modify record
6:delete record
ENTER YOUR CHOICE
3
enter file name
bb.txt
how many entries you want to insert
2
enter field value
1
ashu
enter field value
2
priya
record inserted
do u want to continue
y
********MENU*********
1:creat database
2:view database
3:insert record
4:search record
5:modify record
6:delete record
ENTER YOUR CHOICE
2
enter file name
bb.txt
student
rollno name
1
ashu
2
priya
do u want to continue
y
********MENU*********
1:creat database
2:view database
3:insert record
4:search record
5:modify record
6:delete record
ENTER YOUR CHOICE
4
enter file name
bb.txt
enter rollno to be search
1
1
ashu
record found
do u want to continue
y
********MENU*********
1:creat database
2:view database
3:insert record
4:search record
5:modify record
6:delete record
ENTER YOUR CHOICE
5
enter file name
bb.txt
enter roll no to be modify
2
2
priya
record found
enter name
priyanka
record modify
do u want to continue
y
********MENU*********
1:creat database
2:view database
3:insert record
4:search record
5:modify record
6:delete record
ENTER YOUR CHOICE
6
enter file name
bb.txt
enter roll no to be deleted
2
2
priya
record found
record deleted
do u want to continue
n
Assignment no.2
Program:
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void quicksort(int a[],int,int);
void merge(int a[], int low, int mid, int high);
void divide(int a[], int low, int high);
int main()
{
int a[20],n,i;
pid_t pid;
printf("Enter size of the array: ");
scanf("%d",&n);
printf("Enter %d elements: ",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
pid = fork();
switch(pid)
{
case 0:
printf ("I am child, my ID: %d", getpid() );
printf ("\nI am child, my Parent id: %d \n",getppid() );
quicksort(a,0,n-1);
break;
case -1:
printf ("The child process has not created");
break;
default:
printf ("\nI am in default , process id: %d ",getpid());
divide( a, 0, n-1);
sleep(3);
break;
} // switch case closed
printf("\n Sorted elements:\n ");
for(i=0;i<n;i++)
printf(" \t %d",a[i]);
return 0;
}
void divide(int a[], int low, int high)
{
if(low<high) // The array has atleast 2 elements
{
int mid = (low+high)/2;
divide(a, low, mid); // Recursion chain to sort first half of the array
divide(a, mid+1, high); // Recursion chain to sort second half of the array
merge(a, low, mid, high);
}
}
void merge(int a[], int low, int mid, int high)
{
int i, j, k, m = mid-low+1, n = high-mid;
int first_half[m], second_half[n];
for(i=0; i<m; i++) // Extract first half (already sorted)
first_half[i] = a[low+i];
for(i=0; i<n; i++) // Extract second half (already sorted)
second_half[i] = a[mid+i+1];
i = j = 0;
k = low;
while(i<m || j<n) // Merge the two halves
{
if(i >= m)
{
a[k++] = second_half[j++];
continue;
}
if(j >= n)
{
a[k++] = first_half[i++];
continue;
}
if(first_half[i] < second_half[j])
a[k++] = first_half[i++];
else
a[k++] = second_half[j++];
}
}
void quicksort(int a[],int first,int last)
{
int pivot,j,temp,i;
if(first<last){
pivot=first;
i=first;
j=last;
while(i<j){
while(a[i]<=a[pivot]&&i<last)
i++;
while(a[j]>a[pivot])
j--;
if(i<j){
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
temp=a[pivot];
a[pivot]=a[j];
a[j]=temp;
quicksort(a,first,j-1);
quicksort(a,j+1,last);
}
}
Output
it@ubuntu:~/osl-ass$ cc ass2.c -o ass2
it@ubuntu:~/osl-ass$ ./ass2
Enter size of the array: 5
Enter 5 elements: 88 33 99 11 22
I am child, my ID: 1936
I am child, my Parent id: 1935
Sorted elements:
11
22
33
88
99
I am in default , process id: 1935
Sorted elements:
11
22
33
88
99
Assignment no.3
Program:
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
int val[10],ele;
pid_t pid;
char* cval[10];
//char *newenviron[] = { NULL };
int i,j,n,temp;
printf("\nEnter the size for an array: ");
scanf("%d",&n);
printf("\nEnter %d elements : ", n);
for(i=0;i<n;i++)
scanf("%d",&val[i]);
printf("\nEntered elements are: ");
for(i=0;i<n;i++)
printf("\t%d",val[i]);
for(i=1;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(val[j]>val[j+1])
{
temp=val[j];
val[j]=val[j+1];val[j+1]=temp;
}
}
}
printf("\nSorted elements are: ");
for(i=0;i<n;i++)
printf("\t%d",val[i]);
printf("\nEnter element to search: ");
scanf("%d",&ele);
val[i] = ele;
for (i=0; i < n+1; i++)
{
char a[sizeof(int)];
snprintf(a, sizeof(int), "%d", val[i]);
cval[i] = malloc(sizeof(a));
strcpy(cval[i], a);
}
cval[i]=NULL;
pid=fork();
if(pid==0)
{
execv(argv[1], cval);
perror("Error in execve call...");
}}
//ass3b.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[],char *en[])
{
int i,j,c,ele;
int arr[argc];
for (j = 0; j < argc-1; j++)
{
int n=atoi(argv[j]);
arr[j]=n;
}
ele=atoi(argv[j]);
i=0;
j=argc-1;
c=(i+j)/2;
while(arr[c]!=ele && i<=j)
{
if(ele > arr[c])
i = c+1;
else
j = c-1;
}
if(i<=j)
else
c = (i+j)/2;
printf("\nElement Found in the given Array...!!!\n");
printf("\nElement Not Found in the given Array...!!!\n");
}
Output:
it@ubuntu:~/osl-ass$ cc ass3a.c -o ass3a
it@ubuntu:~/osl-ass$ cc ass3b.c -o ass3b
it@ubuntu:~/osl-ass$ ./ass3a ./ass3b
Enter the size for an array: 5
Enter 5 elements : 7 8 1 2 4
Entered elements are: 7
8
1
2
4
Sorted elements are: 1
2
4
7
8
Enter element to search: 2
it@ubuntu:~/osl-ass$
Element Found in the given Array...!!!
Assignment no.4
Program: sjf.c
#include <stdio.h>
#define max 10
int main()
{
 int n,bt[max],wt[max],p[max],tat[max];
 float awt=0,atat=0;
 printf("Enter the number of processes: ");
 scanf("%d",&n);
 printf("Enter the process number and its burst time: ");
 for(int i=0;i<n;i++)
 {
 printf("\nprocess: ");
 scanf("%d %d",&p[i],&bt[i]);
 }
 printf("\nBefore sorting\n ");
 for(int i=0;i<n;i++)
 {
 printf("p%d - burst time: %d\n",p[i],bt[i]);
 }
 for(int i=0;i<n-1;i++)
 {
 for(int j=0;j<n-i-1;j++)
 {
 if(bt[j]>bt[j+1])
 {
 int temp = bt[j];
 bt[j] = bt[j+1];
 bt[j+1] = temp;
 int temp1 = p[i];
 p[i]= p[i+1];
 p[i+1] = temp1;
 }
 }
 }
 printf("\nAfter sorting\n ");
 for(int i=0;i<n;i++)
 {
 printf("p%d - burst time: %d\n",p[i],bt[i]);
 }
 printf("PR\tBT\tWT\tTAT\n");
 for(int i=0;i<n;i++)
 {
 wt[i]=0;
 tat[i]=0;
 for(int j=0;j<i;j++)
 {
 wt[i]=wt[i]+bt[j];
 }
 tat[i] = wt[i] + bt[i];
 awt = awt + wt[i];
 atat = atat + tat[i];
 printf("%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
 }
 awt = awt/n;
 atat = atat/n;
 printf("\nAverage waiting time: %f",awt);
 printf("\nAverage turnaround time: %f",atat);
}
round robin.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100
struct process
{
int process_id;
int arrival_time;
int burst_time;
int waiting_time;
int turn_around_time;
int remaining_time;
};
int queue[N];
int front = 0, rear = 0;
struct process proc[N];
void push(int process_id)
{
queue[rear] = process_id;
rear = (rear+1)%N;
}
int pop()
{
}
if(front == rear)
return -1;
int return_position = queue[front];
front = (front +1)%N;
return return_position;
int main()
{
float wait_time_total = 0.0, tat = 0.0;
int n,time_quantum;
printf("Enter the number of processes: ");
scanf("%d", &n);
for(int i=0; i<n; i++)
{
printf("Enter the arrival time for the process%d: ",i+1);
scanf("%d", &proc[i].arrival_time);
printf("Enter the burst time for the process%d: ",i+1);
scanf("%d", &proc[i].burst_time);
proc[i].process_id = i+1;
proc[i].remaining_time = proc[i].burst_time;
}
printf("Enter time quantum: ");
scanf("%d",&time_quantum);
int time=0;
int processes_left=n;
int position=-1;
int local_time=0;
for(int j=0; j<n; j++)
if(proc[j].arrival_time == time)
push(j);
while(processes_left)
{
if(local_time == 0)
{
if(position != -1)
push(position);
}
position = pop();
for(int i=0; i<n; i++)
{
if(proc[i].arrival_time > time)
continue;
if(i==position)
continue;
if(proc[i].remaining_time == 0)
continue;
}
proc[i].waiting_time++;
proc[i].turn_around_time++;
if(position != -1)
{
}
else
}
proc[position].remaining_time--;
proc[position].turn_around_time++;
if(proc[position].remaining_time == 0)
{
processes_left--;
local_time = -1;
position = -1;
}
local_time = -1;
time++;
local_time = (local_time +1)%time_quantum;
for(int j=0; j<n; j++)
if(proc[j].arrival_time == time)
push(j);
printf("\n");
printf("Process\t\tArrival Time\tBurst Time\tWaiting time\tTurn around time\n");
for(int i=0; i<n; i++)
{
printf("%d\t\t%d\t\t", proc[i].process_id, proc[i].arrival_time);
printf("%d\t\t%d\t\t%d\n", proc[i].burst_time, proc[i].waiting_time,
proc[i].turn_around_time);
}
tat += proc[i].turn_around_time;
wait_time_total += proc[i].waiting_time;
tat = tat/(1.0*n);
wait_time_total = wait_time_total/(1.0*n);
printf("\nAverage waiting time : %f",wait_time_total);
printf("\nAverage turn around time : %f\n", tat);
}
Assignment no.5
Program:
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define RAND_DIVISOR 100000000
#define TRUE 1
#define BUFFER_SIZE 5
typedef int buffer_item;
pthread_mutex_t mutex;
sem_t full, empty;
buffer_item buffer[BUFFER_SIZE];
int counter;
pthread_t tid;
//Thread ID
pthread_attr_t attr; //Set of thread attributes
void *producer(void *param); /* the producer thread */
void *consumer(void *param); /* the consumer thread */
void initializeData() {
/* Create the mutex lock */
pthread_mutex_init(&mutex, NULL);
/* Create the full semaphore and initialize to 0 */
sem_init(&full, 0, 0);
/* Create the empty semaphore and initialize to BUFFER_SIZE */
sem_init(&empty, 0, BUFFER_SIZE);
/* Get the default attributes */
pthread_attr_init(&attr);
/* init buffer */
counter = 0;
}
/* Producer Thread */
void *producer(void *param)
{buffer_item item;
while(TRUE) {
/* sleep for a random period of time */
int rNum = rand() / RAND_DIVISOR;
sleep(rNum);
/* generate a random number */
item = rand();
/* acquire the empty lock */
sem_wait(&empty);
/* acquire the mutex lock */
pthread_mutex_lock(&mutex);
if(insert_item(item)) {
fprintf(stderr, " Producer report error condition\n");
}
else {
printf("producer produced %d\n", item);
}
/* release the mutex lock */
pthread_mutex_unlock(&mutex);
/* signal full */
sem_post(&full);
}
}
/* Consumer Thread */
void *consumer(void *param)
{buffer_item item;
while(TRUE) {
/* sleep for a random period of time */
int rNum = rand() / RAND_DIVISOR;
sleep(rNum);
/* aquire the full lock */
sem_wait(&full);
/* aquire the mutex lock */
pthread_mutex_lock(&mutex);
if(remove_item(&item)) {
fprintf(stderr, "Consumer report error condition\n");
}
else {
printf("consumer consumed %d\n", item);
}
/* release the mutex lock */
pthread_mutex_unlock(&mutex);
/* signal empty */
sem_post(&empty);
}
}
/* Add an item to the buffer */
int insert_item(buffer_item item)
{
/* When the buffer is not full add the item
and increment the counter*/
if(counter < BUFFER_SIZE)
{buffer[counter] = item;
counter++;
return 0;
}
else { /* Error the buffer is full */
return -1;
}}
/* Remove an item from the buffer */
int remove_item(buffer_item *item) {
/* When the buffer is not empty remove the item
and decrement the counter */
if(counter > 0) {
*item = buffer[(counter-1)];
counter--;
return 0;
}
else { /* Error buffer empty */
return -1;
}
}
int main(int argc, char *argv[])
{int i;
int mainSleepTime = 10; /* Time in seconds for main to sleep */
int numProd = 10; /* Number of producer threads */
int numCons = 10; /* Number of consumer threads */
/* Initialize the app */
initializeData();
/* Create the producer threads */
for(i = 0; i < numProd; i++) {
/* Create the thread */
pthread_create(&tid,&attr,producer,NULL);
}
/* Create the consumer threads */
for(i = 0; i < numCons; i++) {
/* Create the thread */
pthread_create(&tid,&attr,consumer,NULL);
}
/* Sleep for the specified amount of time in milliseconds */
sleep(mainSleepTime);
/* Exit the program */
printf("Exit the program\n");
exit(0);
}
Output:
it@ubuntu:~/osl-ass$ cc ass4.c -o ass4 -lpthread
it@ubuntu:~/osl-ass$ ./ass4
producer produced 35005211
consumer consumed 35005211
producer produced 1726956429
consumer consumed 1726956429
producer produced 278722862
consumer consumed 278722862
producer produced 468703135
producer produced 1801979802
producer produced 635723058
producer produced 1125898167
Exit the program
Assignment no.6
Program:
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
void * reader(void *) ;
void *writer (void *) ;
sem_t wsem,mutex ;
int readcount=0 ;
main()
{
int a=1,b=1; system("clear");
sem_init(&wsem,0,1) ;
sem_init(&mutex,0,1) ;
pthread_t r,w,r1,w1 ;
pthread_create(&r,NULL,reader,(void *)a);
a++;
pthread_create(&w1,NULL,writer,(void *)b);
b++;
pthread_create(&r1,NULL,reader,(void *)a);
pthread_create(&w,NULL,writer,(void *)b);
pthread_join(r,NULL);
pthread_join(w1,NULL);
pthread_join(r1,NULL);
pthread_join(w,NULL) ;
printf("main terminated\n");
}
void * reader(void * arg)
{
int c=(int)arg ;
printf("\nreader %d is created",c);
sleep(1);
sem_wait(&mutex) ;
readcount++;
if(readcount==1)
sem_wait(&wsem) ;
sem_post(&mutex) ;
/*Critcal Section */
printf("\n\nreader %d is reading\n ",c);
sleep(1) ;
printf("\nreader%d finished reading\n",c);
/* critical section completd */
sem_wait(&mutex) ;
readcount-- ;
if(readcount==0)
sem_post(&wsem) ;
sem_post(&mutex) ;
}
void * writer(void * arg)
{
int c=(int)arg ;
printf("\nwriter %d is created",c);
sleep(1);
sem_wait(&wsem) ;
printf("\nwriter %d is writing\n",c) ;
sleep(1);
printf("\nwriter%d finished writing\n",c);
sem_post(&wsem) ;
}
/*output :
it@ubuntu:~$ cc readerpriority.c -o read -lpthreadit@ubuntu:~$ ./read
writer 1 is created
reader 1 is created
reader 2 is created
writer 2 is created
writer 1 is writing
writer1 finished writing
reader 1 is reading
reader 2 is reading
reader1 finished reading
reader2 finished reading
writer 2 is writing
writer2 finished writing
main terminated
Assignment no.7
PROGRAM:
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int need[100][100],allot[100][100],max[100][100],available[100];
bool isFinished[100];
int sequence[100];
void isSafe(int N,int M)
{
int i,j,work[100],count=0;
for(i=0;i<M;i++)
work[i]=available[i];
for(i=0;i<100;i++)
isFinished[i]=false;
while(count<N)
{
bool canAllot=false;
for(i=0;i<N;i++)
{
if(isFinished[i]==false)
{
for(j=0;j<M;j++)
{
if(work[j]<need[i][j])
{
break;
}
}
if(j==M)
{
for(j=0;j<M;j++)
{
work[j]+=allot[i][j];
}
}
}
sequence[count++]=i;
isFinished[i]=true;
canAllot=true;
}
if(canAllot==false)
{
}
}
printf("System Is not safe\n");
return ;
printf("System is in safe state\n");
}
printf("Safe sequence :");
for(i=0;i<N;i++)
printf("%d ",sequence[i]);
printf("\n");
int main()
{
int i,j,N,M;
printf("Enter the number of process and resources :");
scanf("%d %d",&N,&M);
printf("Enter the available resources :\n");
for(i=0;i<M;i++)
scanf("%d",&available[i]);
printf("Enter the Allocation Matrix :\n");
for(i=0;i<N;i++)
for(j=0;j<M;j++)
scanf("%d",&allot[i][j]);
printf("Enter the matrix for maximum demand of each process :\n");
for(i=0;i<N;i++)
for(j=0;j<M;j++)
scanf("%d",&max[i][j]);
//calculation of need matrix
for(i=0;i<N;i++)
for(j=0;j<M;j++)
need[i][j]=max[i][j]-allot[i][j];
isSafe(N,M);
int indx,arr[100];
printf("Enter the process no for resource request :");
scanf("%d",&indx);
printf("Enter the requested instances of Each :");
for(i=0;i<M;i++)
scanf("%d",&arr[i]);
for(i=0;i<M;i++)
{
if( need[indx][i]<arr[i] || arr[i]>available[i] )
{
printf("Cannot request\n");
break;
}
}
if(i==M)
{
for(i=0;i<M;i++)
{
allot[indx][i]+=arr[i];
available[i]-=arr[i];
need[indx][i]-=arr[i];
}
}
isSafe(N,M);
}
Assignment no.8
program:
/*
FIFO Page Replacement Algorithm
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
int pointer;
int faults ,hits;
void print(int frame_size,int frame[])
{
int i;
//printf("Printing the Frames: ");
for(i=0;i<frame_size;i++)
{
if(frame[i]==-1)
printf("- ");
else
printf("%d ",frame[i]);
}
}
printf("\n");
void add_reference(int frame_size,int frame[], int reference)
{
int i;
bool alloted = false;
for(i=0;i<frame_size;i++)
{
if(frame[i]==reference)
{
alloted = true;
printf(" Hit for %d | ", reference);
hits++;
break;
}
else if(frame[i]==-1)
{
alloted = true;
frame[i] = reference;
printf("Fault for %d | ", reference);
faults++;
break;
}
if(alloted == false)
{
faults++;
printf("Fault for %d | ", reference);
frame[pointer] = reference;
pointer = (pointer+1)%frame_size;
}
print(frame_size, frame);
int main()
{
int frame_size,i,number_of_references;
printf("Enter frame size: ");
scanf("%d",&frame_size);
int frame[frame_size];
for(i=0;i<frame_size;i++)
{
frame[i] = -1;
}
print(frame_size,frame);
printf("Enter the number of references: ");
scanf("%d",&number_of_references);
int reference[number_of_references];
}
for(i=0;i<number_of_references;i++)
{
scanf("%d",&reference[i]);
add_reference(frame_size,frame,reference[i]);
}
printf("\nNumber of faults: %d \nNumber of hits: %d\n",faults,hits );
/*
Least Recently Used Page Replacement Algorithm
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
int pointer;
int faults ,hits;
void print(int frame_size,int frame[])
{
int i;
//printf("Printing the Frames: ");
for(i=0;i<frame_size;i++)
{
if(frame[i]==-1)
printf("- ");
else
printf("%d ",frame[i]);
}
}
printf("\n");
int predict(int reference_length, int references[], int page_no ,int frame_size,int frame[], int start)
{
int pos = -1, farthest = start, i;
for(i=0;i<frame_size;i++)
{
int j;
for(j=start-1;j>=0;j--)
{
if(frame[i]==references[j])
{
if(j<farthest)
{
farthest=j;
pos=i;
}
break;
}
}
if(j==page_no)
return i;
}
if(pos == -1)
return 0;
else
return pos;
void add_reference(int frame_size,int frame[], int reference, int current_position,int
reference_length,
int references[])
{
int i;
bool allocated=false;
for(i=0;i<frame_size;i++)
{
if(frame[i]==reference)
{
printf(" Hit for %d | ", reference);
hits++;
allocated = true;
break;
}
else if(frame[i]==-1)
{
frame[i] = reference;
printf("Fault for %d | ", reference);
faults++;
allocated = true;
break;
}
}
if(allocated==false)
{
int j =
predict(reference_length,references,current_position,frame_size,frame,current_position+1);
frame[j] = reference;
printf("Fault for %d | ", reference);
faults++;
}
}
print(frame_size, frame);
int main()
{
int frame_size,i,number_of_references;
printf("Enter frame size: ");
scanf("%d",&frame_size);
int frame[frame_size];
for(i=0;i<frame_size;i++)
{
frame[i] = -1;
}
print(frame_size,frame);
printf("Enter the number of references: ");
scanf("%d",&number_of_references);
int reference[number_of_references];
for(i=0;i<number_of_references;i++)
{
scanf("%d",&reference[i]);
add_reference(frame_size,frame,reference[i],i,number_of_references,reference);
}
printf("\nNumber of faults: %d \nNumber of hits: %d\n",faults,hits );
}
/*
Optimal Page Replacement Algorithm
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
int pointer;
int faults ,hits;
void print(int frame_size,int frame[])
{
int i;
//printf("Printing the Frames: ");
for(i=0;i<frame_size;i++)
{
if(frame[i]==-1)
printf("- ");
else
printf("%d ",frame[i]);
}
printf("\n");
int predict(int reference_length, int references[], int page_no ,int frame_size,int frame[], int start)
{
int pos = -1, farthest = start, i;
for(i=0;i<frame_size;i++)
{
int j;
for(j=start;j<reference_length;j++)
{
if(frame[i]==references[j])
{
if(j>farthest)
{
farthest=j;
pos=i;
}
break;
}
}
if(j==page_no)
return i;
}
if(pos == -1)
return 0;
else
return pos;
}
void add_reference(int frame_size,int frame[], int reference, int current_position,int
reference_length,
int references[])
{
int i;
bool allocated=false;
for(i=0;i<frame_size;i++)
{
if(frame[i]==reference)
{
printf(" Hit for %d | ", reference);
hits++;
allocated = true;
break;
}
else if(frame[i]==-1)
{
frame[i] = reference;
printf("Fault for %d | ", reference);
faults++;
allocated = true;
break;
}
}
if(allocated==false)
{
int j =
predict(reference_length,references,current_position,frame_size,frame,current_position+1);
frame[j] = reference;
printf("Fault for %d | ", reference);
faults++;
}
}
print(frame_size, frame);
int main()
{
int frame_size,i,number_of_references;
printf("Enter frame size: ");
scanf("%d",&frame_size);
int frame[frame_size];
for(i=0;i<frame_size;i++)
{
frame[i] = -1;
}
print(frame_size,frame);
printf("Enter the number of references: ");
scanf("%d",&number_of_references);
int reference[number_of_references];
for(i=0;i<number_of_references;i++)
{
scanf("%d",&reference[i]);
add_reference(frame_size,frame,reference[i],i,number_of_references,reference);
}
printf("\nNumber of faults: %d \nNumber of hits: %d\n",faults,hits );
}
Assignment no.9
Program:
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main()
{
int fd,fd1;
char * myfifo = "myfifo";
char buf[1024];
int words = 1, len = 0, i=0;
FILE *fp;
char * myfifo1 = "myfifo1";
mkfifo(myfifo1, 0777);
fd = open(myfifo, O_RDONLY);
read(fd, buf, 1024);
printf("First Message Received: \n%s", buf);
while(buf[i]!='\0')
{
while(buf[i]==' ')//no.of spaces=no.of words
{
words++;
i++;
}
i++;
}
printf("\nTotal words = %d \n",words);
fp = fopen("test.txt", "w+");
fprintf(fp, "Total words = %d \n",words);
fclose(fp);
close(fd);
unlink(myfifo);
fd1 = open(myfifo1, O_WRONLY);
write(fd1, "Your message received...\n", sizeof("Your message received...\n"));
close(fd1);
return 0;
}
//Inter process communication in Linux using FIFO
#include<stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
int fd,fd1;
char * myfifo = "myfifo";
char * myfifo1 = "myfifo1";
char buf[1024];
mkfifo(myfifo, 0666);
mkfifo(myfifo1, 0777);
fd = open(myfifo, O_WRONLY);
write(fd, "Hello friends... \nWelcome hi...", sizeof("Hello friends... \nWelcome hi..."));
close(fd);
unlink(myfifo);
fd1 = open(myfifo1, O_RDONLY);
read(fd1, buf, sizeof(buf));
printf("%s",buf);
unlink(myfifo1);
close(fd1);
return 0;}
Output:

Assignment no.10
program:
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#define SHMSZ
27
main()
{
int shmid;
key_t key;
char *shm, *s;
/*
* We need to get the segment named
* "5678", created by the server.
*/
key = 5678;
/*
* Locate the segment.
*/
if ((shmid = shmget(key, SHMSZ, 0666)) < 0)
{perror("shmget");
exit(1);
}
/*
* Now we attach the segment to our data space.
*/
if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
{perror("shmat");
exit(1);
}
/*
* Now read what the server put in the memory.*/
for (s = shm; *s != NULL; s++)
putchar(*s);
putchar('\n');
/*
* Finally, change the first character of the
* segment to '*', indicating we have read
* the segment.
*/
*shm = '*';
exit(0);
}
//server.c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#define SHMSZ
27
main()
{
char c;
int shmid;
key_t key;
char *shm, *s;
/*
* We'll name our shared memory segment
* "5678".
*/
key= 5678;
/*
* Create the segment.
*/
if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
{perror("shmget");
exit(1);
}
/*
* Now we attach the segment to our data space.
*/
if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
{perror("shmat");
exit(1);
}
/*
* Now put some things into the memory for the
* other process to read. */
s = shm;
for (c = 'a'; c <= 'd'; c++)
*s++ = c;
*s=NULL;
/* Finally, we wait until the other process
* changes the first character of our memory
* to '*', indicating that it has read what
* we put there.
*/
while (*shm != '*')
sleep(1);
exit(0);}
}
Assignment no.11
Program:
Disk Scheduling
C-Look
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
struct request
{
int request_track_number;
bool visited;
};
int main()
{
int i,no_of_requests,initial_head,limit,j,choice,previous_head;
printf("Enter the number of requests: ");
scanf("%d",&no_of_requests);
struct request req[no_of_requests];
printf("Enter the requests: ");
for (i = 0; i < no_of_requests; ++i)
{
scanf("%d",&req[i].request_track_number);
req[i].visited = false;
}
printf("Enter initial position of R/W head: ");
scanf("%d",&initial_head);
printf("Enter the previous position of R/W head: ");
scanf("%d",&previous_head);
printf("Enter the cylinder size: ");
scanf("%d",&limit);
if(previous_head - initial_head > 0 )
{
choice = 2;
}
else
choice = 1;
//scanf("%d",&choice);
int seek_time=0;
printf("%d -> ",initial_head );
int cp_initial_head = initial_head;
if(choice == 1)
{
initial_head);
for(i=initial_head;i<limit;i++)
{
for(j=0;j<no_of_requests;j++)
{
if(req[j].request_track_number == i && req[j].visited == false)
{
printf("%d -> ", req[j].request_track_number);
req[j].visited = true;
seek_time += abs(req[j].request_track_number -
}
initial_head);
initial_head = req[j].request_track_number;
}
}
initial_head = 0;
for(i=0;i<cp_initial_head;i++)
{
for(j=0;j<no_of_requests;j++)
{
if(req[j].request_track_number == i && req[j].visited == false)
{
printf("%d -> ", req[j].request_track_number);
req[j].visited = true;
seek_time += abs(req[j].request_track_number -
}
}
printf("\n");
}
initial_head = req[j].request_track_number;
}
else if(choice == 2)
{
for(i=initial_head;i>=0;i--)
{
for(j=0;j<no_of_requests;j++)
{
if(req[j].request_track_number == i && req[j].visited == false)
{
printf("%d -> ", req[j].request_track_number);
req[j].visited = true;
seek_time += abs(req[j].request_track_number -
initial_head);
initial_head = req[j].request_track_number;4
}
initial_head);
}
}
initial_head = limit-1;
for(i=limit;i>cp_initial_head;i--)
{
for(j=0;j<no_of_requests;j++)
{
if(req[j].request_track_number == i && req[j].visited == false)
{
printf("%d -> ", req[j].request_track_number);
req[j].visited = true;
seek_time += abs(req[j].request_track_number -
}
}
initial_head = req[j].request_track_number;
}
printf("\n");
}
/*
}
printf("Seek Time: %d\n", seek_time);
Disk Scheduling
Scan
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
struct request
{
int request_track_number;
bool visited;
};
int main()
{
int i,no_of_requests,initial_head,limit,j,choice,previous_head;
printf("Enter the number of requests: ");
scanf("%d",&no_of_requests);
struct request req[no_of_requests];
printf("Enter the requests: ");
for (i = 0; i < no_of_requests; ++i)
{
scanf("%d",&req[i].request_track_number);
req[i].visited = false;
}
printf("Enter initial position of R/W head: ");
scanf("%d",&initial_head);
printf("Enter the previous position of R/W head: ");
scanf("%d",&previous_head);
printf("Enter the cylinder size: ");
scanf("%d",&limit);
if(previous_head - initial_head > 0 )
{
choice = 2;
}
else
choice = 1;
//scanf("%d",&choice);
int seek_time=0;
printf("%d -> ",initial_head );
if(choice == 1)
{
for(i=initial_head;i<limit;i++)
{
for(j=0;j<no_of_requests;j++)
{
if(req[j].request_track_number == i && req[j].visited == false)
{
printf("%d -> ", req[j].request_track_number);
req[j].visited = true;
seek_time += abs(req[j].request_track_number -
initial_head);
initial_head = req[j].request_track_number;
}
}
}
printf("%d -> ", limit-1);
seek_time += abs(limit-1 – initial_head);
initial_head);
initial_head = limit-1;
for(i=initial_head;i>=0;i--)
{
for(j=0;j<no_of_requests;j++)
{
if(req[j].request_track_number == i && req[j].visited == false)
{
printf("%d -> ", req[j].request_track_number);
req[j].visited = true;
seek_time += abs(req[j].request_track_number -
}
initial_head = req[j].request_track_number;
}
}
seek_time += abs(initial_head - 0);
printf("0 \n");
}
else if(choice == 2)
{
for(i=initial_head;i>=0;i--)
{
for(j=0;j<no_of_requests;j++)
{
if(req[j].request_track_number == i && req[j].visited == false)
{
printf("%d -> ", req[j].request_track_number);
req[j].visited = true;
seek_time += abs(req[j].request_track_number -
initial_head);
initial_head = req[j].request_track_number;
}
}
}
printf("%d -> ", 0);
seek_time += abs(0 - initial_head);
initial_head = 0;
for(i=initial_head;i<limit;i++)
{
for(j=0;j<no_of_requests;j++)
{
if(req[j].request_track_number == i && req[j].visited == false)
{
printf("%d -> ", req[j].request_track_number);
req[j].visited = true;
seek_time += abs(req[j].request_track_number -
initial_head);
}
initial_head = req[j].request_track_number;
}
}
seek_time += abs(limit-1 - initial_head );
printf("%d \n", limit-1);
}
printf("Seek Time: %d\n", seek_time);
}
/*
Disk Scheduling
Shortest Seek Time First
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
struct request
{
int request_track_number;
bool visited;
};
int main()
{
int i,no_of_requests,initial_head,limit,j,choice,previous_head;
printf("Enter the number of requests: ");
scanf("%d",&no_of_requests);
struct request req[no_of_requests];
printf("Enter the requests: ");
for (i = 0; i < no_of_requests; ++i)
{
scanf("%d",&req[i].request_track_number);
req[i].visited = false;
}
printf("Enter initial position of R/W head: ");
scanf("%d",&initial_head);
int seek_time=0;
== false)
printf("%d -> ",initial_head );
int n = no_of_requests;
while(n)
{
int min = 1e9;
int min_track_number, position;
for(i=0;i<no_of_requests;i++)
{
if(abs(initial_head - req[i].request_track_number) < min && req[i].visited
{
}
}
}
min = abs(initial_head - req[i].request_track_number);
min_track_number = req[i].request_track_number;
position = i;
}
initial_head = req[position].request_track_number;
req[position].visited = true;
printf("%d ->",min_track_number);
seek_time += min;
n--;
printf("\nSeek Time: %d\n", seek_time);
Assignment no.12
Program:
#include <linux/kernel.h>
asmlinkage long sys_hello(void)
{
printk(“Hello world\n”);
return 0;
}
//Makefile
obj-y := hello.o
//userspace.c
#include
<stdio.h>
#include
<linux/kernel.h>
#include
<sys/syscall.h>
#include <unistd.h>
int main()
{
long int amma = syscall(354);
printf(“System call sys_hello returned %ld\n”,
amma);return 0;
}