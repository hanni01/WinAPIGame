#pragma once

class IComponent;//���漱��
class GameObject //abstract - > �߻� �Լ� ������ �ڵ����� �߻������� ��//���� �ɾ��ֱ� ��δ� ��ü�� ������ �� ����
{
public:
	GameObject();
	virtual ~GameObject() {};

	virtual bool Awake() = 0; //�߻� �Լ�
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;

	template <typename T>
	T* GetComponent()
	{
		const type_info& key = typeid(T);

		auto iter = mComponents.find(key);
		if (iter == mComponents.end())
		{
			return nullptr;
		}
		return reinterpret_cast<T*>(iter->second);
	}

	template <typename T>
	void AddComponent()
	{
		const type_info& key = typeid(T);

		auto iter = mComponents.find(key);
		if (iter != mComponents.end())
		{
			//�α� ����ų�
			return;
		}
		//������Ʈ �����Ҵ�
		T* component = new T;
		mComponents.emplace(key, component);
	}
private:
	std::map<type_info, IComponent*> mComponents;
};

