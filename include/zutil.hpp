#pragma once
#ifdef ZUTIL_EXPORTS
#define ZUTIL_API __declspec(dllexport)
#else
#define ZUTIL_API __declspec(dllimport)
#endif

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<Windows.h>

namespace zutil
{
	class ZUTIL_API FileOperator
	{
	public:
		// constructor (input filename from explorer)
		FileOperator();
		// constructor (input filename)
		FileOperator(std::string iFileName);
		//destructor
		~FileOperator();

		// get path of input
		std::string getPath();
		// get name of input without extension
		std::string getName();
		// get name of input with extension
		std::string getNameWithExt();
		// get extension of input
		std::string getExt();
		// get path and name of input without ext
		std::string getNonExt();
		// get path and name and extension
		std::string getPathNameExt();

	private:
		bool getFileNameFromExplorer(HWND hWnd, char* fname, int size, const char* initDir, char* title);

	private:
		std::string input_;
		std::string path_;
		std::string name_;
		std::string ext_;
	};

	enum VECTOR_ARRAY_MAJOR
	{
		COL_MAJOR = 0,
		ROW_MAJOR = 1
	};

	// load csv as vector
	ZUTIL_API void csvLoad(std::string iFilename, std::vector<double>& oVec, int flag = ROW_MAJOR);
	ZUTIL_API void csvLoad(std::string iFilename, std::vector<int>& oVec, int flag = ROW_MAJOR);

	// load csv as matrix
	ZUTIL_API void csvLoad(std::string iFilename, std::vector<std::vector<double>>& oArr);
	ZUTIL_API void csvLoad(std::string iFilename, std::vector<std::vector<int>>& oArr);

	// convert string to number
	ZUTIL_API void str2num(std::string &str, double* num);
	ZUTIL_API void str2num(std::string &str, int* num);


}