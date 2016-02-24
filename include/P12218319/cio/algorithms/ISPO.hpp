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
#ifndef P12218319_CIO_ISPO_HPP
#define P12218319_CIO_ISPO_HPP

#include "Algorithm.hpp"

namespace P12218319 { namespace cio {
	template<const uint32_t DIMENTIONS>
	class P12218319_EXPORT_API ISPO : public Algorithm {
	public:
		FTrend P12218319_CALL operator()(const Problem<DIMENTIONS>& problem, const uint32_t maxEvaluations) const override {
			// first, we need to define variables for storing the paramters of the algorithm
			double A = mParams[0];
			double P = mParams[1];
			int B = static_cast<int>(mParams[2]));
			int S = static_cast<int>(mParams[3]);
			double E = mParams[4];
			int PartLoop = static_cast<int>(mParams[5]);

			//we always need an object FTrend (for storing the fitness trend), and variables for storing the dimesionality and the bounds of the problem
			FTrend FT;

			// particle (the solution)
			double particle[DIMENTIONS];
			double fParticle;
			uint32_t i = 0;
			// initial solution
			if(initialSolution != null) {
				particle = initialSolution;
				fParticle = initialFitness;
			}else {//random intitial guess
				particle = generateRandomSolution();
				fParticle = problem(particle);
				++i;
			}
			//store the initital guess
			FT.push_back(fParticle);

			// temp variables
			double L = 0.0;
			double velocity = 0.0;
			double oldfFParticle = fParticle;
			double posOld;

			//main loop
			while(i < maxEvaluations){
				for(uint32_t j = 0; j < DIMENTIONS && i < maxEvaluations; ++j){
					// init learning factor
					L = 0;

					// for each part loop
					for(uint32_t k = 0; k < PartLoop && i < maxEvaluations; k++) {
						// old fitness value
						oldfFParticle = fParticle;
						// old particle position
						posOld = particle[j];

						// calculate velocity
						velocity = A / std::pow(k + 1, P)*(-0.5 + rand()) + B*L;

						// calculate new position
						particle[j] += velocity;
						particle[j] = std::min(std::max(particle[j], problem.mBounds[j][0]), problem.mBounds[j][1]);

						// calculate new fitness
						fParticle = problem(particle);
						++i;//iteration couter has to be incremented

						// estimate performance
						if(oldfFParticle < fParticle) {
							// adjust learning factor
							if(L != 0) L /= S;
							if(std::abs(L) < E) L = 0;
							// use old position
							particle[j] = posOld;
							fParticle = oldfFParticle;
						} else {
							// use current velocity as learning factor
							L = velocity;
						}

						if(i % DIMENTIONS == 0) FT.push_back(fParticle);
					}
				}
			}


			finalBest = particle; //save the final best
			FT.push_back(fParticle);//add it to the txt file (row data)


			return FT; //return the fitness trend
		}
	};
}}

#endif