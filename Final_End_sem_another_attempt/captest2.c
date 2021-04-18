#include <stdio.h>
#include <stdlib.h>




int main()
{
    
    int status = system("xset q| grep Caps");

    printf("\n%d",status);




    return 0;
}







