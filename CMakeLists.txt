set_target_properties(PandemoniumRenderer PROPERTIES LINKER_LANGUAGE CXX)

target_sources(
	PandemoniumRenderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers/GraphicsContext.h ${CMAKE_CURRENT_SOURCE_DIR}/headers/Shader.h
								${CMAKE_CURRENT_SOURCE_DIR}/src/Shader.cpp
)

target_include_directories(
	PandemoniumRenderer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers ${CMAKE_CURRENT_SOURCE_DIR}/../Pandemonium-Core/headers
								${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/glad/include
)
