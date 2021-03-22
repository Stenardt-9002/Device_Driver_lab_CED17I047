
// Write a C program, compile it as module, insert into kernel, check message in log, remove module from kernel.




#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>


MODULE_AUTHOR("Ritvik Raj Singh");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Testing Q5 driver");


static int __init hello_init(void)
{
    printk(KERN_INFO "testing Q6\n");
    return 0;
}




static void __exit hello_exit(void)
{
    printk(KERN_INFO "Ending driver\n" );
}

module_init(hello_init) ;
module_exit(hello_exit) ;








/*
obj-m:=Q5.o
KVERSION = $(shell uname -r)
all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean


*/


// -C path of kernel 
// compile M needs absolute path 

//compile
//make 

//inserting module
//sudo insmod Q5.ko

//check log
//sudo dmesg|tail

//removal of module
//sudo rmmod Q5


//tail -f /var/log/message