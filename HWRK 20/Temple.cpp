#include <iostream>
#include <ctime>
#include <cstdlib>

void fill_arr(int arr[], const int l) {
	srand(time(NULL));
	for (int i{}; i < l; i++)
		arr[i] = rand() / (100 + 100) - 100;
}

void show_arr(int arr[], const int l) {
	std::cout << "[";
	for (int i{}; i < l; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
	std::cout << std::endl;
}

int search_index(int arr[], const int l, int index, int begin = 0) {
	for (int i = begin; i < l; i++){
		if (arr[i] == index)
			return i;
	}

}

int search_last_index(int arr[], const int l, int last_index, int begin = 1) {
	for (int i = l - begin; i > 0; i--) {
		if (arr[i] == last_index)
			return i;
	}
}

int arr_min(int arr[], const int l) {
	int min = arr[0];
	for (int i{}; i < l; i++) {
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

int arr_max(int arr[], const int l) {
	int max = arr[0];
	for (int i{}; i < l; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

template <typename T>
double mean_value(T arr[], const double l) {
	double sum = 0;
	for (int i{}; i < l; i++)
		sum += arr[i];
	return sum / l;
}

void range(int arr[], const int l, int a, int b) {
	if (a > b)
		std::swap(a, b);
	for (int i{}; i < l; i++)
		if (arr[i] >= a && arr[i] <= b)
			std::cout << arr[i] << " ";
}

int counter(int arr[], const int l, int num) {
	int counter = 0;
	for (int i{}; i < l; i++)
		if (arr[i] == num)
			counter++;
	return counter;
}

// К сожалению, не реализовал защиту от "классного пользователя"
int main() {
	setlocale(LC_ALL, "Russian");

	int n,start, last, a, b, c;

	const int s = 100;
	int arr[s];
	fill_arr(arr, s);
	show_arr(arr, s);

	std::cout << "Укажите число из массива -> ";
	std::cin >> n;
	std::cout << "Укажите начало поиска (по умолчанию 0) -> ";
	std::cin >> start;
	std::cout << "Индекс первого вхождения в массив = " << search_index(arr, s, n,start);
	std::cout << "\nУкажите начало поиска (по умолчанию 1) -> ";
	std::cin >> last;
	std::cout << "Индекс последнего вхождения в массив = " << search_last_index(arr, s, n, last);
	std::cout << "\nМинимальный элемент массива = " << arr_min(arr, s);
	std::cout << "\nМаксимальный элемент массива = " << arr_max(arr, s);
	std::cout << "\nСреднее арифметическое массива = " << mean_value(arr, s);
	std::cout << "\nУкажите начало и конец диапазона чисел -> ";
	std::cin >> a >> b;
	range(arr, s, a, b);
	std::cout << "\nВыберите число из массива -> ";
	std::cin >> c;
	std::cout << "Число " << c << " встречается в массиве " << counter(arr, s, c) << " раз";

	return 0;
}