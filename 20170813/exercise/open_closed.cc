#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

enum ShapeType
{
	circle,square
};

struct Shape
{
	ShapeType itsType;
};

struct Square
{
	ShapeType itsType;
	double itsSide;
	Point itsTopLeft;
};

struct Circle
{
	ShapeType itsType;
	double itsRadius;
	Point itsCenter;
};

void DrawSquare(struct Square*);
void DrawCircle(struct Circle*);
typedef struct Shape *ShapePointer;

void DrawAllShapes(ShapePointer list[],int n)
{
	int i;
	for(i = 0;i < n;i++)
	{
		struct Shape* s = list[i];
		switch(s->itsType)
		{
			case square:
				DrawSquare((struct Square*)s);
				break;
			case circle:
				DrawCircle((struct Circle*)s);
				break;
		}
	}
}

int main(void)
{
}
