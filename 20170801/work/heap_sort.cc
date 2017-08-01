#include <iostream>
#include <cmath>
 
using std::cout;
using std::endl;

#if 1
class Point
{
public:
	Point(int ix=0,int iy =0)
	:_ix(ix)
	,_iy(iy)
	{}
	friend std::ostream & operator <<(std::ostream &os,const Point &rhs);
	friend bool operator <(const Point &lhs,const Point &rhs);
	friend bool operator >(const Point &lhs,const Point &rhs);
	friend bool operator == (const Point &lhs,const Point &rhs);

	float distance()const
	{
		return sqrt(_ix*_ix+_iy*_iy);
	}

private:
	int _ix;
	int _iy;
};

std::ostream & operator <<(std::ostream &os,const Point &rhs)
{
	cout<<"operator << called"<<endl;
	os<<"("<<rhs._ix
	  <<","<<rhs._iy
	  <<")";
	return os;
}

bool operator <(const Point &lhs,const Point &rhs)
{
	cout<<"operator < called..."<<endl;
	return (lhs.distance()<rhs.distance());
}

bool operator >(const Point &lhs,const Point &rhs)
{
	cout<<"operator > called..."<<endl;
	return (lhs.distance()>rhs.distance());
}
#endif

template <typename T,typename Compare = std::less<T> >
class HeapSort
{
public:
	HeapSort(T *arr,int size)
	:_arr(arr)
	,_size(size)
	{
		cout<<"HeapSort(T*,int)"<<endl;
	}

	void swap(int x,int y)
	{
		T tmp;
		tmp = _arr[x];
		_arr[x] = _arr[y];
		_arr[y] = tmp;
	}

	void heapAdjust(int i,int range)
	{
		int tmp,flag = 0;
		while(i*2 <= range && flag == 0)
		{
			if(_arr[i] < _arr[i*2])
				tmp = i*2;
			else
				tmp = i;
			if(i*2+1 <= range)
			{
				//如果右孩子更大,更新较大的结点编号
				if(_arr[tmp] < _arr[i*2+1])
					tmp = i*2+1;
			}
			if(tmp != i)
			{
				swap(tmp,i);
				i = tmp;//交换后更新结点编号,便于继续向下调整
			}else
				flag = 1;//父结点较大，无需继续调整
		}
	}

	void sort()
	{
		int idx;
		for(idx = _size/2; idx >= 1; --idx)
		{
			heapAdjust(idx,_size);
		}

		for(idx = _size;idx >=1;--idx)
		{
			swap(1,idx);
			heapAdjust(1,idx-1);
		}
	}

	void disp()
	{
		for(int idx = 1;idx <= _size; ++idx)
		{
			cout<<_arr[idx]<<" ";
		}
		cout<<endl;
	}

private:
	T *_arr;
	int _size;
};

int main(void)
{
	//从下标为1的元素开始排序
	Point parr[6]={Point(0,0),Point(1,2),Point(-1,3),Point(3,4),Point(-1,0),Point(1,0)};
	HeapSort<Point> hpPoint(parr,5);
	hpPoint.sort();
	for(int idx = 1;idx <=5; ++idx)
		cout<<parr[idx]<<endl;

//	int arr[11]={0,2,5,1,4,3,9,7,10,6,8};
//	HeapSort<int> hp(arr,10);
//	hp.sort();
//	hp.disp();
	
//	string s[6] = {"0","hello","B","D","A","C"};
//	HeapSort<string> hps(s,5);
//	hps.sort();
//	hps.disp();
}
