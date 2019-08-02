//----------------------------------------------------------------------------------------------------------------------
/// @file Terrain.h
/// @author Ben Carey
/// @version 1.0
//----------------------------------------------------------------------------------------------------------------------

#ifndef TERRAIN_H_
#define TERRAIN_H_

#include <iostream>
#include <vector>
#include <ngl/Vec3.h>
#include "noiseutils.h"

//----------------------------------------------------------------------------------------------------------------------
/// @class Terrain
//----------------------------------------------------------------------------------------------------------------------

class Terrain
{
public:
  //CONSTRUCTOR FUNCTIONS
  //--------------------------------------------------------------------------------------------------------------------
  /// @brief default ctor for our Generator class
  //--------------------------------------------------------------------------------------------------------------------
  Terrain()=default;
  //--------------------------------------------------------------------------------------------------------------------
  //--------------------------------------------------------------------------------------------------------------------
  Terrain(int _dimension);
  //--------------------------------------------------------------------------------------------------------------------
  /// @brief default dtor for our Generator class
  //--------------------------------------------------------------------------------------------------------------------
  ~Terrain()=default;

  //PUBLIC MEMBER VARIABLES
  //--------------------------------------------------------------------------------------------------------------------
  std::vector<std::vector<ngl::Vec3>> m_vertices;
  std::vector<std::vector<GLshort>> m_indices;


  float m_width =100;
  size_t m_numRows = 250;

  //PUBLIC MEMBER FUNCTION
  //--------------------------------------------------------------------------------------------------------------------
  /// @brief assigns values to m_heightmap based on current noise attributes
  //--------------------------------------------------------------------------------------------------------------------
  void generate();

private:

  GLshort getIndex(size_t _x, size_t _y);

};

#endif //TERRAINGENERATOR_H_