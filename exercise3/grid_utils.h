//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute! 
// Copyright (C) 2015-2017 CGV TU Dresden - All Rights Reserved
//
#pragma once

#include <array>
#include <cgv/math/fvec.h>

typedef cgv::math::fvec<float, 3> vec3;
typedef std::array<int, 3> index3;

//converts 3d floating point position pos into 3d integer grid cell index
inline index3 position_2_cell_index(const vec3& pos, const vec3& cell_extents) 
{
	index3 idx;
	for(int d = 0; d < 3; ++d)
	{
		idx[d] = int(pos[d]/cell_extents[d]);
			if (pos[d] < 0)
				--idx[d];
	}
	return idx;	
}

//returns true if the two interval [lb1,ub2] and [lb2,ub2] overlap 
inline bool overlap_intervals(float lb1, float ub1, float lb2, float ub2)
{
	if(lb1 > ub1) 
			std::swap(lb1,ub1);
	if(lb2 > ub2) 
			std::swap(lb2,ub2);
	if(ub1 < lb2|| lb1 >ub2)
		return false;
	return true;	
}

