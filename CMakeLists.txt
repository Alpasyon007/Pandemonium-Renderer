set_target_properties(PandemoniumRenderer PROPERTIES LINKER_LANGUAGE CXX)

target_sources(PandemoniumRenderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers/GraphicsContext.h)

target_include_directories(PandemoniumRenderer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers ${CMAKE_CURRENT_SOURCE_DIR}/../Pandemonium-Core/headers)
