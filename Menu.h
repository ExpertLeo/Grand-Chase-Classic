class cMenu
{
public:
	cMenu();

	void Design();

	void Draw_Dashboard();
	void Draw_Cheats();
	void Draw_GameResult();
	void Draw_Farming();
	void Draw_Dimensional();
	void Draw_Loot();
	void Draw_Config();
	void Draw_Dev();
	void Draw_Automations();

	void Function_Cheats();
	void Function_MissionResult();

	CTimer* Timer_DebugPresent;
	CTimer* Timer_CheckWiindow;
	CTimer* Timer_ApiHook;

	int dwSpeedFactor, dwStageHack;
	bool bEnableSpeed, bStageHack;

public:
	bool bMenuPos[9], bMenuOpen[5];

	int uiMenuCode = 0;

	vector<char*> szPrediction;

	/* CHEATS */
	bool bAtt, bDef, bHp, bMp, bCriChance, bCritDmg, bAutoStart, bAutoKill, bSkillCooldown, bAutoPortal, bSkillModifier[3], bAutoLoot, bLootType[2], bForceLoot, bSkipDialogue;
	float fAtt, fDef, fCriChance, fCritDmg;
	int uiSkillModifier[3], dwSkillOwner;

	bool bAutoEnchant, bAutoBuy;
	int uiEnchantLevel, uiGemQtd;

	char szSearchLoot[64];

	/* RESULTS */
	bool bMissionTimer, bComboHits, bComboRatio, bTotalComboScore, bComboDmg, bComboReceive, bAerialCombo, bComboEliminations, bRandomStatus, bKillPortalAtTime, bMagneticFilter, bDimensionalLevel, bDimensionalSpawnQtd, bLevelHack, bDimensionLevelFake, bDimensionWaveCount, bDimensionKilledMonster, bDimensionKilledBoss, bDimensionalSpawnModel;
	int uiMissionTimer, uiComboHits, uiComboDmg, uiComboReceived, uiAerialCombo, uiComboElimination, uiBuffId, uiDimensionalLevel, uiDimensionalSpawnQtd, uiDimensionKills, uiDimensionBossKills, uiDimensionFakeLevel, uiSpawnId, uiDimensionWaveCount;
	int uiRandMissionTimer, uiRandComboHits, uiRandComboDmg, uiRandDimensionWaveCount, uiRandComboReceived, uiRandAerialCombo, uiRandComboElimination, uiRandHitCount, uiKillPortalTimer, uiRandFakeLevel, uiRandMonsterKill, uiRandBossKill, uiContinentSpawn, uiMonsterSpawnEllia, uiMonsterSpawnXenia, uiMonsterSpawnAton, uiTotalComboScore, uiRandComboScore;
	float fComboRatio, fRandComboRatio;

	int uiCurrentPrediction = 0, uiCurrentLoot = 0, uiCurrentFilter = 0;
};

extern cMenu* Menu;