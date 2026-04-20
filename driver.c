//les includes
#include "driver.h"

//table usb

//avec vid et pid
struct usb_device_id ma_table_usb[] = {
    { USB_DEVICE(0x1234, 0x5678) },
    { USB_DEVICE(0x8765, 0x4321) },
    {} // fin de la table
};


//fonctions mon porbe et disctonnect
 int mon_probe(struct usb_interface *interfaceusb, const struct usb_device_id *identif) {
        printk(KERN_INFO "Mon module de réseau a été chargé.\n");
        return 0; // succès
    }
void mon_disconnect(struct usb_interface *interfaceusb) {
    printk(KERN_INFO "Mon module de réseau a été déchargé.\n");
}


//struct usb driver pou regrouper tout et enregistrer aupres du kernel 

struct usb_driver mon_driver_usb = {
    .name = "mon_driver_usb",
    .id_table = ma_table_usb,
    .probe = mon_probe, // fonction qui sera appelée quand un périphérique correspondant est connecté
    .disconnect = mon_disconnect, // fonction qui sera appelée quand un périphérique correspondant est dé
};

//init et exit

int mon_init() {
    int ret = usb_register(&mon_driver_usb); // enregistrement du driver auprès du kernel
    if (ret) {
        printk(KERN_ERR "Erreur lors de l'enregistrement du driver USB.\n");
        return ret;
    }
   
    return 0; // succès
}

void mon_exit() {
    usb_deregister(&mon_driver_usb); // désenregistrement du driver auprès du kernel
    printk(KERN_INFO "Mon module de réseau a été déchargé.\n");
}

//macros et MODULE_*

module_init(mon_init);
module_exit(mon_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Driver test");
MODULE_DEVICE_TABLE(usb, ma_table_usb);
