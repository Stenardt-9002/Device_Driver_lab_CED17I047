/*
By 
        Ritvik Raj Singh 
        CED17I047

*/

/*


1.

(a) Write a module that can take an integer parameter when it is loaded with insmod command.

AND

(b) Write a module which prints your name in log.




*/









#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>



MODULE_AUTHOR("Ritvik Raj Singh");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Testing module with integer parametre");

int myvar ;

module_param(myvar,int,0);

static int __init hello_init(void)
{
    // printk(KERN_INFO "End Sem Lab DD\n");
    // printk(KERN_INFO "Variable passed %d \n",myvar);
    printk(KERN_INFO "My name is Ritvik Raj Singh and the variable passed is %d \n",myvar);

    return 0;
}




static void __exit hello_exit(void)
{
    printk(KERN_INFO "Ending driver\n" );
}

module_init(hello_init) ;
module_exit(hello_exit) ;




// https://tldp.org/LDP/lkmpg/2.6/html/x323.html