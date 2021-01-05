#include<iostream>
#include<vector>

using namespace std;


//假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
//
//给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/can-place-flowers
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//贪心算法：连续三个 0 ，就种一颗花
bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
	if (0 == n)
		return true;
	if (1 == flowerbed.size())
		return 1 - flowerbed[0];
	flowerbed.push_back(0);
	int cnt = 0;
	vector<int>::iterator it1 = flowerbed.begin();
	vector<int>::iterator it2 = flowerbed.begin() + 1;
	vector<int>::iterator it3 = flowerbed.begin() + 2;
	while (flowerbed.end() - 1 != it2)
	{
		if (flowerbed.begin() == it1)
		{
			if ((!*it1) && (!*it2))
			{
				cout << "在 index = " << it1 - flowerbed.begin() << " 处种花" << endl;
				*it1 = 1;
				cnt++;
			}
		}
		else
		{
			if ((!*it1) && (!*it2) && (!*it3))
			{
				cout << "在 index = " << it2 - flowerbed.begin() << " 处种花" << endl;
				*it2 = 1;
				cnt++;
			}
		}
		if (cnt == n)
			return true;
		it1++;
		it2++;
		it3++;
	}
	return false;
}



int main605()
{
	vector<int>test = { 0,0,1 };
	int ret = canPlaceFlowers(test, 2);
	cout << "main：ret=" << ret << endl;
	return 0;
}