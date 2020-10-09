#pragma once
typedef long double ld;

class Friction_coefficients
{
	public:
		static ld static_rubber_concrete_dry;
		static ld static_rubber_concrete_wet;
		static ld static_wood_wood;
	
};
ld Friction_coefficients::static_rubber_concrete_dry = 1.0;
ld Friction_coefficients::static_rubber_concrete_wet = 0.7;
ld Friction_coefficients::static_wood_wood = 0.5;
/*
 *ld Physics::val = 0.0;
vector<ld> Physics::vector_values = { 0.0,0.0,0.0,0.0 };
map<string, ld> Physics::static_friction = {
	{"rubber_concrete_dry", 1.0},
	{"rubber_concrete_wet", 0.7},
	{"wood_wood", 0.5},
	{"waxedWood_wetSnow", 0.14},
	{"metal_wood", 0.5},
	{"steel_steel_dry", 0.6},
	{"steel_steel_oiled", 0.05},
	{"teflon_steel", .04},
	{"bone_lubricated_synovial_fluid", .016},
	{"shoes_wood", .9},
	{"shoes_ice", .1},
	{"ice_ice", .1},
	{"steel_ice", .4}
};
map<string, ld> Physics::kinetic_friction = {
	{"rubber_concrete_dry", 0.7},
	{"rubber_concrete_wet", 0.5},
	{"wood_wood", 0.3},
	{"waxedWood_wetSnow", 0.1},
	{"metal_wood", 0.3},
	{"steel_steel_dry", 0.3},
	{"steel_steel_oiled", 0.03},
	{"teflon_steel", .04},
	{"bone_lubricated_synovial_fluid", .015},
	{"shoes_wood", .7},
	{"shoes_ice", .05},
	{"ice_ice", .03},
	{"steel_ice", .04}
};
 *
 * 
 */