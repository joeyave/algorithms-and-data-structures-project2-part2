// lab2_db.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include "Node.h"

int main()
{
	std::cout << "Create a list. Write 'stop' to stop." << std::endl;
	create(&list1_head);

	std::cout << std::endl << "Choose the option below. Write 'print' to print a list." << std::endl;
	std::cout << "1. Add a node at the front of the list." << std::endl;
	std::cout << "2. Add a node after a given node." << std::endl;
	std::cout << "3. Add a node at the end of the list." << std::endl;
	std::cout << "4. Delete a node at the given position." << std::endl;
	std::cout << "5. Delete every Nth node." << std::endl;
	std::cout << "6. Delete a list." << std::endl;
	std::cout << "7. Sort a list." << std::endl;
	std::cout << "8. Get union of two lists." << std::endl;
	std::cout << "9. Get intersection of two lists." << std::endl;
	std::cout << "10. Move node by N." << std::endl;
	std::cout << "11. Clone a list." << std::endl;

	while (true)
	{
		std::cout << std::endl << "Your choice: ";

		std::string ans;
		std::cin >> ans;

		if (ans == "1")
		{
			std::cout << "Input integer to push: ";
			int n;
			std::cin >> n;

			push(&list1_head, n);
			continue;
		}

		if (ans == "2")
		{
			std::cout << "Input integer to add: ";
			int new_data;
			std::cin >> new_data;

			std::cout << "Input index of the previous node: ";
			int index;
			std::cin >> index;

			insert_after(&list1_head, index, new_data);
			continue;
		}

		if (ans == "3")
		{
			std::cout << "Input integer to append: ";
			int n;
			std::cin >> n;

			append(&list1_head, n);
			continue;
		}

		if (ans == "4")
		{
			std::cout << "Input index of the node to be deleted: ";
			int n;
			std::cin >> n;

			delete_node_by_index(&list1_head, n);
			continue;
		}

		if (ans == "5")
		{
			std::cout << "Input n: ";
			int n;
			std::cin >> n;

			delete_every_nth_node(&list1_head, n);
			continue;
		}

		if (ans == "6")
		{
			std::cout << "Are you sure?" << std::endl;
			std::string ans;
			std::cin >> ans;

			if (ans == "yes")
				delete_list(&list1_head);

			continue;
		}

		if (ans == "7")
		{
			merge_sort(&list1_head);

			continue;
		}

		if (ans == "8")
		{
			std::cout << std::endl << "Create second list. Write 'stop' to stop." << std::endl;
			create(&list2_head);

			Node* union_list_head = get_union(list1_head, list2_head);
			print(union_list_head);
		}

		if (ans == "9")
		{
			std::cout << std::endl << "Create second list. Write 'stop' to stop." << std::endl;
			create(&list3_head);

			Node* intersection_list_head = get_intersection(list1_head, list3_head);
			print(intersection_list_head);
		}

		if (ans == "10")
		{
			std::cout << "Input index of the node to move: ";
			int index;
			std::cin >> index;

			std::cout << "Input N: ";
			int n;
			std::cin >> n;

			move_node(&list1_head, index, n);
		}

		if (ans == "11")
		{
			Node* clone_head = clone_list(list1_head);

			print(clone_head);
		}

		if (ans == "print")
		{
			std::cout << "What list to print?" << std::endl;
			std::string ans;
			std::cin >> ans;

			print(list1_head);

			std::cout << std::endl;
		}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
