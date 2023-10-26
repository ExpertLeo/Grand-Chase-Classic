class CPlayer;
struct sCurrentStats;
class cGameState;
class sSkillUsage;
class sSkillInfo;
class cSkill;
class CQuestGameManager;
class cQuest;
class cMissionInfo;
class cMission;
class cKGCDropItem;
class cKGCDropManager;
class cDrop;
class cKGCPortal;
class cPortalManager;
class cRoomScene;
class cKGCRoomSceneS6;
class cKGCRoomButtonPanelS6;
class cKD3DButton;
class cGameInput;
class KInput;
class cGameOverlay;
class cKGCGameOverlayUI;
class cSceneList;
class cKGCScene;
class cGameScene;
class sInfinityTime;
class KGCNewNecklaceEnchantDlg;
class cTGInfinityMonsterGen;
class cTriggerChildren;
class CTrigger;
class cTriggerList;
class cStage;
class cKGCUIScene;
class cKGCGrowthMissionDlg;
class cGrowthRewards;
class cGrowthMission;
class cInfinityDungeon;
class cInfinityDungeonInfo;
class sMonsterRankInfo;
class sMonsterLevel;
class sMonsterSpawnInfo;
class CGCGlobal;
class cKGCGlobal;
class SUserInfo;
struct SDungeonInfo;
class cKGCGameBoard;


enum EGCGameMode // GC_GM_*
{
	GC_GM_INVALID = -1,   // invalid game mode value

	GC_GM_TUTORIAL = 0,    // 튜토리얼
	GC_GM_TEAM_MODE = 1,    // 팀 모드
	GC_GM_SURVIVAL_MODE = 2,    // 서바이벌 모드
	GC_GM_TAG_TEAM = 3,    // 태그매치 팀모드
	GC_GM_TAG_SURVIVAL = 4,    // 태그매치 서바이벌
	GC_GM_GUILD_BATTLE = 5,    // 길드전 모드
	GC_GM_INDIGO_TEAM = 6,    // 용사의 섬
	GC_GM_QUEST0 = 7,    // 시련의 숲
	GC_GM_QUEST1 = 8,    // 시련의 탑
	GC_GM_QUEST2 = 9,    // 세르딘성 외곽
	GC_GM_QUEST3 = 10,   // 캐리비치
	GC_GM_QUEST4 = 11,   // 오크사원
	GC_GM_QUEST5 = 12,   // 고르고스 던전
	GC_GM_QUEST6 = 13,   // 엘프의 숲
	GC_GM_QUEST7 = 14,   // 맹세의 계곡
	GC_GM_QUEST8 = 15,   // 망각의 늪
	GC_GM_QUEST9 = 16,   // 망자의 묘지
	GC_GM_QUEST10 = 17,   // 잊혀진 도시
	GC_GM_QUEST11 = 18,   // 가이코즈의 성
	GC_GM_QUEST12 = 19,   // 파투세이의 바다
	GC_GM_QUEST13 = 20,   // 엘리아 대륙
	GC_GM_QUEST14 = 21,   // 불의 사원
	GC_GM_QUEST15 = 22,   // 헬 브릿지
	GC_GM_QUEST16 = 23,   // 카제아제의 성
	GC_GM_QUEST17 = 24,   // 카스툴 유적지 하층
	GC_GM_QUEST18 = 25,   // 카스툴 유적지 상층
	GC_GM_QUEST19 = 26,   // 베르메시아의 최후
	GC_GM_QUEST20 = 27,   // 제니아 접경지
	GC_GM_MONSTER_CRUSADER = 28,   // 몬스터 원정대
	GC_GM_MONSTER_HUNT = 29,   // 몬스터 대전(시즌1.미사용)
	GC_GM_QUEST21 = 30,   // 순환의신전
	GC_GM_DEATH_TEAM = 31,   // 데스매치 팀
	GC_GM_DEATH_SURVIVAL = 32,   // 데스매치 서바이벌
	GC_GM_MINIGAME_TREEDROP = 33,    // 미니게임 통나무 떨어지기
	GC_GM_MINIGAME_BALLOON = 34,    // 미니게임 풍선 터뜨리기
	GC_GM_MINIGAME_BUTTERFRY = 35,    // 미니게임 나비 잡기
	GC_GM_QUEST22 = 36,   // 소실의협곡
	GC_GM_ANGELS_EGG = 37,    //천사의 알
	GC_GM_CAPTAIN = 38,   // 대장전
	GC_GM_QUEST23 = 39,   // 실버랜드 성난 엔트의 숲
	GC_GM_QUEST24 = 40,   // 실버랜드 실버나이츠
	GC_GM_QUEST25 = 41,    // 실버랜드 미명의 호수
	GC_GM_QUEST26 = 42,    // 제니아 이그니스의 산맥
	GC_GM_QUEST27 = 43,    // 싫버랜드 수룡의 늪
	GC_GM_QUEST28 = 44,    // 실버랜드 원시의 섬
	GC_GM_QUEST29 = 45,    // 실버랜드 드레이크 웜의 영지
	GC_GM_QUEST30 = 46,    // 실버랜드 빅터의 요새
	GC_GM_QUEST31 = 47,    // 제니아 조율의 제단
	GC_GM_QUEST32 = 48,    // 제니아 파괴의신전
	GC_GM_QUEST33 = 49,    // 제니아 생명의숲
	GC_GM_QUEST34 = 50,    // 제니아 지배의 성
	GC_GM_QUEST35 = 51,    // 베르메시아 보스 던전
	GC_GM_QUEST36 = 52,    // 실버랜드 보스 던전
	GC_GM_QUEST37 = 53,    // 엘리아 보스 던전
	GC_GM_QUEST38 = 54,    // 제니아 보스 던전
	GC_GM_QUEST39 = 55,    // 고블린 노역소
	GC_GM_QUEST40 = 56,    // 지하암흑 터널
	GC_GM_QUEST41 = 57,    // 쿵지 쿵지
	GC_GM_QUEST42 = 58,    // 드워프 전초기지
	GC_GM_QUEST43 = 59,    // 신기루 사막
	GC_GM_QUEST44 = 60,    // 드워프 보급로
	GC_GM_QUEST45 = 61,    // 썬더 해머
	GC_GM_QUEST46 = 62,    // 영웅던전 ( 파멸의 성소 )
	GC_GM_QUEST47 = 63,    // 영웅던전 ( 지옥의 용광로 )
	GC_GM_QUEST48 = 64,    // 고대왕국의 흔적
	GC_GM_DOTA = 65,    // 점령전
	GC_GM_AGIT = 66,    // 아지트
	GC_GM_QUEST49 = 67,    // 이벤트 던전 카니발 ( 악몽의 서커스 )
	GC_GM_QUEST50 = 68,    // 이벤트 릴레이 던전 ( 앵그리 보오스 )
	GC_GM_QUEST51 = 69,    // 이벤트 영웅 던전 ( 악몽의 서커스 리뉴얼 )
	GC_GM_QUEST52 = 70,    // 릴레이 영웅 던전 슈퍼 몬스터 ( 환영의 미궁 )
	GC_GM_QUEST53 = 71,	 // 명계열차 301 (GhostTrain)
	GC_GM_QUEST54 = 72,	 // 배고픈 펫들의 반란
	GC_GM_QUEST55 = 73,	 // 카루엘 접경지(KaruelBorder)
	GC_GM_QUEST56 = 74,	 // 카루엘 (Karuel)
	GC_GM_QUEST57 = 75,	 // 이벤트 던전( 야시장 )
	GC_GM_QUEST58 = 76,    // 레이드던전
	GC_GM_AUTOMATCH_TEAM = 77,    // 대전팀 자동매칭
	GC_GM_QUEST59 = 78,    // 사막 도적마을( 아툼 )
	GC_GM_QUEST60 = 79,    // 라 협곡( 아툼 )
	GC_GM_QUEST61 = 80,    // 세트의 피라미드( 아툼 )
	GC_GM_QUEST62 = 81,    // 코우나트 붕괴지( 아케메디아 )
	GC_GM_QUEST63 = 82,    // 코우나트 붕괴지( 이벤트던전 )
	GC_GM_QUEST64 = 83,    // 이벤트 슈팅던전( 탈린의 역습 )

	GC_GM_QUEST65 = 84,    // 아델 신대륙 ( 저주받은 정원 )
	GC_GM_QUEST66 = 85,    // 아델 신대륙 ( 오염된 지하실 )
	GC_GM_QUEST67 = 86,    // 아델 신대륙 ( 망령이 깃든 복도 )
	GC_GM_QUEST68 = 87,    // 아델 신대륙 ( 배신자의 화실 )
	GC_GM_QUEST69 = 88,    // 아델 신대륙 ( 어둠에 물든 서재 )
	GC_GM_QUEST70 = 89,    // 아델 신대륙 ( 아라크네의 둥지 )

	GC_GM_QUEST71 = 90,    // 베이가스 신대륙 ( 골리아스 서식지 )
	GC_GM_QUEST72 = 91,    // 베이가스 신대륙 ( 고대 골렘의 무덤 )
	GC_GM_QUEST73 = 92,    // 베이가스 신대륙 ( 그림자 밀림 )
	GC_GM_QUEST74 = 93,    // 베이가스 신대륙 ( 라세르타의 사냥터 )
	GC_GM_QUEST75 = 94,    // 베이가스 신대륙 ( 절망의 대지 )
	GC_GM_QUEST76 = 95,    // 베이가스 신대륙 ( 차원의 경계 )

	GC_GM_FATAL_DEATH_TEAM = 96,   // 페이탈 데스매치 팀
	GC_GM_FATAL_DEATH_SURVIVAL = 97,   // 페이탈 데스매치 서바이벌

	GC_GM_QUEST77 = 98,	//-- 엘리아 사냥터
	GC_GM_QUEST78 = 99,	//-- 제니아 사냥터 
	GC_GM_QUEST79 = 100,	//-- 아툼 사냥터 
	GC_GM_QUEST80 = 101,	//-- 아케메디아 사냥터
	GC_GM_QUEST81 = 102,	//-- 만렙컨트롤 던전

	NUM_GC_GAME_MODE,
};

template <class T, int thesize>
class KSafeArray
{
private:
	T v[thesize];
public:
	KSafeArray() {}
	~KSafeArray() {}

	// 타입 정의
	typedef T value_type;
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef T& reference;
	typedef const T& const_reference;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;

	// 반복자 지원
	iterator begin() { return v; }
	const_iterator begin() const { return v; }
	iterator end() { return v + thesize; }
	const iterator end() const { return v + thesize; }

	// 직접적인 원소 액세스
	reference operator[](std::size_t i) {

		if (i<0 || i >= thesize)
		{
#if defined(DEBUG)
			throw new std::exception("Invalid Index");
#elif !defined( __PATH__ )
			terminate();
#endif
		}

		return v[i];
	}
	const_reference operator[] (std::size_t i) const {

		if (i<0 || i >= thesize)
		{
#if defined(DEBUG)
			throw new std::exception("Invalid Index");
#elif !defined( __PATH__ )
			terminate();
#endif
		}
		return v[i];
	}

	// 사이즈 관련
	size_type size() const { return thesize; }
	size_type max_size() const { return thesize; }

	// 기존 배열로의 전환
	T* as_array() { return v; }
};

class KAttributeInfo
{
public:
	enum ATTRIBUTE_STATE
	{
		ATS_OPENED,
		ATS_USING,
		ATS_CLOSED,
	};

	enum ATTRIBUTE_TYPE
	{
		ATT_UNKNOWN = -1,
	};

	char    m_cSlotID;
	char    m_cType;
	char    m_cState;
	float   m_fValue;
};

class KSocketInfo
{
public:
	enum SOCKET_STATE
	{
		STS_INIT,
		STS_CLOSED,
		STS_OPENED,
		STS_USING,
		STS_BREAK,

		STS_NUM,
	};

	DWORD   m_CardItemID;
	char    m_cSlotID;
	char    m_cState;
};

class KItem
{
public:
	enum ITEM_STATE
	{
		UNLIMITED_ITEM = -1,
		INVALID_ITEM = 0,
	};

	enum ITEM_GRADE
	{
		GRADE_NORMAL = 0,
		GRADE_RARE = 1,
		GRADE_EPIC = 2,
		GRADE_LEGEND = 3,
		GRADE_NUM,
	};

	enum ITEM_TYPE
	{
		TYPE_NORMAL = 0x00000000, // 일반
		TYPE_LOOK = 0x00000001, // 룩(코디)아이템
		TYPE_AGIT_OBJ = 0x00000002, // 아지트 아이템
	};

	enum EItemCharType
	{
		EICT_AGIT = -1,

		EICT_ELESIS = 0,
		EICT_LIRE = 1,
		EICT_ARME = 2,
		EICT_LAS = 3,
		EICT_RYAN = 4,
		EICT_RONAN = 5,
		EICT_AMY = 6,
		EICT_JIN = 7,
		EICT_SIEG = 8,
		EICT_MARI = 9,
		EICT_DIO = 10,
		EICT_ZERO = 11,
		EICT_LEY = 12,
		EICT_LUPUS = 13,
		EICT_RIN = 14,
		EICT_ASIN = 15,
		EICT_LIME = 16,
		EICT_EDEL = 17,
		EICT_BEIGAS = 18,

		EICT_NO_TYPE = 255,
	};

	enum INVEN_TYPE
	{
		INVENTORY = 0,
		DEPOT = -1,
		VIRTUAL_DEPOT = -2, // 실제로 DB에서는 254로 기록 돼 있음. DEPOT이 -1이라서(DB에는 255) 따라감
	};

	DWORD    m_ItemID;
	INT64   m_ItemUID;
	int         m_nCount;
	int         m_nInitCount;
	short       m_sEquipLevel;
	short       m_sEquipLvDown;
	int         m_nPeriod;
	time_t      m_tStartDate;
	time_t      m_tRegDate;
	time_t      m_tEndDate;
	std::vector< KSocketInfo > m_vecSocket;
	std::vector< KAttributeInfo > m_vecAttribute;
	char        m_cItemType;
	INT64   m_EnchantEquipItemUID;
	char        m_cEnchantLevel;
	char        m_cGradeID;
	char        m_cEnchantEquipGradeID;
	DWORD    m_CoordItemID;
	INT64   m_CoordItemUID;
	char        m_cInitInvenType;
	char        m_cInvenType;
	char        m_cCharType;
	char        m_cInitTabID;
	char        m_cTabID;
	char        m_cInitSlotID;
	char        m_cSlotID;
	bool        m_bReserveNewUID;
	DWORD    m_DesignCoordiID;
};

template <typename T>
struct sEncrypt
{
public:
	__int32 dwEncryptId; //0x0000 
	__int32 dwUnknownValue00;
	T Value; //0x0008 
	DWORD dwBaseXor; //0x000C 
	__int32 dwUnknownValue01;
	__int32 dwUnknownValue02;

public:
	T Decrypt()
	{
		DWORD* EncryptTable02 = (DWORD*)EncryptTable00;

		DWORD ConvertedAddy = reinterpret_cast<DWORD>(&Value);

		DWORD EncryptedValue = *(DWORD*)ConvertedAddy;

		EncryptedValue ^= EncryptTable02[2 * dwEncryptId];

		return *(T*)&EncryptedValue;
	}

	void Encrypt(T Value)
	{

		DWORD* EncryptTable02 = (DWORD*)EncryptTable00;

		DWORD ConvertedValue = *(DWORD*)&Value;

		DWORD EncryptedValue = EncryptTable02[2 * dwEncryptId] ^ ConvertedValue;

		this->Value = *(T*)&EncryptedValue;
	}

}; //Size=0x0018

struct sCurrentStats
{
public:
	sEncrypt<float> m_Attack; //0x0000
	sEncrypt<float> m_Def; //0x0018 
	sEncrypt<float> m_MaxHp; //0x0030 
	sEncrypt<float> m_SpAttack; //0x0048 
	sEncrypt<float> m_SpDef; //0x0060 
	sEncrypt<float> m_HpDrain; //0x0078 
	sEncrypt<float> m_MpDrain; //0x0090 
	sEncrypt<float> m_HpRate; //0x00A8 
	sEncrypt<float> m_MpRate; //0x00C0 
	sEncrypt<float> m_CriticalChance; //0x00D8 
	sEncrypt<float> m_CounterDef; //0x00F0 
	sEncrypt<float> m_Rolling; //0x0108 
	sEncrypt<float> m_FastHpRecoveryLimitTime; //0x0120 
	sEncrypt<float> m_IgnoreHaste; //0x0138 
	sEncrypt<float> m_AutoRecoveryHpLimit; //0x0150 
	sEncrypt<float> m_UnknownStatus07; //0x0168 
	sEncrypt<float> m_CriticalDamage; //0x0180 

}; //Size=0x0198


