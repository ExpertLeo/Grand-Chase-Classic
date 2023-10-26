class cMain
{
public:
	cMain();

private:
	typedef int(__thiscall* oGetPlayerIndex)(int MyD3DApp);
	typedef CPlayer*(__thiscall* tGetLocalPlayer)(int MyD3DApp);
	typedef int(__thiscall* oGetPlayerBaseByIndex)(int Class, int Index);
	typedef CPlayer*(__thiscall* oGetPlayer)(int nResult);
	typedef void(__thiscall* oSetHPALLMonster)(int a1, int Health, DWORD a2);
	typedef cKGCDropManager*(*oGetDrop)();
	typedef void(__thiscall* oSetMonsterHealth)(CMonster* pMonster, float Health);
	typedef void(__thiscall* oStartButtonPress)(cKGCScene* pRoomSceneS6);
	typedef void(__thiscall* oSetShowDialogue)(cKGCGameOverlayUI* GameOverlay, int Value, __int8 Unk);
	typedef void(__thiscall* oActiveBuff)(int a1, int iPlayerIndex_, int iBuffIndex_, float fBuffTime_, int iBuffLevel_, int iIndex_, bool bIsCrashPlayer, bool bAccTime_, int dwAttackUnit);
	typedef void(__thiscall* oSelectReward)(cKGCScene* RewardS4_row0, int RewardIndex);
	typedef cItemInfo* (__thiscall* oGetItemInfo)(int a1, int Id);
	typedef int(__thiscall* oDecryptGameState)(int GameBase);
	typedef cInfinityDungeon* (__thiscall* oGetInfinityDungeon)();
	typedef void(__thiscall* oSend_StrongLevelUpReq)(KGCNewNecklaceEnchantDlg* KP2P);
	typedef void(__thiscall* oSend_BuyItemForGPReq)(int KP2P, DWORD dwGoodsID_, int iDuration, int iPeriod);
	typedef cKGCWorldManager*(*oGetKGCWorldManager)();
	typedef int(*oGetKP2P)();
	typedef void(__cdecl* oMonsterObserverForDropItem)(int iTriggerID, D3DXVECTOR2 vPos);
	typedef void(__thiscall* oAddMonKillNum)(cKGCGameBoard* g_pGameBoard, int iMon, int iMonNum, int iTGID);
	typedef void(__thiscall* oVirtualKill)(DWORD kUserMission, DWORD m_iMonsterType, int m_iLevel, int m_eNPC);
	typedef void(__thiscall* oShowExp)(CMonster* pMonster);
	float GetDistanceBetween(float* Original, float* Target);
	bool ExistThisLoot(int Id);
	void ImportContinentBoss();

	enum MAINOFFSETS
	{
		PLAYERBASE = 0x2C2E8, //0x2C19C
		GAMESTATE = 0x2C274, // 0x2C16C
		INVENTORYMANAGER = 0x35448
	};

	CTimer Timer_StartTimer;

	DWORD MyD3DApp;
	cMonsterManager* pMonsterMgr;
	cPortalManager* pPortalMng;
	cGameOverlay* pOverlay;
	CEveryTriggerManager* pEveryTriggerManager;
	cItemManager* pkItem;
	DWORD BuffActive_Class;
	DWORD ItemInfo_Class;

	oGetInfinityDungeon GetInfinityDungeonInfo;
	oSetShowDialogue SetShowDialogue;
	oDecryptGameState DecryptGameState;
	
	DWORD KP2P;
	oGetKP2P GetKP2P;
	oSetMonsterHealth SetMonsterHealth;
	oSend_StrongLevelUpReq Send_StrongLevelUpReq;
	oSend_BuyItemForGPReq Send_BuyItemForGPReq;
	oSelectReward SelectReward;
//	oGetItemInfo GetItemInfo;	
	oGetDrop GetDrop;
	oGetKGCWorldManager GetKGCWorldManager;
	

	CTimer Timer_BossSpawn, Timer_Dialogue, Timer_Enchant, Timer_BuyGem;
public:
	DWORD EncryptionTable;
	oActiveBuff SetMagicEffect;
	cRoomScene* pRoomScene;
	oStartButtonPress StartButtonPress;
	cGameScene* pGameScene;
	cMission* pMission;
	oMonsterObserverForDropItem MonsterObserverForDropItem;
	oAddMonKillNum AddMonKillNum;
	oVirtualKill VirtualKill;
	DWORD kUserMission;
	oShowExp ShowExp;
	KEndGameReq kNot;
	KEndGameReq kNot2;
	enum GAMESTATES
	{
		GS_ROOM = 6,
		GS_GAME = 7,
		GS_LOADING = 11,
		GS_SERVER = 15,
		GS_WORLDMAP = 16,
	};

	cQuest* pQuest;

	cKGCScene* GetChildrenByName(cKGCScene* Scene, char* szName);

	KItem* GetInventoryItemByID(GCITEMID ID);
	KItem* GetInventoryItemByUID(GCITEMUID ID);

	void SetInfinity();

	void ChangeInfinityLevel(int Level);
	void ChangeInfinityMonster(int dwMap, int Model);
	void ChangeInfinitySpawnQuantity(int Quantity);

	int GetStage();
	void SetStage(int Stage);
	void DimensionSpeedUp();
	void MagneticGP();
	void MagneticItem();
	void MagneticFilter();
	void PredictionItem(vector<char*> & vec);
	void ActiveBuff(int dwBuffId, float Duration);
	DWORD GetGameTime();
	void AutoEnchant(int nLevel, bool bBuy, int uiGemQtd);
	void SetDialogueOff();
	void ForceDrop();
	void KillDimensionalPortal();
	void SetGameTime(int GameTime);
	void SetHitCount(int Hitcount);
	void SetComboRatio(float fCombo);
	void SetTotalComboRatio(int fTotalCombo);
	void SetTotalCombo(int Combo);
	void SetComboDamage(int Dmg);
	void SetReceivedHits(int ReceivedHits);
	void SetAerialCombo(int Dmg);
	void SetComboElimination(int Dmg);
	void SetMonsterKilled(int Qtd);
	void SetBossKilled(int Qtd);
	void SetDimensionLevelFake(int Level);
	void SetALLHPMonster(float Health);
	void SetDimensionWaveCount(int WaveCount);
	void PrintMonsters();
	bool IsAnyMonsterAlive();
	bool IsDimensional();
	int GetMonsterCount();
	CMonster* GetMonsterByTGID(int TGID);
	void AutoStart();
	void AutoKill();
	void AutoPortal();
	bool IsEnterInPortal();
	DWORD GetGameState();
	DWORD GetGame();
	DWORD GetPlayerBase(int Idx);
	CPlayer* GetLocalPlayer();
	cKGCPortal* GetFarestPortal();
	void SetEquipLevel(int Level);
	int GetContinentBoss(int dwMap, int Idx);
	tGetLocalPlayer oGetLocalPlayer;

	void SearchLoot(char* szLoot);
	void AddLoot(int Id);
	void RmvLoot(int Id);
	void AddLootThroughLoad(int Id);
	void AddPrefix(char* szPrefix);
	vector<DWORD> v_Loot;
	vector<DWORD> v_FilterId;
	vector<char*> v_szLoot;
	vector<char*> v_szFilter;
	vector<DWORD> v_XeniaBoss;
	vector<DWORD> v_ElliaBoss;
	vector<DWORD> v_AtonBoss;
};

extern cMain* GrandChase;