#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
	: m_fSpeed(0.f)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));

	// �׵���ķ� ����� �ʱ�ȭ �ϴ� �Լ�
	D3DXMatrixIdentity(&m_tInfo.matWorld);

}

CObj::~CObj()
{
}