class CMonster
{
public:
	char pad_0x0000[0x4]; //0x0000
	string m_strMonsterName; //0x0004 
	char pad_0x001C[0x14C4]; //0x001C
	__int32 m_iMonsterType; //0x14E0 
	__int32 m_iBossMonster; //0x14E4 
	char pad_0x14E8[0x260]; //0x14E8
	sEncrypt<int> m_AnimationId; //0x1748 
	char pad_0x1760[0x18]; //0x1760
	sEncrypt<float> m_PosX; //0x1778 
	sEncrypt<float> m_PosY; //0x1790 
	char pad_0x17A8[0x58]; //0x17A8
	sEncrypt<float> m_Health; //0x1800 
	char pad_0x1818[0x68]; //0x1818
	sEncrypt<int> m_iLevel; //0x1880 
	char pad_0x1898[0xC8]; //0x1898
	__int32 m_eNPC; //0x1960 
	char pad_0x1964[0x8C]; //0x1964
	__int32 m_iTriggerID; //0x19F0 
	__int32 m_pDropItemObserver; //0x19F4 

}; //Size=0x1D9C

/*
class CMonster
{
public:
	char pad_0x0000[0x1D8]; //0x0000
	DWORD dwMonsterType; //0x01D8 
	DWORD m_iBossMonster; //0x01DC 
	char pad_0x01E0[0x168]; //0x01E0
	sEncrypt<float> m_PosX; //0x0348 
	sEncrypt<float> m_PosY; //0x0360 
	char pad_0x0378[0x150]; //0x0378
	sEncrypt<float> m_Health; //0x04C8 
	char pad_0x04E0[0x38]; //0x04E0
	sEncrypt<DWORD> m_iLevel; //0x0518 
	char pad_0x0530[0x38]; //0x0530
	DWORD m_eNPC; //0x0568 
	char pad_0x056C[0xC]; //0x056C
	float m_fAttackPoint; //0x0578 
	float m_fSummonsAtkRatio; //0x057C 
	float m_fOwnerAtkRatio; //0x0580 
	float m_fHPPoint; //0x0584 
	__int32 m_iMonsterNameID; //0x0588 
	char pad_0x058C[0xC]; //0x058C
	wstring m_strMonsterName; //0x0598 
	char pad_0x05B0[0xE8]; //0x05B0
	DWORD m_iTriggerID; //0x0698 
	char pad_0x069C[0x15C]; //0x069C
	DWORD m_iSummonned; //0x07F8 
	char pad_0x07FC[0xD8]; //0x07FC

}; //Size=0x08D4
*/


class cMonsterManager
{
public:
	map <DWORD, CMonster*> m_mapMonster;
};


class sSkillUsage
{
public:
	DWORD dwSkillId;
	DWORD dwCount;
}; //Size=0x0008

class cGameState
{
public:
	char pad_0x0000[0x10]; //0x0000
	sEncrypt<int> m_CurrentState;


}; //Size=0x0040

class sSkillInfo
{
public:
	__int32 dwSkillId; //0x0000 
	char pad_0x0004[0x4]; //0x0004
	sEncrypt<float> m_Cooldown; //0x0008 
	char pad_0x0020[0x10]; //0x0020

}; //Size=0x0030

class cSkill
{
public:
	sSkillInfo SkillIInfo[6]; //0x0000 
	char pad_0x0090[0x8]; //0x0090

}; //Size=0x0098

#pragma pack(push)
#pragma pack(1)
class SUserInfo
{
public:
	DWORD dwUID; //0x0000 
	wstring strLogin; //0x0004  wstring 
	wstring strNickName; //0x001C 
	wstring strNation; //0x0034 
	DWORD eGCUserLevel; //0x004C 
	unsigned char iAge; //0x0050 
	unsigned char bMan; //0x0051 
	unsigned char cCharIndex; //0x0052 
	char pad_0x0053[0x8E]; //0x0053
	unsigned char iTeam; //0x00E1 
	__int8 bHost; //0x00E2 
	unsigned char bLive; //0x00E3 
	__int32 iGP; //0x00E4 
	char pad_0x00E8[0x10]; //0x00E8

}; //Size=0x019C

class cKGCGlobal
{
public:
	char pad_0x0000[0x1C]; //0x0000
	unsigned char m_bNewUser_Tutorial; //0x001C 
	unsigned char m_bNewUser_Quest; //0x001D 
	char pad_0x001E[0x1A]; //0x001E
	sEncrypt<BOOL> m_bCheckChangedKOM; //0x0038 BOOL 
	char pad_0x0050[0x7C]; //0x0050
	SUserInfo m_kUserInfo; //0x00CC 
	char pad_0x0268[0x784]; //0x0268

}; //Size=0x09EC
#pragma pack(pop)

class CPlayer
{
public:
	char pad_0x0000[0xD08]; //0x0000
	sCurrentStats m_CurrentStatus; //0x0D08 
	char pad_0x0EA0[0x890]; //0x0EA0
	SUserInfo m_UserInfo; //0x1730 
	sEncrypt<int> m_PlayerState; //0x1828 0 In Room, 1 Ready, 2 In Game 
	char pad_0x1840[0x86A0]; //0x1840
	D3DXVECTOR2 m_vPosition; //0x9EE0 
	char pad_0x9EE8[0x2AC]; //0x9EE8
	map<int, sSkillUsage*> m_mapSkillUsage; //0xA194 map<int, sSkillUsage>
	vector<sSkillInfo*> m_vSkillInfo; //0xA19C vector<sSkillInfo> 
	char pad_0xA1A8[0x108]; //0xA1A8
	DWORD m_iControlInfoComboCount; //0xA2B0 
	DWORD m_iControlInfoBackAttackCount; //0xA2B4 
	DWORD m_iControlInfoBeAttackedCount; //0xA2B8 
	DWORD m_iControlInfoRank; //0xA2BC 
	char pad_0xA2C0[0xC34]; //0xA2C0

}; //Size=0xAEF4

/*
class CPlayer
{
public:
	char pad_0x0000[0x414]; //0x0000
	DWORD dwUID; // 0x0414;
	wstring wszLogin; //0x0418 
	wstring wszName; //0x0430 
	wstring wszCountry; //0x0448 
	char pad_0x0460[0xAC]; //0x0460
	sEncrypt<int> m_PlayerState; //0x050C 0 In Room, 1 Ready, 2 In Game 
	char pad_0x0524[0x4754]; //0x0524
	sEncrypt<int> m_CharacterId; //0x4C78 
	char pad_0x4C90[0x11F0]; //0x4C90
	sCurrentStats m_CurrentStatus; //0x5E80 
	char pad_0x6018[0x2C48]; //0x6018
	D3DXVECTOR2 m_vPosition; //0x8C60 
	char pad_0x8C68[0x2A0]; //0x8C68
	map<int, sSkillUsage> m_mapSkillUsage; //0x8F08 map<int, sSkillUsage>
	cSkill* pSkill; //0x8F10 
	char pad_0x8F14[0x10C]; //0x8F14
	DWORD m_iControlInfoComboCount; //0x9020 
	DWORD m_iControlInfoBackAttackCount; //0x9024 
	DWORD m_iControlInfoBeAttackedCount; //0x9028 
	DWORD m_iControlInfoRank; //0x902C 
	char pad_0x9030[0xC34]; //0x9030

}; //Size=0x9C64
*/

class cQuest
{
public:
	CQuestGameManager* pQuestGameManager; //0x0000 
	char pad_0x0004[0x40]; //0x0004

}; //Size=0x0044

class CQuestGameManager
{
public:
	char pad_0x0000[0x28]; //0x0000
	__int32 m_iBeforeDirection; //0x0028 
	__int32 m_iCurStage; //0x002C 
	DWORD m_iCurTileX; //0x0030 
	DWORD m_iCurTileY; //0x0034 
	__int32 m_iBossStageNum; //0x0038 
	unsigned char m_bQuestStarted; //0x003C 
	unsigned char m_bWin; //0x003D 
	unsigned char m_bEndGame; //0x003E 
	unsigned char m_bClearStage; //0x003F 
	unsigned char m_bLoading; //0x0040 
	char pad_0x0041[0x3]; //0x0041
	DWORD m_dwEndGameDelay; //0x0044 
	unsigned char m_bDramaStage; //0x0048 
	char pad_0x0049[0x7]; //0x0049
	DWORD m_dwPlayFrame; //0x0050 
	unsigned char m_bShowStartMsg; //0x0054 
	unsigned char m_bPerfectMode; //0x0055 
	unsigned char m_bMonLoadComplete; //0x0056 
	char pad_0x0057[0x1]; //0x0057
	__int32 m_iMonsterNum; //0x0058 
	char pad_0x005C[0x64]; //0x005C
	unsigned char m_bSendGetEndGameInfo; //0x00C0 
	unsigned char m_bGetEndGameInfo; //0x00C1 
	char pad_0x00C2[0x2]; //0x00C2
	__int32 m_dwEndGameInfoDelayTime; //0x00C4 
	char pad_0x00C8[0x8]; //0x00C8
	unsigned char m_bSendRouletteList; //0x00D0 
	unsigned char m_bRouletteList; //0x00D1 
	char pad_0x00D2[0x6]; //0x00D2
	__int32 m_dwRouletteWaitDelay; //0x00D8 
	char pad_0x00DC[0x16C]; //0x00DC
	std::map< std::pair<int, int>, bool >  m_mapStageHistory; //0x0248 std::map< std::pair<int, int>, bool > 
	char pad_0x0250[0x18]; //0x0250
	DWORD m_iCurDialoge; //0x0268 
	unsigned char m_bMovement; //0x026C 
	char pad_0x026D[0x8B]; //0x026D
	sEncrypt<float> m_fRankPoint; //0x02F8 
	sEncrypt<int> m_MaxCombo; //0x0310 
	sEncrypt<int> m_MaxComboDamage; //0x0328 
	sEncrypt<int> m_ComboDamage; //0x0340 
	sEncrypt<int> m_TotalDamageFromMonster; //0x0358 
	sEncrypt<int> m_TotalBackPlusAerialAttack; //0x0370 
	sEncrypt<int> m_KillCombo; //0x0388 
	sEncrypt<int> m_MaxKillCombo; //0x03A0 
	sEncrypt<int> m_BossKillCombo; //0x03B8 
	sEncrypt<float> fTotalDamage; //0x03D0 
	sEncrypt<int> m_InfinityDungeonPartyRank; //0x03E8 
	sEncrypt<int> m_InfinityDungeonMonsterLevel; //0x0400 
	unsigned char m_bExistMonsterInScreen; //0x0418 
	unsigned char m_bPortalInScreen; //0x0419 
	char pad_0x041A[0x5A]; //0x041A
	DWORD m_iHeroDungeonLevel; //0x0474 
	DWORD m_iPlayersAveLv; //0x0478 
	unsigned char m_ucPlayerNum; //0x047C 
	unsigned char m_bRankPortalCheck; //0x047D 
	unsigned char m_bComboBreak; //0x047E 
	char pad_0x047F[0x31]; //0x047F

}; //Size=0x04B0

/*
class CQuestGameManager
{
public:
	char pad_0x0000[0x24]; //0x0000
	__int32 m_iBeforeDirection; //0x0024 
	__int32 m_iCurStage; //0x0028 
	DWORD m_iCurTileX; //0x002C 
	DWORD m_iCurTileY; //0x0030 
	__int32 m_iBossStageNum; //0x0034 
	unsigned char m_bQuestStarted; //0x0038 
	unsigned char m_bWin; //0x0039 
	unsigned char m_bEndGame; //0x003A 
	unsigned char m_bClearStage; //0x003B 
	unsigned char m_bLoading; //0x003C 
	char pad_0x003D[0x3]; //0x003D
	DWORD m_dwEndGameDelay; //0x0040 
	unsigned char m_bDramaStage; //0x0044 
	char pad_0x0045[0x3]; //0x0045
	DWORD m_dwPlayFrame; //0x0048 
	unsigned char m_bShowStartMsg; //0x004C 
	unsigned char m_bPerfectMode; //0x004D 
	unsigned char m_bMonLoadComplete; //0x004E 
	char pad_0x004F[0x1]; //0x004F
	__int32 m_iMonsterNum; //0x0050 
	__int8 m_bIsHackedDungeon; //0x0054 
	unsigned char m_bIsMonsterHPHack; //0x0055 
	unsigned char m_bIsAttackedMon; //0x0056 
	unsigned char m_bBossStage; //0x0057 
	DWORD m_iCurMonsterNum; //0x0058 
	std::vector<std::vector<float>>  m_vecCurAtk; //0x005C  std::vector<std::vector<float>>
	std::vector<std::vector<float>>  m_vecIncAtkRatio; //0x0068  std::vector<std::vector<float>> 
	char pad_0x0074[0x44]; //0x0074
	unsigned char m_bSendGetEndGameInfo; //0x00B8 
	unsigned char m_bGetEndGameInfo; //0x00B9 
	char pad_0x00BA[0x2]; //0x00BA
	__int32 m_dwEndGameInfoDelayTime; //0x00BC 
	char pad_0x00C0[0xC]; //0x00C0
	unsigned char m_bSendRouletteList; //0x00CC 
	unsigned char m_bRouletteList; //0x00CD 
	char pad_0x00CE[0x2]; //0x00CE
	__int32 m_dwRouletteWaitDelay; //0x00D0 
	char pad_0x00D4[0x170]; //0x00D4
	std::map< std::pair<int, int>, bool > m_mapStageHistory; //0x0244 std::map< std::pair<int, int>, bool > 
	char pad_0x024C[0x18]; //0x024C
	DWORD m_iCurDialoge; //0x0264 
	unsigned char m_bMovement; //0x0268 
	char pad_0x0269[0x7]; //0x0269
	D3DXVECTOR2 m_vecArena; //0x0270 
	__int32 m_iMaxStage; //0x0278 
	__int32 m_iAllLevelMaxStage; //0x027C 
	DWORD m_iComboBreakCount; //0x0280 
	char pad_0x0284[0x1C]; //0x0284
	sEncrypt<float> m_fRankPoint; //0x02A0 
	sEncrypt<int> m_MaxCombo; //0x02B8 
	sEncrypt<int> m_MaxComboDamage; //0x02D0 
	sEncrypt<int> m_ComboDamage; //0x02E8 
	sEncrypt<int> m_TotalDamageFromMonster; //0x0300 
	sEncrypt<int> m_TotalBackPlusAerialAttack; //0x0318 
	sEncrypt<int> m_KillCombo; //0x0330 
	sEncrypt<int> m_MaxKillCombo; //0x0348 
	sEncrypt<int> m_BossKillCombo; //0x0360 
	sEncrypt<float> fTotalDamage; //0x0378 
	sEncrypt<int> m_InfinityDungeonPartyRank; //0x0390 
	sEncrypt<int> m_InfinityDungeonMonsterLevel; //0x03A8 
	unsigned char m_bExistMonsterInScreen; //0x03C0 
	unsigned char m_bPortalInScreen; //0x03C1 
	char pad_0x03C2[0x5A]; //0x03C2
	DWORD m_iHeroDungeonLevel; //0x041C 
	DWORD m_iPlayersAveLv; //0x0420 
	unsigned char m_ucPlayerNum; //0x0424 
	unsigned char m_bRankPortalCheck; //0x0425 
	unsigned char m_bComboBreak; //0x0426 
	char pad_0x0427[0x31]; //0x0427

}; //Size=0x0458
*/


class sPlayer_Work
{
public:
	unsigned char IsLive; //0x0000 
	unsigned char IsLevelUp; //0x0001 
	char pad_0x0002[0x2]; //0x0002
	__int32 IsSPLevelUp; //0x0004 
	float fGuildPointPercent; //0x0008 
	char pad_0x000C[0x8]; //0x000C
	DWORD Start_Score; //0x0014 
	sEncrypt<int> How_Kill; //0x0018 
	__int32 How_Die; //0x0030 
	unsigned char IsWin; //0x0034 
	char pad_0x0035[0x3]; //0x0035
	__int32 m_iChar; //0x0038 
	__int32 dwUID; //0x003C 
	char pad_0x0040[0x18]; //0x0040

}; //Size=0x0058



class cMission
{
public:
	cKGCGameBoard* pMissionInfo; //0x0000 
	char pad_0x0004[0x3C]; //0x0004

}; //Size=0x0040

class cKGCGameBoard
{
public:
	std::vector< int >  m_vtMonKillTGID; //0x0000 std::vector< int >  
	std::map< int, unsigned short > m_mapMonKillNum; //0x000C 
	std::map< int, unsigned short > m_mapMonNum; //0x0014 
	char pad_0x001C[0x94]; //0x001C
	sEncrypt<int> m_GameTime; //0x00B0 
	char pad_0x00C8[0x30]; //0x00C8
	__int32 m_iAttackCount; //0x00F8 
	char pad_0x00FC[0x4]; //0x00FC
	sPlayer_Work m_pStartingMember[6]; //0x0100 
	char pad_0x0310[0x40]; //0x0310

}; //Size=0x0350

class cDrop
{
public:
	cKGCDropManager* pDropManager; //0x0000 
	char pad_0x0004[0x60]; //0x0004

}; //Size=0x0064


class cKGCDropManager
{
public:
	char pad_0x0000[0x14]; //0x0000
	map<DWORD, cKGCDropItem*> m_mapItemDrop; //0x0014 
	char pad_0x001C[0x8]; //0x001C
	map<DWORD, cKGCDropItem*> m_mapGpDrop; //0x0024 
	char pad_0x002C[0x6C]; //0x002C
	std::set< DWORD> m_setGetGP; //0x0098 std::set< DWORD>
	std::map< DWORD, DWORD > m_mapGetItem; //0x00A0 std::map< DWORD, DWORD >

}; //Size=0x0084

