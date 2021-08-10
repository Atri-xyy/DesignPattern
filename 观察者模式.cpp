#include <iostream>
#include <vector>
#include <list>
using namespace std;
/*
观察者模式(Observer Pattern):定义对象之间的一种一对多关系.使得每当
一个对象状态发生改变时.其相关依赖对象都能得到通知并被自动更新.
角色:
Subject(目标):可以被多个观察者观察.提供一系列方法来增加删除观察者.并且拥有Notify()方法.
ConcreateSubject(具体目标):包含经常发生改变的数据
Observer(观察者):定义抽象接口
ConcreateObserver(具体观察者):实现抽象类的update()方法

*/
class Object;
class AbstractObserver //观察者提供更新
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

class AbstractObject {//目标对象提供增删
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
	Object* p = new Object();//创建观察目标

	/*添加观察者*/
	Observer* s1 = new Observer("ob1", p);
	Observer* s2 = new Observer("ob2", p);
	Observer* s3 = new Observer("ob3", p);
	Observer* s4 = new Observer("ob4", p);

	/*添加观察者到目标*/
	p->Add(s1);
	p->Add(s2);
	p->Add(s3);
	p->Add(s4);

	/*产生事件*/
	p->action = "first play game";
	p->Notify();
	p->Remove(s2);
	p->action = "second play game";
	p->Notify();
	return 0;
}