
#define MAPPED_SIZE 10000
#define DDR_RAM_PHYS 10000



#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{


    int _fdmem;
    int *map = NULL;
    const char memDevice[] = "/dev/mem"; //access physical memory 

    /* open /dev/mem and error checking */
    _fdmem = open( memDevice, O_RDWR | O_SYNC );

    if (_fdmem < 0)
    {
        printf("Failed to open the /dev/mem !\n");
        return 0;
    }
    else
    {
        printf("open /dev/mem successfully !\n");
    }
    printf("Debug Point 1 !\n");
    //creates a new mapping in the virtual address space of the calling process. 
    map= (int *)(mmap(0,MAPPED_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,_fdmem,DDR_RAM_PHYS));

    printf("Debug point 2 (copied to virtual memory address) !\n");

    // printf("Failed to open the /dev/mem !\n");

    for(int i=0;i<100;i++)
        {
            printf("content: 0x%x\n",*(map+i));
        }

    if (munmap(map,MAPPED_SIZE)==-1)
    {
        perror("Error un-mmapping the file");
    }
    close(_fdmem);

    return 0;
}




/* The following code snippet is from 

    https://stackoverflow.com/questions/9662193/how-to-accessif-possible-kernel-space-from-user-space
*/


