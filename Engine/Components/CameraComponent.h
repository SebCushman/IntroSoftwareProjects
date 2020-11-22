#pragma once
#include "Math\Vector2.h"
#include "Component.h"

namespace nc
{
	class CameraComponent : public Component
	{
	public:
		virtual void Create(void* data = nullptr) override;
		virtual void Destroy() override;
		virtual Object* Clone() const override { return new CameraComponent{ *this }; }

		virtual void Update() override;

		void UpdateCameraPosition(int x, int y);
		void UpdateCameraPosition(Vector2 position);

		void Read(const rapidjson::Value& value) override;

		Vector2 GetCameraPosition() { return m_cameraPosition; }

		void SetCropFactor(Vector2 v) { m_cropFactor = v; }
		Vector2 GetCropFactor() { return m_cropFactor; }


	private:
		Vector2 m_cameraPosition{ 0,0 };
		Vector2 m_cropFactor{ 0, 0 };
	};
}