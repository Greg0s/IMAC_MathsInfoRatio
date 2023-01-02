find_package (Doxygen)

message(VERBOSE "Doxygen settings :")
message(VERBOSE "IMAC_LibRatio_SOURCE_DIR :  " ${IMAC_LibRatio_SOURCE_DIR})
message(VERBOSE "IMAC_LibRatio_BINARY_DIR :  " ${IMAC_LibRatio_BINARY_DIR})
message(VERBOSE "DOXYGEN_EXECUTABLE :  " ${DOXYGEN_EXECUTABLE})

if(DOXYGEN_FOUND)
  configure_file (${IMAC_LibRatio_SOURCE_DIR}/doc/Doxyfile-html.cmake ${IMAC_LibRatio_SOURCE_DIR}/doc/Doxyfile-html)
  add_custom_target (html ${DOXYGEN_EXECUTABLE} ${IMAC_LibRatio_SOURCE_DIR}/doc/Doxyfile-html)
endif (DOXYGEN_FOUND)
