#include "Advanced2D.h"

Camera::Camera(void)
{
	p_position = D3DXVECTOR3(0.0f,0.0f,10.0f);
	p_updir = D3DXVECTOR3(0.0f,1.0f,0.0f);

	//hard coded to 1.3333 by default
	float ratio = 640 / 480;
	setPerspective(3.14159f / 4, ratio, 1.0f, 2000.0f);

}

Camera::~Camera(void)
{
}

void Camera::setPerspective(float fov, float aspectRatio, float nearRange, float farRange)
{
	this->setFOV(fov);
	this->setAspectRatio(aspectRatio);
	this->setNearRange(nearRange);
	this->setFarRange(farRange);
}


void Camera::Update()
{
    //set the camera's perspective matrix
    D3DXMatrixPerspectiveFovLH(&this->p_matrixProj, this->p_fov, this->p_aspectRatio, this->p_nearRange, this->p_farRange);
    g_engine->getDevice()->SetTransform(D3DTS_PROJECTION, &this->p_matrixProj);

    //set the camera's view matrix
    D3DXMatrixLookAtLH(&this->p_matrixView, &this->p_position, &this->p_target, &this->p_updir);
    g_engine->getDevice()->SetTransform(D3DTS_VIEW, &this->p_matrixView);
}

void Camera::setPosition(float x, float y, float z)
{
	this->p_position.x = x;
	this->p_position.y = y;
	this->p_position.z = z;
}

void Camera::setPosition(D3DXVECTOR3 position)
{
	this->setPosition(position.x, position.y, position.z);
}

