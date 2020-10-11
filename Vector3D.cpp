#include "Vector3D.h"

using namespace std;

Vector3D::Vector3D() //constructor
{
  x=0;
  y=0;
  z=0;
  xAngle = 0.0;
  yAngle = 0.0;
  zAngle = 0.0;
  _ptr3d = nullptr;
 // _ptr2d = nullptr;
  set_allAngles();
  object_counter++;
  //cout<< object_counter << ": " <<"in the 3dVector default constructor"<<endl;
}
Vector3D::Vector3D(double x1,double y1,double z1) //initializing object with values.
{
  x=x1;
  y=y1;
  z=z1;
  xAngle = 0.0;
  yAngle = 0.0;
  zAngle = 0.0;
  _ptr3d = nullptr;
 // _ptr2d = nullptr;
  set_magnitude();
  set_allAngles();  
  object_counter++;
	//cout<< object_counter << ": " <<"in the x,y,z constructor" << endl;;
}
Vector3D::Vector3D(const Vector3D &vec)
	: Vector(vec)
{
  x=vec.x;
  y=vec.y;
  z=vec.z;
  xAngle = 0.0;
  yAngle = 0.0;
  zAngle = 0.0;
  _ptr3d = nullptr;
  set_magnitude();
  set_allAngles();
  object_counter++;
//	cout<< object_counter << ": " <<"in the 3dcopy constructor";
}
void Vector3D::setX(double _x)
{
    x = _x;
    set_allAngles();
    set_magnitude();
}
void Vector3D::setY(double _y)
{
    y = _y;
    set_allAngles();
    set_magnitude();
}
void Vector3D::setZ(double _z)
{
    z = _z;
    set_allAngles();
    set_magnitude();
}
void Vector3D::set_xAngle(double _xa)
{
    xAngle = _xa;
    set_allAngles();
    set_magnitude();
}
void Vector3D::set_yAngle(double _ya)
{
    yAngle = _ya;
    set_allAngles();
    set_magnitude();
}
void Vector3D::set_zAngle(double _za)
{
    zAngle = _za;
    set_allAngles();
    set_magnitude();
}
void Vector3D::showAllData()
{
    magnitude = find_magnitude();
    cout<< setprecision(9) << fixed;
  	cout<< "x: " << x << " ";
    cout<< "y: " << y << " ";
    cout<< "z: " << z << endl;
    cout<< "mag: " << magnitude << endl;
    cout << "angles aX: "<< xAngle << ", aY: "<<yAngle<<", aZ: "<<zAngle
         << endl;		
	show_mode();	  
}
void Vector3D::showPolarCord()const
{
    cout << setprecision(9) << fixed << "polar<" << x << ", " << y << ", " << z << ">";
}
void Vector3D::set_allAngles()
{
    xAngle = return_xAngle();
    yAngle = return_yAngle();
    zAngle = return_zAngle();
    //angle = 
}

void Vector3D::set_magnitude()
{
    magnitude = find_magnitude();
}

Vector3D Vector3D::check_division(double d)
{   
    return *this;
}

//addition
Vector3D Vector3D::operator+(const Vector3D &vec)const
{
	cout << "in Vector3D::operator+(const Vector3D &vec)"<<endl;
    return Vector3D(x+vec.x,y+vec.y,z+vec.z);
}
Vector3D Vector3D::operator+(Vector &vec)const
{
	cout << "in Vector3D::operator+(Vector &vec)const "<<endl;
    return Vector3D(x+vec.x,y+vec.y,z);
}

Vector3D &Vector3D::operator+=(const Vector3D &vec)
{
	cout << "in &Vector3D::operator+=(const Vector3D &vec)"<<endl;
    x+=vec.x;
    y+=vec.y;
    z+=vec.z;
    set_allAngles();
    return *this;
}

//substraction//
Vector3D Vector3D::operator-(const Vector3D &vec)
{
    return Vector3D(x-vec.x,y-vec.y,z-vec.z);
}
Vector3D Vector3D::operator-(const double n) const
{
    return Vector3D(x-n, y-n, z-n);
}
Vector3D Vector3D::operator-() const
{
    return Vector3D(-x, -y, -z);
}
Vector3D Vector3D::operator--()
{
    return Vector3D(--x, --y, --z);
}
Vector3D Vector3D::operator--(int)
{
    return Vector3D(x--, y--, z--);
}
Vector3D &Vector3D::operator-=(const Vector3D &vec)
{
    x-=vec.x;
    y-=vec.y;
    z-=vec.z;
    set_allAngles();
    return *this;
}

//scalar multiplication
Vector3D Vector3D::operator*(double value)
{
    return Vector3D(x*value,y*value,z*value);
}
Vector3D &Vector3D::operator*=(double value)
{
    x*=value;
    y*=value;
    z*=value;
    set_allAngles();
    return *this;
}

//scalar division

Vector3D Vector3D::operator/(double d)
{
    return check_division(d);
   
}
Vector3D Vector3D::operator/(int d)
{
    return check_division(d);
   
}

Vector3D &Vector3D::operator/=(double value)
{
  
    x/=value;
    y/=value;
    z/=value;
    set_allAngles();
    return *this;
}

Vector3D&
Vector3D::operator=(const Vector3D& vec)
{
    this->_ptr3d = vec._ptr3d;
    x = vec.x;
    y = vec.y;
    z = vec.z;
    set_allAngles();
	
    return *this;
}

ostream& operator<<(ostream& os, const Vector3D & v)
{	
  if(v.mode == 'R' || v.mode == 'r'){
  	v.showRectCord(); 
  }
  else{
  	v.showPolarCord();
  }  
  return os;
} 


//Dot product
double Vector3D::dot_product(const Vector3D &vec)
{
    return x * vec.x + vec.y * y + vec.z * z;
}
//cross product
Vector3D Vector3D::cross_product(const Vector3D &vec)
{
    double ni=y*vec.z-z*vec.y;
    double nj=z*vec.x-x*vec.z;
    double nk=x*vec.y-y*vec.x;
    return Vector3D(ni,nj,nk);
}
double Vector3D::find_magnitude()
{
    return sqrt(square());
}
double Vector3D::square()
{
    return x*x+y*y+z*z;
}

auto Vector3D::normalization() -> Vector3D
{
    assert(find_magnitude()!=0);
    *this/=find_magnitude();
    return *this;
}


double Vector3D::distance(const Vector3D &vec)
{
    double x1, x2, y1, y2, z1, z2;
    x1 = this->x;
    x2 = vec.x;
    y1 = this->y;
    y2 = vec.y;
    z1 = this->z;
    z2 = vec.z;
    return sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2))); 
}

double Vector3D::returnX()const
{
    return x;
}
double Vector3D::returnY()const
{
    return y;
}
double Vector3D::returnZ()const
{
    return z;
}
double Vector3D::return_xAngle()const
{
    return atan2(sqrt(y * y + z * z), x) * DEGREE;
}
double Vector3D::return_yAngle()const
{
    return atan2(sqrt(x * x + z * z), y) * DEGREE;
}
double Vector3D::return_zAngle()const
{
    return atan2(sqrt(x * x  + y * y), z) * DEGREE;
}
void Vector3D::display()
{
    cout<<x<<" "<<y<<" "<<z<<endl;
}

Vector3D::~Vector3D()
{	
	--object_counter;
    //delete this;
	//cout << "In Vector3D destructor: "<< object_counter << " objects remain\n"
	//		 << endl;
}


