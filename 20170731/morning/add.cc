//对于模板而言，可以分成头文件和实现文件 ，但在引用的时候，必须要能够看到实现

template <typename T>
T add(T a,T b)
{
	return a + b;
}

