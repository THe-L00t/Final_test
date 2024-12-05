#ifndef _Shape
#define _Shape

class Shape
{
public:
	Shape() {};
	virtual ~Shape() {};	//가상함수로 만들어 줄것! 왜냐 자식 클래스가 만들어 질때 부모 생성자 이후 자식 생성자가 호출되어 생기기때문에 
	//소멸 할때도 불려야 한다. 
	virtual void draw() const = 0;

};
#endif

