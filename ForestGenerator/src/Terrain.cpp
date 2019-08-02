#include "Terrain.h"

void Terrain::generate()
{
  noise::module::Perlin perlinModule;

/*  perlinModule.SetOctaveCount(m_octaves);
  perlinModule.SetFrequency(m_frequency);
  perlinModule.SetPersistence(m_persistence);
  perlinModule.SetLacunarity(m_lacunarity);
*/
  //float height = float(perlinModule.GetValue(getX(i)/10,getY(i)/10,m_seed));

  perlinModule.SetFrequency(0.1);

  m_vertices = {{}};
  m_indices = {{}};
  float startVal = m_width*0.5f;
  float spacing = m_width/(m_numRows-1);

  for(size_t i=0; i<m_numRows; i++)
  {
    m_vertices[0].push_back({-startVal,
                             float(perlinModule.GetValue(double(-startVal),double(-startVal + i*spacing),0))*2,
                             -startVal + i*spacing});
    for(size_t j=0; j<m_numRows-1; j++)
    {
      m_vertices[0].push_back({-startVal + (j+1)*spacing,
                               float(perlinModule.GetValue(double(-startVal + (j+1)*spacing),double(-startVal + i*spacing),0))*2,
                               -startVal + i*spacing});
    }
  }

/*  for(float a=-startVal; a<=startVal; a+=spacing)
  {
    m_vertices.push_back({-startVal,
                          float(perlinModule.GetValue(double(-startVal),double(a),0))*2,
                          a});
    for(float b=-startVal; b<startVal; b+=spacing)
    {
      m_vertices.push_back({b+spacing,
                            float(perlinModule.GetValue(double(b+spacing),double(a),0))*2,
                            a});
    }
  }*/

  for(size_t j=0; j<m_numRows-2; j++)
  {
    if(j%2==0)
    {
      for(size_t i=0; i<m_numRows; i++)
      {
        m_indices[0].push_back(getIndex(i,j));
        m_indices[0].push_back(getIndex(i,j+1));
      }
    }
    else
    {
      for(size_t i=0; i<m_numRows; i++)
      {
        m_indices[0].push_back(getIndex(m_numRows-1-i,j));
        m_indices[0].push_back(getIndex(m_numRows-1-i,j+1));
      }
    }
  }
}

GLshort Terrain::getIndex(size_t _x, size_t _z)
{
  return GLshort(_z*m_numRows+_x);
}
