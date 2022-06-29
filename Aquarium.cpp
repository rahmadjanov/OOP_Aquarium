#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <algorithm>
#include "Fish.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Aquarium Aqua;

	int menu = 1;
	int menu_add;

	while (menu != 0) {

		for (auto obj : Aqua.fsh) {
			if ((obj->GetHealth() < 1) && (obj->type == 0)) {
				obj->SetHealth(0);
				obj->SetState("мёртвая");
			}
		}

		system("clear || cls");
		cout << "0.Выход из программы" << endl;
		cout << "1.Добавить рыбу в аквариум" << endl;
		cout << "2.Добавить улитку в аквариум" << endl;
		cout << "3.Добавить украшение в аквариум" << endl;
		cout << "4.Покормить рыб" << endl;
		cout << "5.Убрать рыбу из аквариума" << endl;
		cout << "6.Убрать улитку из аквариума" << endl;
		cout << "7.Убрать украшения из аквариума" << endl;
		cout << "8.Почистить аквариум" << endl;
		cout << "9.Опустошить аквариум" << endl;
		cout << "10.Вывести информацию об аквариуме" << endl;
		cin >> menu;

		if (menu == 0) {
			break;
		}
		if (menu == 1) {
			system("clear || cls");
			cout << "___________Добавить рыбу___________" << endl;
			cout << "0.Выход в главное меню" << endl;
			cout << "1.Добавить рыбу-полосатика" << endl;
			cout << "2.Добавить рыбу-клоуна" << endl;
			cin >> menu_add;
			switch (menu_add) {
			case 0:
				break;
			case 1:
				system("clear || cls");
				int count;
				cout << "___________Добавить рыбу-полосатика___________" << endl;
				cout << " Количество рыб, которое вы хотите добавить: ";
				cin >> count;
				for (int i = 0; i < count; i++) {
					string f_name;
					cout << endl;
					cout << "Введите кличку рыбы: ";
					cin >> f_name;
					Aqua.Add((fish_all*) new fish(f_name, 30, 2, "рыба-полосатик", "живая"));
					Aqua.fish_number++;
					cout << "Рыба-полосатик" << " " << f_name << " добавлена! " << endl << endl;
				}
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
				break;

			case 2:
				system("clear || cls");
				cout << "___________Добавить рыбу-клоуна________________" << endl;
				cout << " Количество рыб, которое вы хотите добавить: ";
				cin >> count;
				for (int i = 0; i < count; i++) {
					string f_name;
					cout << endl;
					cout << "Введите кличку рыбы: ";
					cin >> f_name;
					Aqua.Add((fish_all*) new fish(f_name, 40, 3, "рыба-клоун", "живая"));
					Aqua.fish_number++;
					cout << "Рыба-клоун" << " " << f_name << " добавлена! " << endl << endl;
				}
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
				break;
			}
		}

		if (menu == 2) {
			system("clear || cls");
			cout << "___________Добавить улитку___________" << endl;
			cout << "0.Выход в главное меню" << endl;
			cout << "1.Добавить улитку-кругляша" << endl;
			cout << "2.Добавить улитку-спиральку" << endl;
			cin >> menu_add;
			switch (menu_add) {
			case 0:
				break;
			case 1:
				system("clear || cls");
				int count;
				cout << "___________Добавить улитку-кругляша___________" << endl;
				cout << " Количество улиток, которое вы хотите добавить: ";
				cin >> count;
				for (int i = 0; i < count; i++) {
					string s_name;
					cout << endl;
					cout << "Введите кличку улитки: ";
					cin >> s_name;
					Aqua.Add((fish_all*) new snail(s_name, 20, "улитка-кругляш", -1));
					Aqua.snail_number++;
					cout << "Улитка-кругляш" << " " << s_name << " добавлена! " << endl << endl;
				}
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
				break;

			case 2:
				system("clear || cls");
				cout << "___________Добавить улитку-спиральку___________" << endl;
				cout << " Количество улиток, которое вы хотите добавить: ";
				cin >> count;
				for (int i = 0; i < count; i++) {
					string s_name;
					cout << endl;
					cout << "Введите кличку улитки: ";
					cin >> s_name;
					Aqua.Add((fish_all*) new snail(s_name, 10, "улитка-спиралька", -1));
					Aqua.snail_number++;
					cout << "Улитка-спиралька" << " " << s_name << " добавлена! " << endl << endl;
				}
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
				break;
			}
			Aqua.Damage_fish();
		}

		if (menu == 3) {
			system("clear || cls");
			cout << "___________Добавить украшение___________" << endl;
			cout << "0.Выход в главное меню" << endl;
			cout << "1.Добавить камень" << endl;
			cout << "2.Добавить водоросли" << endl;
			cin >> menu_add;
			switch (menu_add) {
			case 0:
				break;
			case 1: {
				string color;
				cout << endl;
				cout << "Укажите цвет камня: ";
				cin >> color;
				Aqua.Add((fish_all*) new decor(color, "камень", 2));
				Aqua.decor_number++;
				cout << color << " камень успешно добавлен!" << endl;
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
				break;
			}
			case 2:
				string color;
				cout << endl;
				cout << "Укажите цвет водорослей: ";
				cin >> color;
				cout << endl;
				Aqua.Add((fish_all*) new decor(color, "водоросли", 3));
				Aqua.decor_number++;
				cout << color << " водоросли успешно добавлены!" << endl;
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
				break;
			}
			Aqua.Damage_fish();
		}
		if (menu == 4) {
			system("clear || cls");
			cout << "___________Покормить рыб___________" << endl;
			cout << "0.Выход в главное меню" << endl;
			cout << "1.Покормить кормом Sticks (+2 здоровья)" << endl;
			cout << "2.Покормить кормом TetraMin (+4 здоровья)" << endl;
			cin >> menu_add;
			TetraMin trm;
			Sticks stk;
			switch (menu_add) {
			case 0:
				break;
			case 1:
				for (auto obj : Aqua.fsh) {
					if ((obj->type == 0) && (obj->GetState() == "живая")) {
						obj->SetHealthM(stk.GetNutritionalValue());
						cout << obj->GetType() << " " << obj->GetName() << " " << "успешно покормлена ";
						cout << stk.GetType() << " " << stk.GetName() << "!" << endl;
						Aqua.A_MUD.SetMudFrom(stk.GetMud() + obj->GetMud());
					}
				}
				cout << "Нажмите любую клавишу для продолжения." << endl << endl;
				cout << "_______________________________________________";
				(void)_getch();
				break;
			case 2:
				for (auto obj : Aqua.fsh) {
					if ((obj->type == 0) && (obj->GetState() == "живая")) {
						obj->SetHealthM(trm.GetNutritionalValue());
						cout << obj->GetType() << " " << obj->GetName() << " " << "успешно покормлена ";
						cout << trm.GetType() << " " << trm.GetName() << "!" << endl;
						Aqua.A_MUD.SetMudFrom(trm.GetMud() + obj->GetMud());
					}
				}
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
				break;
			}
		}
		if (menu == 5) {
			system("clear || cls");
			cout << "___________Убрать рыбу из аквариума___________" << endl;
			cout << "0.Выход в главное меню" << endl;
			cout << "1.Убрать всю рыбу" << endl;
			cout << "2.Убрать рыбу по кличке..." << endl << endl;
			cin >> menu_add;
			switch (menu_add) {
			case 0:
				break;
			case 1:
				for (size_t i = 0; Aqua.fsh.size(); i++) {
					if (Aqua.fsh[i]->type == 0) {
						Aqua.Remove(i);
						Aqua.fish_number--;
					}
				}
				Aqua.fsh.clear();
				cout << "Вся рыба успешно извлечена из аквариума! :(" << endl << endl;
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
				break;
			case 2:
				int size1;
				int size2;
				string name;
				size1 = Aqua.fsh.size();
				cout << "Введите кличку рыбы: ";
				cin >> name;
				int i = 0;
				for (auto obj : Aqua.fsh) {
					if ((obj->GetName() == name) && (obj->type == 0)) {
						cout << obj->GetType() << " " << obj->GetName() << " успешно извлечена из аквариума!" << endl << endl;
						Aqua.Remove(i);
						Aqua.fish_number--;
					}
					i++;
					continue;
				}
				size2 = Aqua.fsh.size();
				if (size1 == size2) {
					cout << "Рыба с таким именем не найдена! " << endl;
				}
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
				break;
			}
			Aqua.Damage_fish();
		}
		if (menu == 6) {
			system("clear || cls");
			cout << "___________Убрать улитку из аквариума___________" << endl;
			cout << "0.Выход в главное меню" << endl;
			cout << "1.Убрать всех улиток" << endl;
			cout << "2.Убрать улитку по кличке..." << endl << endl;
			cin >> menu_add;
			switch (menu_add) {
			case 0:
				break;
			case 1:
				for (size_t i = 0; Aqua.fsh.size(); i++) {
					if (Aqua.fsh[i]->type == 1) {
						Aqua.Remove(i);
						Aqua.snail_number--;
					}
				}
				cout << "Все улитки успешно извлечены из аквариума! :(" << endl << endl;
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
				break;
			case 2:
				int size1;
				int size2;
				string name;
				size1 = Aqua.fsh.size();
				cout << "Введите кличку улитки: ";
				cin >> name;
				int i = 0;
				for (auto obj : Aqua.fsh) {
					if ((obj->GetName() == name) && (obj->type == 1)) {
						cout << obj->GetType() << " " << obj->GetName() << " успешно извлечена из аквариума!" << endl << endl;
						Aqua.Remove(i);
						Aqua.snail_number--;
					}
					i++;
					continue;
				}
				size2 = Aqua.fsh.size();
				if (size1 == size2) {
					cout << "Улитка с таким именем не найдена! " << endl;
				}
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
				break;
			}
			Aqua.Damage_fish();
		}
		if (menu == 7) {
			system("clear || cls");
			cout << "___________Убрать украшение из аквариума___________" << endl;
			cout << "0.Выход в главное меню" << endl;
			cout << "1.Убрать все украшения" << endl;
			cout << "2.Убрать камни" << endl;
			cout << "3.Убрать водоросли" << endl << endl;
			cin >> menu_add;
			if (menu_add == 0) {
				break;
			}
			if (menu_add == 1) {
				for (size_t i = 0; Aqua.fsh.size(); i++) {
					if ((Aqua.fsh[i]->type == 2) || (Aqua.fsh[i]->type == 3)) {
						Aqua.Remove(i);
						Aqua.decor_number--;
					}
				}
				cout << "Все украшения извлечены из аквариума! " << endl;
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
			}
			if (menu_add == 2) {
				size_t size1 = Aqua.fsh.size();
				int i = 0;
				for (auto obj : Aqua.fsh) {
					if (obj->type == 2) {
						cout << "Вы успешно извлекли " << obj->GetColor() << " " << obj->GetType() << "! " << endl;
						Aqua.Remove(i);
						Aqua.decor_number--;
					}
					i++;
					continue;
				}
				int size2 = Aqua.fsh.size();
				if (size1 == size2) {
					cout << "Камней не найдено! " << endl;
				}
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
			}
			if (menu_add == 3) {
				size_t size1 = Aqua.fsh.size();
				int i = 0;
				for (auto obj : Aqua.fsh) {
					if (obj->type == 3) {
						cout << "Вы успешно извлекли " << obj->GetColor() << " " << obj->GetType() << "! " << endl;
						Aqua.Remove(i);
						Aqua.decor_number--;
					}
					i++;
					continue;
				}
				int size2 = Aqua.fsh.size();
				if (size1 == size2) {
					cout << "Водорослей не найдено! " << endl;
				}
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
			}
			Aqua.Damage_fish();
		}
		if (menu == 8) {
			system("clear || cls");
			cout << "__________Почистить аквариум__________" << endl;
			cout << endl;

			if (Aqua.snail_number != 0) {
				int i = 0;
				while (Aqua.fsh[i]->type != 1) i++;
				while (Aqua.A_MUD.GetMud() > 0) {
					cout << "#";
					Sleep(100);
					Aqua.A_MUD.SetMudFrom(Aqua.snail_number * Aqua.fsh[i]->GetMud());
				}
				cout << endl;
				for (auto obj : Aqua.fsh) {
					if (obj->type == 1)
						cout << obj->GetType() << " " << obj->GetName() << " почистила аквариум! " << endl;
				}
				cout << endl << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________";
				(void)_getch();
			}
			else {
				cout << "Некому очищать аквариум :( \n Добавьте улиток! " << endl << endl;
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_______________________________________________";
				(void)_getch();
			}
		}
		if (menu == 9) {
			system("clear || cls");
			cout << "__________Опустошить аквариум__________" << endl;
			cout << "0.Выход в главное меню" << endl;
			cout << "1.Опустошить аквариум" << endl;
			bool choise;
			cin >> choise;
			if (choise) {
				for (auto obj : Aqua.fsh) {
					if (obj->type == 0)
						cout << obj->GetState() << " " << obj->GetType() << " " << obj->GetName() << " успешно извлечена!" << endl;
				}
				for (auto obj : Aqua.fsh) {
					if (obj->type == 1)
						cout << obj->GetType() << " " << obj->GetName() << " успешно извлечена!" << endl;
				}
				for (auto obj : Aqua.fsh) {
					if (obj->type == 2) {
						cout << obj->GetColor() << " " << obj->GetType() << " успешно извлечен!" << endl;
					}
					if (obj->type == 3) {
						cout << obj->GetColor() << " " << obj->GetType() << " успешно извлечены!" << endl;
					}
				}
				Aqua.fsh.clear();
				Aqua.fish_number = 0; Aqua.decor_number = 0; Aqua.snail_number = 0;
				cout << endl << "Аквариум успешно опустошен! " << endl;
				cout << "Нажмите любую клавишу для продолжения." << endl;
				cout << "_________________________________";
				(void)_getch();
			}
		}
		if (menu == 10) {
			system("clear || cls");
			cout << "__________Вывести информацию об аквариуме__________" << endl;

			cout << endl << "Рыба: \t" << "Количество рыб: " << Aqua.fish_number << endl;
			for (auto obj : Aqua.fsh) {
				if (obj->type == 0)
					cout << "Тип: " << obj->GetState() << " " << obj->GetType() << " Кличка: "` << obj->GetName() << " Уровень здоровья: " << obj->GetHealth() << endl;
			}

			cout << endl << "Улитки: \t" << "Количество улиток: " << Aqua.snail_number << endl;
			for (auto obj : Aqua.fsh) {
				if (obj->type == 1)
					cout << "Тип: " << obj->GetType() << " Кличка: " << obj->GetName() << " Уровень здоровья: " << obj->GetHealth() << endl;
			}

			cout << endl << "Украшения: \t" << "Количество украшений: " << Aqua.decor_number << endl;
			for (auto obj : Aqua.fsh) {
				if (obj->type == 2) {
					cout << obj->GetColor() << " " << obj->GetType() << endl;
				}
				if (obj->type == 3) {
					cout << obj->GetColor() << " " << obj->GetType() << endl;
				}
			}
			if (Aqua.A_MUD.GetMud() < 0) { Aqua.A_MUD.SetMud(0); }
			cout << "Уровень загрязнения: " << Aqua.A_MUD.GetMud() << endl << endl;
			cout << "Нажмите любую клавишу для продолжения." << endl;
			cout << "_______________________________________________";
			(void)_getch();
		}
	}
}
