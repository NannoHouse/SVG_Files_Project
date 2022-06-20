#pragma once
#include "String.h"
#include<fstream>


/// Virtal class holding pure virtual functions which need to be implemented in every single inherited class
class Shape {
public:
	/// <summary>
	/// Virtual destructor 
	/// </summary>
	virtual  ~Shape() = default;


	/// <summary>
	/// Clone function 
	/// </summary>
	/// <returns></returns>
	virtual Shape* clone()  = 0;


	/// <summary>
	/// Print function -> prints data of the shape on the console
	/// </summary>
	virtual void print() const = 0;


	/// <summary>
	/// getType -> returns the type of the shape
	/// </summary>
	/// <returns></returns>
	virtual String getType() = 0;


	/// <summary>
	/// Bool function isWithinCircle checks if a shape is inside the circle with given parameters or not
	/// </summary>
	/// <param name="cx"></param>
	/// <param name="cy"></param>
	/// <param name="radius"></param>
	/// <returns></returns>
	virtual bool isWithinCircle(int cx, int cy, int radius) = 0;


	/// <summary>
	/// Bool function isWithinRectangle checks if a shape is inside a given rectangle with parameters
	/// </summary>
	/// <param name="rx"></param>
	/// <param name="ry"></param>
	/// <param name="width"></param>
	/// <param name="hight"></param>
	/// <returns></returns>
	virtual bool isWithinRectangle(int rx, int ry, int width, int hight) = 0;


	/// <summary>
	/// setX sets X value
	/// </summary>
	/// <param name="number"></param>
	virtual void setX( int& number) =0;


	/// <summary>
	/// setY sets Y value 
	/// </summary>
	/// <param name="number"></param>
	virtual void setY( int& number)=0;


	/// <summary>
	/// getY returns X value
	/// </summary>
	/// <returns></returns>
	virtual int getX() const = 0;


	/// <summary>
	/// getY returns Y value
	/// </summary>
	/// <returns></returns>
	virtual int getY() const  = 0;


	/// <summary>
	/// write function writes a shape in file
	/// </summary>
	/// <param name="out"></param>
	virtual void write(std::ofstream& out) const = 0;

	/// <summary>
	/// read function reads all the values of a shape and sets them
	/// </summary>
	virtual void read() = 0;
};