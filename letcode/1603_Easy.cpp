#include<iostream>

using namespace std;

//请你给一个停车场设计一个停车系统。停车场总共有三种不同大小的车位：大，中和小，每种尺寸分别有固定数目的车位。
//
//请你实现 ParkingSystem 类：
//
//	ParkingSystem(int big, int medium, int small) 初始化 ParkingSystem 类，三个参数分别对应每种停车位的数目。
//	bool addCar(int carType) 检查是否有 carType 对应的停车位。 carType 有三种类型：大，中，小，分别用数字 1， 2 和 3 表示。一辆车只能停在  carType 对应尺寸的停车位中。如果没有空车位，请返回 false ，否则将该车停入车位并返回 true 。
//
//
//提示：
//
//	0 <= big, medium, small <= 1000
//	carType 取值为 1， 2 或 3
//	最多会调用 addCar 函数 1000 次
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/design-parking-system
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class ParkingSystem {
public:
	ParkingSystem(int big, int medium, int small) :bigRemain(big), mediumRemain(medium), smallRemain(small)
	{

	}

	bool addCar(int carType) {
		switch (carType)
		{
		case 1:
			if (bigRemain == 0)
				return false;
			else
			{
				bigRemain--;
				return true;
			}
		case 2:
			if (mediumRemain == 0)
				return false;
			else
			{
				mediumRemain--;
				return true;
			}
		case 3:
			if (smallRemain == 0)
				return false;
			else
			{
				smallRemain--;
				return true;
			}
		default:
			return false;
		}
	}
private:
	int bigRemain;
	int mediumRemain;
	int smallRemain;
};


int main1603()
{
	ParkingSystem* obj = new ParkingSystem(1, 1, 0);
	bool ret;
	ret = obj->addCar(1);
	cout << "main：ret = " << ret << endl;
	ret = obj->addCar(2);
	cout << "main：ret = " << ret << endl;
	ret = obj->addCar(3);
	cout << "main：ret = " << ret << endl;
	ret = obj->addCar(1);
	cout << "main：ret = " << ret << endl;
	return 0;
}