// OOP_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class String
{
	char* text = nullptr;
	unsigned int length = 0;
	unsigned int capacity = 80;

public:
	String() : String("", 80) {}

	String(const char* text) : String(text, 80) {}

	String(unsigned int capacity) : String("", capacity) {}

	String(const String& original) : String(original.text, original.capacity) {}

	String(const char* text, unsigned int capacity)
	{
		SetString(text, capacity);
	}

	~String()
	{
		if (text != nullptr)
		{
			delete[] text;
			text = nullptr;
		}
	}

	String GetString() const
	{
		String copy = text;
		return copy;
	}

	void SetString(const char* text, unsigned int capacity = 80)
	{
		length = strlen(text);

		if (capacity <= length)
			capacity = length + 1;
		this->capacity = capacity;

		delete[] this->text;
		this->text = new char[capacity];
		strcpy_s(this->text, length + 1, text);
	}

	int GetLength() const
	{
		return length;
	}

	// метода SetLength не должно быть!

	int GetCapacity() const
	{
		return capacity;
	}

	void Clear()
	{
		text[0] = 0;
		length = 0;
	}

	void ShrinkToFit()
	{
		if (length + 1 <= capacity)
		{
			return;
		}

		capacity = length + 1;
		char* temp = new char[capacity];
		strcpy_s(temp, capacity, text);
		delete[] text;
		text = temp;
	}

	void ShowInfo() const
	{
		cout << "Text: " << text << "\n";
		cout << "Length: " << length << "\n";
		cout << "Capacity: " << capacity << "\n";
	}

	///////////////////////////////// МОИ МЕТОДЫ /////////////////////////////////

	void GetCharAt(unsigned int index)
	{
		if (index > length) return;

		for (int i = 0; i < length; i++) {
			if (i == index)
				cout << "Your index is: " << index << "\nYour symbol is: " << text[i];
		} 
		cout << "\n\n";
	}
	
	void GetLine() const 
	{
		for (int i = 0; i < length; i++) {
			if (text[i] != ' ')
				cout << text[i];
			else return;
		}
		cout << "\n\n";
	}

	void Print()
	{
		for (int i = 0; i < length; i++) {
			cout << text[i];
		}
		cout << "\n\n";
	}

	void Replace(char R, char Z)
	{
		for (int i = 0; i < length; i++) {
			if (text[i] == R)
				text[i] = Z;
				cout << text[i];
		}
		cout << "\n\n";
	}

	void Reverse()
	{
		for (int i = length; i > 0 ; i--) {
			cout << text[i];
		}
		cout << "\n\n";
	}

	void RandomFill()
	{
		for (int i = 0; i < capacity; i++) {
			text[i] = rand() % 100;
			cout << text[i];
		}
		cout << "\n\n";
	}
	
};

int main()
{
	String a;
	a.SetString("Reading occurs only up to the first space \n");
	
	a.Print();

	a.GetLine();
	cout << "\n\n";
	a.GetCharAt(2);
	a.Replace('a', 'b');
	a.Reverse();

	String b;
	b.RandomFill();

	
	

	/*
	// String b("Alex");
	// b.ShowInfo();

	// String c(75);
	// c.ShowInfo();

	// String d("Alex", 20);
	// d.ShowInfo();

	// String e = d;
	// e.ShowInfo();
	*/

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
