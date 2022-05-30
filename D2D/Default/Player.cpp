
//==================================================
// 내 방식
//#include "stdafx.h"
//#include "Player.h"
//
//CPlayer::CPlayer()
//{
//}
//
//CPlayer::~CPlayer()
//{
//	Release();
//}
//
//void CPlayer::Initialize(void)
//{
//	m_tInfo.vPos = { 350.f, 350.f, 0.f };
//	m_tInfo.vDir = { 0.f, 0.f, 0.f };
//
//	m_vTankBody[0] = { m_tInfo.vPos.x - 50.f, m_tInfo.vPos.y - 50.f, 0.f};
//	m_vTankBody[1] = { m_tInfo.vPos.x - 50.f, m_tInfo.vPos.y + 50.f, 0.f };
//	m_vTankBody[2] = { m_tInfo.vPos.x + 50.f, m_tInfo.vPos.y + 50.f, 0.f };
//	m_vTankBody[3] = { m_tInfo.vPos.x + 50.f, m_tInfo.vPos.y - 50.f, 0.f };
//	m_vTankBody[4] = { m_tInfo.vPos.x, m_tInfo.vPos.y - 50.f, 0.f };
//
//	m_vTankPosin[0] = { m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f };
//	m_vTankPosin[1] = { m_tInfo.vPos.x, m_tInfo.vPos.y - 100.f, 0.f };
//
//	m_fAngle = 0.f;
//	m_fAnglePosin = 0.f;
//
//	m_fSpeed = 5.0f;
//	m_bPositionChange = false;
//}
//
//void CPlayer::Update(void)
//{
//	m_fAngle = 0.f;
//	m_fAnglePosin = 0.f;
//
//	m_tInfo.vDir = { (m_vTankBody[4].x - m_tInfo.vPos.x) / 10.f, (m_vTankBody[4].y - m_tInfo.vPos.y) / 10.f, 0.f };
//
//	Key_Input();
//
//	// 이동 연산 먼저
//	D3DXMATRIX	matTrans;
//	
//	D3DXMatrixTranslation(&matTrans, m_tInfo.vDir.x, m_tInfo.vDir.y, 0.f);
//	m_tInfo.matWorld = matTrans;
//
//	if (m_bPositionChange)
//	{
//		for (auto& _iter : m_vTankBody)
//		{
//			D3DXVec3TransformCoord(&_iter, &_iter, &m_tInfo.matWorld);
//		}
//
//		for (auto& _iter : m_vTankPosin)
//		{
//			D3DXVec3TransformCoord(&_iter, &_iter, &m_tInfo.matWorld);
//		}
//
//		D3DXVec3TransformCoord(&m_tInfo.vPos, &m_tInfo.vPos, &m_tInfo.matWorld);
//
//		m_bPositionChange = false;
//	}
//
//
//	// 이동된 Pos기준 회전 연산
//	// Body
//	D3DXMATRIX	matRotZ;
//	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));
//	m_tInfo.matWorld = matRotZ;
//
//	for (auto& _iter : m_vTankBody)
//	{
//		// 변경된 기준점을 수식에 넣는 대신,
//		// 좌표 자체를 0점으로 옮겨서 회전한 후, 원래자리로 갖다놓는 것 같다.
//		_iter.x -= m_tInfo.vPos.x;
//		_iter.y -= m_tInfo.vPos.y;
//		D3DXVec3TransformCoord(&_iter, &_iter, &m_tInfo.matWorld);
//		_iter.x += m_tInfo.vPos.x;
//		_iter.y += m_tInfo.vPos.y;
//	}
//
//	// Posin
//	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAnglePosin));
//	m_tInfo.matWorld = matRotZ;
//
//	for (auto& _iter : m_vTankPosin)
//	{
//		_iter.x -= m_tInfo.vPos.x;
//		_iter.y -= m_tInfo.vPos.y;
//		D3DXVec3TransformCoord(&_iter, &_iter, &m_tInfo.matWorld);
//		_iter.x += m_tInfo.vPos.x;
//		_iter.y += m_tInfo.vPos.y;
//	}
//}
//
//void CPlayer::Render(HDC hDC)
//{
//	// Body
//	MoveToEx(hDC, m_vTankBody[0].x, m_vTankBody[0].y, NULL);
//	LineTo(hDC, m_vTankBody[1].x, m_vTankBody[1].y);
//	LineTo(hDC, m_vTankBody[2].x, m_vTankBody[2].y);
//	LineTo(hDC, m_vTankBody[3].x, m_vTankBody[3].y);
//	LineTo(hDC, m_vTankBody[0].x, m_vTankBody[0].y);
//	
//	// Posin
//	MoveToEx(hDC, m_vTankPosin[0].x, m_vTankPosin[0].y, NULL);
//	LineTo(hDC, m_vTankPosin[1].x, m_vTankPosin[1].y);
//}
//
//void CPlayer::Release(void)
//{
//}
//
//void CPlayer::Key_Input(void)
//{
//	if (GetAsyncKeyState('W'))
//		m_bPositionChange = true;
//
//	if (GetAsyncKeyState('S'))
//	{
//		m_tInfo.vDir.x *= -1;
//		m_tInfo.vDir.y *= -1;
//		m_bPositionChange = true;
//	}
//
//	if (GetAsyncKeyState('A'))
//		m_fAngle -= 1.f;
//
//	if (GetAsyncKeyState('D'))
//		m_fAngle += 1.f;
//
//	if (GetAsyncKeyState(VK_LEFT))
//		m_fAnglePosin -= 1.f;
//
//	if (GetAsyncKeyState(VK_RIGHT))
//		m_fAnglePosin += 1.f;
//}

