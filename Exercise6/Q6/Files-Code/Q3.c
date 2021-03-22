//#simple char driver


#include <linux/init.h>          
#include <linux/module.h>   
#include <linux/fs.h>   /* for character driver support */


//functions operations read write open close when access to /dev/nod
int ex1open(struct inode *pinode,struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function \n",__FUNCTION__ ) ;
    return 0 ;
}
ssize_t ex1read(struct file *pfile,char __user *buffer,size_t length ,loff_t *offset) 
{
    printk(KERN_ALERT "Inside the %s function \n",__FUNCTION__ ) ;
    return 0;
}

ssize_t ex1write(struct file *pfile,const char __user *buffer,size_t length ,loff_t *offset) 
{
    printk(KERN_ALERT "Inside the %s function \n",__FUNCTION__ ) ;
    return length ; //bytes written
}
int ex01close(struct inode *pinode,struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function \n",__FUNCTION__ ) ;
    return 0;
}



//register function when node 420 is accessed
struct file_operations ex07_file_operations = {
    //linux/fs
    //file owner ,read,write,open,close 
    //operations
    .owner = THIS_MODULE ,
    .open = ex1open ,
    .read = ex1read ,
    .write = ex1write ,
    .release = ex01close

};




//init when module loadeds
int ex01_simple_module_init(void)
{
    printk(KERN_ALERT "Inside the %s function \n",__FUNCTION__ ) ;

//register with kernel (reg character device driver)
    register_chrdev(420 /*Major Number*/,"Simple Character Driver"/* */,&ex07_file_operations/* File Operations */ ) ;

    return 0;
//intialised then get called in kernel

}
// no difference between device and file


//unloaded
void ex01_simple_module_exit(void)
{
    //exit operation 
    printk(KERN_ALERT "Inside the %s function \n",__FUNCTION__ ) ;

    //unregister character driver
    unregister_chrdev(420,"Simple Character Driver") ;

}

module_init(ex01_simple_module_init);
module_exit(ex01_simple_module_exit);















//make
// make -C /lib/modules/$(uname -r)/build M=$PWD modules 
// make -C /lib/modules/$(uname -r)/build M=$PWD modules
//check 
// lsmod | grep ex //check existing 
//sudo insmod ./Q3.ko

//cat /proc/devices //check character driver at 420

//sudo mknod -m 666 /dev/Q3 c 420 0 // c == character device
// ls -l /dev/Q3
// sudo tail -f /var/log/syslog //continuously xheck log

// cat /dev/Q3 //read
// echo "testQ3" > /dev/Q3  //write

//sudo rmmod Q3
//register
//character






