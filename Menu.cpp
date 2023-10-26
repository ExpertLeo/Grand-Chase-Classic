#include "include.h"

cMenu* Menu;

cMenu::cMenu()
{
	//ZeroMemory(bMenuPos, sizeof(bMenuPos));
	//ZeroMemory(bMenuOpen, sizeof(bMenuOpen));
	bAutoBuy = false;
	uiGemQtd = 3;
	bAutoEnchant = false;
	uiEnchantLevel = 6;

	sprintf(szSearchLoot, "");
	bMagneticFilter = false;
	bDimensionalLevel = false;
	bDimensionalSpawnQtd = false;
	bDimensionalSpawnModel = false;

	uiMonsterSpawnEllia = 0;
	uiMonsterSpawnXenia = 0;
	uiMonsterSpawnAton = 0;
	uiContinentSpawn = 0;
	bTotalComboScore = false;
	uiMenuCode = 0;
	uiDimensionWaveCount = 1;
	bDimensionWaveCount = false;

	uiSpawnId = 1;
	uiDimensionalLevel = 99;
	uiDimensionalSpawnQtd = 15;
	bLevelHack = false;

	bMenuOpen[0] = false;
	bMenuOpen[1] = false;
	bMenuOpen[2] = false;
	bMenuOpen[3] = false;
	bMenuOpen[4] = false;

	bMenuPos[0] = false;
	bMenuPos[1] = false;
	bMenuPos[2] = false;
	bMenuPos[3] = false;
	bMenuPos[4] = false;
	bMenuPos[5] = false;
	bMenuPos[6] = false;
	bMenuPos[7] = false;
	bMenuPos[8] = false;

	bSkillModifier[0] = false;
	bSkillModifier[1] = false;
	bSkillModifier[2] = false;
	
	uiSkillModifier[0] = false;
	uiSkillModifier[1] = false;
	uiSkillModifier[2] = false;
	
	bAtt = false;
	bDef = false;
	bHp = false; 
	bMp = false;
	bCriChance = false; 
	bCritDmg = false;

	fAtt = 20000;
	fDef = 20000;
	fCriChance = 10;
	fCritDmg = 10;

	dwSpeedFactor = 3;
	bEnableSpeed = false;
	dwStageHack = 999;
	bStageHack = false;

	Timer_DebugPresent = new CTimer();
	Timer_CheckWiindow = new CTimer();
	Timer_ApiHook = new CTimer();

	bSkipDialogue = false;
	bAutoKill = false;
	bSkillCooldown = false;
	dwSkillOwner = 9999;

	bMissionTimer= false;
	bComboHits= false;
	bComboRatio= false;
	bComboDmg= false; 
	bComboReceive= false; 
	bAerialCombo= false; 
	bComboEliminations= false;
	bRandomStatus = false;
	uiMissionTimer = 500;
	uiComboHits = 20;
	uiComboDmg = 2750;
	uiComboReceived = 0;
	uiAerialCombo = 7;
	uiComboElimination = 4;
	fComboRatio = 40000;

	bAutoStart = false;
	bKillPortalAtTime = false;
	

	bAutoPortal = false;
	bAutoLoot = false;
	bForceLoot = false;
	bLootType[0] = true;
	bLootType[1] = true;

}

void cMenu::Design()
{
	ImGuiStyle* style = &ImGui::GetStyle();
	ImVec4* colors = ImGui::GetStyle().Colors;

	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	style->Alpha = 1.f;
	style->WindowRounding = 4.f;
	style->FramePadding = ImVec2(4, 3);
	style->WindowPadding = ImVec2(8, 8);
	style->ItemInnerSpacing = ImVec2(4, 4);
	style->ItemSpacing = ImVec2(8, 4);
	style->FrameRounding = 5.f;
	style->ScrollbarSize = 2.f;
	style->ScrollbarRounding = 12.f;
	style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style->IndentSpacing = 21.0f;
	style->DisplayWindowPadding = ImVec2(22, 22);
	style->DisplaySafeAreaPadding = ImVec2(4, 4);

	colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.13f, 0.13f, 0.97f);
	colors[ImGuiCol_Button] = ImVec4(0.74f, 0.02f, 0.02f, 0.55f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 0.00f, 0.00f, 0.61f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.98f, 0.00f, 0.00f, 0.88f);
	colors[ImGuiCol_Separator] = ImVec4(0.74f, 0.02f, 0.02f, 0.55f);

	colors[ImGuiCol_Header] = ImVec4(0.74f, 0.02f, 0.02f, 0.55f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(1.00f, 0.00f, 0.00f, 0.61f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.98f, 0.00f, 0.00f, 0.88f);

	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.74f, 0.02f, 0.02f, 0.55f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(1.00f, 0.00f, 0.00f, 0.61f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.98f, 0.00f, 0.00f, 0.88f);


	io.DeltaTime = 1.0f / 60.0f;
	io.Fonts->AddFontDefault();
}

