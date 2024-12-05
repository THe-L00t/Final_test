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

ShapeManager& ShapeManager::operator=(ShapeManager& other)
{
	capacity = other.capacity + 50;
	nShape = other.nShape;
	delete[] shapes;
	shapes = new Shape * [capacity];
	for (int i = 0; i < nShape; ++i)
	{
		shapes[i] = other.shapes[i];
		other.shapes = nullptr;
	}
	return *this;
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

int ShapeManager::getCapacity()
{
	return capacity;
}

ShapeManager& ShapeManager::updateSM()
{
	//capacity += 100;
	//Shape** temp = new Shape * [capacity];
	//temp = shapes;
	////memcpy(temp, shapes, sizeof(Shape*));
	///*for (int i = 0; i < capacity-100; ++i)
	//{
	//	delete shapes[i];
	//}*/
	//delete[] shapes;
	//shapes = new Shape * [capacity];
	////memcpy(shapes, temp, sizeof(Shape*));
	///*for (int i = 0; i < capacity; ++i)
	//{
	//	delete temp[i];
	//}*/
	
	ShapeManager temp(capacity + 100);
	temp.nShape = nShape;
	for (int i = 0; i < nShape; ++i)
	{
		temp.shapes[i] =shapes[i];
	}
	delete[] shapes;
	return temp;
}
