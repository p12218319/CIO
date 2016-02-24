/*
	Copyright 2016 Adam Smith & Fabio Caraffini (Original Java version)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
   
   email : p12218319@myemail.dmu.ac.uk
*/
#ifndef P12218319_CIO_ALGORITHM_HPP
#define P12218319_CIO_ALGORITHM_HPP

#include <vector>
#include "..\benchmarks\Problem.hpp"


namespace P12218319 { namespace cio {
	typedef std::vector<double> FTrend;

	template<const uint32_t DIMENTIONS>
	class P12218319_EXPORT_API Algorithm {
	public:
		enum {
			MAX_PARAMS = 16
		};
	protected:
		double mParams[MAX_PARAMS];
		double mBounds[DIMENTIONS][0];
	protected:
		double P12218319_CALL GenerateRandomSolution(BoundArray&) const;
	public:
		virtual P12218319_CALL ~Algorithm() {}
		virtual FTrend P12218319_CALL operator()(const Problem<DIMENTIONS>&, const uint32_t) const = 0;
	};
}}

#endif