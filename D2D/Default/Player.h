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


	// Local World 개념 분리 시 필요한 변수
	INFO			m_tInfoLocal;
	D3DXVECTOR3		m_vTankBodyLocal[5];
	D3DXVECTOR3		m_vTankPosinLocal[2];


	/*
	D3DXVECTOR3		m_vPlayerPos;	// 위치 벡터

	D3DXVECTOR3		m_vPlayerDir;	// 방향 벡터
	D3DXVECTOR3		m_vPlayerLook;	// 방향 벡터

	D3DXVECTOR3		m_vPlayerNormal;	// 법선 벡터*/
};

