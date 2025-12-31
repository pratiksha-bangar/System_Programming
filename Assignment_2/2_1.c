/*
Read whole file  --- 
accept file name and print full content on console
use a buffer loop (read() until 0)
show total read bytes
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

# define BUFFER_SIZE 1024

int main()
{
    int fd =0;
    char fname[100];
    int readdata=0;
    int totalbytes=0;
    char buffer[BUFFER_SIZE];

    printf("Enter file name:");
    scanf("%s",fname);

    fd = open(fname,O_RDONLY);                                    // open

    if(fd == -1)
    {
        printf("Unable to open file");
        return -1;
    }

    printf("File opened Sucessfully with fd:%d\n",fd);


    while((readdata = read(fd, buffer, BUFFER_SIZE)) > 0)            // read
    {
        write(STDOUT_FILENO, buffer, readdata);                     // write
        totalbytes = totalbytes + readdata;
    }

    printf("\nTotal Data Read :%d bytes\n",totalbytes);

    close(fd);

    return 0;
}