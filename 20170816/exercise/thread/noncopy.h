#ifndef __NONCOPY_H__
#define __NONCOPY_H__

namespace wd
{
class Noncopy
{
protected:
	Noncopy(){}
	~Noncopy(){}

private:
	Noncopy(const Noncopy &);
	Noncopy & operator = (const Noncopy &);
};
}//end of namespace wd

#endif
