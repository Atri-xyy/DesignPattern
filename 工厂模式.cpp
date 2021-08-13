#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
������ɫ:�򵥹���ģʽ�ĺ���.����ʵ�ִ�������ʵ�����ڲ��߼�.������Ĵ�����Ʒ��ķ������Ա����ֱ�ӵ���.���������Ʒ�Ķ���.
�����Ʒ��ɫ:�򵥹���ģʽ�����������ж���ĸ���.��������������ʵ�����еĹ����ӿ�.
�����Ʒ��ɫ:�Ǽ򵥹���ģʽ�Ĵ���Ŀ��.���д��������ǳ䵱�����ɫ��ĳ���������ʵ��.
ȱ��:���޸Ĳ����

�򵥹���ģʽ������Ĵ�����ģʽ,�ֽ�����̬��������ģʽ��ͨ��ר�Ŷ���һ���������𴴽�����
���ʵ������������ʵ��ͨ�������й�ͬ�ĸ��ࡣ

��������ģʽͬ��������Ĵ�����ģʽ�ֱ���Ϊ��̬����ģʽ ����������ģʽ�������Ƕ���һ����
����Ʒ����Ĺ����ӿڣ���ʵ�ʴ��������Ƴٵ����൱�С�
���Ĺ����಻�ٸ����Ʒ�Ĵ����������������Ϊһ�����󹤳���ɫ����������幤���������ʵ
�ֵĽӿڣ�������һ�����󻯵ĺô���ʹ�ù�������ģʽ����ʹϵͳ�ڲ��޸ľ��幤����ɫ�����
�������µĲ�Ʒ��

���󹤳�ģʽ��������̬�Ĺ���ģʽ����Ϊ���������һ���Եġ����󹤳�ģʽ������ͻ����ṩ
һ���ӿڣ�ʹ�ÿͻ����ڲ���ָ����Ʒ�ľ������͵�����£��ܹ����������Ʒ��Ĳ�Ʒ����
*/

enum PRODUCTTYPE //�����ֻ�����
{
	OPPO,
	VIVO,
	HUAWEI
};

enum OTHERTYPE //�������
{
	IC,//оƬ
	CASE//���
};
class phonebase {
public:
	virtual ~phonebase() {};
	virtual void show() = 0;
};


/*oppo�����Ʒphone*/
class OPPOPhone :public phonebase {
	void show() { cout << "OPPO Phone" << endl; };
};

/*vivo�����Ʒphone*/
class VIVOPhone :public phonebase {
	void show() { cout << "VIVO Phone" << endl; };
};

/*HUAWEI�����Ʒphone*/
class HUAWEIPhone :public phonebase {
	void show() { cout << "HUAWEI Phone" << endl; };
};

class OTHERBase {//�����Ʒother
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

class Factory {//���󹤳�
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