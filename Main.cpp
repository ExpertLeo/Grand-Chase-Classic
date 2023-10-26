#include "include.h"

cMain* GrandChase;

DWORD EncryptTable00 = 0;

void __fastcall hk_SendDetect(int a1)
{
	printf(Xor("Detection Blocked \n"));
}


cMain::cMain()
{
	VIRTUALIZER_FISH_WHITE_START
	DWORD GameModule = (DWORD)GetModuleHandleA(NULL);

	ImportContinentBoss();

	oGetLocalPlayer = (tGetLocalPlayer)FindSignature((PBYTE)"\x55\x56\x8B\xE9\xE8\x00\x00\x00\x00\x8B\x35\x00\x00\x00\x00\x8B\x90\x00\x00\x00\x00\x8B\x80\x00\x00\x00\x00\x3B\xD0\x74\x0F\x90\x39\x32", "xxxxx????xx????xx????xx????xxxxxxx");

	printf("GetLocalPlayer %x \n", oGetLocalPlayer);

	MyD3DApp = FindSignaturePointer(2, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x81\xC1\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\xF0\xB8\x00\x00\x00\x00\xF7\x6F\x14\xC1\xFA\x02", "xx????xx????x????xxx????xxxxxx");

	printf("MyD3DApp %x \n", MyD3DApp);

	EncryptTable00 = FindSignaturePointer(3, (PBYTE)"\x33\x14\xC5\x00\x00\x00\x00\x8B\x4F\x0C\x33\x0C\xC5\x00\x00\x00\x00\x8D\x45\x9C\x89\x4D\xA0", "xxx????xxxxxx????xxxxxx");

	DWORD dwEncCompareBypass = FindSignatureCall(1, (PBYTE)"\xE8\x00\x00\x00\x00\x8B\x44\x24\x10\x89\x44\x24\x10\x8B\x03", "x????xxxxxxxxxx");

	printf("EncCompareBypass %x \n", dwEncCompareBypass);

	pGameScene = (cGameScene*)FindSignaturePointer(1, (PBYTE)"\xA1\x00\x00\x00\x00\x0F\x45\xD1\x8B\x0D\x00\x00\x00\x00\x3B\x81\x00\x00\x00\x00\x75\x11\x84\xD2", "x????xxxxx????xx????xxxx");

	printf("pGameScene: %x \n", pGameScene);

	DWORD OldP;
	VirtualProtect((LPVOID)dwEncCompareBypass, 0x60, PAGE_EXECUTE_READWRITE, &OldP);
	memcpy((void*)dwEncCompareBypass, "\xC3\x90\x90", 3);
	VirtualProtect((LPVOID)dwEncCompareBypass, 0x60, OldP, &OldP);

	/* OnOk */
	Send_StrongLevelUpReq = (oSend_StrongLevelUpReq)FindSignaturePointer(2, (PBYTE)"\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\x89\x7D\x38\xE8\x00\x00\x00\x00\x8B\x8F\x00\x00\x00\x00\x8D\x45\x30", "xx?????xx?????xxxx????xx????xxx");

	printf("Send_StrongLevelUpReq %x \n", Send_StrongLevelUpReq);

	pOverlay = (cGameOverlay*)FindSignaturePointer(2, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8D\x45\xD8\x6A\xFF\x6A\x01\x50", "xx????xxxxxxxx");

	printf("pOverlay: %x \n", pOverlay);

	pMonsterMgr = (cMonsterManager*)FindSignaturePointer(2, (PBYTE)"\x8B\x35\x00\x00\x00\x00\x8B\x46\x04\x80\x78\x0D\x00\x75\x21\x39\x78\x10", "xx????xxxxxxxxxxxx");

	printf("MonsterMgr: %x \n", pMonsterMgr);

	MonsterObserverForDropItem = (oMonsterObserverForDropItem)FindSignaturePointer(6, (PBYTE)"\xC7\x86\x00\x00\x00\x00\x00\x00\x00\x00\x5E\x83\xC4\x0C\xC2\x0C\x00\x8B\xCE", "xx????????xxxxxxxxx");

	printf("MonsterObserverForDropItem: %x \n", MonsterObserverForDropItem);

	AddMonKillNum = (oAddMonKillNum)FindSignature((PBYTE)"\x83\xEC\x14\x8D\x44\x24\x18\x53\x56\x57\x8B\xF9\x50\x8D\x44\x24\x14\x50", "xxxxxxxxxxxxxxxxxx");

	printf("AddMonKillNum: %x \n", AddMonKillNum);

	pMission = (cMission*)FindSignaturePointer(2, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x50\x6A\x01\xFF\xB7\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xC7\x87\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xB7\x00\x00\x00\x00", "xx????xxxxx????x????xx????????xx????");

	printf("Mission: %x \n", pMission);

	VirtualKill = (oVirtualKill)FindSignatureCall(1, (PBYTE)"\xE8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xFF\xB7\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00", "x????x????xx????xx????");

	printf("VirtualKill: %x \n", VirtualKill);

	kUserMission = FindSignaturePointer(1, (PBYTE)"\xB9\x00\x00\x00\x00\x53\xFF\xB6\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x5F\x5B\x8B\x86\x00\x00\x00\x00", "x????xxx????x????xxxx????");

	printf("kUserMission: %x \n", kUserMission);

	ShowExp = (oShowExp)FindSignature((PBYTE)"\x83\xEC\x0C\x53\x56\x57\x8B\xD9\xE8\x00\x00\x00\x00\x8B\x88\x00\x00\x00\x00", "xxxxxxxxx????xx????");

	printf("ShowExp: %x \n", ShowExp);

	pQuest = (cQuest*)FindSignaturePointer(2, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\x41\x34\x3B\x85\x00\x00\x00\x00\x75\x0B\x8B\x41\x30", "xx????xxxxx????xxxxx");

	printf("Quest: %x \n", pQuest);

	pEveryTriggerManager = (CEveryTriggerManager*)FindSignaturePointer(1, (PBYTE)"\xB9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\xB5\x00\x00\x00\x00\xBA\x00\x00\x00\x00\x2B\xD6\xC7\x85\x00\x00\x00\x00\x00\x00\x00\x00", "x????x????xx????x????xxxx????????");

	printf("pEveryTriggerManager: %x \n", pEveryTriggerManager);

	pPortalMng = (cPortalManager*)FindSignaturePointer(1, (PBYTE)"\xB9\x00\x00\x00\x00\x89\x45\xEC\xFF\x75\xEC\xC7\x40\x00\x00\x00\x00\x00\xC6\x40\x04\x00", "x????xxxxxxxx?????xxxx");

	printf("PortalMng: %x \n", pPortalMng);

	KP2P = FindSignaturePointer(2, (PBYTE)"\x89\x0D\x00\x00\x00\x00\x81\xFE\x00\x00\x00\x00\x7D\x07\x8B\x45\x10", "xx????xx????xxxxx");

	printf("KP2P: %x \n", KP2P);

	Send_BuyItemForGPReq = (oSend_BuyItemForGPReq)FindSignature((PBYTE)"\x83\xEC\x10\xA1\x00\x00\x00\x00\x33\xC4\x89\x44\x24\x0C\x8B\x49\x08\x85\xC9\x74\x41\x83\xB9\x00\x00\x00\x00\x00", "xxxx????xxxxxxxxxxxxxxx?????");

	printf("Send_BuyItemForGPReq: %x \n", Send_BuyItemForGPReq);

	SetMonsterHealth = (oSetMonsterHealth)FindSignature((PBYTE)"\xA1\x00\x00\x00\x00\x56\x8B\xF1\x85\xC0\x74\x14", "x????xxxxxxx");

	printf("SetMonsterHealth: %x \n", SetMonsterHealth);

	GetInfinityDungeonInfo = (oGetInfinityDungeon)FindSignatureCall(1, (PBYTE)"\xE8\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x8B\xF8\x6A\x00\x6A\x01\xE8\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00", "x????xx????xxxxxxx????xx????");

	printf("GetInfinityDungeonInfo: %x \n", GetInfinityDungeonInfo);

	GetKGCWorldManager = (oGetKGCWorldManager)FindSignatureCall(1, (PBYTE)"\xE8\x00\x00\x00\x00\x8B\x50\x28\xA1\x00\x00\x00\x00\x88\x90\x00\x00\x00\x00\x80\x3D\x00\x00\x00\x00\x00", "x????xxxx????xx????xx?????");

	printf("GetKGCWorldManager: %x \n", GetKGCWorldManager);

	pkItem = (cItemManager*)FindSignaturePointer(2, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x84\xC0\x75\x7B\xEB\x70\x83\xFE\xFF", "xx????x????x????xxxxxxxxx");

	printf("pkItem: %x \n", pkItem);

	SetShowDialogue = (oSetShowDialogue)FindSignature((PBYTE)"\x53\x8B\x5C\x24\x08\x56\x57\x8B\xF9\x53\x8B\x8F\x00\x00\x00\x00", "xxxxxxxxxxxx????");

	printf("SetShowDialogue: %x \n", SetShowDialogue);

	GetDrop = (oGetDrop)FindSignatureCall(1, (PBYTE)"\xE8\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x8B\x75\x94\x8B\x7D\x98\x3B\xF7\x0F\x84\x00\x00\x00\x00", "x????xxx????xxxxxxxxxx????");

	printf("GetDrop: %x \n", GetDrop);

	StartButtonPress = (oStartButtonPress)FindSignature((PBYTE)"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x0C\x56\xA1\x00\x00\x00\x00\x33\xC5\x50\x8D\x45\xF4\x64\xA3\x00\x00\x00\x00\xC6\x05\x00\x00\x00\x00\x00\xC7\x05\x00\x00\x00\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00", "xxxxxx????xx????xxxxxx????xxxxxxxx????xx?????xx????????xx?????");

	printf("StartButtonPress: %x \n", StartButtonPress);

	/*	

	SetMagicEffect = (oActiveBuff)FindSignature((PBYTE)"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x78\x56\xA1\x00\x00\x00\x00\x33\xC5\x50\x8D\x45\xF4\x64\xA3\x00\x00\x00\x00\x89\x4D\xEC\x0F\xB6\x45\x1C\x85\xC0\x74\x41\xC7\x45\x00\x00\x00\x00\x00", "xxxxxx????xx????xxxxxx????xxxxxxxx????xxxxxxxxxxxxx?????");
		
	printf("tActiveBuff: %x \n", SetMagicEffect);

	BuffActive_Class = FindSignaturePointer(2, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xEB\x1A\x6A\x00\x6A\x00\x6A\x00", "xx????x????xxxxxxxx");

	printf("BuffActive_Class: %x \n", BuffActive_Class);

	*/

	VIRTUALIZER_FISH_WHITE_END
}

KItem* cMain::GetInventoryItemByID(GCITEMID ID)
{
	cKCItemManager* kItemManager = pkItem->Manager;

	if (kItemManager && kItemManager->ItemList.size())
	{
		auto it = kItemManager->ItemList.begin();

		for (; it != kItemManager->ItemList.end(); ++it)
			if (it->second->m_ItemID == ID)
				return it->second;
	}

	return NULL;
}

KItem* cMain::GetInventoryItemByUID(GCITEMUID ID)
{
	cKCItemManager* kItemManager = pkItem->Manager;

	if (kItemManager && kItemManager->ItemList.size())
	{
		auto it = kItemManager->ItemList.begin();

		for (; it != kItemManager->ItemList.end(); ++it)
			if (it->second->m_ItemUID == ID)
				return it->second;
	}

	return NULL;
}

cKGCScene* cMain::GetChildrenByName(cKGCScene* pScene, char* szName)
{
	for (int i = 0; i < pScene->m_vChildren.size(); i++)
		if (pScene->m_vChildren[i]->szName.find(szName) != string::npos)
			return pScene->m_vChildren[i];
		
	return NULL;
}

void cMain::DimensionSpeedUp()
{
	if (IsDimensional())
		if (pEveryTriggerManager->m_vtActiveTrigger.size() && pEveryTriggerManager->m_vtActiveTrigger[0] && pEveryTriggerManager->m_vtActiveTrigger[0]->pChildren)
		{
			cTGInfinityMonsterGen* pInfinityMonsterGen = pEveryTriggerManager->m_vtActiveTrigger[0]->pChildren->pInfinityMonsterGen;

			if (pInfinityMonsterGen)
			{
				pInfinityMonsterGen->m_RestartSpawn.dwMax = 1;
				pInfinityMonsterGen->m_MobSpawn.dwMax = 55;
				pInfinityMonsterGen->m_WaitBoss.dwMax = 1;
				pInfinityMonsterGen->m_BestBoss.dwMax = 99999;

				if (pInfinityMonsterGen->m_RestartSpawn.dwCurrent > pInfinityMonsterGen->m_RestartSpawn.dwMax + 5)
					pInfinityMonsterGen->m_RestartSpawn.dwCurrent = 0;

				if (pInfinityMonsterGen->m_MobSpawn.dwCurrent > pInfinityMonsterGen->m_MobSpawn.dwMax + 5)
					pInfinityMonsterGen->m_MobSpawn.dwCurrent = 0;

				if (pInfinityMonsterGen->m_BestBoss.dwCurrent > pInfinityMonsterGen->m_BestBoss.dwMax + 5)
					pInfinityMonsterGen->m_BestBoss.dwCurrent = 0;

				if (pInfinityMonsterGen->m_WaitBoss.dwCurrent > pInfinityMonsterGen->m_WaitBoss.dwMax + 5)
					pInfinityMonsterGen->m_WaitBoss.dwCurrent = 0;
			}
		}
}

void cMain::ChangeInfinitySpawnQuantity(int Quantity)
{
	for (auto InfinityInfo : GetInfinityDungeonInfo()->m_mapInfintyDungeon)
		for (int i = 0; i < InfinityInfo.second.m_MonsterQuantity.GetSize(); i++)
			InfinityInfo.second.m_MonsterQuantity.Data->Value[i] = Quantity;
}

void cMain::ChangeInfinityMonster(int dwMap, int Model)
{
	for (auto InfinityInfo : GetInfinityDungeonInfo()->m_mapInfintyDungeon)
		if (InfinityInfo.second.dwDungeonId == dwMap)
			for (auto SpawnInfo : InfinityInfo.second.m_mapMonsterSpawnInfo)
				for (int i = 0; i < SpawnInfo.second.m_Monster.GetSize(); i++)
					SpawnInfo.second.m_Monster.Data->Value[i] = Model;
}

void cMain::SetInfinity()
{
	auto it = GetKGCWorldManager()->m_mapDungeonInfo.begin();

	for (; it != GetKGCWorldManager()->m_mapDungeonInfo.end(); ++it)
	{
		//if (it->second.m_emGameMode == ::GC_GM_QUEST77)
		it->second.m_emGameMode = GC_GM_QUEST79;

		it->second.m_emDungeonType = EM_DUNGEON_TYPE::DUNGEON_TYPE_NORMAL;
	}
}

void cMain::ChangeInfinityLevel(int Level)
{
	cInfinityDungeon* pInfinityDungeon = GetInfinityDungeonInfo();

	for (auto it = pInfinityDungeon->m_mapInfintyDungeon.begin(); it != pInfinityDungeon->m_mapInfintyDungeon.end(); ++it)
		for (auto monsterIt = it->second.m_mapMonsterSpawnInfo.begin(); monsterIt != it->second.m_mapMonsterSpawnInfo.end(); ++monsterIt)
			monsterIt->second.dwLevel = Level;
}

int cMain::GetStage()
{
	return pEveryTriggerManager->m_Stage.Decrypt();
}

void cMain::SetStage(int Stage)
{
	pEveryTriggerManager->m_Stage.Encrypt(Stage);
	pEveryTriggerManager->m_RenderStage.Encrypt(Stage);
}

void cMain::MagneticGP()
{
	CPlayer* pLocalPlayer = GetLocalPlayer();

	if (pLocalPlayer)
	{
		for (auto pGP : GetDrop()->m_mapGpDrop)
		{
			if (pGP.second->m_iTime)
				pGP.second->m_vPos = pLocalPlayer->m_vPosition;
		}
	}
}

void cMain::SetDialogueOff()
{
	if (pOverlay->pGameOverlayUI->bIsShowDialogue)
	{
		Timer_Dialogue.Start(1000);
		SetShowDialogue(pOverlay->pGameOverlayUI, 0, 0);
	}
}

void cMain::AutoEnchant(int nLevel, bool bBuy, int uiGemQtd)
{
	KItem* kItem = GetInventoryItemByID(888);

	if (kItem && kItem->m_nCount >= 3)
	{
			cKGCScene* pScene = pGameScene->pCurrentScene->pUIScene->pCurrentUI;

			if (pScene && pScene->szName.find(Xor("necklace_enchant_dlg")) != string::npos)
			{
				KGCNewNecklaceEnchantDlg* pNecklace = (KGCNewNecklaceEnchantDlg*)pScene;

				if (pNecklace)
				{
					if (pNecklace->m_Count > 61)
						pNecklace->m_Count = 61;

					if (pNecklace->nLevel < nLevel && !pNecklace->m_Result && !Timer_Enchant.Running())
					{
						Send_StrongLevelUpReq(pNecklace);
						Timer_Enchant.Start(1000);
					}
				}
			}
	}
	else if (bBuy && !Timer_BuyGem.Running())
	{
		Send_BuyItemForGPReq(*(DWORD*)KP2P, 888 * 10, uiGemQtd, -1);
		Timer_BuyGem.Start(2000);
	}
}

DWORD cMain::GetGameTime()
{
	return pMission->pMissionInfo->m_GameTime.Decrypt();
}

void cMain::ForceDrop()
{
	for (auto pItem : GetDrop()->m_mapItemDrop)
		if (pItem.second->m_iState == -1)
			MonsterObserverForDropItem(pItem.second->m_iTriggerID, GetLocalPlayer()->m_vPosition);
}

void cMain::ActiveBuff(int dwBuffId, float Duration)
{
	SetMagicEffect(*(DWORD*)BuffActive_Class, 0, dwBuffId, Duration, 1, -1, true, false, 0);
}

void cMain::PredictionItem(vector<char*> & vec)
{
	for (auto pItem : GetDrop()->m_mapItemDrop)
	{
		char* szTexto = new char[120];

		sprintf(szTexto, Xor("%ls"), pItem.second->m_strName.c_str());

		vec.push_back(szTexto);
	}
}

void cMain::ImportContinentBoss()
{
	v_ElliaBoss.push_back(73); // Dark Amon
	v_ElliaBoss.push_back(53); // Giant Stone Golem
	v_ElliaBoss.push_back(25); // Cyclope
	v_ElliaBoss.push_back(24); // Kazeaze
	v_ElliaBoss.push_back(52); // Gadosen
	v_ElliaBoss.push_back(51); // Basilisk
	v_ElliaBoss.push_back(21); // Kamiki
	v_ElliaBoss.push_back(81); // Patusei Head
	v_ElliaBoss.push_back(82); // Patusei Body
	v_ElliaBoss.push_back(83); // Patusei Legs

	v_XeniaBoss.push_back(208); // Thanatos T3
	v_XeniaBoss.push_back(192); // Divine Tree
	v_XeniaBoss.push_back(178); // Periot
	v_XeniaBoss.push_back(168); // Jurior
	v_XeniaBoss.push_back(144); // Zig
	v_XeniaBoss.push_back(129); // Bultaros
	v_XeniaBoss.push_back(118); // Samsara
	v_XeniaBoss.push_back(120); // Octus
	v_XeniaBoss.push_back(119); // Lenasien

	v_AtonBoss.push_back(660); // Immortal Barakup
	v_AtonBoss.push_back(640); // Kapu 
	v_AtonBoss.push_back(864); // Karte Infinity
	v_AtonBoss.push_back(648); // Karte Normal
	v_AtonBoss.push_back(246); // Sand Ruler
	v_AtonBoss.push_back(227); // Kungji Elder
	v_AtonBoss.push_back(221); // Hatshepsut
	v_AtonBoss.push_back(215); // Setesh

}

bool cMain::ExistThisLoot(int Id)
{
	auto it = find(v_FilterId.begin(), v_FilterId.end(), Id);

	if (it != v_FilterId.end())
		return true;

	return false;
}

void cMain::MagneticFilter()
{
	CPlayer* pLocalPlayer = GetLocalPlayer();

	if (pLocalPlayer)
	{
		for (auto pItem : GetDrop()->m_mapItemDrop)
		{
			if (pItem.second->m_iTime)
				if (ExistThisLoot(pItem.second->m_dwGoodsID))
					pItem.second->m_vPos = pLocalPlayer->m_vPosition;
				else
					pItem.second->m_vPos = D3DXVECTOR2(999, 999);
		}
	}
}

void cMain::MagneticItem()
{
	CPlayer* pLocalPlayer = GetLocalPlayer();

	if (pLocalPlayer)
	{
		for (auto pItem : GetDrop()->m_mapItemDrop)
		{
			if (pItem.second->m_iTime)
				pItem.second->m_vPos = pLocalPlayer->m_vPosition;
		}
	}
}

void cMain::SetGameTime(int GameTime)
{
	pMission->pMissionInfo->m_GameTime.Encrypt(GameTime);
}

void cMain::SetHitCount(int Hitcount)
{
	pMission->pMissionInfo->m_iAttackCount = Hitcount;
}



void cMain::SetComboRatio(float fRatio)
{
	pQuest->pQuestGameManager->m_fRankPoint.Encrypt(fRatio);
//	pQuest->pQuestGameManager->m_ComboRatioSlime.Encrypt(fRatio * 2);
}

void cMain::SetTotalComboRatio(int fRatio)
{
	pQuest->pQuestGameManager->m_ComboDamage.Encrypt(fRatio);
}

void cMain::SetTotalCombo(int Combo)
{
	pQuest->pQuestGameManager->m_MaxCombo.Encrypt(Combo);

	CPlayer* pPlayer = GetLocalPlayer();

	if (pPlayer)
		pPlayer->m_iControlInfoComboCount = Combo;
}

void cMain::SetComboDamage(int Dmg)
{
	pQuest->pQuestGameManager->m_MaxComboDamage.Encrypt(Dmg);
}

void cMain::SetReceivedHits(int ReceivedHits)
{
	pQuest->pQuestGameManager->m_TotalDamageFromMonster.Encrypt(ReceivedHits);

	CPlayer* pPlayer = GetLocalPlayer();

	if (pPlayer)
		pPlayer->m_iControlInfoBeAttackedCount = ReceivedHits;
}

void cMain::SetAerialCombo(int Dmg)
{
	pQuest->pQuestGameManager->m_TotalBackPlusAerialAttack.Encrypt(Dmg);

	CPlayer* pPlayer = GetLocalPlayer();

	if (pPlayer)
		pPlayer->m_iControlInfoBackAttackCount = Dmg;
}

void cMain::SetMonsterKilled(int Qtd)
{
	pQuest->pQuestGameManager->m_KillCombo.Encrypt(Qtd);
}

void cMain::SetBossKilled(int Qtd)
{
	pQuest->pQuestGameManager->m_BossKillCombo.Encrypt(Qtd);
}

void cMain::SetDimensionLevelFake(int Level)
{
	pQuest->pQuestGameManager->m_InfinityDungeonMonsterLevel.Encrypt(Level);
}

void cMain::SetComboElimination(int Dmg)
{
	pQuest->pQuestGameManager->m_MaxKillCombo.Encrypt(Dmg);
}

void cMain::SetDimensionWaveCount(int WaveCount)
{
	GetInfinityDungeonInfo()->dwWaveSpawned = WaveCount;
}

void cMain::PrintMonsters()
{
	auto it = pMonsterMgr->m_mapMonster.begin();

	for (; it != pMonsterMgr->m_mapMonster.end(); ++it)
		if (it->second)
			printf(Xor("%x - %ls - %d - %d\n"), it->second, it->second->m_strMonsterName.c_str(), it->second->m_iMonsterType, it->second->m_iTriggerID);
}

void cMain::KillDimensionalPortal()
{
	auto it = pMonsterMgr->m_mapMonster.begin();

	for (; it != pMonsterMgr->m_mapMonster.end(); ++it)
		if (it->second && it->second->m_Health.Decrypt() && it->second->m_iMonsterType == 863)
			SetMonsterHealth(it->second, 0);
}

void cMain::SetALLHPMonster(float Health)
{
	auto it = pMonsterMgr->m_mapMonster.begin();

	for (; it != pMonsterMgr->m_mapMonster.end(); ++it)
		if (it->second && it->second->m_iMonsterType != 863)
			SetMonsterHealth(it->second, Health);
}

CMonster* cMain::GetMonsterByTGID(int TGID)
{
	auto it = pMonsterMgr->m_mapMonster.begin();

	for (; it != pMonsterMgr->m_mapMonster.end(); ++it)
		if (it->second && it->second->m_iTriggerID == TGID)
			return it->second;

	return NULL;
}

bool cMain::IsDimensional()
{
	if (GetGameState() == GS_GAME && pQuest->pQuestGameManager->m_mapStageHistory.size() == 1 && pQuest->pQuestGameManager->m_InfinityDungeonMonsterLevel.Decrypt() != 0)
		return true;

	return false;
}

bool cMain::IsAnyMonsterAlive()
{
	auto it = pMonsterMgr->m_mapMonster.begin();

	for (; it != pMonsterMgr->m_mapMonster.end(); ++it)
		if (it->second && it->second->m_Health.Decrypt())
			return true;

	return false;
}

int cMain::GetMonsterCount()
{
	return pMonsterMgr->m_mapMonster.size();
}

bool cMain::IsEnterInPortal()
{
	auto it = pPortalMng->m_mapPortal.begin();

	for (; it != pPortalMng->m_mapPortal.end(); ++it)
		if (it->first)
			if (it->first && it->first->m_bIsOpen && it->first->dwPortalCode == 2)
				return true;

	return false;
}

float cMain::GetDistanceBetween(float* Original, float* Target)
{
	double nDX = Original[0] - Target[0];
	double nDY = Original[1] - Target[1];

	double nRes = sqrt(nDX*nDX + nDY*nDY);

	return nRes;
}

cKGCPortal* cMain::GetFarestPortal()
{
	FLOAT fNearby = 0;
	CPlayer* pPlayer = GetLocalPlayer();
	cKGCPortal* pPortal = NULL;
	
	if (pPlayer)
	{
		auto it = pPortalMng->m_mapPortal.begin();

		for (; it != pPortalMng->m_mapPortal.end(); ++it)
			if (it->first)
				if (it->first && it->first->m_bIsOpen)
				{
					float Dist = GetDistanceBetween(pPlayer->m_vPosition, it->first->m_vPos);

					if (Dist >= fNearby)
					{
						fNearby = Dist;
						pPortal = it->first;
					}
				}
	}

	return pPortal;
}

void cMain::AutoPortal()
{
	CPlayer* pPlayer = GetLocalPlayer();

	if (pPlayer && !IsEnterInPortal())
	{
		cKGCPortal* pPortal = GetFarestPortal();

		if (pPortal)
		{
			pPlayer->m_vPosition = pPortal->m_vPos;
			pPortal->dwPortalCode = 2;
		}
	}
}

void cMain::AutoStart()
{
	if (GetGameState() == GS_ROOM && !Timer_StartTimer.Running())
	{
		cKGCScene* pScene = GetChildrenByName(pGameScene->pCurrentScene, Xor("room_button_panel"));
		
		if (pScene)
		{
			StartButtonPress(pScene);

			Timer_StartTimer.Start(1.25f);
		}
	}
}

wchar_t * ToWideChar(const char * name)
{
	wchar_t * pwcsName = new wchar_t[256];
	MultiByteToWideChar(CP_ACP, 0, name, -1, (LPWSTR)pwcsName, 256);
	return pwcsName;
}

int cMain::GetContinentBoss(int dwMap, int Idx)
{
	if (dwMap == 98)
		return v_ElliaBoss[Idx];

	if (dwMap == 99)
		return v_XeniaBoss[Idx];

	if (dwMap == 100)
		return v_AtonBoss[Idx];

	return 1;
}

void cMain::SetEquipLevel(int Level)
{
	auto it = pkItem->Manager->m_mapDB.begin();

	for (; it != pkItem->Manager->m_mapDB.end(); ++it)
	{
		cItemInfo* pFTItem = it->second;

		if (pFTItem)
			pFTItem->dwLevel = Level;
	}
}

void cMain::AddLootThroughLoad(int Id)
{
	if (!ExistThisLoot(Id))
	{
		v_FilterId.push_back(Id);

		auto it = pkItem->Manager->m_mapDB.find(Id);

		if (it != pkItem->Manager->m_mapDB.end())
		{
			cItemInfo* pFTItem = it->second;

			if (pFTItem)
			{
				char* szTxt = new char[128];

				sprintf(szTxt, Xor("%ls"), pFTItem->szName.c_str());
				v_szFilter.push_back(szTxt);
			}
		}
	}
}

void cMain::AddPrefix(char* szPrefix)
{
	auto it = pkItem->Manager->m_mapDB.begin();

	for (; it != pkItem->Manager->m_mapDB.end(); ++it)
	{
		cItemInfo* pFTItem = it->second;

		if (pFTItem)
		{
			wchar_t* pName = ToWideChar(szPrefix);

			if (pFTItem->szName.find(pName) != wstring::npos)
				AddLootThroughLoad(pFTItem->dwId);
		}
	}
}

void cMain::AddLoot(int Id)
{
	if (!ExistThisLoot(v_Loot[Id]))
	{
		v_FilterId.push_back(v_Loot[Id]);
		v_szFilter.push_back(v_szLoot[Id]);
	}
}

void cMain::RmvLoot(int Id)
{
	auto it = find(v_FilterId.begin(), v_FilterId.end(), v_FilterId[Id]);

	if (it != v_FilterId.end())
		v_FilterId.erase(it);

	auto it1 = find(v_szFilter.begin(), v_szFilter.end(), v_szFilter[Id]);

	if (it1 != v_szFilter.end())
		v_szFilter.erase(it1);
}

void cMain::SearchLoot(char* szLoot)
{
	v_Loot.clear();
	v_szLoot.clear();

	auto it = pkItem->Manager->m_mapDB.begin();

	for (; it != pkItem->Manager->m_mapDB.end(); ++it)
	{
		cItemInfo* pFTItem = it->second;

		if (pFTItem)
		{
			wchar_t* pName = ToWideChar(szLoot);

			if (pFTItem->szName.find(pName) != string::npos)
			{
				char* szTxt = new char[256];
				
				v_Loot.push_back(pFTItem->dwId);
				sprintf(szTxt, Xor("%ls"), pFTItem->szName.c_str());
				v_szLoot.push_back(szTxt);
			}			
		}
	}
}

void cMain::AutoKill()
{
	if (!pOverlay->pGameOverlayUI->bIsShowDialogue && IsAnyMonsterAlive() && !Timer_Dialogue.Running())
		SetALLHPMonster(0);
}

DWORD cMain::GetGame()
{
	DWORD dwApp = *(DWORD*)MyD3DApp;

	DWORD dwGameState = *(DWORD*)(dwApp + GAMESTATE);

	return dwGameState;
}

DWORD cMain::GetGameState()
{
	DWORD dwApp = *(DWORD*)MyD3DApp;

	if (dwApp)
	{
		DWORD dwGameState = *(DWORD*)(dwApp + GAMESTATE);

		if (dwGameState)
		{
			cGameState* pGameState = (cGameState*)dwGameState;

			if (pGameState)
			{

				return pGameState->m_CurrentState.Decrypt();
			}
		}
	}

	return 9999;
}


CPlayer* cMain::GetLocalPlayer()
{
	return oGetLocalPlayer(*(DWORD*)MyD3DApp);
}