//----------------------------------------------------------------------------------------------------------------------
/// @file Camera.h
/// @author Ben Carey
/// @version 1.0
/// @date 23/01/19 updated to NCCA coding standards
/// Revision History :
/// Initial Version 21/01/19 used for ASE terrainGeneration project
//----------------------------------------------------------------------------------------------------------------------

#ifndef CAMERA_H_
#define CAMERA_H_

#include <iostream>
#include <vector>
#include <ngl/Vec3.h>

//----------------------------------------------------------------------------------------------------------------------
/// @class Camera
/// @brief this struct stores the details of the camera for NGLScene
//----------------------------------------------------------------------------------------------------------------------


struct Camera
{
  //CONSTRUCTOR
  //--------------------------------------------------------------------------------------------------------------------
  /// @brief ctor for Camera struct - uses reset function so I only have to change the default values in one place
  //--------------------------------------------------------------------------------------------------------------------
  Camera();

  Camera(ngl::Vec3 _initialFrom, ngl::Vec3 _initialTo,
         ngl::Vec3 _initialUp, ngl::Vec3 _initialAxis);

  //MEMBER VARIABLES
  //--------------------------------------------------------------------------------------------------------------------
  /// @brief position vector of the camera
  //--------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_from;
  //--------------------------------------------------------------------------------------------------------------------
  /// @brief position vector the camera is pointed at
  //--------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_to;
  //--------------------------------------------------------------------------------------------------------------------
  /// @brief the up direction of the camera
  //--------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_up;
  //--------------------------------------------------------------------------------------------------------------------
  /// @brief the vector for us to rotate around when we move the mouse horizontally
  //--------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_axis;

  //--------------------------------------------------------------------------------------------------------------------
  /// @brief
  //--------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_initialFrom = {0,40,50};
  //--------------------------------------------------------------------------------------------------------------------
  /// @brief
  //--------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_initialTo = {0,10,0};
  //--------------------------------------------------------------------------------------------------------------------
  /// @brief
  //--------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_initialUp = {0,1,0};
  //--------------------------------------------------------------------------------------------------------------------
  /// @brief
  //--------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_initialAxis = {0,1,0};

  //METHODS
  //--------------------------------------------------------------------------------------------------------------------
  /// @brief called to reset the values of the camera
  //--------------------------------------------------------------------------------------------------------------------
  void reset();

};


#endif //CAMERA_H_
