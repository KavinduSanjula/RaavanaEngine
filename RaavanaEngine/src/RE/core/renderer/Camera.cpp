#include "repch.h"
#include "Camera.h"

namespace RE {
	
	Camera::Camera(float minX, float maxX, float minY, float maxY)
		:m_Position(glm::vec3(1.0f)),
		m_Scale(glm::vec3(1.0f)),
		m_Projection(glm::ortho(minX, maxX, minY, maxY, -1.0f, 1.0f)),
		m_View(glm::translate(glm::mat4(1.0f), m_Position)),
		m_ScaleMat(glm::scale(glm::mat4(1.0f), m_Scale)),
		m_Rotation(glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(0.0f,0.0f,1.0f)))
	{
		m_ViewProjection = m_Projection * m_View * m_ScaleMat * m_Rotation;
		SetPosition({ 1,1,1 });
		SetScale({ 1,1 });
	}

	Camera::~Camera()
	{
	}

	void Camera::SetPosition(const glm::vec3& pos)
	{
		m_Position = pos;
		m_View = glm::translate(glm::mat4(1.0f), m_Position);
		RecalculateViewProjection();
	}

	void Camera::SetScale(const glm::vec2& scale)
	{
		m_Scale = glm::vec3(scale.x, scale.y, 1.0f);
		m_ScaleMat = glm::scale(glm::mat4(1.0f), m_Scale);
		RecalculateViewProjection();
	}

	void Camera::Rotate(float angle)
	{
		m_RotationZ = angle;
		m_Rotation = glm::rotate(glm::mat4(1.0f), m_RotationZ, glm::vec3(0.0f, 0.0f, 1.0f));
		RecalculateViewProjection();
	}

	void Camera::RecalculateViewProjection()
	{
		m_ViewProjection = m_Projection * m_View * m_ScaleMat * m_Rotation;
	}

}