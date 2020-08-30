#include "pch.h"
#include "CBossState.h"
#include "CAnimation.h"
#include "CTextureManager.h"
#include "CGraphicDevice.h"
#include "CTimeManager.h"
#include "CShadow.h"
#include "CPlayerManager.h"

CBossState* EggIdleState::Update(CBoss* _pBoss)
{
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
		pAnimation->Update(GET_SINGLE(CTimeManager)->GetElapsedTime());

	pAnimation->ChangeClip("EggIdle");

	return nullptr;
}

void EggIdleState::Render(CBoss* _pBoss)
{
	// �ִϸ��̼� ���
	int iFrame = 0;
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
	{
		ANIMATION_CLIP* pClip = pAnimation->GetCurrentClip();
		iFrame = pClip->iFrame; // �ε���
	}

	TEXINFO* pTexInfo = _pBoss->GetTextureInfo()[iFrame];

	float fCenterX = float(pTexInfo->tImageInfo.Width * 0.5f);
	float fCenterY = float(pTexInfo->tImageInfo.Height * 0.5f);

	D3DXMATRIX matScale, matTrans, matWorld;
	if (_pBoss->GetDirection() == DIRECTION::LEFT)
		D3DXMatrixScaling(&matScale, -1.f, 1.f, 0.f);
	else
		D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);

	// 20�� ��Ʈ �߽ɿ� �̹��� ���߱� ����.
	D3DXMatrixTranslation(&matTrans, _pBoss->GetInfo()->vPos.x, _pBoss->GetInfo()->vPos.y - 20, 0.f);
	matWorld = matScale * matTrans;

	CGraphicDevice::Get_Instance()->GetSprite()->SetTransform(&matWorld);
	CGraphicDevice::Get_Instance()->GetSprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	CShadow::RenderShadow(_pBoss);
}

CBossState* EggStartState::Update(CBoss* _pBoss)
{
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
		pAnimation->Update(GET_SINGLE(CTimeManager)->GetElapsedTime());

	pAnimation->ChangeClip("EggStart");

	return nullptr;
}

void EggStartState::Render(CBoss* _pBoss)
{
	// �ִϸ��̼� ���
	int iFrame = 0;
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
	{
		ANIMATION_CLIP* pClip = pAnimation->GetCurrentClip();
		iFrame = pClip->iFrame; // �ε���
	}

	TEXINFO* pTexInfo = _pBoss->GetTextureInfo()[iFrame];

	float fCenterX = float(pTexInfo->tImageInfo.Width * 0.5f);
	float fCenterY = float(pTexInfo->tImageInfo.Height * 0.5f);

	D3DXMATRIX matScale, matTrans, matWorld;
	if (_pBoss->GetDirection() == DIRECTION::LEFT)
		D3DXMatrixScaling(&matScale, -1.f, 1.f, 0.f);
	else
		D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);

	// 20�� ��Ʈ �߽ɿ� �̹��� ���߱� ����.
	D3DXMatrixTranslation(&matTrans, _pBoss->GetInfo()->vPos.x, _pBoss->GetInfo()->vPos.y - 20, 0.f);
	matWorld = matScale * matTrans;

	CGraphicDevice::Get_Instance()->GetSprite()->SetTransform(&matWorld);
	CGraphicDevice::Get_Instance()->GetSprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	CShadow::RenderShadow(_pBoss);
}

CBossState* EggCrackState::Update(CBoss* _pBoss)
{
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
		pAnimation->Update(GET_SINGLE(CTimeManager)->GetElapsedTime());

	pAnimation->ChangeClip("EggCrack");

	return nullptr;
}

void EggCrackState::Render(CBoss* _pBoss)
{
	int iFrame = 0;
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
	{
		ANIMATION_CLIP* pClip = pAnimation->GetCurrentClip();
		iFrame = pClip->iFrame; // �ε���
	}

	TEXINFO* pTexInfo = _pBoss->GetTextureInfo()[iFrame];

	float fCenterX = float(pTexInfo->tImageInfo.Width * 0.5f);
	float fCenterY = float(pTexInfo->tImageInfo.Height * 0.5f);

	D3DXMATRIX matScale, matTrans, matWorld;
	if (_pBoss->GetDirection() == DIRECTION::LEFT)
		D3DXMatrixScaling(&matScale, -1.f, 1.f, 0.f);
	else
		D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);

	// 20�� ��Ʈ �߽ɿ� �̹��� ���߱� ����.
	D3DXMatrixTranslation(&matTrans, _pBoss->GetInfo()->vPos.x, _pBoss->GetInfo()->vPos.y - 20, 0.f);
	matWorld = matScale * matTrans;

	CGraphicDevice::Get_Instance()->GetSprite()->SetTransform(&matWorld);
	CGraphicDevice::Get_Instance()->GetSprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	CShadow::RenderShadow(_pBoss);
}

