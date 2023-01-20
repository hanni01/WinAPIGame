#pragma once

class IComponent;//전방선언
class GameObject //abstract - > 추상 함수 생성시 자동으로 추상적으로 됨//제한 걸어주기 얘로는 객체를 생성할 수 없다
{
public:
	GameObject();
	virtual ~GameObject() {};

	virtual bool Awake() = 0; //추상 함수
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
			//로그 남기거나
			return;
		}
		//컴포넌트 동적할당
		T* component = new T;
		mComponents.emplace(key, component);
	}
private:
	std::map<type_info, IComponent*> mComponents;
};

