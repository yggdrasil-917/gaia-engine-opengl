#ifndef MATH_COMMONS_HPP
#define MATH_COMMONS_HPP

#define PI							3.141592653589793238462f
#define PI_OVER_180			0.0174532925f
#define PI_OVER_180_INV 57.295779513082f
#define EPSILON					0.0000001f

template<typename T>
inline void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

inline static float DegreesToRadians(float x)
{
	return x * PI_OVER_180;
}
	
inline static float RadiansToDegrees(float x)
{
	return x * PI_OVER_180_INV;
}
	
#ifndef MAX
#define MAX(a, b) a > b ? a : b
#endif

#ifndef MIN
#define MIN(a, b) a < b ? a : b
#endif

#endif