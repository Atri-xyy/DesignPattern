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
class AbstractObserver{
public:
	virtual void update() = 0;
};

class AbstractObject {
public:
	virtual void Add(AbstractObserver*) = 0;
	virtual void Remove(AbstractObserver*) = 0;
	virtual void Notify() = 0;
};
class ObserverA : public AbstractObserver {
public:
	
	void update() {
		cout << "A stop ..." << endl;
	}
private:
	
};
class ObserverB : public AbstractObserver {
public:

	void update() {
		cout << "B stop ..." << endl;
	}
private:

};
class ObserverC : public AbstractObserver {
public:

	void update() {
		cout << "C stop ..." << endl;
	}
private:

};

class Object :public AbstractObject {
public:
	void Add(AbstractObserver* observer) {
		ObserverList.push_back(observer);
	}
	void Remove(AbstractObserver* observer) {
		ObserverList.remove(observer);
	}
	void Notify() {
		for (auto it = ObserverList.begin(); it != ObserverList.end(); it++) {
			(*it)->update();
		}
	}
private:
	list<AbstractObserver*>ObserverList;
};
