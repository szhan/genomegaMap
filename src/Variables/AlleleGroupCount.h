/*  Copyright 2018 Daniel Wilson.
 *
 *  Part of the omegaMap library.
 *
 *  The omegaMap library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  The omegaMap library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with the omegaMap library. If not, see <http://www.gnu.org/licenses/>.
 */
/*
 *  AlleleGroupCount.h
 *  gcat
 *
 *  Created by Daniel Wilson on 10/17/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef _ALLELE_GROUP_COUNT_VARIABLE_H_
#define _ALLELE_GROUP_COUNT_VARIABLE_H_
#include <DAG/Value.h>
#include <vector>
#include <myerror.h>
#include <Properties/Length.h>

using std::vector;

using namespace gcat;

namespace gcat_omegaMap {
	
class AlleleGroupCount : public Value, public LengthProperty {
public:
	// Constructor
	AlleleGroupCount() {};
	// Copy constructor
	AlleleGroupCount(const AlleleGroupCount &x) {};
	// Destructor
	virtual ~AlleleGroupCount() {};
	
	// Report encoding
	virtual vector<string> encoding() const = 0;
	// Number of groups
	virtual int n_groups() const = 0;
	// Number of sequences
	virtual int n(const int gp) const = 0;
	// Sequence length: assumed same for all. Inherited from LengthProperty
	//virtual int length() const = 0;
	// Return the counts for a particular group
	virtual const vector< vector<int> >& operator[](const int gp) const = 0;
	
	// Print header (implementation of inherited method)
	virtual void print_header(ostream& out, string sep) {
		myutils::warning("AlleleGroupCount::print_header(): no print method available");
	}
	// Print value (implementation of inherited method)	
	virtual void print(ostream& out, string sep) {
	}
};
	
} // namespace gcat_omegaMap

#endif // _ALLELE_GROUP_COUNT_VARIABLE_H_

