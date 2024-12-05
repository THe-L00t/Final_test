//������ ����.cpp
#include <iostream>

#include "Point.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeManager.h"

int main()
{
	bool exit{ false }, back{false};
	int menu{}, sel{}, x[3]{}, y[3]{}, num{};
	double dx{}, dy{}, r{};
	ShapeManager sm(100);

	sm.insert(new Triangle());
	sm.insert(new Triangle(Point(0, 0), Point(1, 1), Point(2, 2)));
	sm.insert(new Circle(Point(1.23, 4.56), 7.89));

	for (int i = 0; i < 10; i++)
	{
		sm.insert(new Rectangle(Point(i, i + 1), Point(i * 2, i * 3)));
	}

	while (not exit) {
		std::cout << "--Menu--" << std::endl << std::endl;
		std::cout << "1. ���ϴ� ���� �߰�" << std::endl;
		std::cout << "2. ��ü ������ �׸���" << std::endl;
		std::cout << "3. ���� �����" << std::endl;
		std::cout << "4. ���α׷� ������" << std::endl;
		std::cin >> menu;
		if (menu == 1){
			while (not back) {
				system("cls");
				std::cout << "������ �����ϼ���." << std::endl << std::endl;
				std::cout << "1. �ﰢ��" << std::endl;
				std::cout << "2. �簢��" << std::endl;
				std::cout << "3. ��" << std::endl;
				std::cout << "4. �ڷΰ��� " << std::endl;
				std::cin >> sel;
				if (sel == 1) {
					system("cls");
					std::cout << "�� ���� ��ǥ�� �Է��ϼ���." << std::endl;
					std::cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
					sm.insert(new Triangle(Point(x[0],y[0]), Point(x[1], y[1]), Point(x[2], y[2])));
					back = true;
				}
				else if (sel == 2) {
					system("cls");
					std::cout << "�� ���� ��ǥ�� �Է��ϼ���." << std::endl;
					std::cin >> x[0] >> y[0] >> x[1] >> y[1];
					sm.insert(new Rectangle(Point(x[0], y[0]), Point(x[1], y[1])));
					back = true;
				}
				else if (sel == 3) {
					system("cls");
					std::cout << "���� �߽� ��ǥ�� �������� �Է��ϼ���." << std::endl;
					std::cin >> dx >> dy >> r;
					sm.insert(new Circle(Point(dx, dy), r));
					back = true;
				}
				else if (sel == 4) { 
					
					back = true; 
				}
				else std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			}
		}
		else if (menu == 2) { 
			system("cls"); 
			sm.draw(); 
		}
		else if (menu == 3) {
			system("cls");
			std::cout << "��� ������� ������ �����ұ��?" << std::endl;
			std::cout << "1. �� ��° ������ �����ұ��?" << std::endl;
			std::cout << "2. � ������ �����ұ��?" << std::endl;
			std::cin >> menu;
			if (menu == 1) {
				std::cout << "�� ��° ������ �����ұ��?" << std::endl;
				std::cin >> num;
				if (sm[num] == nullptr) std::cout << "�߸��� �Է��Դϴ�." << std::endl;
				/*for (int i = num; sm[i-1] != nullptr; ++i)
				{*/
				sm.remove(num);
				//}
			}
			else if (menu == 2) {
				std::cout << "� ������ �����ұ��?" << std::endl;
				std::cout << "1. �ﰢ��" << std::endl;
				std::cout << "2. �簢��" << std::endl;
				std::cout << "3. ��" << std::endl;
				std::cin >> num;
				if (num == 1) {
					for (int i = 0; i <=sm.getnShape(); ++i)
					{
						if (dynamic_cast<Triangle*>(sm[i]) != nullptr) {	//dynamic_cast �߿��� �ٿ� ĳ���� �ص� �Ǵ��� Ȯ��
								sm.remove(i);
						}
					}
				}
				else if (num == 2) {
					for (int i = 0; i <= sm.getnShape(); ++i)
					{
						if (dynamic_cast<Rectangle*>(sm[i]) != nullptr) {
							
								sm.remove(i);
							
						}
					}
				}
				else if (num == 3) {
					for (int i = 0; i <= sm.getnShape(); ++i)
					{
						if (dynamic_cast<Circle*>(sm[i]) != nullptr) {
							
								sm.remove(i);
							
						}
					}
				}
				else std::cout << "�߸��� �Է��Դϴ�." << std::endl;

			}
			else std::cout << "�߸��� �Է��Դϴ�. " << std::endl;
		}
		else if (menu == 4) { 
			exit = true; 
		}
		else std::cout << " �߸��� �Է��Դϴ�. " << std::endl;
		back = false;
		//system("cls");
		for (int i = 0; i < 100; i++)
		{
			if (sm.getnShape() >= sm.getCapacity()) {
				sm.updateSM();
			}
			sm.insert(new Rectangle(Point(i, i + 1), Point(i * 2, i * 3)));
		}
		
	}

	sm.draw();

}


