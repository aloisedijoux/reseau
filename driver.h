
#ifndef DRIVER_H
#define DRIVER_H

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/usb.h>


int mon_probe(struct usb_interface *interfaceusb, const struct usb_device_id *identif);
void mon_disconnect(struct usb_interface *interfaceusb);
int mon_init(void);
void mon_exit(void);

#endif // DRIVER_H