//==================================================
// 영웅이 방식

//#include "stdafx.h"
//#include "Player.h"
//
//CPlayer::CPlayer()
//{
//}
//
//CPlayer::~CPlayer()
//{
//	Release();
//}
//
//
//void CPlayer::Initialize(void)
//{
//	m_tInfo.vPos = { 300.f, 400.f, 0.f };
//
//	Setting();
//	m_tInfo.vDir = { 0.f, -1.f, 0.f };
//
//	m_vTankBody[0] = { m_tInfo.vPos.x - 40.f, m_tInfo.vPos.y - 50.f, 0.f };
//	m_vTankBody[1] = { m_tInfo.vPos.x - 40.f, m_tInfo.vPos.y + 50.f, 0.f };
//	m_vTankBody[2] = { m_tInfo.vPos.x + 40.f, m_tInfo.vPos.y + 50.f, 0.f };
//	m_vTankBody[3] = { m_tInfo.vPos.x + 40.f, m_tInfo.vPos.y - 50.f, 0.f };
//
//	m_vTankPosin[0] = { m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f };
//	m_vTankPosin[1] = { m_tInfo.vPos.x, m_tInfo.vPos.y - 100.f, 0.f };
//
//	m_fAngle = 0.f;
//	m_fAnglePosin = 0.f;
//
//	m_fSpeed = 5.0f;
//	//m_bPositionChange = false;
//}
//
//void CPlayer::Update(void)
//{
//	Key_Input();
//	
//	// 전체 회전
//	Setting();
//
//	D3DXMATRIX	matScale, matRotZ, matTrans;
//	
//	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
//	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));
//	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);
//	m_tInfo.matWorld = matScale * matRotZ * matTrans;
//
//	for (auto& _iter : m_vTankBody)
//		D3DXVec3TransformCoord(&_iter, &_iter, &m_tInfo.matWorld);
//
//	for (auto& _iter : m_vTankPosin)
//		D3DXVec3TransformCoord(&_iter, &_iter, &m_tInfo.matWorld);
//
//	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vDir, &m_tInfo.matWorld);
//
//	//포신 회전
//	Setting_OnlyPosin();
//
//	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
//	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAnglePosin));
//	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);
//
//	m_tInfo.matWorld = matScale * matRotZ * matTrans;
//
//	for (auto& _iter : m_vTankPosin)
//		D3DXVec3TransformCoord(&_iter, &_iter, &m_tInfo.matWorld);
//}
//
//void CPlayer::Render(HDC hDC)
//{
//	// Body
//	MoveToEx(hDC, m_vTankBody[0].x, m_vTankBody[0].y, NULL);
//	LineTo(hDC, m_vTankBody[1].x, m_vTankBody[1].y);
//	LineTo(hDC, m_vTankBody[2].x, m_vTankBody[2].y);
//	LineTo(hDC, m_vTankBody[3].x, m_vTankBody[3].y);
//	LineTo(hDC, m_vTankBody[0].x, m_vTankBody[0].y);
//
//	// Posin
//	MoveToEx(hDC, m_vTankPosin[0].x, m_vTankPosin[0].y, NULL);
//	LineTo(hDC, m_vTankPosin[1].x, m_vTankPosin[1].y);
//
//	// Head
//	Ellipse(hDC, m_vTankBody[0].x - 10.f, m_vTankBody[0].y - 10.f, m_vTankBody[0].x + 10.f, m_vTankBody[0].y + 10.f);
//	Ellipse(hDC, m_vTankBody[3].x - 10.f, m_vTankBody[3].y - 10.f, m_vTankBody[3].x + 10.f, m_vTankBody[3].y + 10.f);
//}
//
//void CPlayer::Release(void)
//{
//}
//
//void CPlayer::Key_Input(void)
//{
//	if (GetAsyncKeyState('W'))
//	{
//		m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;
//		m_tInfo.vPos.y += m_tInfo.vDir.y * m_fSpeed;
//	}
//
//	if (GetAsyncKeyState('S'))
//	{
//		m_tInfo.vPos.x -= m_tInfo.vDir.x * m_fSpeed;
//		m_tInfo.vPos.y -= m_tInfo.vDir.y * m_fSpeed;
//	}
//
//	if (GetAsyncKeyState('A'))
//		m_fAngle -= 3.f;
//
//	if (GetAsyncKeyState('D'))
//		m_fAngle += 3.f;
//
//	if (GetAsyncKeyState(VK_LEFT))
//		m_fAnglePosin -= 3.f;
//
//	if (GetAsyncKeyState(VK_RIGHT))
//		m_fAnglePosin += 3.f;
//}
//
//void CPlayer::Setting()
//{
//	m_tInfo.vDir = { 0.f, -1.f, 0.f };
//
//	m_vTankBody[0] = { - 40.f, - 50.f, 0.f };
//	m_vTankBody[1] = { - 40.f, + 50.f, 0.f };
//	m_vTankBody[2] = { + 40.f, + 50.f, 0.f };
//	m_vTankBody[3] = { + 40.f, - 50.f, 0.f };
//
//	m_vTankPosin[0] = { 0.f, 0.f, 0.f };
//	m_vTankPosin[1] = { 0.f, - 100.f, 0.f };
//}
//
//void CPlayer::Setting_OnlyPosin()
//{
//	m_vTankPosin[0] = { 0.f, 0.f, 0.f };
//	m_vTankPosin[1] = { 0.f, - 100.f, 0.f };
//}

