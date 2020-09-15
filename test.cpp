#include <iostream>
#include <vector>
#include <string>

class CompactNode
{
private:
   uint32_t m_Data = 0;
	uint32_t m_ColorIndex1 = 0;
	uint32_t m_ColorIndex2 = 0;
	uint32_t m_ColorIndex3 = 0;
public:
   CompactNode() : m_Data(0), m_ColorIndex1(0), m_ColorIndex2(0), m_ColorIndex3(0) {};
   void SetColorIndex(uint32_t voxelIndex, uint32_t colorIndex)
	{
		switch(voxelIndex)
		{
			case 0:
         {
				uint32_t aligned = colorIndex << 20;
				m_ColorIndex1 &= 0x000FFFFF; 
				m_ColorIndex1 |= aligned;
            break;
         }
			case 1:
         {
				uint32_t aligned = colorIndex << 8;
				m_ColorIndex1 &= 0xFFF000FF;
				m_ColorIndex1 |= aligned;
            break;
         }
			case 2:
         {
				// First 8 bits of colorIndex go into m_ColorIndex1
				uint32_t firstEight = colorIndex >> 4;
				m_ColorIndex1 &= 0xFFFFFF00;
				m_ColorIndex1 |= firstEight;

				// Last 4 bits of colorIndex go into m_ColorIndex2
				uint32_t lastFour = (colorIndex & 0x0000000F) << 28;
				m_ColorIndex2 &= 0x0FFFFFFF;
				m_ColorIndex2 |= lastFour;
            break;
         }
			case 3:
         {
				uint32_t aligned = colorIndex << 16;
				m_ColorIndex2 &= 0xF000FFFF;
				m_ColorIndex2 |= aligned;
            break;
         }
			case 4:
         {
				uint32_t aligned = colorIndex << 4;
				m_ColorIndex2 &= 0xFFFF000F;
				m_ColorIndex2 |= aligned;
            break;
         }
			case 5:
         {
				// First 4 bits of colorIndex go into m_ColorIndex2
				uint32_t firstFour = colorIndex >> 8;
				m_ColorIndex2 &= 0xFFFFFFF0;
				m_ColorIndex2 |= firstFour;

				// Last 8 bits of colorIndex go into m_ColorIndex3
				uint32_t lastEight = (colorIndex & 0x000000FF) << 24;
				m_ColorIndex3 &= 0x00FFFFFF;
				m_ColorIndex3 |= lastEight;
            break;
         }
			case 6:
         {
				uint32_t aligned = colorIndex << 12;
				m_ColorIndex3 &= 0xFF000FFF;
				m_ColorIndex3 |= aligned;
            break;
         }
			case 7:
         {
				uint32_t aligned = colorIndex << 0;
				m_ColorIndex3 &= 0xFFFFF000;
				m_ColorIndex3 |= aligned;
            break;
         }
      }
	}

   uint32_t GetColorIndex(uint32_t voxelIndex)
	{
      uint32_t clearmask = 0x00000FFF;
      switch(voxelIndex)
      {
         case 0:
         {
            return m_ColorIndex1 >> 24;
         }
         case 1:
         {
            return (m_ColorIndex1 >> 8) & clearmask;
         }
         case 2:
         {
            // Last 8 bits of m_ColorIndex1 are first 8 bits of color index
            uint32_t firstEight = (m_ColorIndex1 & 0x000000FF) << 4;
            // First 4 bits of m_ColorIndex2 are last 4 bits of color index
            uint32_t lastFour = (m_ColorIndex2 & 0xF0000000) >> 28;

            return firstEight | lastFour;
         }
         case 3:
         {
            return (m_ColorIndex2 >> 16) & clearmask;
         }
         case 4:
         {
            return (m_ColorIndex2 >> 4) & clearmask;
         }
         case 5:
         {
            // Last 4 bits of m_ColorIndex2 are first 4 bits of color index
            uint32_t firstFour = (m_ColorIndex2 & 0x0000000F) << 8;
            // First 8 bits of m_ColorIndex3 are last 8 bits of color index
            uint32_t lastEight = (m_ColorIndex3 & 0xFF000000) >> 24;

            return firstFour | lastEight;
         }
         case 6:
         {
            return (m_ColorIndex3 >> 12) & clearmask;
         }
         case 7:
         {
            return m_ColorIndex3 & clearmask;
         }
      }
	}
};

int main()
{
   CompactNode node;
   node.SetColorIndex(2, 15);
   std::cout << node.GetColorIndex(0);
   std::cout << std::endl;
}