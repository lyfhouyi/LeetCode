﻿//给定一个整数数组  nums，求出数组从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点。
//
//实现 NumArray 类：
//
//	NumArray(int[] nums) 使用数组 nums 初始化对象
//	int sumRange(int i, int j) 返回数组 nums 从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点（也就是 sum(nums[i], nums[i + 1], ..., nums[j])）
//
//提示：
//
//	0 <= nums.length <= 10^4
//	- 10^5 <= nums[i] <= 10^5
//	0 <= i <= j < nums.length
//	最多调用 10^4 次 sumRange 方法
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/range-sum-query-immutable
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。