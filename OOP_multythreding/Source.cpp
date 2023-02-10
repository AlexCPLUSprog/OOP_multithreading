#include <iostream>
#include <thread>	// �����
#include <chrono>

// ����������� (Parallelism) - <��������� ���������� ������. �� ������ ���� ���� ������> 
// �������������� (Concurrency) - <��������� ������� ����������� �� �������������� �������� ����>

// std::cout - non thread-safe
void work(int a, int b) {
	std::cout << "Work started\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::cout << "Work thread: " << std::this_thread::get_id() << '\n';
	std::cout << "Work ended\n";
}

int main() {
	
	std::cout << "Main thread " << std::this_thread::get_id() << '\n';	// ������� �����. ��� ������ �����������! (������ ��� ������ ���������������)
	// ��������� ��������� �� �������. ����� ����������� ��������� -----> std::thread t1(work, 5, 6);
	std::thread t1([](int a, int b) {
		std::cout << a << " " << b << '\n';
		std::cout << "Work started\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		std::cout << "Work thread: " << std::this_thread::get_id() << '\n';
		std::cout << "Work ended\n";
		}, 5, 6);	// ����� ��������� ������

	std::thread t2(work, 3, 2);
	std::cout << "Hello\n";

	// race condition - "�����" ������/���������
	int x = 1;


	t1.join();	// ������������ � �������� ������
	t2.join();
	
	


}