class cKGCDropItem
{
public:
	char pad_0x0000[0x8]; //0x0000
	__int32 m_iTriggerID; //0x0008 
	DWORD m_dwDropUID; //0x000C 
	DWORD m_dwUserUID; //0x0010 
	__int32 m_iOwnerIndex; //0x0014 
	unsigned char m_cDropType; //0x0018 
	char pad_0x0019[0x3]; //0x0019
	__int32 m_dwGoodsID; //0x001C 
	DWORD m_iDuration; //0x0020 
	DWORD m_iMonID; //0x0024 
	DWORD m_iStageCountType; //0x0028 
	DWORD m_iState; //0x002C 
	DWORD m_iTime; //0x0030 
	char pad_0x0034[0x4]; //0x0034
	D3DXVECTOR2 m_vPos; //0x0038 
	char pad_0x0040[0x58]; //0x0040
	wstring m_strName; //0x0098 
	char pad_0x00B0[0x5C]; //0x00B0

}; //Size=0x010C

/*
class cKGCDropItem
{
public:
	char pad_0x0000[0x1C]; //0x0000
	DWORD dwId; //0x001C 
	char pad_0x0020[0xC]; //0x0020
	DWORD dwDropItem; //0x002c
	DWORD dwElapseTime; //0x0030 
	char pad_0x0034[0x4]; //0x0034
	D3DXVECTOR2 m_vPos; //0x0038 
	char pad_0x0040[0x58]; //0x0040
	wstring szName; //0x0098 wstring 
	char pad_0x00B0[0x54]; //0x00B0

}; //Size=0x0104
*/

class cKGCPortal
{
public:
	char pad_0x0000[0x8]; //0x0000
	D3DXVECTOR2 m_vPos; //0x0008 
	char pad_0x0010[0xC]; //0x0010
	__int8 m_bIsOpen; //0x001C 
	char pad_0x001D[0x7]; //0x001D
	__int32 dwPortalCode; //0x0024 
	char pad_0x0028[0xC]; //0x0028
	DWORD dwPortalFlag; //0x0034 
	DWORD dwDirection; //0x0038 
	char pad_0x003C[0x404]; //0x003C

}; //Size=0x0440


class cPortalManager
{
public:
	std::map <cKGCPortal*, DWORD> m_mapPortal;

}; //Size=0x0040




class cRoomScene
{
public:
	cKGCRoomSceneS6* pRoomSceneS6; //0x0000 
	char pad_0x0004[0x3C]; //0x0004

}; //Size=0x0040


class cKGCRoomSceneS6
{
public:
	char pad_0x0000[0x408]; //0x0000
	cKGCRoomButtonPanelS6* pRoomButtonPanelS6; //0x0408 
	char pad_0x040C[0x7FC]; //0x040C

}; //Size=0x0C08


class cKGCRoomButtonPanelS6
{
public:
	char pad_0x0000[0x344]; //0x0000
	cKD3DButton* pStartButton; //0x0344 
	char pad_0x0348[0x4]; //0x0348

}; //Size=0x034C


class cKD3DButton
{
public:
	char pad_0x0000[0xC]; //0x0000
	char* szName; //0x000C 
	char pad_0x0010[0x130]; //0x0010
	D3DXVECTOR2 m_vPosition; //0x0140 
	char pad_0x0148[0x3C]; //0x0148

}; //Size=0x0184


class cGameScene
{
public:
	cKGCScene* pCurrentScene; //0x0000 

}; //Size=0x0040

class cKGCScene
{
public:
	char pad_0x0000[0xC]; //0x0000
	__int32 dwId; //0x000C 
	char pad_0x0010[0x4]; //0x0010
	string szName; //0x0014 
	char pad_0x002C[0x3C]; //0x002C
	cKGCUIScene* pUIScene; //0x0068 
	char pad_0x006C[0x4]; //0x006C
	std::vector<cKGCScene*> m_vChildren; //0x0070 
	char pad_0x007C[0x2BC]; //0x007C

}; //Size=0x0338


class cSceneList
{
public:
	cKGCScene* pChild[15]; //0x0000 

}; //Size=0x07A8

class cKGCUIScene
{
public:
	char pad_0x0000[0x4]; //0x0000
	string szName; //0x0004 
	char pad_0x001C[0x4C]; //0x001C
	cKGCScene* pCurrentUI; //0x0068
	char pad_0x006C[0x2D4]; //0x006C
	KGCNewNecklaceEnchantDlg* pGCNewNecklaceEnchantDlg; //0x0340 
	char pad_0x0344[0x1C]; //0x0344

}; //Size=0x0360


class cKGCGrowthMissionDlg : public cKGCScene
{
public:
	char pad_0x0330[0xC]; //0x0330
	cGrowthRewards* pGrowthRewards; //0x033C 
	char pad_0x0340[0x28]; //0x0340

}; //Size=0x0368


class cGrowthRewards
{
public:
	cGrowthMission* pReward[21]; //0x0000 

}; //Size=0x0084

class cGrowthMission
{
public:
	__int32 dwID; //0x0000 
	__int32 dwPrevID; //0x0004 
	string szName; //0x0008 
	__int32 dwGoal; //0x0020 
	DWORD dwVP; //0x0024 
	DWORD dwRewardId; //0x0028 
	DWORD dwRewardQuantity; //0x002C 
	__int32 dwToolTip; //0x0030 

}; //Size=0x0034

class cGameInput
{
public:
	KInput* cInput; //0x0000 
	char pad_0x0004[0x3C]; //0x0004

}; //Size=0x0040

class KInput
{
public:
	char pad_0x0000[0x110]; //0x0000
	__int32 dwRightMouse; //0x0110 
	char pad_0x0114[0x114]; //0x0114
	__int8 RightMouse; //0x0228 
	char pad_0x0229[0x5DB]; //0x0229

}; //Size=0x0804

class cGameOverlay
{
public:
	cKGCGameOverlayUI* pGameOverlayUI; //0x0000 
	char pad_0x0004[0x9C]; //0x0004

}; //Size=0x00A0

class cKGCGameOverlayUI
{
public:
	char pad_0x0000[0x474]; //0x0000
	unsigned char bIsShowDialogue; //0x0474 

}; //Size=0x0484

class CEveryTriggerManager
{
public:
	char pad_0x0000[0x10]; //0x0000
	std::vector<CTrigger*> m_vtActiveTrigger; //0x0010 
	char pad_0x001C[0x1C]; //0x001C
	string szRenderStage; //0x0038 
	sEncrypt<int> m_RenderStage; //0x0050 
	char pad_0x0068[0x10]; //0x0068
	string szStage; //0x0078 
	sEncrypt<int> m_Stage; //0x0090 
	char pad_0x00A8[0x440]; //0x00A8

}; //Size=0x04E8

class cTriggerList
{
public:
	CTrigger* pTrigger; //0x0000 
	char pad_0x0004[0x20]; //0x0004

}; //Size=0x0024

class CTrigger
{
public:
	char pad_0x0000[0x18]; //0x0000
	string szName; //0x0018 
	cTriggerChildren* pChildren; //0x0030 
	char pad_0x0034[0x50]; //0x0034

}; //Size=0x0084


class cTriggerChildren
{
public:
	char pad_0x0000[0x4]; //0x0000
	cTGInfinityMonsterGen* pInfinityMonsterGen; //0x0004 
	char pad_0x0008[0x40]; //0x0008

}; //Size=0x0048


class sInfinityTime
{
public:
	DWORD dwMax; //0x0000 
	DWORD dwCurrent; //0x0004 

}; //Size=0x0008

class cTGInfinityMonsterGen
{
public:
	char pad_0x0000[0x18]; //0x0000
	sInfinityTime m_MobSpawn; //0x0018 
	char pad_0x0020[0x4]; //0x0020
	sInfinityTime m_CommonBoss; //0x0024 
	sInfinityTime m_BestBoss; //0x002C 
	sInfinityTime m_WaitBoss; //0x0034 
	sInfinityTime m_RestartSpawn; //0x003C 
	unsigned char bSpawn; //0x0044 
	unsigned char bIsSpawnFreezed; //0x0045 
	unsigned char bShowPortalMsg; //0x0046 
	unsigned char bIsSpawnFreezedByBoss; //0x0047 
	char pad_0x0048[0x40]; //0x0048

}; //Size=0x0088

class cItemInfo
{
public:
	wstring szName; //0x0000 
	char pad_0x0018[0x18]; //0x0018
	DWORD dwId; //0x0030 
	char pad_0x0034[0xC]; //0x0034
	DWORD dwLevel; //0x0040 
	char pad_0x0044[0x4]; //0x0044
	DWORD dwStatus; //0x0048 
	char pad_0x004C[0x28]; //0x004C
	DWORD dwSellPrice; //0x0074 
	char pad_0x0078[0x68]; //0x0078

}; //Size=0x00E0


class cKCItemManager
{
public:
	char pad_0x0000[0xA0]; //0x0000
	std::map<DWORD, KItem*> ItemList; //0x00A0 
	char pad_0x00A8[0x4C]; //0x00A8
	stdext::hash_map<DWORD, cItemInfo*> m_mapDB; //0x00F0 
	char pad_0x0114[0xD0]; //0x0114

}; //Size=0x01E4


class cItemManager
{
public:
	cKCItemManager* Manager; //0x0000 
	char pad_0x0004[0x8]; //0x0004

}; //Size=0x000C

template <typename T>
class sData
{
public:
	T Value[20]; //0x0000 

}; //Size=0x0004

template <typename T>
class sLuaVector
{
public:
	int GetSize()
	{
		return  (dwLength - (DWORD)Data) / 4;
	}

	sData<T>* Data; //0x0000 
	DWORD dwLength; //0x0004 
	char pad_0x0008[0x4]; //0x0008

}; //Size=0x000C

class cInfinityDungeon
{
public:
	map<DWORD, cInfinityDungeonInfo> m_mapInfintyDungeon; //0x0000 cInfinityDungeonInfo
	char pad_0x0004[0x10]; //0x0004
	__int32 dwWaveSpawned; //0x0014 

}; //Size=0x0084

class cInfinityDungeonInfo
{
public:
	DWORD dwDungeonId; //0x0000 
	char pad_0x0004[0x18]; //0x0004
	DWORD dwBossRegenRank; //0x001C 
	DWORD dwRegenWaitTime; //0x0020 
	DWORD dwMinBossRegenTime; //0x0024 
	DWORD dwMaxBossRegenTime; //0x0028 
	map<DWORD, sMonsterRankInfo> m_mapMonsterRank; //0x002C  map<DWORD,sMonsterRank>
	DWORD dwMonsterRegenTime; //0x0034 
	DWORD dwStartMonsterLevel; //0x0038 
	sLuaVector<DWORD> m_MonsterQuantity; //0x003C 
	sLuaVector<DWORD> m_StartMonsterSpawn; //0x0048 
	map <DWORD, sMonsterSpawnInfo> m_mapMonsterSpawnInfo; //0x0054  sMonsterSpawnInfo

}; //Size=0x005C


class sMonsterRankInfo
{
public:
	DWORD dwRank; //0x0000 
	DWORD dwLevel; //0x0004 

}; //Size=0x0008

class sMonsterSpawnInfo
{
public:
	DWORD dwIndex; //0x0000 
	DWORD dwLevel; //0x0004 
	sLuaVector<DWORD> m_Rank; //0x0008 
	sLuaVector<DWORD> m_Monster; //0x0014 

}; //Size=0x0024

class KGCNewNecklaceEnchantDlg : public cKGCScene
{
public:
	char pad_0x0338[0x2C]; //0x0338
	DWORD m_ItemID; //0x0364 
	DWORD m_ItemUID; //0x0368 
	DWORD m_AssistID; //0x036C 
	DWORD nMaterial; //0x0370 
	DWORD nLevel; //0x0374 
	DWORD m_Result; //0x0378 
	DWORD m_Count; //0x037C 
	char pad_0x0380[0x38]; //0x0380

}; //Size=0x03B8


enum EM_DUNGEON_TYPE
{
	DUNGEON_TYPE_INVALID = -1,
	DUNGEON_TYPE_NORMAL = 0,
	DUNGEON_TYPE_HERO = 1,
	DUNGEON_TYPE_EVENT = 2,
	DUNGEON_TYPE_RELAY_HERO = 3,
	DUNGEON_TYPE_RAID_HERO = 4,
	DUNGEON_TYPE_INFINITY = 5,
};

struct SDungeonInfo
{
	EGCGameMode         m_emGameMode;       //  게임모드 ( 던전 Flag ) 
	std::string         m_strLoadingImg;    // 로딩 파일 이름 
	int                 m_nLimitLevel;     //  던전 난이도 ( 노멀 1, 어려움 2, 매우어려움 3 ) 
	bool                m_bHellMode;        //  헬모드 여부
	EM_DUNGEON_TYPE     m_emDungeonType;    //  던전 타입
	int                 m_nDungeonName;     //  던전 이름 스트링 넘버
	int                 m_nWorldMapName;    //  월드맵 이름 스트링 넘버
	bool                m_bShowPlayTime;  // 플레이 타임 출력여부
	bool                m_bShowRank;  // 랭크UI 출력여부
	bool                m_bShowTodayTip;  // 오늘의 팁 출력여부
	bool                m_bComboEffect;  // 콤보이펙트 출력여부
	bool                m_bUseGameItem;    // 게임아이템 사용여부
	bool                m_bUsePetSkill;    // 펫 필살기 사용여부
	bool                m_bNoRecoveryMode; // MP자동회복 금지모드
	int                 m_nMaxPlayerNum;    // 던전 플레이 인원
	int                 m_iCharLife;    // 던전 기본 Life
};

class cKGCWorldManager
{
public:
	std::map<EGCGameMode, SDungeonInfo> m_mapDungeonInfo; //0x0000
	char pad_0x0008[0x20]; //0x0008
	DWORD m_eCurrentWorldMap; //0x0028 
	DWORD m_iCurrentSelectDungeon; //0x002C 
	char pad_0x0030[0x3D4]; //0x0030

}; //Size=0x0404


struct KCharacterStats
{
public:
	enum MODE_TYPE {
		MT_DUNGEON = 0,
		MT_TEAM,
		MT_SURVIVAL,
	};

	int     m_nAccCount;  // 플레이 횟수
	int     m_nModeType;  // 모드 타입
};

#define DECL_DATA(p) struct p

DECL_DATA(KCharacterExpInfo)
{
	char                m_cCharType;
	int                 m_nBaseExp; // 게임후 기본적으로 받는 경험치;
	int                 m_nTotalRecvExp;
	std::map<int, float> m_mapExpBoost;
	std::map<int, float> m_mapSpxBoost;
	int                 m_nAdditionnalExp;
	DWORD               m_dwTotalRecvSpx;;
	char                m_cCharJob;
	void Clear()
	{
		m_nBaseExp = 0;
		m_nTotalRecvExp = 0;
		m_mapExpBoost.clear();
		m_mapSpxBoost.clear();
		m_nAdditionnalExp = 0;
		m_dwTotalRecvSpx = 0;
	}
};

DECL_DATA(KKillCoinInfo)
{
	DWORD   m_dwUserUID;
	char    m_cCharType;
	int     m_nCoin;
};

DECL_DATA(KHackData)
{
	std::vector<float>  m_vecAtkData;       // 클라이언트 공격력 값(스테이지 클리어 개수만큼)
	std::vector<float>  m_vecIncAPRatio;    // 클라이언트 공격력 증가 비율값(스테이지 클리어 개수만큼)
	bool                m_bUseAllKill;      // 올킬 사용여부
	bool                m_bMonsterHPHack;   // 몬스터HP 해킹여부

	void Clear()
	{
		m_vecAtkData.clear();
		m_vecIncAPRatio.clear();
		m_bUseAllKill = false;
		m_bMonsterHPHack = false;
	}
};

DECL_DATA(KDungeonDetail) // 한 캐에 대한 스킬 정보.
{
	DWORD                   m_dwDungeonID;    // 던전 ID.
	DWORD                   m_dwDifficult;    // 던전 난이도.
	DWORD                   m_dwStageID;      // StageID.

	KDungeonDetail() :m_dwDungeonID(0), m_dwDifficult(0), m_dwStageID(0) {}

	bool operator < (const KDungeonDetail & right) const
	{
		if (m_dwDungeonID > right.m_dwDungeonID) return false;
		else if (m_dwDungeonID < right.m_dwDungeonID) return true;

		if (m_dwDifficult > right.m_dwDifficult) return false;
		else if (m_dwDifficult < right.m_dwDifficult) return true;

		if (m_dwStageID > right.m_dwStageID) return false;
		else if (m_dwStageID < right.m_dwStageID) return true;

		return false;
	}

private:
	bool operator == (const KDungeonDetail & right) const;
	bool operator >= (const KDungeonDetail & right) const;
	bool operator <= (const KDungeonDetail & right) const;
	bool operator >  (const KDungeonDetail & right) const;
};

