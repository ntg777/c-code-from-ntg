//
// Created by shovval on 16/08/2016.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define lineleangth 1001
#define maxlines 1001
#define MAXDEPENS 101
#define FIRSTVALUE 0
#define TRUE 1
#define FALSE 0
#define EMPTY 0
struct files
{
    char *filename;
    int dependenscount;
    int outherfile[MAXDEPENS];
    char *thisdependenson[MAXDEPENS];
    int isokforself;
};

//void gfs(char *Lines[])
//{
//    int stackpointer =0;
//    int linepointer=0;
//    struct files stack[maxlines];
//    //strtok:
//    stack[stackpointer].filename="strtok";
//    while (Lines [linepointer]!="EOF")//can be on the same line need to fix this
//    {
//        while (stack[stackpointer].isokforself==NULL && "strtok" != NULL)
//        {
//
//        }
//    }
//}
int checkforloop(int stack[],int nextinpot)
{
    for(int i=0;stack[i]!=-1;i++)
    {
        if(stack[i]==nextinpot)
            {
            return TRUE;
        }
    }
    return FALSE;
}

int dfsrecursion(struct files* dependencies,int stack[],int stackpointer)
{
    struct files *filepoiner = &dependencies[stack[stackpointer]]; //filepoiner is for an easy way to read the code, he represent the file we are looking at
    stackpointer++;
    char* dependname;
    int lookforfile=EMPTY;
    // printf("%s",dependencies[2].filename);
    if(filepoiner!=NULL)
    {
        filepoiner->dependenscount=0;
        //filepoiner->thisdependenson[filepoiner->dependenscount]=0;
        while (filepoiner->thisdependenson[filepoiner->dependenscount] != NULL)
        {
            dependname = filepoiner->thisdependenson[filepoiner->dependenscount++];
            for (lookforfile = EMPTY; lookforfile < maxlines && strcmp(dependencies[lookforfile].filename,"EOF") != 0; lookforfile++)//can remove lookforfile<maxlines there is no need for it
            {  // this for loops in dependencies trying to find the coresponing file
                if (strcmp(dependencies[lookforfile].filename, dependname)==FALSE) // we fond the dependened in dependencies array
                {
                    if(checkforloop(stack,lookforfile) == TRUE)
                    {
                        return FALSE;//make sure to exit this mean there is a loop. need to add it
                    }
                    else
                    {
                        stack[stackpointer] = lookforfile; //push lookforfile
                        if( dfsrecursion(dependencies,stack,stackpointer+1)==FALSE)
                        {
                            return FALSE;
                        }
                    }

                }
            }
            //here we now that the file we just looked at is ok and is not creating a loop
            dependencies[lookforfile].isokforself=1;

        }
    }
    return TRUE;
}

void fileopen(char* alltext[])
{
    FILE *fPointer;
    fPointer = fopen("C:\\Users\\owner\\ClionProjects\\ex2\\test.txt", "r");
    char singleLine[lineleangth];
    int textpointer=EMPTY;
    while (!feof(fPointer))
    {
        fgets( singleLine ,lineleangth ,fPointer);// i can remove singleline and use only temp but this is easy to understand
        char *temp = malloc(sizeof(singleLine)*sizeof(char));//memory leck
        if(temp == NULL)
        {
            printf("Error");
        }
        strcpy(temp,singleLine);
        alltext[textpointer]=temp;
        textpointer++;
    }
    alltext[textpointer]="EOF";
}

void brakedownaline(struct files* dependencies,char* singleline,int linepointer)
{
    const char *sembole = ":";
    char* temp= strtok(singleline, sembole);
    sembole=",";
    for (int i = EMPTY; dependencies[i].filename != NULL; i++) //this is the n^2 in the program can be remove if we know that in no plase there is
    {
        if(strcmp(dependencies[i].filename,temp)==0) //if the file is allready registered
        {
            linepointer=i;

        }
    }
   //strcpy(&(dependencies[linepointer].filename),temp);
    dependencies[linepointer].filename=temp;
    while (TRUE)
    {
        dependencies[linepointer].thisdependenson[dependencies[linepointer].dependenscount] = strtok(NULL, sembole); //add macro to all this
        if (dependencies[linepointer].thisdependenson[dependencies[linepointer].dependenscount] == NULL)
        {
            strtok(dependencies[linepointer].thisdependenson[dependencies[linepointer].dependenscount-1], "\n");
            break;
        }
        dependencies[linepointer].dependenscount++;
    }
        //sold never be null add debag
    if(dependencies[linepointer].dependenscount<0)
    {
        //this is an error
    }
    else
    {
        if (dependencies[linepointer].thisdependenson[0]!=NULL && strcmp(dependencies[linepointer].thisdependenson[0], "\n") == 0)
        {
            dependencies[linepointer].thisdependenson[0] = NULL;
            dependencies[linepointer].dependenscount--;
        }
    }
}

int startdfs()
{
    char* alltext[maxlines];
    fileopen(alltext);
    struct files dependencies[maxlines];
    int stackofdependenc[maxlines];
    int weareatline=EMPTY;
    int emptylines=EMPTY;
    for( weareatline = FIRSTVALUE; weareatline < maxlines && strcmp( alltext[weareatline],"EOF"); weareatline++)
    {
        char *singleline = alltext[weareatline];
        brakedownaline(dependencies, singleline,weareatline-emptylines);
        stackofdependenc[weareatline]=-1;
        if(dependencies[weareatline-emptylines].filename==NULL)
        {
            emptylines++;
        }
    //    dependencies[i].isokforself=0;
    }
    dependencies[weareatline-emptylines].filename="EOF";

    int stackpointer=FIRSTVALUE;

    for(int i=FIRSTVALUE;i<maxlines;i++)
    {
        stackofdependenc[FIRSTVALUE]=i;
        if(dfsrecursion(dependencies,stackofdependenc,stackpointer)==TRUE)
        {
            return TRUE;
        }

    }
    return FALSE;
}




