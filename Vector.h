#ifndef _CDLIB_VECTOR
#define _CDLIB_VECTOR
#include "stdafx.h"
#include <vector>
#include <string>
#include <strstream>
#include <complex>
#include <assert.h>
//#include <cblas.h>
#include "Utility.h"

namespace CDLib
{
	
	
	template <int n, class T = double>
	class Vector
	{
	public:
		//Default and Copy Constructor
		Vector();
		Vector(const Vector& v);
		explicit Vector(const T* d) { assign(d); }
		Vector(T x, T y) { assert(n >= 2); assign(x, y); }
		Vector(T x, T y, T z) { assert(n >= 3); assign(x, y, z); }
		Vector(T x, T y, T z, T w) { assert(n >= 4); assign(x, y, z, w); }

		//Assignment 
		Vector<n,T>& operator= (const Vector<n,T>& d);
		Vector<n,T>& assign(const Vector<n,T>& d);
		Vector<n,T>& assign(const T *d);
		Vector<n,T>& assign(const std::vector<T> d);
		Vector<n,T>& assign(T a1, T a2);
		Vector<n,T>& assign(T a1, T a2, T a3);
		Vector<n,T>& assign(T a1, T a2, T a3, T a4);

		//Accessors
		const T* array() const;
		T* start() const;
		T* end() const;
		
		void copyTo(T* d) const;
		void copyTo(std::vector<T>& d) const;
		void copyTo(Vector<n,T>& v) const;
		
		T& operator [] (int i) ;
		T& x() ;
		T& y() ;
		T& z() ;
		T& w() ;
		T& r() ;
		T& g() ;
		T& b() ;
		T& a() ;

		const T& operator [] (int i) const;
		const T& x() const;
		const T& y() const;
		const T& z() const;
		const T& w() const;
		const T& r() const;
		const T& g() const;
		const T& b() const;
		const T& a() const;

		Vector<2, T> swizzle(int a, int b){return Vector<2,T>((*this)[a],(*this)[b]);}
		Vector<3, T> swizzle(int a, int b, int c){return Vector<3,T>((*this)[a],(*this)[b], (*this)[c]);}
		Vector<4, T> swizzle(int a, int b, int c, int d)
		{return Vector<4,T>((*this)[a],(*this)[b],(*this)[c],(*this)[d]);}

		std::string toString() const;
		
		//Modifying Operators - Generic
		Vector<n,T>& operator += (const Vector<n,T>& v);
		Vector<n,T>& operator -= (const Vector<n,T>& v);
		Vector<n,T>& operator *= (T v);
		Vector<n,T>& operator /= (T v);

	private:
		T data[n];
	};

	//Static Operators - Generic
	template<int n, class T> Vector<n,T> operator + (const Vector<n,T>& lhs, const Vector<n,T>& rhs);
	template<int n, class T> Vector<n,T> operator - (const Vector<n,T>& lhs, const Vector<n,T>& rhs);
	template<int n, class T> Vector<n,T> operator * (T c, const Vector<n,T>& v);
	template<int n, class T> Vector<n,T> operator * (const Vector<n,T>& v, T c);
	template<int n, class T> Vector<n,T> operator / (const Vector<n,T>& v, T c);
	template<int n, class T> std::ostream& operator<< (std::ostream& stream, const Vector<n,T>& v);

	template<int n, class T> Vector<n,T> operator - (const Vector<n,T>& lhs);

	template<int n, class T> bool operator == (const Vector<n,T>& lhs, const Vector<n,T>& rhs);
	template<int n, class T> bool operator != (const Vector<n,T>& lhs, const Vector<n,T>& rhs);

	//Static Targeted Operator Functions - Generic
	//The operators are written in terms of these functions
	/*
	template <int N, class T> Vector<N,T>& add(Vector<n,T>& target, const Vector<n,T>& lhs, const Vector<n,T>& rhs);
	template <int N, class T> Vector<N,T>& sub(Vector<n,T>& target, const Vector<n,T>& lhs, const Vector<n,T>& rhs);
	template <int N, class T> Vector<N,T>& mul(Vector<n,T>& target, const Vector<n,T>& v, T c);
	template <int N, class T> Vector<N,T>& div(Vector<n,T>& target, const Vector<n,T>& lhs, T rhs);
	*/
	
	template<int n, class T> bool almost_equals(const Vector<n,T>& lhs, const Vector<n,T>& rhs, T delta);
	template<int n, class T> bool strongly_unequals(const Vector<n,T>& lhs, const Vector<n,T>& rhs, T delta);

	template <int N, class T> T dot(const Vector<N,T>& lhs, const Vector<N,T>& rhs);
	template <int N, class T> Vector<N,T>& cross(Vector<N,T>& target, const Vector<N,T>& lhs, const Vector<N,T>& rhs);
	template <int n, class T> Vector<n,T> cross(Vector<n,T> lhs, Vector<n,T> rhs)
	{
		Vector<n,T> temp;
		cross(temp, lhs, rhs);
		return temp;
	}

	template <int N, class T> T norm(const Vector<N,T>& v);
	template <int N, class T> T normSq(const Vector<N,T>& v);
	template <int N, class T> T norm1(const Vector<N,T>& v);
	template <int N, class T> T normInf(const Vector<N,T>& v);
	template <int N, class T> T normMin(const Vector<N,T>& v);

	template <class T> Vector<3,T> normal(Vector<3,T> a, Vector<3,T> b, Vector<3,T> c)
	{
		return normalize(cross(c - a, b - a));
	}
	
	template <int N, class T> Vector<N,T> normalize(const Vector<N,T>& v) 
	{ 
		T n = norm(v);
		return v / n; 
	}

	template <int N, class T> T distance(const Vector<N,T>& a, const Vector<N,T>& b);
	template <int N, class T> T distanceSq(const Vector<N,T>& a, const Vector<N,T>& b);

	template <int N, class T> T angle(const Vector<N,T>& a, const Vector<N,T>& b);
	template <int N, class T> T angleCos(const Vector<N,T>& a, const Vector<N,T>& b);

	//Important Typedefs
	typedef Vector<1, float> Vector1f;
	typedef Vector<2, float> Vector2f;
	typedef Vector<3, float> Vector3f;
	typedef Vector<4, float> Vector4f;

	typedef Vector<1, double> Vector1d;
	typedef Vector<2, double> Vector2d;
	typedef Vector<3, double> Vector3d;
	typedef Vector<4, double> Vector4d;

	typedef Vector< 1, std::complex<float> > Vector1c;
	typedef Vector< 2, std::complex<float> > Vector2c;
	typedef Vector< 3, std::complex<float> > Vector3c;
	typedef Vector< 4, std::complex<float> > Vector4c;
		
	typedef Vector< 1, std::complex<double> > Vector1z;
	typedef Vector< 2, std::complex<double> > Vector2z;
	typedef Vector< 3, std::complex<double> > Vector3z;
	typedef Vector< 4, std::complex<double> > Vector4z;

	typedef Vector<1, int> Vector1i;
	typedef Vector<2, int> Vector2i;
	typedef Vector<3, int> Vector3i;
	typedef Vector<4, int> Vector4i;

};

#include "Vector_impl.h"

#endif

