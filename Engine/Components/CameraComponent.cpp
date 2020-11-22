#include "pch.h"
#include "CameraComponent.h"
namespace nc
{
	void CameraComponent::Create(void* data)
	{
		m_owner = static_cast<nc::GameObject*>(data);
	}

	void CameraComponent::Destroy()
	{
	}

	void CameraComponent::Update()
	{

	}

	void CameraComponent::UpdateCameraPosition(int x, int y)
	{
		m_cameraPosition.x = x;
		m_cameraPosition.y = y;

	}

	void CameraComponent::UpdateCameraPosition(Vector2 position)
	{
		m_cameraPosition = position;
	}

	void CameraComponent::Read(const rapidjson::Value& value)
	{
		json::Get(value, "position", m_cameraPosition);
	}

}
