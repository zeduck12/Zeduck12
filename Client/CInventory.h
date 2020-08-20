#pragma once
class CInventory final
{
public:
	CInventory() = default;
	virtual ~CInventory();

public:
	bool Ready(void);
	void Release(void);

public:
	GUN::ID GetCurWeapon(void) const { return m_eCurWeaponID; }; // ���� ������� ���� ��ȯ
	
public:
	void GainWeapon(GUN::ID _eID);		// ���� ���
	void ChangeWeapon(void);			// ���� �ٲٱ�

private:
	int m_iCapacity;					 // �κ��丮 ũ��
	GUN::ID m_eCurWeaponID;				 // ���� ������� ���� ID
	std::vector<GUN::ID> m_vecInventory; // ���� ��� �κ��丮
};


// ���߿� �κ��丮�� ����ִ� �Ѿ� + �� �̹��� ����ϱ�.