DECL_DATA(KDungeonCharInfo)
{
	DWORD                   m_dwLoginUID;
	DWORD                   m_dwCharType;
	DWORD                   m_dwLevel;
	DWORD                   m_dwDungeonID;
	DWORD                   m_dwDifficult;
	DWORD                   m_dwPlayTime;
	DWORD                   m_dwNormalAttack;       // 캐릭터 공격력
	DWORD                   m_dwDefence;            // 캐릭터 방어력
	DWORD                   m_dwVitality;           // 캐릭터 생명령
	DWORD                   m_dwSpecialAttack;      // 캐릭터 스킬 공격력
	DWORD                   m_dwMPDrain;            // MP 흡수력
	float                   m_fMPRecoveryRate;      // MP 회복율(예: 50%라면 0.5)
	float                   m_fCounterResistRate;   // 카운터 저항
	DWORD                   m_dwTotalAttack;        // 종합 공격력
	float                   m_fCriticalAttackRate;  // 치명타 확률(예: 50%라면 0.5)
	float                   m_fCriticalDamageRate;  // 치명타 데미지 증가비율(예: 150%라면 1.5)
};

DECL_DATA(KDungeonPlayState)
{
	DWORD              m_dwClearTime;              // 클리어Time (초)
	USHORT             m_usDeath_Cnt;              // 죽은 카운터
	USHORT             m_usLeave_Cnt;              // 게임을 떠난 카운터
	USHORT             m_usSpecial_Cnt;            // 필살기를 사용한 카운터
	USHORT             m_usPetSpecial_Cnt;         // 펫 필살기를 사용한 카운터
	DWORD              m_dwReceiveDamage;          // 내가 받는 데미지 합
	DWORD              m_dwSendDamage;             // 내가 주는 데미지 합
};

DECL_DATA(KDungeonPersonalRecord)
{
	int         m_nStageNum;
	DWORD       m_dwStageClearTime;
	int         m_nControlRank;

	KDungeonPersonalRecord() : m_nStageNum(0), m_dwStageClearTime(0), m_nControlRank(0) {};
};

DECL_DATA(KUserViewGradeTime)
{
	DWORD                   m_dwUserUID;
	DWORD                   m_dwDungeonID;
	DWORD                   m_dwCharType;
	std::map<float, DWORD>   m_mapViewGradeTime;

	KUserViewGradeTime()
		:m_dwUserUID(0)
		, m_dwDungeonID(0)
		, m_dwCharType(0)
	{
		m_mapViewGradeTime.clear();
	}
};

DECL_DATA(KUserLoadingStat)
{
	int                                             m_nGameMode;
	int                                             m_nPartyUserNum;
	int                                             m_nLoadingOutUserCnt;
	int                                             m_nAvgLoadingComplete;
	int                                             m_nAvgFPS;
	int                                             m_nPlayingOutUserCnt;

	KUserLoadingStat() :m_nGameMode(0)
		, m_nPartyUserNum(0)
		, m_nLoadingOutUserCnt(0)
		, m_nAvgLoadingComplete(0)
		, m_nAvgFPS(0)
		, m_nPlayingOutUserCnt(0)
	{}
};

DECL_DATA(KMonsterTypeStat)
{
	int                                         m_nModeID;
	int                                         m_nDifficult;
	DWORD                                       m_dwUserUID;
	int                                         m_nTotalPartyNum;
	bool                                        m_bClear;
	DWORD                                       m_dwPlayTime;
	std::map< std::pair<int, int>, int >          m_mapMonsterTypeCount;
	int                                         m_nTotalDeathCount;

	KMonsterTypeStat() :m_nModeID(0)
		, m_nDifficult(0)
		, m_dwUserUID(0)
		, m_nTotalPartyNum(0)
		, m_bClear(false)
		, m_dwPlayTime(0)
		, m_nTotalDeathCount(0)
	{
		m_mapMonsterTypeCount.clear();
	}

	void Init()
	{
		m_nModeID = 0;
		m_nDifficult = 0;
		m_dwUserUID = 0;
		m_nTotalPartyNum = 0;
		m_bClear = false;
		m_dwPlayTime = 0;
		m_nTotalDeathCount = 0;
		m_mapMonsterTypeCount.clear();
	}
};

DECL_DATA(KUserSkillStat)
{
	std::map< int, int >                    m_mapSkillSlotInfo; // 스킬 슬롯 장착정보 [Index, SkillID]
	std::map< int, int >                    m_mapSkillUseCount; // 스킬 사용 횟수 정보[SkillID, UseCnt]
};

DECL_DATA(KDungeonSubjectStat)
{
	DWORD                           m_dwLoginUID;           // 플레이한 유저의 UID
	int                             m_nGameMode;            // 과제를 수행한 던전 번호
	int                             m_nDifficulty;          // 과제를 수행한 던전의 난이도
	int                             m_nCharType;            // 과제를 수행한 캐릭터
	int                             m_nCharLevel;           // 과제를 수행한 캐릭터의 레벨
	int                             m_nCharPromotion;       // 과제를 수행한 캐릭터의 전직 상태
	std::map< int, std::vector< std::pair< int, bool > > > m_mapSubjectClearInfo;  // map< StageID, vector< pair< SubjectID, bClear > > >

	KDungeonSubjectStat()
		: m_dwLoginUID(0)
		, m_nGameMode(0)
		, m_nDifficulty(0)
		, m_nCharType(0)
		, m_nCharLevel(0)
		, m_nCharPromotion(0)
	{
		m_mapSubjectClearInfo.clear();
	}
};

DECL_DATA(KUserControlInfo)
{
	int                     m_nRank;            // 랭크
	int                     m_nBeAttackedCount; // 피격 횟수
	int                     m_nComboCount;      // 콤보 횟수
	int                     m_nBackAttackCount; // 백어택 횟수
	std::map<int, int>      m_mapUseSkillCount; // 스킬 사용 횟수.
	std::map<int, int>      m_mapUsePositionCount; // 포션 사용 횟수.

	KUserControlInfo()
		: m_nRank(0)
		, m_nBeAttackedCount(0)
		, m_nComboCount(0)
		, m_nBackAttackCount(0)
	{
		m_mapUseSkillCount.clear();
		m_mapUsePositionCount.clear();
	}
};

DECL_DATA(KGameResultIn)
{
	std::wstring                              m_strLogin;
	DWORD                                     m_dwUID;
	int                                       m_nBaseGP;
	int                                       m_nTotalRecvGP;
	int                                       m_iContPoint;
	bool                                      m_bWin;
	int                                       m_iNumKills;
	int                                       m_iNumDies;
	int                                       m_nScore;
	std::vector< KCharacterExpInfo >          m_vecCharExp;         // 경험치 정보 <캐릭터 경험치 정보>
	std::map<int, float>                       m_mapExpBoost;
	std::map<int, float>                       m_mapGpBoost;
	std::map<int, float>                       m_mapSpxBoost;
	int                                       m_nAddtionalGp;
	std::vector<KKillCoinInfo>                m_vecKillCoin;
	KHackData                                 m_kHactkData;
	// 던전 통계용 데이터
	int                                       m_nClearStageCount;   // 클리어한 스테이지 수
	int                                       m_nLastStageID;       // 클리어한 스테이지중 마지막으로 유저가 있던 스테이지 번호
	int                                       m_nLifeCount;         // 남은 목숨수
	int                                       m_nRegenCount;        // 죽어서 부활한 수
	int                                       m_nResult;            // 게임결과(0:성공 / 0이상:클라이언트 정의값)
	bool                                      m_bIsBossStage;       // 마지막이 보스 스테이지인지.
	DWORD                                     m_dwGuildBattlePoint;
	std::map<GCITEMID, int>                   m_mapItemUseCount; // 아이템 사용 횟수.
	std::map<std::pair<DWORD, GCITEMID>, int> m_mapItemBuyCount; // 캐릭터 레벨별 구입 아이템 횟수.
	std::map<DWORD, int>                       m_mapZoneDeathCount; // Zone별 Death Count
	std::map<std::pair<DWORD, DWORD>, int >   m_mapDeathType; //< <Type,Index>, Cnt > Type( Mon : 0, Char : 1 ),index( 고유값 )
	std::map< KDungeonDetail, KDungeonPlayState > m_mapDungeonPlayState;  // 던전 플레이 통계
	std::vector<KDungeonCharInfo>             m_vecDungeonCharStat; // 던전 캐릭터 통계
	std::pair<int, int>                        m_prUseSkillCount; // [스킬 단축버튼 사용 Cnt, 스킬 차징 사용 Cnt ]
	KUserViewGradeTime                        m_kUserViewGradeTime;
	KUserLoadingStat                          m_kUserLoadingStat;     // 유저 로딩 통계.
	KMonsterTypeStat                          m_kMonsterTypeStat; // 몬스터 Type 통계.
	KUserSkillStat                            m_kUserSkillStat;
	char                                      m_cCurrentPromotion; // 플레이한 캐릭터 전직 정보.
	KDungeonSubjectStat                       m_kDungeonSubjectStat; // 던전 과제 달성 통계
	KUserControlInfo                          m_kUserControlInfoData; // 유저 컨트롤 관련 정보
	std::map< int, KDungeonPersonalRecord >   m_mapDungeonPersonalRecord; // 개인 최고 기록 정보 < StageNum, DungeonPersonalRecord >, 던전 랭킹에서도 사용

	KGameResultIn() :m_dwUID(0)
	{
		m_nBaseGP = 0;
		m_nTotalRecvGP = 0;
		m_iContPoint = 0;
		m_bWin = 0;
		m_iNumKills = 0;
		m_iNumDies = 0;
		m_nScore = 0;
		m_mapExpBoost.clear();
		m_mapGpBoost.clear();
		m_mapSpxBoost.clear();
		m_nAddtionalGp = 0;
		m_vecKillCoin.clear();
		std::vector< KCharacterExpInfo >::iterator vit;
		for (vit = m_vecCharExp.begin(); vit != m_vecCharExp.end(); ++vit)
		{
			vit->Clear();
		}
		m_kHactkData.Clear();
		m_nClearStageCount = 0;
		m_nLastStageID = 0;
		m_nLifeCount = 0;
		m_nRegenCount = 0;
		m_nResult = 0;
		m_bIsBossStage = false;
		m_dwGuildBattlePoint = 0;
		m_mapItemUseCount.clear();
		m_mapItemBuyCount.clear();
		m_mapZoneDeathCount.clear();
		m_mapDeathType.clear();
		m_mapDungeonPlayState.clear();
		m_vecDungeonCharStat.clear();
		m_prUseSkillCount.first = 0;
		m_prUseSkillCount.second = 0;
		m_cCurrentPromotion = 0;
		m_mapDungeonPersonalRecord.clear();
	}

	void Clear()
	{
		m_dwUID = 0;
		m_nBaseGP = 0;
		m_nTotalRecvGP = 0;
		m_iContPoint = 0;
		m_bWin = 0;
		m_iNumKills = 0;
		m_iNumDies = 0;
		m_nScore = 0;
		m_mapExpBoost.clear();
		m_mapGpBoost.clear();
		m_mapSpxBoost.clear();
		m_nAddtionalGp = 0;
		m_vecKillCoin.clear();
		std::vector< KCharacterExpInfo >::iterator vit;
		for (vit = m_vecCharExp.begin(); vit != m_vecCharExp.end(); ++vit)
		{
			vit->Clear();
		}
		m_kHactkData.Clear();
		m_nClearStageCount = 0;
		m_nLastStageID = 0;
		m_nLifeCount = 0;
		m_nRegenCount = 0;
		m_nResult = 0;
		m_bIsBossStage = false;
		m_dwGuildBattlePoint = 0;
		m_mapItemUseCount.clear();
		m_mapItemBuyCount.clear();
		m_mapZoneDeathCount.clear();
		m_mapDeathType.clear();
		m_mapDungeonPlayState.clear();
		m_vecDungeonCharStat.clear();
		m_prUseSkillCount.first = 0;
		m_prUseSkillCount.second = 0;
		m_cCurrentPromotion = 0;
		m_mapDungeonPersonalRecord.clear();
	}
};

struct KEndGameReq
{
public:
	std::vector<KGameResultIn>              m_vecGameResult;
	int                                     m_iQuestEndingStage;      // 이녀석은 앞으로 어떻게 사용될지 모르겠다...   
	std::set<int>                           m_setKillMonster;         // 죽인 몬스터의 트리거 생성 ID 생성 트리거는 중복안되니까..
	std::map<DWORD, DWORD>                   m_mapDropResult;          // < Drop UID, User UID >
	std::map< DWORD, std::vector<DWORD> >   m_mapRouletteList;        // < Item's UID, UserUID List >
	std::set<int>                           m_setClearStageCount;     // 몇개의 스테이지를 클리어 했는지 확인.
	DWORD                                   m_dwElapsedSec;           // 던전 클리어 타임 (초단위)
	std::map< DWORD, DWORD >                m_mapGameCountEvent;      // 게임 카운트, 시간에 따른 이벤트 (클라이언트에서 결과 전송) std::map< PlayerUID, EventMode >
	bool                                    m_bGuild;
	USHORT                                  m_usRoomID;
	DWORD                                   m_dwUserUID;
	std::set<DWORD>                         m_setDropGPUID;           // 게임중 획득한 GP UID
	UINT                                    m_uiMVP;                  // MVP, 클라이언트 필요정보
	bool                                    m_bIsBlueWin;             // 승리팀 , 클라이언트 필요정보
	std::vector<bool>                       m_vecIsPlayerWin;         // 클라이언트로 전달할 정보
	std::vector< std::pair< DWORD, int > >  m_vecGuildBPoint;         // < GuildUID, BPointDiff > 클라이언트로 전달하는 길드 배틀 포인트 변화량
	bool                                    m_bIsEscortMonsterAlive;  // 호위 이벤트 몬스터가 살아있으면 true
	bool                                    m_bIsActiveEscortEvent;   // 호위 이벤트 중이면 true
	DWORD                                   m_dwEscortMonsterID;      // 호위 이벤트 몬스터ID, 호위 이벤트 중이고 살아있는 경우 세팅
	std::map<std::pair<int, int>, KCharacterStats>   m_mapCharStats;   // 캐릭터 관련 통계

	void Clear()
	{
		m_vecGameResult.clear();
		m_iQuestEndingStage = 0;
		m_setKillMonster.clear();
		m_mapDropResult.clear();
		m_mapRouletteList.clear();
		m_setClearStageCount.clear();
		m_dwElapsedSec = 0;
		m_mapGameCountEvent.clear();
		m_bGuild = false;
		m_usRoomID = 0;
		m_dwUserUID = 0;
		m_setDropGPUID.clear();
		m_uiMVP = 0;
		m_bIsBlueWin = false;
		m_vecIsPlayerWin.clear();
		m_vecGuildBPoint.clear();
		m_bIsEscortMonsterAlive = false;
		m_bIsActiveEscortEvent = false;
		m_dwEscortMonsterID = 0;
		m_mapCharStats.clear();
	}
};

enum EGCPlayerMagicEffect
{
	EGC_EFFECT_DARKBALL = 0,
	EGC_EFFECT_EAGLE_SITE,
	EGC_EFFECT_CONFUSION,
	EGC_EFFECT_BOOST_HEAL,
	EGC_EFFECT_ATHENS_SWORD,
	EGC_EFFECT_DARK_SWORM,
	EGC_EFFECT_BLOOD_BASH,
	EGC_EFFECT_FIRE_SHIELD,
	EGC_EFFECT_BACKSTEP,
	EGC_EFFECT_BACKSTEP_APPEAR,
	EGC_EFFECT_ANKH_OF_RESURRECTION,
	EGC_EFFECT_SPIT,
	EGC_EFFECT_METAMORPHOSIS_WOLF,
	EGC_EFFECT_METAMORPHOSIS_WOLF_MOON_LIGHT,
	EGC_EFFECT_METAMORPHOSIS_WOLF_AURA,
	EGC_EFFECT_METAMORPHOSIS_WOLF_AURA_SELF,
	EGC_EFFECT_METAMORPHOSIS_NEPHILLIM_FORM,
	EGC_EFFECT_NEPHILLIM_ARMOR_ME,
	EGC_EFFECT_NEPHILLIM_ARMOR_FRIEND,
	EGC_EFFECT_JEWEL_OF_QUEEN,
	EGC_EFFECT_GRADE_BONUS,
	EGC_EFFECT_MOON_FESTIVAL,
	EGC_EFFECT_RONAN_MAGIC_SWORD,
	EGC_EFFECT_RONAN_MAGIC_SWORD_FRIEND,
	EGC_EFFECT_STAT_BALANCE,
	EGC_EFFECT_SUN_FESTIVAL,
	EGC_EFFECT_RONAN_HEAL,
	EGC_EFFECT_BOMB_INFECT,
	EGC_EFFECT_WHITEDAY,
	EGC_EFFECT_METAMORPHOSIS_MDAN_FORM,
	EGC_EFFECT_AMY1_DANCING_BUFF,
	EGC_EFFECT_AMY1_FEVER_TIME_BUFF,
	EGC_EFFECT_AMY1_GODDESS_BUFF,
	EGC_EFFECT_AMY_EVENT,
	EGC_EFFECT_DUNGEON_DAY,
	EGC_EFFECT_RONAN3_FORCE_BUFF,

