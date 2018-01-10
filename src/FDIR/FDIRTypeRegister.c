#include "FDIRTypeRegister.h"
#include "RecoveryAction.h"
#include "DC_NullRecoveryAction.h"
#include "DC_DummyRecoveryAction.h"
#include "DC_FdirCheck.h"
#include "MonitoringProfile.h"
#include "DC_NullProfile.h"

void fdir_type_register(void)
{
    RecoveryAction_register();
    DC_NullRecoveryAction_register();
    DC_DummyRecoveryAction_register();
    DC_FdirCheck_register();
    MonitoringProfile_register();
    DC_NullProfile_register();
}
