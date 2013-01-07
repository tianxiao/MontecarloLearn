//Vector_impl.h
//Contains implementation for the Vector class template

namespace CDLib
{
	//============================================================================
	//Default and Copy Constructor
	//============================================================================
	template <int N, class T> Vector<N,T>::Vector()
	{
	}


	template <int N, class T> Vector<N,T>::Vector(const Vector& v)
	{
		this->assign(v);
	}
	

	//============================================================================
	//Assignment
	//============================================================================

	template<int n,class T> Vector<n,T>& Vector<n,T>::operator= (const Vector<n,T>& d)
	{
		this->assign(d);
		return *this;
	}

	template <int n, class T> Vector<n,T>& Vector<n,T>::assign(const Vector<n,T>& d)
	{
		for(int i=0; i<n; i++)
		{
			data[i] = (T)d[i];
		}
		return *this;
	}

	template <int n, class T> Vector<n,T>& Vector<n,T>::assign(const T *d)
	{
		for(int i=0; i<n; i++) (*this)[i] = d[i];
		return *this;
	}
			
	template <int n, class T> Vector<n,T>& Vector<n,T>::assign(const std::vector<T> d)
	{
		for(int i=0; i<n; i++) (*this)[i] = d[i];
		return *this;
	}

	template <int n, class T> Vector<n,T>& Vector<n,T>::assign(T a1, T a2)
	{
		data[0] = a1;
		data[1] = a2;	
		return *this;
	}
	
	template <int n, class T> Vector<n,T>& Vector<n,T>::assign(T a1, T a2, T a3)
	{
		assign(a1, a2);
		data[2] = a3;
		return *this;
	}
	
	template <int n, class T> Vector<n,T>& Vector<n,T>::assign(T a1, T a2, T a3, T a4)
	{
		assign(a1, a2, a3);
		data[3] = a4;
		return *this;
	}


	//=============================================================================
	//Accessors
	//=============================================================================
	template <int N, class T> const T* Vector<N,T>::array() const { return data; }
	template <int N, class T> T* Vector<N,T>::start() const { return data; }
	template <int N, class T> T* Vector<N,T>::end() const { return &data + N; }

	template <int N, class T> void Vector<N,T>::copyTo(T* d) const
	{
		memcpy(d, data, sizeof(T)*N);
	}
	
	template <int N, class T> void Vector<N,T>::copyTo(std::vector<T>& d) const
	{
		for(int i=0; i<N; i++) d.push_back(data[i]);
	}

	template <int n, class T> void Vector<n,T>::copyTo(Vector<n,T>& v) const
	{
		copyTo(v.data);	
	}

	template <int N, class T> const T& Vector<N,T>::operator [] (int i) const
	{
		return data[i];
	}

	template <int N, class T> const T& Vector<N,T>::x() const { return data[0]; };
	template <int N, class T> const T& Vector<N,T>::y() const { return data[1]; };
	template <int N, class T> const T& Vector<N,T>::z() const { return data[2]; };
	template <int N, class T> const T& Vector<N,T>::w() const { return data[3]; };
	template <int N, class T> const T& Vector<N,T>::r() const { return data[0]; };
	template <int N, class T> const T& Vector<N,T>::g() const { return data[1]; };
	template <int N, class T> const T& Vector<N,T>::b() const { return data[2]; };
	template <int N, class T> const T& Vector<N,T>::a() const { return data[3]; };

	template <int N, class T> T& Vector<N,T>::operator [] (int i)
	{
		return data[i];
	}

	template <int N, class T>  T& Vector<N,T>::x()  { return data[0]; };
	template <int N, class T>  T& Vector<N,T>::y()  { return data[1]; };
	template <int N, class T>  T& Vector<N,T>::z()  { return data[2]; };
	template <int N, class T>  T& Vector<N,T>::w()  { return data[3]; };
	template <int N, class T>  T& Vector<N,T>::r()  { return data[0]; };
	template <int N, class T>  T& Vector<N,T>::g()  { return data[1]; };
	template <int N, class T>  T& Vector<N,T>::b()  { return data[2]; };
	template <int N, class T>  T& Vector<N,T>::a()  { return data[3]; };

	template <int N, class T> std::string Vector<N,T>::toString() const
	{
		std::strstream str;
		str << *this;
		return std::string( str.str() );
	}

	template <int N, class T> 
	std::ostream& operator<< (std::ostream& str, const Vector<N,T>& v)
	{
		str << "( ";
		for(int i=0; i<N; i++)
		{
			str << v[i];
			str << " ";
		}
		str << ")";
		return str;
	}
	
	//=============================================================================
	//Static Targeted Operator Functions 
	//=============================================================================
	template<int n, class T> Vector<n,T> operator + (const Vector<n,T>& lhs, const Vector<n,T>& rhs)
	{
		Vector<n,T> v;
		return add(v, lhs, rhs);
	}
	
	template<int n, class T> Vector<n,T> operator - (const Vector<n,T>& lhs, const Vector<n,T>& rhs)
	{
		Vector<n,T> v;
		return sub(v, lhs, rhs);
	}
	
