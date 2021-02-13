#include<iostream>
#include<vector>
#include<map>

using namespace std;

//给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。
//
//（例如，[1, 2, 3, 1, 2] 中有 3 个不同的整数：1，2，以及 3。）
//
//返回 A 中好子数组的数目。
//
//
//提示：
//
//	1 <= A.length <= 20000
//	1 <= A[i] <= A.length
//	1 <= K <= A.length
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/subarrays-with-k-different-integers
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//双指针遍历数组。以内容集 containSet 为当前考察的子数组所包含的不同元素的集合；不断考察以两个指针为边界构成的子数组，通过子数组的首尾元素判断该子数组是否为好子数组。
int subarraysWithKDistinct(vector<int>& A, int K) 
{
	int n = A.size();
	map<int, int> containMap;
	int i=0;
	int j =0;
	int goodArrayCnt = 0;
	int tmp = 1;
	map<int, int> containMap2;

	//区间 [i,j] 为待考察的子数组。
	while (i < n || j<n)
	{
		if (containMap.size() < K) //以 i 为首元素的子数组集中尚未找到好子数组
		{
			if (j == n)
				return goodArrayCnt;
			else
			{
				if (1 == containMap.count(A[j]))
					containMap.at(A[j])++;
				else
					containMap[A[j]] = 1;
				j++;
			}
		}
		else //以 i 为首元素的子数组集中已找到好子数组
		{
			



			goodArrayCnt+= tmp; //找到好子数组
			cout << "subarraysWithKDistinct：找到好子数组  [" << i << "," << j << "]" <<" tmp = " <<tmp<<endl;
			cout << "goodArrayCnt = " << goodArrayCnt << endl;

			if (j == n - 1)
			{
				return goodArrayCnt;
			}
			else
			{
				while (containMap.at(A[i]) != 1) // A[i] 在子数组中不唯一 
				{
					tmp++;
					cout << "subarraysWithKDistinct：缓冲 + 1 ：tmp = " <<tmp<<endl;
					containMap.at(A[i])--;
					i++;
				}

				if (1 == containMap.count(A[j+1]))
				{
					containMap.at(A[j+1])++;
					j++;
				}
				else
				{
					tmp = 1;
					cout << "subarraysWithKDistinct：缓冲置 1 ：tmp = " << tmp << endl;
					containMap.erase(A[i]);
					i++;
					containMap[A[j + 1]]=1;
					j++;
				}
			}
		}
	}
	return -1;
}


int main992()
{
	////vector<int> test = { 1};
	vector<int> test = { 1,1,2,1,1};
	//vector<int> test = { 1,2,1,3,4 };
	int ret = subarraysWithKDistinct(test,2);
	cout << "main：ret = " << ret << endl;
	return 0;
}