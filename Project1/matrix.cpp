#include <iostream>
#include <vector>

using namespace std;

vector<int> print(vector<vector<int> > matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> res;

	if (row == 0 || col == 0) return res;

	int left = 0, top = 0, right = col - 1, bottom = row - 1;

	while (left <= right && top <= bottom) {
		// left to right
		for (int i = left; i <= right; ++i)
			res.push_back(matrix[top][i]);
		// top to bottom
		for (int i = top + 1; i <= bottom; ++i)
			res.push_back(matrix[i][right]);
		// right to left
		if (top != bottom) {
			for (int i = right - 1; i >= left; --i)
				res.push_back(matrix[bottom][i]);
		}
		// bottom to top
		if (left != right) {
			for (int i = bottom - 1; i > top; --i)
				res.push_back(matrix[i][left]);
		}

		left++, top++, right--, bottom--;
	}

	return res;
}

int test(void)
{
	vector<vector<int> > matrix = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };

	vector<int> ret = print(matrix);
	for (vector<int>::iterator iter = ret.begin(); iter != ret.end(); iter++) {
		cout << *iter << endl;
	}
	
	return 0;
}