CBossState* BossIdleState::Update(CBoss* _pBoss)
{
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
		pAnimation->Update(GET_SINGLE(CTimeManager)->GetElapsedTime());

	pAnimation->ChangeClip("Idle");

	// ���࿡ �÷��̾ �����ߴٸ�
	if (_pBoss->IsDetectPlayerBossVersion() == true)
		return new BossMoveState;

	return nullptr;
}

void BossIdleState::Render(CBoss* _pBoss)
{
	int iFrame = 0;
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
	{
		ANIMATION_CLIP* pClip = pAnimation->GetCurrentClip();
		iFrame = pClip->iFrame; // �ε���
	}

	TEXINFO* pTexInfo = _pBoss->GetTextureInfo()[iFrame];

	float fCenterX = float(pTexInfo->tImageInfo.Width * 0.5f);
	float fCenterY = float(pTexInfo->tImageInfo.Height * 0.5f);

	D3DXMATRIX matScale, matTrans, matWorld;
	if (_pBoss->GetDirection() == DIRECTION::LEFT)
		D3DXMatrixScaling(&matScale, -1.f, 1.f, 0.f);
	else
		D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);

	// 20�� ��Ʈ �߽ɿ� �̹��� ���߱� ����.
	D3DXMatrixTranslation(&matTrans, _pBoss->GetInfo()->vPos.x, _pBoss->GetInfo()->vPos.y - 20, 0.f);
	matWorld = matScale * matTrans;

	CGraphicDevice::Get_Instance()->GetSprite()->SetTransform(&matWorld);
	CGraphicDevice::Get_Instance()->GetSprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	CShadow::RenderShadow(_pBoss);
}

CBossState* BossMoveState::Update(CBoss* _pBoss)
{
	CObj* pPlayer = GET_SINGLE(CPlayerManager)->GetPlayer();
	DO_IF_IS_NOT_VALID_OBJ(pPlayer)
		return nullptr;

	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
		pAnimation->Update(GET_SINGLE(CTimeManager)->GetElapsedTime());

	pAnimation->ChangeClip("Move");

	// ���࿡ �÷��̾ ���� ������ ����� �ٽ� Idle ���·�
	if (_pBoss->IsDetectPlayerBossVersion() == false)
		return new BossIdleState;

	// ���࿡ ���ݹ��� �ȿ� ���´ٸ� AttackState��
	if (_pBoss->IsInAttackRangePlayerBossVersion() == true)
	{
		// �÷��̾� �������� ���⺤�� ����
		D3DXVECTOR3 vDir = pPlayer->GetInfo()->vPos - _pBoss->GetInfo()->vPos;
		D3DXVec3Normalize(&vDir, &vDir);
		_pBoss->SetDirectionVector(vDir);
		return new BossAttackState;
	}

	// ���⺤�� ����.
	D3DXVECTOR3 vDir = pPlayer->GetInfo()->vPos - _pBoss->GetInfo()->vPos;
	D3DXVec3Normalize(&vDir, &vDir);
	_pBoss->SetDirectionVector(vDir);
	// �̵�
	D3DXVECTOR3 vMoveResult = _pBoss->GetPosVector() + _pBoss->GetDirectionVector();
	_pBoss->SetPosVector(vMoveResult);

	return nullptr;
}

void BossMoveState::Render(CBoss* _pBoss)
{
	int iFrame = 0;
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
	{
		ANIMATION_CLIP* pClip = pAnimation->GetCurrentClip();
		iFrame = pClip->iFrame; // �ε���
	}

	TEXINFO* pTexInfo = _pBoss->GetTextureInfo()[iFrame];

	float fCenterX = float(pTexInfo->tImageInfo.Width * 0.5f);
	float fCenterY = float(pTexInfo->tImageInfo.Height * 0.5f);

	D3DXMATRIX matScale, matTrans, matWorld;
	if (_pBoss->GetDirection() == DIRECTION::LEFT)
		D3DXMatrixScaling(&matScale, -1.f, 1.f, 0.f);
	else
		D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);

	// 20�� ��Ʈ �߽ɿ� �̹��� ���߱� ����.
	D3DXMatrixTranslation(&matTrans, _pBoss->GetInfo()->vPos.x, _pBoss->GetInfo()->vPos.y - 20, 0.f);
	matWorld = matScale * matTrans;

	CGraphicDevice::Get_Instance()->GetSprite()->SetTransform(&matWorld);
	CGraphicDevice::Get_Instance()->GetSprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	CShadow::RenderShadow(_pBoss);
}

