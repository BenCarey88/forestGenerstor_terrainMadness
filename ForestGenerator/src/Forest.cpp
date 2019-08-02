//----------------------------------------------------------------------------------------------------------------------
/// @file Forest.cpp
/// @brief implementation file for LSystem class
//----------------------------------------------------------------------------------------------------------------------

#include <math.h>
#include <chrono>
#include "Forest.h"
#include "noiseutils.h"

Forest::Forest(const std::vector<LSystem> &_treeTypes, float _width, float _length, size_t _numTrees, int _numHeroTrees) :
  m_treeTypes(_treeTypes), m_width(_width), m_length(_length), m_numTrees(_numTrees), m_numHeroTrees(_numHeroTrees)
{
  scatterForest();

  for(auto &treeType : m_treeTypes)
  {
    treeType.fillInstanceCache(m_numHeroTrees);
  }

  createForest();
}


//----------------------------------------------------------------------------------------------------------------------

Forest::Tree::Tree(size_t _type, ngl::Mat4 _transform) :
  m_type(_type), m_transform(_transform) {}

Forest::OutputData::OutputData(ngl::Mat4 _transform, size_t _treeType,
                               size_t _id, size_t _age, size_t _innerIndex) :
  m_transform(_transform), m_treeType(_treeType),
  m_id(_id), m_age(_age), m_innerIndex(_innerIndex) {}

void Forest::resizeTransformCache()
{
  m_transformCache={};
  m_transformCache.resize(m_treeTypes.size());
  for(size_t t=0; t<m_treeTypes.size(); t++)
  {
    RESIZE_CACHE_BY_OTHER_CACHE(m_transformCache[t], m_treeTypes[t].m_instanceCache)
  }
}

//----------------------------------------------------------------------------------------------------------------------

void Forest::seedRandomEngine()
{
  size_t seed;
  if(m_useSeed)
  {
    seed = m_seed;
  }
  else
  {
    seed = size_t(std::chrono::system_clock::now().time_since_epoch().count());
  }
  m_gen.seed(seed);
}

//----------------------------------------------------------------------------------------------------------------------

void Forest::scatterForest()
{
  seedRandomEngine();
  m_treeData = {};

  std::uniform_real_distribution<float> distX(-m_width*0.5f, m_width*0.5f);
  std::uniform_real_distribution<float> distZ(-m_length*0.5f, m_length*0.5f);
  std::uniform_real_distribution<float> distRotate(0,360);
  std::uniform_real_distribution<float> distScale(0.6f,0.8f);
  std::uniform_int_distribution<size_t> distTreeType(0,m_treeTypes.size()-1);
  noise::module::Perlin perlinModule;

  perlinModule.SetFrequency(double(5/m_width));

  for(size_t i=0; i<m_numTrees; i++)
  {
    ngl::Mat4 position;
    ngl::Mat4 orientation;
    ngl::Mat4 scale;
    float xPos = distX(m_gen);
    float zPos = distZ(m_gen);
    float yPos = float(perlinModule.GetValue(double(xPos),double(zPos),m_seed))*std::sqrt(m_width);
    position.translate(xPos,yPos,zPos);
    orientation.rotateY(distRotate(m_gen));
    scale = distScale(m_gen)*scale;
    m_treeData.push_back(Tree(distTreeType(m_gen), position*orientation*scale));
  }
}

//----------------------------------------------------------------------------------------------------------------------

void Forest::createTree(size_t _treeType, ngl::Mat4 _transform, size_t _id, size_t _age)
{
  LSystem &treeType = m_treeTypes[_treeType];
  size_t size = treeType.m_instanceCache.at(_id).at(_age).size();
  if(size>0)
  {
    size_t innerIndex = 0;
    Instance * instance = getInstance(treeType, _id, _age, innerIndex);
    ngl::Mat4 T = _transform * instance->m_transform.inverse();
    m_transformCache.at(_treeType).at(_id).at(_age).at(innerIndex).push_back(T);

    for(size_t i=0; i<instance->m_exitPoints.size(); i++)
    {
      size_t newAge = instance->m_exitPoints[i].m_exitAge;
      size_t newId = instance->m_exitPoints[i].m_exitId;
      ngl::Mat4 exitTransform = instance->m_exitPoints[i].m_exitTransform;
      ngl::Mat4 newTransform = _transform * exitTransform;
      createTree(_treeType, newTransform, newId, newAge);
    }
  }
  else
  {
    std::cout<<"Couldn't find instance of tree type "<<treeType.m_name<<" with id "<<_id<<" at age "<<_age<<'\n';
  }
}

Instance * Forest::getInstance(LSystem &_treeType, size_t _id, size_t _age, size_t &_innerIndex)
{
  size_t size = _treeType.m_instanceCache.at(_id).at(_age).size();
  std::uniform_int_distribution<size_t> dist(0,size-1);
  _innerIndex = dist(m_gen);
  return &_treeType.m_instanceCache.at(_id).at(_age).at(_innerIndex);
}

//----------------------------------------------------------------------------------------------------------------------

void Forest::createForest()
{
  seedRandomEngine();
  resizeTransformCache();
  for(auto &tree : m_treeData)
    createTree(tree.m_type,tree.m_transform,0,0);
}
