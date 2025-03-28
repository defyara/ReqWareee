#include "C_CSWeaponBase.h"
#include "..\..\..\reqware\hooks\hooks.h"
CCSWeaponBaseVData* C_CSWeaponBase::Data()
{
	// return pointer to weapon data
	return *reinterpret_cast<CCSWeaponBaseVData**>((uintptr_t)this + H::oGetWeaponData);
}