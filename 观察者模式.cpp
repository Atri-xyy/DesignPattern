#include <iostream>
#include <vector>
#include <list>
using namespace std;
/*
�۲���ģʽ(Observer Pattern):�������֮���һ��һ�Զ��ϵ.ʹ��ÿ��
һ������״̬�����ı�ʱ.��������������ܵõ�֪ͨ�����Զ�����.
��ɫ:
Subject(Ŀ��):���Ա�����۲��߹۲�.�ṩһϵ�з���������ɾ���۲���.����ӵ��Notify()����.
ConcreateSubject(����Ŀ��):�������������ı������
Observer(�۲���):�������ӿ�
ConcreateObserver(����۲���):ʵ�ֳ������update()����

*/
class Object;
class AbstractObserver //�۲����ṩ����
{
public:
	virtual void updata()=0;
};

class Observer :public AbstractObserver {
public:
	Observer(string str, Object* obj) :name(str), oj(obj) {};
	void updata();
	string getName() {
		return name;
	}
private:
	string name;
	Object* oj;
};

class AbstractObject {//Ŀ������ṩ��ɾ
public:
	virtual void Add(Observer* ob) = 0;
	virtual void Remove(Observer* ob) = 0;
	virtual void Notify() = 0;
};

class Object :public AbstractObject {
public:
	void Add(Observer* ob) {
		ObserverList.push_back(ob);
	}
	void Remove(Observer* ob) {
		ObserverList.remove(ob);
		cout << ob->getName() << " is be removed." << endl;
	}
	void Notify() {
		for (auto it = ObserverList.begin(); it != ObserverList.end(); it++) {
			(*it)->updata();
		}
	}
	string action;
private:
	list<Observer*>ObserverList;
};

void Observer::updata() {
	cout << name << ":" << oj->action << endl;
}
int main(void) {
	Object* p = new Object();//�����۲�Ŀ��

	/*��ӹ۲���*/
	Observer* s1 = new Observer("ob1", p);
	Observer* s2 = new Observer("ob2", p);
	Observer* s3 = new Observer("ob3", p);
	Observer* s4 = new Observer("ob4", p);

	/*��ӹ۲��ߵ�Ŀ��*/
	p->Add(s1);
	p->Add(s2);
	p->Add(s3);
	p->Add(s4);

	/*�����¼�*/
	p->action = "first play game";
	p->Notify();
	p->Remove(s2);
	p->action = "second play game";
	p->Notify();
	return 0;
}