#include "CCPch.h"
#include "UIRenderer.h"
#include "UI.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "SoundManager.h"

void UI::Awake()
{
	m_Scene = SceneManager::GetInstance();
	//위에서 씬매니저의 인스턴스도 가져왔지?


	SetUIList(m_pGameObject->GetName());

}

void UI::Start()
{
	

}

void UI::Update()
{

}

void UI::SetUIList(wstring name)
{
	for (auto& _UI : SceneManager::GetInstance()->m_CurScene->m_GameObjectList)
	{
		if (_UI->GetComponent<UIRenderer>())
		{
			if (_UI->GetComponent<UIRenderer>()->GetUIData()->UIType == name)
			{
				m_UIList.push_back(_UI->GetComponent<UIRenderer>());
			}
		}
	}
}

void UI::SwitchUI()
{
	for (auto& _UI : m_UIList)
	{
		_UI->GetUIData()->isDraw = !m_IsOpen;
	}
	m_IsOpen = !m_IsOpen;
}

bool UI::IsOpen()
{
	return m_IsOpen;
}
void UI::OpenUI()
{
	SceneManager::GetInstance()->m_CurScene->m_HimeEngine->SetFireEffect(false);
	for (auto& _UI : m_UIList)
	{
		_UI->GetUIData()->isDraw = true;
	}
	m_IsOpen = true;
}

void UI::CloseUI()
{
	SceneManager::GetInstance()->m_CurScene->m_HimeEngine->SetFireEffect(true);
	for (auto& _UI : m_UIList)
	{
		SoundManager::GetInstance()->BgmSoundControl(0.5f);
		_UI->GetUIData()->isDraw = false;
	}
	m_IsOpen = false;
}
