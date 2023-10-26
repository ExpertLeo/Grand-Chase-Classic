#include "include.h"

cResource::cResource()
{
	sprintf(Loc, Xor("C:\\GC_INFO.config"));
}

void cResource::WriteInteger(char* szSection, char* szKey, int iValue)
{
	char szValue[255]; sprintf(szValue, Xor("%d"), iValue);
	WritePrivateProfileStringA(szSection, szKey, szValue, Loc);
}

void cResource::WriteFloat(char* szSection, char* szKey, float fltValue)
{
	char szValue[255];
	sprintf(szValue, Xor("%f"), fltValue);
	WritePrivateProfileStringA(szSection, szKey, szValue, Loc);
}

void cResource::WriteBoolean(char* szSection, char* szKey, bool bolValue)
{
	GetPrivateProfileIntA(szSection, szKey, bolValue, Loc);
}

void cResource::WriteString(char* szSection, char* szKey, char* szValue)
{
	WritePrivateProfileStringA(szSection, szKey, szValue, Loc);
}

void cResource::ReadInteger(char* szSection, char* szKey, int &Var)
{
	Var = GetPrivateProfileIntA(szSection, szKey, 0, Loc);
}

void cResource::ReadByte(char* szSection, char* szKey, byte &Var)
{
	Var = GetPrivateProfileIntA(szSection, szKey, 0, Loc);
}

void cResource::ReadBoolean(char* szSection, char* szKey, bool &Var)
{
	Var = (bool)GetPrivateProfileIntA(szSection, szKey, 0, Loc);
}

void cResource::ReadFloat(char* szSection, char* szKey, float &Var)
{
	Var = GetPrivateProfileIntA(szSection, szKey, 0, Loc);
}

void cResource::ReadString(char* szSection, char* szKey, char * Var)
{
	GetPrivateProfileStringA(szSection, szKey, "", Var, 52, Loc);
}


void cResource::Save()
{
	WriteInteger(Xor("Mission"), Xor("EnablaMagineticFilter"), Menu->bMagneticFilter);
	WriteInteger(Xor("Mission"), Xor("EnablePortal"), Menu->bKillPortalAtTime);
	WriteInteger(Xor("Mission"), Xor("PortalTimer"), Menu->uiKillPortalTimer);
	WriteInteger(Xor("Mission"), Xor("EnableKill"), Menu->bAutoKill);
	WriteInteger(Xor("Mission"), Xor("EnablePortal"), Menu->bAutoPortal);
	WriteInteger(Xor("Mission"), Xor("EnablePredictionDrop"), Menu->bAutoLoot);
	WriteInteger(Xor("Mission"), Xor("EnableMagneticGP"), Menu->bLootType[0]);
	WriteInteger(Xor("Mission"), Xor("EnableMagneticItem"), Menu->bLootType[1]);
	WriteInteger(Xor("Mission"), Xor("EnableForceDrop"), Menu->bForceLoot);
	WriteInteger(Xor("Mission"), Xor("EnableSkipDialogue"), Menu->bSkipDialogue);

	WriteInteger(Xor("Result"), Xor("EnableTimer"), Menu->bMissionTimer);
	WriteInteger(Xor("Result"), Xor("EnableComboHits"), Menu->bComboHits);
	WriteInteger(Xor("Result"), Xor("EnableComboRatio"), Menu->bComboRatio);
	WriteInteger(Xor("Result"), Xor("EnableComboDmg"), Menu->bComboDmg);
	WriteInteger(Xor("Result"), Xor("EnableComboReceive"), Menu->bComboReceive);
	WriteInteger(Xor("Result"), Xor("EnableAerialCombo"), Menu->bAerialCombo);
	WriteInteger(Xor("Result"), Xor("EnableEliminations"), Menu->bComboEliminations);
	WriteInteger(Xor("Result"), Xor("EnableRandom"), Menu->bRandomStatus);

	WriteInteger(Xor("Result"), Xor("MissionTimer"), Menu->uiMissionTimer);
	WriteInteger(Xor("Result"), Xor("ComboHits"), Menu->uiComboHits);
	WriteInteger(Xor("Result"), Xor("ComboDmg"), Menu->uiComboDmg);
	WriteInteger(Xor("Result"), Xor("ComboReceived"), Menu->uiComboReceived);
	WriteInteger(Xor("Result"), Xor("AerialCombo"), Menu->uiAerialCombo);
	WriteInteger(Xor("Result"), Xor("ComboElimination"), Menu->uiComboElimination);
	WriteFloat(Xor("Result"), Xor("ComboRatio"), Menu->fComboRatio);

	WriteInteger(Xor("Player"), Xor("EnableAtt"), Menu->bAtt);
	WriteInteger(Xor("Player"), Xor("EnableDef"), Menu->bDef);
	WriteInteger(Xor("Player"), Xor("EnableHp"), Menu->bHp);
	WriteInteger(Xor("Player"), Xor("EnableMp"), Menu->bMp);
	WriteInteger(Xor("Player"), Xor("EnableCriChance"), Menu->bCriChance);
	WriteInteger(Xor("Player"), Xor("EnableCriDmg"), Menu->bCritDmg);
	WriteFloat(Xor("Player"), Xor("Att"), Menu->fAtt);
	WriteFloat(Xor("Player"), Xor("Def"), Menu->fDef);
	WriteFloat(Xor("Player"), Xor("CriChance"), Menu->fCriChance);
	WriteFloat(Xor("Player"), Xor("CriDmg"), Menu->fCritDmg);


	int LootSize = GrandChase->v_FilterId.size();

	WriteInteger(Xor("Loot"), Xor("Size"), LootSize);

	if (LootSize)
	{
		for (int i = 0; i < LootSize; i++)
		{
			char szLoot[50];
			sprintf(szLoot, Xor("LT%d"), i);
			WriteInteger(Xor("Loot"), szLoot, GrandChase->v_Loot[i]);
		}
	}
}

