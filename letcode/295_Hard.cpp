#include<iostream>
#include<set>

using namespace std;

//��λ���������б��м����������б�����ż������λ�������м���������ƽ��ֵ��
//
//
//���һ��֧���������ֲ��������ݽṹ��
//
//	void addNum(int num) - �������������һ�����������ݽṹ�С�
//	double findMedian() - ����Ŀǰ����Ԫ�ص���λ����
//
//
//����:
//
//	����������������������� 0 �� 100 ��Χ�ڣ��㽫����Ż�����㷨��
//	����������� 99 % ���������� 0 �� 100 ��Χ�ڣ��㽫����Ż�����㷨��


//ά���������Լ�����λ������һʱ�̣�����λ��С���������ڴ󶥶��У�����λ�������������С�����У���λ���������ѵĶѶ�Ԫ�ؾ���������һ����Ԫ��ʱ����������뵱ǰ��λ���Ĵ�С��ϵ�������������һ�����У�����Ԫ�غ�����������ѵ�Ԫ����ʹ�󶥶ѵ�Ԫ�ظ�����С���ѵ�Ԫ�ظ�����ȣ�ż����������һ���棩��
class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void makeBalance()
	{
		if (bigSide.size() > littleSide.size())
		{
			littleSide.insert(littleSide.begin(), *bigSide.begin());
			bigSide.erase(bigSide.begin());
		}
		else
			if (littleSide.size() - 1 > bigSide.size())
			{
				bigSide.insert(bigSide.begin(), *littleSide.begin());
				littleSide.erase(littleSide.begin());
			}
	}

	void addNum(int num) {
		if (littleSide.empty() || *littleSide.begin() >= num)
			littleSide.insert(num);
		else
			bigSide.insert(num);
		makeBalance();
	}

	double findMedian() {
		if (littleSide.size() > bigSide.size())
			return *littleSide.begin();
		else
			return (*littleSide.begin() + *bigSide.begin()) / 2;
	}
private:
	multiset<double> bigSide; //������λ����Ԫ�������ɵ�С����
	multiset<double, greater<double>> littleSide; //С����λ����Ԫ�������ɵĴ󶥶�
};


int main295()
{
	MedianFinder* obj = new MedianFinder();
	obj->addNum(1);
	obj->addNum(2);
	cout << "main��obj->findMedian() = " << obj->findMedian() << endl;
	obj->addNum(3);
	cout << "main��obj->findMedian() = " << obj->findMedian() << endl;
	return 0;
}