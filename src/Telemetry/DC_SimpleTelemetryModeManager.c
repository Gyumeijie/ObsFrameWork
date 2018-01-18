//
// Copyright 2004 P&P Software GmbH - All Rights Reserved
//
// DC_SimpleTelemetryModeManager.c
//
// Version	1.0
// Date		24.02.03
// Author	A. Pasetti (P&P Software)

#include "../GeneralInclude/CompilerSwitches.h"
#include "../GeneralInclude/ClassId.h"
#include "DC_SimpleTelemetryModeManager.h"



///////////////////////////////////////////////////////////////////////////////
//
//                    non-pure virtual  method(s) definition
//
///////////////////////////////////////////////////////////////////////////////

/**
 * Since this is a fixed-mode mode manager, this method returns without
 * taking any action.
 */
static void update(void *obj)
{
    return;
}



///////////////////////////////////////////////////////////////////////////////
//
//                   object constructor and destructor
//
///////////////////////////////////////////////////////////////////////////////

static void instance_init(Object *obj)
{
    CC_RootObject_setClassId((CC_RootObject*)obj, ID_SIMPLETELEMETRYMODEMANAGER);
    ModeManager_setNumberOfModes((ModeManager*)obj, 1);
    ModeManager_setDefaultMode((ModeManager*)obj, 0);
}

DC_SimpleTelemetryModeManager* DC_SimpleTelemetryModeManager_new(void)
{
    return (DC_SimpleTelemetryModeManager*)object_new(TYPE_DC_SIMPLETELEMETRYMODEMANAGER);
}



///////////////////////////////////////////////////////////////////////////////
//
//                   binding and type registration
//
///////////////////////////////////////////////////////////////////////////////

static void class_init(ObjectClass *oc, void *data)
{
    ModeManagerClass *mmc = MODEMANAGER_CLASS(oc);
    mmc->update = update;
}

static const TypeInfo type_info = {
    .name = TYPE_DC_SIMPLETELEMETRYMODEMANAGER,
    .parent = TYPE_TELEMETRYLISTMODEMANAGER,
    .instance_size = sizeof(DC_SimpleTelemetryModeManager),
    .abstract = false,
    .class_size = sizeof(DC_SimpleTelemetryModeManagerClass),
    .instance_init = instance_init,
    .class_init = class_init,
};

void DC_SimpleTelemetryModeManager_register(void)
{
    type_register_static(&type_info);
}
