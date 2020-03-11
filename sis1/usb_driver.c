#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/usb.h>


//usb driver (pen is a flah drive)
static struct usb_driver pen_driver = {
    .name = "USB Driver",
    .id_table = pen_table,
    .probe = pen_probe,
    .disconnect = pen_disconnect,
};


static int __init pen_init(void){
     int result;
        /* register this driver with the USB subsystem */
        result = usb_register(&pen_driver);
        if (result < 0) {
                err("usb_register failed for the "__FILE__ "driver."
                    "Error number %d", result);
                return -1;
        }
        printk(KERN_INFO "\tRegistration is complete");
        return 0;
}


static void __exit pen_exit(void){
    /* deregister this driver with the USB subsystem */
    usb_deregister(&pen_driver);
    printk(KERN_INFO "\tUnregistration complete");
}


/* table of devices that work with this driver */
static struct usb_device_id pen_table[] = {
    //046d : c083
    { USB_DEVICE(0x046d, 0xc083) },             //info obtained using "lsusb" command
    {}  /*termination entry*/
};

MODULE_DEVICE_TABLE(usb, pen_table);


/*When a device is plugged into the USB bus that matches the device 
ID pattern that your driver registered with the USB core, the probe 
function is called.*/
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id){
    printk(KERN_INFO "USB drive (%04X:%04X) plugged\n", id->idVendor, id->idProduct);
    return 0;
}


static void pen_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "USB drive removed\n");
}


module_init(pen_init);
module_exit(pen_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MADI");


