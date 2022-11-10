set_target_properties(PandemoniumRenderer PROPERTIES LINKER_LANGUAGE CXX)

file(
	GLOB_RECURSE
	HEADERS
	CONFIGURE_DEPENDS
	"*.h"
)

file(
	GLOB_RECURSE
	SRC
	CONFIGURE_DEPENDS
	"*.cpp"
)

target_sources(PandemoniumRenderer PUBLIC ${HEADERS} ${SRC})

# target_sources( PandemoniumRenderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers/GraphicsContext.h ${CMAKE_CURRENT_SOURCE_DIR}/headers/Shader.h
# ${CMAKE_CURRENT_SOURCE_DIR}/src/Shader.cpp ${CMAKE_CURRENT_SOURCE_DIR}/headers/Buffer.h ${CMAKE_CURRENT_SOURCE_DIR}/src/Buffer.cpp
# ${CMAKE_CURRENT_SOURCE_DIR}/headers/Renderer.h ${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer.cpp )

target_include_directories(
	PandemoniumRenderer
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers
			${CMAKE_CURRENT_SOURCE_DIR}/../Pandemonium-Core/headers
			${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/glad/include
			${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/glm
)
