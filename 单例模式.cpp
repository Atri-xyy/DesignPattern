#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


/*
类的对象有且只有一个.
单例模式的类只提供私有的构造函数
该类提供了一个静态的公有方法用于创建或获取它本身的静态私有对象
懒汉单例模式:当第一次使用时才创建一个唯一的实例对象.从而实现延时加载的效果.
饿汉单例模式:程序启动时就创建一个唯一的实例对象.即单例类定义的时候就进行实例化.
使用场景:系统只需要一个实例对象.或者考虑到资源消耗太大只允许创建一个对象.
*/
class CSingleton {//懒汉单例模式 使用的时候才创建
public:
	static  CSingleton* getInstance() {
		if (instance == NULL) {
			unique_lock<mutex>m(m_mutex);
			if (instance == NULL) {
				instance = new CSingleton();
				static CDestory mDel;
			}
		}
		return instance;
	}
	class CDestory {
	public:
		~CDestory() {
			if (CSingleton::instance != NULL) {
				delete CSingleton::instance;
				instance = NULL;
				cout << "~CSingleton()" << endl;
			}
		}
	};
	
private:
	static CSingleton* instance;
	CSingleton() {
		cout << "CSingleton()" << endl;
	}
	static mutex m_mutex;
};

CSingleton* CSingleton::instance = nullptr;
mutex CSingleton::m_mutex;

/*class CSingleton {//饿汉单例 开始就创建
public:
	static CSingleton* getInstance() {
		return instance;
	}
	class CDestroy
	{
	public:
		~CDestroy() {
			delete CSingleton::instance;
			instance = nullptr;
			cout << "~Csingleton()" << endl;
		}
	};
	static CDestroy Del;//删除单例
private:
	static CSingleton* instance;
	CSingleton();

};
CSingleton* CSingleton::instance = new CSingleton();
CSingleton::CDestroy Del;
*/
int main(void) {
	cout << "Process Begin" << endl;
	CSingleton* s1 = CSingleton::getInstance();
	CSingleton* s2 = CSingleton::getInstance();
	cout << "s1:" << s1 << " s2:" << s2 << endl;;
	return 0;
}