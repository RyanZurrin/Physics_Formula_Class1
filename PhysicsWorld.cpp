#include "PhysicsWorld.h"

//ld PhysicsWorld::_val_ = 0.0;

int PhysicsWorld::physics_objectCount = 0;

/**
 *default constructor
 */
PhysicsWorld::PhysicsWorld()
{
	_ptr_ = nullptr;
	kinematics = new Kinematics;
	drag = new Drag;
	elasticity = new Elasticity;
	friction = new Friction;
	uniformCircularMotion = new UniformCircularMotion;
	vector2d = new Vector;
	vector3d = new Vector3D;
	energy = new Energy;
	momentum = new Momentum;
	torque = new Torque;
	statics = new Statics;
	rotationalMotion = new RotationalMotion;
	temperature = new Temperature;
	heat = new Heat;
	thermodynamic = new Thermodynamics;
	dynamics_and_forces = new DynamicsAndForces;
	fluid_statics = new FluidStatics;
	fluid_dynamics = new FluidDynamics;
	waves = new Waves;
	hearing = new Hearing;
	electric_charge = new ElectricCharge;
	electric_potential = new ElectricPotential;
	electric_current = new ElectricCurrent;
	periodic_elements = new PeriodicElements;
	circuits = new Circuits;
	magnetism = new Magnetism;
	emi = new ElectroMagneticInduction;
	countIncrease();
	//countShow();
}
/**
 *copy constructor
 */
PhysicsWorld::PhysicsWorld(const PhysicsWorld& p)
{
	_ptr_ = p._ptr_;
	//vector_values = p.vector_values;
	kinematics = p.kinematics;
	drag = p.drag;
	elasticity = p.elasticity;
	friction = p.friction;
	vector2d = p.vector2d;
	vector3d = p.vector3d;
	uniformCircularMotion = p.uniformCircularMotion;
	momentum = p.momentum;
	energy = p.energy;
	torque = p.torque;
	statics = p.statics;
	rotationalMotion = p.rotationalMotion;
	temperature = p.temperature;
	heat = p.heat;
	thermodynamic = p.thermodynamic;
	dynamics_and_forces = p.dynamics_and_forces;
	fluid_statics = p.fluid_statics;
	fluid_dynamics = p.fluid_dynamics;
	waves = p.waves;
	hearing = p.hearing;
	electric_charge = p.electric_charge;
	electric_potential = p.electric_potential;
	electric_current = p.electric_current;
	periodic_elements = p.periodic_elements;
	circuits = p.circuits;
	magnetism = p.magnetism;
	emi = p.emi;
	//PhysicsWorld_common = p.PhysicsWorld_common;
	countIncrease();
	//countShow();
}
/**
 *copy assignment operator
 */
PhysicsWorld& PhysicsWorld::operator=(const PhysicsWorld& r)
{
	if(this != &r)
	{
		_ptr_ = r._ptr_;
		//vector_values = r.vector_values;
		kinematics = r.kinematics;
		drag = r.drag;
		elasticity = r.elasticity;
		friction = r.friction;
		vector2d = r.vector2d;
		vector3d = r.vector3d;
		uniformCircularMotion = r.uniformCircularMotion;
		energy = r.energy;
		momentum = r.momentum;
		torque = r.torque;
		statics = r.statics;
		rotationalMotion = r.rotationalMotion;
		temperature = r.temperature;
		heat = r.heat;
		thermodynamic = r.thermodynamic;
		dynamics_and_forces = r.dynamics_and_forces;
		fluid_statics = r.fluid_statics;
		fluid_dynamics = r.fluid_dynamics;
		waves = r.waves;
		hearing = r.hearing;
		electric_charge = r.electric_charge;
		electric_potential = r.electric_potential;
		electric_current = r.electric_current;
		periodic_elements = r.periodic_elements;
		circuits = r.circuits;
		magnetism = r.magnetism;
		emi = r.emi;
		countIncrease();
		//countShow();
	}
	return *this;
}

PhysicsWorld::PhysicsWorld(const ld t1, const ld t2, const ld t3)
{
	_ptr_ = nullptr;
	kinematics = new Kinematics;
	drag = new Drag;
	elasticity = new Elasticity;
	friction = new Friction;
	uniformCircularMotion = new UniformCircularMotion;
	vector2d = new Vector;
	vector3d = new Vector3D;
	energy = new Energy;
	momentum = new Momentum;
	torque = new Torque;
	statics = new Statics;
	rotationalMotion = new RotationalMotion;
	temperature = new Temperature;
	heat = new Heat;
	thermodynamic = new Thermodynamics;
	dynamics_and_forces = new DynamicsAndForces;
	fluid_statics = new FluidStatics;
	fluid_dynamics = new FluidDynamics;
	waves = new Waves;
	hearing = new Hearing;
	electric_charge = new ElectricCharge;
	electric_potential = new ElectricPotential;
	electric_current = new ElectricCurrent;
	periodic_elements = new PeriodicElements;
	circuits = new Circuits;
	magnetism = new Magnetism;
	emi = new ElectroMagneticInduction;

	this->vector3d->set_coordinates(t1, t2, t3);

	countIncrease();
}

PhysicsWorld::PhysicsWorld(const ld t1, const ld t2)
{
	drag = new Drag;
	kinematics = new Kinematics;
	elasticity = new Elasticity;
	friction = new Friction;
	uniformCircularMotion = new UniformCircularMotion;
	vector2d = new Vector;
	vector3d = new Vector3D;
	energy = new Energy;
	momentum = new Momentum;
	torque = new Torque;
	statics = new Statics;
	rotationalMotion = new RotationalMotion;
	temperature = new Temperature;
	heat = new Heat;
	thermodynamic = new Thermodynamics;
	dynamics_and_forces = new DynamicsAndForces;
	fluid_statics = new FluidStatics;
	fluid_dynamics = new FluidDynamics;
	waves = new Waves;
	hearing = new Hearing;
	electric_charge = new ElectricCharge;
	electric_potential = new ElectricPotential;
	electric_current = new ElectricCurrent;
	periodic_elements = new PeriodicElements;
	circuits = new Circuits;
	magnetism = new Magnetism;
	emi = new ElectroMagneticInduction;
	_ptr_ = nullptr;
	this->vector2d->set_coordinates(t1, t2);
}

PhysicsWorld::~PhysicsWorld()
{
	delete kinematics;
	delete elasticity;
	delete friction;
	delete vector2d;
	delete vector3d;
	delete drag;
	delete uniformCircularMotion;
	delete energy;
	delete momentum;
	delete _ptr_;
	delete torque;
	delete statics;
	delete rotationalMotion;
	delete temperature;
	delete heat;
	delete thermodynamic;
	delete dynamics_and_forces;
	delete fluid_statics;
	delete fluid_dynamics;
	delete waves;
	delete hearing;
	delete electric_charge;
	delete electric_potential;
	delete electric_current;
	delete periodic_elements;
	delete circuits;
	delete magnetism;
	delete emi;

	countDecrease();
	//countShow();
}