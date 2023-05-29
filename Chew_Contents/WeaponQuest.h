#pragma once
#include "QuestDataTable.h"
#include <Component.h>


class GameObject;
struct TextData;
class SceneManager;
class UIRenderer;


//Weapon거임 
struct CompareData
{
	wstring m_WeaponCategory;
	wstring m_WeaponType;
	float m_Hardness;
	wstring m_EnchantType;
	int m_EnchantSuccess;
	wstring m_Handle;
	int m_Purity;
	int m_Sharpness;
	int m_Weight;
	wstring m_Mat1;
	wstring m_Mat2;
};



class WeaponQuest :
	public Component
{
public:
	void Awake();
	void Start();
	void Update();

	//새로운 퀘스트 설정
	void SetNewQuest();

	//제작 완료시 평가 UI 출력
	void OpenReviewUI();
	void CloseReviewUI();

	int GetCurrentSequence() const { return m_CurrentSequence; }
	void SetCurrentSequence(int val) { m_CurrentSequence = val; }
	
	//미니게임에서 진행된 결과 저장
	void SetDataW(wstring amount, wstring which, int sequence);
	void SetDataI(int amount, wstring which);
	shared_ptr<CompareData> GetData() { return m_WeaponData; };

	//무기 정확히 만들었는지 판정
	bool IsQuestSuccess();
	bool IsWeaponSuccess();
	bool IsMaterialSuccess();

	bool IsCurrentSequence(wstring name);

	wstring GetQuestID();
	wstring CalculateSatistification();

	//디버그
	void UpdateDebugInfo();
	void SetDebugInfo();
private:
	vector<shared_ptr<UIRenderer>> m_UIList;
	shared_ptr<QuestData> m_QuestInfo;
	shared_ptr<CompareData> m_WeaponData;
	shared_ptr<TextData> m_DebugInfo;
	shared_ptr<TextData> m_DebugInfo3;
	shared_ptr<SceneManager> m_Scene;
	int m_CurrentSequence = 9;


};

