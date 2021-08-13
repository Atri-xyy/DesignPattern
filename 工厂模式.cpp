#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
工厂角色:简单工厂模式的核心.负责实现创建所有实例的内部逻辑.工厂类的创建产品类的方法可以被外界直接调用.创建所需产品的对象.
抽象产品角色:简单工厂模式所创建的所有对象的父类.他负责描述所有实例共有的公共接口.
具体产品角色:是简单工厂模式的创建目标.所有创建对象都是充当这个角色的某个具体类的实例.
缺点:对修改不封闭

简单工厂模式属于类的创建型模式,又叫做静态工厂方法模式。通过专门定义一个类来负责创建其他
类的实例，被创建的实例通常都具有共同的父类。

工厂方法模式同样属于类的创建型模式又被称为多态工厂模式 。工厂方法模式的意义是定义一个创
建产品对象的工厂接口，将实际创建工作推迟到子类当中。
核心工厂类不再负责产品的创建，这样核心类成为一个抽象工厂角色，仅负责具体工厂子类必须实
现的接口，这样进一步抽象化的好处是使得工厂方法模式可以使系统在不修改具体工厂角色的情况
下引进新的产品。

抽象工厂模式是所有形态的工厂模式中最为抽象和最其一般性的。抽象工厂模式可以向客户端提供
一个接口，使得客户端在不必指定产品的具体类型的情况下，能够创建多个产品族的产品对象。
*/

enum PRODUCTTYPE //定义手机类型
{
	OPPO,
	VIVO,
	HUAWEI
};

enum OTHERTYPE //其他配件
{
	IC,//芯片
	CASE//配件
};
class phonebase {
public:
	virtual ~phonebase() {};
	virtual void show() = 0;
};


/*oppo具体产品phone*/
class OPPOPhone :public phonebase {
	void show() { cout << "OPPO Phone" << endl; };
};

/*vivo具体产品phone*/
class VIVOPhone :public phonebase {
	void show() { cout << "VIVO Phone" << endl; };
};

/*HUAWEI具体产品phone*/
class HUAWEIPhone :public phonebase {
	void show() { cout << "HUAWEI Phone" << endl; };
};

class OTHERBase {//抽象产品other
public:
	virtual ~OTHERBase() {};
	virtual void show() = 0;
};

class OPPOTHER :public OTHERBase {
	void  show() { cout << "OPPO OTHER PRODUCT" << endl; }
};


class VIVOOTHER :public OTHERBase {
	void  show() { cout << "VIVO OTHER PRODUCT" << endl; }
};



class HUAWEITHER :public OTHERBase {
	void  show() { cout << "HUAWEI OTHER PRODUCT" << endl; }
};

class Factory {//抽象工厂
public:
	virtual phonebase* createPhone() = 0;
	virtual OTHERBase* createOther() = 0;
};

class OPPOFactor :public Factory {
public:
	phonebase* createPhone() {
		return new OPPOPhone();
	}
	OTHERBase* createOther() {
		return new OPPOTHER();
	}
};

class HUAWEIFactor :public Factory {
public:
	phonebase* createPhone() {
		return new HUAWEIPhone();
	}
	OTHERBase* createOther() {
		return new HUAWEITHER();
	}
};

class VIVOFactor :public Factory {
public:
	phonebase* createPhone() {
		return new VIVOPhone();
	}
	OTHERBase* createOther() {
		return new VIVOOTHER();
	}
};
int main1(void) {
	OPPOFactor ofactory;
	phonebase* p1 = ofactory.createPhone();
	OTHERBase* p2 = ofactory.createOther();
	p1->show();
	p2->show();
	delete p1;
	delete p2;
	return 0;

}