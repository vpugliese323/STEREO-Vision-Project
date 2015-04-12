/*
This code is designed to read files containing polar coordinates

Coordinate format: (r, theta, phi)
Where theta is from vertical and phi is from horizontal
Assumes r is in centimeters, and theta and phi are in degrees

Why use a struct as opposed to a class?
Because this code is meant to be easily portable to C
*/

#include <iostream>

using namespace std;

struct world
{
	int readfile()//reads coordinates from txt files
	{
		//do stuff
	}
	//int graph[][3];//vector array containing points from scan
	//update changed to pointer to allow for "returning" array
	//"point" in this part of code is (theta, phi), r is ignored b/c unknown
	int search(int point[], int graph[129600][3])//find point to change in graph
//changed from int *update(.....
	{
		//Begin with binary search for point
		int arraysize = sizeof(graph)/sizeof(int);//finds graph length
		int a = graph[arraysize][2];//high
		int b = graph[0][2];//low
		int midpoint = int((b-a)/2);//partitions
		while(graph[midpoint][2] != point[1])//compares phi
		{
			if (graph[midpoint][2] < point[1])//relation test
			{
				midpoint = int((midpoint-a)/2);//repartition
			}
			if (graph[midpoint][2] > point[1])//relation test
			{
				midpoint = int((b-midpoint)/2);//repartition
			}
		}

	//Need to find theta within unknown bound of phi
	//This program assumes degree values for positions are integers
	//This program also assumes data contains scans from all 360 degrees
	//Solution is to jump up or down to position and check

		if (graph[midpoint][1] < point[0])//relation test
		{
			//change position
			midpoint += point[0] - graph[midpoint][1];
		}
		else if (graph[midpoint][1] > point[1])//relation test
		{
			//change position
			midpoint -= point[0] - graph[midpoint][1];
		}
		//final relation test
		if ((graph[midpoint][1] == point[0])&&(graph[midpoint][2] == point[1]))
		{
			/*int x = graph[midpoint][0];//r
			int y = graph[midpoint][1];//theta
			int z = graph[midpoint][2];//phi*/
			//return x, y, z;

			return midpoint;//Returns location in array
		}
		else
		{
			cout << "ERROR\n";
		}
	}
	int insert(int insertpoint, int graph[][3])
	{
		//do stuff
	}
} myworld;

int main()
{
	//world myworld;
	//int arr[][2] = {(1, 0, 0), (8, 1, 0), (3, 0, 1), (7, 1, 1)};
	int graph[][3] = {{1, 0, 0}, {8, 1, 0}, {3, 0, 1}, {7, 1, 1}};
	//int mygraph[][2] = myworld.graph;
	//int arr[][2] = {(1, 0, 0), (8, 1, 0), (3, 0, 1), (7, 1, 1)};
	int point[] = {1, 0};
	int insertpoint = myworld.search(point, graph);
	//int insertpoint[] = {a, b, c};
	//myworld.update(point, graph);
	cout << insertpoint;
	cin.get();
	cin.ignore();

	return 0;
}
