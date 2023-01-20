#include "pch.h"
#include "Transform.h"

void Transform::OnAlloc()
{
}

void Transform::OnFree()
{
}

Position Transform::GetPosition() const
{
	return mPos;
}

void Transform::SetPosition(int x, int y)
{
	mPos.x = x;
	mPos.y = y;
}
