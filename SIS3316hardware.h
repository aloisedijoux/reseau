
//SIS3316MOdule de MIDAS
//Si on enleve les dépendances à midas càd
// #include "midas.h"
// #include "odbxx.h"
// Alors ne sont pas définis:
// INT (type)
// variables from idas::odb variables càd une variable de type odb défini dans la classe midas , pareil pour midas::osb settings


//SIS3316module de paqs 
//on enleve:
// #include "/PAQS_Basics/PAQSadcBasics.h"
// #include "/PAQS_Basics/PAQSsignal.h" // only for TRACE
//ne sont pas définis:
//de paqsadcbasics: TIMESTAMP_ADC, Polarity , MSGERR
//de paqssignal: BYTE, TRACE, DWORD, UINT16, USHORT
//Dans le cpp, ne sont pas définis:
//de paqssupport.h: timeGetTime(), Sleep(, MSGDBG, <<, CopyMemory, DAQSAMPLE, LONGLONG, LLONG_MAX

#include "drivers/sis3316.h"
#include "drivers/sis3316_class.h"
#include "drivers/vme_interface_class.h"
#include "drivers/sis1100linux_vme_class.h"
#include <array>
#include <vector>

#include "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" //pour uint32_t

typedef int INT;
//this class should have, for attributes: vme
class SIS3316Module : public sis3316_adc {
    private:
        UINT module_address; 
        int i_module;
        
        
    public:
        INT ReadModuleInformation();
        //prend en parametres : le crate : controllertype vmecrate*, l'adresse de base du module et un int i module;
        SIS3316Module(sis1100* crate, unsigned int baseaddr, int i_mod);
        SIS3316Module::SIS3316Module(sis1100* crate, unsigned int baseaddr, int i_mod)
    : sis3316_adc(crate, baseaddr), i_module{i_mod}
{

}


};