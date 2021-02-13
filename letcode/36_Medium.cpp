#include<iostream>
#include<vector>
#include<set>

using namespace std;

//判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
//
//	数字 1 - 9 在每一行只能出现一次。
//	数字 1 - 9 在每一列只能出现一次。
//	数字 1 - 9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
//
//数独部分空格内已填入了数字，空白格用 '.' 表示。
//
//
//说明 :
//
//	一个有效的数独（部分已被填充）不一定是可解的。
//	只需要根据以上规则，验证已经填入的数字是否有效即可。
//	给定数独序列只包含数字 1 - 9 和字符 '.' 。
//	给定数独永远是 9x9 形式的。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/valid-sudoku
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：集合。使用三个集合数组，分别对应行集合数组、列集合数组、3×3宫集合数组。通过将数独中各数字加入所属集合，判断数独的有效性。
//bool isValidSudoku(vector<vector<char>>& board)
//{
//	vector<set<int>> rowSets(9);
//	vector<set<int>> colSets(9);
//	vector<set<int>> boxSets(9);
//
//	//遍历 9×9 的每一个元素
//	int boxNo;
//	for (int i = 0; i < 9; i++) //遍历数独各行
//	{
//		for (int j = 0; j < 9; j++) //遍历数独各列
//		{
//			if (board[i][j] == '.')
//				continue;
//			else
//			{
//				//检查同行中是否有重复
//				if (rowSets[i].end() != rowSets[i].find(board[i][j]))
//					return false;
//				rowSets[i].insert(board[i][j]);
//
//				//检查同列中是否有重复
//				if (colSets[j].end() != colSets[j].find(board[i][j]))
//					return false;
//				colSets[j].insert(board[i][j]);
//
//				//检查同宫中是否有重复
//				boxNo = 3 * (i / 3) + (j / 3);
//				if (boxSets[boxNo].end() != boxSets[boxNo].find(board[i][j]))
//					return false;
//				boxSets[boxNo].insert(board[i][j]);
//			}
//		}
//	}
//	return true;
//}


//解法二：桶。使用三个桶数组，分别对应行桶数组、列桶数组、3×3宫桶数组。通过将数独中各数字加入所属桶，判断数独的有效性。
bool isValidSudoku(vector<vector<char>>& board)
{
	vector<vector<bool>> rowBuckets(9, vector<bool>(9, false));
	vector<vector<bool>> colBuckets(9, vector<bool>(9, false));
	vector<vector<bool>> boxBuckets(9, vector<bool>(9, false));

	//遍历 9×9 的每一个元素
	int boxNo;
	for (int i = 0; i < 9; i++) //遍历数独各行
	{
		for (int j = 0; j < 9; j++) //遍历数独各列
		{
			if (board[i][j] == '.')
				continue;
			else
			{
				//检查同行中是否有重复
				if (rowBuckets[i][board[i][j] - '1'])
					return false;
				rowBuckets[i][board[i][j] - '1'] = true;

				//检查同列中是否有重复
				if (colBuckets[j][board[i][j] - '1'])
					return false;
				colBuckets[j][board[i][j] - '1'] = true;

				//检查同宫中是否有重复
				boxNo = 3 * (i / 3) + (j / 3);
				if (boxBuckets[boxNo][board[i][j] - '1'])
					return false;
				boxBuckets[boxNo][board[i][j] - '1'] = true;
			}
		}
	}
	return true;
}


int main36()
{
	vector<vector<char>> test = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '.', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '.', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '.', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	bool ret = isValidSudoku(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}