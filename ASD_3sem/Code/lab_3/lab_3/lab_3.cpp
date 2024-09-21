//<-------------------->
//Deikstra's algorythm for graph where each edge has a weight
// 
// 
//<-------------------->
#include <iostream>
#define INF INT_MAX
using namespace std;

const int NodesInGraph = 9;				// A  B  C  D  E  F  G  H  I
int Graph[NodesInGraph][NodesInGraph] = { {0, 7, 10,0 ,0 ,0, 0, 0, 0},//A
										  {7, 0, 0, 0, 0, 9, 27,0, 0},//B
										  {10,0, 0, 0, 31,8, 0, 0, 0},//C
										  {0, 0, 0, 0, 32,0, 0, 17,21},//D
										  {0, 0, 31,32,0, 0, 0, 0, 0},//E
										  {0, 9, 8, 0, 0, 0, 0, 11,0},//F
										  {0, 27,0, 0, 0, 0, 0, 0, 15},//G
										  {0, 0, 0, 17,0, 11,0, 0, 15},//H
										  {0, 0, 0, 21,0, 0, 15,15, 0}};//I


void main()
{

}