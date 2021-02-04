#include<iostream>
#include<set>

using namespace std;

//中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
//
//
//设计一个支持以下两种操作的数据结构：
//
//	void addNum(int num) - 从数据流中添加一个整数到数据结构中。
//	double findMedian() - 返回目前所有元素的中位数。
//
//
//进阶:
//
//	如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
//	如果数据流中 99 % 的整数都在 0 到 100 范围内，你将如何优化你的算法？


//维护两个堆以计算中位数。任一时刻，比中位数小的数保存于大顶堆中，比中位数大的数保存于小顶堆中；中位数由两个堆的堆顶元素决定；插入一个新元素时，需根据其与当前中位数的大小关系决定将其加入哪一个堆中；插入元素后，需调整两个堆的元素以使大顶堆的元素个数与小顶堆的元素个数相等（偶），或比其多一（奇）。
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
	multiset<double> bigSide; //大于中位数的元素所构成的小顶堆
	multiset<double, greater<double>> littleSide; //小于中位数的元素所构成的大顶堆
};


int main295()
{
	MedianFinder* obj = new MedianFinder();
	obj->addNum(1);
	obj->addNum(2);
	cout << "main：obj->findMedian() = " << obj->findMedian() << endl;
	obj->addNum(3);
	cout << "main：obj->findMedian() = " << obj->findMedian() << endl;
	return 0;
}