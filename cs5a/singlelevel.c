//single-level directory
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct file{
char fileName[15][20];
char dirName[10];
int fno;

};

struct file dir;
int i,n;

void InsertFile(){
printf("\n Enter the File name ");
scanf("%s",dir.fileName[dir.fno]);
dir.fno++;
}

void DisplayFiles(){
printf("\n");
printf("+------------------------+");
printf("\n Directorytfiles    \n");
printf("+------------------------+");
printf("\n %s",dir.dirName);
for(i=0;i<dir.fno;i++){
printf("\n %s",dir.fileName[i]);
}
printf("\n+------------------------+");
}

void DeleteFile(){
char name[20];
printf("\n Enter the file to be deleted : ");
scanf("%s",name);
for(i=0;i<dir.fno;i++){
if(strcmp(dir.fileName[i],name)==0){
printf("%s is deleted \t",dir.fileName[i]);
strcpy(dir.fileName[i],dir.fileName[dir.fno-1]);
dir.fno--;
}
}
}

void SearchFile(){
char name[20];
int found=-1;
printf("\n Enter the file to be searched :");
scanf("%s",name);
for(i=0;i<dir.fno;i++){
if(strcmp(dir.fileName[i],name)==0){
printf("\n The File is found at position %d",i+1);
found=1;
break;
}
}
if(found==-1)
printf("\n the file is not found ");



}



int main(){
int op;
dir.fno=0;
printf("\n Enter the directory name");
scanf("%s",dir.dirName);
while(1){
printf("\n choose! 1:Insert 2:Delete 3:search4: display 5:Exitn>>");
scanf("%d",&op);
switch(op){
case 1:InsertFile();
break;
case 2:DeleteFile();
break;
case 3:SearchFile();
break;
case 4:DisplayFiles();;
break;

case 5:exit(0);  
}

}
return 0;
}
