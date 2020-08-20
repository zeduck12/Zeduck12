#pragma once
class CCollisionManager
{
public:
	DECLARE_SINGLETON(CCollisionManager)

public:
	static bool CollideBullet(CObj* _pDstObj, CObj* _SrcObj);				 // Object�� �Ѿ��浹 
	static bool CollidePlayerMonster(CObj* _pDstObj, CObj* _SrcObj);		 // �÷��̾�� ���� �浹
	static bool CollideWallGrenade(CObj* _pDstObj, CObj* _SrcObj);			 // ���� ����ź
	static bool CollideLineToLine(LINEINFO& _DstLine, LINEINFO& _SrcLine);	 // ���� �� �浹
	static bool CollideLineToLineReturn(LINEINFO& _DstLine, LINEINFO& _SrcLine, LINEPOS* _pOut = nullptr);	 // ���� �� �浹

private:
	CCollisionManager() = default;
	~CCollisionManager();

};
