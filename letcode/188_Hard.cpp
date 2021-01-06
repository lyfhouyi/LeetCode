#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
//
//设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
//
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//
//
//
//提示：
//
//	0 <= k <= 100
//	0 <= prices.length <= 1000
//	0 <= prices[i] <= 1000
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



vector<int>::iterator be;
//计算矩阵的目的在于：避免重复运算，以空间换时间
vector<vector<int>>singleMat; // maxProfit_single_range 计算矩阵
vector<vector<int>>maxMat; // max_element 计算矩阵  a_ij = range[j,i] 内的最大值
vector<vector<pair<int, int>>>cutMat; // where2cut 计算矩阵



void setMaxMat(int rangeBegin, int rangeEnd, int maxPos, int maxVal)
{
	for (int i = maxPos; i < rangeEnd; i++)
	{
		for (int j = rangeBegin; j <= maxPos; j++)
		{
			maxMat[i][j] = maxVal;
		}
	}
}


int maxProfit_single_range(vector<int>::iterator begin, vector<int>::iterator end)
{
	if (end - begin == 1)
		return 0;
	int profitMax = singleMat[end - be - 1][begin - be];
	if (profitMax != -1)
	{
		//cout << "maxProfit_single_range：跳过了计算" << endl;
		return profitMax;
	}
	//cout << "maxProfit_single_range：计算[" << begin - be << "," << end - be << "]"  << endl; 
	profitMax = 0;
	//cout << "maxProfit_single：输入数组 "<< prices.size()<<": ";
	//for (vector<int>::iterator it = prices.begin(); it != prices.end(); it++)
	//{
	//	cout << *it << "    ";
	//}
	//cout << endl;
	int profitInc_right;
	int max_right;
	vector<int>::iterator max_pos;
	for (vector<int>::iterator it = begin; it != end; it++)
	{
		max_right = maxMat[end - be - 1][it - be];
		if (max_right != -1)
		{
			//cout << "maxProfit_single_range->max_element：跳过了计算" << endl;
			profitInc_right = max_right - *it;
		}
		else
		{
			//cout << "maxProfit_single_range->max_element：计算[" << it - be << "," << end - be << "]" << endl;
			max_pos = max_element(it, end);
			profitInc_right = *max_pos - *it;
			setMaxMat(it - be, end - be, max_pos - be, *max_pos);
		}
		if (profitInc_right > profitMax)
			profitMax = profitInc_right;
	}
	//cout << "maxProfit_single：maxProfit= "<< profitMax<<endl;
	singleMat[end - be - 1][begin - be] = profitMax;
	return profitMax;
}


int where2cut(vector<int>::iterator begin, vector<int>::iterator end, int& index)
{
	if (end - begin == 1)
		return 0;
	pair<int, int>tmp = cutMat[begin - be][end - be - 1];
	if ((tmp.first != -1) && (tmp.second != -1))
	{
		// cout << "where2cut：跳过了计算" << endl;
		index = tmp.second;
		return tmp.first;
	}
	//cout << "where2cut：输入数组 " << end - begin << ": ";
	//for (vector<int>::iterator it = begin; it != end; it++)
	//{
	//	cout << *it << "    ";
	//}
	//cout << endl;
	//cout << "where2cut：调用 maxProfit_single_range [" << begin - be << "," << end - be << "]" << endl;
	int profitNow = maxProfit_single_range(begin, end); //当前的交易利润
	int profit_left = 0;
	int profit_right = 0;

	int profitMax = profitNow;
	for (vector<int>::iterator it = begin + 1; it != end; it++)
	{
		//cout << "where2cut：调用 maxProfit_single_range [" << begin - be << "," << it + 1 - be << "]" << endl;
		profit_left = maxProfit_single_range(begin, it + 1);
		//cout << "where2cut：调用 maxProfit_single_range [" << it - be << "," << end - be << "]" << endl;
		profit_right = maxProfit_single_range(it, end);
		if (profit_left + profit_right > profitMax)
		{
			profitMax = profit_left + profit_right;
			index = it - begin + 1;
			//cout << "where2cut：找到了更优切一刀，位置：" << index << endl;
		}
	}

	//cout << "where2cut：找到了当前局部数组的最佳切一刀，位置：" << index << endl;
	//cout << endl;
	cutMat[begin - be][end - be - 1] = pair<int, int>(profitMax - profitNow, index);
	return profitMax - profitNow;
}


//贪心算法。每次迭代找到最佳切一刀
int maxProfit(int k, vector<int>& prices)
{
	be = prices.begin();
	singleMat.resize(prices.size(), vector<int>(prices.size(), -1));
	maxMat.resize(prices.size(), vector<int>(prices.size(), -1));
	cutMat.resize(prices.size(), vector<pair<int, int>>(prices.size(), pair<int, int>(-1, -1)));

	if ((prices.size() == 0) || (k == 0))
		return 0;
	if (k <= 1)
	{
		//cout << "maxProfit：调用 maxProfit_single_range [" << prices.begin() - be << "," << prices.end() - be << "]" << endl;
		return maxProfit_single_range(prices.begin(), prices.end());
	}

	int c = k - 1; //最多可以切几刀
	//cout << "maxProfit：调用 maxProfit_single_range [" << prices.begin()-be << "," << prices.end() - be << "]" << endl;
	int profitMax = maxProfit_single_range(prices.begin(), prices.end());
	int index = 0; //全局最佳切一刀位置
	int index_i = 0;
	int profitInc = 0;
	int profitInc_i = 0;
	vector<unsigned long>cutPos({ 0,prices.size() });
	// cout << "maxProfit：调用 where2cut [" << 0 << "," << prices.end() - prices.begin() <<"]"<< endl;
	profitInc = where2cut(prices.begin(), prices.end(), index);
	while (profitInc && c)
	{
		// cout << "maxProfit：找到了全数组的最佳切一刀，位置：" << index <<"\n"<< endl;
		c--;
		profitMax += profitInc;
		cutPos.push_back(index);
		sort(cutPos.begin(), cutPos.end());
		profitInc = 0;
		for (vector<unsigned long>::iterator it = cutPos.begin(); it != cutPos.end() - 1; it++) //找到下一个最佳切一刀
		{
			// cout << "maxProfit：调用 where2cut [" << *it << "," << *(it + 1) << "]" << endl;
			profitInc_i = where2cut(prices.begin() + *it, prices.begin() + *(it + 1), index_i);
			if (profitInc_i > profitInc)
			{
				index = *it + index_i;
				profitInc = profitInc_i;
			}
		}
	}

	// cout << "maxProfit：共" << cutPos.size()-1 << "次交易" << endl;

	// cout << "maxProfit：切分位置为：" << cutPos.size()-2 << "：";
	// for (vector<unsigned long>::iterator it = cutPos.begin()+1; it != cutPos.end()-1; it++)
	// {
	//     cout << *it << "    ";
	// }
	// cout << endl;

	// cout << "maxProfit：profit_now=" << profitMax << endl;
	return profitMax;
}


int main188()
{
	vector<int> test = { 3,2,6,5,0,3 };
	int ret = maxProfit(2,test);
	cout << "main：ret = " << ret << endl;
	return 0;
}