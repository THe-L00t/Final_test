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

Shape* ShapeManager::operator[](int idx)
{
	return shapes[idx];
}


void ShapeManager::insert(Shape* a)
{
	shapes[nShape] = a;
	nShape++;
}

void ShapeManager::remove(int n)
{
	for (int j = n; shapes[j] != nullptr; ++j)
	{
		if (shapes[n + 1] == nullptr) return;
		if (shapes[n] != shapes[n + 1]) {
			delete shapes[n];
		}
		shapes[n] = shapes[n + 1];
		//shapes[n + 1] = nullptr;
	}
	nShape--;
	/*if (shapes[n + 1] == nullptr) return;
	if (shapes[n] != shapes[n + 1]) {
		delete shapes[n];
	}
	shapes[n] = shapes[n + 1];
	shapes[n + 1] = nullptr;*/
	
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

int ShapeManager::getnShape()
{
	return nShape;
}
