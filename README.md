SIS1 topic: USB input interruptor, that checks the plugged-in available usb devices.

Module shows plugged-in exact device which I configured in the source code (i.e. my gaming mouse Logitech G403).

To test this module you should first clone the module, insert it into the kernel and look into dmesg which will show info about plugged-in device.

Useful link: https://kernel.readthedocs.io/en/sphinx-samples/writing_usb_driver.html
