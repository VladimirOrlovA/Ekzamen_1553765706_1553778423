#include<iostream>
using namespace std;

// Ekzamen_1553765706_1553778423 //

void fillArray(int **arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			arr[i][j] = 1 + rand() % 101;
	}
}

void printArray(int **arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << "  ";
		cout << endl;
	}
}

void averageColumn(int **arr, int n, int m)
{
	int sum = 0;
	float aver;

	cout << "Sum of each column: \n";

	for (int i = 0; i < m; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
			sum += arr[j][i];
	
		aver = float(sum) / n;
		cout << i + 1 << " -> " << sum << endl;
		cout << "Average of sum -> " << aver << "\n\n";
	}
	
}

void averageColumn2(int **arr, int n, int m)
{
	int sum = 0;
	float aver;
	
	cout << "Sum of each even column: \n";

	for (int i = 0; i < m; i += 2)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
				sum += arr[j][i];

		cout << i << " -> " << sum << endl;
		aver = float(sum) / n;
		cout << "Average is sum even column ->" << aver << "\n\n";
	}
	
}

void task1()
{
	/*Дано действительное число а.Не пользуясь никакими	другими арифметическими операциями, кроме умножения, получить:
	a^28 за шесть операций;*/

	float num;
	cout << "Enter number -> ";
	cin >> num;
	float num2 = num * num;
	float num4 = num2 * num2;
	float num8 = num4 * num4;
	float num12 = num8 * num4;
	float num24 = num12 * num12;
	float num28 = num24 * num4;
	cout << "\nNumber " << num << "^28 = " << num28 << "\n\n";

}

void task2()
/*Дано действительное число x. Вычислить:
 
*/
{
	float x, numerator = 1, denominator = 1;
	float xr;

	cout << "Enter number x -> ";
	cin >> x;
	for (int i = 1; i < 7; i++)
	{
		numerator *= (x - pow(2, i));
		denominator *= (x - (pow(2, i) - 1));
	}
	xr = numerator / denominator;
	cout <<"\nResult x = "<< xr << "\n\n";
}

void task3()
/*Даны натуральные числа n, b0, ..... , bn. Вычислить f(b0)+f(b1)+...+f(bn), где x^2, если x=3,
 x, если x/3=1, в остальных случаях [x/3]  */
{
	int i, start, end, in;
	
	cout << "Enter value - > ";
	cin >> start >> end;

	cout << "\nEnter the last member: ";
	cin >> in;

	for (i = start; i <= end; i += in);
	{
		if (i % 3 == 0)
			cout << i << " x^2 = " << pow(i, 2) << endl;

		else if (i % 3 == 1)
			cout << i << endl;

		else cout << i << " x/3 = " << float(i) / 3 << endl;
	}
}

void task4()
{
	/*Дано натуральное число n.Выбросить из записи числа n
		цифры 0 и 5, оставив прежним порядок остальных цифр.Например, из
		числа 59015509 должно получиться 919.*/

	unsigned int n = 59015509, t = 1, editN = 0;
	cout << "\nWe have number N = 59015509 \n";

	do
	{
		if ((n % 10 != 0) && (n % 10 != 5))
		{
			editN += (n % 10) * t;
			t *= 10;
		}
		n /= 10;

	} while (n > 0);

	cout <<"\nNumber N without digits 0 and 5 is -> "<< editN << "\n\n";
}

void task5()

/*Даны натуральное число n, символы s1....sn. Среди которых есть двоеточия. 
Получить все символы расположенные до первого двоеточия включительно*/
{
	char str[15];
	cout << "\Enter any symbols include : -> ";
	cin >> str;

	cout << "\nResult - ";

	for (int i = 0; i < strlen(str); i++)
	{
		cout << str[i];
		if (str[i] == ':')
			break;
	}

	cout << "\n\n";
}


void task6()
/*Даны натуральное число n, действительная матрица размером n х 9. Найти среднее арифметическое
а) каждого из столбцов
б) каждого из столбцов имеющих четные номера*/
{
	int n;
	int **arr;
	cout << "Enter n: ";
	cin >> n;
	arr = new int*[n];
	
	for (int i = 0; i < n; i++)
		arr[i] = new int[9];

	fillArray(arr, n, 9);
	printArray(arr, n, 9);

	cout << "\n (1) - Result average of every coloumn\n (2) - Result average of even coloumns \n";

	int choice;
	cout << "\n -> ";
	cin >> choice;
	
	cout << "\n\n";

	switch (choice)
	{
	case 1:	{averageColumn(arr, n, 9); break;}
	case 2: {averageColumn2(arr, n, 9); break;}
	}
}



int main()
{
	int choice;
	char flag='y';

	do
	{
		cout << "Enter number of task: ";
		cin >> choice;

		switch (choice)
		{
		case 1:	{task1(); break; }
		case 2: {task2(); break; }
		case 3: {task3(); break; }
		case 4: {task4(); break; }
		case 5: {task5(); break; }
		case 6: {task6(); break; }
		default: cout << "\n\nSelected Number of Task does not exist!\n\n";
		}

		cout << "Do you want to continue? y/n -> ";
		cin >> flag;

	} while (flag == 'y');
}