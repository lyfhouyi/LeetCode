#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

//假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
//
//请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
//
//
//提示：
//
//	1 <= people.length <= 2000
//	0 <= hi <= 106
//	0 <= ki < people.length
//	题目数据确保队列可以被重建
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/queue-reconstruction-by-height
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//贪心算法。逐项取出身高最矮的人，将其归位至正确位置。人 p 的正确位置 pos 位于在 pos 之前恰好有 p[1] 个空位的地方。
vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
	int n = people.size();
	sort(people.begin(), people.end(), [](vector<int> A, vector<int> B) {return (A[0] < B[0]) || (A[0] == B[0] && A[1] > B[1]); });
	vector<vector<int>>ret(n, vector<int>(2, INT_MAX));
	int seatCnt;
	int j;

	//逐项取出身高最矮的人，将其归位至正确位置
	for (int i = 0; i < n; i++)
	{
		seatCnt = people[i][1];
		j = 0;
		while (seatCnt > 0) //跳过 people[i][1] 个空位
		{
			if (ret[j][0] >= people[i][0]) //发现一个空位
				seatCnt--;
			j++;
		}

		while (ret[j][0] != INT_MAX) //后归位的人不能抢占先归位的人的位置
			j++;

		//找到当前人的正确位置
		ret[j][0] = people[i][0];
		ret[j][1] = people[i][1];
		cout << "当前人 [" << people[i][0] << "," << people[i][1] << "]" << " 的正确位置在 " << j << endl;
	}
	return ret;
}


//贪心算法，细节优化，避免了找空位时的比较。逐项取出身高最矮的人，将其归位至正确位置。人 p 的正确位置 pos 位于在 pos 之前恰好有 p[1] 个空位的地方。
//vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
//{
//	int n = people.size();
//	sort(people.begin(), people.end(), [](vector<int> A, vector<int> B) {return (A[0] < B[0]) || (A[0] == B[0] && A[1] > B[1]); });
//	vector<vector<int>>ret(n);
//	int seatCnt;
//	int j;
//
//	//逐项取出身高最矮的人，将其归位至正确位置
//	for (int i = 0; i < n; i++)
//	{
//		seatCnt = people[i][1];
//		j = 0;
//		while (seatCnt > 0) //跳过 people[i][1] 个空位
//		{
//			if (ret[j].empty()) //发现一个空位
//				seatCnt--;
//			j++;
//		}
//
//		while (!ret[j].empty()) //后归位的人不能抢占先归位的人的位置
//			j++;
//
//		//找到当前人的正确位置
//		ret[j] = people[i];
//		cout << "当前人 [" << people[i][0] << "," << people[i][1] << "]" << " 的正确位置在 " << j << endl;
//	}
//	return ret;
//}


int main406()
{
	vector<vector<int>> test = { {7, 0},{4, 4},{7, 1},{5, 0},{6, 1},{5, 2} };
	//vector<vector<int>> test = { {6, 0},{5, 0},{4, 0},{3, 2},{2, 2},{1, 4} };
	vector<vector<int>> ret = reconstructQueue(test);
	cout << "main：ret = " << endl;
	for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << "[" << it->at(0) << "," << it->at(1) << "],";
	cout << endl;
	return 0;
}