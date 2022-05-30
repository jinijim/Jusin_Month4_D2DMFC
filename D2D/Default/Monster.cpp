#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(void)
{
	m_tInfo.vPos	= { 100.f, 100.f, 0.f };
	m_fSpeed		= 5.f;
	m_tInfo.vLook = { 1.f, 0.f, 0.f };
}

void CMonster::Update(void)
{

#pragma region ����

	/*m_tInfo.vDir = m_pPlayer->Get_Info().vPos - m_tInfo.vPos;
	
	float	fLength = sqrtf(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	m_tInfo.vDir.x /= fLength;
	m_tInfo.vDir.y /= fLength;
	m_tInfo.vDir.z = 0.f;

	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;*/

#pragma endregion ����

#pragma region ���� 2

	/*m_tInfo.vDir = ::Get_Mouse() - m_tInfo.vPos;

	float	fDiagonal = sqrtf(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	m_tInfo.vDir.x /= fDiagonal;
	m_tInfo.vDir.y /= fDiagonal;
	m_tInfo.vDir.z = 0.f;

	float	fDiagonal2 = sqrtf(m_tInfo.vLook.x * m_tInfo.vLook.x + m_tInfo.vLook.y * m_tInfo.vLook.y);

	m_tInfo.vLook.x /= fDiagonal2;
	m_tInfo.vLook.y /= fDiagonal2;
	m_tInfo.vLook.z = 0.f;

	float	fDot = m_tInfo.vDir.x * m_tInfo.vLook.x + m_tInfo.vDir.y * m_tInfo.vLook.y;

	float	fAngle = acosf(fDot);

	if (m_tInfo.vPos.y < Get_Mouse().y)
		fAngle = 2.f * D3DX_PI - fAngle;

	m_tInfo.vPos.x += m_fSpeed * cosf(fAngle);
	m_tInfo.vPos.y -= m_fSpeed * sinf(fAngle);*/

#pragma endregion ���� 2

	m_tInfo.vDir = ::Get_Mouse() - m_tInfo.vPos;

	// ������ ����ȭ�� �����ϴ� �Լ�(1. ��� ���� ��� ������ ���ΰ� 2. ���� ���ͷ� ���� ����)
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	D3DXVec3Normalize(&m_tInfo.vLook, &m_tInfo.vLook);

	// ������ ũ�⸦ �����ִ� �Լ�
	// float fLength = D3DXVec3Length(&m_tInfo.vDir);

	// �� ���� ������ ������ �����ϴ� �Լ�
	float fDot = D3DXVec3Dot(&m_tInfo.vDir, &m_tInfo.vLook);

	// �� ���� ������ ������ �����ϴ� �Լ�(1. ��� ���� ������ ����, 2~3���� ���ϴ� ���� ����)

	/*D3DXVECTOR3	vAxis;
	D3DXVec3Cross(&vAxis, &m_tInfo.vDir, &m_tInfo.vLook);*/
		
	float	fAngle = acosf(fDot);

	if (m_tInfo.vPos.y < Get_Mouse().y)
		fAngle = 2.f * D3DX_PI - fAngle;

	m_tInfo.vPos.x += m_fSpeed * cosf(fAngle);
	m_tInfo.vPos.y -= m_fSpeed * sinf(fAngle);

	
}

void CMonster::Render(HDC hDC)
{
	Ellipse(hDC,
		int(m_tInfo.vPos.x - 50.f),
		int(m_tInfo.vPos.y - 50.f),
		int(m_tInfo.vPos.x + 50.f),
		int(m_tInfo.vPos.y + 50.f));
}

void CMonster::Release(void)
{
	
}

// ���� ���� : ũ�Ⱑ 1�� ����
// ������ ����ȭ : ���� ���͸� ����� ����

// ������ ������ ���� : �ݵ�� �� ���� ����(���� ����)�� ���� ����

// ���� : ��Į�� ��(����� ����� �߻�), ��ȣ�� A �� B, ������ ��� : x*x` + y*y`+ z*z`
// ���� : ���� ��(����� ���Ͱ� �߻�), ��ȣ�� A X B, ������ ��� 

/*
X		Y		Z

X`      Y`      Z`

(Y * Z` - Z * Y`, X * Z` - Z * X`, X * Y` - Y * X`);*/


// 1. ������ ������ �̿��Ͽ� �÷��̾ ����ٴϴ� ���͸� �����϶�.