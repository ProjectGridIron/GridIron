# src/gridiron/CMakeLists.txt
set(GRIDIRON_XHTML_NS "\"gi\"")
set(GRIDIRON_HTML_DOCROOT "html")
add_subdirectory(base_classes)
add_subdirectory(user_controls)
add_subdirectory(html)
# do NOT include test or docs. they're included conditionally further up