	EGC_EFFECT_GUILD_MEMBER_POWER_UP,
	EGC_EFFECT_GUILD_POWER_UP,
	EGC_EFFECT_GUILD_FATAL_POWER_UP,
	EGC_EFFECT_GUILD_COUNTER_POWER_UP,
	EGC_EFFECT_GUILD_COUNTER_POWER_UP_REAL,
	EGC_EFFECT_GUILD_CRITICAL,
	EGC_EFFECT_GUILD_MEMBER_GUARD_UP,
	EGC_EFFECT_GUILD_GUARD_UP,
	EGC_EFFECT_GUILD_COUNTER_MANA_REGEN,
	EGC_EFFECT_GUILD_COUNTER_MANA_REGEN_REAL,
	EGC_EFFECT_GUILD_MANA_REGEN,
	EGC_EFFECT_GUILD_COUNTER_MANA_KEEP,
	EGC_EFFECT_GUILD_MEMBER_HP_UP,
	EGC_EFFECT_GUILD_HP_UP,
	EGC_EFFECT_GUILD_COUNTER_HP_REGEN,
	EGC_EFFECT_GUILD_COUNTER_HP_REGEN_REAL,
	EGC_EFFECT_GUILD_HP_REGEN,
	EGC_EFFECT_GUILD_EVASION,
	EGC_EFFECT_GUILD_MEMBER_GP_UP,
	EGC_EFFECT_GUILD_GP_UP,
	EGC_EFFECT_GUILD_MEMBER_EXP_UP,
	EGC_EFFECT_GUILD_EXP_UP,
	EGC_EFFECT_GUILD_FATAL_POWER_UP_REAL,
	EGC_EFFECT_GC_CLUB_BONUS,
	EGC_EFFECT_DEATHMATCH_BONUS,
	EGC_EFFECT_AMY2_PERFORMENCE_SPECIAL2_ATK,
	EGC_EFFECT_BRUNCH_OF_FLOWERS,

	EGC_SKILLEFFECT_ELESIS1_NEWSPECIAL1_B,
	EGC_SKILLEFFECT_ELESIS1_BERSERK,
	EGC_EFFECT_WELCOME_SEASON2,
	EGC_EFFECT_FRIENDS_DAY,
	EGC_EFFECT_EMBLEM,
	EGC_FRIENDSHIP_RING,
	EGC_ABYSS_KNIGHT,
	EGC_PV_DAY,
	EGC_EFFECT_SKILL_ARME_DEATHCLOUD_BUFF,
	EGC_EFFECT_SKILL_FEAR_LV1,
	EGC_EFFECT_SKILL_FEAR_LV2,
	EGC_EFFECT_SKILL_ARME_FROSTRING_LV1,
	EGC_EFFECT_SKILL_ARME_FROSTRING_LV2,

	EGC_EFFECT_SKILL_ARME_SAINTBREEDING,
	EGC_1010_DAY_GP100,
	EGC_EFFECT_AMY_TOGETHER,
	EGC_AMY3_DANCEMODE_SPECIAL1_EFF,
	EGC_AMY3_DANCEMODE_SPECIAL3_BUFF,//80

	EGC_EFFECT_COUPLE_BUFF, //81
	EGC_EFFECT_COUPLE_DAY,//82

	EGC_EFFECT_COUPLE_BUFF_GP,//83
	EGC_JIN_BURNNING_MODE_EFFECT,//84

	EGC_EFFECT_CAPTAIN_DEBUFF,//85
	EGC_EFFECT_CAPTAIN_BUFF,//86
	EGC_EFFECT_JEWEL_OF_AMY,
	EGC_EFFECT_SEIREN,//88
	EGC_BLUESTONE_DUNGEON,//89
	EGC_EFFECT_ATTACK_10PER_UP,//90
	EGC_EFFECT_DEFENCE_10PER_UP,//91
	EGC_EFFECT_HP_10PER_UP,                //92
	EGC_SKILLEFFECT_FIREARROW_DOTDAMAGE,   //93
	EGC_SKILLEFFECT_POISONARROW_DOTDAMAGE, //94
	EGC_SKILLEFFECT_DAMAGE_AMPLIFIER_LV1,  //95
	EGC_SKILLEFFECT_MOVE_SPEEDUP,          //96
	EGC_SKILLEFFECT_SHOT_SPEEDUP,          //97
	EGC_SKILLEFFECT_MP_REGEN_SPEED,        //98
	EGC_BUFF_COOLTIME_NOTIFIER_91,         //99 --no use
	EGC_BUFF_COOLTIME_NOTIFIER_92,         //100 --no use
	EGC_BUFF_COOLTIME_NOTIFIER_93,         //101 --no use

	EGC_BUFF_CLONE_ATK,                    //102
	EGC_SKILL_DROP_WEAPON,                 //103
	EGC_SKILL_STUN_SURIKEN,                //104
	EGC_SKILL_HIDE,                        //105
	EGC_SKILL_LAS_MOVE_SPEEDUP,            //106
	EGC_SKILL_LAS_SUPER_JUMP,              //107
	EGC_EFFECT_DEVIL,					//108
	EGC_EFFECT_LIRE_TOGETHER,			//109
	EGC_SKILLEFFECT_WING_SHOES,			//110
	EGC_SKILLEFFECT_SPY_CLOAK,			//111
	EGC_SKILLEFFECT_SANDGLASS,			//112
	EGC_EFFECT_NEW_DUNGEON_DAY,			//113
	EGC_EFFECT_HONGKONG_3TH_ANNIVERSARY,//114
	EGC_EFFECT_GLAD_FRIEND, //반갑다친구야(홍콩) //115
	EGC_EFFECT_HONGKONG_CHARACTER_EMBLEM,		//116
	EGC_SIEG_FURY,						//117

	EGC_EFFECT_SUMMON_BONG,				//118
										// 스크립트에 enum좀 적어주시고, 숫자좀 잘 맞춰주시길...

										EGC_EFFECT_HP_TOTEM_COOL,			//119
										EGC_EFFECT_MP_TOTEM_COOL,			//120
										EGC_EFFECT_DP_TOTEM,				//121
										EGC_EFFECT_DP_TOTEM_COOL,			//122
										EGC_EFFECT_WOLF_HOWL,				//123
										EGC_EFFECT_RYAN_MOVE_SPEEDUP,		//124
										EGC_EFFECT_RYAN_STRONGLY_LIFE_FORCE_LV1,		//125
										EGC_EFFECT_RYAN_STRONGLY_LIFE_FORCE_LV2,		//126
										EGC_EFFECT_RYAN_WILD_HOWLING,		//127
										EGC_EFFECT_RYAN_NATURESHIELD,		//128
										EGC_EFFECT_RYAN_STONEWALL,			//129
										EGC_AMY4_MELOMODE_SPECIAL3_BUFF,   //130
										EGC_EFFECT_MURING_HEAL,             //131
										EGC_EFFECT_RAINBOW_EVENT,            //132
										EGC_PET_AGGRESIVE,                  //133
										EGC_EFFECT_FRIEND_RING,             //134
										EGC_EFFECT_JURIOR_CURSE_L,             //135
										EGC_EFFECT_JURIOR_CURSE_R,             //136

										EGC_EFFECT_COMMON_ATK_UP,			//137
										EGC_EFFECT_COMMON_DEF_UP,			//138
										EGC_EFFECT_COMMON_VIT_UP,			//139

										EGC_EFFECT_RONAN_DEF_SHIELD,				//140
										EGC_EFFECT_RONAN_SWORD_EYE_LV1,				//141
										EGC_EFFECT_RONAN_SWORD_EYE_LV2,				//142
										EGC_EFFECT_RONAN_SWORD_EYE_LV3,				//143
										EGC_EFFECT_RONAN_LIGHTNING_ENCHANT,   	//144
										EGC_EFFECT_RONAN_DARK_MIST_INVISI,   	//145
										EGC_EFFECT_RONAN_DARK_MIST_ATK,          //146
										EGC_EFFECT_INVISIBLE,                    //147  // 투명은 무조껀 이거를 쓰세요. 버프 아이콘이 필요하다거나 공격력 옵션이 필요하다거나 하면 2
										EGC_EFFECT_RONAN_FIRE_ENCHANT,   	//148
										EGC_EFFECT_RONAN_DARK_ENCHANT,   	//149
										EGC_EFFECT_RONAN_BLOOD_ENCHANT,   	//150
										EGC_EFFECT_RONAN_HOLY_LV3_SHIELD,   	//151

										EGC_EFFECT_RONAN_TOGETHER,					//152
										EGC_EFFECT_TOGETHER_2,							//153
										EGC_EFFECT_TOGETHER_3,							//154
										EGC_EFFECT_TOGETHER_4,							//155

										EGC_EFFECT_RONAN_SHIELD_COOLTIME,   			//=156
										EGC_EFFECT_RONAN_MANA_STOP,         			//=157
										EGC_EFFECT_JUNGSU_CONTROL,                      //=158
										EGC_EFFECT_STARSIGNBOARD_EVENT,                 //=159
										EGC_EFFECT_JIN4_COUNTER,                        //=160
										EGC_EFFECT_CHATTING_BUFF,                       //=161
										EGC_EFFECT_GHOST_HIDE,							//=162

										EGC_EFFECT_CIRCULATION_AMY2,	//				= 163,
										EGC_EFFECT_CIRCULATION_DUNGEON,	//			= 164,
										EGC_EFFECT_THIEF_PENDANT,		//			= 165,
										EGC_EFFECT_DARK_ASSASIN,		//				= 166,
										EGC_EFFECT_SIEG_TOGETHER,                      //=167
										EGC_EFFECT_GUILD_BUF,							//=168
										EGC_EFFECT_GACHASET_LOW_LEVEL1,                     //=169
										EGC_EFFECT_GACHASET_LOW_LEVEL2,                     //=170
										EGC_EFFECT_GACHASET_LOW_LEVEL3,                     //=171
										EGC_EFFECT_GACHASET_MIDDLE_LEVEL1,                     //=172
										EGC_EFFECT_GACHASET_MIDDLE_LEVEL2,                     //=173
										EGC_EFFECT_GACHASET_MIDDLE_LEVEL3,                     //=174
										EGC_EFFECT_GACHASET_HIGH_LEVEL1,                     //=175
										EGC_EFFECT_GACHASET_HIGH_LEVEL2,                     //=176
										EGC_EFFECT_GACHASET_HIGH_LEVEL3,                     //=177

										EGC_EFFECT_IP_BONUS,                //178
										EGC_EFFECT_LOI_FESTIVAL,                //179

										EGC_AMY_STIGMA,                          //180
										EGC_AMY_HOLY_DANCE,                  //181    
										EGC_AMY_FAN_SERVICE,                     //182
										EGC_AMY_ABRACADABRA_1 = 183,
										EGC_AMY_ABRACADABRA_2 = 184,
										EGC_AMY_ABRACADABRA_3 = 185,
										EGC_AMY_ABRACADABRA_4 = 186,
										EGC_AMY_ABRACADABRA_5 = 187,
										EGC_AMY_ABRACADABRA_6 = 188,
										EGC_AMY_ABRACADABRA_7 = 189,
										EGC_AMY_ABRACADABRA_8 = 190,
										EGC_AMY_ABRACADABRA_9 = 191,
										EGC_AMY_ABRACADABRA_10 = 192,
										EGC_AMY_ABRACADABRA_11 = 193,
										EGC_AMY_ABRACADABRA_12 = 194,
										EGC_AMY_ABRACADABRA_13 = 195,
										EGC_CANCELATION = 196,
										EGC_BUF_PRE_AMY_SKILLTREE = 197,
										EGC_EFFECT_GUILD_BUF_AP = 198,
										EGC_MARI1_WDW = 199,
										EGC_MARI1_MANASHIELD = 200,
										EGC_EFFECT_SETESH_PROTECT = 201,
										EGC_EFFECT_SCORPIS = 202,
										EGC_EFFECT_HATSHEPSUT_BUFF_1 = 203,
										EGC_EFFECT_HATSHEPSUT_BUFF_2 = 204,
										EGC_EFFECT_HATSHEPSUT_BUFF_3 = 205,
										EGC_EFFECT_POTION_BUFF_VALENTINE = 206,
										EGC_EFFECT_VALENTINE_COUPLE_BUFF = 207,
										EGC_EFFECT_MARI_1 = 208,
										EGC_EFFECT_OVERDRIVE = 209,
										EGC_EFFECT_TEN_TEN_DAY = 210,
										EGC_GWC = 211,
										EGC_NEW_YEAR = 212,
										EGC_PRE_PRIME_KINGHT = 213,
										EGC_PRE_PRIME_KINGHT2 = 214,
										EGC_PET_SEAMUS_BUFF = 215,
										EGC_EFFECT_POTION_US_2ND = 216,
										EGC_EFFECT_SERVER_EXP_UP = 217,
										EGC_SIEG4_FURY = 218,
										EGC_EFFECT_POTION_BUFF_PRIMENIGHT = 219,
										EGC_EFFECT_MUHAN_BONUSPOINT = 220, //보너스 포인트 무제한 버프
										EGC_EFFECT_MUHAN_LIFE = 221, //목숨 무제한 버프
										EGC_EFFECT_LIE_DAY_BUF = 222,
										EGC_EFFECT_WEEKEND_BONUS = 223, //주말 이벤트
										EGC_EFFECT_POTION_GREEN = 224,
										EGC_EFFECT_RAINBOW_EVENT_JACKPOT = 225,

										EGC_EFFECT_EVENT_BUF1 = 226,
										EGC_EFFECT_EVENT_BUF2 = 227,
										EGC_EFFECT_EVENT_BUF3 = 228,
										EGC_EFFECT_EVENT_BUF4 = 229,
										EGC_EFFECT_MARI3_BUILD_BUFF_TEAM = 230,
										EGC_EFFECT_MARI3_BUILD_BUFF_ENEMY = 231,
										EGC_EFFECT_MARI3_BUILD_LIMIT_TIME = 232,
										EGC_MARI_JSJ = 233,
										EGC_MARI3_MAGIC_BEAD_MP_RECOVERY = 234,
										EGC_EFFECT_EXP_UP = 235,
										EGC_EFFECT_GC_BLOG_BONUS = 236,

										EGC_SIEG1_SKILL_CASH_SPECIAL3_BUFF = 237,

										EGC_SIEG1_SKILL_SILENT_FURY = 238,
										EGC_SIEG1_SKILL_LIVING_FREE = 239,
										EGC_SIEG1_SKILL_LIVING_FREE_BONUS_TIME = 240,

										EGC_EFFECT_EVENT_BUF5 = 241,
										EGC_EFFECT_TALINS_CURSE = 242,
										EGC_ELESIS_HYPER_ARMOR = 243,
										EGC_ELESIS_PROVOKE = 244,
										EGC_ELESIS_PROVOKE_COOL = 245,
										EGC_EFFECT_MON_INFINITY_DEFENCE = 246,
										EGC_EFFECT_MON_NEMOPHILLA_FALL = 247,
										EGC_EFFECT_MON_NEMOPHILLA_MIND = 248,
										EGC_EFFECT_MON_NEMOPHILLA_MIND_SIGN = 249,

										EGC_EFFECT_HERO_EARRING_01 = 250,
										EGC_EFFECT_HERO_EARRING_SHIELD = 251,
										EGC_EFFECT_DIO_LIFEKEEP = 252,

										EGC_PETEFFECT_FIREARROW_DOTDAMAGE = 253,

										EGC_SKILL_JIN_KUMKANG = 254,
										EGC_SKILL_JIN_KYUHWA = 255,

										EGC_HELL_HOWLING_GHOST = 256,
										EGC_HELL_HOWLING_GHOST_SIGN = 257,
										EGC_HELL_VULCANUS_RAGE = 258,

										EGC_EFFECT_HERO_EARRING_02 = 259,
										EGC_EFFECT_HERO_EARRING_SHIELD_2 = 260,
										EGC_PLAYPARK_BONUS_BUFF = 266,
										EGC_EFFECT_WEAPONCHANGE = 267,
										EGC_EFFECT_SUPERSTAR_BUFF = 268,
										EGC_EFFECT_LEY_CHARGE_MODE_R = 269,
										EGC_EFFECT_LEY_CHARGE_MODE = 270,
										EGC_EFFECT_LEY_CHARGE_BALL_R = 271,
										EGC_EFFECT_LEY_CHARGE_BALL = 272,
										EGC_EFFECT_LEY_MP_REGEN_SPEED = 273,
										EGC_LEY_SKILL_ETHER = 274,
										EGC_LEY_SKILL_INSPIRE = 275,
										EGC_EFFECT_SELION_SP_UP = 276,
										EGC_EFFECT_CARNATION = 277,

