#ifndef _Shape
#define _Shape

class Shape
{
public:
	Shape() {};
	virtual ~Shape() {};	//�����Լ��� ����� �ٰ�! �ֳ� �ڽ� Ŭ������ ����� ���� �θ� ������ ���� �ڽ� �����ڰ� ȣ��Ǿ� ����⶧���� 
	//�Ҹ� �Ҷ��� �ҷ��� �Ѵ�. 
	virtual void draw() const = 0;

};
#endif

