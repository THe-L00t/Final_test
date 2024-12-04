#include <iostream>
#include "ShapeManager.h"
using namespace std;

ShapeManager::ShapeManager(int n)
{
	nShape = 0;
	capacity = n;
	shapes = new Shape * [capacity];
}

ShapeManager::~ShapeManager()
{
	delete[] shapes;
}

void ShapeManager::insert(Shape* a)
{
	shapes[nShape] = a;
	nShape++;
}

void ShapeManager::draw() const
{
	cout << "------------------------------------------------" << '\n';
	cout << "�����ϴ� ��� ������ �׸��ϴ�. " << '\n';
	cout << "�ִ� " << capacity << "���� ������ ���� �� �ֽ��ϴ�." << '\n';
	cout << "��� " << nShape << "���� ������ �ֽ��ϴ�." << '\n';
	cout << "------------------------------------------------" << '\n' << '\n';

	for (int i = 0; i < nShape; i++)
	{
		cout << "[" << i << "] ";
		shapes[i]->draw();
	}
	cout << '\n';

	cout << "------------------------------------------------" << '\n';
	cout << "�׸��⸦ ��Ĩ�ϴ�." << '\n';
	cout << "------------------------------------------------" << '\n' << '\n';

}
