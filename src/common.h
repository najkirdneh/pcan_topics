//****************************************************************************
// INCLUDES
#include <libpcan.h>

//****************************************************************************
// DEFINES

//****************************************************************************
// GLOBALS
extern HANDLE h;
extern const char *current_release;

//****************************************************************************
// LOCALS

//****************************************************************************
// PROTOTYPES
#ifdef __cplusplus
extern "C" 
{
#endif


void signal_handler(int signal);

void do_exit(int error);

// the opposite: lookup for device string out of HW_.. constant
char *getNameOfInterface(int nType);

// print out device and channel diagnostics
void print_diag(const char *prgName);
#ifdef __cplusplus
}
#endif

