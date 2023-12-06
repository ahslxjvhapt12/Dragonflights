#include "pch.h"
#include "Fence.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Texture.h"

Fence::Fence()
	: m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Player", L"Texture\\YB.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(32.f, 32.f));
}

Fence::~Fence()
{

}

void Fence::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	for (int i = 0; i < 5; i++)
	{
		BitBlt(_dc, (int)(vPos.x - vScale.x / 2) + i * 32, (int)(vPos.y - vScale.y / 2) + i * 32, Width, Height, m_pTex->GetDC(), 0, 0, SRCCOPY);

	}

	Component_Render(_dc);
}