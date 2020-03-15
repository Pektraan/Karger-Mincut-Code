#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

using namespace std;
const int NUMB=200;
const unsigned long long NUMOFTIMES=220000000;

struct edge{
    int x;int y;
};

int comparex(const void *a,const void *b){
    struct edge *e1=(struct edge *)a,*e2=(struct edge *)b;
    if((e1->x)==(e2->x)){
        return ((e1->y) - (e2->y));
    }
    else
    return ((e1->x) - (e2->x));
}

void population(int *arraypointers[]){
    //Population begins
    //arraypointers holds pointers to indivarr which in turn holds the data in a row and end is indicated by a -1
    FILE *fp=fopen("kargerMinCut.txt","r");

    int *indivarr=(int *)malloc((sizeof(int)*70));
    int indivarrcount=0;int arraypointerscount=0;
    while(!feof(fp)){
        fscanf(fp,"%d",&indivarr[indivarrcount++]);
        char c;
        c=getc(fp);
        if(c=='\n'){
            indivarr[indivarrcount]=-1;
            arraypointers[arraypointerscount++]=&indivarr[0];
            indivarr=(int *)malloc((sizeof(int)*70));
            indivarrcount=0;
        }
    }
    arraypointers[arraypointerscount++]=&indivarr[0];indivarr[indivarrcount]=-1;

    //Population ends
    return;
}

int counterarrayofstructs(struct edge *arr){
    int i=0;
    while((arr[i].x)!=-1){
        i++;
    }
    return i;
}

struct edge *removeduplicates(struct edge *A,int counter){

        int length=counter;
        if(length==0 || length==1) return A;
        int i=1;
        for(int j=1; j<length; j++)
        {
            if(A[j].y!=A[j-1].y||A[j].x!=A[j-1].x)
            {
                A[i].y=A[j].y;
                A[i].x=A[j].x;
                i++;
            }
        }
        if(i<length){ A[i].y=-1;A[i].x=-1;}
        return A;

}

void populatearray(int *arraypointers[],struct edge *arr){
    int i=0;int j=0;int *indivarr;
    while(i<NUMB){
        indivarr=arraypointers[i];
        int index=1;
        while(indivarr[index]!=-1){
            if(indivarr[0]<indivarr[index]){
                (arr[j].x)=indivarr[0];
                (arr[j++].y)=indivarr[index];
                index++;
            }
            else{
                (arr[j].x)=indivarr[index];
                (arr[j++].y)=indivarr[0];
                index++;
            }
        }
        i++;
    }
    (arr[j].x)=-1;
    (arr[j].y)=-1;

    int temp=counterarrayofstructs(arr);
    qsort(arr,temp,sizeof(struct edge),comparex);
    arr=removeduplicates(arr,temp);
    return;
}

void populateverticescount(struct edge *arr,int verticescount[],int counter){
    int i=1;
    while(i<=counter){
        if(verticescount[arr[i].x]!=1)
            verticescount[arr[i].x]=1;
        else if(verticescount[arr[i].y]!=1)
            verticescount[arr[i].y]=1;
        i++;
    }
    return;
}

int countverticescount(int verticescount[]){
    int i=1;int j=0;
    while(i<=NUMB){
        if(verticescount[i]==1)
            j++;
        i++;
    }
    return j;
}

void makesame(struct edge *arr,int temp1,int temp2){
    int i=0;
    while(arr[i].x!=-1){
        if(arr[i].x==temp1)
            arr[i].x=temp2;
        else if(arr[i].y==temp1)
            arr[i].y=temp2;
        i++;
    }
    return;
}

void removeselfloops(struct edge *A,int tempcount){
    int length=tempcount;
        if(length==0 || length==1) return;
        int i=0;
        for(int j=0; j<length; j++)
        {
            if(A[j].x!=A[j].y)
            {
                A[i].y=A[j].y;
                A[i].x=A[j].x;
                i++;
            }
        }
        if(i<length){ A[i].y=-1;A[i].x=-1;}
        return;
}

int findmincut(int *arraypointers[],struct edge *arr){

    int verticescount[NUMB+1]={0};verticescount[0]=-1;
    int tempcount=counterarrayofstructs(arr);
    populateverticescount(arr,verticescount,tempcount);
    int countofverticescount=countverticescount(verticescount);
    while((countofverticescount=countverticescount(verticescount))>2){
        tempcount=counterarrayofstructs(arr);
        int randomnumber=rand()%tempcount;
        int temp1=arr[randomnumber].y;
        int temp2=arr[randomnumber].x;
        arr[randomnumber].y=arr[randomnumber].y;
        makesame(arr,temp1,temp2);
        qsort(arr,tempcount,sizeof(struct edge),comparex);
        verticescount[temp1]=0;
        removeselfloops(arr,tempcount);
    }
    return (counterarrayofstructs(arr));
}

int main(){
    srand(time(NULL));
    int smallestmincut=INT_MAX;unsigned long long counter=0;int tempmincut;
    int **arraypointers;
    arraypointers=(int **)malloc(sizeof(int *)*210);
    population(arraypointers);
    //Population ends
    struct edge *arr=(struct edge *)malloc(sizeof(struct edge)*12000);
    populatearray(arraypointers,arr);
    struct edge *arr1=(struct edge *)malloc(sizeof(struct edge)*12000);
    while(counter<NUMOFTIMES){
        arr1=arr;

        tempmincut=findmincut(arraypointers,arr1);
        if(tempmincut<smallestmincut)
            smallestmincut=tempmincut;
        counter++;
    }
    free(arr1);
    //printer(arraypointers);

    cout<<"The mincut is "<<smallestmincut<<endl;

    return 0;


}