										EGC_EFFECT_ZERO2_AMID_BUFF = 278,
										EGC_EFFECT_ZERO2_INCREASE_SS = 279,
										EGC_EFFECT_ZERO2_INCREASE_OS = 280,
										EGC_EFFECT_ZERO2_INCREASE_DS = 281,
										EGC_EFFECT_ZERO2_INCREASE_DS_LV1 = 282,
										EGC_EFFECT_ZERO2_INCREASE_DS_LV2 = 283,
										EGC_EFFECT_ZERO2_DS_REFLECTION = 284,
										EGC_EFFECT_ZERO2_INCREASE_OS_LV1 = 285,
										EGC_EFFECT_ZERO2_INCREASE_OS_LV2 = 286,
										EGC_EFFECT_ZERO2_INCREASE_SS_LV1 = 287,
										EGC_EFFECT_ZERO2_INCREASE_SS_LV2 = 288,

										EGC_EFFECT_EVENT_TWICE_ATTACK = 289,
										EGC_EFFECT_EVENT_TWICE_DEFENSE = 290,
										EGC_EFFECT_EVENT_TWICE_CRITICAL = 291,

										EGC_EFFECT_EVENT_SUPER_ARMOR = 292,
										EGC_EFFECT_EVENT_ARENA = 293,
										EGC_EFFECT_EVENT_ANTI = 294,
										EGC_EFFECT_EVENT_BERSERK = 295,

										EGC_EFFECT_LEY2_GAROUILLE = 296,
										EGC_EFFECT_LEY2_MERRY = 297,
										EGC_EFFECT_LEY2_BLIND = 298,
										EGC_EFFECT_LEY2_MERRY_SKILL = 299,

										//	길드 포션
										EGC_EFFECT_ATTACK_UP15 = 302,
										EGC_EFFECT_DEFEND_UP15 = 303,
										EGC_EFFECT_VITAL_UP15 = 304,

										EGC_EFFECT_EVENT_ATTACK_1000 = 305,

										EGC_EFFECT_POTION_JASON = 306,
										EGC_EFFECT_USER_BENEFIT_BONUS = 307,

										EGC_EFFECT_ATHENA_SILVER = 308,
										EGC_EFFECT_ATHENA_GOLD = 309,
										EGC_EFFECT_ATHENA_MASTER = 310,
										EGC_EFFECT_ATHENA_GRANDMASTER = 311,

										EGC_EFFECT_AGIT_FRUIT_EXP_LV1 = 312,
										EGC_EFFECT_AGIT_FRUIT_EXP_LV2 = 313,
										EGC_EFFECT_AGIT_FRUIT_EXP_LV3 = 314,
										EGC_EFFECT_AGIT_FRUIT_EXP_LV4 = 315,

										EGC_EFFECT_AGIT_FRUIT_GP_LV1 = 316,
										EGC_EFFECT_AGIT_FRUIT_GP_LV2 = 317,
										EGC_EFFECT_AGIT_FRUIT_GP_LV3 = 318,
										EGC_EFFECT_AGIT_FRUIT_GP_LV4 = 319,

										EGC_EFFECT_AGIT_FRUIT_ATK_LV1 = 320,
										EGC_EFFECT_AGIT_FRUIT_ATK_LV2 = 321,
										EGC_EFFECT_AGIT_FRUIT_ATK_LV3 = 322,
										EGC_EFFECT_AGIT_FRUIT_ATK_LV4 = 323,

										EGC_EFFECT_AGIT_FRUIT_DEF_LV1 = 324,
										EGC_EFFECT_AGIT_FRUIT_DEF_LV2 = 325,
										EGC_EFFECT_AGIT_FRUIT_DEF_LV3 = 326,
										EGC_EFFECT_AGIT_FRUIT_DEF_LV4 = 327,

										EGC_EFFECT_AGIT_FRUIT_HP_LV1 = 328,
										EGC_EFFECT_AGIT_FRUIT_HP_LV2 = 329,
										EGC_EFFECT_AGIT_FRUIT_HP_LV3 = 330,
										EGC_EFFECT_AGIT_FRUIT_HP_LV4 = 331,

										EGC_EFFECT_AGIT_FRUIT_ALL = 332,
										EGC_EFFECT_AGIT_FRUIT_EXP_GP = 333,

										EGC_EFFECT_ATTRIBUTE_SUPER_ARMOR = 334,
										EGC_EFFECT_ATTRIBUTE_RECORVERY_MP_UP = 335,
										EGC_EFFECT_ATTRIBUTE_ATTACK_UP = 336,
										EGC_EFFECT_ATTRIBUTE_SPEED_UP = 337,
										EGC_EFFECT_ATTRIBUTE_CRITICAL_DAMAGE_UP = 338,
										EGC_EFFECT_ATTRIBUTE_POTION_UP = 339,

										EGC_EFFECT_INVEN_BUFF_HEROES1 = 340,	// 참전 용사의 은빛 징표
										EGC_EFFECT_INVEN_BUFF_HEROES2 = 341,	// 참전 용사의 금빛 징표
										EGC_EFFECT_INVEN_BUFF_HEROES3 = 342,	// 참전 용사의 무지개 빛 증표


										EGC_EFFECT_MARI_EVNET_EARRING = 343,  //  마리 이벤트 귀걸이

										EGC_EFFECT_MARI4_REPAIR = 346,  //  마리 3차전직 리페어
										EGC_EFFECT_MARI4_REPAIR_R = 347,  //  마리 3차전직 리페어
										EGC_EFFECT_MARI4_DRAIN = 348,
										EGC_EFFECT_MARI4_BARRIER = 349,
										EGC_EFFECT_MARI4_CANCELER = 350,
										EGC_EFFECT_MARI4_LAUNCHER_WAIT = 351,

										EGC_FIRE_DOTDAMAGE_FOR_ZERO = 352,
										EGC_LEY1_SECRET_PASSAGE_LV1_DMG = 353,
										EGC_LEY1_SECRET_PASSAGE_LV2_DMG = 354,
										EGC_LEY1_SECRET_PASSAGE_LV3_DMG = 355,

										EGC_LEY2_THE_CENTER_OF_GRAVITY = 356,

										EGC_EFFECT_EVENT_CARNIVAL_ATK = 357,
										EGC_EFFECT_EVENT_CARNIVAL_DEF = 358,
										EGC_EFFECT_EVENT_CARNIVAL_MAXLIFE = 359,
										EGC_EFFECT_EVENT_CARNIVAL_CRI = 360,
										EGC_EFFECT_EVENT_CARNIVAL_LIFE = 361,
										EGC_EFFECT_EVENT_CARNIVAL_MP = 362,
										EGC_EFFECT_EVENT_CARNIVAL_REFLECTION = 363,
										EGC_EFFECT_EVENT_CARNIVAL_JOKER = 364,

										EGC_EFFECT_EVENT_CARNIVAL_BLIND_IN = 365,
										EGC_EFFECT_EVENT_CARNIVAL_BLIND_OUT = 366,
										EGC_EFFECT_EVENT_CARNIVAL_SWITCH_LEFT = 367,
										EGC_EFFECT_EVENT_CARNIVAL_SWITCH_RIGHT = 368,

										EGC_EFFECT_EVENT_CARNIVAL_LYONNESSE_DEF = 369,

										EGC_EFFECT_VITAL_UP15_EVENT = 370,
										EGC_EFFECT_CHAR_SKILL_SUPER_ARMOR = 371,

										EGC_EFFECT_AD_UP10 = 372,
										EGC_EFFECT_JUMP_UP10 = 373,

										EGC_EFFECT_CARNIVAL_LAS = 374,
										EGC_EFFECT_ATTACK_UP999 = 375,
										EGC_EFFECT_LUPUS1_NETHER_BLADE_BLEEDING = 376,
										EGC_EFFECT_PARTY_AP_HP_10_PER = 377,
										EGC_EFFECT_HELLMODE_FREE = 378,
										EGC_EFFECT_HERO_EARRING_03 = 379,
										EGC_EFFECT_HERO_EARRING_SHIELD_3 = 380,

										EGC_EFFECT_BLACK_DRAGON_DOT_DAMAGE = 381,
										EGC_EFFECT_BLACK_DRAGON_SP_UP = 382,
										EGC_EFFECT_ECLIPSE_IMAGE_BUFF = 383,

										EGC_EFFECT_SUB_ABILITY_BUFF_LV0 = 384,
										EGC_EFFECT_SUB_ABILITY_BUFF_LV1 = 385,
										EGC_EFFECT_SUB_ABILITY_BUFF_LV2 = 386,
										EGC_EFFECT_SUB_ABILITY_BUFF_LV3 = 387,
										EGC_EFFECT_SUB_ABILITY_BUFF_LV4 = 388,
										EGC_EFFECT_SUB_ABILITY_BUFF_LV5 = 389,

										EGC_EFFECT_RIN_CHARGING_EFF = 390,
										EGC_EFFECT_RIN_MON_DEFDOWN_EFF = 391,
										EGC_EFFECT_RIN_RAGE_MODE_BUFF = 392,
										EGC_EFFECT_DEFHP_10_PER = 393,

										EGC_DT_TRAIN_CAPTAIN_ATTACK_03_BUFF = 394,
										EGC_DT_TRAIN_CAPTAIN_ATTACK_06_BUFF = 395,
										EGC_EFFECT_EVENT_TRAIN_BLIND_IN = 396,
										EGC_EFFECT_EVENT_TRAIN_BLIND_OUT = 397,
										EGC_EFFECT_EVENT_TRAIN_BLIND_MONDEF = 398,
										EGC_EFFECT_EVENT_TRAIN_FIRE_DOTEDAMAGE = 399,
										EGC_EFFECT_EVENT_TRAIN_UNDER_REPAIR = 400,
										EGC_EFFECT_EVENT_TRAIN_UPPER_REPAIR = 401,

										EGC_EFFECT_EVENT_TRAIN_TRAFFIC_LIGHTS = 402,

										EGC_EFFECT_PET_JACK_GHOST = 403,

										EGC_EFFECT_EVENT_TRAIN_PRISONER_WEAK = 404,

										EGC_EFFECT_BOSS_FURY_BUFF = 405,
										EGC_EFFECT_EVENT_TRAIN_ATTACK03_FIRE_DOTEDAMAGE = 406,

										EGC_EFFECT_DEFHP_5_PER = 407,
										EGC_EFFECT_DEFHP_7_PER = 408,

										EGC_EFFECT_DIO3_POWER_MARBLE = 409,
										EGC_EFFECT_DIO3_POWER_MARBLE_UPGRADE_LV1 = 410,
										EGC_EFFECT_DIO3_POWER_MARBLE_UPGRADE_LV2 = 411,
										EGC_EFFECT_DIO3_POWER_MARBLE_UPGRADE_LV3 = 412,

										EGC_EFFECT_DIO3_TIME_MARBLE = 413,
										EGC_EFFECT_DIO3_TIME_MARBLE_UPGRADE_LV1 = 414,
										EGC_EFFECT_DIO3_TIME_MARBLE_UPGRADE_LV2 = 415,
										EGC_EFFECT_DIO3_TIME_MARBLE_UPGRADE_LV3 = 416,

										EGC_EFFECT_DIO3_SPELL_MARBLE = 417,
										EGC_EFFECT_DIO3_SPELL_MARBLE_UPGRADE_LV1 = 418,
										EGC_EFFECT_DIO3_SPELL_MARBLE_UPGRADE_LV2 = 419,
										EGC_EFFECT_DIO3_SPELL_MARBLE_UPGRADE_LV3 = 420,

										EGC_EFFECT_DIO3_TENATIOUS_HOLD = 421,
										EGC_EFFECT_DIO3_PROUD_SWING = 422,

										EGC_EFFECT_PET_RENCIA = 423,
										EGC_EFFECT_RENCIA_SHIELD = 424,

										EGC_EFFECT_ASTAROT_SP_UP = 425,
										EGC_EFFECT_CONFUSION2 = 426,

										EGC_EFFECT_JUMPUP = 427,

										EGC_EFFECT_MEDUSA_ATK = 428,

										EGC_EFFECT_ASIN_DEFFENCE_LV1 = 429,
										EGC_EFFECT_ASIN_DEFFENCE_LV2 = 430,
										EGC_EFFECT_ASIN_OFFENCE_LV1 = 431,
										EGC_EFFECT_ASIN_OFFENCE_LV2 = 432,
										EGC_EFFECT_ASIN_SPEED_LV1 = 433,
										EGC_EFFECT_ASIN_SPEED_LV2 = 434,
										EGC_EFFECT_ASIN_ADDTION_BUFF = 435,
										EGC_EFFECT_ASIN1_MP_RECOVERY_LV1 = 436,
										EGC_EFFECT_ASIN1_MP_RECOVERY_LV2 = 437,
										EGC_EFFECT_ASIN1_DEBUFF_MP_REGEN_STOP = 438,
										EGC_EFFECT_ASIN1_DEBUFF_SPEED_DOWN = 439,
										EGC_EFFECT_ASIN1_SPEICLA_USE_MP_DECREASE = 440,
										EGC_EFFECT_ASIN1_SPECIAL4_DOT_DAMAGE = 441,
										EGC_EFFECT_ASIN1_ULTIMATE_BUFF = 442,
										EGC_EFFECT_ASIN1_MP_RECOVERY_LV3 = 443,
										EGC_EFFECT_ASIN1_DEBUFF_DEF_DOWN = 444,
										EGC_EFFECT_ASIN1_DEBUFF_ICON = 445,

										EGC_EFFECT_ASIN1_HIDDEN_SKILL_ICON = 446,

										EGC_EFFECT_JUMP_UP_POTION = 447,
										EGC_EFFECT_CRI_UP_POTION = 448,
										EGC_EFFECT_SPEED_UP_POTION = 449,

										EGC_EFFECT_REVOLT_GETFOOD = 450,
										EGC_EFFECT_REVOLT_ATK_UP = 451,
										EGC_EFFECT_REVOLT_DEF_UP = 452,
										EGC_EFFECT_REVOLT_CRI_UP = 453,
										EGC_EFFECT_REVOLT_JUMP_UP = 454,
										EGC_EFFECT_REVOLT_MOVE_UP = 455,
										EGC_EFFECT_REVOLT_JUMP_DOWN = 456,
										EGC_EFFECT_REVOLT_MOVE_DOWN = 457,
										EGC_EFFECT_REVOLT_NOTUSE_SPECIAL = 458,
										EGC_EFFECT_REVOLT_WARNING_1 = 459,
										EGC_EFFECT_REVOLT_WARNING_2 = 460,
										EGC_EFFECT_REVOLT_SUMMON = 461,
										EGC_EFFECT_REVOLT_SMALLMAID = 462,
										EGC_EFFECT_REVOLT_THIEF = 463,
										EGC_EFFECT_CLEAR_DEBUFF = 464,
										EGC_EFFECT_MONSTER_SPEED_DOWN = 465,
										EGC_EFFECT_ELESIS_PET_DOT_DAMAGE = 466,
										EGC_EFFECT_STOP_ATK = 467,

										EGC_EFFECT_AGGRO_BUFF = 468,
										EGC_EFFECT_LIME_SPECIAL2_BUFF = 469,
										EGC_EFFECT_LIME_SPECIAL4_LEFEKEEP = 470,
										EGC_EFFECT_LIME_OFFENSE_AURA = 471,
										EGC_EFFECT_LIME_OFFENSE_AURA_ATK_UP = 472,
										EGC_EFFECT_LIME_OFFENSE_AURA_CONTINOUS_DMG = 473,
										EGC_EFFECT_LIME_OFFENSE_AURA_CRITICAL_UP = 474,
										EGC_EFFECT_LIME_DEFENSE_AURA = 475,
										EGC_EFFECT_LIME_DEFENSE_AURA_DEF_UP = 476,
										EGC_EFFECT_LIME_DEFENSE_AURA_HP_RECOVERY = 477,
										EGC_EFFECT_LIME_DEFENSE_AURA_SHEILD = 478,
										EGC_EFFECT_LIME_ASSITANT_AURA = 479,
										EGC_EFFECT_LIME_ASSITANT_AURA_MP_RECOVERY_UP = 480,
										EGC_EFFECT_LIME_ASSITANT_AURA_SP_MANA_DOWN = 481,
										EGC_EFFECT_LIME_ASSITANT_AURA_ALL_MANA_DOWN = 482,

										EGC_EFFECT_LIME_HYPER_ARMOR = 483,
										EGC_EFFECT_LIME_MP_RECOVERY_LV1 = 484,
										EGC_EFFECT_LIME_MP_RECOVERY_LV2 = 485,
										EGC_EFFECT_LIME_DECREASE_CATCHED_DAMAGE = 486,
										EGC_EFFECT_LIME_FATAL_SUPER_ARMOR = 487,
										EGC_EFFECT_LIME_OFFENSE_AURA_SIZEUP = 488,
										EGC_EFFECT_LIME_OFFENSE_AURA_ATK_UP_SIZEUP = 489,
										EGC_EFFECT_LIME_DEFENSE_AURA_SIZEUP = 490,
										EGC_EFFECT_LIME_DEFENSE_AURA_DEF_UP_SIZEUP = 491,
										EGC_EFFECT_LIME_ASSITANT_AURA_SIZEUP = 492,
										EGC_EFFECT_LIME_ASSITANT_AURA_MP_RECOVERY_UP_SIZEUP = 493,
										EGC_EFFECT_LIME_OFFENSE_AURA_MP_DOWN = 494,
										EGC_EFFECT_LIME_OFFENSE_AURA_MP_DOWN_SIZEUP = 495,
										EGC_EFFECT_LIME_DEFENSE_AURA_MP_DOWN = 496,
										EGC_EFFECT_LIME_DEFENSE_AURA_MP_DOWN_SIZEUP = 497,
										EGC_EFFECT_LIME_ASSITANT_AURA_EFFECT = 498,
										EGC_EFFECT_LIME_ASSITANT_AURA_EFFECT_SIZEUP = 499,

