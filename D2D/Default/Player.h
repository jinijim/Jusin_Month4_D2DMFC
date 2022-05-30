#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	void		Key_Input(void);
	void		Setting();
	void		Setting_OnlyPosin();


private:

	D3DXVECTOR3		m_vTankBody[5];
	D3DXVECTOR3		m_vTankPosin[2];
	float			m_fAngle;
	float			m_fAnglePosin;


	// Local World ���� �и� �� �ʿ��� ����
	INFO			m_tInfoLocal;
	D3DXVECTOR3		m_vTankBodyLocal[5];
	D3DXVECTOR3		m_vTankPosinLocal[2];


	/*
	D3DXVECTOR3		m_vPlayerPos;	// ��ġ ����

	D3DXVECTOR3		m_vPlayerDir;	// ���� ����
	D3DXVECTOR3		m_vPlayerLook;	// ���� ����

	D3DXVECTOR3		m_vPlayerNormal;	// ���� ����*/
};

