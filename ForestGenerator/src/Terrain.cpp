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

  m_vertices = {};
  m_indices = {};
  m_vertexList = {};
  m_indexList = {};

  float startVal = m_width*0.5f;
  float spacing = m_width/(m_numRows-1);

/*  for(size_t i=0; i<m_numRows; i++)
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
  }*/

  for(float a=-startVal; a<=startVal; a+=spacing)
  {
    m_vertexList.push_back({-startVal,
                          float(perlinModule.GetValue(double(-startVal),double(a),0))*2,
                          a});
    for(float b=-startVal; b<startVal; b+=spacing)
    {
      m_vertexList.push_back({b+spacing,
                            float(perlinModule.GetValue(double(b+spacing),double(a),0))*2,
                            a});
    }
  }

  for(size_t j=0; j<m_numRows-2; j++)
  {
    if(j%2==0)
    {
      for(size_t i=0; i<m_numRows; i++)
      {
        m_indexList.push_back(getIndex(i,j));
        m_indexList.push_back(getIndex(i,j+1));
      }
    }
    else
    {
      for(size_t i=0; i<m_numRows; i++)
      {
        m_indexList.push_back(getIndex(m_numRows-1-i,j));
        m_indexList.push_back(getIndex(m_numRows-1-i,j+1));
      }
    }
  }

  size_t count=0;
  while(count<m_indexList.size())
  {
    std::vector<ngl::Vec3> verts = {};
    std::vector<GLshort> inds = {};
    size_t limit = count+30000;
    if(limit > m_indexList.size())
    {
      limit = m_indexList.size();
    }
    GLshort index = 0;
    for(; count<limit; count++)
    {
      if(count%10==0)
      {
         //std::cout<<"\n"<<count<<" "<<index<<" "<<m_indexList.size()<<"\n";
      }
      verts.push_back(m_vertexList.at(m_indexList.at(count)));
      inds.push_back(GLshort(index));
      index++;
    }
    m_vertices.push_back(verts);
    m_indices.push_back(inds);
  }
}

size_t Terrain::getIndex(size_t _x, size_t _z)
{
  return size_t(_z*m_numRows+_x);
}
