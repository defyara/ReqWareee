#pragma once
#include <cstdint>
#include "../C_EntityInstance/C_EntityInstance.h"
#include "../../../reqware/utils/memory/memorycommon.h"
#include "../../../reqware/utils/math/vector/vector.h"
#include "../../../../source/reqware/utils/schema/schema.h"
#include "../../../../source/reqware/utils/memory/vfunc/vfunc.h"
#include "../handle.h"

class C_BaseEntity : public CEntityInstance
{
public:
	schema(int, m_iMaxHealth, "C_BaseEntity->m_iMaxHealth");
	SCHEMA_ADD_OFFSET(int, m_iHealth, 0x344);
	SCHEMA_ADD_OFFSET(int, m_iTeamNum, 0x3E3);

	bool IsBasePlayer()
	{
		SchemaClassInfoData_t* pClassInfo;
		dump_class_info(&pClassInfo);
		if (pClassInfo == nullptr)
			return false;

		return hash_32_fnv1a_const(pClassInfo->szName) == hash_32_fnv1a_const("C_CSPlayerPawn");
	}

	bool IsViewmodelAttachment()
	{
		SchemaClassInfoData_t* pClassInfo;
		dump_class_info(&pClassInfo);
		if (pClassInfo == nullptr)
			return false;

		return hash_32_fnv1a_const(pClassInfo->szName) == hash_32_fnv1a_const("C_ViewmodelAttachmentModel");
	}

	bool IsViewmodel()
	{
		SchemaClassInfoData_t* pClassInfo;
		dump_class_info(&pClassInfo);
		if (pClassInfo == nullptr)
			return false;

		return hash_32_fnv1a_const(pClassInfo->szName) == hash_32_fnv1a_const("C_CSGOViewModel");
	}

	bool IsPlayerController()
	{
		SchemaClassInfoData_t* _class = nullptr;
		dump_class_info(&_class);
		if (!_class)
			return false;

		const uint32_t hash = hash_32_fnv1a_const(_class->szName);

		return (hash == hash_32_fnv1a_const("CCSPlayerController"));
	}
};
