include(admAsNeeded)
SET(ADM_dxva2_SRCS
ADM_coreDxva2.cpp
ADM_coreD3D.cpp
)	
#*************************************************
#*************************************************
ADM_ADD_SHARED_LIBRARY(ADM_coreDxva26 ${ADM_dxva2_SRCS})
INCLUDE_DIRECTORIES(../include)
TARGET_LINK_LIBRARIES(ADM_coreDxva26 ADM_core6 ADM_coreUI6 dxva2 ADM_coreImage6)
ADM_INSTALL_LIB(ADM_coreDxva26)