										// 4단 필살기
										EGC_EFFECT_ELESIS1_SPECIAL4_CHANGE_MODE = 500,

										EGC_EFFECT_AGIT_FRUIT_ATK_LV1_MATCH = 501,
										EGC_EFFECT_AGIT_FRUIT_ATK_LV2_MATCH = 502,
										EGC_EFFECT_AGIT_FRUIT_ATK_LV3_MATCH = 503,
										EGC_EFFECT_AGIT_FRUIT_ATK_LV4_MATCH = 504,

										EGC_EFFECT_AGIT_FRUIT_DEF_LV1_MATCH = 505,
										EGC_EFFECT_AGIT_FRUIT_DEF_LV2_MATCH = 506,
										EGC_EFFECT_AGIT_FRUIT_DEF_LV3_MATCH = 507,
										EGC_EFFECT_AGIT_FRUIT_DEF_LV4_MATCH = 508,

										EGC_EFFECT_AGIT_FRUIT_HP_LV1_MATCH = 509,
										EGC_EFFECT_AGIT_FRUIT_HP_LV2_MATCH = 510,
										EGC_EFFECT_AGIT_FRUIT_HP_LV3_MATCH = 511,
										EGC_EFFECT_AGIT_FRUIT_HP_LV4_MATCH = 512,

										EGC_EFFECT_AGIT_FRUIT_ALL_MATCH = 513,

										EGC_EFFECT_DIO_SPECIAL_CONTINOUS_DMG = 514,
										EGC_EFFECT_SIEG1_SPECIAL4_BUFF = 515,
										EGC_EFFECT_SIEG3_SPECIAL4_BUFF = 516,
										EGC_EFFECT_AMY1_SPECIAL4_BUFF = 517,
										EGC_EFFECT_AMY4_SPECIAL4_DEBUFF_1 = 518,
										EGC_EFFECT_AMY4_SPECIAL4_DEBUFF_2 = 519,
										EGC_EFFECT_AMY4_SPECIAL4_DEBUFF_3 = 520,
										EGC_EFFECT_AMY4_SPECIAL4_DEBUFF_4 = 521,
										EGC_EFFECT_MARI1_SPECIAL4_BUFF = 522,
										EGC_EFFECT_MARI2_SPECIAL4_BUFF = 523,

										EGC_EFFECT_DIO_SPECIAL_CONTINOUS_DMG_EVENT_MON = 524,

										EGC_EFFECT_RONAN3_SPECIAL4_TEMPEST = 525,
										EGC_EFFECT_JIN2_CONTINOUS_DMG = 526,
										EGC_EFFECT_MARI4_SPECIAL4_DOT_DAMAGE = 527,
										EGC_EFFECT_SIEG4_SPECIAL4_BUFF = 528,

										EGC_EFFECT_ATHENA_SILVER_MATCH = 529,
										EGC_EFFECT_ATHENA_GOLD_MATCH = 530,
										EGC_EFFECT_ATHENA_MASTER_MATCH = 531,
										EGC_EFFECT_ATHENA_GRANDMASTER_MATCH = 532,

										EGC_EFFECT_TITLE_TRAIN = 533,
										EGC_EFFECT_TITLE_TRAIN_MATCH = 534,
										EGC_EFFECT_REVOLT = 535,
										EGC_EFFECT_REVOLT_MATCH = 536,

										EGC_EFFECT_MARI4_SPECIAL4_DOT_DAMAGE_EVENT_MON = 537,
										EGC_EFFECT_ANGRY_SETESH_PROTECT = 538,
										EGC_EFFECT_BLITCHEN_SP_UP = 539,
										EGC_EFFECT_RONAN4_SPECIAL4_BUFF = 540,
										EGC_EFFECT_JIN1_SPECIAL4_BUFF = 541,
										EGC_EFFECT_JIN4_SPECIAL4_BUFF = 542,

										EGC_EFFECT_KARUELBORDER_SCOUT_ADDEFF = 543,
										EGC_EFFECT_KARUELBORDER_ASSASSIN_ADDEFF = 544,
										EGC_EFFECT_KARUELBORDER_ASSASSIN_SHADOW = 545,
										EGC_EFFECT_KARUELBORDER_ARCHER_ADDEFF = 546,
										EGC_EFFECT_KARUELBORDER_BUFFBOX = 547,
										EGC_EFFECT_KARUELBORDER_CAVALRY_ADDEFF = 548,
										EGC_EFFECT_KARUELBORDER_TRAP = 549,
										EGC_EFFECT_KARUEL_MON_PALACEGUARD_EFF = 550,
										EGC_EFFECT_KARUEL_GUARDANGEL_EFF = 551,
										EGC_EFFECT_KARUEL_GALADRIEL_FILECLEANNER = 552,
										EGC_EFFECT_KARUEL_GALADRIEL_FILEPASS = 553,
										EGC_EFFECT_KARUEL_TRAP_01 = 554,
										EGC_EFFECT_KARUEL_TRAP_02 = 555,
										EGC_EFFECT_KARUELBORDER_BUFFBOX_IMAGE = 556,
										EGC_EFFECT_KARUEL_GALADRIEL_POISON = 557,
										EGC_EFFECT_BAKUNAWA_SP_UP = 558,
										EGC_EFFECT_KARUELBORDER_DHAILA_PHASE3 = 559,
										EGC_EFFECT_KARUEL_TRAP_01_B = 560,
										EGC_EFFECT_KARUEL_TRAP_02_B = 561,
										EGC_EFFECT_KARUELBORDER_CAVALRY_GUARD = 562,
										EGC_EFFECT_KARUELBORDER_DAHLIA4_GUARD = 563,

										EGC_EFFECT_NIGHTMARKET_LANTERNMON_YELLOW_BUFF = 564,
										EGC_EFFECT_NIGHTMARKET_LANTERNMON_RED_BUFF1 = 565,
										EGC_EFFECT_NIGHTMARKET_LANTERNMON_BLACK_BUFF1 = 566,
										EGC_EFFECT_NIGHTMARKET_LANTERNMON_BLUE_BUFF1 = 567,
										EGC_EFFECT_NIGHTMARKET_LANTERNMON_GREEN_BUFF1 = 568,
										EGC_EFFECT_NIGHTMARKET_HAETAE_STONE = 569,
										EGC_EFFECT_NIGHTMARKET_HAETAE_STONE_DAMAGE = 570,
										EGC_EFFECT_NIGHTMARKET_HAETAE_BLEEDING = 571,
										EGC_EFFECT_NIGHTMARKET_WOMAN_ATTACK02 = 572,
										EGC_EFFECT_NIGHTMARKET_WOMAN_ATTACK04 = 573,
										EGC_EFFECT_NIGHTMARKET_NINETAILS_ATTACK08 = 574,
										EGC_EFFECT_NIGHTMARKET_NINETAILS_ATTACK08_START = 575,
										EGC_EFFECT_NIGHTMARKET_NINETAILS_ATTACK08_ATTACK = 576,
										EGC_EFFECT_NIGHTMARKET_NINETAILS_ATTACK09 = 577,
										EGC_EFFECT_NIGHTMARKET_NINETAILS_ATTACK08_PARTICLE = 578,
										EGC_EFFECT_NIGHTMARKET_DRUNKENFROG_ATTACK02 = 579,
										EGC_EFFECT_NIGHTMARKET_DRUNKENFROG_ATTACK06_NORMAL = 580,
										EGC_EFFECT_NIGHTMARKET_LANTERNMON_GREEN_BUFF2 = 581,
										EGC_EFFECT_NIGHTMARKET_LANTERNMON_GREEN_BUFF3 = 582,
										EGC_EFFECT_NIGHTMARKET_LANTERNMON_RED_BUFF2 = 583,
										EGC_EFFECT_NIGHTMARKET_LANTERNMON_RED_BUFF3 = 584,
										EGC_EFFECT_NIGHTMARKET_LANTERNMON_BLACK_BUFF2 = 585,
										EGC_EFFECT_NIGHTMARKET_LANTERNMON_BLUE_BUFF2 = 586,
										EGC_EFFECT_NIGHTMARKET_LANTERNMON_BLUE_BUFF3 = 587,
										EGC_EFFECT_NIGHTMARKET_WOMAN_ATTACK05 = 588,
										EGC_EFFECT_NIGHTMARKET_DRUNKENFROG_ATTACK06_HARD = 589,
										EGC_EFFECT_NIGHTMARKET_DRUNKENFROG_ATTACK06_HELL = 590,
										EGC_EFFECT_NIGHTMARKET_CENTER_DIE = 591,
										EGC_EFFECT_NIGHTMARKET_FIREDOTDAMAGE = 592,
										EGC_EFFECT_NIGHTMARKET_MISS = 593,

										EGC_EFFECT_NIGHTMARKET_NINETAILS_ATTACK09_BACK = 594,

										EGC_EFFECT_DIO4_HAND_TYPE2_DMG_BUFF = 595,
										EGC_EFFECT_DIO4_COOLSPIRAL_SPEED_UP = 596,
										EGC_EFFECT_DIO4_BLACKSPACE_SHIELD = 597,
										EGC_EFFECT_DIO4_HAND_MANA_ATK_LV1 = 598,
										EGC_EFFECT_DIO4_HAND_MANA_ATK_LV2 = 599,
										EGC_EFFECT_DIO4_LIFE_KEEP_MISSILE_DMG_RESIST = 600,
										EGC_EFFECT_DIO4_DEVIL_PASSIVE_CRITICAL_RATIO_UP = 601,
										EGC_EFFECT_DIO4_WEAPON_PASSIVE_RECOVERY_HP = 602,
										EGC_EFFECT_DIO4_DEVIL_PASSIVE_LV3 = 603,
										EGC_EFFECT_DIO4_BLACKSPACE_SHIELD_TYPE2 = 604,

										EGC_EFFECT_BERKASLAIR_BALLISTA = 605,
										EGC_EFFECT_BERKASLAIR_CATAPULT = 606,
										EGC_EFFECT_BERKASLAIR_DRAGOON_DEF_UP = 607,
										EGC_EFFECT_BERKASLAIR_GUIDEBALLISTA = 608,
										EGC_EFFECT_BERKASLAIR_GUIDECATAPULT = 609,
										EGC_EFFECT_BERKASLAIR_GUIDEBERRIER = 610,
										EGC_EFFECT_BERKASLAIR_GUIDEREPRESS = 611,

										EGC_EFFECT_BERKASLAIR_REPRESS = 612,
										EGC_EFFECT_BERKASLAIR_BARRIER_SHOW = 613,
										EGC_EFFECT_BERKASLAIR_BARRIER_MONSTER = 614,
										EGC_EFFECT_BERKASLAIR_BARRIER_PLAYER = 615,
										EGC_EFFECT_BERKASLAIR_BARRIER_STARTTIME = 616,
										EGC_EFFECT_BERKASLAIR_BALLISTA_CRASH = 617,
										EGC_EFFECT_BERKASLAIR_CATAPULT_CRASH = 618,
										EGC_EFFECT_BERKASLAIR_REPRESS_SHOW = 619,
										EGC_EFFECT_BERKASLAIR_ALTKEY_PARTICLE = 620,
										EGC_EFFECT_BERKASLAIR_BERKAS_ATTACK06_PARTICLE = 621,
										EGC_EFFECT_BERKASLAIR_BERKAS_ATTACK03_PARTICLE = 622,
										EGC_EFFECT_BERKASLAIR_BERKAS_ATTACK03_PARTICLE_R = 623,
										EGC_EFFECT_BERKASLAIR_OBJECT_SPEED_UP = 624,
										EGC_EFFECT_BERKASLAIR_OBJECT_HP_RECOVERY = 625,

										EGC_ELESIS_DEFENCE_BUFF = 626,
										EGC_EFFECT_COMMON_SUPER_ARMOR_BUFF = 627,
										EGC_JIN1_ABUNDANTSTEP_HYPER_BUFF = 628,
										EGC_ZERO_INCREASE_DEFFENCE_BUFF = 629,
										EGC_EFFECT_RONAN_HOLY_LV3_SUPER_SHIELD = 630,

										EGC_EFFECT_RIN2_GODDESS_SPECIAL2_SHIELD = 631,
										EGC_EFFECT_RIN2_GODDESS_UNIQUE_TEAM_BUFF = 632,
										EGC_EFFECT_RIN2_GODDESS_CHARGING_SKILL_LV1 = 633,
										EGC_EFFECT_RIN2_GODDESS_CHARGING_SKILL_LV2 = 634,
										EGC_EFFECT_RIN2_GODDESS_CHARGING_SKILL_LV3 = 635,
										EGC_EFFECT_RIN2_GODDESS_UNIQUE_SKILL_SHIELD = 636,
										EGC_EFFECT_RIN2_GODDESS_UNLIMITED_SPELL = 637,
										EGC_EFFECT_RIN2_EVIL_SURVIVAL_SKILL_BUFF = 638,
										EGC_EFFECT_RIN2_GODDESS_CHARGING_SKILL_LV1_L = 639,
										EGC_EFFECT_RIN2_GODDESS_CHARGING_SKILL_LV2_L = 640,
										EGC_EFFECT_RIN2_GODDESS_CHARGING_SKILL_LV3_L = 641,
										EGC_EFFECT_RIN3_EVIL_CHARGING_EFFECT_DECO = 642,
										EGC_EFFECT_RIN3_EVIL_CHARGING_EFFECT_LV1 = 643,
										EGC_EFFECT_RIN3_EVIL_CHARGING_EFFECT_LV2 = 644,
										EGC_EFFECT_RIN3_EVIL_CHARGING_EFFECT_LV3 = 645,
										EGC_EFFECT_RIN3_EVIL_CHARGING_INCREASE_ATK_LV1 = 646,
										EGC_EFFECT_RIN3_EVIL_CHARGING_INCREASE_ATK_LV2 = 647,
										EGC_EFFECT_RIN3_EVIL_CHARGING_INCREASE_ATK_LV3 = 648,
										EGC_EFFECT_RIN3_EVIL_CHARGING_TELEPORT_COOLTIME = 649,
										EGC_EFFECT_RIN3_EVIL_STRONG_WEAPON_DARK_CURSE = 650,
										EGC_EFFECT_RIN3_EVIL_STRONG_WEAPON_MONSTER_DMG = 651,
										EGC_EFFECT_RIN3_EVIL_STRONG_SPECIAL3_AURA = 652,

										EGC_EFFECT_RIN_EVIL_MARBLE = 653,
										EGC_EFFECT_RIN2_EVIL_BASE_SPECIAL1_HP_STOP = 654,
										EGC_EFFECT_RIN3_GODDESS_UNIQUE_SKILL_HP_STOP = 655,
										EGC_EFFECT_RIN4_EVIL_SPECIAL2_DARK = 656,
										EGC_EFFECT_RIN4_FORM_GODDESS_BUFF = 657,
										EGC_EFFECT_RIN4_FORM_EVIL_BUFF = 658,
										EGC_EFFECT_RIN4_FORM_PASSIVE1_TYPE_A_BUFF = 659,
										EGC_EFFECT_RIN4_FORM_PASSIVE3_TYPE_B_BUFF = 660,
										EGC_EFFECT_RIN4_FORM_EVIL_SHOCK_SPEED_UP = 661,
										EGC_EFFECT_RIN4_FORM_DEFFENCE_REFLECT_DAMAGE = 662,
										EGC_EFFECT_RIN4_FORM_GODDESS_DECO_PARTICLE = 663,
										EGC_EFFECT_RIN4_FORM_EVIL_DECO_PARTICLE = 664,
										EGC_EFFECT_RIN4_CHANGE_FORM_COOL_TIME = 665,
										EGC_EFFECT_RIN4_FORM_DEFFENCE_COOLTIME = 666,

										EGC_EFFECT_DIO_LIFEKEEP_LIMIT_BUFF = 667,

										EGC_EFFECT_RIN4_MP_RECOVERY_LV1 = 668,
										EGC_EFFECT_RIN4_MP_RECOVERY_LV2 = 669,
										EGC_EFFECT_RIN4_CRITICALUP_LV1 = 670,
										EGC_EFFECT_RIN4_CRITICALUP_LV2 = 671,
										EGC_EFFECT_RIN4_NO_SPECIAL_BUFF = 672,
										EGC_EFFECT_ONLY_ONE_MOTION_HYPER_ARMOR_BUFF = 673,
										EGC_EFFECT_ONLY_ONE_MOTION_SUPER_BUFF = 674,

										EGC_EFFECT_EVENT_ZERO_SUPER_ARMOR = 675,

