#include "Point.hpp"

int main()
{
	{
		Point a(0, 0);
		Point b(2, 5);
		Point c(5, 0);
		Point p1(2, 4);
		Point p2(0, 9);
		
		std::cout <<"// Test 1 // (0,0), (2,5), (5,0)" << std::endl <<  "Point (2,4) is ";
		if (bsp(a, b, c, p1) == true)
			std::cout << "inside";
		else
			std::cout << "outside";
		std::cout << " of the triangle" << std::endl;
		std::cout << "Point (0,9) is ";
		if (bsp(a, b, c, p2) == true)
			std::cout << "inside";
		else
			std::cout << "outside";
		std::cout << " of the triangle" << std::endl;
	}
	{
		Point a(10, 5);
		Point b(6, 1);
		Point c(8, 6);
		Point p1(8, 4);
		Point p2(6, 4);
		
		std::cout << std::endl << "// Test 2 // (10,5), (6,1), (8,6)" << std::endl  << "Point (8,4) is ";
		if (bsp(a, b, c, p1) == true)
			std::cout << "inside";
		else
			std::cout << "outside";
		std::cout << " of the triangle" << std::endl;
		std::cout << "Point (6,4) is ";
		if (bsp(a, b, c, p2) == true)
			std::cout << "inside";
		else
			std::cout << "outside";
		std::cout << " of the triangle" << std::endl;
	}
	{
		Point a(-5, -5);
		Point b(-1, -6);
		Point c(-4, -2);
		Point p1(-3, -4);
		Point p2(3, 4);
		
		std::cout << std::endl << "// Test 3 // (-5,-5), (-1,-6), (-4,-2)" << std::endl  << "Point (-3,-4) is ";
		if (bsp(a, b, c, p1) == true)
			std::cout << "inside";
		else
			std::cout << "outside";
		std::cout << " of the triangle" << std::endl;
		std::cout << "Point (3,4) is ";
		if (bsp(a, b, c, p2) == true)
			std::cout << "inside";
		else
			std::cout << "outside";
		std::cout << " of the triangle" << std::endl;
	}
	{
		Point a(5, 5);
		Point b(1, 6);
		Point c(4, 2);
		Point p1(3, 4);
		Point p2(-3, -4);
		
		std::cout << std::endl << "// Test 4 // (5,5), (1,6), (4,2)" << std::endl  << "Point (3,4) is ";
		if (bsp(a, b, c, p1) == true)
			std::cout << "inside";
		else
			std::cout << "outside";
		std::cout << " of the triangle" << std::endl;
		std::cout << "Point (-3,-4) is ";
		if (bsp(a, b, c, p2) == true)
			std::cout << "inside";
		else
			std::cout << "outside";
		std::cout << " of the triangle" << std::endl;
	}
	{
		Point a(2, 2);
		Point b(6, 2);
		Point c(4, 6);
		Point p1(4, 3);
		Point p2(5, 4);
		
		std::cout << std::endl << "// Test 5 // (2,2), (6,2), (4,6)" << std::endl  << "Point (4,3) is ";
		if (bsp(a, b, c, p1) == true)
			std::cout << "inside";
		else
			std::cout << "outside";
		std::cout << " of the triangle" << std::endl;
		std::cout << "Point (5,4) is ";
		if (bsp(a, b, c, p2) == true)
			std::cout << "inside";
		else
			std::cout << "outside";
		std::cout << " of the triangle" << std::endl;
	}
	return 0;
}