	template<int n, class T> Vector<n,T> operator * (T c, const Vector<n,T>& v)
	{
		Vector<n,T> x;
		return mul(x, v, c);
	}
	
	template<int n, class T> Vector<n,T> operator * (const Vector<n,T>& v, T c)
	{
		Vector<n,T> x;
		return mul(x, v, c);
	}
	
	template<int n, class T> Vector<n,T> operator / (const Vector<n,T>& v, T c)
	{
		Vector<n,T> x;
		return div(x, v, c);
	}

	template<int n, class T> Vector<n,T> operator - (const Vector<n,T>& lhs)
	{
		Vector<n,T> x;
		return mul(x, lhs, (T)-1.0);
	}


	template<int n, class T> bool operator == (const Vector<n,T>& lhs, const Vector<n,T>& rhs)
	{
		for(int i=0; i<n; i++) if( lhs[i] != rhs[i] ) return false;
		return true;
	}

	template<int n, class T> bool operator != (const Vector<n,T>& lhs, const Vector<n,T>& rhs)
	{
		for(int i=0; i<n; i++) if( lhs[i] == rhs[i] ) return false;
		return true;
	}

	//=============================================================================
	//Static Targeted Operator Functions 
	//=============================================================================
	template <int n, class T> 
	Vector<n,T>& add(Vector<n,T>& target, const Vector<n,T>& lhs, const Vector<n,T>& rhs)
	{
		double d;
		for(int i=0; i<n; i++) 
		{
			d = lhs[i] + rhs[i];
			target[i] = d;
		}
		return target;
	}
	
	template <int n, class T> 
	Vector<n,T>& sub(Vector<n,T>& target, const Vector<n,T>& lhs, const Vector<n,T>& rhs)
	{
		for(int i=0; i<n; i++) target[i] = lhs[i] - rhs[i];
		return target;
	}

	template <int n, class T> 
	Vector<n,T>& mul(Vector<n,T>& target, const Vector<n,T>& v, T c)
	{
		for(int i=0; i<n; i++) target[i] = v[i] * c;
		return target;
	}

	template <int n, class T> 
	Vector<n,T>& div(Vector<n,T>& target, const Vector<n,T>& v, T c)
	{
		mul(target, v, 1/c);
		return target;
	}
	
	template<int n, class T> bool almost_equals(const Vector<n,T>& lhs, const Vector<n,T>& rhs, T delta)
	{
		for(int i=0; i<n; i++) 	
			if( abs(lhs[i] - rhs[i]) > delta ) return false;
			else return true;
			
	}

	template<int n, class T> bool strongly_unequals(const Vector<n,T>& lhs, const Vector<n,T>& rhs, T delta)
	{
		for(int i=0; i<n; i++) 	
			if( abs(lhs[i] - rhs[i]) < delta ) return false;
			else return true;
	}

	template <int N, class T>
	T dot(const Vector<N,T>& lhs, const Vector<N,T>& rhs)
	{
		T dot = 0;
		for(int i=0; i<N; i++) dot += lhs[i] * rhs[i];
		return dot;
	}

	template <int N, class T>
	Vector<N,T>& cross(Vector<N,T>& target, const Vector<N,T>& lhs, const Vector<N,T>& rhs)
	{
		target[0] = lhs[1]*rhs[2] - lhs[2]*rhs[1];
		target[1] = lhs[0]*rhs[2] - lhs[2]*rhs[0];
		target[2] = lhs[0]*rhs[1] - lhs[1]*rhs[0];
		return target;
	}

	template <int N, class T> T norm(const Vector<N,T>& v)
	{
		return sqrt(dot(v,v));
	}

	template <int N, class T> T normSq(const Vector<N,T>& v)
	{
		return dot(v, v);
	}


	template <int N, class T> T norm1(const Vector<N,T>& v)
	{
		T n = 0;
		for(int i=0; i<N; i++) n += fabs(v[i]);
		return n;
	}

	template <int n, class T> T normInf(const Vector<n,T>& v)
	{
		T d = v[0];	
		for(int i=1; i<n; i++) d = max(d, v[i]);
		return n;
	}

	template <int n, class T> T normMin(const Vector<n,T>& v)
	{
		T d = v[0];	
		for(int i=1; i<n; i++) d = min(d, v[i]);
		return n;
	}


	template <int N, class T> T distance(const Vector<N,T>& a, const Vector<N,T>& b)
	{
		return sqrt(distanceSq(a, b));
	}

	template <int N, class T> T distanceSq(const Vector<N,T>& a, const Vector<N,T>& b)
	{
		T d=0;
		for(int i=0; i<N; i++) d += (a[i] - b[i]) * (a[i] - b[i]);
		return d;
	}

	template <int N, class T> T angle(const Vector<N,T>& a, const Vector<N,T>& b)
	{
		return acos(angleCos(a, b));
	}

	template <int N, class T> T angleCos(const Vector<N,T>& a, const Vector<N,T>& b)
	{
		T d = dot(a, b);
		return d / ( norm(a) * norm(b) );
	}


}