										EGC_EFFECT_ZERO_DOMINATION_OF_GRANDARK = 676,
										EGC_EFFECT_ZERO_DS_REFLECTION_REINFORCEMENT = 677,
										EGC_EFFECT_ZERO_SS_ATK_UP_BUFF = 678,
										EGC_EFFECT_ZERO_DS_RESIST_CATCH_BUFF = 679,
										EGC_EFFECT_ZERO_UNIQUE_CARTOON = 680,

										EGC_EFFECT_DESERT_KUFU_BLOOD = 681,
										EGC_EFFECT_DESERT_KUFU_HIDE = 682,
										EGC_EFFECT_DESERT_KUFU_SHIELD = 683,
										EGC_EFFECT_DESERT_KUFU_SHIELD_TIMEMER = 684,
										EGC_EFFECT_DESERT_KUFU_SUMMON_TIMEMER = 685,
										EGC_EFFECT_DESERT_EMBARK_CHARACTER = 686,
										EGC_EFFECT_DESERT_KUFU_SHIELD_PARTICLE1 = 687,
										EGC_EFFECT_DESERT_KUFU_SHIELD_PARTICLE2 = 688,

										EGC_EFFECT_ZERO4_FRONT_TELEPORT_COOLTIME = 689,
										EGC_ZERO4_DS_DEFFENCE_UP = 690,
										EGC_ZERO4_OS_CRITICAL_UP = 691,
										EGC_ZERO4_STANCE_CATCH_RESIST = 692,
										EGC_ZERO4_FATAL_MP_RECOVERY_UP = 693,

										EGC_PET_PLUBELL_SUPER_ARMOR = 694,

										EGC_EFFECT_PET_CHOUCRING = 695,
										EGC_EFFECT_CHOUCRING_SHIELD = 696,

										EGC_EFFECT_BUFF_DONATION_BUFF_1 = 697,
										EGC_EFFECT_BUFF_DONATION_BUFF_2 = 698,
										EGC_EFFECT_BUFF_DONATION_BUFF_3 = 699,
										EGC_EFFECT_BUFF_DONATION_BUFF_4 = 700,
										EGC_EFFECT_BUFF_DONATION_BUFF_5 = 701,

										EGC_EFFECT_RACANYON_SCORPION_BLOOD = 702,
										EGC_EFFECT_RACANYON_HOODCROW_SHIELD = 703,
										EGC_EFFECT_RACANYON_CHAR_WIND = 704,
										EGC_EFFECT_RACANYON_KARTE_ATTACK06 = 705,
										EGC_EFFECT_RACANYON_KARTE_SHIELD = 706,
										EGC_EFFECT_RACANYON_KARTE_SHIELD_PARTICLE1 = 707,
										EGC_EFFECT_RACANYON_KARTE_SHIELD_PARTICLE2 = 708,
										EGC_EFFECT_RACANYON_KARTE_PHASE1 = 709,
										EGC_EFFECT_RACANYON_KARTE_PHASE2 = 710,
										EGC_EFFECT_RACANYON_CHAR_BIGWIND = 711,

										EGC_EFFECT_LEY3_SUMMON_HAUNT = 712,
										EGC_EFFECT_LEY3_HAUNT_CURSE01_MON = 713,
										EGC_EFFECT_LEY3_HAUNT_CURSE02 = 714,
										EGC_EFFECT_LEY3_HAUNT_CURSE02_MON = 715,
										EGC_EFFECT_LEY3_HAUNT_CURSE03 = 716,
										EGC_EFFECT_LEY3_HAUNT_CURSE03_MON = 717,
										EGC_EFFECT_LEY3_HAUNT_CURSE04_LV1 = 718,
										EGC_EFFECT_LEY3_HAUNT_CURSE04_LV2 = 719,
										EGC_EFFECT_LEY3_COMMAND_SUMMON_OFF = 720,
										EGC_EFFECT_LEY3_COMMAND_SUMMON_UP = 721,
										EGC_EFFECT_LEY3_COMMAND_SUMMON_LEFT = 722,
										EGC_EFFECT_LEY3_COMMAND_SUMMON_RIGHT = 723,
										EGC_EFFECT_LEY3_MERY_BITE_SPEED_DOWN = 724,
										EGC_EFFECT_LEY3_MERY_BITE_CONTINOUS_DMG = 725,
										EGC_EFFECT_LEY3_SUMMON_HAUNT_HP_UP_LV1 = 726,
										EGC_EFFECT_LEY3_SUMMON_HAUNT_HP_UP_LV2 = 727,
										EGC_EFFECT_LEY3_GAROUILLE_BREATH_DARK = 728,

										EGC_EFFECT_LEY4_SUMMON_JEEVES = 729,

										EGC_EFFECT_PYRAMID_ANUBIS_SPEED_DOWN = 730,
										EGC_EFFECT_PYRAMID_BARAKUP_STOP = 731,
										EGC_EFFECT_PYRAMID_BARAKUP_SHIELD = 732,
										EGC_EFFECT_PYRAMID_SIGNALFIRE_SPACEBAR = 733,
										EGC_EFFECT_PYRAMID_SIGNALFIRE_SHIELD = 734,
										EGC_EFFECT_PYRAMID_SIGNALFIRE_SHIELD2 = 735,
										EGC_EFFECT_PYRAMID_SIGNALFIRE_ON = 736,
										EGC_EFFECT_OSIRISRELIC_EMBARK_CHARACTER = 737,

										EGC_EFFECT_PYRAMID_SIGNALFIRE_BLIND = 738,

										EGC_EFFECT_KARUEL_GALADRIEL_MONSTER_FILECLEANNER = 739,

										EGC_EFFECT_LEY4_SUMMON_JEEVES_SKILL = 740,
										EGC_EFFECT_LEY3_COMMAND_SUMMON_DOWN = 741,
										EGC_EFFECT_LEY4_SUMMON_GAROUILLE_PLUS_BUFF = 742,
										EGC_EFFECT_LEY4_SUMMON_MERRY_PLUS_BUFF = 743,
										EGC_EFFECT_LEY4_SUMMON_HAUNT_PLUS_BUFF = 744,
										EGC_EFFECT_LEY4_SUMMON_JEEVES_PLUS_BUFF = 745,
										EGC_EFFECT_LEY4_UNIQUE_DASH = 746,
										EGC_EFFECT_LEY4_UNIQUE_DASH_L = 747,

										EGC_EFFECT_LEY3_SUMMON_HAUNT_FOR_DUNGEON = 748,
										EGC_EFFECT_LEY3_SUMMON_HAUNT_HP_UP_LV1_FOR_DUNGEON = 749,
										EGC_EFFECT_LEY3_SUMMON_HAUNT_HP_UP_LV2_FOR_DUNGEON = 750,
										EGC_EFFECT_LEY2_MERRY_FOR_DUNGEON = 751,
										EGC_EFFECT_LEY2_MERRY_HP_LV1_FOR_DUNGEON = 752,
										EGC_EFFECT_LEY2_MERRY_HP_LV2_FOR_DUNGEON = 753,
										EGC_EFFECT_LEY4_SUMMON_JEEVES_FOR_DUNGEON = 754,
										EGC_EFFECT_LEY2_MERRY_HP_LV1 = 755,
										EGC_EFFECT_LEY2_MERRY_HP_LV2 = 756,

										EGC_EFFECT_COWNAT_HIGHLANDER_STOP = 757,
										EGC_EFFECT_COWNAT_ASTAROT_SHIELD = 758,
										EGC_EFFECT_COWNAT_CAXIAS_SHIELD = 759,
										EGC_COWNAT_DRAMA_SIEG_FURY = 760,

										EGC_EFFECT_ASIN2_UNIQUE_SKILL1 = 761,
										EGC_EFFECT_ASIN2_UNIQUE_SKILL1_UPGRADE = 762,
										EGC_EFFECT_ASIN2_UNIQUE_SKILL2_FOR_PLAYER = 763,
										EGC_EFFECT_ASIN2_UNIQUE_SKILL2_FOR_MONSTER = 764,

										EGC_EFFECT_COMMON_SUPER_ARMOR_NO_EDGE_COLOR = 765,

										EGC_EFFECT_LIME2_SPECIAL1_PLAYER_DEBUFF = 766,
										EGC_EFFECT_LIME2_SPECIAL1_MON_DEBUFF = 767,

										EGC_EFFECT_LIME_COMMAND_AURA_OFF = 768,
										EGC_EFFECT_LIME_COMMAND_AURA_UP = 769,
										EGC_EFFECT_LIME_COMMAND_AURA_LEFT = 770,
										EGC_EFFECT_LIME_COMMAND_AURA_RIGHT = 771,
										EGC_EFFECT_LIME2_SELF_AURA_OFFENSE = 772,
										EGC_EFFECT_LIME2_SELF_AURA_DEFFENCE = 773,
										EGC_EFFECT_LIME2_SELF_AURA_MOVE = 774,
										EGC_EFFECT_LIME2_SELF_AURA_DECREASE_MANA_RECOVERY = 775,
										EGC_EFFECT_LIME2_DEFFENCE_COOL_TIME = 776,
										EGC_EFFECT_LIME2_MANASHIELD = 777,
										EGC_EFFECT_LIME2_BERSERKER_LV1 = 778,
										EGC_EFFECT_LIME2_BERSERKER_LV2 = 779,
										EGC_EFFECT_LIME2_BERSERKER_LV3 = 780,
										EGC_EFFECT_LIME2_DEFFENCE_PARTICLE = 781,
										EGC_EFFECT_LIME2_DEFFENCE_PARTICLE_L = 782,
										EGC_EFFECT_NO_CRASH_CHECK_BUFF = 783,
										EGC_EFFECT_LIME2_DISABLE_SPECIAL = 784,

										EGC_COMBAT_GAME_ITEM_COOL = 785,

										EGC_EFFECT_PET_KOG_B_CHAR_LOCK = 786,
										EGC_EFFECT_PET_KOG_B_MON_LOCK = 787,

										EGC_EFFECT_LIME_ASSITANT_AURA_ALL_MANA_DOWN_COOLTIME = 788,

										// 아지트 버프 개선
										EGC_AGIT_NEW_BUFF_DUNGEON_LV1 = 789,
										EGC_AGIT_NEW_BUFF_DUNGEON_LV2 = 790,
										EGC_AGIT_NEW_BUFF_DUNGEON_LV3 = 791,
										EGC_AGIT_NEW_BUFF_DUNGEON_LV4 = 792,
										EGC_AGIT_NEW_BUFF_DUNGEON_LV5 = 793,
										EGC_AGIT_NEW_BUFF_MATCH_LV1 = 794,
										EGC_AGIT_NEW_BUFF_MATCH_LV2 = 795,
										EGC_AGIT_NEW_BUFF_MATCH_LV3 = 796,
										EGC_AGIT_NEW_BUFF_MATCH_LV4 = 797,
										EGC_AGIT_NEW_BUFF_MATCH_LV5 = 798,

										EGC_EFFECT_EDEL1_X_COMMAND_SKILL_COOLTIME = 799,
										EGC_EFFECT_EDEL1_UNIQUE_SKILL1_STEAL_WEAPON = 800,
										EGC_EFFECT_EDEL1_UNIQUE_SKILL1_MON_DEBUFF = 801,
										EGC_EFFECT_EDEL1_UNIQUE_SKILL2_PLAYER_DEBUFF = 802,
										EGC_EFFECT_EDEL1_UNIQUE_SKILL2_MON_DEBUFF = 803,
										EGC_EFFECT_EDEL1_UNIQUE_SKILL3_PLAYER_DEBUFF = 804,
										EGC_EFFECT_EDEL1_UNIQUE_SKILL3_MON_DEBUFF = 805,
										EGC_EFFECT_EDEL1_SPEED_UP_LV1 = 806,
										EGC_EFFECT_EDEL1_SPEED_UP_LV2 = 807,
										EGC_EFFECT_EDEL1_SPEED_UP_LV3 = 808,
										EGC_EFFECT_EDEL1_SPEED_UP_LV4 = 809,
										EGC_EFFECT_EDEL1_MP_RECOVERY_LV1 = 810,
										EGC_EFFECT_EDEL1_MP_RECOVERY_LV2 = 811,
										EGC_EFFECT_EDEL1_MP_RECOVERY_LV3 = 812,
										EGC_EFFECT_EDEL1_MP_RECOVERY_LV4 = 813,
										EGC_EFFECT_EDEL1_BERSERKER_HYPER_ARMOR = 814,

										EGC_EFFECT_RONAN3_DARK_ENCHANT = 815,
										EGC_EFFECT_RONAN3_LIGHTNING_ENCHANT = 816,
										EGC_EFFECT_RONAN3_FIRE_ENCHANT = 817,
										EGC_EFFECT_RONAN3_BLOOD_ENCHANT = 818,
										EGC_EFFECT_RONAN2_WHITE_HOLY_SHIELD = 819,
										EGC_EFFECT_ARME_COMMON_SHIELD = 820,

										EGC_EFFECT_MAP_TRAP_SPIDERWEB = 821,
										EGC_EFFECT_ACTION_SUBJECT_HP_UP = 822,
										EGC_EFFECT_MON_CHAR_LOCK = 823,
										EGC_EFFECT_MON_ARACHNE_STOP = 824,
										EGC_EFFECT_MON_ARACHNE_KEYLOCK = 825,
										EGC_EFFECT_MON_GREYARACHNIA_BLOOD = 826,
										EGC_EFFECT_MON_GREYARACHNIA_STOP = 827,

										EGC_EFFECT_ACTION_SUBJECT_ATTACK_UP = 828,
										EGC_EFFECT_ACTION_SUBJECT_DEFFNSE_UP = 829,
										EGC_EFFECT_ACTION_SUBJECT_CRITICAL_UP = 830,

										EGC_EFFECT_TUTORIAL_ATTRIBUTE_UP = 831,
										EGC_EFFECT_MON_ARACHNE_BLOOD = 832,

										EGC_EFFECT_RONAN3_COMMON_SHIELD = 833,
										EGC_EFFECT_COMMON_IGNORE_CRASH = 834,

										EGC_EFFECT_DARK_NIGHTMARE_DEBUFF = 835,

										EGC_EFFECT_BEIGAS_BARRIER = 836,
										EGC_EFFECT_BEIGAS_SPECIAL_TYPE5_LV3_DEBUFF = 837,
										EGC_EFFECT_BEIGAS_INCREASE_ATK_GS_1_2 = 838,
										EGC_EFFECT_BEIGAS_MP_RECOVERY_GS_1_3 = 839,
										EGC_EFFECT_BEIGAS_MP_RECOVERY_GS_2_3 = 840,

										EGC_EFFECT_GRANDROCK_TROKA_FIREDOTDAMAGE = 841,
										EGC_EFFECT_GROUNDOFDESPAIR_PATROLLER_STOP = 842,
										EGC_EFFECT_HUNTINGFIELD_LOKLOK_BOOM_DOT_DAMAGE = 843,

										EGC_EFFECT_EDEL2_SPECIAL_B_LIGHTNING = 844,
										EGC_EFFECT_EDEL2_SPECIAL_B_FIRE = 845,
										EGC_EFFECT_EDEL2_SPECIAL_B_CURSE = 846,
										EGC_EFFECT_EDEL2_SPECIAL_B_DARK = 847,
										EGC_EFFECT_EDEL2_SPECIAL_C_TELEPORT = 848,
										EGC_EFFECT_EDEL2_SPECIAL_C_MP_RECOVERY = 849,
										EGC_EFFECT_EDEL2_SPECIAL_C_DECREASE_COOLTIME = 850,
										EGC_EFFECT_EDEL2_SPECIAL_C_REFLECT_DMG = 851,
										EGC_EFFECT_EDEL2_PASSIVE_INCREASE_CRITICAL_LV1 = 852,
										EGC_EFFECT_EDEL2_PASSIVE_INCREASE_CRITICAL_LV2 = 853,
										EGC_EFFECT_EDEL2_PASSIVE_INCREASE_CRITICAL_LV3 = 854,
										EGC_EFFECT_EDEL2_PASSIVE_INCREASE_CRITICAL_LV4 = 855,
										EGC_EFFECT_EDEL2_PASSIVE_INCREASE_CRITICAL_LV5 = 856,

										EGC_EFFECT_FULLMOON_EVENT_JACKPOT = 857,
										EGC_EFFECT_FULLMOON_EVENT = 858,
										EGC_EFFECT_PET_DOKKAEBIE = 859,
										EGC_EFFECT_DOKKAEBIE_SHIELD = 860,
										EGC_EFFECT_RIN3_HYPER_ARMOR = 861,
										EGC_EFFECT_VITALITY_BUFF = 862,
										EGC_EFFECT_CONFUSION_REINFORCEMENT = 863,

										EGC_EFFECT_SAVING_EMPTY_STATE = 864,

										EGC_EFFECT_PET_LEONA_FULL = 865,
										EGC_EFFECT_PET_LEONA_WEAPON = 866,

										EGC_EFFECT_EDEL_TOGETHER = 867,
										EGC_EFFECT_EXTINCTION_KAZEAZE_PHASE1_DARK_SPACE = 868,
										EGC_EFFECT_RONAN_MAGICSWORD_MODE = 869,
										EGC_EFFECT_RONAN_MAGICSWORD_MODE_UNEQUIP = 870,

										EGC_EFFECT_NUM,
};