#ifndef DATATABLE_H
#define DATATABLE_H
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <numeric>
#include <cmath>

namespace w8
{
	/*!Templated class DataTable that holds a dataset of xy coordinates. */
	template <typename T>
	class DataTable
	{

		std::vector<T> x;
		std::vector<T> y;

		unsigned m_width, m_decimals;

	public:

		/*!DataTable constructor that recieves a reference to an fstream object, and two unsigned integers for width formatting and decimal places to output.*/
		DataTable(std::ifstream& fs, unsigned width, unsigned decimals) : m_width{ width }, m_decimals{ decimals }
		{
			T tmp;
			bool isX = true; //tracks whether the next value is x or y

			while (fs >> tmp)
			{
				(isX) ? x.push_back(tmp) : y.push_back(tmp);
				isX = !isX;	//switch boolean values per iteration
			}
		}

		/*!Member function query that returns the mean or average of all y values.*/
		T mean() const
		{
			return std::accumulate(y.begin(), y.end(), (T)0) / y.size();
		}

		/*!Member function query that returns the standard deviation of the dataset.*/
		T sigma() const
		{
			std::vector<T> tmp = y;

			for (size_t i = 0; i < tmp.size(); i++)
			{
				tmp[i] = std::pow(tmp[i] - mean(), 2);	//subtract mean and square element at index i.
			}

			return std::sqrt(std::accumulate(tmp.begin(), tmp.end(), (T)0) * (1.0 / (T)tmp.size()));
		}

		/*!Member function query that returns the median of the dataset.*/
		T median() const
		{
			std::vector<T> tmp = y;
			std::sort(tmp.begin(), tmp.end());

			return tmp[tmp.size() / 2];
		}

		/*!Member query function that calculates and sets the value inside the received referenced slope and y_intercept of datatype T*/
		void regression(T& slope, T& y_intercept) const
		{
			//declare for readability
			//get mean of x and y
			//average of yMean defined in mean()
			T xMean = std::accumulate(x.begin(), x.end(), (T)0) / x.size();

			//x and y of slope
			T rise = 0;
			T run = 0;

			for (int i = 0; i < y.size(); i++)
			{
				rise += (x.at(i) - xMean) * (y.at(i) - mean());
				run += std::pow((x.at(i) - xMean), 2);
			}

			slope = rise / run;
			y_intercept = mean() - (slope * xMean);
		}

		/*!Member query function that displays the the DataTable object details to the referenced ostream object received.*/
		void display(std::ostream& os) const
		{
			os << std::setw(m_width) << "x" << std::setw(m_width) << "y" << std::endl;

			for (int i = 0; i < y.size(); i++)
			{
				os << std::setw(m_width) << std::fixed << std::setprecision(m_decimals) << x.at(i) << std::setw(m_width) << y.at(i) << std::endl;
			}
		}
	};

	/*!Helper function that outputs the details of the DataTable object used with the (<<) overloaded operator to the ostream object reference received.*/
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& obj)
	{
		obj.display(os);
		return os;
	}
}

#endif //DATATABLE_H

