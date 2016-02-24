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
#ifndef P12218319_CIO_CMAES_HPP
#define P12218319_CIO_CMAES_HPP

#include "Algorithm.hpp"

namespace P12218319 { namespace cio {
	template<const uint32_t DIMENTIONS>
	class P12218319_EXPORT_API ISPO : public Algorithm {
	public:
		FTrend P12218319_CALL operator()(const Problem<DIMENTIONS>& problem, const uint32_t maxEvaluations) const override {
			FTrend FT; //Use this object to store solutions

			double[] best[DIMENTIONS];
			double fBest = NAN;
			int j = 0;
			if(initialSolution != null) {
				best = initialSolution;
				fBest = initialFitness;
			}else { //if not inserted, we need to randomly sample the initial guess
				best = generateRandomSolution(problem.mBounds);
				fBest = problem(best);
				FT.push_back(fBest);
				++j;
			}
			// new a CMA-ES and set some initial values
			/*CMAEvolutionStrategy cma = new CMAEvolutionStrategy();
			cma.setRepairMatrix(true);				// repair ill-conditioned matrix
			cma.setDimension(DIMENTIONS);		// overwrite some loaded properties
			cma.setInitialX(best);					// in each dimension, also setTypicalX can be used
			cma.setInitialStandardDeviation(0.2);	// also a mandatory setting 
			cma.options.verbosity = -1;
			cma.options.writeDisplayToFile = -1;

			// initialize cma and get fitness array to fill in later
			double[] fitness = cma.init();

			// iteration loop
			while (j < maxEvaluations)
			{
				// --- core iteration step ---
				// get a new population of solutions
				double[][] pop = cma.samplePopulation();

				for (int i = 0; i < pop.length && j < maxEvaluations; ++i)
				{
					// saturate solution on problem.mBounds 
					pop[i] = saturate(pop[i], problem.mBounds);

					// compute fitness/objective value	
					fitness[i] = problem.f(pop[i]);

					// save best
					if (fitness[i] < fBest)
					{
						fBest = fitness[i];
						for (int n = 0; n < DIMENTIONS; n++)
							best[n] = pop[i][n];
						FT.add(j, fBest);//add the best solution found in this iteration to the fitness trend (it will be saved in a txt file)
					}

					j++;
				}

				// pass fitness array to update search distribution
				cma.updateDistribution(fitness);
			}

			finalBest = best;

			//add the best solutionat the end f the fitness trend
			FT.add(j, fBest);*/

			//return bests;
			return FT;
		}
	};
}}

#endif