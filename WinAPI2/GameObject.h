#pragma once
class GameObject //abstract - > �߻� �Լ� ������ �ڵ����� �߻������� ��//���� �ɾ��ֱ� ��δ� ��ü�� ������ �� ����
{
public:
	GameObject();
	virtual ~GameObject() {};

	virtual bool Awake(HDC HDC) = 0; //�߻� �Լ�
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

protected:
	HDC mHDC;
	Position mPos;
};