CBossState* BossAttackedState::Update(CBoss* _pBoss)
{
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
		pAnimation->Update(GET_SINGLE(CTimeManager)->GetElapsedTime());

	pAnimation->ChangeClip("Attacked");

	m_fCoolTime = 0.4f;
	m_fStackTime += GET_SINGLE(CTimeManager)->GetElapsedTime();
	if (m_fStackTime >= m_fCoolTime)
		return new BossIdleState;

	return nullptr;
}

void BossAttackedState::Render(CBoss* _pBoss)
{
	int iFrame = 0;
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
	{
		ANIMATION_CLIP* pClip = pAnimation->GetCurrentClip();
		iFrame = pClip->iFrame; // �ε���
	}

	TEXINFO* pTexInfo = _pBoss->GetTextureInfo()[iFrame];

	float fCenterX = float(pTexInfo->tImageInfo.Width * 0.5f);
	float fCenterY = float(pTexInfo->tImageInfo.Height * 0.5f);

	D3DXMATRIX matScale, matTrans, matWorld;
	if (_pBoss->GetDirection() == DIRECTION::LEFT)
		D3DXMatrixScaling(&matScale, -1.f, 1.f, 0.f);
	else
		D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);

	// 20�� ��Ʈ �߽ɿ� �̹��� ���߱� ����.
	D3DXMatrixTranslation(&matTrans, _pBoss->GetInfo()->vPos.x, _pBoss->GetInfo()->vPos.y - 20, 0.f);
	matWorld = matScale * matTrans;

	CGraphicDevice::Get_Instance()->GetSprite()->SetTransform(&matWorld);
	CGraphicDevice::Get_Instance()->GetSprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	CShadow::RenderShadow(_pBoss);
}

CBossState* BossDeathState::Update(CBoss* _pBoss)
{
	return nullptr;
}

void BossDeathState::Render(CBoss* _pBoss)
{
}

CBossState* BossAttackState::Update(CBoss* _pBoss)
{
	CObj* pPlayer = GET_SINGLE(CPlayerManager)->GetPlayer();
	DO_IF_IS_NOT_VALID_OBJ(pPlayer)
		return nullptr;

	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
		pAnimation->Update(GET_SINGLE(CTimeManager)->GetElapsedTime());

	pAnimation->ChangeClip("Idle");

	// ���࿡ ���ݹ����� ����ٸ� �ٽ� IdleState��
	if (_pBoss->IsInAttackRangePlayerBossVersion() == false)
		return new BossIdleState;

	int iRandNum = rand() % 2 + 1;
	if (m_iCount >= 4)
	{
		if (iRandNum > 1)
		{
			m_iCount = 0;
			m_fStackTime = 0.f;
			_pBoss->ShootRocket();
			return new BossRocketAttackState;
		}
		else
		{
			m_iCount = 0;
			m_fStackTime = 0.f;
			_pBoss->ShootShotgun();
			return new BossShotGunState;
		}
	}

	m_fCoolTime = 0.3f;
	m_fStackTime += GET_SINGLE(CTimeManager)->GetElapsedTime();
	if (m_fStackTime >= m_fCoolTime)
	{
		m_iCount++;
		m_fStackTime = 0.f;
		_pBoss->Shoot();
		
	}

	return nullptr;
}

void BossAttackState::Render(CBoss* _pBoss)
{
	int iFrame = 0;
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
	{
		ANIMATION_CLIP* pClip = pAnimation->GetCurrentClip();
		iFrame = pClip->iFrame; // �ε���
	}

	TEXINFO* pTexInfo = _pBoss->GetTextureInfo()[iFrame];

	float fCenterX = float(pTexInfo->tImageInfo.Width * 0.5f);
	float fCenterY = float(pTexInfo->tImageInfo.Height * 0.5f);

	D3DXMATRIX matScale, matTrans, matWorld;
	if (_pBoss->GetDirection() == DIRECTION::LEFT)
		D3DXMatrixScaling(&matScale, -1.f, 1.f, 0.f);
	else
		D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);

	// 20�� ��Ʈ �߽ɿ� �̹��� ���߱� ����.
	D3DXMatrixTranslation(&matTrans, _pBoss->GetInfo()->vPos.x, _pBoss->GetInfo()->vPos.y - 20, 0.f);
	matWorld = matScale * matTrans;

	CGraphicDevice::Get_Instance()->GetSprite()->SetTransform(&matWorld);
	CGraphicDevice::Get_Instance()->GetSprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	CShadow::RenderShadow(_pBoss);
}

