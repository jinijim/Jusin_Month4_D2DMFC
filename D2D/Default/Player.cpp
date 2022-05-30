#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo.vPos = { 350.f, 350.f, 0.f };
	m_tInfo.vDir = { 0.f, 0.f, 0.f };

	m_vTankBody[0] = { m_tInfo.vPos.x - 50.f, m_tInfo.vPos.y - 50.f, 0.f};
	m_vTankBody[1] = { m_tInfo.vPos.x - 50.f, m_tInfo.vPos.y + 50.f, 0.f };
	m_vTankBody[2] = { m_tInfo.vPos.x + 50.f, m_tInfo.vPos.y + 50.f, 0.f };
	m_vTankBody[3] = { m_tInfo.vPos.x + 50.f, m_tInfo.vPos.y - 50.f, 0.f };
	m_vTankBody[4] = { m_tInfo.vPos.x, m_tInfo.vPos.y - 50.f, 0.f };

	m_vTankPosin[0] = { m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f };
	m_vTankPosin[1] = { m_tInfo.vPos.x, m_tInfo.vPos.y - 100.f, 0.f };

	m_fAngle = 0.f;
	m_fAnglePosin = 0.f;

	m_fSpeed = 5.0f;
	m_bPositionChange = false;
}

void CPlayer::Update(void)
{
	m_tInfo.vDir = { (m_vTankBody[4].x - m_tInfo.vPos.x) / 50.f, (m_vTankBody[4].y - m_tInfo.vPos.y) / 50.f, 0.f };

	Key_Input();

	// 이동 연산 먼저
	D3DXMATRIX	matTrans;
	D3DXMatrixTranslation(&matTrans, m_tInfo.vDir.x, m_tInfo.vDir.y, 0.f);
	m_tInfo.matWorld = matTrans;

	if (m_bPositionChange)
	{
		for (auto& _iter : m_vTankBody)
		{
			D3DXVec3TransformCoord(&_iter, &_iter, &m_tInfo.matWorld);
		}

		for (auto& _iter : m_vTankPosin)
		{
			D3DXVec3TransformCoord(&_iter, &_iter, &m_tInfo.matWorld);
		}

		D3DXVec3TransformCoord(&m_tInfo.vPos, &m_tInfo.vPos, &m_tInfo.matWorld);

		m_bPositionChange = false;
	}


	// 이동된 Pos기준 회전 연산
	// Body
	D3DXMATRIX	matRotZ;
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));
	m_tInfo.matWorld = matRotZ;

	for (auto& _iter : m_vTankBody)
	{
		// 변경된 기준점을 수식에 넣는 대신,
		// 좌표 자체를 0점으로 옮겨서 회전한 후, 원래자리로 갖다놓는 것 같다.
		_iter.x -= m_tInfo.vPos.x;
		_iter.y -= m_tInfo.vPos.y;
		D3DXVec3TransformCoord(&_iter, &_iter, &m_tInfo.matWorld);
		_iter.x += m_tInfo.vPos.x;
		_iter.y += m_tInfo.vPos.y;
	}

	// Posin
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAnglePosin));
	m_tInfo.matWorld = matRotZ;

	for (auto& _iter : m_vTankPosin)
	{
		_iter.x -= m_tInfo.vPos.x;
		_iter.y -= m_tInfo.vPos.y;
		D3DXVec3TransformCoord(&_iter, &_iter, &m_tInfo.matWorld);
		_iter.x += m_tInfo.vPos.x;
		_iter.y += m_tInfo.vPos.y;
	}

	m_fAngle = 0.f;
	m_fAnglePosin = 0.f;
}

void CPlayer::Render(HDC hDC)
{
	// Body
	MoveToEx(hDC, m_vTankBody[0].x, m_vTankBody[0].y, NULL);
	LineTo(hDC, m_vTankBody[1].x, m_vTankBody[1].y);
	LineTo(hDC, m_vTankBody[2].x, m_vTankBody[2].y);
	LineTo(hDC, m_vTankBody[3].x, m_vTankBody[3].y);
	LineTo(hDC, m_vTankBody[0].x, m_vTankBody[0].y);
	
	// Posin
	MoveToEx(hDC, m_vTankPosin[0].x, m_vTankPosin[0].y, NULL);
	LineTo(hDC, m_vTankPosin[1].x, m_vTankPosin[1].y);
}

void CPlayer::Release(void)
{
	
}

void CPlayer::Key_Input(void)
{
	if (GetAsyncKeyState('W'))
		m_bPositionChange = true;

	if (GetAsyncKeyState('S'))
	{
		m_tInfo.vDir.x *= -1;
		m_tInfo.vDir.y *= -1;
		m_bPositionChange = true;
	}

	if (GetAsyncKeyState('A'))
		m_fAngle -= 1.f;

	if (GetAsyncKeyState('D'))
		m_fAngle += 1.f;

	if (GetAsyncKeyState(VK_LEFT))
		m_fAnglePosin -= 1.f;

	if (GetAsyncKeyState(VK_RIGHT))
		m_fAnglePosin += 1.f;
}