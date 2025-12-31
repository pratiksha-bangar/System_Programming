/*
write string to file --
accept fil name and string from user
write string using write() 
print number of bytes written
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main()
{
    int fd =0;
    char fname[100];
    char buffer[BUFFER_SIZE];
    int iRet =0;

    printf("\nEnter file name:");
    scanf("%s",fname);

    getchar();
    printf("\nEnter String you wnat to write in File :");
    fgets(buffer,BUFFER_SIZE,stdin);

    fd = open(fname,O_WRONLY | O_CREAT | O_APPEND);

    if(fd == -1)
    {
        printf("Unable to open file\n ");
        return -1;
    }
    printf("File opened sucessfully with fd:%d\n",fd);


    
    iRet = write(fd,buffer,strlen(buffer));

    printf("%d bytes written",iRet);

    close(fd);

    return 0;
}