static void HelpMarker(const char* desc)
{
	ImGui::TextDisabled(Xor("(?)"));
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

const char* Opt_Continent[] = { ("Ellia"),  ("Xenia"), "Aton" };
const char* Opt_Ellia[] = { ("Dark Amon"),  ("Giant Stone Golem"), ("Cyclops"),  ("Kazeaze"),   ("Gardosen"),  ("Basilisk"),  ("Kamiki"),  ("Patusay Head"), ("Patusay Body"),  ("Patusay Legs") };
const char* Opt_Xenia[] = { ("Thanatos"),  ("Divine Tree"),  ("Periot"),  ("Jurior"),  ("Zig"),  ("Bultaros"),  ("Samsara"),  ("Octus"),  ("Lanesien") };
const char* Opt_Aton[] = { "Immortal Barakhufu", "Karte (Infinity)", "Karte (Normal)", "Khufu", "Elder Kungji", "Hatshepsut", "Setesh" };

void cMenu::Draw_Dashboard()
{

	if (!bMenuPos[0])
	{
		ImGui::SetNextWindowPos(ImVec2(10, 10));
		bMenuPos[0] = true;
	}

	ImGui::SetNextWindowSize(ImVec2(550, 400));

	if (ImGui::Begin(Xor("MenuBackground"), 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar))
	{
		ImGui::Dummy(ImVec2(35, 0));
		ImGui::SameLine();
		ImGui::Text(Xor("Expert Hax"));

		ImGui::SameLine();

		ImGui::Dummy(ImVec2(130, 0));
		ImGui::SameLine();
		ImGui::Text(Xor("Grand Chase - v0.129"));

		ImGui::Separator();

		ImGui::BeginChild(Xor("##MenuBarChild"), ImVec2(150, 364), false);

		if (ImGui::Button(Xor("Farming"), ImVec2(149, 25)))
			uiMenuCode = 0;

		if (ImGui::Button(Xor("Loot"), ImVec2(149, 25)))
			uiMenuCode = 1;

		if (ImGui::Button(Xor("Player"), ImVec2(149, 25)))
			uiMenuCode = 2;

		if (ImGui::Button(Xor("Mission"), ImVec2(149, 25)))
			uiMenuCode = 3;

		if (ImGui::Button(Xor("Dimensional"), ImVec2(149, 25)))
			uiMenuCode = 4;

		if (ImGui::Button(Xor("Automations"), ImVec2(149, 25)))
			uiMenuCode = 6;

		if (ImGui::Button(Xor("Config"), ImVec2(149, 25)))
			uiMenuCode = 5;

		if (ImGui::Button(Xor("DEV"), ImVec2(149, 25)))
			uiMenuCode = 7;

		ImGui::EndChild();

		ImGui::SameLine();

		ImGui::VerticalSeparator();

		ImGui::SameLine();

		ImGui::BeginChild(Xor("##MenuBarChild2"), ImVec2(383, 364), false);
	
		switch (uiMenuCode)
		{
		case 0:
			Draw_Farming();
			break;
		case 1:
			Draw_Loot();
			break;
		case 2:
			Draw_Cheats();
			break;
		case 3:
			Draw_GameResult();
			break;
		case 4:
			Draw_Dimensional();
			break;
		case 5:
			Draw_Config();
			break;
		case 6:
			Draw_Automations();
			break;
		case 7:
			Draw_Dev();
			break;
		}

		ImGui::EndChild();
		ImGui::End();
	}

	

	/*if (bMenuOpen[0])
		Draw_Farming();

	if (bMenuOpen[1])
		Draw_GameResult();

	if (bMenuOpen[2])
		Draw_Cheats();

	if (bMenuOpen[3])
		Draw_Config();*/
}

void cMenu::Draw_Cheats()
{
	if (!bMenuPos[1])
	{
		ImGui::SetNextWindowSize(ImVec2(410, 283));
		ImGui::SetNextWindowPos(ImVec2(160, 10));
		bMenuPos[1] = true;
	}

//	if (ImGui::Begin("Status", &bMenuOpen[0], ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_ShowBorders))
	{
		ImGui::BeginGroup();
		ImGui::PushItemWidth(180);
		ImGui::Checkbox(Xor("Damage"), &bAtt);
		ImGui::SliderFloat(Xor("##AttHack"), &fAtt, 5000, 50000, "%.1f");
		ImGui::Checkbox(Xor("Defense"), &bDef);
		ImGui::SliderFloat(Xor("##DefHack"), &fDef, 5000, 50000, "%.1f");
		ImGui::Checkbox(Xor("Critical Chance"), &bCriChance);
		ImGui::SliderFloat(Xor("##CTHack"), &fCriChance, 1, 100, "%.1f");
		ImGui::Checkbox(Xor("Critical Damage"), &bCritDmg);
		ImGui::SliderFloat(Xor("##CDHack"), &fCritDmg, 1, 100, "%.1f");

		ImGui::Checkbox(Xor("Instant Heal"), &bHp);
		ImGui::Checkbox(Xor("Instant Mana Regen"), &bMp);

		
		ImGui::Checkbox(Xor("No Skill Cooldown"), &bSkillCooldown);
		if (ImGui::Button(Xor("Set Equip Level"), ImVec2(140, 25)))
			GrandChase->SetEquipLevel(1);
		ImGui::EndGroup();

		ImGui::SameLine();
		
		ImGui::BeginGroup();
	
		CPlayer* pLocal = GrandChase->GetLocalPlayer();

			ImGui::Checkbox(Xor("Enable Skill [A]"), &bSkillModifier[0]);

			if (ImGui::Button(Xor("Set Skill [A]"), ImVec2(120, 20)))
			{
				if (pLocal && (GrandChase->GetGameState() == cMain::GAMESTATES::GS_GAME || dwSkillOwner != 9999))
				{
					dwSkillOwner = pLocal->m_UserInfo.cCharIndex;
					uiSkillModifier[0] = pLocal->m_vSkillInfo[0]->dwSkillId;
				}
			}
			ImGui::SameLine();
			HelpMarker(Xor("Go to training, configure your skill bar then press here"));

			ImGui::Checkbox(Xor("Enable Skill [S]"), &bSkillModifier[1]);
			if (ImGui::Button(Xor("Set Skill [S]"), ImVec2(120, 20)))
			{
				if (pLocal && (GrandChase->GetGameState() == cMain::GAMESTATES::GS_GAME || dwSkillOwner != 9999))
				{
					dwSkillOwner = pLocal->m_UserInfo.cCharIndex;
					uiSkillModifier[1] = pLocal->m_vSkillInfo[1]->dwSkillId;
				}
			}
			ImGui::SameLine();
			HelpMarker(Xor("Go to training, configure your skill bar then press here"));

			ImGui::Checkbox(Xor("Enable Skill [D]"), &bSkillModifier[2]);
			if (ImGui::Button(Xor("Set Skill [D]"), ImVec2(120, 20)))
			{
				if (pLocal && (GrandChase->GetGameState() == cMain::GAMESTATES::GS_GAME || dwSkillOwner != 9999))
				{
					dwSkillOwner = pLocal->m_UserInfo.cCharIndex;
					uiSkillModifier[2] = pLocal->m_vSkillInfo[2]->dwSkillId;
				}
			}
			ImGui::SameLine();
			HelpMarker(Xor("Go to training, configure your skill bar then press here"));

			ImGui::InputInt(Xor("##BuffId"), &uiBuffId, 1, 1);
			/*
			if (ImGui::Button(Xor("Active Buff"), ImVec2(125, 20)))
				GrandChase->ActiveBuff(Menu->uiBuffId, 99999);
			ImGui::SameLine();
			HelpMarker(Xor("XP and GP buffs don't work"));
			*/
		ImGui::EndGroup();

	//	ImGui::End();
	}

}

void cMenu::Draw_GameResult()
{
/*	if (!bMenuPos[2])
	{
		ImGui::SetNextWindowSize(ImVec2(385, 373));
		ImGui::SetNextWindowPos(ImVec2(10, 150));
		bMenuPos[2] = true;
	}*/

	//if (ImGui::Begin("Mission", &bMenuOpen[1], ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_ShowBorders))
	{
		ImGui::PushItemWidth(180);

		ImGui::BeginGroup();
		ImGui::Checkbox(Xor("Mission Timer"), &bMissionTimer);
		ImGui::SliderInt(Xor("##uiMissionTimer"), &uiMissionTimer, 20, 720);

		ImGui::Checkbox(Xor("Combo Count"), &bComboHits);
		ImGui::SliderInt(Xor("##uiComboHits"), &uiComboHits, 1, 80);

		ImGui::Checkbox(Xor("Combo Rank"), &bComboRatio);
		ImGui::SameLine();
		HelpMarker(Xor("Set your Combo Rank (C, B, A, S, SS)"));
		ImGui::SliderFloat(Xor("##fComboRatio"), &fComboRatio, 1000, 9999999);

		ImGui::Checkbox(Xor("Combo Damage"), &bComboDmg);
		ImGui::SliderInt(Xor("##uiComboDmg"), &uiComboDmg, 60, 20000);

		ImGui::Checkbox(Xor("Hit Received"), &bComboReceive);
		ImGui::SliderInt(Xor("##uiHitReceived"), &uiComboReceived, 0, 50);

		ImGui::Checkbox(Xor("Aerial Combo"), &bAerialCombo);
		ImGui::SliderInt(Xor("##uiAerialCombo"), &uiAerialCombo, 1, 50);

		ImGui::Checkbox(Xor("Combo Eliminations"), &bComboEliminations);
		ImGui::SliderInt(Xor("##uiComboElimination"), &uiComboElimination, 1, 50);

		ImGui::Checkbox(Xor("Add Random Value"), &bRandomStatus);
		ImGui::SameLine();
		HelpMarker(Xor("Add random value on previous checked functions\nTo spoof your mission results"));
		ImGui::EndGroup();
		
		ImGui::SameLine();
		ImGui::BeginGroup();
		ImGui::Checkbox(Xor("Total Combo Score"), &bTotalComboScore);
		ImGui::SameLine();
		HelpMarker(Xor("ONLY USE IT IN KING SLIME EVENT.\nSet your Combo Rank (C, B, A, S, SS)"));
		ImGui::SliderInt(Xor("##fTotalComboScore"), &uiTotalComboScore, 1000, 9999999);

		ImGui::Checkbox(Xor("Dimension Killed"), &bDimensionKilledMonster);
		ImGui::SliderInt(Xor("##uiDimensionKills"), &uiDimensionKills, 1, 1000);

		ImGui::Checkbox(Xor("Dimension Boss Killed"), &bDimensionKilledBoss);
		ImGui::SliderInt(Xor("##uiDimensionBossKills"), &uiDimensionBossKills, 1, 60);

		ImGui::Checkbox(Xor("Dimension Level (Fake)"), &bDimensionLevelFake);
		ImGui::SliderInt(Xor("##uiDimensionLevelFake"), &uiDimensionFakeLevel, 1, 99);

		ImGui::Checkbox(Xor("Dimension Wave Count"), &bDimensionWaveCount);
		ImGui::SliderInt(Xor("##uiDimensionWaveFake"), &uiDimensionWaveCount, 1, 20);
		ImGui::EndGroup();

	//	ImGui::End();
	}
}

bool bDecryot = false, bEncrypt = false;
int uiDecryptType = 0;
int EncryptValue = 0;
const char* szDecryptType[] = { "INT", "WORD", "BYTE", "FLOAT" };
char szAddress[64];

int uiComboMap = 0, uiMonsterIdToSpawn = 0, uiTGID = 0, uiQTD = 0;

void cMenu::Draw_Dev()
{
	ImGui::BeginGroup();
	ImGui::Checkbox(Xor("Decrypt"), &bDecryot);
	ImGui::Checkbox(Xor("Encrypt"), &bEncrypt);
	ImGui::Combo(Xor("##ComboDecrypt"), &uiDecryptType, szDecryptType, 4);
	ImGui::InputText(Xor("##DecryptText"), szAddress, 64);
	ImGui::Text(Xor("Value to Encrypt"));
	ImGui::InputInt(Xor("##EncryptValue"), &EncryptValue);

	if (bEncrypt)
	{
		DWORD value = strtoul(szAddress, NULL, 16);

		if (value != 0)
		{
			switch (uiDecryptType)
			{
			case 0:
			{
				sEncrypt<int>* pEnc = (sEncrypt<int>*)value;

				pEnc->Encrypt(EncryptValue);
			}
			break;
			case 1:
			{
				sEncrypt<WORD>* pEnc = (sEncrypt<WORD>*)value;

				pEnc->Encrypt(EncryptValue);
			}
			break;
			case 2:
			{
				sEncrypt<BYTE>* pEnc = (sEncrypt<BYTE>*)value;

				pEnc->Encrypt(EncryptValue);
			}
			break;
			case 3:
			{
				sEncrypt<float>* pEnc = (sEncrypt<float>*)value;

				pEnc->Encrypt(EncryptValue);
			}
			break;
			}
		}
	}

	if (bDecryot)
	{
		DWORD value = strtoul(szAddress, NULL, 16);

		if (value != 0)
		{
			switch (uiDecryptType)
			{
			case 0:
			{
				sEncrypt<int>* pEnc = (sEncrypt<int>*)value;

				ImGui::Text(Xor("Decrypt: %d"), pEnc->Decrypt());
			}
			break;
			case 1:
			{
				sEncrypt<WORD>* pEnc = (sEncrypt<WORD>*)value;

				ImGui::Text(Xor("Decrypt: %d"), pEnc->Decrypt());
			}
			break;
			case 2:
			{
				sEncrypt<BYTE>* pEnc = (sEncrypt<BYTE>*)value;

				ImGui::Text(Xor("Decrypt: %d"), pEnc->Decrypt());
			}
			break;
			case 3:
			{
				sEncrypt<float>* pEnc = (sEncrypt<float>*)value;

				ImGui::Text(Xor("Decrypt: %1.1f"), pEnc->Decrypt());
			}
			break;
			}
		}
	}

	ImGui::Combo(Xor("##ComboSummonTest"), &uiComboMap, Opt_Continent, 3);
	ImGui::InputInt(Xor("##InputIdToSummon"), &uiMonsterIdToSpawn, 1, 1);
	if (ImGui::Button(Xor("Change Summon"), ImVec2(125, 20)))
		GrandChase->ChangeInfinityMonster(98 + uiComboMap, uiMonsterIdToSpawn);

	ImGui::Text(Xor("TGID"));
	ImGui::InputInt(Xor("##InputTGID"), &uiTGID, 1, 1);
	ImGui::Text(Xor("QTD"));
	ImGui::InputInt(Xor("##InputQTD"), &uiQTD, 1, 1);
	if (ImGui::Button(Xor("Set Kill Monster"), ImVec2(125, 20)))
		for (int i = 0; i < uiQTD; i++)
		{
			CMonster* pMonster = GrandChase->GetMonsterByTGID(uiTGID);

			if (pMonster)
			{
				printf("Monster Found: %x \n", pMonster);
				GrandChase->ShowExp(pMonster);
				printf("Exp Showed \n");
				GrandChase->VirtualKill(GrandChase->kUserMission, pMonster->m_iMonsterType, pMonster->m_iLevel.Decrypt(), pMonster->m_eNPC);
				printf("Virtual Killed \n");
				GrandChase->AddMonKillNum(GrandChase->pMission->pMissionInfo, pMonster->m_iMonsterType, 1, pMonster->m_iTriggerID);
				printf("Mon Kill \n");
			}
		}

	ImGui::EndGroup();
}

void cMenu::Draw_Automations()
{
	ImGui::BeginGroup();
	ImGui::Checkbox(Xor("Auto Enchant (Necklace)"), &bAutoEnchant);
	ImGui::SliderInt(Xor("##Level"), &uiEnchantLevel, 2, 9);
	ImGui::SameLine();
	HelpMarker(Xor("Enchant Level"));
	ImGui::Checkbox(Xor("Auto Buy Gem"), &bAutoBuy);
	ImGui::SliderInt(Xor("##GemQtd"), &uiGemQtd, 3, 999);
	ImGui::SameLine();
	HelpMarker(Xor("Gem Quantity"));

	ImGui::EndGroup();
}

void cMenu::Draw_Config()
{
	ImGui::BeginGroup();
	ImGui::InputText(Xor("##SaveTxt"), Resource->Loc, sizeof(Resource->Loc));

	if (ImGui::Button(Xor("Save"), ImVec2(125, 20)))
		Resource->Save();

	if (ImGui::Button(Xor("Load"), ImVec2(125, 20)))
		Resource->Load();

	ImGui::EndGroup();
}


void cMenu::Draw_Dimensional()
{
	ImGui::BeginGroup();
	ImGui::Checkbox(Xor("Dimensional Speed"), &bEnableSpeed);
	ImGui::Checkbox(Xor("Kill Portal at Time"), &bKillPortalAtTime);
	ImGui::SliderInt(Xor("##KillPortalTimer"), &uiKillPortalTimer, 1, 60);
	ImGui::Checkbox(Xor("Dimensional Level"), &bDimensionalLevel);
	ImGui::SliderInt(Xor("##SetDimensionalLevel"), &uiDimensionalLevel, 1, 99);
	ImGui::Checkbox(Xor("Dimensional Spawn Quantity"), &bDimensionalSpawnQtd);
	ImGui::SliderInt(Xor("##SetDimensionalSpawnQtd"), &uiDimensionalSpawnQtd, 1, 20);
	ImGui::Checkbox(Xor("Dimensional Spawn"), &bDimensionalSpawnModel);
	ImGui::Combo(Xor("##Continent"), &uiContinentSpawn, Opt_Continent, 3);

	if (uiContinentSpawn == 0)
		ImGui::Combo(Xor("##Monster"), &uiMonsterSpawnEllia, Opt_Ellia, 10);

	if (uiContinentSpawn == 1)
		ImGui::Combo(Xor("##Monster"), &uiMonsterSpawnXenia, Opt_Xenia, 9);

	if (uiContinentSpawn == 2)
		ImGui::Combo(Xor("##Monster"), &uiMonsterSpawnAton, Opt_Aton, 7);

//	ImGui::InputInt(Xor("##SetDimensionalSpawnModel"), &uiSpawnId, 1, 1);
	ImGui::EndGroup();
}

void cMenu::Draw_Loot()
{
	ImGui::BeginGroup();
	ImGui::Checkbox(Xor("Filter Magnetic"), &bMagneticFilter);
	ImGui::SameLine();
	HelpMarker(Xor("This Function Filter which item Magetic will bring to u"));
	ImGui::InputText(Xor("##InputTexto"), szSearchLoot, sizeof(szSearchLoot));
	ImGui::SameLine();
	if (ImGui::Button(Xor("Search"), ImVec2(80, 20)))
		GrandChase->SearchLoot(szSearchLoot);

	ImGui::ListBox(Xor("##LootNames"), &uiCurrentLoot, GrandChase->v_szLoot.data(), GrandChase->v_szLoot.size(), 5);
	ImGui::SameLine();
	ImGui::BeginGroup();
	if (ImGui::Button(Xor("Add"), ImVec2(80, 20)))
		GrandChase->AddLoot(uiCurrentLoot);
	if (ImGui::Button(Xor("Add Prefix"), ImVec2(80, 20)))
		GrandChase->AddPrefix(szSearchLoot);
	ImGui::EndGroup();

	ImGui::ListBox(Xor("##Filters"), &uiCurrentFilter, GrandChase->v_szFilter.data(), GrandChase->v_szFilter.size(), 5);
	ImGui::SameLine();
	ImGui::BeginGroup();
	if (ImGui::Button(Xor("Rmv"), ImVec2(80, 20)))
		GrandChase->RmvLoot(uiCurrentFilter);

	if (ImGui::Button(Xor("Clear"), ImVec2(80, 20)))
	{
		GrandChase->v_FilterId.clear();
		GrandChase->v_szFilter.clear();
	}
	ImGui::EndGroup();
	ImGui::EndGroup();

	ImGui::BeginGroup();
	/*ImGui::Checkbox("Prediction Drop", &bAutoLoot);
	ImGui::ListBox("##PredictionDrops", &uiCurrentPrediction, szPrediction.data(), szPrediction.size(), 6);*/
	ImGui::Checkbox(Xor("Magnetic Item"), &bLootType[1]);
	ImGui::Checkbox(Xor("Magnetic GP"), &bLootType[0]);
	ImGui::Checkbox(Xor("Get Monster Drop"), &bForceLoot);
	ImGui::SameLine();
	HelpMarker(Xor("Will drop all loot from current mission"));
	ImGui::EndGroup();
}

void cMenu::Draw_Farming()
{
		ImGui::PushItemWidth(200);

		ImGui::BeginGroup();
		ImGui::Checkbox(Xor("Auto Start"), &bAutoStart);
		ImGui::Checkbox(Xor("Auto Kill"), &bAutoKill);
		ImGui::Checkbox(Xor("Auto Portal"), &bAutoPortal);
		ImGui::SameLine();
		HelpMarker(Xor("Will teleport u to farest portal (only works playing alone)"));
		ImGui::Checkbox(Xor("Skip Dialogue"), &bSkipDialogue);
		ImGui::EndGroup();

		ImGui::BeginGroup();
		ImGui::Checkbox(Xor("Stage Hack"), &bStageHack);
		ImGui::SameLine();
		HelpMarker(Xor("Set previous saved stage"));
		if (ImGui::Button(Xor("Save Stage"), ImVec2(125, 20)))
			dwStageHack = GrandChase->GetStage();
		ImGui::EndGroup();
		
}

bool bRandomIncrement = false, bDrawLoot = true;

void cMenu::Function_Cheats()
{
	/*if (!Menu->Timer_CheckWiindow->Running())
	{
		EHProtect->CheckWindow();
		Menu->Timer_CheckWiindow->Start(5000);
	}*/

	VIRTUALIZER_FISH_WHITE_START
	
	/*if (!Menu->Timer_DebugPresent->Running())
	{
		EHProtect->CheckDebugPresent();
		Menu->Timer_DebugPresent->Start(2100);
	}*/


	if (GrandChase->GetGameState() != cMain::GAMESTATES::GS_GAME)
	{
		szPrediction.clear();
		bDrawLoot = true;
		bRandomIncrement = true;
	}

	if (bAutoStart)
		GrandChase->AutoStart();

	if (bAutoEnchant)
		GrandChase->AutoEnchant(uiEnchantLevel, bAutoBuy, uiGemQtd);

	if (GrandChase->GetGameState() == cMain::GAMESTATES::GS_GAME && GrandChase->GetMonsterCount())
	{
		CPlayer* pLocalPlayer = GrandChase->GetLocalPlayer();

		if (pLocalPlayer)
		{
			if (bEnableSpeed)
				GrandChase->DimensionSpeedUp();

			if (bDimensionalLevel)
				GrandChase->ChangeInfinityLevel(uiDimensionalLevel);

			if (bDimensionalSpawnQtd)
				GrandChase->ChangeInfinitySpawnQuantity(uiDimensionalSpawnQtd);

			if (bDimensionalSpawnModel)
			{
				int dwMap = 98 + uiContinentSpawn;

				int dwMonster = 1;

				if (dwMap == 98)
					dwMonster = GrandChase->GetContinentBoss(dwMap, uiMonsterSpawnEllia);

				if (dwMap == 99)
					dwMonster = GrandChase->GetContinentBoss(dwMap, uiMonsterSpawnXenia);

				if (dwMap == 100)
					dwMonster = GrandChase->GetContinentBoss(dwMap, uiMonsterSpawnAton);

				if (dwMonster != 1)
					GrandChase->ChangeInfinityMonster(dwMap, dwMonster);
			}

			if (bStageHack && dwStageHack != 999)
				GrandChase->SetStage(dwStageHack);

			if (bForceLoot)
				GrandChase->ForceDrop();

			if (bAutoLoot)
				if (bDrawLoot)
				{
					GrandChase->PredictionItem(szPrediction);
					bDrawLoot = false;
				}

			if (bAtt)
				pLocalPlayer->m_CurrentStatus.m_Attack.Encrypt(fAtt);

			if (bDef)
				pLocalPlayer->m_CurrentStatus.m_Def.Encrypt(fDef);

			if (bCriChance)
				pLocalPlayer->m_CurrentStatus.m_CriticalChance.Encrypt(fCriChance);

			if (bCritDmg)
				pLocalPlayer->m_CurrentStatus.m_CriticalDamage.Encrypt(fCritDmg);

			if (bHp)
				pLocalPlayer->m_CurrentStatus.m_HpRate.Encrypt(999999999);

			if (bMp)
				pLocalPlayer->m_CurrentStatus.m_MpRate.Encrypt(99999);
			
			if (bSkipDialogue)
				GrandChase->SetDialogueOff();

			if (bAutoKill)
				GrandChase->AutoKill();

			if (bAutoPortal)
				GrandChase->AutoPortal();

			if (bSkillCooldown)
				for (int i = 0; i < 3; i++)
					pLocalPlayer->m_vSkillInfo[i]->m_Cooldown.Encrypt(0);
					
			if (bLootType[0])
				GrandChase->MagneticGP();

			if (bLootType[1])
				if (!bMagneticFilter)
					GrandChase->MagneticItem();
				else
					GrandChase->MagneticFilter();
			
			if (dwSkillOwner == pLocalPlayer->m_UserInfo.cCharIndex)
			{
				if (bSkillModifier[0])
					pLocalPlayer->m_vSkillInfo[0]->dwSkillId = uiSkillModifier[0];

				if (bSkillModifier[1])
					pLocalPlayer->m_vSkillInfo[1]->dwSkillId = uiSkillModifier[1];

				if (bSkillModifier[2])
					pLocalPlayer->m_vSkillInfo[2]->dwSkillId = uiSkillModifier[2];
			}
			
			if (bRandomStatus)
			{
				if (bRandomIncrement)
				{
					uiRandMissionTimer = rand() % 180;
					fRandComboRatio = rand() % 12000;
					uiRandAerialCombo = rand() % 12;
					uiRandComboDmg = rand() % 12000;
					uiRandComboElimination = rand() % 10;
					uiRandComboHits = rand() % 32;
					uiRandComboReceived = rand() % 6;
					uiRandHitCount = rand() % 30;
					bRandomIncrement = false;
					uiRandComboScore = rand() % 12000;
					uiRandDimensionWaveCount = rand() % 10;
				}
			}
			else
			{
				uiRandMissionTimer = 0;
				fRandComboRatio = 0;
				uiRandAerialCombo = 0;
				uiRandComboDmg = 0;
				uiRandComboElimination = 0;
				uiRandComboHits = 0;
				uiRandHitCount = 0;
				uiRandComboReceived = 0;
				uiRandComboScore = 0;
				uiRandDimensionWaveCount = 0;
			}

			if (bDimensionWaveCount)
			{
				int Count = uiDimensionWaveCount;

				Count += uiRandDimensionWaveCount;

				GrandChase->SetDimensionWaveCount(Count);
			}

			if (bMissionTimer)
			{
				int Timer = uiMissionTimer + uiRandMissionTimer;

				GrandChase->SetGameTime(Timer * 55);
			}

			if (bComboRatio)
			{
				float Ratio = fComboRatio;

				Ratio += fRandComboRatio;

				GrandChase->SetComboRatio(Ratio);
			}

			if (bTotalComboScore)
			{
				int Ratio = uiTotalComboScore;

				Ratio += uiRandComboScore;

				GrandChase->SetTotalComboRatio(Ratio);
			}

			if (bComboHits)
			{
				int Hits = uiComboHits;
				Hits += uiRandComboHits;

				GrandChase->SetTotalCombo(Hits);
				GrandChase->SetHitCount(Hits + uiRandHitCount);
			}

			if (bComboDmg)
			{
				int Damage = uiComboDmg;
				Damage += uiRandComboDmg;

				GrandChase->SetComboDamage(Damage);
			}

			if (bComboReceive)
			{
				int Hits = uiComboReceived;
				Hits += uiRandComboReceived;

				GrandChase->SetReceivedHits(Hits);
			}

			if (bAerialCombo)
			{
				int AerialHits = uiAerialCombo + uiRandAerialCombo;

				GrandChase->SetAerialCombo(AerialHits);
			}

			if (bComboEliminations)
			{
				int Eliminations = uiComboElimination + uiRandComboElimination;
				GrandChase->SetComboElimination(Eliminations);
			}

			if (bDimensionLevelFake)
			{
				int Level = uiDimensionFakeLevel + uiRandFakeLevel;

				GrandChase->SetDimensionLevelFake(Level);
			}

			if (bDimensionKilledBoss)
			{
				int Boss = uiDimensionBossKills + uiRandBossKill;

				GrandChase->SetBossKilled(Boss);
			}

			if (bDimensionKilledMonster)
			{
				int Kill = uiDimensionKills + uiRandMonsterKill;

				GrandChase->SetMonsterKilled(Kill);
			}

			if (bKillPortalAtTime)
				if (GrandChase->GetGameTime() >= (uiKillPortalTimer * 55 * 60))
					GrandChase->KillDimensionalPortal();
		}
	}
	VIRTUALIZER_FISH_WHITE_END
}