//==================================================
// 현수 방식

#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
{
	// 인코딩 확인
	int i = 0;
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	ZeroMemory(&m_tInfoLocal, sizeof(INFO));
	//D3DXMatrixIdentity(&m_tInfoLocal.matWorld);

	m_tInfo.vPos = { 400.f, 300.f, 0.f };

	m_tInfoLocal.vPos = { 0.f, 0.f, 0.f };
	m_tInfoLocal.vDir = { 0.f, -1.f, 0.f };

	m_vTankBodyLocal[0] = { -40.f, -50.f, 0.f };
	m_vTankBodyLocal[1] = { -40.f, +50.f, 0.f };
	m_vTankBodyLocal[2] = { +40.f, +50.f, 0.f };
	m_vTankBodyLocal[3] = { +40.f, -50.f, 0.f };

	m_vTankPosinLocal[0] = { 0.f, 0.f, 0.f };
	m_vTankPosinLocal[1] = { 0.f, -100.f, 0.f };

	m_fAngle = 0.f;
	m_fAnglePosin = 0.f;

	m_fSpeed = 5.0f;
}

void CPlayer::Update(void)
{
	Key_Input();

	// 전체 회전

	D3DXMATRIX	matScale, matRotZ, matTrans;

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);
	m_tInfo.matWorld = matScale * matRotZ * matTrans;

	for (int i = 0; i < 5; ++i)
		D3DXVec3TransformCoord(&m_vTankBody[i], &m_vTankBodyLocal[i], &m_tInfo.matWorld);

	for (int i = 0; i < 2; ++i)
		D3DXVec3TransformCoord(&m_vTankPosin[i], &m_vTankPosinLocal[i], &m_tInfo.matWorld);

	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfoLocal.vDir, &m_tInfo.matWorld);

	//포신 회전

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAnglePosin));
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);

	m_tInfo.matWorld = matScale * matRotZ * matTrans;

	for (int i = 0; i < 2; ++i)
		D3DXVec3TransformCoord(&m_vTankPosin[i], &m_vTankPosinLocal[i], &m_tInfo.matWorld);
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

	// Head
	Ellipse(hDC, m_vTankBody[0].x - 10.f, m_vTankBody[0].y - 10.f, m_vTankBody[0].x + 10.f, m_vTankBody[0].y + 10.f);
	Ellipse(hDC, m_vTankBody[3].x - 10.f, m_vTankBody[3].y - 10.f, m_vTankBody[3].x + 10.f, m_vTankBody[3].y + 10.f);
}

void CPlayer::Release(void)
{
}

void CPlayer::Key_Input(void)
{
	if (GetAsyncKeyState('W'))
	{
		m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;
		m_tInfo.vPos.y += m_tInfo.vDir.y * m_fSpeed;
	}

	if (GetAsyncKeyState('S'))
	{
		m_tInfo.vPos.x -= m_tInfo.vDir.x * m_fSpeed;
		m_tInfo.vPos.y -= m_tInfo.vDir.y * m_fSpeed;
	}

	if (GetAsyncKeyState('A'))
		m_fAngle -= 3.f;

	if (GetAsyncKeyState('D'))
		m_fAngle += 3.f;

	if (GetAsyncKeyState(VK_LEFT))
		m_fAnglePosin -= 3.f;

	if (GetAsyncKeyState(VK_RIGHT))
		m_fAnglePosin += 3.f;
}