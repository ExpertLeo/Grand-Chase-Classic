class cResource
{
public:
	cResource();

	void ReadBoolean(char* szSection, char* szKey, bool &Var);
	void ReadFloat(char* szSection, char* szKey, float &Var);
	void ReadInteger(char* szSection, char* szKey, int &Var);
	void ReadByte(char* szSection, char* szKey, byte &Var);
	void ReadIntegerA(char* szSection, char* szKey, int &Var);
	void ReadString(char* szSection, char* szKey, char* Text);

	void WriteInteger(char* szSection, char* szKey, int iValue);
	void WriteBoolean(char* szSection, char* szKey, bool bolValue);
	void WriteFloat(char* szSection, char* szKey, float fltValue);
	void WriteString(char* szSection, char* szKey, char* szValue);
	void WriteIntegerA(char* szSection, char* szKey, int iValue);

	void Save();
	void Load();
	void AutoLoad();

	void SaveLoginData();
	void LoadLoginData();


	char Loc[200];
};

extern cResource* Resource;