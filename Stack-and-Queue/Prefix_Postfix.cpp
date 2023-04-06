#include <iostream>						//Подключение библиотеки ввода-вывода
#include <string>
using namespace std;


struct stack {							//Стек описывается как struct следующим образом
	char inf;
	stack* next;
};


void push(stack*& h, char x) {			//Функция добавления элемента в стек
	stack* r = new stack;				//Создаём новый элемент
	r->inf = x;							//Информационное поле inf = x
	r->next = h;						//Cледующим элементов является h
	h = r;								//Теперь r является головой
}


char pop(stack*& h) {					//Функция удаления элемента из стека (и возвращение его значения)
	int i = h->inf;						//Значение первого элемента
	stack* r = h;						//Указатель на голову стека
	h = h->next;						//Переносим указатель на следующий элемент
	delete r;							//Удаляем первый элемент
	return i;							//Возвращаем значение
}


void reverse(stack*& h) {				//Функция "обращения" стека
	stack* head1 = NULL;				//Инициализация буферного стека
	while (h)							//Пока стек не пуст
		push(head1, pop(h));			//Переписываем из одного стека в другой
	h = head1;							//Переобозначаем указатели
}


int prior(char &a) {
	if (a == '(') {
		return 1;
	}
	else if (a == '+' || a == '-') {
		return 2;
	}
	else if (a == '*' || a == '/') {
		return 3;
	}
	else if (isdigit(a)) {
		return 4;
	}
	else if (a == ' ') {
		return 5;
	}
	else {
		return 6;
	}

}


int main() {							//Главная функция
	setlocale(LC_ALL, "RUS");

	string str, result_str = "";
	cout << "Выражение в инфиксной форме:" << endl;
	getline(cin, str);
	//str += '.';
	cout << str << endl;
	stack* head = NULL;					//Инициализация

	for (size_t i = 0; i < str.size(); i++) {
		char a = str[i];
		cout << "a = " << a << endl;
		if (a == ' ') {
			cout << "pustota" << endl;
			continue;
		}
		if (isdigit(a)) {
			result_str += a;
			cout << "result_str = " << result_str << endl;
		}
		if (a == '(') {
			cout << "(" << endl;
			push(head, a);
		}
		if ((a == '+' || a == '-' || a == '*' || a == '/') && !head) {
			cout << "+-*/!" << endl;
			push(head, a);
		}
		if (a == ')') {
			cout << ")" << endl;
			while (head->inf != '(') {
				char s = pop(head);
				result_str += s;
			}
			//извлекаем закрывающую скобку
		}
		if (a == '+' || a == '-' || a == '*' || a == '/') {
			cout << "davau" << endl;
			if (prior(a) > prior(head->inf)) {
				push(head, a);
			}
		
			else {
				cout << "nu davai" << endl;
				while (prior(a) <= prior(head->inf)) {
					char s = pop(head);
					result_str += s;
					cout << "result_str = " << result_str << endl;
				}
				push(head, a);
			}
		}
		cout << "prohod" << endl;
	}

	while (head) {
		cout << "nuuuuuu" << endl;
		char s = pop(head);
		result_str += s;
	}
	
	cout << "Ответ: " << endl;
	cout << result_str << endl;

	system("Pause");					//Пауза
	return 0;							//Конец программы
}
