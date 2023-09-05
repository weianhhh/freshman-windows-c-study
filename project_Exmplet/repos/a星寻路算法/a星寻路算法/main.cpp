#include <iostream>
#include <vector>
#pragma warning(disable:26495)
using namespace std;
#define rows 10 
#define cols 10

#define ZXDJ 10
#define XXDJ 14
enum dirent
{
	p_up,p_down,p_left,p_right,p_lup,p_ldown,p_rup,p_rdown
};
struct MyPoint 
{
	int row, col;
	int f, g, h;
};
struct treeNode
{
	MyPoint pos;
	vector<treeNode*> childe;
	treeNode* pParent;
};

treeNode* createTreeNode(int row, int col) {
	treeNode* pNew = new treeNode;
	memset(pNew, 0, sizeof(treeNode));
	pNew->pos.row = row;
	pNew->pos.col = col;
	return pNew;
}
int getH(MyPoint pos,MyPoint endPos)
{
	int x = ((endPos.col > pos.col)? (endPos.col - pos.col) : (pos.col - endPos.col));
	int y = ((endPos.row > pos.row) ? (endPos.row - pos.row) : (pos.row - endPos.row));
	return ZXDJ * (x + y);
}
int main()
{
	int map[rows][cols] = {
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,1,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
	};
	bool pathMap[rows][cols] = { 0 };


	MyPoint begPos = { 2,1 };
	MyPoint endpos = { 6,7 };
	treeNode* pRoot = createTreeNode(begPos.row, begPos.col);
	pathMap[begPos.row][begPos.col] = true;

	vector<treeNode*>buff;
	vector<treeNode*>::iterator it;
	vector<treeNode*>::iterator itMin;
	treeNode* pCurrent = pRoot;
	treeNode* pChild = NULL;
	bool isFindEnd = false;
	while (true)
	{
		for (int i = 0; i < 8; i++) {
			pChild = createTreeNode(pCurrent->pos.row, pCurrent->pos.col);
			switch (i)
			{
			case p_up:
				pChild->pos.row--;
				pChild->pos.g += ZXDJ;
				break;
			case p_down:
				pChild->pos.row++;
				pChild->pos.g += ZXDJ;
				break;
			case p_left:
				pChild->pos.col--;
				pChild->pos.g += ZXDJ;
				break;
			case p_right:
				pChild->pos.col++;
				pChild->pos.g += ZXDJ;
				break;
			case p_lup:
				pChild->pos.col--;
				pChild->pos.row--;
				pChild->pos.g += XXDJ;
				break;
			case p_ldown:
				pChild->pos.col++;
				pChild->pos.row--;
				pChild->pos.g += XXDJ;
				break;
			case p_rup:
				pChild->pos.col++;
				pChild->pos.row--;
				pChild->pos.g += XXDJ;
				break;
			case p_rdown:
				pChild->pos.col++;
				pChild->pos.row++;
				pChild->pos.g += XXDJ;
				break;
			}
			if (0 == map[pChild->pos.row][pChild->pos.col] && false == pathMap[pChild->pos.row][pChild->pos.col]) {
				pChild->pos.h = getH(pChild->pos, endpos);
				pChild->pos.f = pChild->pos.g + pChild->pos.h;

				pCurrent->childe.push_back(pChild);
				pChild->pParent = pCurrent;
				buff.push_back(pChild);

			}
			else {
				delete pChild;
			}
		}
		it = buff.begin();
		itMin = buff.begin();
		for (;it != buff.end();it++)
		{
			itMin = (((*itMin)->pos.f < (*it)->pos.f) ? itMin : it);
		}
		pCurrent = *itMin;
		pathMap[pCurrent->pos.row][pCurrent->pos.col] = true;
		buff.erase(itMin);
		if (endpos.row == pCurrent->pos.row && endpos.col == pCurrent->pos.col) {
			isFindEnd = true;
			break;
		}
		if (buff.size() == 0) { break; }
		if (isFindEnd) {
			printf("找到终点啦!@*@!\n,路径是:"); 
			while (pCurrent)
			{
				printf("(%d,%d)",pCurrent->pos.row,pCurrent->pos.col);
				pCurrent = pCurrent->pParent;
			}
			printf("\n");
		}
		else { printf("没有找到终点!|*|\n"); }
	}
	return 0;
}