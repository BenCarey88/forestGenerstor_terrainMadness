//----------------------------------------------------------------------------------------------------------------------
/// @file WindowParams.h
/// @author Jonathan Macey
/// @version 2.0
/// @date 05/07/19
/// Revision History :
/// 10/9/13: This is an initial version used for the new NGL6 / Qt 5 demos
/// 05/07/19: updated by Ben Carey for use in ForestGenerator project
//----------------------------------------------------------------------------------------------------------------------

#ifndef WINDOWPARAMS_H_
#define WINDOWPARAMS_H_

//----------------------------------------------------------------------------------------------------------------------
/// @struct WinParams
/// @brief this struct stores attributes for the QTWidget window used for things like mouse events
//----------------------------------------------------------------------------------------------------------------------


struct WinParams
{
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to store the x rotation mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int spinXFace=0;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to store the y rotation mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int spinYFace=0;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief flag to indicate if the mouse button is pressed when dragging
  //----------------------------------------------------------------------------------------------------------------------
  bool rotate=false;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief flag to indicate if the middle mouse button is pressed when dragging
  //----------------------------------------------------------------------------------------------------------------------
  bool translate=false;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous x mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int origX=0;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous y mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int origY=0;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous x mouse value for Position changes
  //----------------------------------------------------------------------------------------------------------------------
  int origXPos=0;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous y mouse value for Position changes
  //----------------------------------------------------------------------------------------------------------------------
  int origYPos=0;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief window width
  //----------------------------------------------------------------------------------------------------------------------
  int width=1024;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief window height
  //----------------------------------------------------------------------------------------------------------------------
  int height=720;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief window scale
  //----------------------------------------------------------------------------------------------------------------------
  float scale=1;
};

//----------------------------------------------------------------------------------------------------------------------
/// @brief the increment for x/y translation with mouse movement
//----------------------------------------------------------------------------------------------------------------------
constexpr float INCREMENT=0.1f;
//----------------------------------------------------------------------------------------------------------------------
/// @brief the increment for the wheel zoom
//----------------------------------------------------------------------------------------------------------------------
constexpr float ZOOM=0.2f;

//----------------------------------------------------------------------------------------------------------------------
/// @brief the nearFrame of the camera view
//----------------------------------------------------------------------------------------------------------------------
constexpr float nearFrame = 0.05f;
//----------------------------------------------------------------------------------------------------------------------
/// @brief the farFrame of the camera view
//----------------------------------------------------------------------------------------------------------------------
constexpr float farFrame = 10000.0f;
//----------------------------------------------------------------------------------------------------------------------
/// @brief the field of view of the camera
//----------------------------------------------------------------------------------------------------------------------
constexpr float fieldOfView = 45.0f;

#endif //WINDOWPARAMS_H_
