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
#ifndef P12218319_CIO_ACKLEY_HPP
#define P12218319_CIO_ACKLEY_HPP

#include "Problem.hpp"

namespace P12218319 { namespace cio {
	template<const uint32_t DIMENTIONS>
	class P12218319_EXPORT_API Ackley : public Problem<DIMENTIONS> {
	public:
		double P12218319_CALL operator()(typename Problem<DIMENTIONS>::InputArray& x) const override throw() {
			const double a = 20.f;
			const double b = 0.2f;
			const double c = 2.f * PI;
		
			double squareSum = 0.f;		
			double cosSum = 0.f;
			for(uint32_t i = 0; i < DIMENTIONS; ++i) {
				squareSum += std::pow(x[i], 2.f);
				cosSum += std::cos(c*x[i]);
			}

			return y = -a * std::exp(-b * std::sqrt(squareSum/DIMENTIONS)) - std::exp(cosSum/DIMENTIONS) + a + std::exp(1);
		}
	};
}}

#endif