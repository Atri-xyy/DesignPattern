#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


/*
��Ķ�������ֻ��һ��.
����ģʽ����ֻ�ṩ˽�еĹ��캯��
�����ṩ��һ����̬�Ĺ��з������ڴ������ȡ������ľ�̬˽�ж���
��������ģʽ:����һ��ʹ��ʱ�Ŵ���һ��Ψһ��ʵ������.�Ӷ�ʵ����ʱ���ص�Ч��.
��������ģʽ:��������ʱ�ʹ���һ��Ψһ��ʵ������.�������ඨ���ʱ��ͽ���ʵ����.
ʹ�ó���:ϵͳֻ��Ҫһ��ʵ������.���߿��ǵ���Դ����̫��ֻ������һ������.
*/
class CSingleton {//��������ģʽ ʹ�õ�ʱ��Ŵ���
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

/*class CSingleton {//�������� ��ʼ�ʹ���
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
	static CDestroy Del;//ɾ������
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