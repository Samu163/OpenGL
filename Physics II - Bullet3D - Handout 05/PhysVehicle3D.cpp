#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;

	wheel.color = Black;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());

	Cube FrontChassis(info.chassis_size2.x, info.chassis_size2.y, info.chassis_size2.z);
	FrontChassis.color = Black;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&FrontChassis.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offsetFront(info.chassis_offset2.x, info.chassis_offset2.y, info.chassis_offset2.z);
	offsetFront = offsetFront.rotate(q.getAxis(), q.getAngle());

	Cube CabinaChassis(info.chassis_size3.x, info.chassis_size3.y, info.chassis_size3.z);
	CabinaChassis.color = White;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&CabinaChassis.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offsetCabina(info.chassis_offset3.x, info.chassis_offset3.y, info.chassis_offset3.z);
	offsetCabina = offsetCabina.rotate(q.getAxis(), q.getAngle());
	//Soportes
	Cube DIzquierdaChassis(info.chassis_size4.x, info.chassis_size4.y, info.chassis_size4.z);
	DIzquierdaChassis.color = Grey;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&DIzquierdaChassis.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offsetDIzquierda(info.chassis_offset4.x, info.chassis_offset4.y, info.chassis_offset4.z);
	offsetDIzquierda = offsetDIzquierda.rotate(q.getAxis(), q.getAngle());

	Cube DDerchaChassis(info.chassis_size5.x, info.chassis_size5.y, info.chassis_size5.z);
	DDerchaChassis.color = Grey;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&DDerchaChassis.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offsetDDercha(info.chassis_offset5.x, info.chassis_offset5.y, info.chassis_offset5.z);
	offsetDDercha = offsetDDercha.rotate(q.getAxis(), q.getAngle());

	Cube AIzquierdaChassis(info.chassis_size6.x, info.chassis_size6.y, info.chassis_size6.z);
	AIzquierdaChassis.color = White;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&CabinaChassis.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offsetAIzquierda(info.chassis_offset6.x, info.chassis_offset6.y, info.chassis_offset6.z);
	offsetAIzquierda = offsetAIzquierda.rotate(q.getAxis(), q.getAngle());

	Cube ADerechaChassis(info.chassis_size7.x, info.chassis_size7.y, info.chassis_size7.z);
	ADerechaChassis.color = White;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&ADerechaChassis.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offsetADerecha(info.chassis_offset7.x, info.chassis_offset7.y, info.chassis_offset7.z);
	offsetADerecha = offsetADerecha.rotate(q.getAxis(), q.getAngle());

	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();

	FrontChassis.transform.M[12] += offsetFront.getX();
	FrontChassis.transform.M[13] += offsetFront.getY();
	FrontChassis.transform.M[14] += offsetFront.getZ();

	CabinaChassis.transform.M[12] += offsetCabina.getX();
	CabinaChassis.transform.M[13] += offsetCabina.getY();
	CabinaChassis.transform.M[14] += offsetCabina.getZ();

	DIzquierdaChassis.transform.M[12] += offsetDIzquierda.getX();
	DIzquierdaChassis.transform.M[13] += offsetDIzquierda.getY();
	DIzquierdaChassis.transform.M[14] += offsetDIzquierda.getZ();

	DDerchaChassis.transform.M[12] += offsetDDercha.getX();
	DDerchaChassis.transform.M[13] += offsetDDercha.getY();
	DDerchaChassis.transform.M[14] += offsetDDercha.getZ();

	AIzquierdaChassis.transform.M[12] += offsetAIzquierda.getX();
	AIzquierdaChassis.transform.M[13] += offsetAIzquierda.getY();
	AIzquierdaChassis.transform.M[14] += offsetAIzquierda.getZ();

	ADerechaChassis.transform.M[12] += offsetADerecha.getX();
	ADerechaChassis.transform.M[13] += offsetADerecha.getY();
	ADerechaChassis.transform.M[14] += offsetADerecha.getZ();


	chassis.Render();
	FrontChassis.Render();
	CabinaChassis.Render();
	DIzquierdaChassis.Render();
	DDerchaChassis.Render();
	AIzquierdaChassis.Render();
	ADerechaChassis.Render();
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}

