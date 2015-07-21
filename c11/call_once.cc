/**
 * C++11的call_once使用示例
 *
 * @author 云景
 * @since 2015.07.21
 */

#include <iostream>
#include <thread>
#include <mutex>

std::once_flag flag;
int Gid = 0;

void setup(std::string param)
{
    Gid++;
    std::cout << "Called once! " << Gid << " param:" << param.c_str() << std::endl;
}

void doprint(std::string param)
{
    std::call_once(flag, setup, param);
}

int main()
{
    std::thread t1(doprint, "1");
    std::thread t2(doprint, "2");
    std::thread t3(doprint, "3");
    std::thread t4(doprint, "4");

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "Gid: " << Gid << std::endl;
	getchar();
}
