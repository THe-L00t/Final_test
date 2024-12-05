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
	cout << "관리하는 모든 도형을 그립니다. " << '\n';
	cout << "최대 " << capacity << "개의 도형을 담을 수 있습니다." << '\n';
	cout << "모두 " << nShape << "개의 도형이 있습니다." << '\n';
	cout << "------------------------------------------------" << '\n' << '\n';

	for (int i = 0; i < nShape; i++)
	{
		cout << "[" << i << "] ";
		shapes[i]->draw();
	}
	cout << '\n';

	cout << "------------------------------------------------" << '\n';
	cout << "그리기를 마칩니다." << '\n';
	cout << "------------------------------------------------" << '\n' << '\n';

}

int ShapeManager::getnShape()
{
	return nShape;
}