CBossState* BossRocketAttackState::Update(CBoss* _pBoss)
{
	CObj* pPlayer = GET_SINGLE(CPlayerManager)->GetPlayer();
	DO_IF_IS_NOT_VALID_OBJ(pPlayer)
		return nullptr;

	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
		pAnimation->Update(GET_SINGLE(CTimeManager)->GetElapsedTime());

	pAnimation->ChangeClip("Idle");

	// ���࿡ ���ݹ����� ����ٸ� �ٽ� IdleState��
	if (_pBoss->IsInAttackRangePlayerBossVersion() == false)
		return new BossIdleState;

	m_fCoolTime = 1.f;
	m_fStackTime += GET_SINGLE(CTimeManager)->GetElapsedTime();
	if (m_fStackTime >= m_fCoolTime)
	{
		if (m_iCount >= 5)
		{
			m_iCount = 0;
			m_fStackTime = 0.f;
			return new BossAttackState;
		}

		m_iCount++;
		m_fStackTime = 0.f;
		_pBoss->ShootRocket();
	}


	return nullptr;
}

void BossRocketAttackState::Render(CBoss* _pBoss)
{
	int iFrame = 0;
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
	{
		ANIMATION_CLIP* pClip = pAnimation->GetCurrentClip();
		iFrame = pClip->iFrame; // �ε���
	}

	TEXINFO* pTexInfo = _pBoss->GetTextureInfo()[iFrame];

	float fCenterX = float(pTexInfo->tImageInfo.Width * 0.5f);
	float fCenterY = float(pTexInfo->tImageInfo.Height * 0.5f);

	D3DXMATRIX matScale, matTrans, matWorld;
	if (_pBoss->GetDirection() == DIRECTION::LEFT)
		D3DXMatrixScaling(&matScale, -1.f, 1.f, 0.f);
	else
		D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);

	// 20�� ��Ʈ �߽ɿ� �̹��� ���߱� ����.
	D3DXMatrixTranslation(&matTrans, _pBoss->GetInfo()->vPos.x, _pBoss->GetInfo()->vPos.y - 20, 0.f);
	matWorld = matScale * matTrans;

	CGraphicDevice::Get_Instance()->GetSprite()->SetTransform(&matWorld);
	CGraphicDevice::Get_Instance()->GetSprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	CShadow::RenderShadow(_pBoss);
}

CBossState* BossShotGunState::Update(CBoss* _pBoss)
{
	CObj* pPlayer = GET_SINGLE(CPlayerManager)->GetPlayer();
	DO_IF_IS_NOT_VALID_OBJ(pPlayer)
		return nullptr;

	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
		pAnimation->Update(GET_SINGLE(CTimeManager)->GetElapsedTime());

	pAnimation->ChangeClip("Idle");

	// ���࿡ ���ݹ����� ����ٸ� �ٽ� IdleState��
	if (_pBoss->IsInAttackRangePlayerBossVersion() == false)
		return new BossIdleState;

	m_fCoolTime = 1.5f;
	m_fStackTime += GET_SINGLE(CTimeManager)->GetElapsedTime();
	if (m_fStackTime >= m_fCoolTime)
	{
		if (m_iCount >= 5)
		{
			m_iCount = 0;
			m_fStackTime = 0.f;
			return new BossAttackState;
		}

		m_iCount++;
		m_fStackTime = 0.f;
		_pBoss->ShootShotgun();
	}

	return nullptr;
}

void BossShotGunState::Render(CBoss* _pBoss)
{
	int iFrame = 0;
	CAnimation* pAnimation = _pBoss->GetAnimation();
	if (pAnimation)
	{
		ANIMATION_CLIP* pClip = pAnimation->GetCurrentClip();
		iFrame = pClip->iFrame; // �ε���
	}

	TEXINFO* pTexInfo = _pBoss->GetTextureInfo()[iFrame];

	float fCenterX = float(pTexInfo->tImageInfo.Width * 0.5f);
	float fCenterY = float(pTexInfo->tImageInfo.Height * 0.5f);

	D3DXMATRIX matScale, matTrans, matWorld;
	if (_pBoss->GetDirection() == DIRECTION::LEFT)
		D3DXMatrixScaling(&matScale, -1.f, 1.f, 0.f);
	else
		D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);

	// 20�� ��Ʈ �߽ɿ� �̹��� ���߱� ����.
	D3DXMatrixTranslation(&matTrans, _pBoss->GetInfo()->vPos.x, _pBoss->GetInfo()->vPos.y - 20, 0.f);
	matWorld = matScale * matTrans;

	CGraphicDevice::Get_Instance()->GetSprite()->SetTransform(&matWorld);
	CGraphicDevice::Get_Instance()->GetSprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	CShadow::RenderShadow(_pBoss);
}