void cResource::Load()
{
	int LootSize = 0;

	ReadInteger(Xor("Loot"), Xor("Size"), LootSize);

	if (LootSize)
	{
		int Id = 0;

		for (int i = 0; i < LootSize; i++)
		{
			char szLoot[50];
			sprintf(szLoot, Xor("LT%d"), i);
			ReadInteger(Xor("Loot"), szLoot, Id);
			
			if (Id)
				GrandChase->AddLootThroughLoad(Id);
		}
	}

	ReadBoolean(Xor("Mission"), Xor("EnablaMagineticFilter"), Menu->bMagneticFilter);
	ReadBoolean(Xor("Mission"), Xor("EnablePortal"), Menu->bKillPortalAtTime);
	ReadInteger(Xor("Mission"), Xor("PortalTimer"), Menu->uiKillPortalTimer);
	ReadBoolean(Xor("Mission"), Xor("EnableKill"), Menu->bAutoKill);
	ReadBoolean(Xor("Mission"), Xor("EnablePortal"), Menu->bAutoPortal);
	ReadBoolean(Xor("Mission"), Xor("EnablePredictionDrop"), Menu->bAutoLoot);
	ReadBoolean(Xor("Mission"), Xor("EnableMagneticGP"), Menu->bLootType[0]);
	ReadBoolean(Xor("Mission"), Xor("EnableMagneticItem"), Menu->bLootType[1]);
	ReadBoolean(Xor("Mission"), Xor("EnableForceDrop"), Menu->bForceLoot);
	ReadBoolean(Xor("Mission"), Xor("EnableSkipDialogue"), Menu->bSkipDialogue);

	ReadBoolean(Xor("Result"), Xor("EnableTimer"), Menu->bMissionTimer);
	ReadBoolean(Xor("Result"), Xor("EnableComboHits"), Menu->bComboHits);
	ReadBoolean(Xor("Result"), Xor("EnableComboRatio"), Menu->bComboRatio);
	ReadBoolean(Xor("Result"), Xor("EnableComboDmg"), Menu->bComboDmg);
	ReadBoolean(Xor("Result"), Xor("EnableComboReceive"), Menu->bComboReceive);
	ReadBoolean(Xor("Result"), Xor("EnableAerialCombo"), Menu->bAerialCombo);
	ReadBoolean(Xor("Result"), Xor("EnableEliminations"), Menu->bComboEliminations);
	ReadBoolean(Xor("Result"), Xor("EnableRandom"), Menu->bRandomStatus);

	ReadInteger(Xor("Result"), Xor("MissionTimer"), Menu->uiMissionTimer);
	ReadInteger(Xor("Result"), Xor("ComboHits"), Menu->uiComboHits);
	ReadInteger(Xor("Result"), Xor("ComboDmg"), Menu->uiComboDmg);
	ReadInteger(Xor("Result"), Xor("ComboReceived"), Menu->uiComboReceived);
	ReadInteger(Xor("Result"), Xor("AerialCombo"), Menu->uiAerialCombo);
	ReadInteger(Xor("Result"), Xor("ComboElimination"), Menu->uiComboElimination);
	ReadFloat(Xor("Result"), Xor("ComboRatio"), Menu->fComboRatio);

	ReadBoolean(Xor("Player"), Xor("EnableAtt"), Menu->bAtt);
	ReadBoolean(Xor("Player"), Xor("EnableDef"), Menu->bDef);
	ReadBoolean(Xor("Player"), Xor("EnableHp"), Menu->bHp);
	ReadBoolean(Xor("Player"), Xor("EnableMp"), Menu->bMp);
	ReadBoolean(Xor("Player"), Xor("EnableCriChance"), Menu->bCriChance);
	ReadBoolean(Xor("Player"), Xor("EnableCriDmg"), Menu->bCritDmg);
	ReadFloat(Xor("Player"), Xor("Att"), Menu->fAtt);
	ReadFloat(Xor("Player"), Xor("Def"), Menu->fDef);
	ReadFloat(Xor("Player"), Xor("CriChance"), Menu->fCriChance);
	ReadFloat(Xor("Player"), Xor("CriDmg"), Menu->fCritDmg);
}

cResource* Resource;